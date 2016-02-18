<?php

namespace Phalconry\Mvc\Hmvc;

/**
 * Wrapper for an HMVC request.
 */
class Request extends Phalcon\Di\Phalcon\Di\Injectable
{
    /**
     * Module name
     *
     * @var string
     */
    protected $_module;

    /**
     * Controller name
     *
     * @var string
     */
    protected $_controller;

    /**
     * Action name
     *
     * @var string
     */
    protected $_action;

    /**
     * Request parameters
     *
     * @var array
     */
    protected $_params;

    /**
     * Request response
     *
     * @var mixed
     */
    protected $_response;


    /**
     * HmvcRequest constructor.
     *
     * @param array $args [Optional] Request args {@see Request::set()}
     */
    public function __construct($args = array()) {}

    /**
     * Sets module, controller, action, and/or params from an array.
     *
     * @param array $args 
     * @return \Phalconry\Mvc\Hmvc\Request 
     */
    public function setLocation($args) {}

    /**
     * Sets the module name
     *
     * @param string $module Module name
     * @return \Phalconry\Mvc\Hmvc\Request 
     */
    public function setModuleName($module) {}

    /**
     * Whether a module name is set
     *
     * @return boolean 
     */
    public function hasModuleName() {}

    /**
     * Returns the module name
     *
     * @return string 
     */
    public function getModuleName() {}

    /**
     * Sets the controller name
     *
     * @param string $controller Controller name
     * @return \Phalconry\Mvc\Hmvc\Request 
     */
    public function setControllerName($controller) {}

    /**
     * Whether the controller name is set
     *
     * @return boolean 
     */
    public function hasControllerName() {}

    /**
     * Returns the controller name
     *
     * @return string 
     */
    public function getControllerName() {}

    /**
     * Sets the action name
     *
     * @param string $action Action name
     * @return \Phalconry\Mvc\Hmvc\Request 
     */
    public function setActionName($action) {}

    /**
     * Whether the action name is set
     *
     * @return boolean 
     */
    public function hasActionName() {}

    /**
     * Returns the action name
     *
     * @return string 
     */
    public function getActionName() {}

    /**
     * Sets the request parameters
     *
     * @param array $params 
     * @return \Phalconry\Mvc\Hmvc\Request 
     */
    public function setParams($params) {}

    /**
     * Whether any parameters are set
     *
     * @return boolean 
     */
    public function hasParams() {}

    /**
     * Returns the request parameters
     *
     * @return array 
     */
    public function getParams() {}

    /**
     * Returns the response
     *
     * @return mixed 
     */
    public function getResponse() {}

    /**
     * Dispatches the request and returns a response
     *
     * @param array $args [Optional]
     * @return mixed 
     */
    public function __invoke($args = null) {}

}
