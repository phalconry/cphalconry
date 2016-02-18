
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


ZEPHIR_INIT_CLASS(Phalconry_Mvc_ModuleInterface) {

	ZEPHIR_REGISTER_INTERFACE(Phalconry\\Mvc, ModuleInterface, phalconry, mvc_moduleinterface, phalconry_mvc_moduleinterface_method_entry);

	zend_class_implements(phalconry_mvc_moduleinterface_ce TSRMLS_CC, 1, zephir_get_internal_ce(SS("phalcon\\mvc\\moduledefinitioninterface") TSRMLS_CC));
	return SUCCESS;

}

/**
 * Returns the module's controller namespace.
 *
 * @return string
 */
ZEPHIR_DOC_METHOD(Phalconry_Mvc_ModuleInterface, getControllerNamespace);

/**
 * Sets the module's name.
 *
 * @param string name
 */
ZEPHIR_DOC_METHOD(Phalconry_Mvc_ModuleInterface, setName);

/**
 * Returns the module's name.
 *
 * @return string
 */
ZEPHIR_DOC_METHOD(Phalconry_Mvc_ModuleInterface, getName);

/**
 * Sets the module manager.
 *
 * @param \Phalconry\Mvc\Module\ManagerInterface manager
 */
ZEPHIR_DOC_METHOD(Phalconry_Mvc_ModuleInterface, setManager);

/**
 * Returns the module manager.
 *
 * @return \Phalconry\Mvc\Module\ManagerInterface
 */
ZEPHIR_DOC_METHOD(Phalconry_Mvc_ModuleInterface, getManager);

/**
 * Sets the application.
 *
 * @param \Phalconry\Mvc\ApplicationInterface app
 */
ZEPHIR_DOC_METHOD(Phalconry_Mvc_ModuleInterface, setApp);

/**
 * Returns the application.
 *
 * @return \Phalconry\Mvc\ApplicationInterface
 */
ZEPHIR_DOC_METHOD(Phalconry_Mvc_ModuleInterface, getApp);

/**
 * Checks whether the module is loaded.
 *
 * @return boolean
 */
ZEPHIR_DOC_METHOD(Phalconry_Mvc_ModuleInterface, isLoaded);

/**
 * Checks whether the module is primary.
 *
 * @return boolean
 */
ZEPHIR_DOC_METHOD(Phalconry_Mvc_ModuleInterface, isPrimary);

/**
 * Checks whether the module is the default.
 *
 * @return boolean
 */
ZEPHIR_DOC_METHOD(Phalconry_Mvc_ModuleInterface, isDefault);

