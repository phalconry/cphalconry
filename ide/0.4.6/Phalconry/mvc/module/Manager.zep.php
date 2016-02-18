<?php

namespace Phalconry\Mvc\Module;


class Manager extends Phalcon\Di\Phalcon\Di\Injectable implements \Phalconry\Mvc\Module\ManagerInterface
{
    /**
     * Modules
     *
     * @var array
     */
    protected $_modules = array();

    /**
     * Primary module name
     *
     * @var string
     */
    protected $_primaryName;

    /**
     * Default module name
     *
     * @var string
     */
    protected $_defaultName;


    /**
     * Sets the name of the primary module.
     *
     * @param string $moduleName 
     */
    public function setPrimaryModuleName($moduleName) {}

    /**
     * Returns the name of the primary module.
     *
     * @return string 
     */
    public function getPrimaryModuleName() {}

    /**
     * Sets the name of the default module.
     *
     * @param string $moduleName 
     */
    public function setDefaultModuleName($moduleName) {}

    /**
     * Returns the name of the default module.
     *
     * @return string 
     */
    public function getDefaultModuleName() {}

    /**
     * Registers an array of module definitions.
     *
     * @param array $definitions 
     * @return void 
     */
    public function registerModules($definitions) {}

    /**
     * Sets a module in the registry
     *
     * @param \Phalconry\Mvc\ModuleInterface $module 
     */
    public function addModule(\Phalconry\Mvc\ModuleInterface $module) {}

    /**
     * Returns a module by name, or the primary module if no name is given
     *
     * @param string $name Module name
     * @return \Phalconry\Mvc\ModuleInterface 
     */
    public function getModule($name) {}

    /**
     * Checks whether a module exists
     *
     * @param string|\Phalconry\Mvc\ModuleInterface $name 
     * @return boolean 
     */
    public function hasModule($name) {}

    /**
     * Returns the primary module
     *
     * @throws \Phalcon\Mvc\Exception if primary module is not set
     * @return \Phalconry\Mvc\ModuleInterface 
     */
    public function getPrimaryModule() {}

    /**
     * Loads a module
     *
     * @throws \Phalcon\Mvc\Exception if module has already been loaded
     * @param \Phalconry\Mvc\ModuleInterface $module 
     * @return \Phalconry\Mvc\ModuleInterface 
     */
    public function loadModule(\Phalconry\Mvc\ModuleInterface $module) {}

    /**
     * Whether a module has been loaded
     *
     * @throws \InvalidArgumentException if not given a Module object or string
     * @param mixed $module 
     * @param string|\Phalconry\Mvc\Module $$module 
     * @return boolean 
     */
    public function isLoaded($module) {}

    /**
     * Creates a module object from its name
     *
     * @throws \Phalcon\Mvc\Exception if module is not defined
     * @param mixed $definition 
     * @param string $$name Module name
     * @return \Phalconry\Mvc\ModuleInterface 
     */
    protected function createFromDefinition($definition) {}

}
