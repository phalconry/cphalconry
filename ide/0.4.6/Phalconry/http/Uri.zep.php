<?php

namespace Phalconry\Http;


class Uri
{

    protected $parts = array();


    /**
     * @param mixed $uri 
     */
    public function __construct($uri = null) {}

    /**
     * @return string 
     */
    public function __toString() {}

    /**
     * @param string $name 
     */
    public function __unset($name) {}

    /**
     * @param string $name 
     * @param mixed $value 
     */
    public function __set($name, $value) {}

    /**
     * @param string $name 
     */
    public function __get($name) {}

    /**
     * @param string $name 
     * @return bool 
     */
    public function __isset($name) {}

    /**
     * @return string 
     */
    public function build() {}

    /**
     * @param mixed $query 
     * @return string 
     */
    public function buildQuery($query) {}

    /**
     * @param mixed $uri 
     * @return Uri 
     */
    public function resolve($uri) {}

    /**
     * @param mixed $uri 
     * @return Uri 
     */
    public function extend($uri) {}

    /**
     * @param array $params 
     * @return Uri 
     */
    public function extendQuery($params) {}

    /**
     * @param string $path 
     * @return Uri 
     */
    public function extendPath($path) {}

}
