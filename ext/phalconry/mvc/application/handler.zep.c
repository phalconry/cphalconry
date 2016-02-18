
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
#include "kernel/fcall.h"
#include "kernel/memory.h"
#include "kernel/object.h"
#include "kernel/operators.h"


ZEPHIR_INIT_CLASS(Phalconry_Mvc_Application_Handler) {

	ZEPHIR_REGISTER_CLASS(Phalconry\\Mvc\\Application, Handler, phalconry, mvc_application_handler, phalconry_mvc_application_handler_method_entry, 0);

	/**
	 * The application instance.
	 *
	 * @var \Phalconry\Mvc\ApplicationInterface
	 */
	zend_declare_property_null(phalconry_mvc_application_handler_ce, SL("_application"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_class_implements(phalconry_mvc_application_handler_ce TSRMLS_CC, 1, phalconry_mvc_application_handlerinterface_ce);
	return SUCCESS;

}

/**
 * Constructor - sets the application.
 *
 * @param \Phalconry\Mvc\ApplicationInterface app
 */
PHP_METHOD(Phalconry_Mvc_Application_Handler, __construct) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *app;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &app);



	ZEPHIR_CALL_METHOD(NULL, this_ptr, "setapplication", NULL, 0, app);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * Sets the application.
 *
 * @param \Phalconry\Mvc\ApplicationInterface app
 * @return void
 */
PHP_METHOD(Phalconry_Mvc_Application_Handler, setApplication) {

	zval *app;

	zephir_fetch_params(0, 1, 0, &app);



	zephir_update_property_this(this_ptr, SL("_application"), app TSRMLS_CC);

}

/**
 * Returns the application.
 *
 * @return \Phalconry\Mvc\ApplicationInterface
 */
PHP_METHOD(Phalconry_Mvc_Application_Handler, getApplication) {


	RETURN_MEMBER(this_ptr, "_application");

}

/**
 * Handles a MVC request
 *
 * @param string uri
 * @return \Phalcon\Http\ResponseInterface|boolean
 */
PHP_METHOD(Phalconry_Mvc_Application_Handler, handle) {

	int ZEPHIR_LAST_CALL_STATUS;
	zend_bool hasEvents, returnedResponse;
	zval *uri = NULL, *app = NULL, *dependencyInjector = NULL, *eventsManager = NULL, *router = NULL, *dispatcher = NULL, *implicitView = NULL, *response = NULL, *view = NULL, *moduleName = NULL, *moduleManager = NULL, *module = NULL, *controller = NULL, *possibleResponse = NULL, *renderStatus = NULL, *_0, *_1 = NULL, *_2 = NULL, *_3, *_4 = NULL, *_5 = NULL, *_6 = NULL, *_7 = NULL, *_8 = NULL, *_9 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &uri);

	if (!uri) {
		uri = ZEPHIR_GLOBAL(global_null);
	}


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_application"), PH_NOISY_CC);
	ZEPHIR_CPY_WRT(app, _0);
	ZEPHIR_CALL_METHOD(&_1, app, "getdi", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(dependencyInjector, _1);
	ZEPHIR_CALL_METHOD(&_1, app, "geteventsmanager", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(eventsManager, _1);
	ZEPHIR_INIT_VAR(_2);
	ZVAL_STRING(_2, "router", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&_1, dependencyInjector, "getshared", NULL, 0, _2);
	zephir_check_temp_parameter(_2);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(router, _1);
	ZEPHIR_INIT_NVAR(_2);
	ZVAL_STRING(_2, "moduleManager", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&_1, dependencyInjector, "getshared", NULL, 0, _2);
	zephir_check_temp_parameter(_2);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(moduleManager, _1);
	ZEPHIR_INIT_NVAR(_2);
	ZVAL_STRING(_2, "dispatcher", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&_1, dependencyInjector, "getshared", NULL, 0, _2);
	zephir_check_temp_parameter(_2);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(dispatcher, _1);
	ZEPHIR_CALL_METHOD(&_1, app, "getconfig", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(_2);
	ZVAL_STRING(_2, "implicitView", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_VAR(_3);
	ZVAL_BOOL(_3, 1);
	ZEPHIR_CALL_METHOD(&implicitView, _1, "get", NULL, 0, _2, _3);
	zephir_check_temp_parameter(_2);
	zephir_check_call_status();
	hasEvents = (Z_TYPE_P(eventsManager) == IS_OBJECT);
	ZEPHIR_CALL_METHOD(NULL, router, "handle", NULL, 0, uri);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&moduleName, router, "getmodulename", NULL, 0);
	zephir_check_call_status();
	if (!(zephir_is_true(moduleName))) {
		ZEPHIR_CALL_METHOD(&moduleName, moduleManager, "getdefaultmodulename", NULL, 0);
		zephir_check_call_status();
	}
	if (zephir_is_true(moduleName)) {
		if (hasEvents == 1) {
			ZEPHIR_INIT_NVAR(_2);
			ZVAL_STRING(_2, "application:beforeStartModule", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(&_4, eventsManager, "fire", NULL, 0, _2, app, moduleName);
			zephir_check_temp_parameter(_2);
			zephir_check_call_status();
			if (ZEPHIR_IS_FALSE_IDENTICAL(_4)) {
				RETURN_MM_BOOL(0);
			}
		}
		ZEPHIR_CALL_METHOD(&_4, moduleManager, "getmodule", NULL, 0, moduleName);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(module, _4);
		ZEPHIR_CALL_METHOD(NULL, moduleManager, "loadmodule", NULL, 0, module);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&_4, module, "getcontrollernamespace", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, dispatcher, "setdefaultnamespace", NULL, 0, _4);
		zephir_check_call_status();
		if (hasEvents == 1) {
			ZEPHIR_INIT_NVAR(_2);
			ZVAL_STRING(_2, "application:afterStartModule", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(NULL, eventsManager, "fire", NULL, 0, _2, app, module);
			zephir_check_temp_parameter(_2);
			zephir_check_call_status();
		}
	}
	ZEPHIR_CALL_METHOD(NULL, dispatcher, "setmodulename", NULL, 0, moduleName);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_4, router, "getnamespacename", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, dispatcher, "setnamespacename", NULL, 0, _4);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_5, router, "getcontrollername", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, dispatcher, "setcontrollername", NULL, 0, _5);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_6, router, "getactionname", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, dispatcher, "setactionname", NULL, 0, _6);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_7, router, "getparams", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, dispatcher, "setparams", NULL, 0, _7);
	zephir_check_call_status();
	if (ZEPHIR_IS_TRUE_IDENTICAL(implicitView)) {
		ZEPHIR_INIT_NVAR(_2);
		ZVAL_STRING(_2, "view", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&_8, dependencyInjector, "getshared", NULL, 0, _2);
		zephir_check_temp_parameter(_2);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(view, _8);
		ZEPHIR_CALL_METHOD(NULL, view, "start", NULL, 0);
		zephir_check_call_status();
	}
	if (hasEvents == 1) {
		ZEPHIR_INIT_NVAR(_2);
		ZVAL_STRING(_2, "application:beforeHandleRequest", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&_8, eventsManager, "fire", NULL, 0, _2, app, dispatcher);
		zephir_check_temp_parameter(_2);
		zephir_check_call_status();
		if (ZEPHIR_IS_FALSE_IDENTICAL(_8)) {
			RETURN_MM_BOOL(0);
		}
	}
	ZEPHIR_CALL_METHOD(&controller, dispatcher, "dispatch", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&possibleResponse, dispatcher, "getreturnedvalue", NULL, 0);
	zephir_check_call_status();
	if (ZEPHIR_IS_FALSE_IDENTICAL(possibleResponse)) {
		ZEPHIR_INIT_NVAR(_2);
		ZVAL_STRING(_2, "response", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_RETURN_CALL_METHOD(dependencyInjector, "getshared", NULL, 0, _2);
		zephir_check_temp_parameter(_2);
		zephir_check_call_status();
		RETURN_MM();
	}
	if (hasEvents == 1) {
		ZEPHIR_INIT_NVAR(_2);
		ZVAL_STRING(_2, "application:afterHandleRequest", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(NULL, eventsManager, "fire", NULL, 0, _2, app, controller);
		zephir_check_temp_parameter(_2);
		zephir_check_call_status();
	}
	if (Z_TYPE_P(possibleResponse) == IS_OBJECT) {
		returnedResponse = (zephir_is_instance_of(possibleResponse, SL("Phalcon\\Http\\ResponseInterface") TSRMLS_CC));
	} else {
		returnedResponse = 0;
	}
	if (returnedResponse == 0) {
		if (ZEPHIR_IS_TRUE_IDENTICAL(implicitView)) {
			if (Z_TYPE_P(controller) == IS_OBJECT) {
				ZEPHIR_INIT_VAR(renderStatus);
				ZVAL_BOOL(renderStatus, 1);
				if (hasEvents == 1) {
					ZEPHIR_INIT_NVAR(_2);
					ZVAL_STRING(_2, "application:viewRender", ZEPHIR_TEMP_PARAM_COPY);
					ZEPHIR_CALL_METHOD(&renderStatus, eventsManager, "fire", NULL, 0, _2, app, view);
					zephir_check_temp_parameter(_2);
					zephir_check_call_status();
				}
				if (!ZEPHIR_IS_FALSE_IDENTICAL(renderStatus)) {
					ZEPHIR_CALL_METHOD(&_4, dispatcher, "getcontrollername", NULL, 0);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&_8, dispatcher, "getactionname", NULL, 0);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&_9, dispatcher, "getparams", NULL, 0);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(NULL, view, "render", NULL, 0, _4, _8, _9);
					zephir_check_call_status();
				}
			}
		}
	}
	if (ZEPHIR_IS_TRUE_IDENTICAL(implicitView)) {
		ZEPHIR_CALL_METHOD(NULL, view, "finish", NULL, 0);
		zephir_check_call_status();
	}
	if (returnedResponse == 0) {
		ZEPHIR_INIT_NVAR(_2);
		ZVAL_STRING(_2, "response", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&_4, dependencyInjector, "getshared", NULL, 0, _2);
		zephir_check_temp_parameter(_2);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(response, _4);
		if (ZEPHIR_IS_TRUE_IDENTICAL(implicitView)) {
			ZEPHIR_CALL_METHOD(&_4, view, "getcontent", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(NULL, response, "setcontent", NULL, 0, _4);
			zephir_check_call_status();
		}
	} else {
		ZEPHIR_CPY_WRT(response, possibleResponse);
	}
	RETURN_CCTOR(response);

}

