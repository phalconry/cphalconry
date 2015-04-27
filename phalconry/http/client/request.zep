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

use Phalconry\Http\Uri;
use Phalconry\Http\Client;
use RuntimeException;

/**
 * Represents an outgoing HTTP message
 */
class Request extends Message
{

	/**
	 * @var string
	 */
	protected method = "GET";

	/**
	 * @var \Phalconry\Http\Uri
	 */
	protected uri;

	/**
	 * @var \Phalconry\Http\Client\Response
	 */
	protected response;

	/**
	 * @var \Phalconry\Http\Client
	 */
	protected client;

	/**
	 * Constructor
	 *
	 * @param string baseUri [Optional]
	 */
	public function __construct(var baseUri = null)
	{
		parent::__construct();
		this->setUri(baseUri);
	}

	/**
	 * Sets the request method
	 *
	 * @param string httpMethod
	 * @return \Phalconry\Http\Client\Request
	 */
	public function setMethod(string! httpMethod) -> <Request>
	{
		let this->method = strtoupper(httpMethod);
		return this;
	}

	/**
	 * Returns the request method
	 *
	 * Default method is "GET"
	 *
	 * @return string
	 */
	public function getMethod() -> string
	{
		return this->method;
	}

	/**
	 * Sets the response message
	 *
	 * @param \Phalconry\Http\Client\Response response
	 * @return \Phalconry\Http\Client\Request
	 */
	public function setResponse(<Response> response) -> <Request>
	{
		response->setParent(this);
		let this->response = response;
		return this;
	}

	/**
	 * Returns the request's response
	 *
	 * @return \Phalconry\Http\Client\Response
	 */
	public function getResponse() -> <Response>
	{
		return this->response;
	}

	/**
	 * Sets the request URI
	 *
	 * @param mixed uri
	 * @return \Phalconry\Http\Client\Request
	 */
	public function setUri(var uri) -> <Request>
	{
		let this->uri = new Uri(uri);
		return this;
	}

	/**
	 * Returns the request URI
	 *
	 * @return \Phalconry\Http\Uri
	 */
	public function getUri() -> <Uri>
	{
		return this->uri;
	}

	/**
	 * Resolves the request URI using the given argument
	 *
	 * @see \Phalconry\Http\Uri::resolve()
	 *
	 * @param mixed uri
	 * @return \Phalconry\Http\Uri
	 */
	public function resolveUri(var uri) -> <Uri>
	{
		return this->uri->resolve(uri);
	}

	/**
	 * Adds an array of query parameters to the request URI
	 *
	 * @param array params
	 * @return \Phalconry\Http\Client\Request
	 */
	public function addQueryParams(array params) -> <Request>
	{
		this->uri->extendQuery(params);
		return this;
	}

	/**
	 * Adds an array of headers to the request
	 *
	 * @param array headers
	 * @return \Phalconry\Http\Client\Request
	 */
	public function addHeaders(array headers) -> <Request>
	{
		this->header->addMultiple(headers);
		return this;
	}

	/**
	 * Sets a single request header
	 *
	 * @param string name
	 * @param string value
	 * @return \Phalconry\Http\Client\Request
	 */
	public function setHeader(string name, string value) -> <Request>
	{
		this->header->set(name, value);
		return this;
	}

	/**
	 * Builds the header fields
	 *
	 * @return \Phalconry\Http\Client\Request
	 */
	public function buildHeaderFields() -> <Request>
	{
		this->header->build(Header::BUILD_FIELDS);
		return this;
	}

	/**
	 * Sets the request client object
	 *
	 * @param \Phalconry\Http\Client client
	 * @return \Phalconry\Http\Client\Request
	 */
	public function setClient(<Client> client) -> <Request>
	{
		let this->client = client;
		return this;
	}

	/**
	 * Returns the request client object, if set
	 *
	 * @return \Phalconry\Http\Client
	 */
	public function getClient() -> <Client>
	{
		return this->client;
	}

	/**
	 * Sends the request
	 *
	 * @return \Phalconry\Http\Client\Request
	 * @throws \RuntimeException if client is not set and cannot be retrieved from the default DI container
	 */
	public function send() -> <Request>
	{
		var client;

		let client = this->client;

		if typeof client != "object" {

			let client = \Phalcon\Di::getDefault()->getShared("httpClient");

			if typeof client != "object" {
				throw new RuntimeException("Cannot locate Client");
			}
		}

        client->send(this);

        return this;
	}

	/**
	 * Alias of send()
	 * @return \Phalconry\Http\Client\Request
	 */
	public function __invoke() -> <Request>
	{
		return this->send();
	}

}
