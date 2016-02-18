<?php

namespace Phalconry\Mvc;


class Application implements \Phalconry\Mvc\ApplicationInterface
{
    /**
     * Dependency injection container.
     *
     * @var \Phalcon\DiInterface
     */
    protected $_dependencyInjector;

    /**
     * Events manager.
     *
     * @var \Phalcon\Events\ManagerInterface
     */
    protected $_eventsManager;

    /**
     * Application bootstrap.
     *
     * @var \Phalconry\Mvc\Application\BootstrapInterface
     */
    protected $_bootstrap;

    /**
     * Main request handler.
     *
     * @var \Phalconry\Mvc\Application\HandlerInterface
     */
    protected $_handler;

    /**
     * Whether the app has been booted.
     *
     * @var boolean
     */
    protected $_booted = false;


    /**
     * Application constructor.
     *
     * @param \Phalcon\DiInterface $di [Optional]
     * @param \Phalconry\Mvc\EnvironmentInterface $env [Optional]
     */
    public function __construct(\Phalcon\DiInterface $di = null, EnvironmentInterface $env = null) {}

    /**
     * Sets the dependency injector
     *
     * @param \Phalcon\DiInterface $dependencyInjector 
     */
    public function setDI(\Phalcon\DiInterface $dependencyInjector) {}

    /**
     * Returns the internal dependency injector
     *
     * @return \Phalcon\DiInterface 
     */
    public function getDI() {}

    /**
     * Sets the events manager.
     *
     * @param \Phalcon\Events\ManagerInterface $eventsManager 
     */
    public function setEventsManager(\Phalcon\Events\ManagerInterface $eventsManager) {}

    /**
     * Returns the internal event manager.
     *
     * @return \Phalcon\Events\ManagerInterface 
     */
    public function getEventsManager() {}

    /**
     * Returns the module manager.
     *
     * @return \Phalconry\Mvc\Module\ManagerInterface 
     */
    public function getModuleManager() {}

    /**
     * Returns the primary module.
     *
     * @return \Phalconry\Mvc\ModuleInterface 
     */
    public function getPrimaryModule() {}

    /**
     * Returns the dispatcher.
     *
     * @return \Phalcon\Mvc\DispatcherInterface 
     */
    public function getDispatcher() {}

    /**
     * Returns the Env object.
     *
     * @return \Phalconry\Mvc\EnvironmentInterface 
     */
    public function getEnvironment() {}

    /**
     * Returns the application Config object.
     *
     * @return \Phalcon\Config 
     */
    public function getConfig() {}

    /**
     * Returns the global environment instance or an item from it
     *
     * @param string $key [Optional] Item to fetch from Env. If omitted, the Env object is returned.
     * @return \Phalconry\Mvc\EnvironmentInterface|\Phalcon\Config|mixed 
     */
    public function env($key = null) {}

    /**
     * Returns a directory path
     *
     * @param string $name Path name.
     * @return string 
     */
    public function getPath($name) {}

    /**
     * Sets a named directory path.
     *
     * @param string $name Path name.
     * @param string $value Absolute directory path.
     */
    public function setPath($name, $value) {}

    /**
     * Sets the bootstrap object.
     *
     * @param \Phalconry\Mvc\Application\BootstrapInterface $bootstrap 
     */
    public function setBootstrap(\Phalconry\Mvc\Application\BootstrapInterface $bootstrap) {}

    /**
     * Sets the request handler.
     *
     * @param \Phalconry\Mvc\Application\HandlerInterface $handler 
     */
    public function setHandler(\Phalconry\Mvc\Application\HandlerInterface $handler) {}

    /**
     * Whether the application has booted.
     *
     * @return boolean 
     */
    public function isBooted() {}

    /**
     * Loads a service through its provider.
     *
     * @param \Phalconry\Di\ServiceProviderInterface $provider 
     * @return \Phalconry\Mvc\ApplicationInterface 
     */
    public function loadService(\Phalconry\Di\ServiceProviderInterface $provider) {}

    /**
     * Loads an array of service providers.
     *
     * @param array $providers 
     * @return \Phalconry\Mvc\ApplicationInterface 
     */
    public function loadServices($providers) {}

    /**
     * Runs the application and sends the response.
     *
     * @return void 
     */
    public function run() {}

    /**
     * Boot the application.
     *
     * @return boolean 
     */
    public function bootstrap() {}

    /**
     * Handles a MVC request
     *
     * @param string $uri 
     * @return mixed|\Phalcon\Http\ResponseInterface|boolean 
     */
    public function handle($uri = null) {}

    /**
     * Sends the response.
     *
     * @param mixed|\Phalcon\Http\ResponseInterface $response 
     */
    public function respond($response = null) {}

}
