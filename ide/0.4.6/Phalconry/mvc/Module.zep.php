<?php

namespace Phalconry\Mvc;


abstract class Module implements \Phalconry\Mvc\ModuleInterface, \Phalcon\Di\InjectionAwareInterface
{
    /**
     * Dependency injector.
     *
     * @param \Phalcon\DiInterface
     */
    protected $_dependencyInjector;

    /**
     * Module name.
     *
     * @var string
     */
    protected $_name;

    /**
     * Application.
     *
     * @var \Phalconry\Mvc\ApplicationInterface
     */
    protected $_application;

    /**
     * Module manager.
     *
     * @var \Phalconry\Mvc\Module\ManagerInterface
     */
    protected $_manager;


    /**
     * Sets the dependency injector.
     *
     * @param \Phalcon\DiInterface $di 
     */
    public function setDI(\Phalcon\DiInterface $di) {}

    /**
     * Returns the dependency injector.
     *
     * @return \Phalcon\DiInterface 
     */
    public function getDI() {}

    /**
     * Sets the module's name.
     *
     * @param string $name 
     */
    public function setName($name) {}

    /**
     * Returns the module's name.
     *
     * @return string 
     */
    public function getName() {}

    /**
     * Sets the module manager.
     *
     * @param \Phalconry\Mvc\Module\ManagerInterface $manager 
     */
    public function setManager(\Phalconry\Mvc\Module\ManagerInterface $manager) {}

    /**
     * Returns the module manager.
     *
     * @return \Phalconry\Mvc\Module\ManagerInterface 
     */
    public function getManager() {}

    /**
     * Sets the application.
     *
     * @param \Phalconry\Mvc\ApplicationInterface $app 
     */
    public function setApp(ApplicationInterface $app) {}

    /**
     * Returns the application.
     *
     * @return \Phalconry\Mvc\ApplicationInterface 
     */
    public function getApp() {}

    /**
     * Checks whether the module is loaded.
     *
     * @return boolean 
     */
    public function isLoaded() {}

    /**
     * Checks whether the module is primary.
     *
     * @return boolean 
     */
    public function isPrimary() {}

    /**
     * Checks whether the module is the default.
     *
     * @return boolean 
     */
    public function isDefault() {}

    /**
     * Registers the module autoloaders.
     *
     * @param mixed $di 
     */
    public function registerAutoloaders(\Phalcon\DiInterface $di = null) {}

    /**
     * Registers the module services.
     *
     * @param mixed $di 
     */
    public function registerServices(\Phalcon\DiInterface $di) {}

}
