<?php

namespace Phalconry\Http\Client\Adapter;


class Curl implements \Phalconry\Http\Client\Adapter\AdapterInterface
{
    /**
     * cURL handle
     *
     * @var resource
     */
    protected $handle;



    public static function isAvailable() {}

    /**
     * @param mixed $curlHandle 
     */
    public function __construct($curlHandle = null) {}


    public function __destruct() {}


    public function __clone() {}

    /**
     * @param mixed $option 
     * @param mixed $value 
     */
    public function setOption($option, $value) {}

    /**
     * @param mixed $options 
     */
    public function setOptions($options) {}

    /**
     * @param mixed $timeout 
     */
    public function setTimeout($timeout) {}

    /**
     * @param mixed $timeout 
     */
    public function setConnectTimeout($timeout) {}

    /**
     * @param mixed $host 
     * @param mixed $port 
     * @param mixed $user 
     * @param mixed $pass 
     */
    public function setProxy($host, $port = 8080, $user = null, $pass = null) {}

    /**
     * @param mixed $request 
     * @param mixed $params 
     * @param mixed $customHeader 
     * @param bool $fullResponse 
     */
    public function get(\Phalconry\Http\Client\Request $request, $params = array(), $customHeader = array(), $fullResponse = false) {}

    /**
     * @param mixed $request 
     * @param mixed $params 
     * @param mixed $customHeader 
     * @param bool $fullResponse 
     */
    public function head(\Phalconry\Http\Client\Request $request, $params = array(), $customHeader = array(), $fullResponse = false) {}

    /**
     * @param mixed $request 
     * @param mixed $params 
     * @param mixed $customHeader 
     * @param bool $fullResponse 
     */
    public function delete(\Phalconry\Http\Client\Request $request, $params = array(), $customHeader = array(), $fullResponse = false) {}

    /**
     * @param mixed $request 
     * @param mixed $params 
     * @param bool $urlEncode 
     * @param mixed $customHeader 
     * @param bool $fullResponse 
     */
    public function post(\Phalconry\Http\Client\Request $request, $params = array(), $urlEncode = true, $customHeader = array(), $fullResponse = false) {}

    /**
     * @param mixed $request 
     * @param mixed $params 
     * @param bool $urlEncode 
     * @param mixed $customHeader 
     * @param bool $fullResponse 
     */
    public function put(\Phalconry\Http\Client\Request $request, $params = array(), $urlEncode = true, $customHeader = array(), $fullResponse = false) {}

    /**
     * @param mixed $request 
     */
    public function __invoke(\Phalconry\Http\Client\Request $request) {}

    /**
     * @param mixed $request 
     * @param mixed $customHeader 
     * @param bool $fullResponse 
     * @return \Phalconry\Http\Client\Response 
     */
    protected function send(\Phalconry\Http\Client\Request $request, $customHeader = array(), $fullResponse = false) {}

    /**
     * Prepare data for a cURL post.
     *
     * @param mixed $params Data to send.
     * @param boolean $urlEncode Whether to url-encode params. Defaults to true.
     * @return void 
     */
    protected function initPostFields($params, $urlEncode = true) {}


    protected function initOptions() {}

}
