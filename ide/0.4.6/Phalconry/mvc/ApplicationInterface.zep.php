<?php

namespace Phalconry\Mvc;


interface ApplicationInterface extends \Phalcon\Di\InjectionAwareInterface, \Phalcon\Events\EventsAwareInterface
{

    /**
     * Sets the bootstrap object.
     *
     * @param \Phalconry\Mvc\Application\BootstrapInterface $bootstrap 
     */
    public function setBootstrap(\Phalconry\Mvc\Application\BootstrapInterface $bootstrap);

    /**
     * Sets the request handler.
     *
     * @param \Phalconry\Mvc\Application\HandlerInterface $handler 
     */
    public function setHandler(\Phalconry\Mvc\Application\HandlerInterface $handler);

    /**
     * Returns the Env object or an item from it.
     *
     * @param string $key [Optional]
     * @return mixed|\Phalconry\Mvc\EnvironmentInterface 
     */
    public function env($key = null);

    /**
     * Returns the Env object.
     *
     * @return \Phalconry\Mvc\EnvironmentInterface 
     */
    public function getEnvironment();

    /**
     * Returns the application Config object.
     *
     * @return \Phalcon\Config 
     */
    public function getConfig();

    /**
     * Returns the module manager.
     *
     * @return Phalconry\Mvc\Module\ManagerInterface 
     */
    public function getModuleManager();

    /**
     * Returns the primary module.
     *
     * @return \Phalconry\Mvc\ModuleInterface 
     */
    public function getPrimaryModule();

    /**
     * Returns the dispatcher.
     *
     * @return \Phalcon\DispatcherInterface 
     */
    public function getDispatcher();

    /**
     * Loads a service through its provider.
     *
     * @param \Phalconry\Di\ServiceProviderInterface $provider 
     * @return \Phalconry\Mvc\ApplicationInterface 
     */
    public function loadService(\Phalconry\Di\ServiceProviderInterface $provider);

    /**
     * Loads an array of service providers.
     *
     * @param array $providers 
     * @return \Phalconry\Mvc\ApplicationInterface 
     */
    public function loadServices($providers);

    /**
     * Bootstraps the application.
     *
     * @return void 
     */
    public function bootstrap();

    /**
     * Handles the request and returns a response.
     *
     * @param string $uri [Optional]
     * @return mixed|\Phalcon\Http\ResponseInterface|boolean 
     */
    public function handle($uri = null);

    /**
     * Sends the response.
     *
     * @param mixed|\Phalcon\Http\ResponseInterface $response 
     */
    public function respond($response = null);

    /**
     * Checks whether the application has booted.
     *
     * @return boolean 
     */
    public function isBooted();

}
