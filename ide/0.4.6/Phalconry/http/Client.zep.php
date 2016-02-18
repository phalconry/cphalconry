<?php

namespace Phalconry\Http;


class Client extends Phalcon\Di\Phalcon\Di\Injectable
{
    /**
     * HTTP client library version
     *
     * @var string
     */
    const VERSION = "0.1";

    /**
     * The last request sent
     *
     * @var \Phalconry\Http\Client\Request
     */
    protected $_lastRequest;

    /**
     * The adapter classname
     *
     * @var string
     */
    static private $adapterClass;


    /**
     * Returns the client adapter
     *
     * @throws \Phalconry\Http\Client\Adapter\Exception if no adapters are available
     * @return \Phalconry\Http\Client\Adapter\AdapterInterface 
     */
    public static function getAdapter() {}

    /**
     * Creates and returns a new request object
     *
     * @param string $uri 
     * @param string $method [Optional] Default "GET"
     * @param array $params [Optional] Query parameters
     * @param array $headers [Optional] Extra headers
     * @return \Phalconry\Http\Client\Request 
     */
    public static function createHttpRequest($uri, $method = "GET", $params = array(), $headers = array()) {}

    /**
     * Creates and returns a new request object
     *
     * @param string $uri 
     * @param string $method [Optional] Default "GET"
     * @param array $params [Optional] Query parameters
     * @param array $headers [Optional] Extra headers
     * @return \Phalconry\Http\Client\Request 
     */
    public function createRequest($uri, $method = "GET", $params = array(), $headers = array()) {}

    /**
     * Sends a request.
     *
     * @param \Phalconry\Http\Client\Request $request 
     * @return \Phalconry\Http\Client 
     */
    public function send(\Phalconry\Http\Client\Request $request) {}

    /**
     * Returns the response associated with a given request or the last request sent if none given.
     *
     * @throws \Phalconry\Http\Client\Exception if no requests have been sent
     * @param \Phalconry\Http\Client\Request $request [Optional]
     * @return \Phalconry\Http\Client\Response 
     */
    public function getResponse(\Phalconry\Http\Client\Request $request = null) {}

}
