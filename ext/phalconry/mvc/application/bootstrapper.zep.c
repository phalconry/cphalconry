
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
#include "kernel/file.h"
#include "kernel/concat.h"
#include "kernel/require.h"
#include "kernel/hash.h"
#include "kernel/array.h"
#include "kernel/operators.h"


ZEPHIR_INIT_CLASS(Phalconry_Mvc_Application_Bootstrapper) {

	ZEPHIR_REGISTER_CLASS(Phalconry\\Mvc\\Application, Bootstrapper, phalconry, mvc_application_bootstrapper, phalconry_mvc_application_bootstrapper_method_entry, 0);

	return SUCCESS;

}

/**
 * application:boot event callback
 *
 * Boots the application using values from Env (DI key: "env").
 *
 * * Loader is set using the optional "loader" (array) arguments:
 * 		* "namespaces" (array)
 * 		* "dirs" (array)
 * 		* "classes" (array)
 *
 * * If no "loader" argument is set, the file "loader.php" in directory "config" MUST exist.
 *
 * * Application::setDefaultServices() is called, passing the DI as the only argument.
 *
 * * If "modules" (array) argument exists, they are registered and autoloaded. Otherwise, a file named
 * "modules.php" MUST exist in the "config" directory.
 *
 * * If a "default_module" (string) argument exists, it will be used to set the default module
 * (via `Application::setDefaultModule()`)
 */
PHP_METHOD(Phalconry_Mvc_Application_Bootstrapper, boot) {

	HashTable *_12;
	HashPosition _11;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *event, *app, *nothing = NULL, *di = NULL, *env = NULL, *loader, *configPath = NULL, *loaderArgs, *_0 = NULL, *_1 = NULL, *_2 = NULL, *_3 = NULL, *_4, *_5 = NULL, *_6 = NULL, *_7 = NULL, *_8 = NULL, *_9 = NULL, *_10 = NULL, *modules = NULL, *modArgs = NULL, *moduleClasses, **_13, *modClassName = NULL, *modPath = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &event, &app, &nothing);

	ZEPHIR_SEPARATE_PARAM(app);
	if (!nothing) {
		nothing = ZEPHIR_GLOBAL(global_null);
	}


	ZEPHIR_CALL_METHOD(&di, app, "getdi", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_0);
	ZVAL_STRING(_0, "env", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&env, di, "getshared", NULL, 0, _0);
	zephir_check_temp_parameter(_0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(loader);
	object_init_ex(loader, zephir_get_internal_ce(SS("phalcon\\loader") TSRMLS_CC));
	ZEPHIR_CALL_METHOD(NULL, loader, "__construct", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(_0);
	ZVAL_STRING(_0, "config", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&configPath, env, "getpath", NULL, 0, _0);
	zephir_check_temp_parameter(_0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, loader, "register", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(_1, app);
	if (zephir_set_symbol_str(SS("app"), _1 TSRMLS_CC) == FAILURE){
	  return;
	}
	ZEPHIR_CPY_WRT(_2, di);
	if (zephir_set_symbol_str(SS("di"), _2 TSRMLS_CC) == FAILURE){
	  return;
	}
	ZEPHIR_CPY_WRT(_3, loader);
	if (zephir_set_symbol_str(SS("loader"), _3 TSRMLS_CC) == FAILURE){
	  return;
	}
	ZEPHIR_OBS_VAR(_4);
	zephir_read_property(&_4, env, SL("loader"), PH_NOISY_CC);
	if (Z_TYPE_P(_4) == IS_OBJECT) {
		ZEPHIR_OBS_VAR(loaderArgs);
		zephir_read_property(&loaderArgs, env, SL("loader"), PH_NOISY_CC);
		ZEPHIR_OBS_VAR(_5);
		zephir_read_property(&_5, loaderArgs, SL("namespaces"), PH_NOISY_CC);
		if (Z_TYPE_P(_5) == IS_OBJECT) {
			ZEPHIR_OBS_VAR(_6);
			zephir_read_property(&_6, loaderArgs, SL("namespaces"), PH_NOISY_CC);
			ZEPHIR_CALL_METHOD(&_7, _6, "toarray", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(NULL, loader, "registernamespaces", NULL, 0, _7);
			zephir_check_call_status();
		}
		ZEPHIR_OBS_NVAR(_6);
		zephir_read_property(&_6, loaderArgs, SL("dirs"), PH_NOISY_CC);
		if (Z_TYPE_P(_6) == IS_OBJECT) {
			ZEPHIR_OBS_VAR(_8);
			zephir_read_property(&_8, loaderArgs, SL("dirs"), PH_NOISY_CC);
			ZEPHIR_CALL_METHOD(&_7, _8, "toarray", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(NULL, loader, "registerdirs", NULL, 0, _7);
			zephir_check_call_status();
		}
		ZEPHIR_OBS_NVAR(_6);
		zephir_read_property(&_6, loaderArgs, SL("classes"), PH_NOISY_CC);
		if (Z_TYPE_P(_6) == IS_OBJECT) {
			ZEPHIR_OBS_NVAR(_8);
			zephir_read_property(&_8, loaderArgs, SL("classes"), PH_NOISY_CC);
			ZEPHIR_CALL_METHOD(&_7, _8, "toarray", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(NULL, loader, "registerclasses", NULL, 0, _7);
			zephir_check_call_status();
		}
	} else {
		ZEPHIR_INIT_VAR(_9);
		ZEPHIR_CONCAT_VS(_9, configPath, "loader.php");
		if ((zephir_file_exists(_9 TSRMLS_CC) == SUCCESS)) {
			ZEPHIR_INIT_VAR(_10);
			ZEPHIR_CONCAT_VS(_10, configPath, "loader.php");
			if (zephir_require_zval(_10 TSRMLS_CC) == FAILURE) {
				RETURN_MM_NULL();
			}
		}
	}
	ZEPHIR_INIT_LNVAR(_9);
	ZEPHIR_CONCAT_VS(_9, configPath, "services.php");
	if ((zephir_file_exists(_9 TSRMLS_CC) == SUCCESS)) {
		ZEPHIR_INIT_LNVAR(_10);
		ZEPHIR_CONCAT_VS(_10, configPath, "services.php");
		if (zephir_require_zval(_10 TSRMLS_CC) == FAILURE) {
			RETURN_MM_NULL();
		}
	}
	ZEPHIR_CALL_METHOD(NULL, app, "setdefaultservices", NULL, 0, di);
	zephir_check_call_status();
	ZEPHIR_OBS_NVAR(_5);
	zephir_read_property(&_5, env, SL("modules"), PH_NOISY_CC);
	if (Z_TYPE_P(_5) == IS_OBJECT) {
		ZEPHIR_OBS_NVAR(_6);
		zephir_read_property(&_6, env, SL("modules"), PH_NOISY_CC);
		ZEPHIR_CALL_METHOD(&modules, _6, "toarray", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(moduleClasses);
		array_init(moduleClasses);
		ZEPHIR_INIT_NVAR(_0);
		ZVAL_BOOL(_0, 0);
		ZEPHIR_CALL_METHOD(NULL, app, "registermodules", NULL, 0, modules, _0);
		zephir_check_call_status();
		zephir_is_iterable(modules, &_12, &_11, 0, 0, "phalconry/mvc/application/bootstrapper.zep", 103);
		for (
		  ; zephir_hash_get_current_data_ex(_12, (void**) &_13, &_11) == SUCCESS
		  ; zephir_hash_move_forward_ex(_12, &_11)
		) {
			ZEPHIR_GET_HVALUE(modArgs, _13);
			ZEPHIR_OBS_NVAR(modClassName);
			if (zephir_array_isset_string_fetch(&modClassName, modArgs, SS("className"), 0 TSRMLS_CC)) {
				ZEPHIR_OBS_NVAR(modPath);
				if (zephir_array_isset_string_fetch(&modPath, modArgs, SS("path"), 0 TSRMLS_CC)) {
					zephir_array_update_zval(&moduleClasses, modClassName, &modPath, PH_COPY | PH_SEPARATE);
				}
			}
		}
		if (!(ZEPHIR_IS_EMPTY(moduleClasses))) {
			ZEPHIR_CALL_METHOD(NULL, loader, "registerclasses", NULL, 0, moduleClasses);
			zephir_check_call_status();
		}
		ZEPHIR_OBS_NVAR(_6);
		zephir_read_property(&_6, env, SL("default_module"), PH_NOISY_CC);
		if (Z_TYPE_P(_6) == IS_STRING) {
			ZEPHIR_OBS_NVAR(_8);
			zephir_read_property(&_8, env, SL("default_module"), PH_NOISY_CC);
			ZEPHIR_CALL_METHOD(NULL, app, "setdefaultmodule", NULL, 0, _8);
			zephir_check_call_status();
		}
	} else {
		ZEPHIR_INIT_LNVAR(_9);
		ZEPHIR_CONCAT_VS(_9, configPath, "modules.php");
		if ((zephir_file_exists(_9 TSRMLS_CC) == SUCCESS)) {
			ZEPHIR_INIT_LNVAR(_10);
			ZEPHIR_CONCAT_VS(_10, configPath, "modules.php");
			if (zephir_require_zval(_10 TSRMLS_CC) == FAILURE) {
				RETURN_MM_NULL();
			}
		}
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * application:afterStartModule event callback
 *
 * The active Module object will be set as the "primary" module with the module manager (DI key: "moduleManager").
 *
 * * The default dispatch namespace will be set on the dispatcher (DI key: "dispatcher") using the module's
 *   `getControllerNamespace()` method.
 * * Finally the module receives the Application and its `onLoad()` method is called.
 */
PHP_METHOD(Phalconry_Mvc_Application_Bootstrapper, afterStartModule) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *event, *app, *module, *di = NULL, *moduleManager = NULL, *globalEvents = NULL, *dispatcher = NULL, *view = NULL, *_0 = NULL, *_1 = NULL, *_2 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &event, &app, &module);



	ZEPHIR_CALL_METHOD(&di, app, "getdi", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_0);
	ZVAL_STRING(_0, "moduleManager", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&moduleManager, di, "getshared", NULL, 0, _0);
	zephir_check_temp_parameter(_0);
	zephir_check_call_status();
	if (Z_TYPE_P(moduleManager) == IS_OBJECT) {
		ZEPHIR_INIT_NVAR(_0);
		ZVAL_STRING(_0, "dispatcher", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&dispatcher, di, "getshared", NULL, 0, _0);
		zephir_check_temp_parameter(_0);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(_0);
		ZVAL_STRING(_0, "events", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&globalEvents, di, "getshared", NULL, 0, _0);
		zephir_check_temp_parameter(_0);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(_0);
		ZVAL_STRING(_0, "view", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&view, di, "getshared", NULL, 0, _0);
		zephir_check_temp_parameter(_0);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&_1, moduleManager, "getname", NULL, 0, module);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, module, "setname", NULL, 0, _1);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, moduleManager, "setprimary", NULL, 0, module);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, module, "setapp", NULL, 0, app);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&_2, module, "getcontrollernamespace", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, dispatcher, "setdefaultnamespace", NULL, 0, _2);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, dispatcher, "seteventsmanager", NULL, 0, globalEvents);
		zephir_check_call_status();
		if (Z_TYPE_P(view) == IS_OBJECT) {
			ZEPHIR_CALL_METHOD(NULL, view, "seteventsmanager", NULL, 0, globalEvents);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(_0);
			ZVAL_STRING(_0, "view", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(NULL, globalEvents, "attach", NULL, 0, _0, module);
			zephir_check_temp_parameter(_0);
			zephir_check_call_status();
		}
		ZEPHIR_CALL_METHOD(NULL, module, "onload", NULL, 0);
		zephir_check_call_status();
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * application:afterHandleRequest event callback
 *
 * The view is retrieved from the DI (key: "view").
 *
 * If "view" == response type, as given by the responder (DI key: "responder"), the `onView()` method
 * is called on the primary module.
 *
 * If the response type is not "view", the view component is disabled (via View::disable()).
 */
PHP_METHOD(Phalconry_Mvc_Application_Bootstrapper, afterHandleRequest) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *event, *app, *controller, *di = NULL, *view = NULL, *moduleManager = NULL, *responder = NULL, *_0 = NULL, *_1 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &event, &app, &controller);



	ZEPHIR_CALL_METHOD(&di, app, "getdi", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_0);
	ZVAL_STRING(_0, "view", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&view, di, "getshared", NULL, 0, _0);
	zephir_check_temp_parameter(_0);
	zephir_check_call_status();
	if (Z_TYPE_P(view) == IS_OBJECT) {
		ZEPHIR_INIT_NVAR(_0);
		ZVAL_STRING(_0, "moduleManager", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&moduleManager, di, "getshared", NULL, 0, _0);
		zephir_check_temp_parameter(_0);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(_0);
		ZVAL_STRING(_0, "responder", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&responder, di, "getshared", NULL, 0, _0);
		zephir_check_temp_parameter(_0);
		zephir_check_call_status();
		if (Z_TYPE_P(moduleManager) == IS_OBJECT) {
			ZEPHIR_CALL_METHOD(&_1, moduleManager, "getprimary", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(NULL, _1, "onview", NULL, 0, view);
			zephir_check_call_status();
		}
		if (Z_TYPE_P(responder) == IS_OBJECT) {
			ZEPHIR_INIT_NVAR(_0);
			ZVAL_STRING(_0, "view", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(&_1, responder, "istype", NULL, 0, _0);
			zephir_check_temp_parameter(_0);
			zephir_check_call_status();
			if (!(zephir_is_true(_1))) {
				ZEPHIR_CALL_METHOD(NULL, view, "disable", NULL, 0);
				zephir_check_call_status();
			}
		}
	}
	ZEPHIR_MM_RESTORE();

}

