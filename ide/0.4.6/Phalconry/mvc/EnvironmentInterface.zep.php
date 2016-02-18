<?php

namespace Phalconry\Mvc;


interface EnvironmentInterface
{

    /**
     * Whether currently using command line.
     *
     * @return boolean 
     */
    public function isCli();

    /**
     * Returns the environment name.
     *
     * @return string 
     */
    public function getEnvironment();

    /**
     * Returns the timezone.
     *
     * @return string 
     */
    public function getTimezone();

    /**
     * Sets the locale.
     *
     * @param string $locale 
     * @return \Phalconry\Mvc\EnvironmentInterface 
     */
    public function setLocale($locale);

    /**
     * Returns the locale name.
     *
     * @return string|null 
     */
    public function getLocale();

    /**
     * Sets the directory paths.
     *
     * @param mixed $paths Directory paths
     * @return \Phalconry\Mvc\EnvironmentInterface 
     */
    public function setPaths($paths);

    /**
     * Returns the directory paths.
     *
     * @return \Phalcon\Registry|\Phalcon\Config 
     */
    public function getPaths();

    /**
     * Sets a directory path by name.
     *
     * @param string $name 
     * @param string $path 
     * @return \Phalconry\Mvc\EnvironmentInterface 
     */
    public function setPath($name, $path);

    /**
     * Returns a directory path by name.
     *
     * @param string $name 
     * @return string 
     */
    public function getPath($name);

    /**
     * Returns a Config object for a given section.
     *
     * @throws \Phalconry\Exception if section exists but isn't a Config.
     * @param string $section Section name.
     * @return \Phalconry\Config 
     */
    public function getConfig($section);

    /**
     * Get an item using "dot" notation.
     *
     * @param string $key 
     * @param mixed $defaultValue [Optional]
     * @return mixed 
     */
    public function get($key, $defaultValue = null);

    /**
     * Set an item using "dot" notation.
     *
     * @param string $key 
     * @param mixed $value 
     * @param mixed $defaultValue 
     * @return mixed 
     */
    public function set($key, $value);

    /**
     * Check if an item exists using "dot" notation.
     *
     * @param string $key 
     * @return bool 
     */
    public function has($key);

}
