<?php

namespace Phalconry\Mvc\Plugin;

/**
 * Contract for a plugin manager.
 */
interface ManagerInterface
{

    /**
     * Sets the plugin base namespace.
     *
     * @param string $pluginNamespace 
     * @return void 
     */
    public function setNamespace($pluginNamespace);

    /**
     * Returns the plugin base namespace.
     *
     * @return string 
     */
    public function getNamespace();

    /**
     * Sets the plugin directory path.
     *
     * @throws \InvalidArgumentException if path is invalid.
     * @param string $dirPath 
     * @return void 
     */
    public function setPath($dirPath);

    /**
     * Returns the plugin directory path.
     *
     * @return string|null 
     */
    public function getPath();

    /**
     * Returns the classname of a plugin.
     *
     * @param string $name 
     * @return string 
     */
    public function getPluginClassname($name);

    /**
     * Builds the path to a plugin file.
     *
     * @param string $name 
     * @return string|null 
     */
    public function getPluginFilePath($name);

    /**
     * Registers a plugin as an object or by class.
     *
     * @param string|\Phalconry\Mvc\PluginInterface $classname 
     * @return \Phalconry\Mvc\Plugin\ManagerInterface 
     */
    public function register($classname);

    /**
     * Registers a plugin object.
     *
     * @param \Phalconry\Mvc\PluginInterface $plugin 
     * @return \Phalconry\Mvc\Plugin\ManagerInterface 
     */
    public function add(\Phalconry\Mvc\PluginInterface $plugin);

    /**
     * Returns a plugin by name.
     * If the plugin has not been registered, it will be located.
     *
     * @param string $name 
     * @return \Phalconry\Mvc\PluginInterface|null 
     */
    public function get($name);

    /**
     * Checks if a plugin has been registered.
     *
     * @param string|\Phalconry\Mvc\PluginInterface $plugin 
     * @return boolean 
     */
    public function isRegistered($plugin);

    /**
     * Checks if a plugin has been loaded.
     *
     * @param string|\Phalconry\Mvc\PluginInterface $plugin 
     * @return boolean 
     */
    public function isLoaded($plugin);

    /**
     * Loads a plugin.
     *
     * @param string|\Phalconry\Mvc\PluginInterface $plugin 
     * @return \Phalconry\Mvc\PluginInterface 
     */
    public function load($plugin);

}
