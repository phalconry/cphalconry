
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
#include "kernel/fcall.h"
#include "kernel/memory.h"
#include "kernel/file.h"
#include "kernel/concat.h"
#include "kernel/require.h"
#include "kernel/hash.h"
#include "kernel/array.h"
#include "kernel/operators.h"


ZEPHIR_INIT_CLASS(Phalconry_Mvc_Application_Bootstrap) {

	ZEPHIR_REGISTER_CLASS(Phalconry\\Mvc\\Application, Bootstrap, phalconry, mvc_application_bootstrap, phalconry_mvc_application_bootstrap_method_entry, 0);

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
 * * If no "loader" argument is set, the file "loader.php" in directory "config" MUST exist, as it will be
 * "require"-ed.
 *
 * * Application::setDefaultServices() is called, passing the DI as the only argument.
 *
 * * If "modules" (array) argument exists, they are registered and autoloaded. Otherwise, the file "modules.php" in
 * directory "config" MUST exist and will be "require"-ed.
 *
 * * If a "default_module" (string) argument exists, it will be used to set the default module
 * (via Application::setDefaultModule())
 */
PHP_METHOD(Phalconry_Mvc_Application_Bootstrap, boot) {

	HashTable *_17;
	HashPosition _16;
	zval *_4 = NULL, *_6 = NULL, *_7 = NULL, *_9 = NULL, *_12 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *event, *app, *nothing = NULL, *di = NULL, *env = NULL, *loader, *configPath = NULL, *loaderArgs, *_0 = NULL, *_1 = NULL, *_2 = NULL, *_3 = NULL, *_5, *_8 = NULL, *_10 = NULL, *_11 = NULL, *_13 = NULL, *_14 = NULL, *_15 = NULL, *modules = NULL, *modArgs = NULL, *moduleClasses, **_18, *_19, *_20 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &event, &app, &nothing);

	ZEPHIR_SEPARATE_PARAM(app);
	if (!nothing) {
		nothing = ZEPHIR_GLOBAL(global_null);
	}


	if (!(zephir_instance_of_ev(event, zephir_get_internal_ce(SS("phalcon\\events\\event") TSRMLS_CC) TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "Parameter 'event' must be an instance of 'Phalcon\\Events\\Event'", "", 0);
		return;
	}
	if (!(zephir_instance_of_ev(app, phalconry_mvc_application_ce TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "Parameter 'app' must be an instance of 'Phalconry\\Mvc\\Application'", "", 0);
		return;
	}
	ZEPHIR_CALL_METHOD(&di, app, "getdi", NULL);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_0);
	ZVAL_STRING(_0, "env", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&env, di, "getshared", NULL, _0);
	zephir_check_temp_parameter(_0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(loader);
	object_init_ex(loader, zephir_get_internal_ce(SS("phalcon\\loader") TSRMLS_CC));
	ZEPHIR_CALL_METHOD(NULL, loader, "__construct", NULL);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(_0);
	ZVAL_STRING(_0, "config", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&configPath, env, "getpath", NULL, _0);
	zephir_check_temp_parameter(_0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, loader, "register", NULL);
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
	ZEPHIR_INIT_VAR(_4);
	ZEPHIR_INIT_NVAR(_4);
	ZVAL_STRING(_4, "loader", 1);
	ZEPHIR_OBS_VAR(_5);
	zephir_read_property_zval(&_5, env, _4, PH_NOISY_CC);
	if (Z_TYPE_P(_5) == IS_OBJECT) {
		ZEPHIR_INIT_VAR(_6);
		ZEPHIR_INIT_NVAR(_6);
		ZVAL_STRING(_6, "loader", 1);
		ZEPHIR_OBS_VAR(loaderArgs);
		zephir_read_property_zval(&loaderArgs, env, _6, PH_NOISY_CC);
		ZEPHIR_INIT_VAR(_7);
		ZEPHIR_INIT_NVAR(_7);
		ZVAL_STRING(_7, "namespaces", 1);
		ZEPHIR_OBS_VAR(_8);
		zephir_read_property_zval(&_8, loaderArgs, _7, PH_NOISY_CC);
		if (Z_TYPE_P(_8) == IS_OBJECT) {
			ZEPHIR_INIT_VAR(_9);
			ZEPHIR_INIT_NVAR(_9);
			ZVAL_STRING(_9, "namespaces", 1);
			ZEPHIR_OBS_VAR(_10);
			zephir_read_property_zval(&_10, loaderArgs, _9, PH_NOISY_CC);
			ZEPHIR_CALL_METHOD(&_11, _10, "toarray", NULL);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(NULL, loader, "registernamespaces", NULL, _11);
			zephir_check_call_status();
		}
		ZEPHIR_INIT_NVAR(_9);
		ZEPHIR_INIT_NVAR(_9);
		ZVAL_STRING(_9, "dirs", 1);
		ZEPHIR_OBS_NVAR(_10);
		zephir_read_property_zval(&_10, loaderArgs, _9, PH_NOISY_CC);
		if (Z_TYPE_P(_10) == IS_OBJECT) {
			ZEPHIR_INIT_VAR(_12);
			ZEPHIR_INIT_NVAR(_12);
			ZVAL_STRING(_12, "dirs", 1);
			ZEPHIR_OBS_VAR(_13);
			zephir_read_property_zval(&_13, loaderArgs, _12, PH_NOISY_CC);
			ZEPHIR_CALL_METHOD(&_11, _13, "toarray", NULL);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(NULL, loader, "registerdirs", NULL, _11);
			zephir_check_call_status();
		}
		ZEPHIR_INIT_NVAR(_9);
		ZEPHIR_INIT_NVAR(_9);
		ZVAL_STRING(_9, "classes", 1);
		ZEPHIR_OBS_NVAR(_10);
		zephir_read_property_zval(&_10, loaderArgs, _9, PH_NOISY_CC);
		if (Z_TYPE_P(_10) == IS_OBJECT) {
			ZEPHIR_INIT_NVAR(_12);
			ZEPHIR_INIT_NVAR(_12);
			ZVAL_STRING(_12, "classes", 1);
			ZEPHIR_OBS_NVAR(_13);
			zephir_read_property_zval(&_13, loaderArgs, _12, PH_NOISY_CC);
			ZEPHIR_CALL_METHOD(&_11, _13, "toarray", NULL);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(NULL, loader, "registerclasses", NULL, _11);
			zephir_check_call_status();
		}
	} else {
		ZEPHIR_INIT_VAR(_14);
		ZEPHIR_CONCAT_VS(_14, configPath, "loader.php");
		if ((zephir_file_exists(_14 TSRMLS_CC) == SUCCESS)) {
			ZEPHIR_INIT_VAR(_15);
			ZEPHIR_CONCAT_VS(_15, configPath, "loader.php");
			if (zephir_require_zval(_15 TSRMLS_CC) == FAILURE) {
				RETURN_MM_NULL();
			}
		}
	}
	ZEPHIR_CALL_METHOD(NULL, app, "setdefaultservices", NULL, di);
	zephir_check_call_status();
	ZEPHIR_INIT_LNVAR(_14);
	ZEPHIR_CONCAT_VS(_14, configPath, "services.php");
	if ((zephir_file_exists(_14 TSRMLS_CC) == SUCCESS)) {
		ZEPHIR_INIT_LNVAR(_15);
		ZEPHIR_CONCAT_VS(_15, configPath, "services.php");
		if (zephir_require_zval(_15 TSRMLS_CC) == FAILURE) {
			RETURN_MM_NULL();
		}
	}
	ZEPHIR_INIT_NVAR(_6);
	ZEPHIR_INIT_NVAR(_6);
	ZVAL_STRING(_6, "modules", 1);
	ZEPHIR_OBS_NVAR(_8);
	zephir_read_property_zval(&_8, env, _6, PH_NOISY_CC);
	if (Z_TYPE_P(_8) == IS_OBJECT) {
		ZEPHIR_INIT_NVAR(_7);
		ZEPHIR_INIT_NVAR(_7);
		ZVAL_STRING(_7, "modules", 1);
		ZEPHIR_OBS_NVAR(_10);
		zephir_read_property_zval(&_10, env, _7, PH_NOISY_CC);
		ZEPHIR_CALL_METHOD(&modules, _10, "toarray", NULL);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(moduleClasses);
		array_init(moduleClasses);
		ZEPHIR_INIT_NVAR(_0);
		ZVAL_BOOL(_0, 0);
		ZEPHIR_CALL_METHOD(NULL, app, "registermodules", NULL, modules, _0);
		zephir_check_call_status();
		zephir_is_iterable(modules, &_17, &_16, 0, 0, "phalconry/mvc/application/bootstrap.zep", 96);
		for (
		  ; zephir_hash_get_current_data_ex(_17, (void**) &_18, &_16) == SUCCESS
		  ; zephir_hash_move_forward_ex(_17, &_16)
		) {
			ZEPHIR_GET_HVALUE(modArgs, _18);
			if (zephir_array_isset_string(modArgs, SS("className"))) {
				if (zephir_array_isset_string(modArgs, SS("path"))) {
					zephir_array_fetch_string(&_19, modArgs, SL("path"), PH_NOISY | PH_READONLY, "phalconry/mvc/application/bootstrap.zep", 91 TSRMLS_CC);
					ZEPHIR_OBS_NVAR(_13);
					zephir_array_fetch_string(&_13, modArgs, SL("className"), PH_NOISY, "phalconry/mvc/application/bootstrap.zep", 91 TSRMLS_CC);
					zephir_array_update_zval(&moduleClasses, _13, &_19, PH_COPY | PH_SEPARATE);
				}
			}
		}
		if (!(ZEPHIR_IS_EMPTY(moduleClasses))) {
			ZEPHIR_CALL_METHOD(NULL, loader, "registerclasses", NULL, moduleClasses);
			zephir_check_call_status();
		}
		ZEPHIR_INIT_NVAR(_9);
		ZEPHIR_INIT_NVAR(_9);
		ZVAL_STRING(_9, "default_module", 1);
		ZEPHIR_OBS_NVAR(_10);
		zephir_read_property_zval(&_10, env, _9, PH_NOISY_CC);
		if (Z_TYPE_P(_10) == IS_STRING) {
			ZEPHIR_INIT_NVAR(_12);
			ZEPHIR_INIT_NVAR(_12);
			ZVAL_STRING(_12, "default_module", 1);
			ZEPHIR_OBS_NVAR(_13);
			zephir_read_property_zval(&_13, env, _12, PH_NOISY_CC);
			ZEPHIR_CALL_METHOD(NULL, app, "setdefaultmodule", NULL, _13);
			zephir_check_call_status();
		}
	} else {
		ZEPHIR_INIT_LNVAR(_14);
		ZEPHIR_CONCAT_VS(_14, configPath, "modules.php");
		if ((zephir_file_exists(_14 TSRMLS_CC) == SUCCESS)) {
			ZEPHIR_INIT_LNVAR(_15);
			ZEPHIR_CONCAT_VS(_15, configPath, "modules.php");
			if (zephir_require_zval(_15 TSRMLS_CC) == FAILURE) {
				RETURN_MM_NULL();
			}
		}
	}
	ZEPHIR_INIT_NVAR(_6);
	ZEPHIR_INIT_NVAR(_6);
	ZVAL_STRING(_6, "session", 1);
	ZEPHIR_OBS_NVAR(_8);
	zephir_read_property_zval(&_8, env, _6, PH_NOISY_CC);
	if (Z_TYPE_P(_8) == IS_OBJECT) {
		ZEPHIR_INIT_NVAR(_7);
		ZEPHIR_INIT_NVAR(_7);
		ZVAL_STRING(_7, "session", 1);
		ZEPHIR_OBS_NVAR(_10);
		zephir_read_property_zval(&_10, env, _7, PH_NOISY_CC);
		ZEPHIR_INIT_NVAR(_0);
		ZVAL_STRING(_0, "auto_start", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&_11, _10, "get", NULL, _0);
		zephir_check_temp_parameter(_0);
		zephir_check_call_status();
		if (zephir_is_true(_11)) {
			ZEPHIR_INIT_NVAR(_0);
			ZVAL_STRING(_0, "session", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(&_20, di, "getshared", NULL, _0);
			zephir_check_temp_parameter(_0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(NULL, _20, "start", NULL);
			zephir_check_call_status();
		}
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * application:afterStartModule event callback
 *
 * The active Module object will be set as the "primary" module with the module manager (DI key: "moduleManager").
 *
 * * The default "dispatch" namespace will be set on the dispatcher (DI key: "dispatcher")
 * using the module's `getControllerNamespace()` method.
 * * Finally the module receives the Application and its `onLoad()` method is called.
 */
PHP_METHOD(Phalconry_Mvc_Application_Bootstrap, afterStartModule) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *event, *app, *module, *di = NULL, *moduleManager = NULL, *viewEvents = NULL, *_0 = NULL, *_1 = NULL, *_2 = NULL, *_3 = NULL, *_4 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &event, &app, &module);



	if (!(zephir_instance_of_ev(event, zephir_get_internal_ce(SS("phalcon\\events\\event") TSRMLS_CC) TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "Parameter 'event' must be an instance of 'Phalcon\\Events\\Event'", "", 0);
		return;
	}
	if (!(zephir_instance_of_ev(app, phalconry_mvc_application_ce TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "Parameter 'app' must be an instance of 'Phalconry\\Mvc\\Application'", "", 0);
		return;
	}
	if (!(zephir_instance_of_ev(module, phalconry_mvc_module_ce TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "Parameter 'module' must be an instance of 'Phalconry\\Mvc\\Module'", "", 0);
		return;
	}
	ZEPHIR_CALL_METHOD(&di, app, "getdi", NULL);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_0);
	ZVAL_STRING(_0, "moduleManager", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&moduleManager, di, "getshared", NULL, _0);
	zephir_check_temp_parameter(_0);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(_0);
	ZVAL_STRING(_0, "viewEvents", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&viewEvents, di, "getshared", NULL, _0);
	zephir_check_temp_parameter(_0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_1, moduleManager, "getname", NULL, module);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, module, "setname", NULL, _1);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, moduleManager, "setprimary", NULL, module);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, module, "setapp", NULL, app);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(_0);
	ZVAL_STRING(_0, "dispatcher", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&_2, di, "getshared", NULL, _0);
	zephir_check_temp_parameter(_0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_3, module, "getcontrollernamespace", NULL);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, _2, "setdefaultnamespace", NULL, _3);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(_0);
	ZVAL_STRING(_0, "view", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&_4, di, "getshared", NULL, _0);
	zephir_check_temp_parameter(_0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, _4, "seteventsmanager", NULL, viewEvents);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(_0);
	ZVAL_STRING(_0, "view", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(NULL, viewEvents, "attach", NULL, _0, module);
	zephir_check_temp_parameter(_0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, module, "onload", NULL);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * application:afterHandleRequest event callback
 *
 * The view is retrieved from the DI (key: "view").
 *
 * If "view" == response type, as given by the responder (DI key: "responder"), the `onView()` method
 * is called on the "primary" module.
 *
 * If the response type is not "view", the view component is disabled (via View::disable()).
 */
PHP_METHOD(Phalconry_Mvc_Application_Bootstrap, afterHandleRequest) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *event, *app, *controller, *di = NULL, *view = NULL, *_0 = NULL, *_1 = NULL, *_2 = NULL, *_3 = NULL, *_4 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &event, &app, &controller);



	if (!(zephir_instance_of_ev(event, zephir_get_internal_ce(SS("phalcon\\events\\event") TSRMLS_CC) TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "Parameter 'event' must be an instance of 'Phalcon\\Events\\Event'", "", 0);
		return;
	}
	if (!(zephir_instance_of_ev(app, phalconry_mvc_application_ce TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "Parameter 'app' must be an instance of 'Phalconry\\Mvc\\Application'", "", 0);
		return;
	}
	ZEPHIR_CALL_METHOD(&di, app, "getdi", NULL);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_0);
	ZVAL_STRING(_0, "view", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&view, di, "getshared", NULL, _0);
	zephir_check_temp_parameter(_0);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(_0);
	ZVAL_STRING(_0, "moduleManager", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&_1, di, "getshared", NULL, _0);
	zephir_check_temp_parameter(_0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_2, _1, "getprimary", NULL);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, _2, "onview", NULL, view);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(_0);
	ZVAL_STRING(_0, "responder", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&_3, di, "getshared", NULL, _0);
	zephir_check_temp_parameter(_0);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(_0);
	ZVAL_STRING(_0, "view", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&_4, _3, "istype", NULL, _0);
	zephir_check_temp_parameter(_0);
	zephir_check_call_status();
	if (!(zephir_is_true(_4))) {
		ZEPHIR_CALL_METHOD(NULL, view, "disable", NULL);
		zephir_check_call_status();
	}
	ZEPHIR_MM_RESTORE();

}

