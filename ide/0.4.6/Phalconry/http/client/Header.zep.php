<?php

namespace Phalconry\Http\Client;

/**
 * Represents a collection of HTTP headers
 */
class Header implements \Countable
{

    const BUILD_STATUS = 1;


    const BUILD_FIELDS = 2;


    protected $version = "1.0";


    protected $statusCode = 0;


    protected $statusMessage = "";


    protected $status = "";


    private $fields = array();


    static protected $messages;


    /**
     * Sets a single header field
     *
     * @param string $name 
     * @param mixed $value 
     */
    public function set($name, $value) {}

    /**
     * Sets an array of headers
     *
     * @param array $fields 
     */
    public function setMultiple($fields) {}

    /**
     * Adds an array of headers
     *
     * @param array $fields 
     */
    public function addMultiple($fields) {}

    /**
     * Returns a single header field
     *
     * @param string $name 
     * @return string 
     */
    public function get($name) {}

    /**
     * Returns all header fields
     *
     * @return array 
     */
    public function getAll() {}

    /**
     * Determine if a header exists with a specific key.
     *
     * @param string $name Key to lookup
     * @return boolean 
     */
    public function has($name) {}

    /**
     * Removes a single header by name
     *
     * @param string $name 
     */
    public function remove($name) {}

    /**
     * Parses an array or string of headers into the object
     *
     * @param string|array $content 
     * @return boolean 
     */
    public function parse($content) {}

    /**
     * Builds the headers and possibly the fields
     *
     * @param int $flags [Optional] Bitwise BUILD_* class constants. Default 0
     * @return array lines
     */
    public function build($flags = 0) {}

    /**
     * Returns the number of header fields
     *
     * @return int 
     */
    public function count() {}

    /**
     * Returns message text for a given HTTP status code
     *
     * @param int $code 
     * @return string|null 
     */
    public static function getStatusMessage($code) {}

}
