/*
 +------------------------------------------------------------------------+
 | Phalcon Framework                                                      |
 +------------------------------------------------------------------------+
 | Copyright (c) 2011-2012 Phalcon Team (http://www.phalconphp.com)       |
 +------------------------------------------------------------------------+
 | This source file is subject to the New BSD License that is bundled     |
 | with this package in the file docs/LICENSE.txt.                        |
 |                                                                        |
 | If you did not receive a copy of the license and are unable to         |
 | obtain it through the world-wide-web, please send an email             |
 | to license@phalconphp.com so we can send you a copy immediately.       |
 +------------------------------------------------------------------------+
 | Author: Tuğrul Topuz <tugrultopuz@gmail.com>                           |
 +------------------------------------------------------------------------+
 */
namespace Phalconry\Http\Client\Adapter;

use Phalconry\Http\Uri;
use Phalconry\Http\Client;
use Phalconry\Http\Client\Request;
use Phalconry\Http\Client\Response;
use Phalconry\Http\Client\Exception as HttpException;
use InvalidArgumentException;

class Curl implements AdapterInterface
{

	/**
	 * cURL handle
	 * @var resource
	 */
	protected handle;

	public static function isAvailable()
	{
		return extension_loaded("curl");
	}

	public function __construct(var curlHandle = null)
	{

		if typeof curlHandle == "null" {
			let this->handle = curl_init();
		} else {
			if is_resource(curlHandle) {
				let this->handle = curlHandle;
        	} else {
				throw new InvalidArgumentException("Handle must be cURL resource");
			}
		}

		this->initOptions();
	}

	public function __destruct()
	{
		curl_close(this->handle);
	}

	public function __clone()
	{
		return new Curl(curl_copy_handle(this->handle));
	}

	public function setOption(var option, var value)
	{
		return curl_setopt(this->handle, option, value);
	}

	public function setOptions(var options)
	{
		return curl_setopt_array(this->handle, options);
	}

	public function setTimeout(var timeout)
	{
		this->setOption(CURLOPT_TIMEOUT, timeout);
	}

	public function setConnectTimeout(var timeout)
	{
		this->setOption(CURLOPT_CONNECTTIMEOUT, timeout);
	}

	public function setProxy(var host, var port = 8080, var user = null, var pass = null)
	{
		this->setOptions([
			CURLOPT_PROXY: host,
			CURLOPT_PROXYPORT: port
		]);

		if (typeof user == "string" && "" !== user) {

            var pair;
            let pair = user;

			if (typeof pass == "string" && "" !== pass) {
				let pair .= ":".pass;
			}

			this->setOption(CURLOPT_PROXYUSERPWD, pair);
		}
	}

	public function get(<Request> request, var params = [], var customHeader = [], boolean fullResponse = false)
	{
		if ! empty params {
			request->getUri()->extendQuery(params);
		}

		this->setOptions([
			CURLOPT_URL: request->getUri()->build(),
			CURLOPT_HTTPGET: true,
			CURLOPT_CUSTOMREQUEST: "GET"
		]);

		return this->send(request, customHeader, fullResponse);
	}

	public function head(<Request> request, var params = [], var customHeader = [], boolean fullResponse = false)
	{
		if ! empty params {
			request->getUri()->extendQuery(params);
		}

		this->setOptions([
			CURLOPT_URL: request->getUri()->build(),
			CURLOPT_HTTPGET: true,
			CURLOPT_CUSTOMREQUEST: "HEAD"
		]);

		return this->send(request, customHeader, fullResponse);
	}

	public function delete(<Request> request, var params = [], var customHeader = [], boolean fullResponse = false)
	{
		if ! empty params {
			request->getUri()->extendQuery(params);
		}

		this->setOptions([
			CURLOPT_URL: request->getUri()->build(),
			CURLOPT_HTTPGET: true,
			CURLOPT_CUSTOMREQUEST: "DELETE"
		]);

		return this->send(customHeader, fullResponse);
	}

	public function post(<Request> request, var params = [], boolean urlEncode = true, var customHeader = [], boolean fullResponse = false)
	{
		this->setOptions([
			CURLOPT_URL: request->getUri()->build(),
			CURLOPT_POST: true,
			CURLOPT_CUSTOMREQUEST: "POST"
		]);

		this->initPostFields(params, urlEncode);

		return this->send(customHeader, fullResponse);
	}

	public function put(<Request> request, var params = [], boolean urlEncode = true, var customHeader = [], boolean fullResponse = false)
	{
		this->setOptions([
			CURLOPT_URL: request->getUri()->build(),
			CURLOPT_POST: true,
			CURLOPT_CUSTOMREQUEST: "PUT"
		]);

		this->initPostFields(params, urlEncode, customHeader);

		return this->send(customHeader, fullResponse);
	}

	public function __invoke(<Request> request)
	{
        var method;
		let method = strtolower(request->getMethod());

		if method_exists(this, method) {
			return this->{method}(request);
		}

		throw new Exception("Unknown HTTP method");
	}

	protected function send(<Request> request, var customHeader = [], boolean fullResponse = false) -> <Response>
	{
        var header, content, errorNo, headerSize, response;

		if ! empty customHeader {
			let header = customHeader;
		} else {

			let header = [];

            if count(request->header) > 0 {
				let header = request->header->build();
			}

            let header[] = "Expect:";
		}

		this->setOption(CURLOPT_HTTPHEADER, header);

		let content = curl_exec(this->handle);
        let errorNo = curl_errno(this->handle);

		if errorNo !== 0 {
			throw new HttpException(curl_error(this->handle), errorNo);
		}

		let headerSize = curl_getinfo(this->handle, CURLINFO_HEADER_SIZE);

		let response = new Response();
		response->parseHeaders(substr(content, 0, headerSize));

		if fullResponse {
			response->setBody(content);
		} else {
			response->setBody(substr(content, headerSize));
		}

		return response;
	}

	/**
	 * Prepare data for a cURL post.
	 *
	 * @param mixed   params      Data to send.
	 * @param boolean urlEncode Whether to url-encode params. Defaults to true.
	 *
	 * @return void
	 */
	protected function initPostFields(var params, boolean urlEncode = true)
	{
		if typeof params == "array" {
            var param;
			for param in params {
				if (typeof param == "string" && preg_match("/^@/", param)) {
					let urlEncode = false;
					break;
				}
			}

			if urlEncode {
				let params = http_build_query(params);
			}
		}

		if ! empty params {
			this->setOption(CURLOPT_POSTFIELDS, params);
		}
	}

	protected function initOptions() -> void
	{
		this->setOptions([
			CURLOPT_RETURNTRANSFER: true,
			CURLOPT_AUTOREFERER: true,
			CURLOPT_FOLLOWLOCATION: true,
			CURLOPT_MAXREDIRS: 20,
			CURLOPT_HEADER: true,
			CURLOPT_PROTOCOLS: CURLPROTO_HTTP | CURLPROTO_HTTPS,
			CURLOPT_REDIR_PROTOCOLS: CURLPROTO_HTTP | CURLPROTO_HTTPS,
			CURLOPT_USERAGENT: "Phalcon HTTP/" . Client::VERSION . " (Curl)",
			CURLOPT_CONNECTTIMEOUT: 30,
			CURLOPT_TIMEOUT: 30
		]);
	}

}
