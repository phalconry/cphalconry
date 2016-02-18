namespace Phalconry\WebService;

use Phalconry\Http\Client;
use Phalconry\Http\Client\Request;

interface ServiceInterface
{

	/**
	 * Returns the HTTP client
	 *
	 * @return \Phalconry\Http\Client
	 */
	public function getClient() -> <Client>;

	/**
	 * Returns a URL to the service using the given args
	 *
	 * @param array $args [Optional]
	 * @return string
	 */
	public function buildUrl(array args = []) -> string;

	/**
	 * Returns a new HTTP request
	 *
	 * @param string $url [Optional] Request URL
	 * @param string $method [Optional] HTTP request method
	 * @param array $headers [Optional] Request headers
	 * @return \Phalconry\Http\Client\Request
	 */
	public function createRequest(var url = null, var method = null, array headers = []) -> <Request>;

	/**
	 * Returns the response body decoded to a PHP object
	 *
	 * @param mixed $body
	 * @return object
	 */
	public function buildResponseBody(var body) -> var;

}
