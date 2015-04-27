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

class Stream implements AdapterInterface
{

	/**
	 * Stream context
	 * @var resource
	 */
	protected context;

	public static function isAvailable() {
		var wrappers;
        let wrappers = stream_get_wrappers();
		return in_array("http", wrappers) && in_array("https", wrappers);
	}

	public function __construct() {
		let this->context = stream_context_create();
		this->initOptions();
	}

	public function __destruct() {
		let this->context = null;
	}

	public function setOption(var option, var value) {
		return stream_context_set_option(this->context, "http", option, value);
	}

	public function setOptions(var options) {
		return stream_context_set_option(this->context, ["http": options], null, null);
	}

	public function setTimeout(var timeout) {
		this->setOption("timeout", timeout);
	}

	public function setProxy(var host, var port = 8080, var user = null, var pass = null) {

        var uri;

		let uri = new Uri([
			"scheme": "tcp",
			"host": host,
			"port": port
		]);

		if typeof user == "string" {

            let uri->user = user;

			if typeof pass == "string" {
				let uri->pass = pass;
			}
		}

		this->setOption("proxy", uri->build());
	}

	public function get(<Request> request, var params = []) {

		if ! empty params {
			request->getUri()->extendQuery(params);
		}

		this->setOptions([
			"method": "GET",
			"content": ""
		]);

		request->header->remove("Content-Type");

		return this->send(request);
	}

	public function head(<Request> request, var params = []) {

		if ! empty params {
			request->getUri()->extendQuery(params);
		}

		this->setOptions([
			"method": "HEAD",
			"content": ""
		]);

		request->header->remove("Content-Type");

		return this->send(request);
	}

	public function delete(<Request> request, var params = []) {

		if ! empty params {
			request->getUri()->extendQuery(params);
		}

		this->setOptions([
			"method": "DELETE",
			"content": ""
		]);

		request->header->remove("Content-Type");

		return this->send(request);
	}

	public function post(<Request> request, var params = []) {
		this->setOption("method", "POST");
		this->initPostFields(request, params);
		return this->send(request);
	}

	public function put(<Request> request, var params = []) {
		this->setOption("method", "PUT");
		this->initPostFields(request, params);
		return this->send(request);
	}

	public function __invoke(<Request> request, var params = []) {

        var method;
		let method = strtolower(request->getMethod());

		if method_exists(this, method) {
			return this->{method}(request, params);
		}

		throw new Exception("Unknown HTTP method");
	}

	protected function errorHandler(var errorNumber, var errorString) {
		throw new HttpException(errorString, errorNumber);
	}

	protected function send(<Request> request) {

        var content, response, http_response_header;
		let http_response_header = "";

		if count(request->header) > 0 {
			this->setOption("header", request->buildHeaderFields());
		}

		set_error_handler([this, "errorHandler"]);
		let content = file_get_contents(request->getUri()->build(), false, this->context);
		restore_error_handler();

		let response = new Response();
		response->parseHeaders(http_response_header);
		response->setBody(content);

		return response;
	}

	protected function initPostFields(<Request> request, var params = []) {

		if (typeof params == "array" && ! empty params) {
			request->setHeader("Content-Type", "application/x-www-form-urlencoded");
			this->setOption("content", http_build_query(params));
		}
	}

	protected function initOptions() {
		this->setOptions([
			"user_agent": "Phalcon HTTP/" . Client::VERSION . " (Stream)",
			"follow_location": 1,
			"max_redirects": 20,
			"timeout": 30
		]);
	}

}
