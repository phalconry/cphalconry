<?php

namespace Phalconry\WebService;


interface ServiceInterface
{

    /**
     * Returns the HTTP client
     *
     * @return \Phalconry\Http\Client 
     */
    public function getClient();

    /**
     * Returns a URL to the service using the given args
     *
     * @param array $args 
     * @param array $$args [Optional]
     * @return string 
     */
    public function buildUrl($args = array());

    /**
     * Returns a new HTTP request
     *
     * @param mixed $url 
     * @param mixed $method 
     * @param array $headers 
     * @param string $$url [Optional] Request URL
     * @param string $$method [Optional] HTTP request method
     * @param array $$headers [Optional] Request headers
     * @return \Phalconry\Http\Client\Request 
     */
    public function createRequest($url = null, $method = null, $headers = array());

    /**
     * Returns the response body decoded to a PHP object
     *
     * @param mixed $body 
     * @param mixed $$body 
     * @return object 
     */
    public function buildResponseBody($body);

}
