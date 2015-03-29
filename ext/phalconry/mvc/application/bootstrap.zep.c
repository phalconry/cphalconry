
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
 */
PHP_METHOD(Phalconry_Mvc_Application_Bootstrap, boot) {

	HashTable *_12;
	HashPosition _11;
	zval *_6 = NULL, *_7 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *event, *app, *nothing = NULL, *env = NULL, *loader, *configPath = NULL, *_0 = NULL, *_1 = NULL, *_2 = NULL, *_3 = NULL, *_4 = NULL, *_5 = NULL, *args, *_8 = NULL, *_9 = NULL, *_10 = NULL, *modules = NULL, *moduleArgs = NULL, *moduleClasses, **_13, *_14, *_15 = NULL;

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
	ZEPHIR_CALL_METHOD(&_0, app, "getdi", NULL);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_1);
	ZVAL_STRING(_1, "env", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&env, _0, "getshared", NULL, _1);
	zephir_check_temp_parameter(_1);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(loader);
	object_init_ex(loader, zephir_get_internal_ce(SS("phalcon\\loader") TSRMLS_CC));
	ZEPHIR_CALL_METHOD(NULL, loader, "__construct", NULL);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "config", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&configPath, env, "getpath", NULL, _1);
	zephir_check_temp_parameter(_1);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, loader, "register", NULL);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(_2, app);
	if (zephir_set_symbol_str(SS("app"), _2 TSRMLS_CC) == FAILURE){
	  return;
	}
	ZEPHIR_CALL_METHOD(&_3, app, "getdi", NULL);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(_4, _3);
	if (zephir_set_symbol_str(SS("di"), _4 TSRMLS_CC) == FAILURE){
	  return;
	}
	ZEPHIR_CPY_WRT(_5, loader);
	if (zephir_set_symbol_str(SS("loader"), _5 TSRMLS_CC) == FAILURE){
	  return;
	}
	if ((0 == 0)) {
		ZEPHIR_INIT_VAR(_6);
		ZEPHIR_INIT_NVAR(_6);
		ZVAL_STRING(_6, "loader", 1);
		ZEPHIR_OBS_VAR(args);
		zephir_read_property_zval(&args, env, _6, PH_NOISY_CC);
		if ((0 == 0)) {
			ZEPHIR_INIT_VAR(_7);
			ZEPHIR_INIT_NVAR(_7);
			ZVAL_STRING(_7, "namespaces", 1);
			ZEPHIR_OBS_VAR(_8);
			zephir_read_property_zval(&_8, args, _7, PH_NOISY_CC);
			ZEPHIR_CALL_METHOD(&_3, _8, "toarray", NULL);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(NULL, loader, "registernamespaces", NULL, _3);
			zephir_check_call_status();
		}
		if ((0 == 0)) {
			ZEPHIR_INIT_NVAR(_7);
			ZEPHIR_INIT_NVAR(_7);
			ZVAL_STRING(_7, "dirs", 1);
			ZEPHIR_OBS_NVAR(_8);
			zephir_read_property_zval(&_8, args, _7, PH_NOISY_CC);
			ZEPHIR_CALL_METHOD(&_9, _8, "toarray", NULL);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(NULL, loader, "registerdirs", NULL, _9);
			zephir_check_call_status();
		}
		if ((0 == 0)) {
			ZEPHIR_INIT_NVAR(_7);
			ZEPHIR_INIT_NVAR(_7);
			ZVAL_STRING(_7, "classes", 1);
			ZEPHIR_OBS_NVAR(_8);
			zephir_read_property_zval(&_8, args, _7, PH_NOISY_CC);
			ZEPHIR_CALL_METHOD(&_9, _8, "toarray", NULL);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(NULL, loader, "registerclasses", NULL, _9);
			zephir_check_call_status();
		}
	} else {
		ZEPHIR_INIT_VAR(_10);
		ZEPHIR_CONCAT_VS(_10, configPath, "loader.php");
		if (zephir_require_zval(_10 TSRMLS_CC) == FAILURE) {
			RETURN_MM_NULL();
		}
	}
	ZEPHIR_CALL_METHOD(&_9, app, "getdi", NULL);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, app, "setdefaultservices", NULL, _9);
	zephir_check_call_status();
	ZEPHIR_INIT_LNVAR(_10);
	ZEPHIR_CONCAT_VS(_10, configPath, "services.php");
	if (zephir_require_zval(_10 TSRMLS_CC) == FAILURE) {
		RETURN_MM_NULL();
	}
	if ((0 == 0)) {
		ZEPHIR_INIT_NVAR(_6);
		ZEPHIR_INIT_NVAR(_6);
		ZVAL_STRING(_6, "modules", 1);
		ZEPHIR_OBS_NVAR(_8);
		zephir_read_property_zval(&_8, env, _6, PH_NOISY_CC);
		ZEPHIR_CALL_METHOD(&modules, _8, "toarray", NULL);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(moduleClasses);
		array_init(moduleClasses);
		ZEPHIR_INIT_NVAR(_1);
		ZVAL_BOOL(_1, 0);
		ZEPHIR_CALL_METHOD(NULL, app, "registermodules", NULL, modules, _1);
		zephir_check_call_status();
		zephir_is_iterable(modules, &_12, &_11, 0, 0, "phalconry/mvc/application/bootstrap.zep", 75);
		for (
		  ; zephir_hash_get_current_data_ex(_12, (void**) &_13, &_11) == SUCCESS
		  ; zephir_hash_move_forward_ex(_12, &_11)
		) {
			ZEPHIR_GET_HVALUE(moduleArgs, _13);
			if (zephir_array_isset_string(moduleArgs, SS("className"))) {
				if (zephir_array_isset_string(moduleArgs, SS("path"))) {
					zephir_array_fetch_string(&_14, moduleArgs, SL("path"), PH_NOISY | PH_READONLY, "phalconry/mvc/application/bootstrap.zep", 70 TSRMLS_CC);
					ZEPHIR_OBS_NVAR(_15);
					zephir_array_fetch_string(&_15, moduleArgs, SL("className"), PH_NOISY, "phalconry/mvc/application/bootstrap.zep", 70 TSRMLS_CC);
					zephir_array_update_zval(&moduleClasses, _15, &_14, PH_COPY | PH_SEPARATE);
				}
			}
		}
		if (!(ZEPHIR_IS_EMPTY(moduleClasses))) {
			ZEPHIR_CALL_METHOD(NULL, loader, "registerclasses", NULL, moduleClasses);
			zephir_check_call_status();
		}
		if ((0 == 0)) {
			ZEPHIR_INIT_NVAR(_7);
			ZEPHIR_INIT_NVAR(_7);
			ZVAL_STRING(_7, "default_module", 1);
			ZEPHIR_OBS_NVAR(_8);
			zephir_read_property_zval(&_8, env, _7, PH_NOISY_CC);
			ZEPHIR_CALL_METHOD(NULL, app, "setdefaultmodule", NULL, _8);
			zephir_check_call_status();
		}
	} else {
		ZEPHIR_INIT_LNVAR(_10);
		ZEPHIR_CONCAT_VS(_10, configPath, "modules.php");
		if (zephir_require_zval(_10 TSRMLS_CC) == FAILURE) {
			RETURN_MM_NULL();
		}
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * application:afterStartModule event callback
 */
PHP_METHOD(Phalconry_Mvc_Application_Bootstrap, afterStartModule) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *event, *app, *module, *manager = NULL, *_0 = NULL, *_1 = NULL, *_2 = NULL, *_3 = NULL, *_4 = NULL, *_5 = NULL;

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
	ZEPHIR_CALL_METHOD(&_0, app, "getdi", NULL);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_1);
	ZVAL_STRING(_1, "moduleManager", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&manager, _0, "getshared", NULL, _1);
	zephir_check_temp_parameter(_1);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_2, manager, "getname", NULL, module);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, module, "setname", NULL, _2);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, manager, "setprimary", NULL, module);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_3, app, "getdi", NULL);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "dispatcher", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&_4, _3, "getshared", NULL, _1);
	zephir_check_temp_parameter(_1);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_5, module, "getcontrollernamespace", NULL);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, _4, "setdefaultnamespace", NULL, _5);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, module, "setapp", NULL, app);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, module, "onload", NULL);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * application:afterHandleRequest event callback
 */
PHP_METHOD(Phalconry_Mvc_Application_Bootstrap, afterHandleRequest) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *event, *app, *controller, *view = NULL, *_0 = NULL, *_1 = NULL, *_2 = NULL, *_3 = NULL, *_4 = NULL, *_5 = NULL, *_6 = NULL, *_7 = NULL;

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
	ZEPHIR_CALL_METHOD(&_0, app, "getdi", NULL);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_1);
	ZVAL_STRING(_1, "view", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&view, _0, "getshared", NULL, _1);
	zephir_check_temp_parameter(_1);
	zephir_check_call_status();
	if (Z_TYPE_P(view) == IS_OBJECT) {
		ZEPHIR_CALL_METHOD(&_2, app, "getdi", NULL);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(_1);
		ZVAL_STRING(_1, "responder", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&_3, _2, "getshared", NULL, _1);
		zephir_check_temp_parameter(_1);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(_1);
		ZVAL_STRING(_1, "view", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&_4, _3, "istype", NULL, _1);
		zephir_check_temp_parameter(_1);
		zephir_check_call_status();
		if (zephir_is_true(_4)) {
			ZEPHIR_CALL_METHOD(&_5, app, "getdi", NULL);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(_1);
			ZVAL_STRING(_1, "moduleManager", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(&_6, _5, "getshared", NULL, _1);
			zephir_check_temp_parameter(_1);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&_7, _6, "getprimary", NULL);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(NULL, _7, "onview", NULL, view);
			zephir_check_call_status();
		} else {
			ZEPHIR_CALL_METHOD(NULL, view, "disable", NULL);
			zephir_check_call_status();
		}
	}
	ZEPHIR_MM_RESTORE();

}

