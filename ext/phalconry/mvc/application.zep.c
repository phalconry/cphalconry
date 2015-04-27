
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


ZEPHIR_INIT_CLASS(Phalconry_Mvc_Application) {

	ZEPHIR_REGISTER_CLASS_EX(Phalconry\\Mvc, Application, phalconry, mvc_application, zephir_get_internal_ce(SS("phalcon\\mvc\\application") TSRMLS_CC), phalconry_mvc_application_method_entry, 0);

	return SUCCESS;

}

/**
 * Application constructor.
 *
 * @param \Phalcon\DiInterface $di [Optional]
 * @param \Phalconry\Mvc\Env $env [Optional]
 */
PHP_METHOD(Phalconry_Mvc_Application, __construct) {

	int ZEPHIR_LAST_CALL_STATUS;
	zend_bool _0, _1;
	zval *di = NULL, *env = NULL, *eventsManager, *_2 = NULL, *_3 = NULL, *_4 = NULL, *_5 = NULL, *_6 = NULL, *_7 = NULL, *_8 = NULL, *_9 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 2, &di, &env);

	if (!di) {
		ZEPHIR_CPY_WRT(di, ZEPHIR_GLOBAL(global_null));
	} else {
		ZEPHIR_SEPARATE_PARAM(di);
	}
	if (!env) {
		env = ZEPHIR_GLOBAL(global_null);
	}


	_0 = Z_TYPE_P(di) != IS_NULL;
	if (_0) {
		_0 = !(zephir_is_instance_of(di, SL("Phalcon\\DiInterface") TSRMLS_CC));
	}
	if (_0) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "Parameter 'di' must be an instance of 'Phalcon\\DiInterface'", "", 0);
		return;
	}
	_1 = Z_TYPE_P(env) != IS_NULL;
	if (_1) {
		_1 = !(zephir_instance_of_ev(env, phalconry_mvc_env_ce TSRMLS_CC));
	}
	if (_1) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "Parameter 'env' must be an instance of 'Phalconry\\Mvc\\Env'", "", 0);
		return;
	}
	if (Z_TYPE_P(di) == IS_NULL) {
		ZEPHIR_INIT_NVAR(di);
		object_init_ex(di, zephir_get_internal_ce(SS("phalcon\\di\\factorydefault") TSRMLS_CC));
		ZEPHIR_CALL_METHOD(NULL, di, "__construct", NULL);
		zephir_check_call_status();
	}
	ZEPHIR_INIT_VAR(_2);
	ZVAL_STRING(_2, "app", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(NULL, di, "setshared", NULL, _2, this_ptr);
	zephir_check_temp_parameter(_2);
	zephir_check_call_status();
	if (Z_TYPE_P(env) == IS_OBJECT) {
		ZEPHIR_INIT_NVAR(_2);
		ZVAL_STRING(_2, "env", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(NULL, di, "setshared", NULL, _2, env);
		zephir_check_temp_parameter(_2);
		zephir_check_call_status();
	}
	ZEPHIR_INIT_NVAR(_2);
	ZVAL_STRING(_2, "moduleManager", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&_3, di, "has", NULL, _2);
	zephir_check_temp_parameter(_2);
	zephir_check_call_status();
	if (!(zephir_is_true(_3))) {
		ZEPHIR_INIT_NVAR(_2);
		ZVAL_STRING(_2, "moduleManager", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_INIT_VAR(_4);
		ZVAL_STRING(_4, "Phalconry\\Mvc\\Module\\Manager", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(NULL, di, "setshared", NULL, _2, _4);
		zephir_check_temp_parameter(_2);
		zephir_check_temp_parameter(_4);
		zephir_check_call_status();
	}
	ZEPHIR_INIT_NVAR(_2);
	ZVAL_STRING(_2, "responder", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&_5, di, "has", NULL, _2);
	zephir_check_temp_parameter(_2);
	zephir_check_call_status();
	if (!(zephir_is_true(_5))) {
		ZEPHIR_INIT_NVAR(_2);
		ZVAL_STRING(_2, "responder", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_INIT_NVAR(_4);
		ZVAL_STRING(_4, "Phalconry\\Mvc\\Responder", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(NULL, di, "setshared", NULL, _2, _4);
		zephir_check_temp_parameter(_2);
		zephir_check_temp_parameter(_4);
		zephir_check_call_status();
	}
	ZEPHIR_INIT_NVAR(_2);
	ZVAL_STRING(_2, "view", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&_6, di, "has", NULL, _2);
	zephir_check_temp_parameter(_2);
	zephir_check_call_status();
	if (!(zephir_is_true(_6))) {
		ZEPHIR_INIT_NVAR(_2);
		ZVAL_STRING(_2, "view", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_INIT_NVAR(_4);
		ZVAL_STRING(_4, "Phalcon\\Mvc\\View", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(NULL, di, "setshared", NULL, _2, _4);
		zephir_check_temp_parameter(_2);
		zephir_check_temp_parameter(_4);
		zephir_check_call_status();
	}
	ZEPHIR_INIT_NVAR(_2);
	ZVAL_STRING(_2, "viewEvents", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&_7, di, "has", NULL, _2);
	zephir_check_temp_parameter(_2);
	zephir_check_call_status();
	if (!(zephir_is_true(_7))) {
		ZEPHIR_INIT_NVAR(_2);
		ZVAL_STRING(_2, "viewEvents", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_INIT_NVAR(_4);
		ZVAL_STRING(_4, "Phalcon\\Events\\Manager", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(NULL, di, "setshared", NULL, _2, _4);
		zephir_check_temp_parameter(_2);
		zephir_check_temp_parameter(_4);
		zephir_check_call_status();
	}
	ZEPHIR_INIT_NVAR(_2);
	ZVAL_STRING(_2, "hmvcRequest", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&_8, di, "has", NULL, _2);
	zephir_check_temp_parameter(_2);
	zephir_check_call_status();
	if (!(zephir_is_true(_8))) {
		ZEPHIR_INIT_NVAR(_2);
		ZVAL_STRING(_2, "hmvcRequest", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_INIT_NVAR(_4);
		ZVAL_STRING(_4, "Phalconry\\Mvc\\HmvcRequest", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(NULL, di, "setshared", NULL, _2, _4);
		zephir_check_temp_parameter(_2);
		zephir_check_temp_parameter(_4);
		zephir_check_call_status();
	}
	ZEPHIR_INIT_NVAR(_2);
	ZVAL_STRING(_2, "httpClient", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&_9, di, "has", NULL, _2);
	zephir_check_temp_parameter(_2);
	zephir_check_call_status();
	if (!(zephir_is_true(_9))) {
		ZEPHIR_INIT_NVAR(_2);
		ZVAL_STRING(_2, "httpClient", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_INIT_NVAR(_4);
		ZVAL_STRING(_4, "Phalconry\\Http\\Client", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(NULL, di, "setshared", NULL, _2, _4);
		zephir_check_temp_parameter(_2);
		zephir_check_temp_parameter(_4);
		zephir_check_call_status();
	}
	ZEPHIR_INIT_VAR(eventsManager);
	object_init_ex(eventsManager, zephir_get_internal_ce(SS("phalcon\\events\\manager") TSRMLS_CC));
	if (zephir_has_constructor(eventsManager TSRMLS_CC)) {
		ZEPHIR_CALL_METHOD(NULL, eventsManager, "__construct", NULL);
		zephir_check_call_status();
	}
	ZEPHIR_INIT_NVAR(_2);
	object_init_ex(_2, phalconry_mvc_application_bootstrap_ce);
	if (zephir_has_constructor(_2 TSRMLS_CC)) {
		ZEPHIR_CALL_METHOD(NULL, _2, "__construct", NULL);
		zephir_check_call_status();
	}
	ZEPHIR_INIT_NVAR(_4);
	ZVAL_STRING(_4, "application", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(NULL, eventsManager, "attach", NULL, _4, _2);
	zephir_check_temp_parameter(_4);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "seteventsmanager", NULL, eventsManager);
	zephir_check_call_status();
	ZEPHIR_CALL_PARENT(NULL, phalconry_mvc_application_ce, this_ptr, "__construct", NULL, di);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * Returns the global environment instance or an item from it
 *
 * @param string key [Optional] Item to fetch from Env. If omitted, the Env object is returned.
 * @return \Phalconry\Mvc\Env|\Phalcon\Config|mixed
 */
PHP_METHOD(Phalconry_Mvc_Application, env) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *key = NULL, *_0 = NULL, *_1 = NULL, *_2 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &key);

	if (!key) {
		key = ZEPHIR_GLOBAL(global_null);
	}


	if (Z_TYPE_P(key) == IS_NULL) {
		ZEPHIR_CALL_METHOD(&_0, this_ptr, "getdi", NULL);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(_1);
		ZVAL_STRING(_1, "env", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_RETURN_CALL_METHOD(_0, "getshared", NULL, _1);
		zephir_check_temp_parameter(_1);
		zephir_check_call_status();
		RETURN_MM();
	}
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getdi", NULL);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "env", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&_2, _0, "getshared", NULL, _1);
	zephir_check_temp_parameter(_1);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(_2, "get", NULL, key);
	zephir_check_call_status();
	RETURN_MM();

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
	ZVAL_STRING(_2, "env", ZEPHIR_TEMP_PARAM_COPY);
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
	ZVAL_STRING(_2, "env", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&_1, _0, "getshared", NULL, _2);
	zephir_check_temp_parameter(_2);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, _1, "setpath", NULL, name, value);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * Returns a module by name, or the primary module if none given.
 *
 * @param string $name [Optional] Module name
 * @return \Phalconry\Mvc\Module
 */
PHP_METHOD(Phalconry_Mvc_Application, getModuleObject) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *name_param = NULL, *_0 = NULL, *_1 = NULL, *_2;
	zval *name = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &name_param);

	if (!name_param) {
		ZEPHIR_INIT_VAR(name);
		ZVAL_EMPTY_STRING(name);
	} else {
		zephir_get_strval(name, name_param);
	}


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getdi", NULL);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_2);
	ZVAL_STRING(_2, "moduleManager", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&_1, _0, "getshared", NULL, _2);
	zephir_check_temp_parameter(_2);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(_1, "get", NULL, name);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Sets the type of response
 *
 * @see \Phalconry\Mvc\Responder
 *
 * @param string
 */
PHP_METHOD(Phalconry_Mvc_Application, setResponseType) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *responseType_param = NULL, *_0 = NULL, *_1 = NULL, *_2;
	zval *responseType = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &responseType_param);

	zephir_get_strval(responseType, responseType_param);


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getdi", NULL);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_2);
	ZVAL_STRING(_2, "responder", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&_1, _0, "getshared", NULL, _2);
	zephir_check_temp_parameter(_2);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, _1, "settype", NULL, responseType);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * Returns the type of response
 *
 * @see \Phalconry\Mvc\Responder
 *
 * @return string
 */
PHP_METHOD(Phalconry_Mvc_Application, getResponseType) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *_0 = NULL, *_1 = NULL, *_2;

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getdi", NULL);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_2);
	ZVAL_STRING(_2, "responder", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&_1, _0, "getshared", NULL, _2);
	zephir_check_temp_parameter(_2);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(_1, "gettype", NULL);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Runs the application and sends the response.
 */
PHP_METHOD(Phalconry_Mvc_Application, run) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *response = NULL, *_0 = NULL, *_1 = NULL, *_2 = NULL, *_3 = NULL, *_4 = NULL;

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getdi", NULL);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_2);
	ZVAL_STRING(_2, "env", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&_1, _0, "has", NULL, _2);
	zephir_check_temp_parameter(_2);
	zephir_check_call_status();
	if (unlikely(!zephir_is_true(_1))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(zephir_get_internal_ce(SS("phalcon\\mvc\\application\\exception") TSRMLS_CC), "Env instance not set in DI container", "phalconry/mvc/application.zep", 148);
		return;
	}
	ZEPHIR_INIT_NVAR(_2);
	ZVAL_NULL(_2);
	ZEPHIR_CALL_METHOD(&response, this_ptr, "handle", NULL, _2);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_3, this_ptr, "getdi", NULL);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(_2);
	ZVAL_STRING(_2, "responder", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&_4, _3, "getshared", NULL, _2);
	zephir_check_temp_parameter(_2);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, _4, "respond", NULL, response);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * Adds the default services to the DI
 *
 * @param \Phalcon\DiInterface $di
 */
PHP_METHOD(Phalconry_Mvc_Application, setDefaultServices) {

	zval *di;

	zephir_fetch_params(0, 1, 0, &di);



	if (!(zephir_is_instance_of(di, SL("Phalcon\\DiInterface") TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STRW(spl_ce_InvalidArgumentException, "Parameter 'di' must be an instance of 'Phalcon\\DiInterface'", "", 0);
		return;
	}

}

