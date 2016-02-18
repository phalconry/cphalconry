<?php

namespace Phalconry\Mvc;


interface ModuleInterface extends \Phalcon\Mvc\ModuleDefinitionInterface
{

    /**
     * Returns the module's controller namespace.
     *
     * @return string 
     */
    public function getControllerNamespace();

    /**
     * Sets the module's name.
     *
     * @param string $name 
     */
    public function setName($name);

    /**
     * Returns the module's name.
     *
     * @return string 
     */
    public function getName();

    /**
     * Sets the module manager.
     *
     * @param \Phalconry\Mvc\Module\ManagerInterface $manager 
     */
    public function setManager(\Phalconry\Mvc\Module\ManagerInterface $manager);

    /**
     * Returns the module manager.
     *
     * @return \Phalconry\Mvc\Module\ManagerInterface 
     */
    public function getManager();

    /**
     * Sets the application.
     *
     * @param \Phalconry\Mvc\ApplicationInterface $app 
     */
    public function setApp(ApplicationInterface $app);

    /**
     * Returns the application.
     *
     * @return \Phalconry\Mvc\ApplicationInterface 
     */
    public function getApp();

    /**
     * Checks whether the module is loaded.
     *
     * @return boolean 
     */
    public function isLoaded();

    /**
     * Checks whether the module is primary.
     *
     * @return boolean 
     */
    public function isPrimary();

    /**
     * Checks whether the module is the default.
     *
     * @return boolean 
     */
    public function isDefault();

}
