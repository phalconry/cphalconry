<?php

namespace Phalconry\Mvc;


class Env extends \Phalconry\Config implements \Phalconry\Mvc\EnvironmentInterface
{
    /**
     * Default environment identifier
     *
     * @var string
     */
    const DEFAULT_ENVIRONMENT = "production";

    /**
     * Default timezone identifier
     *
     * @var string
     */
    const DEFAULT_TIMEZONE = "UTC";

    /**
     * Environment name
     *
     * @var string
     */
    protected $env;

    /**
     * Timezone identifier
     *
     * @var string
     */
    protected $timezone;

    /**
     * Named directory paths
     *
     * @var \Phalcon\Registry
     */
    protected $paths;

    /**
     * Whether in command line mode.
     *
     * @var boolean
     */
    protected $cli;


    /**
     * Constructor.
     *
     * @param array $config 
     */
    public function __construct($config = array()) {}

    /**
     * Returns the environment name.
     *
     * @return string 
     */
    public function getEnvironment() {}

    /**
     * Returns the timezone.
     *
     * @return string 
     */
    public function getTimezone() {}

    /**
     * Sets the locale.
     *
     * @param string $locale 
     * @return \Phalconry\Mvc\EnvironmentInterface 
     */
    public function setLocale($locale) {}

    /**
     * Returns the locale name.
     *
     * @return string 
     */
    public function getLocale() {}

    /**
     * Sets the directory paths.
     *
     * @param mixed $paths Directory paths
     * @return \Phalconry\Mvc\EnvironmentInterface 
     */
    public function setPaths($paths) {}

    /**
     * Returns the directory paths.
     *
     * @return \Phalcon\Registry 
     */
    public function getPaths() {}

    /**
     * Sets a directory path by name.
     *
     * @param string $name 
     * @param string $path 
     * @return \Phalconry\Mvc\EnvironmentInterface 
     */
    public function setPath($name, $path) {}

    /**
     * Returns a directory path by name.
     *
     * @param string $name 
     * @return string 
     */
    public function getPath($name) {}

    /**
     * Returns a Config object for a given section.
     *
     * @throws \Phalcon\Exception if section exists but isn't a Config.
     * @param string $section Section name.
     * @return \Phalcon\Config 
     */
    public function getConfig($section) {}

    /**
     * Whether currently using command line.
     *
     * @return boolean 
     */
    public function isCli() {}

    /**
     * Allow read-only access to protected properties.
     *
     * @param string $key 
     * @return mixed 
     */
    public function __get($key) {}

    /**
     * Allow read-only access to protected properties.
     *
     * @param string $key 
     * @return boolean 
     */
    public function __isset($key) {}

    /**
     * Magic call
     *
     * @param string $func 
     * @param array $args 
     */
    public function __call($func, $args) {}

    /**
     * Returns the environment name.
     *
     * @return string 
     */
    public function __toString() {}

}
