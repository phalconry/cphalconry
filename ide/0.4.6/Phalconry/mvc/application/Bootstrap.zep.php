<?php

namespace Phalconry\Mvc\Application;


class Bootstrap implements \Phalconry\Mvc\Application\BootstrapInterface
{
    /**
     * @var \Phalcon\Loader
     */
    protected $loader;


    /**
     * Boots the application.
     *
     * @param \Phalconry\Mvc\ApplicationInterface $app 
     * @return void 
     */
    public function boot(\Phalconry\Mvc\ApplicationInterface $app) {}

    /**
     * Configure loader
     *
     * @param mixed $di 
     * @param mixed $app 
     * @param mixed $loader 
     */
    protected function registerLoader(\Phalcon\DiInterface $di, \Phalconry\Mvc\ApplicationInterface $app, \Phalcon\Loader $loader) {}

    /**
     * Configure services
     *
     * @param mixed $di 
     * @param mixed $app 
     * @param mixed $loader 
     */
    protected function registerServices(\Phalcon\DiInterface $di, \Phalconry\Mvc\ApplicationInterface $app, \Phalcon\Loader $loader) {}

    /**
     * Configure modules
     *
     * @param mixed $di 
     * @param mixed $app 
     * @param mixed $loader 
     */
    protected function registerModules(\Phalcon\DiInterface $di, \Phalconry\Mvc\ApplicationInterface $app, \Phalcon\Loader $loader) {}

}
