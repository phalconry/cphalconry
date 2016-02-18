<?php

namespace Phalconry\Mvc\Application;


interface BootstrapInterface
{

    /**
     * Boots the application.
     *
     * @param \Phalconry\Mvc\ApplicationInterface $app 
     * @return void 
     */
    public function boot(\Phalconry\Mvc\ApplicationInterface $app);

}
