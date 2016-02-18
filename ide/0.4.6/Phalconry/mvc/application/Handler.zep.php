<?php

namespace Phalconry\Mvc\Application;


class Handler implements \Phalconry\Mvc\Application\HandlerInterface
{
    /**
     * The application instance.
     *
     * @var \Phalconry\Mvc\ApplicationInterface
     */
    protected $_application;


    /**
     * Constructor - sets the application.
     *
     * @param \Phalconry\Mvc\ApplicationInterface $app 
     */
    public function __construct(\Phalconry\Mvc\ApplicationInterface $app) {}

    /**
     * Sets the application.
     *
     * @param \Phalconry\Mvc\ApplicationInterface $app 
     * @return void 
     */
    public function setApplication(\Phalconry\Mvc\ApplicationInterface $app) {}

    /**
     * Returns the application.
     *
     * @return \Phalconry\Mvc\ApplicationInterface 
     */
    public function getApplication() {}

    /**
     * Handles a MVC request
     *
     * @param string $uri 
     * @return \Phalcon\Http\ResponseInterface|boolean 
     */
    public function handle($uri = null) {}

}
