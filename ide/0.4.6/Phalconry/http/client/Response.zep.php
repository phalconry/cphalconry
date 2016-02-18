<?php

namespace Phalconry\Http\Client;

/**
 * Represents an incoming HTTP message (in response to a sent Request).
 */
class Response extends \Phalconry\Http\Client\Message
{
    /**
     * @var mixed
     */
    protected $body;


    /**
     * Sets the response body
     *
     * @param mixed $body 
     * @return \Phalconry\Http\Client\Response 
     */
    public function setBody($body) {}

    /**
     * Returns the response body
     *
     * @return mixed 
     */
    public function getBody() {}

    /**
     * Parses a string or array of headers into the object
     *
     * @param string|array $headers 
     * @return \Phalconry\Http\Client\Response 
     */
    public function parseHeaders($headers) {}

    /**
     * Returns the response body decoded to a object, if possible, otherwise boolean false.
     * Uses the "Content-Type" header to determine if the body can be decoded.
     * Currently, the following formats can be decoded:
     * JSON - with Content-Type header "application/json"
     * XML - with Content-Type header "application/xml" or "text/xml"
     *
     * @return object|boolean 
     */
    public function getBodyDecoded() {}

}
