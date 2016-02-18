<?php

namespace Phalconry\Events;


class GlobalManager extends Phalcon\Events\Phalcon\Events\Manager
{
    /**
     * @var boolean
     */
    static protected $_created;


    /**
     * Protected constructor.
     */
    protected function __construct() {}

    /**
     * Create the single GlobalManager instance.
     *
     * @throws \RuntimeException if called more than once per request.
     * @return \Phalconry\Events\GlobalManager 
     */
    public static function create() {}

}
