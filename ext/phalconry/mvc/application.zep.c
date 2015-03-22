
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
#include "kernel/exception.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "kernel/hash.h"
#include "kernel/array.h"
#include "kernel/concat.h"
#include "kernel/require.h"


ZEPHIR_INIT_CLASS(Phalconry_Mvc_Application) {

	ZEPHIR_REGISTER_CLASS_EX(Phalconry\\Mvc, Application, phalconry, mvc_application, zephir_get_internal_ce(SS("phalcon\\mvc\\application") TSRMLS_CC), phalconry_mvc_application_method_entry, 0);

	/**
	 * Name of the primary module
	 * @var string
	 */
	zend_declare_property_null(phalconry_mvc_application_ce, SL("_moduleName"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * Module registry
	 * @var \Phalcon\Registry
	 */
	zend_declare_property_null(phalconry_mvc_application_ce, SL("_moduleRegistry"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * Responder
	 * @var \Phalconry\Mvc\Responder
	 */
	zend_declare_property_null(phalconry_mvc_application_ce, SL("_responder"), ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

/**
 * Application constructor.
 *
 * @param Env $env Environment instance
 */
PHP_METHOD(Phalconry_Mvc_Application, __construct) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *env, *di, *eventsManager, *_0 = NULL, *_1;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &env);



	if (!(zephir_instance_of_ev(env, phalconry_mvc_env_ce TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "Parameter 'env' must be an instance of 'Phalconry\\Mvc\\Env'", "", 0);
		return;
	}
	ZEPHIR_INIT_VAR(di);
	object_init_ex(di, zephir_get_internal_ce(SS("phalcon\\di\\factorydefault") TSRMLS_CC));
	ZEPHIR_CALL_METHOD(NULL, di, "__construct", NULL);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_0);
	ZVAL_STRING(_0, "app", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(NULL, di, "setshared", NULL, _0, this_ptr);
	zephir_check_temp_parameter(_0);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(_0);
	ZVAL_STRING(_0, "config", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(NULL, di, "setshared", NULL, _0, env);
	zephir_check_temp_parameter(_0);
	zephir_check_call_status();
	ZEPHIR_CALL_PARENT(NULL, phalconry_mvc_application_ce, this_ptr, "__construct", NULL, di);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(_0);
	object_init_ex(_0, zephir_get_internal_ce(SS("phalcon\\registry") TSRMLS_CC));
	if (zephir_has_constructor(_0 TSRMLS_CC)) {
		ZEPHIR_CALL_METHOD(NULL, _0, "__construct", NULL);
		zephir_check_call_status();
	}
	zephir_update_property_this(this_ptr, SL("_moduleRegistry"), _0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(eventsManager);
	object_init_ex(eventsManager, zephir_get_internal_ce(SS("phalcon\\events\\manager") TSRMLS_CC));
	if (zephir_has_constructor(eventsManager TSRMLS_CC)) {
		ZEPHIR_CALL_METHOD(NULL, eventsManager, "__construct", NULL);
		zephir_check_call_status();
	}
	ZEPHIR_INIT_VAR(_1);
	ZVAL_STRING(_1, "application", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(NULL, eventsManager, "attach", NULL, _1, this_ptr);
	zephir_check_temp_parameter(_1);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "seteventsmanager", NULL, eventsManager);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * Returns a directory path
 *
 * @param string $name Path name.
 * @return string
 */
PHP_METHOD(Phalconry_Mvc_Application, getPath) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *name_param = NULL, *_0 = NULL, *_1 = NULL, *_2;
	zval *name = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name_param);

	zephir_get_strval(name, name_param);


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getdi", NULL);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_2);
	ZVAL_STRING(_2, "config", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&_1, _0, "getshared", NULL, _2);
	zephir_check_temp_parameter(_2);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(_1, "getpath", NULL, name);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Sets a named directory path.
 *
 * @param string $name Path name.
 * @param string $value Absolute directory path.
 */
PHP_METHOD(Phalconry_Mvc_Application, setPath) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *name_param = NULL, *value_param = NULL, *_0 = NULL, *_1 = NULL, *_2;
	zval *name = NULL, *value = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &name_param, &value_param);

	zephir_get_strval(name, name_param);
	zephir_get_strval(value, value_param);


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getdi", NULL);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_2);
	ZVAL_STRING(_2, "config", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&_1, _0, "getshared", NULL, _2);
	zephir_check_temp_parameter(_2);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, _1, "setpath", NULL, name, value);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * Returns the name of a module from an object
 *
 * @param \Phalconry\Mvc\Module $module [Optional]
 * @return string
 */
PHP_METHOD(Phalconry_Mvc_Application, getModuleName) {

	HashTable *_2;
	HashPosition _1;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *className = NULL;
	zend_bool _0;
	zval *module = NULL, *modules = NULL, *key = NULL, *value = NULL, **_3, *_4;

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
		RETURN_MM_MEMBER(this_ptr, "_moduleName");
	}
	ZEPHIR_INIT_VAR(className);
	zephir_get_class(className, module, 0 TSRMLS_CC);
	ZEPHIR_CALL_METHOD(&modules, this_ptr, "getmodules", NULL);
	zephir_check_call_status();
	zephir_is_iterable(modules, &_2, &_1, 0, 0, "phalconry/mvc/application.zep", 93);
	for (
	  ; zephir_hash_get_current_data_ex(_2, (void**) &_3, &_1) == SUCCESS
	  ; zephir_hash_move_forward_ex(_2, &_1)
	) {
		ZEPHIR_GET_HMKEY(key, _2, _1);
		ZEPHIR_GET_HVALUE(value, _3);
		zephir_array_fetch_string(&_4, value, SL("className"), PH_NOISY | PH_READONLY, "phalconry/mvc/application.zep", 88 TSRMLS_CC);
		if (ZEPHIR_IS_IDENTICAL(_4, className)) {
			RETURN_CCTOR(key);
		}
	}
	RETURN_MM_NULL();

}

/**
 * Returns a module by name, or the primary module if none given.
 *
 * @param string $name [Optional] Module name
 * @return \Phalconry\Mvc\Module
 */
PHP_METHOD(Phalconry_Mvc_Application, getModule) {

	zval *name_param = NULL, *_1, *_2, *_3;
	zval *name = NULL, *_0 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &name_param);

	if (!name_param) {
		ZEPHIR_INIT_VAR(name);
		ZVAL_EMPTY_STRING(name);
	} else {
		zephir_get_strval(name, name_param);
	}


	if (1 == 0) {
		ZEPHIR_INIT_VAR(_0);
		ZEPHIR_INIT_NVAR(_0);
		ZVAL_STRING(_0, "_moduleObject", 1);
		ZEPHIR_OBS_VAR(_1);
		zephir_read_property_zval(&_1, this_ptr, _0, PH_NOISY_CC);
		RETURN_CCTOR(_1);
	}
	_2 = zephir_fetch_nproperty_this(this_ptr, SL("_moduleRegistry"), PH_NOISY_CC);
	zephir_array_fetch(&_3, _2, name, PH_NOISY | PH_READONLY, "phalconry/mvc/application.zep", 108 TSRMLS_CC);
	RETURN_CTOR(_3);

}

/**
 * Adds a module to the registry
 *
 * @param \Phalconry\Mvc\Module $module
 */
PHP_METHOD(Phalconry_Mvc_Application, setModule) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *module, *name = NULL, *_0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &module);



	if (!(zephir_instance_of_ev(module, phalconry_mvc_module_ce TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "Parameter 'module' must be an instance of 'Phalconry\\Mvc\\Module'", "", 0);
		return;
	}
	ZEPHIR_CALL_METHOD(&name, this_ptr, "getmodulename", NULL, module);
	zephir_check_call_status();
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_moduleRegistry"), PH_NOISY_CC);
	if (zephir_array_isset(_0, name)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_RuntimeException, "Module already set", "phalconry/mvc/application.zep", 122);
		return;
	}
	ZEPHIR_CALL_METHOD(NULL, module, "setname", NULL, name);
	zephir_check_call_status();
	zephir_update_property_array(this_ptr, SL("_moduleRegistry"), name, module TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

/**
 * Loads a module
 *
 * @param string|\Phalconry\Mvc\Module $module
 * @return \Phalconry\Mvc\Module
 */
PHP_METHOD(Phalconry_Mvc_Application, loadModule) {

	zend_class_entry *_2;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *module = NULL, *moduleList = NULL, *className, *_0, *_1 = NULL, *_3 = NULL, *di = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &module);

	ZEPHIR_SEPARATE_PARAM(module);


	if (Z_TYPE_P(module) == IS_STRING) {
		ZEPHIR_CALL_METHOD(&moduleList, this_ptr, "getmodules", NULL);
		zephir_check_call_status();
		if (!(zephir_array_isset(moduleList, module))) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "Unknown module", "phalconry/mvc/application.zep", 144);
			return;
		}
		zephir_array_fetch(&_0, moduleList, module, PH_NOISY | PH_READONLY, "phalconry/mvc/application.zep", 148 TSRMLS_CC);
		ZEPHIR_OBS_VAR(className);
		zephir_array_fetch_string(&className, _0, SL("className"), PH_NOISY, "phalconry/mvc/application.zep", 148 TSRMLS_CC);
		ZEPHIR_INIT_NVAR(module);
		zephir_fetch_safe_class(_1, className);
		_2 = zend_fetch_class(Z_STRVAL_P(_1), Z_STRLEN_P(_1), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);
		object_init_ex(module, _2);
		if (zephir_has_constructor(module TSRMLS_CC)) {
			ZEPHIR_CALL_METHOD(NULL, module, "__construct", NULL);
			zephir_check_call_status();
		}
	}
	if (zephir_instance_of_ev(module, phalconry_mvc_module_ce TSRMLS_CC)) {
		ZEPHIR_CALL_METHOD(&_3, module, "isloaded", NULL);
		zephir_check_call_status();
		if (zephir_is_true(_3)) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_RuntimeException, "Cannot reload module", "phalconry/mvc/application.zep", 155);
			return;
		}
	} else {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "Invalid module given", "phalconry/mvc/application.zep", 158);
		return;
	}
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "setmodule", NULL, module);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&di, this_ptr, "getdi", NULL);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, module, "registerautoloaders", NULL, di);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, module, "registerservices", NULL, di);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, module, "setapp", NULL, this_ptr);
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
PHP_METHOD(Phalconry_Mvc_Application, isModuleLoaded) {

	zval *_2 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *module, *_0, *_1 = NULL, *_3, *_4;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &module);



	if (zephir_instance_of_ev(module, phalconry_mvc_module_ce TSRMLS_CC)) {
		ZEPHIR_RETURN_CALL_METHOD(module, "isloaded", NULL);
		zephir_check_call_status();
		RETURN_MM();
	}
	if (Z_TYPE_P(module) != IS_STRING) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "Expecting string or Module", "phalconry/mvc/application.zep", 188);
		return;
	}
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_moduleName"), PH_NOISY_CC);
	if (ZEPHIR_IS_IDENTICAL(module, _0)) {
		ZEPHIR_INIT_VAR(_1);
		if ((0 == 0)) {
			ZEPHIR_INIT_VAR(_2);
			ZEPHIR_INIT_NVAR(_2);
			ZVAL_STRING(_2, "_moduleObject", 1);
			ZEPHIR_OBS_VAR(_3);
			zephir_read_property_zval(&_3, this_ptr, _2, PH_NOISY_CC);
			ZEPHIR_CALL_METHOD(&_1, _3, "isloaded", NULL);
			zephir_check_call_status();
		} else {
			ZVAL_BOOL(_1, 0);
		}
		RETURN_CCTOR(_1);
	}
	_4 = zephir_fetch_nproperty_this(this_ptr, SL("_moduleRegistry"), PH_NOISY_CC);
	RETURN_MM_BOOL(zephir_array_isset(_4, module));

}

/**
 * Returns the primary module name.
 *
 * @return string
 */
PHP_METHOD(Phalconry_Mvc_Application, getPrimaryModuleName) {


	RETURN_MEMBER(this_ptr, "_moduleName");

}

/**
 * Returns the primary module
 *
 * @return \Phalconry\Mvc\Module
 */
PHP_METHOD(Phalconry_Mvc_Application, getPrimaryModule) {

	zval *_1;
	zval *_0 = NULL;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(_0);
	ZEPHIR_INIT_NVAR(_0);
	ZVAL_STRING(_0, "_moduleObject", 1);
	ZEPHIR_OBS_VAR(_1);
	zephir_read_property_zval(&_1, this_ptr, _0, PH_NOISY_CC);
	RETURN_CCTOR(_1);

}

/**
 * Returns the responder
 *
 * @return \Phalconry\Mvc\Responder
 */
PHP_METHOD(Phalconry_Mvc_Application, getResponder) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *_0, *_1 = NULL, *_2 = NULL, *_3;

	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(_0);
	zephir_read_property_this(&_0, this_ptr, SL("_responder"), PH_NOISY_CC);
	if (Z_TYPE_P(_0) == IS_NULL) {
		ZEPHIR_CALL_METHOD(&_1, this_ptr, "getdi", NULL);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(_3);
		ZVAL_STRING(_3, "responder", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&_2, _1, "getshared", NULL, _3);
		zephir_check_temp_parameter(_3);
		zephir_check_call_status();
		zephir_update_property_this(this_ptr, SL("_responder"), _2 TSRMLS_CC);
	}
	RETURN_MM_MEMBER(this_ptr, "_responder");

}

/**
 * Sets the type of response
 *
 * @param string
 */
PHP_METHOD(Phalconry_Mvc_Application, setResponseType) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *type_param = NULL, *_0 = NULL;
	zval *type = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &type_param);

	zephir_get_strval(type, type_param);


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getresponder", NULL);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, _0, "settype", NULL, type);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * Returns the type of response
 *
 * @return string
 */
PHP_METHOD(Phalconry_Mvc_Application, getResponseType) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *_0 = NULL;

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getresponder", NULL);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(_0, "gettype", NULL);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Runs the application and sends the response.
 */
PHP_METHOD(Phalconry_Mvc_Application, run) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *response = NULL, *_0, *_1 = NULL;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(_0);
	ZVAL_NULL(_0);
	ZEPHIR_CALL_METHOD(&response, this_ptr, "handle", NULL, _0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "getresponder", NULL);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, _1, "respond", NULL, response);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * application:boot event callback
 */
PHP_METHOD(Phalconry_Mvc_Application, boot) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *event, *app, *nothing, *env = NULL, *_0 = NULL, *_1;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &event, &app, &nothing);



	if (!(zephir_instance_of_ev(event, zephir_get_internal_ce(SS("phalcon\\events\\event") TSRMLS_CC) TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "Parameter 'event' must be an instance of 'Phalcon\\Events\\Event'", "", 0);
		return;
	}
	if (!(zephir_instance_of_ev(app, zephir_get_internal_ce(SS("phalcon\\mvc\\application") TSRMLS_CC) TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "Parameter 'app' must be an instance of 'Phalcon\\Mvc\\Application'", "", 0);
		return;
	}
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getdi", NULL);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_1);
	ZVAL_STRING(_1, "config", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&env, _0, "getshared", NULL, _1);
	zephir_check_temp_parameter(_1);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "_registerautoloaders", NULL, env);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "_registerservices", NULL, env);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "_registermodules", NULL, env);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * application:afterStartModule event callback
 */
PHP_METHOD(Phalconry_Mvc_Application, afterStartModule) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *moduleName = NULL;
	zval *event, *app, *moduleName_param = NULL, *module = NULL, *_0 = NULL, *_1 = NULL, *_2, *_3 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &event, &app, &moduleName_param);

	zephir_get_strval(moduleName, moduleName_param);


	if (!(zephir_instance_of_ev(event, zephir_get_internal_ce(SS("phalcon\\events\\event") TSRMLS_CC) TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "Parameter 'event' must be an instance of 'Phalcon\\Events\\Event'", "", 0);
		return;
	}
	if (!(zephir_instance_of_ev(app, zephir_get_internal_ce(SS("phalcon\\mvc\\application") TSRMLS_CC) TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "Parameter 'app' must be an instance of 'Phalcon\\Mvc\\Application'", "", 0);
		return;
	}
	zephir_update_property_this(this_ptr, SL("_moduleName"), moduleName TSRMLS_CC);
	ZEPHIR_CALL_METHOD(&module, this_ptr, "getprimarymodule", NULL);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, module, "setname", NULL, moduleName);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getdi", NULL);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_2);
	ZVAL_STRING(_2, "dispatcher", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&_1, _0, "getshared", NULL, _2);
	zephir_check_temp_parameter(_2);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_3, module, "getcontrollernamespace", NULL);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, _1, "setdefaultnamespace", NULL, _3);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, module, "setapp", NULL, this_ptr);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, module, "onload", NULL);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * application:afterHandleRequest event callback
 */
PHP_METHOD(Phalconry_Mvc_Application, afterHandleRequest) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *event, *app, *moduleName, *view = NULL, *_0 = NULL, *_1 = NULL, *_2 = NULL, *_3 = NULL, *_4 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &event, &app, &moduleName);



	if (!(zephir_instance_of_ev(event, zephir_get_internal_ce(SS("phalcon\\events\\event") TSRMLS_CC) TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "Parameter 'event' must be an instance of 'Phalcon\\Events\\Event'", "", 0);
		return;
	}
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getdi", NULL);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_1);
	ZVAL_STRING(_1, "view", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&view, _0, "getshared", NULL, _1);
	zephir_check_temp_parameter(_1);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_2, this_ptr, "getresponder", NULL);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "view", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&_3, _2, "istype", NULL, _1);
	zephir_check_temp_parameter(_1);
	zephir_check_call_status();
	if (zephir_is_true(_3)) {
		ZEPHIR_CALL_METHOD(&_4, this_ptr, "getprimarymodule", NULL);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, _4, "onview", NULL, view);
		zephir_check_call_status();
	} else {
		ZEPHIR_CALL_METHOD(NULL, view, "disable", NULL);
		zephir_check_call_status();
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Registers class loader(s)
 */
PHP_METHOD(Phalconry_Mvc_Application, _registerAutoloaders) {

	zval *_0 = NULL, *_1 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *env, *loader, *args, *_2 = NULL, *_3 = NULL, *_4 = NULL, *_5 = NULL, *_6, *_7;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &env);



	if (!(zephir_instance_of_ev(env, phalconry_mvc_env_ce TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "Parameter 'env' must be an instance of 'Phalconry\\Mvc\\Env'", "", 0);
		return;
	}
	ZEPHIR_INIT_VAR(loader);
	object_init_ex(loader, zephir_get_internal_ce(SS("phalcon\\loader") TSRMLS_CC));
	ZEPHIR_CALL_METHOD(NULL, loader, "__construct", NULL);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, loader, "register", NULL);
	zephir_check_call_status();
	if ((0 == 0)) {
		ZEPHIR_INIT_VAR(_0);
		ZEPHIR_INIT_NVAR(_0);
		ZVAL_STRING(_0, "loader", 1);
		ZEPHIR_OBS_VAR(args);
		zephir_read_property_zval(&args, env, _0, PH_NOISY_CC);
		if ((0 == 0)) {
			ZEPHIR_INIT_VAR(_1);
			ZEPHIR_INIT_NVAR(_1);
			ZVAL_STRING(_1, "namespaces", 1);
			ZEPHIR_OBS_VAR(_2);
			zephir_read_property_zval(&_2, args, _1, PH_NOISY_CC);
			ZEPHIR_CALL_METHOD(&_3, _2, "toarray", NULL);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(NULL, loader, "registernamespaces", NULL, _3);
			zephir_check_call_status();
		}
		if ((0 == 0)) {
			ZEPHIR_INIT_NVAR(_1);
			ZEPHIR_INIT_NVAR(_1);
			ZVAL_STRING(_1, "dirs", 1);
			ZEPHIR_OBS_NVAR(_2);
			zephir_read_property_zval(&_2, args, _1, PH_NOISY_CC);
			ZEPHIR_CALL_METHOD(&_3, _2, "toarray", NULL);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(NULL, loader, "registerdirs", NULL, _3);
			zephir_check_call_status();
		}
		if ((0 == 0)) {
			ZEPHIR_INIT_NVAR(_1);
			ZEPHIR_INIT_NVAR(_1);
			ZVAL_STRING(_1, "classes", 1);
			ZEPHIR_OBS_NVAR(_2);
			zephir_read_property_zval(&_2, args, _1, PH_NOISY_CC);
			ZEPHIR_CALL_METHOD(&_3, _2, "toarray", NULL);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(NULL, loader, "registerclasses", NULL, _3);
			zephir_check_call_status();
		}
	} else {
		ZEPHIR_CPY_WRT(_4, this_ptr);
		if (zephir_set_symbol_str(SS("app"), _4 TSRMLS_CC) == FAILURE){
		  return;
		}
		ZEPHIR_CPY_WRT(_5, loader);
		if (zephir_set_symbol_str(SS("loader"), _5 TSRMLS_CC) == FAILURE){
		  return;
		}
		ZEPHIR_INIT_VAR(_6);
		ZVAL_STRING(_6, "config", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&_3, env, "getpath", NULL, _6);
		zephir_check_temp_parameter(_6);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(_7);
		ZEPHIR_CONCAT_VS(_7, _3, "loader.php");
		if (zephir_require_zval(_7 TSRMLS_CC) == FAILURE) {
			RETURN_MM_NULL();
		}
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Registers global services
 */
PHP_METHOD(Phalconry_Mvc_Application, _registerServices) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *env, *_0 = NULL, *_1 = NULL, *_2 = NULL, *_3 = NULL, *_4, *_5;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &env);



	if (!(zephir_instance_of_ev(env, phalconry_mvc_env_ce TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "Parameter 'env' must be an instance of 'Phalconry\\Mvc\\Env'", "", 0);
		return;
	}
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getdi", NULL);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "setdefaultservices", NULL, _0);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(_1, this_ptr);
	if (zephir_set_symbol_str(SS("app"), _1 TSRMLS_CC) == FAILURE){
	  return;
	}
	ZEPHIR_CALL_METHOD(&_2, this_ptr, "getdi", NULL);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(_3, _2);
	if (zephir_set_symbol_str(SS("di"), _3 TSRMLS_CC) == FAILURE){
	  return;
	}
	ZEPHIR_INIT_VAR(_4);
	ZVAL_STRING(_4, "config", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&_2, env, "getpath", NULL, _4);
	zephir_check_temp_parameter(_4);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_5);
	ZEPHIR_CONCAT_VS(_5, _2, "services.php");
	if (zephir_require_zval(_5 TSRMLS_CC) == FAILURE) {
		RETURN_MM_NULL();
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Registers modules
 */
PHP_METHOD(Phalconry_Mvc_Application, _registerModules) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *_0 = NULL, *_4 = NULL;
	zval *env, *_1, *_2 = NULL, *_3 = NULL, *_5, *_6 = NULL, *_7;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &env);



	if (!(zephir_instance_of_ev(env, phalconry_mvc_env_ce TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "Parameter 'env' must be an instance of 'Phalconry\\Mvc\\Env'", "", 0);
		return;
	}
	if ((0 == 0)) {
		ZEPHIR_INIT_VAR(_0);
		ZEPHIR_INIT_NVAR(_0);
		ZVAL_STRING(_0, "modules", 1);
		ZEPHIR_OBS_VAR(_1);
		zephir_read_property_zval(&_1, env, _0, PH_NOISY_CC);
		ZEPHIR_CALL_METHOD(&_2, _1, "toarray", NULL);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(_3);
		ZVAL_BOOL(_3, 0);
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "registermodules", NULL, _2, _3);
		zephir_check_call_status();
		if ((0 == 0)) {
			ZEPHIR_INIT_VAR(_4);
			ZEPHIR_INIT_NVAR(_4);
			ZVAL_STRING(_4, "default_module", 1);
			ZEPHIR_OBS_VAR(_5);
			zephir_read_property_zval(&_5, env, _4, PH_NOISY_CC);
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "setdefaultmodule", NULL, _5);
			zephir_check_call_status();
		}
	} else {
		ZEPHIR_CPY_WRT(_6, this_ptr);
		if (zephir_set_symbol_str(SS("app"), _6 TSRMLS_CC) == FAILURE){
		  return;
		}
		ZEPHIR_INIT_NVAR(_3);
		ZVAL_STRING(_3, "config", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&_2, env, "getpath", NULL, _3);
		zephir_check_temp_parameter(_3);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(_7);
		ZEPHIR_CONCAT_VS(_7, _2, "modules.php");
		if (zephir_require_zval(_7 TSRMLS_CC) == FAILURE) {
			RETURN_MM_NULL();
		}
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Adds the default services to the DI
 */
PHP_METHOD(Phalconry_Mvc_Application, setDefaultServices) {

	zval *di;

	zephir_fetch_params(0, 1, 0, &di);



	if (!(zephir_is_instance_of(di, SL("Phalcon\\DiInterface") TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STRW(spl_ce_InvalidArgumentException, "Parameter 'di' must be an instance of 'Phalcon\\DiInterface'", "", 0);
		return;
	}

}

