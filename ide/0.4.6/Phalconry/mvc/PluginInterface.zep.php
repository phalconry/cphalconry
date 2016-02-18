<?php

namespace Phalconry\Mvc;


interface PluginInterface
{

    /**
     * Returns the plugin's name.
     *
     * @return string 
     */
    public function getName();

    /**
     * Returns the path to the plugin's directory.
     *
     * @return string 
     */
    public function getPath();

    /**
     * Sets the plugins manager.
     *
     * @param \Phalconry\Mvc\Plugin\ManagerInterface $manager 
     * @return void 
     */
    public function setManager(\Phalconry\Mvc\Plugin\ManagerInterface $manager);

    /**
     * Returns the plugins manager.
     *
     * @return \Phalconry\Mvc\Plugin\ManagerInterface 
     */
    public function getManager();

    /**
     * Returns the plugin's Config object.
     *
     * @return \Phalcon\Config|null 
     */
    public function getConfig();

    /**
     * Checks whether the plugin is loaded.
     * The simplest way to implement this method is to check if the manager exists.
     *
     * @return boolean 
     */
    public function isLoaded();

    /**
     * Loads the plugin.
     *
     * @throws \Phalconry\Mvc\Plugin\Exception
     * @param \Phalcon\DiInterface $di 
     */
    public function load(\Phalcon\DiInterface $di);

}
