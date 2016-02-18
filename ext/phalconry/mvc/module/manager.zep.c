
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
#include "kernel/operators.h"
#include "kernel/memory.h"
#include "kernel/hash.h"
#include "kernel/fcall.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"
#include "kernel/array.h"
#include "kernel/file.h"
#include "kernel/require.h"
#include "kernel/concat.h"
#include "Zend/zend_closures.h"


ZEPHIR_INIT_CLASS(Phalconry_Mvc_Module_Manager) {

	ZEPHIR_REGISTER_CLASS_EX(Phalconry\\Mvc\\Module, Manager, phalconry, mvc_module_manager, zephir_get_internal_ce(SS("phalcon\\di\\injectable") TSRMLS_CC), phalconry_mvc_module_manager_method_entry, 0);

	/**
	 * Modules
	 *
	 * @var array
	 */
	zend_declare_property_null(phalconry_mvc_module_manager_ce, SL("_modules"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * Primary module name
	 *
	 * @var string
	 */
	zend_declare_property_null(phalconry_mvc_module_manager_ce, SL("_primaryName"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * Default module name
	 *
	 * @var string
	 */
	zend_declare_property_null(phalconry_mvc_module_manager_ce, SL("_defaultName"), ZEND_ACC_PROTECTED TSRMLS_CC);

	phalconry_mvc_module_manager_ce->create_object = zephir_init_properties_Phalconry_Mvc_Module_Manager;

	zend_class_implements(phalconry_mvc_module_manager_ce TSRMLS_CC, 1, phalconry_mvc_module_managerinterface_ce);
	return SUCCESS;

}

/**
 * Sets the name of the primary module.
 *
 * @param string moduleName
 */
PHP_METHOD(Phalconry_Mvc_Module_Manager, setPrimaryModuleName) {

	zval *moduleName_param = NULL;
	zval *moduleName = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &moduleName_param);

	zephir_get_strval(moduleName, moduleName_param);


	zephir_update_property_this(this_ptr, SL("_primaryName"), moduleName TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

/**
 * Returns the name of the primary module.
 *
 * @return string
 */
PHP_METHOD(Phalconry_Mvc_Module_Manager, getPrimaryModuleName) {


	RETURN_MEMBER(this_ptr, "_primaryName");

}

/**
 * Sets the name of the default module.
 *
 * @param string moduleName
 */
PHP_METHOD(Phalconry_Mvc_Module_Manager, setDefaultModuleName) {

	zval *moduleName_param = NULL;
	zval *moduleName = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &moduleName_param);

	zephir_get_strval(moduleName, moduleName_param);


	zephir_update_property_this(this_ptr, SL("_defaultName"), moduleName TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

/**
 * Returns the name of the default module.
 *
 * @return string
 */
PHP_METHOD(Phalconry_Mvc_Module_Manager, getDefaultModuleName) {


	RETURN_MEMBER(this_ptr, "_defaultName");

}

/**
 * Registers an array of module definitions.
 *
 * @param array definitions
 * @return void
 */
PHP_METHOD(Phalconry_Mvc_Module_Manager, registerModules) {

	zephir_fcall_cache_entry *_3 = NULL, *_4 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	HashTable *_1;
	HashPosition _0;
	zval *definitions_param = NULL, *name = NULL, *def = NULL, *module = NULL, **_2;
	zval *definitions = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &definitions_param);

	definitions = definitions_param;



	zephir_is_iterable(definitions, &_1, &_0, 0, 0, "phalconry/mvc/module/manager.zep", 93);
	for (
	  ; zephir_hash_get_current_data_ex(_1, (void**) &_2, &_0) == SUCCESS
	  ; zephir_hash_move_forward_ex(_1, &_0)
	) {
		ZEPHIR_GET_HMKEY(name, _1, _0);
		ZEPHIR_GET_HVALUE(def, _2);
		ZEPHIR_CALL_METHOD(&module, this_ptr, "createfromdefinition", &_3, 0, def);
		zephir_check_call_status();
		if (Z_TYPE_P(module) == IS_OBJECT) {
			ZEPHIR_CALL_METHOD(NULL, module, "setname", NULL, 0, name);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(NULL, module, "setmanager", NULL, 0, this_ptr);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "addmodule", &_4, 0, module);
			zephir_check_call_status();
		}
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Sets a module in the registry
 *
 * @param \Phalconry\Mvc\ModuleInterface module
 */
PHP_METHOD(Phalconry_Mvc_Module_Manager, addModule) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *module, *_0 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &module);



	ZEPHIR_CALL_METHOD(&_0, module, "getname", NULL, 0);
	zephir_check_call_status();
	zephir_update_property_array(this_ptr, SL("_modules"), _0, module TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

/**
 * Returns a module by name, or the primary module if no name is given
 *
 * @param string name Module name
 * @return \Phalconry\Mvc\ModuleInterface
 */
PHP_METHOD(Phalconry_Mvc_Module_Manager, getModule) {

	zval *name_param = NULL, *module, *_0;
	zval *name = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name_param);

	zephir_get_strval(name, name_param);


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_modules"), PH_NOISY_CC);
	if (zephir_array_isset_fetch(&module, _0, name, 1 TSRMLS_CC)) {
		RETURN_CTOR(module);
	}
	RETURN_MM_NULL();

}

/**
 * Checks whether a module exists
 *
 * @param string|\Phalconry\Mvc\ModuleInterface name
 * @return boolean
 */
PHP_METHOD(Phalconry_Mvc_Module_Manager, hasModule) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *name, *_0, *_1 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name);



	if (Z_TYPE_P(name) == IS_STRING) {
		_0 = zephir_fetch_nproperty_this(this_ptr, SL("_modules"), PH_NOISY_CC);
		RETURN_MM_BOOL(zephir_array_isset(_0, name));
	}
	ZEPHIR_INIT_VAR(_1);
	if (Z_TYPE_P(name) == IS_OBJECT) {
		_0 = zephir_fetch_nproperty_this(this_ptr, SL("_modules"), PH_NOISY_CC);
		ZEPHIR_CALL_FUNCTION(&_1, "in_array", NULL, 61, name, _0, ZEPHIR_GLOBAL(global_true));
		zephir_check_call_status();
	} else {
		ZVAL_BOOL(_1, 0);
	}
	RETURN_CCTOR(_1);

}

/**
 * Returns the primary module
 *
 * @return \Phalconry\Mvc\ModuleInterface
 *
 * @throws \Phalcon\Mvc\Exception if primary module is not set
 */
PHP_METHOD(Phalconry_Mvc_Module_Manager, getPrimaryModule) {

	zval *_0, *_1, *_2, *_3;

	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(_0);
	zephir_read_property_this(&_0, this_ptr, SL("_primaryName"), PH_NOISY_CC);
	if (unlikely(Z_TYPE_P(_0) != IS_STRING)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(zephir_get_internal_ce(SS("phalcon\\mvc\\application\\exception") TSRMLS_CC), "No primary module set", "phalconry/mvc/module/manager.zep", 147);
		return;
	}
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("_modules"), PH_NOISY_CC);
	ZEPHIR_OBS_VAR(_3);
	zephir_read_property_this(&_3, this_ptr, SL("_primaryName"), PH_NOISY_CC);
	zephir_array_fetch(&_2, _1, _3, PH_NOISY | PH_READONLY, "phalconry/mvc/module/manager.zep", 150 TSRMLS_CC);
	RETURN_CTOR(_2);

}

/**
 * Loads a module
 *
 * @param \Phalconry\Mvc\ModuleInterface module
 * @return \Phalconry\Mvc\ModuleInterface
 *
 * @throws \Phalcon\Mvc\Exception if module has already been loaded
 */
PHP_METHOD(Phalconry_Mvc_Module_Manager, loadModule) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *module, *moduleName = NULL, *di = NULL, *_0 = NULL, *_1 = NULL, *_2, *_3 = NULL, *_4;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &module);



	ZEPHIR_CALL_METHOD(&_0, module, "isloaded", NULL, 0);
	zephir_check_call_status();
	if (zephir_is_true(_0)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(zephir_get_internal_ce(SS("phalcon\\mvc\\application\\exception") TSRMLS_CC), "Cannot reload module", "phalconry/mvc/module/manager.zep", 166);
		return;
	}
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "hasmodule", NULL, 0, module);
	zephir_check_call_status();
	if (!(zephir_is_true(_1))) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "addmodule", NULL, 0, module);
		zephir_check_call_status();
	}
	ZEPHIR_CALL_METHOD(&moduleName, module, "getname", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&di, this_ptr, "getdi", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_OBS_VAR(_2);
	zephir_read_property_this(&_2, this_ptr, SL("_primaryName"), PH_NOISY_CC);
	if (Z_TYPE_P(_2) != IS_STRING) {
		zephir_update_property_this(this_ptr, SL("_primaryName"), moduleName TSRMLS_CC);
	}
	if (zephir_is_instance_of(module, SL("Phalcon\\Di\\InjectionAwareInterface") TSRMLS_CC)) {
		ZEPHIR_CALL_METHOD(NULL, module, "setdi", NULL, 0, di);
		zephir_check_call_status();
	}
	ZEPHIR_INIT_VAR(_4);
	ZVAL_STRING(_4, "app", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&_3, di, "getshared", NULL, 0, _4);
	zephir_check_temp_parameter(_4);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, module, "setapp", NULL, 0, _3);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, module, "registerautoloaders", NULL, 0, di);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, module, "registerservices", NULL, 0, di);
	zephir_check_call_status();
	if ((zephir_method_exists_ex(module, SS("onload") TSRMLS_CC) == SUCCESS)) {
		ZEPHIR_CALL_METHOD(NULL, module, "onload", NULL, 0);
		zephir_check_call_status();
	}
	RETVAL_ZVAL(module, 1, 0);
	RETURN_MM();

}

/**
 * Whether a module has been loaded
 *
 * @param string|\Phalconry\Mvc\Module $module
 * @return boolean
 *
 * @throws \InvalidArgumentException if not given a Module object or string
 */
PHP_METHOD(Phalconry_Mvc_Module_Manager, isLoaded) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *module, *moduleObject, *_0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &module);



	if (Z_TYPE_P(module) == IS_OBJECT) {
		ZEPHIR_RETURN_CALL_METHOD(module, "isloaded", NULL, 0);
		zephir_check_call_status();
		RETURN_MM();
	}
	if (Z_TYPE_P(module) == IS_STRING) {
		ZEPHIR_OBS_VAR(moduleObject);
		_0 = zephir_fetch_nproperty_this(this_ptr, SL("_modules"), PH_NOISY_CC);
		if (zephir_array_isset_fetch(&moduleObject, _0, module, 0 TSRMLS_CC)) {
			ZEPHIR_RETURN_CALL_METHOD(moduleObject, "isloaded", NULL, 0);
			zephir_check_call_status();
			RETURN_MM();
		}
		RETURN_MM_BOOL(0);
	}
	ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "Expecting string or Module", "phalconry/mvc/module/manager.zep", 221);
	return;

}

/**
 * Creates a module object from its name
 *
 * @param string $name Module name
 * @return \Phalconry\Mvc\ModuleInterface
 * @throws \Phalcon\Mvc\Exception if module is not defined
 */
PHP_METHOD(Phalconry_Mvc_Module_Manager, createFromDefinition) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *definition, *di = NULL, *className = NULL, *filePath, *moduleObject = NULL, *_0, *_1;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &definition);



	ZEPHIR_CALL_METHOD(&di, this_ptr, "getdi", NULL, 0);
	zephir_check_call_status();
	if (Z_TYPE_P(definition) == IS_ARRAY) {
		ZEPHIR_OBS_VAR(className);
		if (!(zephir_array_isset_string_fetch(&className, definition, SS("className"), 0 TSRMLS_CC))) {
			ZEPHIR_INIT_NVAR(className);
			ZVAL_STRING(className, "Module", 1);
		}
		ZEPHIR_OBS_VAR(filePath);
		if (zephir_array_isset_string_fetch(&filePath, definition, SS("path"), 0 TSRMLS_CC)) {
			if (!(zephir_class_exists(className, zephir_is_true(ZEPHIR_GLOBAL(global_false))  TSRMLS_CC))) {
				if ((zephir_file_exists(filePath TSRMLS_CC) == SUCCESS)) {
					if (zephir_require_zval(filePath TSRMLS_CC) == FAILURE) {
						RETURN_MM_NULL();
					}
				} else {
					ZEPHIR_INIT_VAR(_0);
					object_init_ex(_0, zephir_get_internal_ce(SS("phalcon\\mvc\\application\\exception") TSRMLS_CC));
					ZEPHIR_INIT_VAR(_1);
					ZEPHIR_CONCAT_SV(_1, "Invalid module file path: ", filePath);
					ZEPHIR_CALL_METHOD(NULL, _0, "__construct", NULL, 0, _1);
					zephir_check_call_status();
					zephir_throw_exception_debug(_0, "phalconry/mvc/module/manager.zep", 248 TSRMLS_CC);
					ZEPHIR_MM_RESTORE();
					return;
				}
			}
		}
		ZEPHIR_CALL_METHOD(&moduleObject, di, "get", NULL, 0, className);
		zephir_check_call_status();
	} else {
		if (!(zephir_instance_of_ev(definition, zend_ce_closure TSRMLS_CC))) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(zephir_get_internal_ce(SS("phalcon\\mvc\\application\\exception") TSRMLS_CC), "Invalid module definition.", "phalconry/mvc/module/manager.zep", 258);
			return;
		}
		ZEPHIR_CALL_FUNCTION(&moduleObject, "call_user_func", NULL, 62, definition, di);
		zephir_check_call_status();
	}
	RETURN_CCTOR(moduleObject);

}

static zend_object_value zephir_init_properties_Phalconry_Mvc_Module_Manager(zend_class_entry *class_type TSRMLS_DC) {

		zval *_0, *_1;

		ZEPHIR_MM_GROW();
	
	{
		zval *this_ptr = NULL;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		_0 = zephir_fetch_nproperty_this(this_ptr, SL("_modules"), PH_NOISY_CC);
		if (Z_TYPE_P(_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(_1);
			array_init(_1);
			zephir_update_property_this(this_ptr, SL("_modules"), _1 TSRMLS_CC);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJVAL_P(this_ptr);
	}

}

