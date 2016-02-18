
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
#include "kernel/operators.h"
#include "kernel/fcall.h"
#include "kernel/memory.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"
#include "kernel/array.h"
#include "kernel/object.h"
#include "kernel/concat.h"


/**
 * Wrapper for an HMVC request.
 */
ZEPHIR_INIT_CLASS(Phalconry_Mvc_Hmvc_Request) {

	ZEPHIR_REGISTER_CLASS_EX(Phalconry\\Mvc\\Hmvc, Request, phalconry, mvc_hmvc_request, zephir_get_internal_ce(SS("phalcon\\di\\injectable") TSRMLS_CC), phalconry_mvc_hmvc_request_method_entry, 0);

	/**
	 * Module name
	 *
	 * @var string
	 */
	zend_declare_property_null(phalconry_mvc_hmvc_request_ce, SL("_module"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * Controller name
	 *
	 * @var string
	 */
	zend_declare_property_null(phalconry_mvc_hmvc_request_ce, SL("_controller"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * Action name
	 *
	 * @var string
	 */
	zend_declare_property_null(phalconry_mvc_hmvc_request_ce, SL("_action"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * Request parameters
	 *
	 * @var array
	 */
	zend_declare_property_null(phalconry_mvc_hmvc_request_ce, SL("_params"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * Request response
	 *
	 * @var mixed
	 */
	zend_declare_property_null(phalconry_mvc_hmvc_request_ce, SL("_response"), ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

/**
 * HmvcRequest constructor.
 *
 * @param array args [Optional] Request args {@see Request::set()}
 */
PHP_METHOD(Phalconry_Mvc_Hmvc_Request, __construct) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *args_param = NULL;
	zval *args = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &args_param);

	if (!args_param) {
		ZEPHIR_INIT_VAR(args);
		array_init(args);
	} else {
	args = args_param;

	}


	if (!(ZEPHIR_IS_EMPTY(args))) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "setlocation", NULL, 0, args);
		zephir_check_call_status();
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Sets module, controller, action, and/or params from an array.
 *
 * @param array args
 * @return \Phalconry\Mvc\Hmvc\Request
 */
PHP_METHOD(Phalconry_Mvc_Hmvc_Request, setLocation) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *args_param = NULL, *module, *controller, *action, *params;
	zval *args = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &args_param);

	args = args_param;



	ZEPHIR_OBS_VAR(module);
	if (zephir_array_isset_string_fetch(&module, args, SS("module"), 0 TSRMLS_CC)) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "setmodulename", NULL, 0, module);
		zephir_check_call_status();
	}
	ZEPHIR_OBS_VAR(controller);
	if (zephir_array_isset_string_fetch(&controller, args, SS("controller"), 0 TSRMLS_CC)) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "setcontrollername", NULL, 0, controller);
		zephir_check_call_status();
	}
	ZEPHIR_OBS_VAR(action);
	if (zephir_array_isset_string_fetch(&action, args, SS("action"), 0 TSRMLS_CC)) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "setactionname", NULL, 0, action);
		zephir_check_call_status();
	}
	ZEPHIR_OBS_VAR(params);
	if (zephir_array_isset_string_fetch(&params, args, SS("params"), 0 TSRMLS_CC)) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "setparams", NULL, 0, params);
		zephir_check_call_status();
	}
	RETURN_THIS();

}

/**
 * Sets the module name
 *
 * @param string module Module name
 * @return \Phalconry\Mvc\Hmvc\Request
 */
PHP_METHOD(Phalconry_Mvc_Hmvc_Request, setModuleName) {

	zval *module_param = NULL;
	zval *module = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &module_param);

	if (unlikely(Z_TYPE_P(module_param) != IS_STRING && Z_TYPE_P(module_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'module' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(module_param) == IS_STRING)) {
		zephir_get_strval(module, module_param);
	} else {
		ZEPHIR_INIT_VAR(module);
		ZVAL_EMPTY_STRING(module);
	}


	zephir_update_property_this(this_ptr, SL("_module"), module TSRMLS_CC);
	RETURN_THIS();

}

/**
 * Whether a module name is set
 *
 * @return boolean
 */
PHP_METHOD(Phalconry_Mvc_Hmvc_Request, hasModuleName) {

	zval *_0;

	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(_0);
	zephir_read_property_this(&_0, this_ptr, SL("_module"), PH_NOISY_CC);
	RETURN_MM_BOOL(Z_TYPE_P(_0) == IS_STRING);

}

/**
 * Returns the module name
 *
 * @return string
 */
PHP_METHOD(Phalconry_Mvc_Hmvc_Request, getModuleName) {


	RETURN_MEMBER(this_ptr, "_module");

}

/**
 * Sets the controller name
 *
 * @param string controller Controller name
 * @return \Phalconry\Mvc\Hmvc\Request
 */
PHP_METHOD(Phalconry_Mvc_Hmvc_Request, setControllerName) {

	zval *controller_param = NULL;
	zval *controller = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &controller_param);

	if (unlikely(Z_TYPE_P(controller_param) != IS_STRING && Z_TYPE_P(controller_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'controller' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(controller_param) == IS_STRING)) {
		zephir_get_strval(controller, controller_param);
	} else {
		ZEPHIR_INIT_VAR(controller);
		ZVAL_EMPTY_STRING(controller);
	}


	zephir_update_property_this(this_ptr, SL("_controller"), controller TSRMLS_CC);
	RETURN_THIS();

}

/**
 * Whether the controller name is set
 *
 * @return boolean
 */
PHP_METHOD(Phalconry_Mvc_Hmvc_Request, hasControllerName) {

	zval *_0;

	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(_0);
	zephir_read_property_this(&_0, this_ptr, SL("_controller"), PH_NOISY_CC);
	RETURN_MM_BOOL(Z_TYPE_P(_0) == IS_STRING);

}

/**
 * Returns the controller name
 *
 * @return string
 */
PHP_METHOD(Phalconry_Mvc_Hmvc_Request, getControllerName) {


	RETURN_MEMBER(this_ptr, "_controller");

}

/**
 * Sets the action name
 *
 * @param string action Action name
 * @return \Phalconry\Mvc\Hmvc\Request
 */
PHP_METHOD(Phalconry_Mvc_Hmvc_Request, setActionName) {

	zval *action_param = NULL;
	zval *action = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &action_param);

	if (unlikely(Z_TYPE_P(action_param) != IS_STRING && Z_TYPE_P(action_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'action' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(action_param) == IS_STRING)) {
		zephir_get_strval(action, action_param);
	} else {
		ZEPHIR_INIT_VAR(action);
		ZVAL_EMPTY_STRING(action);
	}


	zephir_update_property_this(this_ptr, SL("_action"), action TSRMLS_CC);
	RETURN_THIS();

}

/**
 * Whether the action name is set
 *
 * @return boolean
 */
PHP_METHOD(Phalconry_Mvc_Hmvc_Request, hasActionName) {

	zval *_0;

	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(_0);
	zephir_read_property_this(&_0, this_ptr, SL("_action"), PH_NOISY_CC);
	RETURN_MM_BOOL(Z_TYPE_P(_0) == IS_STRING);

}

/**
 * Returns the action name
 *
 * @return string
 */
PHP_METHOD(Phalconry_Mvc_Hmvc_Request, getActionName) {


	RETURN_MEMBER(this_ptr, "_action");

}

/**
 * Sets the request parameters
 *
 * @param array params
 * @return \Phalconry\Mvc\Hmvc\Request
 */
PHP_METHOD(Phalconry_Mvc_Hmvc_Request, setParams) {

	zval *params_param = NULL;
	zval *params = NULL;

	zephir_fetch_params(0, 1, 0, &params_param);

	params = params_param;



	zephir_update_property_this(this_ptr, SL("_params"), params TSRMLS_CC);
	RETURN_THISW();

}

/**
 * Whether any parameters are set
 *
 * @return boolean
 */
PHP_METHOD(Phalconry_Mvc_Hmvc_Request, hasParams) {

	zval *_0, *_1;

	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(_0);
	zephir_read_property_this(&_0, this_ptr, SL("_params"), PH_NOISY_CC);
	if (Z_TYPE_P(_0) == IS_ARRAY) {
		_1 = zephir_fetch_nproperty_this(this_ptr, SL("_params"), PH_NOISY_CC);
		RETURN_MM_BOOL(zephir_fast_count_int(_1 TSRMLS_CC) > 0);
	}
	RETURN_MM_BOOL(0);

}

/**
 * Returns the request parameters
 *
 * @return array
 */
PHP_METHOD(Phalconry_Mvc_Hmvc_Request, getParams) {

	zval *_0, *_1;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(_0);
	ZEPHIR_OBS_VAR(_1);
	zephir_read_property_this(&_1, this_ptr, SL("_params"), PH_NOISY_CC);
	if (Z_TYPE_P(_1) == IS_ARRAY) {
		zephir_read_property_this(&_0, this_ptr, SL("_params"), PH_NOISY_CC);
	} else {
		array_init(_0);
	}
	RETURN_CCTOR(_0);

}

/**
 * Returns the response
 *
 * @return mixed
 */
PHP_METHOD(Phalconry_Mvc_Hmvc_Request, getResponse) {


	RETURN_MEMBER(this_ptr, "_response");

}

/**
 * Dispatches the request and returns a response
 *
 * @param array args [Optional]
 * @return mixed
 */
PHP_METHOD(Phalconry_Mvc_Hmvc_Request, __invoke) {

	zend_class_entry *_0;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *args = NULL, *moduleName, *controllerName, *actionName, *params, *dependencyInjector = NULL, *origDispatcher = NULL, *dispatcher, *moduleManager = NULL, *module = NULL, *response = NULL, *_1 = NULL, *_2 = NULL, *_3 = NULL, *_4, *_5 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &args);

	if (!args) {
		args = ZEPHIR_GLOBAL(global_null);
	}


	if (Z_TYPE_P(args) == IS_ARRAY) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "setlocation", NULL, 0, args);
		zephir_check_call_status();
	}
	ZEPHIR_CALL_METHOD(&dependencyInjector, this_ptr, "getdi", NULL, 0);
	zephir_check_call_status();
	if (Z_TYPE_P(dependencyInjector) != IS_OBJECT) {
		_0 = zend_fetch_class(SL("Phalcon\\Di"), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);
		ZEPHIR_CALL_CE_STATIC(&dependencyInjector, _0, "getdefault", NULL, 0);
		zephir_check_call_status();
		if (unlikely(Z_TYPE_P(dependencyInjector) != IS_OBJECT)) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalconry_mvc_hmvc_exception_ce, "Could not locate dependency injector", "phalconry/mvc/hmvc/request.zep", 253);
			return;
		}
	}
	ZEPHIR_OBS_VAR(moduleName);
	zephir_read_property_this(&moduleName, this_ptr, SL("_module"), PH_NOISY_CC);
	ZEPHIR_OBS_VAR(controllerName);
	zephir_read_property_this(&controllerName, this_ptr, SL("_controller"), PH_NOISY_CC);
	ZEPHIR_OBS_VAR(actionName);
	zephir_read_property_this(&actionName, this_ptr, SL("_action"), PH_NOISY_CC);
	ZEPHIR_OBS_VAR(params);
	zephir_read_property_this(&params, this_ptr, SL("_params"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_2);
	ZVAL_STRING(_2, "dispatcher", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&_1, dependencyInjector, "getshared", NULL, 0, _2);
	zephir_check_temp_parameter(_2);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(origDispatcher, _1);
	ZEPHIR_INIT_VAR(dispatcher);
	if (zephir_clone(dispatcher, origDispatcher TSRMLS_CC) == FAILURE) {
		RETURN_MM();
	}
	if (Z_TYPE_P(moduleName) == IS_STRING) {
		ZEPHIR_INIT_NVAR(_2);
		ZVAL_STRING(_2, "moduleManager", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&_1, dependencyInjector, "getshared", NULL, 0, _2);
		zephir_check_temp_parameter(_2);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(moduleManager, _1);
		if (Z_TYPE_P(moduleManager) != IS_OBJECT) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalconry_mvc_hmvc_exception_ce, "Invalid injected module manager", "phalconry/mvc/hmvc/request.zep", 268);
			return;
		}
		ZEPHIR_CALL_METHOD(&_1, moduleManager, "getprimarymodulename", NULL, 0);
		zephir_check_call_status();
		if (!ZEPHIR_IS_EQUAL(moduleName, _1)) {
			ZEPHIR_CALL_METHOD(&_3, moduleManager, "getmodule", NULL, 0, moduleName);
			zephir_check_call_status();
			ZEPHIR_CPY_WRT(module, _3);
			if (Z_TYPE_P(module) == IS_OBJECT) {
				ZEPHIR_CALL_METHOD(&_3, module, "isloaded", NULL, 0);
				zephir_check_call_status();
				if (!(zephir_is_true(_3))) {
					ZEPHIR_CALL_METHOD(NULL, moduleManager, "loadmodule", NULL, 0, module);
					zephir_check_call_status();
				}
			} else {
				ZEPHIR_INIT_NVAR(_2);
				object_init_ex(_2, phalconry_mvc_hmvc_exception_ce);
				ZEPHIR_INIT_VAR(_4);
				ZEPHIR_CONCAT_SVS(_4, "Could not locate module: '", moduleName, "'");
				ZEPHIR_CALL_METHOD(NULL, _2, "__construct", NULL, 4, _4);
				zephir_check_call_status();
				zephir_throw_exception_debug(_2, "phalconry/mvc/hmvc/request.zep", 280 TSRMLS_CC);
				ZEPHIR_MM_RESTORE();
				return;
			}
			ZEPHIR_CALL_METHOD(&_5, module, "getcontrollernamespace", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(NULL, dispatcher, "setnamespacename", NULL, 0, _5);
			zephir_check_call_status();
		}
		ZEPHIR_CALL_METHOD(NULL, dispatcher, "setmodulename", NULL, 0, moduleName);
		zephir_check_call_status();
	}
	if (Z_TYPE_P(controllerName) == IS_STRING) {
		ZEPHIR_CALL_METHOD(NULL, dispatcher, "setcontrollername", NULL, 0, controllerName);
		zephir_check_call_status();
	}
	if (Z_TYPE_P(actionName) == IS_STRING) {
		ZEPHIR_CALL_METHOD(NULL, dispatcher, "setactionname", NULL, 0, actionName);
		zephir_check_call_status();
	}
	if (Z_TYPE_P(params) == IS_ARRAY) {
		ZEPHIR_CALL_METHOD(NULL, dispatcher, "setparams", NULL, 0, params);
		zephir_check_call_status();
	}
	ZEPHIR_CALL_METHOD(NULL, dispatcher, "dispatch", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&response, dispatcher, "getreturnedvalue", NULL, 0);
	zephir_check_call_status();
	zephir_update_property_this(this_ptr, SL("_response"), response TSRMLS_CC);
	if (zephir_is_instance_of(response, SL("Phalcon\\Http\\ResponseInterface") TSRMLS_CC)) {
		ZEPHIR_RETURN_CALL_METHOD(response, "getcontent", NULL, 0);
		zephir_check_call_status();
		RETURN_MM();
	}
	RETURN_CCTOR(response);

}

