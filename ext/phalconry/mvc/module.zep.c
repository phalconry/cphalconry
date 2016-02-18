
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/object.h"
#include "kernel/memory.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"
#include "kernel/operators.h"
#include "kernel/fcall.h"


ZEPHIR_INIT_CLASS(Phalconry_Mvc_Module) {

	ZEPHIR_REGISTER_CLASS(Phalconry\\Mvc, Module, phalconry, mvc_module, phalconry_mvc_module_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	/**
	 * Dependency injector.
	 *
	 * @param \Phalcon\DiInterface
	 */
	zend_declare_property_null(phalconry_mvc_module_ce, SL("_dependencyInjector"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * Module name.
	 *
	 * @var string
	 */
	zend_declare_property_null(phalconry_mvc_module_ce, SL("_name"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * Application.
	 *
	 * @var \Phalconry\Mvc\ApplicationInterface
	 */
	zend_declare_property_null(phalconry_mvc_module_ce, SL("_application"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * Module manager.
	 *
	 * @var \Phalconry\Mvc\Module\ManagerInterface
	 */
	zend_declare_property_null(phalconry_mvc_module_ce, SL("_manager"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_class_implements(phalconry_mvc_module_ce TSRMLS_CC, 1, phalconry_mvc_moduleinterface_ce);
	zend_class_implements(phalconry_mvc_module_ce TSRMLS_CC, 1, zephir_get_internal_ce(SS("phalcon\\di\\injectionawareinterface") TSRMLS_CC));
	return SUCCESS;

}

/**
 * Sets the dependency injector.
 *
 * @param \Phalcon\DiInterface di
 */
PHP_METHOD(Phalconry_Mvc_Module, setDI) {

	zval *di;

	zephir_fetch_params(0, 1, 0, &di);



	zephir_update_property_this(this_ptr, SL("_dependencyInjector"), di TSRMLS_CC);

}

/**
 * Returns the dependency injector.
 *
 * @return \Phalcon\DiInterface
 */
PHP_METHOD(Phalconry_Mvc_Module, getDI) {


	RETURN_MEMBER(this_ptr, "_dependencyInjector");

}

/**
 * Sets the module's name.
 *
 * @param string name
 */
PHP_METHOD(Phalconry_Mvc_Module, setName) {

	zval *name_param = NULL;
	zval *name = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name_param);

	if (unlikely(Z_TYPE_P(name_param) != IS_STRING && Z_TYPE_P(name_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'name' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(name_param) == IS_STRING)) {
		zephir_get_strval(name, name_param);
	} else {
		ZEPHIR_INIT_VAR(name);
		ZVAL_EMPTY_STRING(name);
	}


	zephir_update_property_this(this_ptr, SL("_name"), name TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

/**
 * Returns the module's name.
 *
 * @return string
 */
PHP_METHOD(Phalconry_Mvc_Module, getName) {


	RETURN_MEMBER(this_ptr, "_name");

}

/**
 * Sets the module manager.
 *
 * @param \Phalconry\Mvc\Module\ManagerInterface manager
 */
PHP_METHOD(Phalconry_Mvc_Module, setManager) {

	zval *manager;

	zephir_fetch_params(0, 1, 0, &manager);



	zephir_update_property_this(this_ptr, SL("_manager"), manager TSRMLS_CC);

}

/**
 * Returns the module manager.
 *
 * @return \Phalconry\Mvc\Module\ManagerInterface
 */
PHP_METHOD(Phalconry_Mvc_Module, getManager) {


	RETURN_MEMBER(this_ptr, "_manager");

}

/**
 * Sets the application.
 *
 * @param \Phalconry\Mvc\ApplicationInterface app
 */
PHP_METHOD(Phalconry_Mvc_Module, setApp) {

	zval *app;

	zephir_fetch_params(0, 1, 0, &app);



	zephir_update_property_this(this_ptr, SL("_application"), app TSRMLS_CC);

}

/**
 * Returns the application.
 *
 * @return \Phalconry\Mvc\ApplicationInterface
 */
PHP_METHOD(Phalconry_Mvc_Module, getApp) {


	RETURN_MEMBER(this_ptr, "_application");

}

/**
 * Checks whether the module is loaded.
 *
 * @return boolean
 */
PHP_METHOD(Phalconry_Mvc_Module, isLoaded) {

	zval *_0;

	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(_0);
	zephir_read_property_this(&_0, this_ptr, SL("_application"), PH_NOISY_CC);
	RETURN_MM_BOOL(Z_TYPE_P(_0) == IS_OBJECT);

}

/**
 * Checks whether the module is primary.
 *
 * @return boolean
 */
PHP_METHOD(Phalconry_Mvc_Module, isPrimary) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *manager = NULL, *_0, *_1 = NULL;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_manager"), PH_NOISY_CC);
	ZEPHIR_CPY_WRT(manager, _0);
	if (Z_TYPE_P(manager) != IS_OBJECT) {
		RETURN_MM_BOOL(0);
	}
	ZEPHIR_CALL_METHOD(&_1, manager, "getprimarymodulename", NULL, 0);
	zephir_check_call_status();
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_name"), PH_NOISY_CC);
	RETURN_MM_BOOL(ZEPHIR_IS_IDENTICAL(_1, _0));

}

/**
 * Checks whether the module is the default.
 *
 * @return boolean
 */
PHP_METHOD(Phalconry_Mvc_Module, isDefault) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *manager = NULL, *_0, *_1 = NULL;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_manager"), PH_NOISY_CC);
	ZEPHIR_CPY_WRT(manager, _0);
	if (Z_TYPE_P(manager) != IS_OBJECT) {
		RETURN_MM_BOOL(0);
	}
	ZEPHIR_CALL_METHOD(&_1, manager, "getdefaultmodulename", NULL, 0);
	zephir_check_call_status();
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_name"), PH_NOISY_CC);
	RETURN_MM_BOOL(ZEPHIR_IS_IDENTICAL(_1, _0));

}

/**
 * Registers the module autoloaders.
 */
PHP_METHOD(Phalconry_Mvc_Module, registerAutoloaders) {

	zval *di = NULL;

	zephir_fetch_params(0, 0, 1, &di);

	if (!di) {
		di = ZEPHIR_GLOBAL(global_null);
	}



}

/**
 * Registers the module services.
 */
PHP_METHOD(Phalconry_Mvc_Module, registerServices) {

	zval *di;

	zephir_fetch_params(0, 1, 0, &di);




}

