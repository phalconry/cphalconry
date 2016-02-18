<?php

namespace Phalconry;


class Config extends Phalcon\Phalcon\Config
{
    /**
     * @var object
     */
    protected $_configParent;


    /**
     * Sets the parent object.
     *
     * @param object $parentObject 
     */
    public function setParent($parentObject) {}

    /**
     * Returns the parent object.
     *
     * @return object|null 
     */
    public function getParent() {}

    /**
     * Checks whether the config has a parent object.
     *
     * @return boolean 
     */
    public function hasParent() {}

    /**
     * Sets an attribute using the array-syntax
     * <code>
     * $config['database'] = array('type' => 'Sqlite');
     * </code>
     *
     * @param mixed $index 
     * @param mixed $value 
     */
    public function offsetSet($index, $value) {}

    /**
     * Returns a Config object for a given section.
     *
     * @throws \Phalconry\Exception if section exists but isn't a Config.
     * @param string $section Section name.
     * @return \Phalconry\Config 
     */
    public function getConfig($section) {}

    /**
     * Get an item using "dot" notation.
     *
     * @param string $key 
     * @param mixed $defaultValue 
     * @return mixed 
     */
    public function get($key, $defaultValue = null) {}

    /**
     * Set an item using "dot" notation.
     *
     * @param string $key 
     * @param mixed $value 
     * @return \Phalconry\Config 
     */
    public function set($key, $value) {}

    /**
     * Check if an item exists using "dot" notation.
     *
     * @param string $key 
     * @return bool 
     */
    public function has($key) {}

    /**
     * Restores the state of a Phalcon\Config object
     *
     * @param array $data 
     * @return Config 
     */
    public static function __set_state($data) {}

}
