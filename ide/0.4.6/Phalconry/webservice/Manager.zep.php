<?php

namespace Phalconry\WebService;

/**
 * Manager manages web services
 */
class Manager extends Phalcon\Di\Phalcon\Di\Injectable implements \Countable
{
    /**
     * @var \Phalconry\WebService\Factory
     */
    protected $_factory;

    /**
     * @var array
     */
    protected $_definitions = array();

    /**
     * @var array
     */
    protected $_services = array();


    /**
     * Sets a web service
     *
     * @param string $name Web service name
     * @param \Phalconry\WebService\ServiceInterface $service 
     */
    public function set($name, ServiceInterface $service) {}

    /**
     * Whether the given service exists
     *
     * @param mixed $service 
     * @param string|\Phalconry\WebService\ServiceInterface  
     * @return boolean 
     */
    public function has($service) {}

    /**
     * Returns a web service by name
     *
     * @throws \Phalconry\WebService\Exception
     * @param string $name Web service name
     * @return \Phalconry\WebService\ServiceInterface 
     */
    public function get($name) {}

    /**
     * Sets a web service definition
     *
     * @throws \InvalidArgumentException if definition is not string or callable
     * @param string $name Web service name
     * @param mixed $definition 
     * @param string|callable $Web service classname, or a callback that returns the object
     */
    public function setDefinition($name, $definition) {}

    /**
     * Whether a definition for the given web service exists
     *
     * @param string $name Web service name
     * @return boolean 
     */
    public function hasDefinition($name) {}

    /**
     * Returns a web service definition
     *
     * @param string $name 
     * @return string|callable|null 
     */
    public function getDefinition($name) {}

    /**
     * Whether a given web service is available
     *
     * @param string $service Web service name
     * @return boolean 
     */
    public function isAvailable($service) {}

    /**
     * Sets the web service factory
     *
     * @param \Phalconry\WebService\Factory $factory 
     */
    public function setFactory(Factory $factory) {}

    /**
     * Returns the web service factory, creating if not set
     *
     * @return \Phalconry\WebService\Factory 
     */
    public function getFactory() {}

    /**
     * Returns the number of registered web services
     *
     * @return int 
     */
    public function count() {}

}
