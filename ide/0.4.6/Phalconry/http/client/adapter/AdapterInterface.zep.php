<?php

namespace Phalconry\Http\Client\Adapter;


interface AdapterInterface
{

    /**
     * @param mixed $option 
     * @param mixed $value 
     */
    public function setOption($option, $value);

    /**
     * @param mixed $options 
     */
    public function setOptions($options);

    /**
     * @param mixed $timeout 
     */
    public function setTimeout($timeout);

    /**
     * @param mixed $host 
     * @param mixed $port 
     * @param mixed $user 
     * @param mixed $pass 
     */
    public function setProxy($host, $port = 8080, $user = null, $pass = null);

    /**
     * @param mixed $request 
     * @param mixed $params 
     */
    public function get(\Phalconry\Http\Client\Request $request, $params = array());

    /**
     * @param mixed $request 
     * @param mixed $params 
     */
    public function head(\Phalconry\Http\Client\Request $request, $params = array());

    /**
     * @param mixed $request 
     * @param mixed $params 
     */
    public function delete(\Phalconry\Http\Client\Request $request, $params = array());

    /**
     * @param mixed $request 
     * @param mixed $params 
     */
    public function post(\Phalconry\Http\Client\Request $request, $params = array());

    /**
     * @param mixed $request 
     * @param mixed $params 
     */
    public function put(\Phalconry\Http\Client\Request $request, $params = array());

    /**
     * @param mixed $request 
     */
    public function __invoke(\Phalconry\Http\Client\Request $request);

}
