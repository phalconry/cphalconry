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
namespace Phalconry\Http\Client;

/**
 * Represents an incoming HTTP message (in response to a sent Request).
 */
class Response extends Message
{

	/**
	 * @var mixed
	 */
	protected body;

	/**
	 * Sets the response body
	 *
	 * @param mixed body
	 * @return \Phalconry\Http\Client\Response
	 */
	public function setBody(var body) -> <Response>
	{
		let this->body = body;
		return this;
	}

	/**
	 * Returns the response body
	 *
	 * @return mixed
	 */
	public function getBody() {
		return this->body;
	}

	/**
	 * Parses a string or array of headers into the object
	 *
	 * @param string|array headers
	 * @return \Phalconry\Http\Client\Response
	 */
	public function parseHeaders(var headers) -> <Response>
	{
		this->header->parse(headers);
		return this;
	}

	/**
	 * Returns the response body decoded to a object, if possible, otherwise boolean false.
	 *
	 * Uses the "Content-Type" header to determine if the body can be decoded.
	 *
	 * Currently, the following formats can be decoded:
	 *  * JSON - with Content-Type header "application/json"
	 *  * XML - with Content-Type header "application/xml" or "text/xml"
	 *
	 * @return object|boolean
	 */
	public function getBodyDecoded()
	{
        var contentType;
        let contentType = this->getHeader("Content-Type");

		if starts_with(contentType, "application/json") {
			return json_decode(this->body);
		}

		if starts_with(contentType, "application/xml") || starts_with(contentType, "text/xml") {
			return simplexml_load_string(this->body);
		}

		return false;
	}

}
