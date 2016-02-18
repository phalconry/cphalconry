<?php

namespace Phalconry\Di;


interface ServiceProviderInterface
{

    /**
     * Registers the service components
     *
     * @param mixed $di 
     * @param \Phalcon\DiInterface $$di 
     */
    public function register(\Phalcon\DiInterface $di);

}
