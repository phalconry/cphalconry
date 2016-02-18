<?php

namespace Phalconry\Mvc;


abstract class Plugin extends Phalcon\Di\Phalcon\Di\Injectable implements \Phalconry\Mvc\PluginInterface
{
    /**
     * @var string
     */
    protected $_path;

    /**
     * @var \Phalconry\Mvc\Plugin\Manager
     */
    protected $_manager;

    /**
     * @var \Phalcon\Config
     */
    protected $_config;


    /**
     * Returns the plugin's name.
     *
     * @return string 
     */
    public function getName() {}

    /**
     * Returns the path to the plugin's directory.
     *
     * @return string 
     */
    public function getPath() {}

    /**
     * Sets the plugins manager.
     *
     * @param \Phalconry\Mvc\Plugin\ManagerInterface $manager 
     * @return void 
     */
    public function setManager(\Phalconry\Mvc\Plugin\ManagerInterface $manager) {}

    /**
     * Returns the plugins manager.
     *
     * @return \Phalconry\Mvc\Plugin\ManagerInterface 
     */
    public function getManager() {}

    /**
     * Returns the plugin's Config object.
     *
     * @return \Phalcon\Config|null 
     */
    public function getConfig() {}

    /**
     * Checks whether the plugin is loaded.
     *
     * @return boolean 
     */
    public function isLoaded() {}

}
