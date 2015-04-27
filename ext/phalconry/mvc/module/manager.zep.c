
#ifdef HAVE_CONFIG_H
#include "../../../ext_config.h"
#endif

#include <php.h>
#include "../../../php_ext.h"
#include "../../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/object.h"
#include "kernel/exception.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "kernel/array.h"
#include "kernel/hash.h"
#include "ext/spl/spl_exceptions.h"

ZEPHIR_INIT_CLASS(Phalconry_Mvc_Module_Manager) {

	ZEPHIR_REGISTER_CLASS_EX(Phalconry\\Mvc\\Module, Manager, phalconry, mvc_module_manager, zephir_get_internal_ce(SS("phalcon\\di\\injectable") TSRMLS_CC), phalconry_mvc_module_manager_method_entry, 0);

	/**
	 * Primary module name
	 * @var string
	 */
	zend_declare_property_null(phalconry_mvc_module_manager_ce, SL("_primary"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * Module registry
	 * @var array
	 */
	zend_declare_property_null(phalconry_mvc_module_manager_ce, SL("_modules"), ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

/**
 * Sets a module in the registry
 *
 * @param \Phalconry\Mvc\Module $module
 */
PHP_METHOD(Phalconry_Mvc_Module_Manager, set) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *module, *_0 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &module);



	if (!(zephir_instance_of_ev(module, phalconry_mvc_module_ce TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "Parameter 'module' must be an instance of 'Phalconry\\Mvc\\Module'", "", 0);
		return;
	}
	ZEPHIR_CALL_METHOD(&_0, module, "getname", NULL);
	zephir_check_call_status();
	zephir_update_property_array(this_ptr, SL("_modules"), _0, module TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

/**
 * Returns a module by name, or the primary module if no name is given
 *
 * @param string $name [Optional] Module name
 * @return \Phalconry\Mvc\Module
 */
PHP_METHOD(Phalconry_Mvc_Module_Manager, get) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *name_param = NULL, *_0 = NULL, _1, *_2;
	zval *name = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &name_param);

	if (!name_param) {
		ZEPHIR_INIT_VAR(name);
		ZVAL_EMPTY_STRING(name);
	} else {
		zephir_get_strval(name, name_param);
	}


	ZEPHIR_INIT_VAR(_0);
	ZEPHIR_SINIT_VAR(_1);
	ZVAL_STRING(&_1, "", 0);
	if (ZEPHIR_IS_EQUAL(&_1, name)) {
		ZEPHIR_CALL_METHOD(&_0, this_ptr, "getprimary", NULL);
		zephir_check_call_status();
	} else {
		_2 = zephir_fetch_nproperty_this(this_ptr, SL("_modules"), PH_NOISY_CC);
		zephir_array_fetch(&_0, _2, name, PH_NOISY, "phalconry/mvc/module/manager.zep", 41 TSRMLS_CC);
	}
	RETURN_CCTOR(_0);

}

/**
 * Sets the primary module in the registry
 *
 * @param \Phalconry\Mvc\Module $module
 * @throws \Phalcon\Mvc\Exception if primary module is already set
 */
PHP_METHOD(Phalconry_Mvc_Module_Manager, setPrimary) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zend_class_entry *_2 = NULL;
	zval *module, *_0, *_1, *_3, *_4 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &module);



	if (!(zephir_instance_of_ev(module, phalconry_mvc_module_ce TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "Parameter 'module' must be an instance of 'Phalconry\\Mvc\\Module'", "", 0);
		return;
	}
	ZEPHIR_OBS_VAR(_0);
	zephir_read_property_this(&_0, this_ptr, SL("_primary"), PH_NOISY_CC);
	if (unlikely(Z_TYPE_P(_0) == IS_STRING)) {
		ZEPHIR_INIT_VAR(_1);
		if (!_2) {
			_2 = zend_fetch_class(SL("Phalcon\\Mvc\\Exception"), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);
		}
		object_init_ex(_1, _2);
		if (zephir_has_constructor(_1 TSRMLS_CC)) {
			ZEPHIR_INIT_VAR(_3);
			ZVAL_STRING(_3, "Primary module already set", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(NULL, _1, "__construct", NULL, _3);
			zephir_check_temp_parameter(_3);
			zephir_check_call_status();
		}
		zephir_throw_exception_debug(_1, "phalconry/mvc/module/manager.zep", 53 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "set", NULL, module);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_4, module, "getname", NULL);
	zephir_check_call_status();
	zephir_update_property_this(this_ptr, SL("_primary"), _4 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

/**
 * Returns the primary module
 *
 * @return \Phalconry\Mvc\Module
 * @throws \Phalcon\Mvc\Exception if primary module is not set
 */
PHP_METHOD(Phalconry_Mvc_Module_Manager, getPrimary) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zend_class_entry *_2 = NULL;
	zval *_0, *_1, *_3, *_4, *_5, *_6;

	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(_0);
	zephir_read_property_this(&_0, this_ptr, SL("_primary"), PH_NOISY_CC);
	if (unlikely(Z_TYPE_P(_0) != IS_STRING)) {
		ZEPHIR_INIT_VAR(_1);
		if (!_2) {
			_2 = zend_fetch_class(SL("Phalcon\\Mvc\\Exception"), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);
		}
		object_init_ex(_1, _2);
		if (zephir_has_constructor(_1 TSRMLS_CC)) {
			ZEPHIR_INIT_VAR(_3);
			ZVAL_STRING(_3, "No primary module set", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(NULL, _1, "__construct", NULL, _3);
			zephir_check_temp_parameter(_3);
			zephir_check_call_status();
		}
		zephir_throw_exception_debug(_1, "phalconry/mvc/module/manager.zep", 70 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	_4 = zephir_fetch_nproperty_this(this_ptr, SL("_modules"), PH_NOISY_CC);
	ZEPHIR_OBS_VAR(_6);
	zephir_read_property_this(&_6, this_ptr, SL("_primary"), PH_NOISY_CC);
	zephir_array_fetch(&_5, _4, _6, PH_NOISY | PH_READONLY, "phalconry/mvc/module/manager.zep", 73 TSRMLS_CC);
	RETURN_CTOR(_5);

}

/**
 * Loads a module
 *
 * @param string|\Phalconry\Mvc\Module $module
 * @return \Phalconry\Mvc\Module
 * @throws \InvalidArgumentException if module is not a string or object
 * @throws \Phalcon\Mvc\Exception if module has already been loaded
 */
PHP_METHOD(Phalconry_Mvc_Module_Manager, load) {

	zephir_nts_static zend_class_entry *_2 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *module = NULL, *di = NULL, *_0 = NULL, *_1 = NULL, *_3;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &module);

	ZEPHIR_SEPARATE_PARAM(module);


	if (Z_TYPE_P(module) == IS_STRING) {
		ZEPHIR_CALL_METHOD(&_0, this_ptr, "create", NULL, module);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(module, _0);
	}
	if (Z_TYPE_P(module) != IS_OBJECT) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "Invalid module given", "phalconry/mvc/module/manager.zep", 93);
		return;
	}
	ZEPHIR_CALL_METHOD(&_0, module, "isloaded", NULL);
	zephir_check_call_status();
	if (zephir_is_true(_0)) {
		ZEPHIR_INIT_VAR(_1);
		if (!_2) {
			_2 = zend_fetch_class(SL("Phalcon\\Mvc\\Exception"), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);
		}
		object_init_ex(_1, _2);
		if (zephir_has_constructor(_1 TSRMLS_CC)) {
			ZEPHIR_INIT_VAR(_3);
			ZVAL_STRING(_3, "Cannot reload module", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(NULL, _1, "__construct", NULL, _3);
			zephir_check_temp_parameter(_3);
			zephir_check_call_status();
		}
		zephir_throw_exception_debug(_1, "phalconry/mvc/module/manager.zep", 97 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "set", NULL, module);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&di, this_ptr, "getdi", NULL);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "app", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&_0, di, "getshared", NULL, _1);
	zephir_check_temp_parameter(_1);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, module, "setapp", NULL, _0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, module, "registerautoloaders", NULL, di);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, module, "registerservices", NULL, di);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, module, "onload", NULL);
	zephir_check_call_status();
	RETVAL_ZVAL(module, 1, 0);
	RETURN_MM();

}

/**
 * Whether a module has been loaded
 *
 * @param string|\Phalconry\Mvc\Module $module
 * @return boolean
 * @throws \InvalidArgumentException if not given a Module object or string
 */
PHP_METHOD(Phalconry_Mvc_Module_Manager, isLoaded) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *module, *_0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &module);



	if (Z_TYPE_P(module) == IS_OBJECT) {
		ZEPHIR_RETURN_CALL_METHOD(module, "isloaded", NULL);
		zephir_check_call_status();
		RETURN_MM();
	}
	if (Z_TYPE_P(module) == IS_STRING) {
		_0 = zephir_fetch_nproperty_this(this_ptr, SL("_modules"), PH_NOISY_CC);
		RETURN_MM_BOOL(zephir_array_isset(_0, module));
	}
	ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "Expecting string or Module", "phalconry/mvc/module/manager.zep", 130);
	return;

}

/**
 * Returns the name of a module from an object
 *
 * @param \Phalconry\Mvc\Module $module [Optional]
 * @return string
 * @throws \Phalcon\Mvc\Exception if module name not found
 */
PHP_METHOD(Phalconry_Mvc_Module_Manager, getName) {

	zephir_nts_static zend_class_entry *_9 = NULL;
	HashTable *_6;
	HashPosition _5;
	int ZEPHIR_LAST_CALL_STATUS;
	zend_bool _0;
	zval *module = NULL, *className, *key = NULL, *value = NULL, *_1 = NULL, *_2 = NULL, *_3 = NULL, *_4 = NULL, **_7, *_8, *_10;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &module);

	if (!module) {
		module = ZEPHIR_GLOBAL(global_null);
	}


	_0 = Z_TYPE_P(module) != IS_NULL;
	if (_0) {
		_0 = !(zephir_instance_of_ev(module, phalconry_mvc_module_ce TSRMLS_CC));
	}
	if (_0) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "Parameter 'module' must be an instance of 'Phalconry\\Mvc\\Module'", "", 0);
		return;
	}
	if (Z_TYPE_P(module) == IS_NULL) {
		RETURN_MM_MEMBER(this_ptr, "_primary");
	}
	ZEPHIR_INIT_VAR(className);
	zephir_get_class(className, module, 0 TSRMLS_CC);
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "getdi", NULL);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_3);
	ZVAL_STRING(_3, "app", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&_2, _1, "getshared", NULL, _3);
	zephir_check_temp_parameter(_3);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_4, _2, "getmodules", NULL);
	zephir_check_call_status();
	zephir_is_iterable(_4, &_6, &_5, 0, 0, "phalconry/mvc/module/manager.zep", 155);
	for (
	  ; zephir_hash_get_current_data_ex(_6, (void**) &_7, &_5) == SUCCESS
	  ; zephir_hash_move_forward_ex(_6, &_5)
	) {
		ZEPHIR_GET_HMKEY(key, _6, _5);
		ZEPHIR_GET_HVALUE(value, _7);
		zephir_array_fetch_string(&_8, value, SL("className"), PH_NOISY | PH_READONLY, "phalconry/mvc/module/manager.zep", 150 TSRMLS_CC);
		if (ZEPHIR_IS_IDENTICAL(_8, className)) {
			RETURN_CCTOR(key);
		}
	}
	ZEPHIR_INIT_NVAR(_3);
	if (!_9) {
		_9 = zend_fetch_class(SL("Phalcon\\Mvc\\Exception"), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);
	}
	object_init_ex(_3, _9);
	if (zephir_has_constructor(_3 TSRMLS_CC)) {
		ZEPHIR_INIT_VAR(_10);
		ZVAL_STRING(_10, "Invalid module name", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(NULL, _3, "__construct", NULL, _10);
		zephir_check_temp_parameter(_10);
		zephir_check_call_status();
	}
	zephir_throw_exception_debug(_3, "phalconry/mvc/module/manager.zep", 155 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();
	return;

}

/**
 * Creates a module object from its name
 *
 * @param string $name Module name
 * @return \Phalconry\Mvc\Module
 * @throws \Phalcon\Mvc\Exception if module is not defined
 */
PHP_METHOD(Phalconry_Mvc_Module_Manager, create) {

	zend_class_entry *_7;
	zephir_nts_static zend_class_entry *_3 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *name_param = NULL, *moduleList = NULL, *className, *moduleObject, *_0 = NULL, *_1 = NULL, *_2 = NULL, *_4, *_5, *_6 = NULL;
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


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getdi", NULL);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_2);
	ZVAL_STRING(_2, "app", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&_1, _0, "getshared", NULL, _2);
	zephir_check_temp_parameter(_2);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&moduleList, _1, "getmodules", NULL);
	zephir_check_call_status();
	if (!(zephir_array_isset(moduleList, name))) {
		ZEPHIR_INIT_NVAR(_2);
		if (!_3) {
			_3 = zend_fetch_class(SL("Phalcon\\Mvc\\Exception"), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);
		}
		object_init_ex(_2, _3);
		if (zephir_has_constructor(_2 TSRMLS_CC)) {
			ZEPHIR_INIT_VAR(_4);
			ZVAL_STRING(_4, "Unknown module", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(NULL, _2, "__construct", NULL, _4);
			zephir_check_temp_parameter(_4);
			zephir_check_call_status();
		}
		zephir_throw_exception_debug(_2, "phalconry/mvc/module/manager.zep", 172 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_array_fetch(&_5, moduleList, name, PH_NOISY | PH_READONLY, "phalconry/mvc/module/manager.zep", 175 TSRMLS_CC);
	ZEPHIR_OBS_VAR(className);
	zephir_array_fetch_string(&className, _5, SL("className"), PH_NOISY, "phalconry/mvc/module/manager.zep", 175 TSRMLS_CC);
	ZEPHIR_INIT_VAR(moduleObject);
	zephir_fetch_safe_class(_6, className);
	_7 = zend_fetch_class(Z_STRVAL_P(_6), Z_STRLEN_P(_6), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);
	object_init_ex(moduleObject, _7);
	if (zephir_has_constructor(moduleObject TSRMLS_CC)) {
		ZEPHIR_CALL_METHOD(NULL, moduleObject, "__construct", NULL);
		zephir_check_call_status();
	}
	ZEPHIR_CALL_METHOD(NULL, moduleObject, "setname", NULL, name);
	zephir_check_call_status();
	RETURN_CCTOR(moduleObject);

}

PHP_METHOD(Phalconry_Mvc_Module_Manager, __construct) {

	zval *_0;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(_0);
	array_init(_0);
	zephir_update_property_this(this_ptr, SL("_modules"), _0 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

