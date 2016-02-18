<?php

namespace Phalconry\Mvc\Plugin;


class Manager extends Phalcon\Di\Phalcon\Di\Injectable implements \Phalconry\Mvc\Plugin\ManagerInterface
{
    /**
     * @var string
     */
    protected $_namespace = "Plugin\\\\";

    /**
     * @var string
     */
    protected $_path;

    /**
     * @var array
     */
    protected $_plugins = array();

    /**
     * @var array
     */
    protected $_loaded = array();


    /**
     * Sets the plugin base namespace.
     *
     * @param string $pluginNamespace 
     * @param string $namespace 
     * @return void 
     */
    public function setNamespace($pluginNamespace) {}

    /**
     * Returns the plugin base namespace.
     * Default is "Plugin\"
     *
     * @return string 
     */
    public function getNamespace() {}

    /**
     * Sets the plugin directory path.
     *
     * @param string $dirPath 
     * @return void 
     */
    public function setPath($dirPath) {}

    /**
     * Returns the plugin directory path.
     *
     * @return string|null 
     */
    public function getPath() {}

    /**
     * Returns the classname of a plugin.
     *
     * @param string $name 
     * @return string 
     */
    public function getPluginClassname($name) {}

    /**
     * Builds the path to a plugin file.
     *
     * @param string $name 
     * @return string|null 
     */
    public function getPluginFilePath($name) {}

    /**
     * Registers a plugin as an object or by class.
     *
     * @throws \InvalidArgumentException if plugin is not string or PluginInterface.
     * @throws \Phalconry\Mvc\Plugin\Exception if plugin class cannot be found.
     * @param string|\Phalconry\Mvc\PluginInterface $classname 
     * @return \Phalconry\Mvc\Plugin\ManagerInterface 
     */
    public function register($classname) {}

    /**
     * Registers a plugin object.
     *
     * @param \Phalconry\Mvc\PluginInterface $plugin 
     * @return \Phalconry\Mvc\Plugin\ManagerInterface 
     */
    public function add(\Phalconry\Mvc\PluginInterface $plugin) {}

    /**
     * Returns a plugin by name.
     * If the plugin has not been registered, it will be located.
     *
     * @param string $name 
     * @return \Phalconry\Mvc\PluginInterface 
     */
    public function get($name) {}

    /**
     * Checks if a plugin has been registered.
     *
     * @param string|\Phalconry\Mvc\PluginInterface $plugin 
     * @return boolean 
     */
    public function isRegistered($plugin) {}

    /**
     * Checks if a plugin has been loaded.
     *
     * @param string|\Phalconry\Mvc\PluginInterface $plugin 
     * @return boolean 
     */
    public function isLoaded($plugin) {}

    /**
     * Loads a plugin.
     *
     * @param string|\Phalconry\Mvc\PluginInterface $plugin 
     * @return \Phalconry\Mvc\PluginInterface 
     */
    public function load($plugin) {}

    /**
     * Locates a plugin in the plugin directory.
     *
     * @throws \Phalconry\Mvc\Plugin\Exception if an invalid plugin is injected.
     * @param string $name 
     * @return \Phalconry\Mvc\PluginInterface|null 
     */
    protected function locatePlugin($name) {}

}
