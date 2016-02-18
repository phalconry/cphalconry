<?php

namespace Phalconry\Mvc\Application;


interface HandlerInterface extends \Phalconry\Mvc\ApplicationAwareInterface
{

    /**
     * Handles the request and returns a response.
     *
     * @param string $uri [Optional]
     * @return \Phalcon\Http\ResponseInterface 
     */
    public function handle($uri = null);

}
