<?php

namespace Phalconry\Mvc;


class Responder extends Phalcon\Mvc\User\Phalcon\Mvc\User\Component
{
    /**
     * Designates a "view" response
     *
     * @var string
     */
    const TYPE_VIEW = "view";

    /**
     * Designates a "text" response
     *
     * @var string
     */
    const TYPE_TEXT = "text";

    /**
     * Designates a "json" response
     *
     * @var string
     */
    const TYPE_JSON = "json";

    /**
     * Designates an "xml" response
     *
     * @var string
     */
    const TYPE_XML = "xml";

    /**
     * Response type
     *
     * @var string
     */
    protected $_type = "view";

    /**
     * Response types that send structured data
     *
     * @var array
     */
    protected $_dataTypes = array("json", "xml");

    /**
     * The response
     *
     * @var \Phalcon\Http\ResponseInterface
     */
    protected $_response;

    /**
     * Response data
     *
     * @var mixed
     */
    protected $_responseData;

    /**
     * Prepended response data
     *
     * @var array
     */
    protected $_beforeData = array();

    /**
     * Appended response data
     *
     * @var array
     */
    protected $_afterData = array();

    /**
     * Response options
     *
     * @var int
     */
    protected $_options = 0;


    /**
     * Sets the type of response
     *
     * @param string $type Response type
     */
    public function setType($type) {}

    /**
     * Returns the response type
     *
     * @return string 
     */
    public function getType() {}

    /**
     * Whether the current response type is identical to the type given
     *
     * @param string $type 
     * @return bool 
     */
    public function isType($type) {}

    /**
     * Whether the given or current response type returns structured data
     *
     * @param string $type [Optional] Default is null, returns if current type is data
     * @return bool 
     */
    public function isDataType($type = null) {}

    /**
     * Modifies and sends the response
     * If the controller returns boolean false or the response object, no modification takes place.
     * If this->fillEmptyContent() == true (default), attempts to fill empty response content with
     * the value returned by the controller.
     *
     * @param \Phalcon\Http\ResponseInterface $response 
     */
    public function respond(\Phalcon\Http\ResponseInterface $response) {}

    /**
     * @param mixed $options 
     */
    public function setOptions($options) {}


    public function getOptions() {}

    /**
     * @param int $option 
     */
    public function addOption($option) {}

    /**
     * @param string $key 
     * @param mixed $value 
     */
    public function prependResponseData($key, $value) {}

    /**
     * @param string $key 
     * @param mixed $value 
     */
    public function appendResponseData($key, $value) {}

    /**
     * @param mixed $response 
     */
    protected function formatResponse(\Phalcon\Http\ResponseInterface $response) {}

    /**
     * @param mixed $response 
     */
    protected function formatText(\Phalcon\Http\ResponseInterface $response) {}

    /**
     * @param mixed $response 
     */
    protected function formatJson(\Phalcon\Http\ResponseInterface $response) {}

    /**
     * @param mixed $response 
     */
    protected function formatXml(\Phalcon\Http\ResponseInterface $response) {}

    /**
     * @param mixed $response 
     */
    protected function formatDataResponse(\Phalcon\Http\ResponseInterface $response) {}

    /**
     * @return array 
     */
    protected function buildDataResponseContent() {}

}
