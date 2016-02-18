
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
#include "kernel/operators.h"
#include "kernel/concat.h"
#include "kernel/file.h"
#include "kernel/require.h"
#include "kernel/object.h"
#include "kernel/hash.h"
#include "kernel/array.h"


ZEPHIR_INIT_CLASS(Phalconry_Mvc_Application_Bootstrap) {

	ZEPHIR_REGISTER_CLASS(Phalconry\\Mvc\\Application, Bootstrap, phalconry, mvc_application_bootstrap, phalconry_mvc_application_bootstrap_method_entry, 0);

	/**
	 * @var \Phalcon\Loader
	 */
	zend_declare_property_null(phalconry_mvc_application_bootstrap_ce, SL("loader"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_class_implements(phalconry_mvc_application_bootstrap_ce TSRMLS_CC, 1, phalconry_mvc_application_bootstrapinterface_ce);
	return SUCCESS;

}

/**
 * Boots the application.
 *
 * @param \Phalconry\Mvc\ApplicationInterface app
 * @return void
 */
PHP_METHOD(Phalconry_Mvc_Application_Bootstrap, boot) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *app, *dependencyInjector = NULL, *loader, *cfgPath = NULL, *loaderFile, *servicesFile, *modulesFile, *_0 = NULL, *_1 = NULL, *_2 = NULL, *_3 = NULL, *_4 = NULL, *_5 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &app);

	ZEPHIR_SEPARATE_PARAM(app);


	ZEPHIR_CALL_METHOD(&dependencyInjector, app, "getdi", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(loader);
	object_init_ex(loader, zephir_get_internal_ce(SS("phalcon\\loader") TSRMLS_CC));
	ZEPHIR_CALL_METHOD(NULL, loader, "__construct", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, loader, "register", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "registerloader", NULL, 0, dependencyInjector, app, loader);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "registerservices", NULL, 0, dependencyInjector, app, loader);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "registermodules", NULL, 0, dependencyInjector, app, loader);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_1);
	ZVAL_STRING(_1, "env", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&_0, dependencyInjector, "getshared", NULL, 0, _1);
	zephir_check_temp_parameter(_1);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "config", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&cfgPath, _0, "getpath", NULL, 0, _1);
	zephir_check_temp_parameter(_1);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&_2, "is_dir", NULL, 53, cfgPath);
	zephir_check_call_status();
	if (zephir_is_true(_2)) {
		ZEPHIR_INIT_VAR(loaderFile);
		ZEPHIR_CONCAT_VS(loaderFile, cfgPath, "loader.php");
		ZEPHIR_INIT_VAR(servicesFile);
		ZEPHIR_CONCAT_VS(servicesFile, cfgPath, "services.php");
		ZEPHIR_INIT_VAR(modulesFile);
		ZEPHIR_CONCAT_VS(modulesFile, cfgPath, "modules.php");
		ZEPHIR_CPY_WRT(_3, dependencyInjector);
		if (zephir_set_symbol_str(SS("di"), _3 TSRMLS_CC) == FAILURE){
		  return;
		}
		ZEPHIR_CPY_WRT(_4, app);
		if (zephir_set_symbol_str(SS("app"), _4 TSRMLS_CC) == FAILURE){
		  return;
		}
		ZEPHIR_CPY_WRT(_5, loader);
		if (zephir_set_symbol_str(SS("loader"), _5 TSRMLS_CC) == FAILURE){
		  return;
		}
		if ((zephir_file_exists(loaderFile TSRMLS_CC) == SUCCESS)) {
			if (zephir_require_zval(loaderFile TSRMLS_CC) == FAILURE) {
				RETURN_MM_NULL();
			}
		}
		if ((zephir_file_exists(servicesFile TSRMLS_CC) == SUCCESS)) {
			if (zephir_require_zval(servicesFile TSRMLS_CC) == FAILURE) {
				RETURN_MM_NULL();
			}
		}
		if ((zephir_file_exists(modulesFile TSRMLS_CC) == SUCCESS)) {
			if (zephir_require_zval(modulesFile TSRMLS_CC) == FAILURE) {
				RETURN_MM_NULL();
			}
		}
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Configure loader
 */
PHP_METHOD(Phalconry_Mvc_Application_Bootstrap, registerLoader) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *di, *app, *loader, *args = NULL, *_0, *_1, *_2 = NULL, *_3 = NULL, *_4 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &di, &app, &loader);



	ZEPHIR_INIT_VAR(_0);
	ZVAL_STRING(_0, "loader", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&args, app, "env", NULL, 0, _0);
	zephir_check_temp_parameter(_0);
	zephir_check_call_status();
	if (Z_TYPE_P(args) != IS_OBJECT) {
		RETURN_MM_BOOL(0);
	}
	ZEPHIR_OBS_VAR(_1);
	zephir_read_property(&_1, args, SL("namespaces"), PH_NOISY_CC);
	if (Z_TYPE_P(_1) == IS_OBJECT) {
		ZEPHIR_OBS_VAR(_2);
		zephir_read_property(&_2, args, SL("namespaces"), PH_NOISY_CC);
		ZEPHIR_CALL_METHOD(&_3, _2, "toarray", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, loader, "registernamespaces", NULL, 0, _3);
		zephir_check_call_status();
	}
	ZEPHIR_OBS_NVAR(_2);
	zephir_read_property(&_2, args, SL("dirs"), PH_NOISY_CC);
	if (Z_TYPE_P(_2) == IS_OBJECT) {
		ZEPHIR_OBS_VAR(_4);
		zephir_read_property(&_4, args, SL("dirs"), PH_NOISY_CC);
		ZEPHIR_CALL_METHOD(&_3, _4, "toarray", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, loader, "registerdirs", NULL, 0, _3);
		zephir_check_call_status();
	}
	ZEPHIR_OBS_NVAR(_2);
	zephir_read_property(&_2, args, SL("classes"), PH_NOISY_CC);
	if (Z_TYPE_P(_2) == IS_OBJECT) {
		ZEPHIR_OBS_NVAR(_4);
		zephir_read_property(&_4, args, SL("classes"), PH_NOISY_CC);
		ZEPHIR_CALL_METHOD(&_3, _4, "toarray", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, loader, "registerclasses", NULL, 0, _3);
		zephir_check_call_status();
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Configure services
 */
PHP_METHOD(Phalconry_Mvc_Application_Bootstrap, registerServices) {

	zephir_fcall_cache_entry *_3 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *di, *app, *loader, *_0 = NULL, *_1 = NULL, *_2 = NULL, *_4 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &di, &app, &loader);



	ZEPHIR_INIT_VAR(_1);
	ZVAL_STRING(_1, "events", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&_0, di, "has", NULL, 0, _1);
	zephir_check_temp_parameter(_1);
	zephir_check_call_status();
	if (!(zephir_is_true(_0))) {
		ZEPHIR_CALL_CE_STATIC(&_2, phalconry_events_globalmanager_ce, "create", &_3, 54);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(_1);
		ZVAL_STRING(_1, "events", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(NULL, di, "setshared", NULL, 0, _1, _2);
		zephir_check_temp_parameter(_1);
		zephir_check_call_status();
	}
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "view", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&_2, di, "has", NULL, 0, _1);
	zephir_check_temp_parameter(_1);
	zephir_check_call_status();
	if (!(zephir_is_true(_2))) {
		ZEPHIR_INIT_NVAR(_1);
		ZVAL_STRING(_1, "view", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_INIT_VAR(_4);
		ZVAL_STRING(_4, "Phalcon\\Mvc\\View", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(NULL, di, "setshared", NULL, 0, _1, _4);
		zephir_check_temp_parameter(_1);
		zephir_check_temp_parameter(_4);
		zephir_check_call_status();
	}
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "moduleManager", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&_2, di, "has", NULL, 0, _1);
	zephir_check_temp_parameter(_1);
	zephir_check_call_status();
	if (!(zephir_is_true(_2))) {
		ZEPHIR_INIT_NVAR(_1);
		ZVAL_STRING(_1, "moduleManager", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_INIT_NVAR(_4);
		ZVAL_STRING(_4, "Phalconry\\Mvc\\Module\\Manager", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(NULL, di, "setshared", NULL, 0, _1, _4);
		zephir_check_temp_parameter(_1);
		zephir_check_temp_parameter(_4);
		zephir_check_call_status();
	}
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "responder", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&_2, di, "has", NULL, 0, _1);
	zephir_check_temp_parameter(_1);
	zephir_check_call_status();
	if (!(zephir_is_true(_2))) {
		ZEPHIR_INIT_NVAR(_1);
		ZVAL_STRING(_1, "responder", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_INIT_NVAR(_4);
		ZVAL_STRING(_4, "Phalconry\\Mvc\\Responder", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(NULL, di, "setshared", NULL, 0, _1, _4);
		zephir_check_temp_parameter(_1);
		zephir_check_temp_parameter(_4);
		zephir_check_call_status();
	}
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "hmvcRequest", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&_2, di, "has", NULL, 0, _1);
	zephir_check_temp_parameter(_1);
	zephir_check_call_status();
	if (!(zephir_is_true(_2))) {
		ZEPHIR_INIT_NVAR(_1);
		ZVAL_STRING(_1, "hmvcRequest", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_INIT_NVAR(_4);
		ZVAL_STRING(_4, "Phalconry\\Mvc\\Hmvc\\Request", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(NULL, di, "setshared", NULL, 0, _1, _4);
		zephir_check_temp_parameter(_1);
		zephir_check_temp_parameter(_4);
		zephir_check_call_status();
	}
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "httpClient", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&_2, di, "has", NULL, 0, _1);
	zephir_check_temp_parameter(_1);
	zephir_check_call_status();
	if (!(zephir_is_true(_2))) {
		ZEPHIR_INIT_NVAR(_1);
		ZVAL_STRING(_1, "httpClient", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_INIT_NVAR(_4);
		ZVAL_STRING(_4, "Phalconry\\Http\\Client", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(NULL, di, "setshared", NULL, 0, _1, _4);
		zephir_check_temp_parameter(_1);
		zephir_check_temp_parameter(_4);
		zephir_check_call_status();
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Configure modules
 */
PHP_METHOD(Phalconry_Mvc_Application_Bootstrap, registerModules) {

	HashTable *_3;
	HashPosition _2;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *di, *app, *loader, *modules = NULL, *_0 = NULL, *moduleManager = NULL, *modulesArray = NULL, *modArgs = NULL, *moduleClasses, *defaultModule = NULL, *_1 = NULL, **_4, *modClassName = NULL, *modPath = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &di, &app, &loader);



	ZEPHIR_INIT_VAR(_0);
	ZVAL_STRING(_0, "modules", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&modules, app, "env", NULL, 0, _0);
	zephir_check_temp_parameter(_0);
	zephir_check_call_status();
	if (Z_TYPE_P(modules) == IS_OBJECT) {
		ZEPHIR_CALL_METHOD(&_1, app, "getdi", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(_0);
		ZVAL_STRING(_0, "moduleManager", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&moduleManager, _1, "getshared", NULL, 0, _0);
		zephir_check_temp_parameter(_0);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&modulesArray, modules, "toarray", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(moduleClasses);
		array_init(moduleClasses);
		ZEPHIR_CALL_METHOD(NULL, moduleManager, "registermodules", NULL, 0, modulesArray);
		zephir_check_call_status();
		zephir_is_iterable(modulesArray, &_3, &_2, 0, 0, "phalconry/mvc/application/bootstrap.zep", 143);
		for (
		  ; zephir_hash_get_current_data_ex(_3, (void**) &_4, &_2) == SUCCESS
		  ; zephir_hash_move_forward_ex(_3, &_2)
		) {
			ZEPHIR_GET_HVALUE(modArgs, _4);
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
		ZEPHIR_INIT_NVAR(_0);
		ZVAL_STRING(_0, "default_module", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&defaultModule, app, "env", NULL, 0, _0);
		zephir_check_temp_parameter(_0);
		zephir_check_call_status();
		if (Z_TYPE_P(defaultModule) == IS_STRING) {
			ZEPHIR_CALL_METHOD(NULL, moduleManager, "setdefaultmodulename", NULL, 0, defaultModule);
			zephir_check_call_status();
		}
	}
	ZEPHIR_MM_RESTORE();

}

