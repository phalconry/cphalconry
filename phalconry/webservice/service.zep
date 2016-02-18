namespace Phalconry\WebService;

use Phalcon\Di\Injectable;
use Phalconry\Http\Client;
use Phalconry\Http\Client\Request;
use Phalconry\Http\Client\Response;

/**
 * Represents a web service
 */
abstract class Service extends Injectable implements ServiceInterface
{

	/**
	 * Returns the HTTP client from the DI container
	 *
	 * @return \Phalconry\Http\Client
	 */
	public function getClient() -> <Client>
	{
		return this->getDI()->getShared("httpClient");
	}

	/**
	 * Returns a new HTTP request
	 *
	 * @param string|array url [Optional] Request URL or args for buildUrl()
	 * @param string method [Optional] HTTP request method
	 * @param array headers [Optional] Request headers
	 * @return \Phalconry\Http\Client\Request
	 */
	public function createRequest(var url = null, var method = null, array! headers = []) -> <Request>
	{
        var request;

		if typeof url == "array" {
			let url = this->buildUrl(url);
		}

		let request = new Request(url);

		if typeof method == "string" {
			request->setMethod(method);
		}

		if ! empty headers {
			request->addHeaders(headers);
		}

		return request;
	}

	/**
	 * Sends a request and returns the response
	 *
	 * @param \Phalconry\Http\Client\Request request
	 * @return \Phalconry\Http\Client\Response
	 */
	public function send(<Request> request) -> <Response>
	{
		return this->getClient()->send(request)->getResponse();
	}

}
