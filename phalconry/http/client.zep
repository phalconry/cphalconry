namespace Phalconry\Http;

use Phalconry\Http\Client\Exception;
use Phalconry\Http\Client\Request;
use Phalconry\Http\Client\Response;
use Phalconry\Http\Client\Adapter\Curl;
use Phalconry\Http\Client\Adapter\Stream;
use Phalconry\Http\Client\Adapter\Exception as AdapterException;
use Phalconry\Http\Client\Adapter\AdapterInterface;

class Client extends \Phalcon\Di\Injectable
{

	/**
	 * HTTP client library version
	 * @var string
	 */
	const VERSION = "0.1";

	/**
	 * The last request sent
	 * @var \Phalconry\Http\Client\Request
	 */
	protected _lastRequest;

	/**
	 * The adapter classname
	 * @var string
	 */
	private static adapterClass;

	/**
	 * Returns the client adapter
	 *
	 * @return \Phalconry\Http\Client\Adapter\AdapterInterface
	 * @throws \Phalconry\Http\Client\Adapter\Exception if no adapters are available
	 */
    public static function getAdapter() -> <AdapterInterface>
	{
		if typeof self::adapterClass == "string" {
			return create_instance(self::adapterClass);
		}

        if Curl::isAvailable() {
        	let self::adapterClass = "Phalconry\\Http\\Client\\Adapter\\Curl";
            return new Curl();
        }

        if Stream::isAvailable() {
        	let self::adapterClass = "Phalconry\\Http\\Client\\Adapter\\Stream";
            return new Stream();
        }

        throw new AdapterException("No client adapters are available");
    }

	/**
	 * Creates and returns a new request object
	 *
	 * @param string uri
	 * @param string method [Optional] Default "GET"
	 * @param array params [Optional] Query parameters
	 * @param array headers [Optional] Extra headers
	 * @return \Phalconry\Http\Client\Request
	 */
	public static function createHttpRequest(var uri, string! method = "GET", array params = [], array headers = []) -> <Request>
	{
        var request;
		let request = new Request(uri);

		request->setMethod(method);

		if ! empty params {
			request->addQueryParams(params);
		}

		if ! empty headers {
			request->addHeaders(headers);
		}

		return request;
	}

	/**
	 * Creates and returns a new request object
	 *
	 * @param string uri
	 * @param string method [Optional] Default "GET"
	 * @param array params [Optional] Query parameters
	 * @param array headers [Optional] Extra headers
	 * @return \Phalconry\Http\Client\Request
	 */
	public function createRequest(var uri, string! method = "GET", array params = [], array headers = []) -> <Request>
	{
        var request;
		let request = self::createHttpRequest(uri, method, params, headers);

		request->setClient(this);

		if typeof this->{"_eventsManager"} == "object" {
			this->{"_eventsManager"}->fire("http-client:createRequest", this, request);
		}

		return request;
	}

	/**
	 * Sends a request.
	 *
	 * @param \Phalconry\Http\Client\Request request
	 * @return \Phalconry\Http\Client
	 */
	public function send(<Request> request) -> <Client>
	{
		var eventsManager, response;

		let eventsManager = this->{"_eventsManager"};

		if typeof eventsManager == "object" {
			eventsManager->fire("http-client:beforeSend", this, request);
		}

		let response = self::getAdapter()->__invoke(request);

		request->setResponse(response);

		if eventsManager == "object" {
			eventsManager->fire("http-client:afterSend", this, request);
		}

		let this->_lastRequest = request;

		return this;
	}

	/**
	 * Returns the response associated with a given request or the last request sent if none given.
	 *
	 * @param \Phalconry\Http\Client\Request request [Optional]
	 * @return \Phalconry\Http\Client\Response
	 * @throws \Phalconry\Http\Client\Exception if no requests have been sent
	 */
	public function getResponse(<Request> request = null) -> <Response>
	{
		if typeof request == "object" {
			return request->getResponse();
		}

		if typeof this->_lastRequest == "object" {
			return this->_lastRequest->getResponse();
		}

		throw new Exception("No requests have been sent");
	}

}
