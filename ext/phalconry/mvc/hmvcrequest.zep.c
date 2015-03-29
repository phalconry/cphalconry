
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
#include "kernel/operators.h"
#include "kernel/fcall.h"
#include "kernel/memory.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"
#include "kernel/array.h"
#include "kernel/object.h"


/**
 * Wrapper for an HMVC request.
 */
ZEPHIR_INIT_CLASS(Phalconry_Mvc_HmvcRequest) {

	ZEPHIR_REGISTER_CLASS_EX(Phalconry\\Mvc, HmvcRequest, phalconry, mvc_hmvcrequest, zephir_get_internal_ce(SS("phalcon\\di\\injectable") TSRMLS_CC), phalconry_mvc_hmvcrequest_method_entry, 0);

	/**
	 * Module name
	 * @var string
	 */
	zend_declare_property_null(phalconry_mvc_hmvcrequest_ce, SL("_module"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * Controller name
	 * @var string
	 */
	zend_declare_property_null(phalconry_mvc_hmvcrequest_ce, SL("_controller"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * Action name
	 * @var string
	 */
	zend_declare_property_null(phalconry_mvc_hmvcrequest_ce, SL("_action"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * Request parameters
	 * @var array
	 */
	zend_declare_property_null(phalconry_mvc_hmvcrequest_ce, SL("_params"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * Request response
	 * @var mixed
	 */
	zend_declare_property_null(phalconry_mvc_hmvcrequest_ce, SL("_response"), ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

/**
 * HmvcRequest constructor.
 *
 * @param array args [Optional] Request args {@see HmvcRequest::set()}
 */
PHP_METHOD(Phalconry_Mvc_HmvcRequest, __construct) {

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
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "setlocation", NULL, args);
		zephir_check_call_status();
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Sets module, controller, action, and/or params from an array.
 *
 * @param array args
 * @return \Phalconry\Mvc\HmvcRequest
 */
PHP_METHOD(Phalconry_Mvc_HmvcRequest, setLocation) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *args_param = NULL, *_0;
	zval *args = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &args_param);

	args = args_param;



	if (zephir_array_isset_string(args, SS("module"))) {
		zephir_array_fetch_string(&_0, args, SL("module"), PH_NOISY | PH_READONLY, "phalconry/mvc/hmvcrequest.zep", 66 TSRMLS_CC);
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "setmodulename", NULL, _0);
		zephir_check_call_status();
	}
	if (zephir_array_isset_string(args, SS("controller"))) {
		zephir_array_fetch_string(&_0, args, SL("controller"), PH_NOISY | PH_READONLY, "phalconry/mvc/hmvcrequest.zep", 70 TSRMLS_CC);
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "setcontrollername", NULL, _0);
		zephir_check_call_status();
	}
	if (zephir_array_isset_string(args, SS("action"))) {
		zephir_array_fetch_string(&_0, args, SL("action"), PH_NOISY | PH_READONLY, "phalconry/mvc/hmvcrequest.zep", 74 TSRMLS_CC);
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "setactionname", NULL, _0);
		zephir_check_call_status();
	}
	if (zephir_array_isset_string(args, SS("params"))) {
		zephir_array_fetch_string(&_0, args, SL("params"), PH_NOISY | PH_READONLY, "phalconry/mvc/hmvcrequest.zep", 78 TSRMLS_CC);
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "setparams", NULL, _0);
		zephir_check_call_status();
	}
	RETURN_THIS();

}

/**
 * Sets the module name
 *
 * @param string module Module name
 * @return \Phalconry\Mvc\HmvcRequest
 */
PHP_METHOD(Phalconry_Mvc_HmvcRequest, setModuleName) {

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
PHP_METHOD(Phalconry_Mvc_HmvcRequest, hasModuleName) {

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
PHP_METHOD(Phalconry_Mvc_HmvcRequest, getModuleName) {


	RETURN_MEMBER(this_ptr, "_module");

}

/**
 * Sets the controller name
 *
 * @param string controller Controller name
 * @return \Phalconry\Mvc\HmvcRequest
 */
PHP_METHOD(Phalconry_Mvc_HmvcRequest, setControllerName) {

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
PHP_METHOD(Phalconry_Mvc_HmvcRequest, hasControllerName) {

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
PHP_METHOD(Phalconry_Mvc_HmvcRequest, getControllerName) {


	RETURN_MEMBER(this_ptr, "_controller");

}

/**
 * Sets the action name
 *
 * @param string action Action name
 * @return \Phalconry\Mvc\HmvcRequest
 */
PHP_METHOD(Phalconry_Mvc_HmvcRequest, setActionName) {

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
PHP_METHOD(Phalconry_Mvc_HmvcRequest, hasActionName) {

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
PHP_METHOD(Phalconry_Mvc_HmvcRequest, getActionName) {


	RETURN_MEMBER(this_ptr, "_action");

}

/**
 * Sets the request parameters
 *
 * @param array params
 * @return \Phalconry\Mvc\HmvcRequest
 */
PHP_METHOD(Phalconry_Mvc_HmvcRequest, setParams) {

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
PHP_METHOD(Phalconry_Mvc_HmvcRequest, hasParams) {

	zval *_0, *_1;

	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(_0);
	zephir_read_property_this(&_0, this_ptr, SL("_params"), PH_NOISY_CC);
	if (Z_TYPE_P(_0) == IS_ARRAY) {
		_1 = zephir_fetch_nproperty_this(this_ptr, SL("_params"), PH_NOISY_CC);
		RETURN_MM_BOOL(!(ZEPHIR_IS_EMPTY(_1)));
	}
	RETURN_MM_BOOL(0);

}

/**
 * Returns the request parameters
 *
 * @return array
 */
PHP_METHOD(Phalconry_Mvc_HmvcRequest, getParams) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *_0, *_1 = NULL;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(_0);
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "hasparams", NULL);
	zephir_check_call_status();
	if (zephir_is_true(_1)) {
		zephir_read_property_this(&_0, this_ptr, SL("_params"), PH_NOISY_CC);
	} else {
		array_init(_0);
	}
	RETURN_CCTOR(_0);

}

/**
 * Dispatches the request and returns a response
 *
 * @param array args [Optional]
 * @return mixed
 */
PHP_METHOD(Phalconry_Mvc_HmvcRequest, __invoke) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *args = NULL, *dispatcher = NULL, *_0 = NULL, *_1 = NULL, *_2 = NULL, *_3, *_4;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &args);

	if (!args) {
		args = ZEPHIR_GLOBAL(global_null);
	}


	if (Z_TYPE_P(args) == IS_ARRAY) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "setlocation", NULL, args);
		zephir_check_call_status();
	}
	ZEPHIR_CALL_METHOD(&dispatcher, this_ptr, "getdispatcher", NULL);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "hasmodulename", NULL);
	zephir_check_call_status();
	if (zephir_is_true(_0)) {
		ZEPHIR_CALL_METHOD(&_1, this_ptr, "getmodulename", NULL);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "preparemodulefordispatch", NULL, dispatcher, _1);
		zephir_check_call_status();
	}
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "hascontrollername", NULL);
	zephir_check_call_status();
	if (zephir_is_true(_1)) {
		ZEPHIR_CALL_METHOD(&_2, this_ptr, "getcontrollername", NULL);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, dispatcher, "setcontrollername", NULL, _2);
		zephir_check_call_status();
	}
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "hasactionname", NULL);
	zephir_check_call_status();
	if (zephir_is_true(_1)) {
		ZEPHIR_CALL_METHOD(&_2, this_ptr, "getactionname", NULL);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, dispatcher, "setactionname", NULL, _2);
		zephir_check_call_status();
	}
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "hasparams", NULL);
	zephir_check_call_status();
	if (zephir_is_true(_1)) {
		ZEPHIR_CALL_METHOD(&_2, this_ptr, "getparams", NULL);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, dispatcher, "setparams", NULL, _2);
		zephir_check_call_status();
	}
	ZEPHIR_CALL_METHOD(NULL, dispatcher, "dispatch", NULL);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_1, dispatcher, "getreturnedvalue", NULL);
	zephir_check_call_status();
	zephir_update_property_this(this_ptr, SL("_response"), _1 TSRMLS_CC);
	ZEPHIR_OBS_VAR(_3);
	zephir_read_property_this(&_3, this_ptr, SL("_response"), PH_NOISY_CC);
	if (zephir_is_instance_of(_3, SL("Phalcon\\Http\\ResponseInterface") TSRMLS_CC)) {
		_4 = zephir_fetch_nproperty_this(this_ptr, SL("_response"), PH_NOISY_CC);
		ZEPHIR_RETURN_CALL_METHOD(_4, "getcontent", NULL);
		zephir_check_call_status();
		RETURN_MM();
	}
	RETURN_MM_MEMBER(this_ptr, "_response");

}

/**
 * Returns the response
 *
 * @return mixed
 */
PHP_METHOD(Phalconry_Mvc_HmvcRequest, getResponse) {


	RETURN_MEMBER(this_ptr, "_response");

}

/**
 * Returns the dispatcher to use for the request
 *
 * @return \Phalcon\Mvc\Dispatcher
 */
PHP_METHOD(Phalconry_Mvc_HmvcRequest, getDispatcher) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *dispatcher = NULL, *_0 = NULL, *_1;

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getdi", NULL);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_1);
	ZVAL_STRING(_1, "dispatcher", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&dispatcher, _0, "getshared", NULL, _1);
	zephir_check_temp_parameter(_1);
	zephir_check_call_status();
	if (zephir_clone(return_value, dispatcher TSRMLS_CC) == FAILURE) {
		RETURN_MM();
	}
	RETURN_MM();

}

/**
 * Prepares to dispatch to a module
 *
 * The module is loaded if not already. If it's not the primary module, the
 * default controller namespace is reset on the cloned dispatcher.
 *
 * @param \Phalcon\Mvc\Dispatcher dispatcher
 * @param string moduleName
 */
PHP_METHOD(Phalconry_Mvc_HmvcRequest, prepareModuleForDispatch) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *moduleName = NULL;
	zval *dispatcher, *moduleName_param = NULL, *moduleManager = NULL, *module = NULL, *_0 = NULL, *_1, *_2 = NULL, *_3 = NULL, *_4 = NULL, *_5 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &dispatcher, &moduleName_param);

	zephir_get_strval(moduleName, moduleName_param);


	if (!(zephir_instance_of_ev(dispatcher, zephir_get_internal_ce(SS("phalcon\\mvc\\dispatcher") TSRMLS_CC) TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "Parameter 'dispatcher' must be an instance of 'Phalcon\\Mvc\\Dispatcher'", "", 0);
		return;
	}
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getdi", NULL);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_1);
	ZVAL_STRING(_1, "moduleManager", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&moduleManager, _0, "getshared", NULL, _1);
	zephir_check_temp_parameter(_1);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_2, moduleManager, "getprimary", NULL);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_3, _2, "getname", NULL);
	zephir_check_call_status();
	if (!ZEPHIR_IS_EQUAL(moduleName, _3)) {
		ZEPHIR_CALL_METHOD(&_4, moduleManager, "isloaded", NULL, moduleName);
		zephir_check_call_status();
		if (zephir_is_true(_4)) {
			ZEPHIR_CALL_METHOD(&module, moduleManager, "get", NULL, moduleName);
			zephir_check_call_status();
		} else {
			ZEPHIR_CALL_METHOD(&module, moduleManager, "load", NULL, moduleName);
			zephir_check_call_status();
		}
		ZEPHIR_CALL_METHOD(&_5, module, "getcontrollernamespace", NULL);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, dispatcher, "setnamespacename", NULL, _5);
		zephir_check_call_status();
	}
	ZEPHIR_CALL_METHOD(NULL, dispatcher, "setmodulename", NULL, moduleName);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

