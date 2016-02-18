<?php

namespace Phalconry\WebService;

/**
 * Represents a web service
 */
abstract class Service extends Phalcon\Di\Phalcon\Di\Injectable implements \Phalconry\WebService\ServiceInterface
{

    /**
     * Returns the HTTP client from the DI container
     *
     * @return \Phalconry\Http\Client 
     */
    public function getClient() {}

    /**
     * Returns a new HTTP request
     *
     * @param string|array $url [Optional] Request URL or args for buildUrl()
     * @param string $method [Optional] HTTP request method
     * @param array $headers [Optional] Request headers
     * @return \Phalconry\Http\Client\Request 
     */
    public function createRequest($url = null, $method = null, $headers = array()) {}

    /**
     * Sends a request and returns the response
     *
     * @param \Phalconry\Http\Client\Request $request 
     * @return \Phalconry\Http\Client\Response 
     */
    public function send(\Phalconry\Http\Client\Request $request) {}

}
