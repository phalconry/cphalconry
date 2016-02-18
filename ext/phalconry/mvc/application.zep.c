
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
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/object.h"
#include "kernel/operators.h"
#include "kernel/hash.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"


ZEPHIR_INIT_CLASS(Phalconry_Mvc_Application) {

	ZEPHIR_REGISTER_CLASS(Phalconry\\Mvc, Application, phalconry, mvc_application, phalconry_mvc_application_method_entry, 0);

	/**
	 * Dependency injection container.
	 *
	 * @var \Phalcon\DiInterface
	 */
	zend_declare_property_null(phalconry_mvc_application_ce, SL("_dependencyInjector"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * Events manager.
	 *
	 * @var \Phalcon\Events\ManagerInterface
	 */
	zend_declare_property_null(phalconry_mvc_application_ce, SL("_eventsManager"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * Application bootstrap.
	 *
	 * @var \Phalconry\Mvc\Application\BootstrapInterface
	 */
	zend_declare_property_null(phalconry_mvc_application_ce, SL("_bootstrap"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * Main request handler.
	 *
	 * @var \Phalconry\Mvc\Application\HandlerInterface
	 */
	zend_declare_property_null(phalconry_mvc_application_ce, SL("_handler"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * Whether the app has been booted.
	 *
	 * @var boolean
	 */
	zend_declare_property_bool(phalconry_mvc_application_ce, SL("_booted"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_class_implements(phalconry_mvc_application_ce TSRMLS_CC, 1, phalconry_mvc_applicationinterface_ce);
	return SUCCESS;

}

/**
 * Application constructor.
 *
 * @param \Phalcon\DiInterface di [Optional]
 * @param \Phalconry\Mvc\EnvironmentInterface env [Optional]
 */
PHP_METHOD(Phalconry_Mvc_Application, __construct) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *di = NULL, *env = NULL, *_0 = NULL;

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


	if (Z_TYPE_P(di) != IS_OBJECT) {
		ZEPHIR_INIT_NVAR(di);
		object_init_ex(di, zephir_get_internal_ce(SS("phalcon\\di\\factorydefault") TSRMLS_CC));
		ZEPHIR_CALL_METHOD(NULL, di, "__construct", NULL, 0);
		zephir_check_call_status();
	}
	if (Z_TYPE_P(env) == IS_OBJECT) {
		ZEPHIR_INIT_VAR(_0);
		ZVAL_STRING(_0, "env", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(NULL, di, "setshared", NULL, 0, _0, env);
		zephir_check_temp_parameter(_0);
		zephir_check_call_status();
	}
	ZEPHIR_INIT_NVAR(_0);
	ZVAL_STRING(_0, "app", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(NULL, di, "setshared", NULL, 0, _0, this_ptr);
	zephir_check_temp_parameter(_0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "setdi", NULL, 0, di);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * Sets the dependency injector
 *
 * @param \Phalcon\DiInterface dependencyInjector
 */
PHP_METHOD(Phalconry_Mvc_Application, setDI) {

	zval *dependencyInjector;

	zephir_fetch_params(0, 1, 0, &dependencyInjector);



	zephir_update_property_this(this_ptr, SL("_dependencyInjector"), dependencyInjector TSRMLS_CC);

}

/**
 * Returns the internal dependency injector
 *
 * @return \Phalcon\DiInterface
 */
PHP_METHOD(Phalconry_Mvc_Application, getDI) {


	RETURN_MEMBER(this_ptr, "_dependencyInjector");

}

/**
 * Sets the events manager.
 *
 * @param \Phalcon\Events\ManagerInterface eventsManager
 */
PHP_METHOD(Phalconry_Mvc_Application, setEventsManager) {

	zval *eventsManager;

	zephir_fetch_params(0, 1, 0, &eventsManager);



	zephir_update_property_this(this_ptr, SL("_eventsManager"), eventsManager TSRMLS_CC);

}

/**
 * Returns the internal event manager.
 *
 * @return \Phalcon\Events\ManagerInterface
 */
PHP_METHOD(Phalconry_Mvc_Application, getEventsManager) {


	RETURN_MEMBER(this_ptr, "_eventsManager");

}

/**
 * Returns the module manager.
 *
 * @return \Phalconry\Mvc\Module\ManagerInterface
 */
PHP_METHOD(Phalconry_Mvc_Application, getModuleManager) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *_0 = NULL, *_1;

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getdi", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_1);
	ZVAL_STRING(_1, "moduleManager", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_RETURN_CALL_METHOD(_0, "getshared", NULL, 0, _1);
	zephir_check_temp_parameter(_1);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Returns the primary module.
 *
 * @return \Phalconry\Mvc\ModuleInterface
 */
PHP_METHOD(Phalconry_Mvc_Application, getPrimaryModule) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *_0 = NULL;

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getmodulemanager", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(_0, "getprimarymodule", NULL, 0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Returns the dispatcher.
 *
 * @return \Phalcon\Mvc\DispatcherInterface
 */
PHP_METHOD(Phalconry_Mvc_Application, getDispatcher) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *_0 = NULL, *_1;

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getdi", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_1);
	ZVAL_STRING(_1, "dispatcher", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_RETURN_CALL_METHOD(_0, "getshared", NULL, 0, _1);
	zephir_check_temp_parameter(_1);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Returns the Env object.
 *
 * @return \Phalconry\Mvc\EnvironmentInterface
 */
PHP_METHOD(Phalconry_Mvc_Application, getEnvironment) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *_0 = NULL, *_1;

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getdi", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_1);
	ZVAL_STRING(_1, "env", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_RETURN_CALL_METHOD(_0, "getshared", NULL, 0, _1);
	zephir_check_temp_parameter(_1);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Returns the application Config object.
 *
 * @return \Phalcon\Config
 */
PHP_METHOD(Phalconry_Mvc_Application, getConfig) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *env = NULL, *_0 = NULL, *_1 = NULL, *_2 = NULL;

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&env, this_ptr, "getenvironment", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_1);
	ZVAL_STRING(_1, "application", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&_0, env, "has", NULL, 0, _1);
	zephir_check_temp_parameter(_1);
	zephir_check_call_status();
	if (!(zephir_is_true(_0))) {
		ZEPHIR_INIT_NVAR(_1);
		object_init_ex(_1, zephir_get_internal_ce(SS("phalcon\\config") TSRMLS_CC));
		ZEPHIR_CALL_METHOD(NULL, _1, "__construct", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(_2);
		ZVAL_STRING(_2, "application", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(NULL, env, "set", NULL, 0, _2, _1);
		zephir_check_temp_parameter(_2);
		zephir_check_call_status();
	}
	ZEPHIR_INIT_NVAR(_2);
	ZVAL_STRING(_2, "application", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_RETURN_CALL_METHOD(env, "get", NULL, 0, _2);
	zephir_check_temp_parameter(_2);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Returns the global environment instance or an item from it
 *
 * @param string key [Optional] Item to fetch from Env. If omitted, the Env object is returned.
 * @return \Phalconry\Mvc\EnvironmentInterface|\Phalcon\Config|mixed
 */
PHP_METHOD(Phalconry_Mvc_Application, env) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *key = NULL, *_0 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &key);

	if (!key) {
		key = ZEPHIR_GLOBAL(global_null);
	}


	if (Z_TYPE_P(key) == IS_NULL) {
		ZEPHIR_RETURN_CALL_METHOD(this_ptr, "getenvironment", NULL, 0);
		zephir_check_call_status();
		RETURN_MM();
	}
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getenvironment", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(_0, "get", NULL, 0, key);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Returns a directory path
 *
 * @param string name Path name.
 * @return string
 */
PHP_METHOD(Phalconry_Mvc_Application, getPath) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *name_param = NULL, *_0 = NULL;
	zval *name = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name_param);

	zephir_get_strval(name, name_param);


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getenvironment", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(_0, "getpath", NULL, 0, name);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Sets a named directory path.
 *
 * @param string name Path name.
 * @param string value Absolute directory path.
 */
PHP_METHOD(Phalconry_Mvc_Application, setPath) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *name_param = NULL, *value_param = NULL, *_0 = NULL;
	zval *name = NULL, *value = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &name_param, &value_param);

	zephir_get_strval(name, name_param);
	zephir_get_strval(value, value_param);


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getenvironment", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, _0, "setpath", NULL, 0, name, value);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * Sets the bootstrap object.
 *
 * @param \Phalconry\Mvc\Application\BootstrapInterface bootstrap
 */
PHP_METHOD(Phalconry_Mvc_Application, setBootstrap) {

	zval *bootstrap;

	zephir_fetch_params(0, 1, 0, &bootstrap);



	zephir_update_property_this(this_ptr, SL("_bootstrap"), bootstrap TSRMLS_CC);

}

/**
 * Sets the request handler.
 *
 * @param \Phalconry\Mvc\Application\HandlerInterface handler
 */
PHP_METHOD(Phalconry_Mvc_Application, setHandler) {

	zval *handler;

	zephir_fetch_params(0, 1, 0, &handler);



	zephir_update_property_this(this_ptr, SL("_handler"), handler TSRMLS_CC);

}

/**
 * Whether the application has booted.
 *
 * @return boolean
 */
PHP_METHOD(Phalconry_Mvc_Application, isBooted) {


	RETURN_MEMBER(this_ptr, "_booted");

}

/**
 * Loads a service through its provider.
 *
 * @param \Phalconry\Di\ServiceProviderInterface provider
 * @return \Phalconry\Mvc\ApplicationInterface
 */
PHP_METHOD(Phalconry_Mvc_Application, loadService) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *provider, *_0 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &provider);



	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getdi", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, provider, "register", NULL, 0, _0);
	zephir_check_call_status();
	RETURN_THIS();

}

/**
 * Loads an array of service providers.
 *
 * @param array providers
 * @return \Phalconry\Mvc\ApplicationInterface
 */
PHP_METHOD(Phalconry_Mvc_Application, loadServices) {

	HashTable *_1;
	HashPosition _0;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *providers_param = NULL, *dependencyInjector = NULL, *provider = NULL, **_2;
	zval *providers = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &providers_param);

	providers = providers_param;



	ZEPHIR_CALL_METHOD(&dependencyInjector, this_ptr, "getdi", NULL, 0);
	zephir_check_call_status();
	zephir_is_iterable(providers, &_1, &_0, 0, 0, "phalconry/mvc/application.zep", 268);
	for (
	  ; zephir_hash_get_current_data_ex(_1, (void**) &_2, &_0) == SUCCESS
	  ; zephir_hash_move_forward_ex(_1, &_0)
	) {
		ZEPHIR_GET_HVALUE(provider, _2);
		ZEPHIR_CALL_METHOD(NULL, provider, "register", NULL, 0, dependencyInjector);
		zephir_check_call_status();
	}
	RETURN_THIS();

}

/**
 * Runs the application and sends the response.
 *
 * @return void
 */
PHP_METHOD(Phalconry_Mvc_Application, run) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *response = NULL, *_0 = NULL, *_1;

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "isbooted", NULL, 0);
	zephir_check_call_status();
	if (!(zephir_is_true(_0))) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "bootstrap", NULL, 0);
		zephir_check_call_status();
	}
	ZEPHIR_INIT_VAR(_1);
	ZVAL_NULL(_1);
	ZEPHIR_CALL_METHOD(&response, this_ptr, "handle", NULL, 0, _1);
	zephir_check_call_status();
	if (Z_TYPE_P(response) == IS_OBJECT) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "respond", NULL, 0, response);
		zephir_check_call_status();
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Boot the application.
 *
 * @return boolean
 */
PHP_METHOD(Phalconry_Mvc_Application, bootstrap) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *dependencyInjector = NULL, *bootstrap = NULL, *eventsManager = NULL, *eventsConfig = NULL, *_0, *_1, *_2 = NULL, *_3 = NULL, *_4 = NULL, *_5;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_booted"), PH_NOISY_CC);
	if (ZEPHIR_IS_TRUE_IDENTICAL(_0)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalconry_mvc_application_exception_ce, "Application has already booted.", "phalconry/mvc/application.zep", 302);
		return;
	}
	zephir_update_property_this(this_ptr, SL("_booted"), (1) ? ZEPHIR_GLOBAL(global_true) : ZEPHIR_GLOBAL(global_false) TSRMLS_CC);
	ZEPHIR_CALL_METHOD(&dependencyInjector, this_ptr, "getdi", NULL, 0);
	zephir_check_call_status();
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("_bootstrap"), PH_NOISY_CC);
	ZEPHIR_CPY_WRT(bootstrap, _1);
	if (Z_TYPE_P(bootstrap) != IS_OBJECT) {
		ZEPHIR_INIT_VAR(_3);
		ZVAL_STRING(_3, "bootstrap", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&_2, dependencyInjector, "has", NULL, 0, _3);
		zephir_check_temp_parameter(_3);
		zephir_check_call_status();
		if (zephir_is_true(_2)) {
			ZEPHIR_INIT_NVAR(_3);
			ZVAL_STRING(_3, "bootstrap", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(&bootstrap, dependencyInjector, "get", NULL, 0, _3);
			zephir_check_temp_parameter(_3);
			zephir_check_call_status();
		} else {
			ZEPHIR_INIT_NVAR(bootstrap);
			object_init_ex(bootstrap, phalconry_mvc_application_bootstrap_ce);
			if (zephir_has_constructor(bootstrap TSRMLS_CC)) {
				ZEPHIR_CALL_METHOD(NULL, bootstrap, "__construct", NULL, 0);
				zephir_check_call_status();
			}
		}
	}
	ZEPHIR_CALL_METHOD(NULL, bootstrap, "boot", NULL, 50, this_ptr);
	zephir_check_call_status();
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("_eventsManager"), PH_NOISY_CC);
	ZEPHIR_CPY_WRT(eventsManager, _1);
	if (Z_TYPE_P(eventsManager) != IS_OBJECT) {
		ZEPHIR_INIT_NVAR(_3);
		ZVAL_STRING(_3, "events", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&_2, dependencyInjector, "has", NULL, 0, _3);
		zephir_check_temp_parameter(_3);
		zephir_check_call_status();
		if (!(zephir_is_true(_2))) {
			RETURN_MM_NULL();
		}
		ZEPHIR_INIT_NVAR(_3);
		ZVAL_STRING(_3, "events", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&eventsManager, dependencyInjector, "getshared", NULL, 0, _3);
		zephir_check_temp_parameter(_3);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "seteventsmanager", NULL, 0, eventsManager);
		zephir_check_call_status();
	}
	ZEPHIR_CALL_METHOD(&_2, this_ptr, "getconfig", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(_3);
	ZVAL_STRING(_3, "events", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&eventsConfig, _2, "get", NULL, 0, _3);
	zephir_check_temp_parameter(_3);
	zephir_check_call_status();
	if (Z_TYPE_P(eventsConfig) == IS_OBJECT) {
		ZEPHIR_INIT_NVAR(_3);
		ZVAL_STRING(_3, "attach", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_INIT_VAR(_5);
		ZVAL_BOOL(_5, 0);
		ZEPHIR_CALL_METHOD(&_4, eventsConfig, "get", NULL, 0, _3, _5);
		zephir_check_temp_parameter(_3);
		zephir_check_call_status();
		if (zephir_is_true(_4)) {
			ZEPHIR_INIT_NVAR(_3);
			ZVAL_STRING(_3, "application", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(NULL, eventsManager, "attach", NULL, 0, _3, this_ptr);
			zephir_check_temp_parameter(_3);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(_3);
	ZVAL_STRING(_3, "application:boot", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(NULL, eventsManager, "fire", NULL, 0, _3, this_ptr);
	zephir_check_temp_parameter(_3);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * Handles a MVC request
 *
 * @param string uri
 * @return mixed|\Phalcon\Http\ResponseInterface|boolean
 */
PHP_METHOD(Phalconry_Mvc_Application, handle) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *uri = NULL, *handler = NULL, *_0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &uri);

	if (!uri) {
		uri = ZEPHIR_GLOBAL(global_null);
	}


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_handler"), PH_NOISY_CC);
	ZEPHIR_CPY_WRT(handler, _0);
	if (Z_TYPE_P(handler) != IS_OBJECT) {
		ZEPHIR_INIT_NVAR(handler);
		object_init_ex(handler, phalconry_mvc_application_handler_ce);
		ZEPHIR_CALL_METHOD(NULL, handler, "__construct", NULL, 51, this_ptr);
		zephir_check_call_status();
	}
	ZEPHIR_RETURN_CALL_METHOD(handler, "handle", NULL, 52, uri);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Sends the response.
 *
 * @param mixed|\Phalcon\Http\ResponseInterface response
 */
PHP_METHOD(Phalconry_Mvc_Application, respond) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *response = NULL, *eventsManager = NULL, *_0 = NULL, *_1 = NULL, *_2 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &response);

	if (!response) {
		response = ZEPHIR_GLOBAL(global_null);
	}


	if (Z_TYPE_P(response) == IS_OBJECT) {
		ZEPHIR_CALL_METHOD(&eventsManager, this_ptr, "geteventsmanager", NULL, 0);
		zephir_check_call_status();
		if (Z_TYPE_P(eventsManager) == IS_OBJECT) {
			ZEPHIR_INIT_VAR(_0);
			ZVAL_STRING(_0, "application:beforeSendResponse", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(NULL, eventsManager, "fire", NULL, 0, _0, this_ptr, response);
			zephir_check_temp_parameter(_0);
			zephir_check_call_status();
		}
		ZEPHIR_CALL_METHOD(&_1, this_ptr, "getdi", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(_0);
		ZVAL_STRING(_0, "responder", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&_2, _1, "getshared", NULL, 0, _0);
		zephir_check_temp_parameter(_0);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, _2, "respond", NULL, 0, response);
		zephir_check_call_status();
	}
	ZEPHIR_MM_RESTORE();

}

