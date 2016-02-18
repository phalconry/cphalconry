
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
#include "kernel/string.h"
#include "kernel/file.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/object.h"
#include "kernel/concat.h"
#include "kernel/require.h"


ZEPHIR_INIT_CLASS(Phalconry_Mvc_Plugin) {

	ZEPHIR_REGISTER_CLASS_EX(Phalconry\\Mvc, Plugin, phalconry, mvc_plugin, zephir_get_internal_ce(SS("phalcon\\di\\injectable") TSRMLS_CC), phalconry_mvc_plugin_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	/**
	 * @var string
	 */
	zend_declare_property_null(phalconry_mvc_plugin_ce, SL("_path"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * @var \Phalconry\Mvc\Plugin\Manager
	 */
	zend_declare_property_null(phalconry_mvc_plugin_ce, SL("_manager"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * @var \Phalcon\Config
	 */
	zend_declare_property_null(phalconry_mvc_plugin_ce, SL("_config"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_class_implements(phalconry_mvc_plugin_ce TSRMLS_CC, 1, phalconry_mvc_plugininterface_ce);
	return SUCCESS;

}

/**
 * Returns the plugin's name.
 *
 * @return string
 */
PHP_METHOD(Phalconry_Mvc_Plugin, getName) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *_0, *_1 = NULL;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(_0);
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "getpath", NULL, 0);
	zephir_check_call_status();
	zephir_basename(_0, _1 TSRMLS_CC);
	zephir_fast_strtolower(return_value, _0);
	RETURN_MM();

}

/**
 * Returns the path to the plugin's directory.
 *
 * @return string
 */
PHP_METHOD(Phalconry_Mvc_Plugin, getPath) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *reflection, *_0, *_1, *_2 = NULL, *_3 = NULL;

	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(_0);
	zephir_read_property_this(&_0, this_ptr, SL("_path"), PH_NOISY_CC);
	if (Z_TYPE_P(_0) != IS_STRING) {
		ZEPHIR_INIT_VAR(reflection);
		object_init_ex(reflection, zephir_get_internal_ce(SS("reflectionclass") TSRMLS_CC));
		ZEPHIR_INIT_VAR(_1);
		zephir_get_class(_1, this_ptr, 0 TSRMLS_CC);
		ZEPHIR_CALL_METHOD(NULL, reflection, "__construct", NULL, 63, _1);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&_2, reflection, "getfilename", NULL, 64);
		zephir_check_call_status();
		ZEPHIR_CALL_FUNCTION(&_3, "dirname", NULL, 65, _2);
		zephir_check_call_status();
		zephir_update_property_this(this_ptr, SL("_path"), _3 TSRMLS_CC);
	}
	RETURN_MM_MEMBER(this_ptr, "_path");

}

/**
 * Sets the plugins manager.
 *
 * @param \Phalconry\Mvc\Plugin\ManagerInterface manager
 * @return void
 */
PHP_METHOD(Phalconry_Mvc_Plugin, setManager) {

	zval *manager;

	zephir_fetch_params(0, 1, 0, &manager);



	zephir_update_property_this(this_ptr, SL("_manager"), manager TSRMLS_CC);

}

/**
 * Returns the plugins manager.
 *
 * @return \Phalconry\Mvc\Plugin\ManagerInterface
 */
PHP_METHOD(Phalconry_Mvc_Plugin, getManager) {


	RETURN_MEMBER(this_ptr, "_manager");

}

/**
 * Returns the plugin's Config object.
 *
 * @return \Phalcon\Config|null
 */
PHP_METHOD(Phalconry_Mvc_Plugin, getConfig) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *config = NULL, *filepath, *_0 = NULL, *_1 = NULL;

	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(config);
	zephir_read_property_this(&config, this_ptr, SL("_config"), PH_NOISY_CC);
	if (Z_TYPE_P(config) != IS_OBJECT) {
		ZEPHIR_CALL_METHOD(&_0, this_ptr, "getpath", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(filepath);
		ZEPHIR_CONCAT_VS(filepath, _0, "/config/config.php");
		if ((zephir_file_exists(filepath TSRMLS_CC) == SUCCESS)) {
			ZEPHIR_OBSERVE_OR_NULLIFY_PPZV(&_1);
			if (zephir_require_zval_ret(&_1, filepath TSRMLS_CC) == FAILURE) {
				RETURN_MM_NULL();
			}
			ZEPHIR_CPY_WRT(config, _1);
			zephir_update_property_this(this_ptr, SL("_config"), config TSRMLS_CC);
		}
	}
	RETURN_CCTOR(config);

}

/**
 * Checks whether the plugin is loaded.
 *
 * @return boolean
 */
PHP_METHOD(Phalconry_Mvc_Plugin, isLoaded) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *manager;

	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(manager);
	zephir_read_property_this(&manager, this_ptr, SL("_manager"), PH_NOISY_CC);
	if (Z_TYPE_P(manager) != IS_OBJECT) {
		RETURN_MM_BOOL(0);
	}
	ZEPHIR_RETURN_CALL_METHOD(manager, "isloaded", NULL, 0, this_ptr);
	zephir_check_call_status();
	RETURN_MM();

}

