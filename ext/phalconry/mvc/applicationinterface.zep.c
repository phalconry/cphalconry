
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


ZEPHIR_INIT_CLASS(Phalconry_Mvc_ApplicationInterface) {

	ZEPHIR_REGISTER_INTERFACE(Phalconry\\Mvc, ApplicationInterface, phalconry, mvc_applicationinterface, phalconry_mvc_applicationinterface_method_entry);

	zend_class_implements(phalconry_mvc_applicationinterface_ce TSRMLS_CC, 1, zephir_get_internal_ce(SS("phalcon\\di\\injectionawareinterface") TSRMLS_CC));
	zend_class_implements(phalconry_mvc_applicationinterface_ce TSRMLS_CC, 1, zephir_get_internal_ce(SS("phalcon\\events\\eventsawareinterface") TSRMLS_CC));
	return SUCCESS;

}

/**
 * Sets the bootstrap object.
 *
 * @param \Phalconry\Mvc\Application\BootstrapInterface bootstrap
 */
ZEPHIR_DOC_METHOD(Phalconry_Mvc_ApplicationInterface, setBootstrap);

/**
 * Sets the request handler.
 *
 * @param \Phalconry\Mvc\Application\HandlerInterface handler
 */
ZEPHIR_DOC_METHOD(Phalconry_Mvc_ApplicationInterface, setHandler);

/**
 * Returns the Env object or an item from it.
 *
 * @param string key [Optional]
 * @return mixed|\Phalconry\Mvc\EnvironmentInterface
 */
ZEPHIR_DOC_METHOD(Phalconry_Mvc_ApplicationInterface, env);

/**
 * Returns the Env object.
 *
 * @return \Phalconry\Mvc\EnvironmentInterface
 */
ZEPHIR_DOC_METHOD(Phalconry_Mvc_ApplicationInterface, getEnvironment);

/**
 * Returns the application Config object.
 *
 * @return \Phalcon\Config
 */
ZEPHIR_DOC_METHOD(Phalconry_Mvc_ApplicationInterface, getConfig);

/**
 * Returns the module manager.
 *
 * @return Phalconry\Mvc\Module\ManagerInterface
 */
ZEPHIR_DOC_METHOD(Phalconry_Mvc_ApplicationInterface, getModuleManager);

/**
 * Returns the primary module.
 *
 * @return \Phalconry\Mvc\ModuleInterface
 */
ZEPHIR_DOC_METHOD(Phalconry_Mvc_ApplicationInterface, getPrimaryModule);

/**
 * Returns the dispatcher.
 *
 * @return \Phalcon\DispatcherInterface
 */
ZEPHIR_DOC_METHOD(Phalconry_Mvc_ApplicationInterface, getDispatcher);

/**
 * Loads a service through its provider.
 *
 * @param \Phalconry\Di\ServiceProviderInterface provider
 * @return \Phalconry\Mvc\ApplicationInterface
 */
ZEPHIR_DOC_METHOD(Phalconry_Mvc_ApplicationInterface, loadService);

/**
 * Loads an array of service providers.
 *
 * @param array providers
 * @return \Phalconry\Mvc\ApplicationInterface
 */
ZEPHIR_DOC_METHOD(Phalconry_Mvc_ApplicationInterface, loadServices);

/**
 * Bootstraps the application.
 *
 * @return void
 */
ZEPHIR_DOC_METHOD(Phalconry_Mvc_ApplicationInterface, bootstrap);

/**
 * Handles the request and returns a response.
 *
 * @param string uri [Optional]
 * @return mixed|\Phalcon\Http\ResponseInterface|boolean
 */
ZEPHIR_DOC_METHOD(Phalconry_Mvc_ApplicationInterface, handle);

/**
 * Sends the response.
 *
 * @param mixed|\Phalcon\Http\ResponseInterface response
 */
ZEPHIR_DOC_METHOD(Phalconry_Mvc_ApplicationInterface, respond);

/**
 * Checks whether the application has booted.
 *
 * @return boolean
 */
ZEPHIR_DOC_METHOD(Phalconry_Mvc_ApplicationInterface, isBooted);

