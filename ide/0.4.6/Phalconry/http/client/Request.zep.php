<?php

namespace Phalconry\Http\Client;

/**
 * Represents an outgoing HTTP message
 */
class Request extends \Phalconry\Http\Client\Message
{
    /**
     * @var string
     */
    protected $method = "GET";

    /**
     * @var \Phalconry\Http\Uri
     */
    protected $uri;

    /**
     * @var \Phalconry\Http\Client\Response
     */
    protected $response;

    /**
     * @var \Phalconry\Http\Client
     */
    protected $client;


    /**
     * Constructor
     *
     * @param string $baseUri [Optional]
     */
    public function __construct($baseUri = null) {}

    /**
     * Sets the request method
     *
     * @param string $httpMethod 
     * @return \Phalconry\Http\Client\Request 
     */
    public function setMethod($httpMethod) {}

    /**
     * Returns the request method
     * Default method is "GET"
     *
     * @return string 
     */
    public function getMethod() {}

    /**
     * Sets the response message
     *
     * @param \Phalconry\Http\Client\Response $response 
     * @return \Phalconry\Http\Client\Request 
     */
    public function setResponse(Response $response) {}

    /**
     * Returns the request's response
     *
     * @return \Phalconry\Http\Client\Response 
     */
    public function getResponse() {}

    /**
     * Sets the request URI
     *
     * @param mixed $uri 
     * @return \Phalconry\Http\Client\Request 
     */
    public function setUri($uri) {}

    /**
     * Returns the request URI
     *
     * @return \Phalconry\Http\Uri 
     */
    public function getUri() {}

    /**
     * Resolves the request URI using the given argument
     *
     * @see \Phalconry\Http\Uri::resolve()
     * @param mixed $uri 
     * @return \Phalconry\Http\Uri 
     */
    public function resolveUri($uri) {}

    /**
     * Adds an array of query parameters to the request URI
     *
     * @param array $params 
     * @return \Phalconry\Http\Client\Request 
     */
    public function addQueryParams($params) {}

    /**
     * Adds an array of headers to the request
     *
     * @param array $headers 
     * @return \Phalconry\Http\Client\Request 
     */
    public function addHeaders($headers) {}

    /**
     * Sets a single request header
     *
     * @param string $name 
     * @param string $value 
     * @return \Phalconry\Http\Client\Request 
     */
    public function setHeader($name, $value) {}

    /**
     * Builds the header fields
     *
     * @return \Phalconry\Http\Client\Request 
     */
    public function buildHeaderFields() {}

    /**
     * Sets the request client object
     *
     * @param \Phalconry\Http\Client $client 
     * @return \Phalconry\Http\Client\Request 
     */
    public function setClient(\Phalconry\Http\Client $client) {}

    /**
     * Returns the request client object, if set
     *
     * @return \Phalconry\Http\Client 
     */
    public function getClient() {}

    /**
     * Sends the request
     *
     * @throws \RuntimeException if client is not set and cannot be retrieved from the default DI container
     * @return \Phalconry\Http\Client\Request 
     */
    public function send() {}

    /**
     * Alias of send()
     *
     * @return \Phalconry\Http\Client\Request 
     */
    public function __invoke() {}

}
