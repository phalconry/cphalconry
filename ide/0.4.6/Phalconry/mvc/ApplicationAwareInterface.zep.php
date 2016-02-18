<?php

namespace Phalconry\Mvc;


interface ApplicationAwareInterface
{

    /**
     * Sets the application.
     *
     * @param \Phalconry\Mvc\ApplicationInterface $app 
     * @return void 
     */
    public function setApplication(ApplicationInterface $app);

    /**
     * Returns the application.
     *
     * @return \Phalconry\Mvc\ApplicationInterface 
     */
    public function getApplication();

}
