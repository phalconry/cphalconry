<?php

namespace Phalconry\WebService;

/**
 * Factory creates web services from definitions
 */
class Factory extends Phalcon\Di\Phalcon\Di\Injectable
{

    /**
     * Create a web service from a definition
     *
     * @throws \Phalconry\WebService\Exception if service cannot be created
     * @throws \UnexpectedValueException if the definition does not resolve to an instance of ServiceInterface
     * @param mixed $definition 
     * @param mixed $$definition Callable, classname, or file
     * @return \Phalconry\WebService\ServiceInterface 
     */
    public function create($definition) {}

}
