
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
#include "kernel/concat.h"
#include "kernel/memory.h"
#include "kernel/string.h"
#include "kernel/object.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"
#include "kernel/operators.h"
#include "kernel/fcall.h"
#include "Zend/zend_closures.h"
#include "kernel/array.h"
#include "kernel/file.h"
#include "kernel/require.h"


ZEPHIR_INIT_CLASS(Phalconry_Mvc_Plugin_Manager) {

	ZEPHIR_REGISTER_CLASS_EX(Phalconry\\Mvc\\Plugin, Manager, phalconry, mvc_plugin_manager, zephir_get_internal_ce(SS("phalcon\\di\\injectable") TSRMLS_CC), phalconry_mvc_plugin_manager_method_entry, 0);

	/**
	 * @var string
	 */
	zend_declare_property_string(phalconry_mvc_plugin_manager_ce, SL("_namespace"), "Plugin\\", ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * @var string
	 */
	zend_declare_property_null(phalconry_mvc_plugin_manager_ce, SL("_path"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * @var array
	 */
	zend_declare_property_null(phalconry_mvc_plugin_manager_ce, SL("_plugins"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * @var array
	 */
	zend_declare_property_null(phalconry_mvc_plugin_manager_ce, SL("_loaded"), ZEND_ACC_PROTECTED TSRMLS_CC);

	phalconry_mvc_plugin_manager_ce->create_object = zephir_init_properties_Phalconry_Mvc_Plugin_Manager;

	zend_class_implements(phalconry_mvc_plugin_manager_ce TSRMLS_CC, 1, phalconry_mvc_plugin_managerinterface_ce);
	return SUCCESS;

}

/**
 * Sets the plugin base namespace.
 *
 * @param string namespace
 * @return void
 */
PHP_METHOD(Phalconry_Mvc_Plugin_Manager, setNamespace) {

	zval *pluginNamespace_param = NULL, *_0, _1, *_2;
	zval *pluginNamespace = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &pluginNamespace_param);

	if (unlikely(Z_TYPE_P(pluginNamespace_param) != IS_STRING && Z_TYPE_P(pluginNamespace_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'pluginNamespace' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(pluginNamespace_param) == IS_STRING)) {
		zephir_get_strval(pluginNamespace, pluginNamespace_param);
	} else {
		ZEPHIR_INIT_VAR(pluginNamespace);
		ZVAL_EMPTY_STRING(pluginNamespace);
	}


	ZEPHIR_INIT_VAR(_0);
	ZEPHIR_SINIT_VAR(_1);
	ZVAL_STRING(&_1, "\\", 0);
	zephir_fast_trim(_0, pluginNamespace, &_1, ZEPHIR_TRIM_RIGHT TSRMLS_CC);
	ZEPHIR_INIT_VAR(_2);
	ZEPHIR_CONCAT_VS(_2, _0, "\\");
	zephir_update_property_this(this_ptr, SL("_namespace"), _2 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

/**
 * Returns the plugin base namespace.
 *
 * Default is "Plugin\"
 *
 * @return string
 */
PHP_METHOD(Phalconry_Mvc_Plugin_Manager, getNamespace) {


	RETURN_MEMBER(this_ptr, "_namespace");

}

/**
 * Sets the plugin directory path.
 *
 * @param string dirPath
 * @return void
 */
PHP_METHOD(Phalconry_Mvc_Plugin_Manager, setPath) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *dirPath_param = NULL, *realpath = NULL, *_0, *_2;
	zval *dirPath = NULL, *_1;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &dirPath_param);

	if (unlikely(Z_TYPE_P(dirPath_param) != IS_STRING && Z_TYPE_P(dirPath_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'dirPath' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(dirPath_param) == IS_STRING)) {
		zephir_get_strval(dirPath, dirPath_param);
	} else {
		ZEPHIR_INIT_VAR(dirPath);
		ZVAL_EMPTY_STRING(dirPath);
	}


	ZEPHIR_CALL_FUNCTION(&realpath, "realpath", NULL, 59, dirPath);
	zephir_check_call_status();
	if (!(zephir_is_true(realpath))) {
		ZEPHIR_INIT_VAR(_0);
		object_init_ex(_0, spl_ce_InvalidArgumentException);
		ZEPHIR_INIT_VAR(_1);
		ZEPHIR_CONCAT_SV(_1, "Invalid plugins directory: ", dirPath);
		ZEPHIR_CALL_METHOD(NULL, _0, "__construct", NULL, 1, _1);
		zephir_check_call_status();
		zephir_throw_exception_debug(_0, "phalconry/mvc/plugin/manager.zep", 66 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_INIT_VAR(_2);
	ZEPHIR_CONCAT_VS(_2, realpath, "/");
	zephir_update_property_this(this_ptr, SL("_path"), _2 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

/**
 * Returns the plugin directory path.
 *
 * @return string|null
 */
PHP_METHOD(Phalconry_Mvc_Plugin_Manager, getPath) {


	RETURN_MEMBER(this_ptr, "_path");

}

/**
 * Returns the classname of a plugin.
 *
 * @param string name
 * @return string
 */
PHP_METHOD(Phalconry_Mvc_Plugin_Manager, getPluginClassname) {

	zval *name_param = NULL, *ucName, *_0;
	zval *name = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name_param);

	if (unlikely(Z_TYPE_P(name_param) != IS_STRING && Z_TYPE_P(name_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'name' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(name_param) == IS_STRING)) {
		zephir_get_strval(name, name_param);
	} else {
		ZEPHIR_INIT_VAR(name);
		ZVAL_EMPTY_STRING(name);
	}


	ZEPHIR_INIT_VAR(ucName);
	zephir_ucfirst(ucName, name);
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_namespace"), PH_NOISY_CC);
	ZEPHIR_CONCAT_VVSVS(return_value, _0, ucName, "\\", ucName, "Plugin");
	RETURN_MM();

}

/**
 * Builds the path to a plugin file.
 *
 * @param string name
 * @return string|null
 */
PHP_METHOD(Phalconry_Mvc_Plugin_Manager, getPluginFilePath) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *name_param = NULL, *_0, *classPath, *_1 = NULL, *_2, _3, *_4, *_5, _6, _7;
	zval *name = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name_param);

	if (unlikely(Z_TYPE_P(name_param) != IS_STRING && Z_TYPE_P(name_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'name' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(name_param) == IS_STRING)) {
		zephir_get_strval(name, name_param);
	} else {
		ZEPHIR_INIT_VAR(name);
		ZVAL_EMPTY_STRING(name);
	}


	ZEPHIR_OBS_VAR(_0);
	zephir_read_property_this(&_0, this_ptr, SL("_path"), PH_NOISY_CC);
	if (Z_TYPE_P(_0) != IS_STRING) {
		RETURN_MM_NULL();
	}
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "getpluginclassname", NULL, 0, name);
	zephir_check_call_status();
	_2 = zephir_fetch_nproperty_this(this_ptr, SL("_namespace"), PH_NOISY_CC);
	ZEPHIR_SINIT_VAR(_3);
	ZVAL_LONG(&_3, zephir_fast_strlen_ev(_2));
	ZEPHIR_INIT_VAR(classPath);
	zephir_substr(classPath, _1, zephir_get_intval(&_3), 0, ZEPHIR_SUBSTR_NO_LENGTH);
	_4 = zephir_fetch_nproperty_this(this_ptr, SL("_path"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_5);
	ZEPHIR_SINIT_VAR(_6);
	ZVAL_STRING(&_6, "\\", 0);
	ZEPHIR_SINIT_VAR(_7);
	ZVAL_STRING(&_7, "/", 0);
	zephir_fast_str_replace(&_5, &_6, &_7, classPath TSRMLS_CC);
	ZEPHIR_CONCAT_VVS(return_value, _4, _5, ".php");
	RETURN_MM();

}

/**
 * Registers a plugin as an object or by class.
 *
 * @param string|\Phalconry\Mvc\PluginInterface classname
 * @return \Phalconry\Mvc\Plugin\ManagerInterface
 *
 * @throws \InvalidArgumentException if plugin is not string or PluginInterface.
 * @throws \Phalconry\Mvc\Plugin\Exception if plugin class cannot be found.
 */
PHP_METHOD(Phalconry_Mvc_Plugin_Manager, register) {

	zend_class_entry *_6;
	zephir_fcall_cache_entry *_1 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *classname = NULL, *_0 = NULL, *_2 = NULL, *_3, *_4 = NULL, *_5 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &classname);

	ZEPHIR_SEPARATE_PARAM(classname);


	if (Z_TYPE_P(classname) == IS_OBJECT) {
		if (zephir_instance_of_ev(classname, zend_ce_closure TSRMLS_CC)) {
			ZEPHIR_CALL_FUNCTION(&_0, "call_user_func", NULL, 62, classname, this_ptr);
			zephir_check_call_status();
			ZEPHIR_CPY_WRT(classname, _0);
		}
		if (!(zephir_instance_of_ev(classname, phalconry_mvc_plugininterface_ce TSRMLS_CC))) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "Invalid plugin object", "phalconry/mvc/plugin/manager.zep", 132);
			return;
		}
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "add", &_1, 0, classname);
		zephir_check_call_status();
	} else {
		if (Z_TYPE_P(classname) != IS_STRING) {
			ZEPHIR_INIT_VAR(_2);
			object_init_ex(_2, spl_ce_InvalidArgumentException);
			ZEPHIR_INIT_VAR(_3);
			zephir_gettype(_3, classname TSRMLS_CC);
			ZEPHIR_INIT_VAR(_4);
			ZEPHIR_CONCAT_SV(_4, "Expecting string or PluginInterface, given: ", _3);
			ZEPHIR_CALL_METHOD(NULL, _2, "__construct", NULL, 1, _4);
			zephir_check_call_status();
			zephir_throw_exception_debug(_2, "phalconry/mvc/plugin/manager.zep", 140 TSRMLS_CC);
			ZEPHIR_MM_RESTORE();
			return;
		}
		if (!(zephir_class_exists(classname, 1 TSRMLS_CC))) {
			ZEPHIR_INIT_NVAR(_2);
			object_init_ex(_2, phalconry_mvc_plugin_exception_ce);
			ZEPHIR_INIT_LNVAR(_4);
			ZEPHIR_CONCAT_SV(_4, "Could not locate plugin class: ", classname);
			ZEPHIR_CALL_METHOD(NULL, _2, "__construct", NULL, 4, _4);
			zephir_check_call_status();
			zephir_throw_exception_debug(_2, "phalconry/mvc/plugin/manager.zep", 144 TSRMLS_CC);
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_INIT_NVAR(_2);
		zephir_fetch_safe_class(_5, classname);
		_6 = zend_fetch_class(Z_STRVAL_P(_5), Z_STRLEN_P(_5), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);
		object_init_ex(_2, _6);
		if (zephir_has_constructor(_2 TSRMLS_CC)) {
			ZEPHIR_CALL_METHOD(NULL, _2, "__construct", NULL, 0);
			zephir_check_call_status();
		}
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "add", &_1, 0, _2);
		zephir_check_call_status();
	}
	RETURN_THIS();

}

/**
 * Registers a plugin object.
 *
 * @param \Phalconry\Mvc\PluginInterface plugin
 * @return \Phalconry\Mvc\Plugin\ManagerInterface
 */
PHP_METHOD(Phalconry_Mvc_Plugin_Manager, add) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *plugin, *_0 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &plugin);



	ZEPHIR_CALL_METHOD(&_0, plugin, "getname", NULL, 0);
	zephir_check_call_status();
	zephir_update_property_array(this_ptr, SL("_plugins"), _0, plugin TSRMLS_CC);
	RETURN_THIS();

}

/**
 * Returns a plugin by name.
 *
 * If the plugin has not been registered, it will be located.
 *
 * @param string name
 * @return \Phalconry\Mvc\PluginInterface
 */
PHP_METHOD(Phalconry_Mvc_Plugin_Manager, get) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *name_param = NULL, *plugin = NULL, *_0;
	zval *name = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name_param);

	if (unlikely(Z_TYPE_P(name_param) != IS_STRING && Z_TYPE_P(name_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'name' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(name_param) == IS_STRING)) {
		zephir_get_strval(name, name_param);
	} else {
		ZEPHIR_INIT_VAR(name);
		ZVAL_EMPTY_STRING(name);
	}


	ZEPHIR_OBS_VAR(plugin);
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_plugins"), PH_NOISY_CC);
	if (zephir_array_isset_fetch(&plugin, _0, name, 0 TSRMLS_CC)) {
		RETURN_CCTOR(plugin);
	}
	ZEPHIR_CALL_METHOD(&plugin, this_ptr, "locateplugin", NULL, 0, name);
	zephir_check_call_status();
	if (Z_TYPE_P(plugin) == IS_OBJECT) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "add", NULL, 0, plugin);
		zephir_check_call_status();
		RETURN_CCTOR(plugin);
	}
	RETURN_MM_NULL();

}

/**
 * Checks if a plugin has been registered.
 *
 * @param string|\Phalconry\Mvc\PluginInterface plugin
 * @return boolean
 */
PHP_METHOD(Phalconry_Mvc_Plugin_Manager, isRegistered) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *plugin, *_0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &plugin);



	if (Z_TYPE_P(plugin) == IS_OBJECT) {
		_0 = zephir_fetch_nproperty_this(this_ptr, SL("_plugins"), PH_NOISY_CC);
		ZEPHIR_RETURN_CALL_FUNCTION("in_array", NULL, 61, plugin, _0, ZEPHIR_GLOBAL(global_true));
		zephir_check_call_status();
		RETURN_MM();
	}
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_plugins"), PH_NOISY_CC);
	RETURN_MM_BOOL(zephir_array_isset(_0, plugin));

}

/**
 * Checks if a plugin has been loaded.
 *
 * @param string|\Phalconry\Mvc\PluginInterface plugin
 * @return boolean
 */
PHP_METHOD(Phalconry_Mvc_Plugin_Manager, isLoaded) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *plugin, *_0 = NULL, *_1, *_2 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &plugin);



	if (Z_TYPE_P(plugin) == IS_OBJECT) {
		ZEPHIR_CALL_METHOD(&_0, this_ptr, "isregistered", NULL, 0, plugin);
		zephir_check_call_status();
		if (!(zephir_is_true(_0))) {
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "add", NULL, 0, plugin);
			zephir_check_call_status();
			RETURN_MM_BOOL(0);
		}
		_1 = zephir_fetch_nproperty_this(this_ptr, SL("_loaded"), PH_NOISY_CC);
		ZEPHIR_CALL_METHOD(&_2, plugin, "getname", NULL, 0);
		zephir_check_call_status();
		RETURN_MM_BOOL(zephir_array_isset(_1, _2));
	}
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("_loaded"), PH_NOISY_CC);
	RETURN_MM_BOOL(zephir_array_isset(_1, plugin));

}

/**
 * Loads a plugin.
 *
 * @param string|\Phalconry\Mvc\PluginInterface plugin
 * @return \Phalconry\Mvc\PluginInterface
 */
PHP_METHOD(Phalconry_Mvc_Plugin_Manager, load) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *plugin, *pluginObject = NULL, *dependencyInjector = NULL, *eventsManager = NULL, *_0 = NULL, *_1 = NULL, *_2 = NULL, *_3 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &plugin);



	if (Z_TYPE_P(plugin) == IS_OBJECT) {
		ZEPHIR_CPY_WRT(pluginObject, plugin);
	} else {
		ZEPHIR_CALL_METHOD(&pluginObject, this_ptr, "get", NULL, 0, plugin);
		zephir_check_call_status();
		if (Z_TYPE_P(pluginObject) != IS_OBJECT) {
			ZEPHIR_INIT_VAR(_0);
			object_init_ex(_0, phalconry_mvc_plugin_exception_ce);
			ZEPHIR_INIT_VAR(_1);
			ZEPHIR_CONCAT_SV(_1, "Could not locate plugin: ", plugin);
			ZEPHIR_CALL_METHOD(NULL, _0, "__construct", NULL, 4, _1);
			zephir_check_call_status();
			zephir_throw_exception_debug(_0, "phalconry/mvc/plugin/manager.zep", 242 TSRMLS_CC);
			ZEPHIR_MM_RESTORE();
			return;
		}
	}
	ZEPHIR_CALL_METHOD(&_2, this_ptr, "isloaded", NULL, 0, pluginObject);
	zephir_check_call_status();
	if (zephir_is_true(_2)) {
		ZEPHIR_INIT_NVAR(_0);
		object_init_ex(_0, phalconry_mvc_plugin_exception_ce);
		ZEPHIR_CALL_METHOD(&_3, pluginObject, "getname", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_INIT_LNVAR(_1);
		ZEPHIR_CONCAT_SV(_1, "Cannot reload plugin: ", _3);
		ZEPHIR_CALL_METHOD(NULL, _0, "__construct", NULL, 4, _1);
		zephir_check_call_status();
		zephir_throw_exception_debug(_0, "phalconry/mvc/plugin/manager.zep", 247 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CALL_METHOD(&dependencyInjector, this_ptr, "getdi", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&eventsManager, this_ptr, "geteventsmanager", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, pluginObject, "setmanager", NULL, 0, this_ptr);
	zephir_check_call_status();
	if (zephir_is_instance_of(pluginObject, SL("Phalcon\\Di\\InjectionAwareInterface") TSRMLS_CC)) {
		ZEPHIR_CALL_METHOD(NULL, pluginObject, "setdi", NULL, 0, dependencyInjector);
		zephir_check_call_status();
	}
	if (Z_TYPE_P(eventsManager) == IS_OBJECT) {
		ZEPHIR_INIT_NVAR(_0);
		ZVAL_STRING(_0, "plugins:beforeLoad", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(NULL, eventsManager, "fire", NULL, 0, _0, this_ptr, pluginObject);
		zephir_check_temp_parameter(_0);
		zephir_check_call_status();
	}
	ZEPHIR_CALL_METHOD(NULL, pluginObject, "load", NULL, 0, dependencyInjector);
	zephir_check_call_status();
	if (Z_TYPE_P(eventsManager) == IS_OBJECT) {
		ZEPHIR_INIT_NVAR(_0);
		ZVAL_STRING(_0, "plugins:afterLoad", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(NULL, eventsManager, "fire", NULL, 0, _0, this_ptr, pluginObject);
		zephir_check_temp_parameter(_0);
		zephir_check_call_status();
	}
	ZEPHIR_CALL_METHOD(&_3, pluginObject, "getname", NULL, 0);
	zephir_check_call_status();
	zephir_update_property_array(this_ptr, SL("_loaded"), _3, ZEPHIR_GLOBAL(global_true) TSRMLS_CC);
	RETURN_CCTOR(pluginObject);

}

/**
 * Locates a plugin in the plugin directory.
 *
 * @param string name
 * @return \Phalconry\Mvc\PluginInterface|null
 *
 * @throws \Phalconry\Mvc\Plugin\Exception if an invalid plugin is injected.
 */
PHP_METHOD(Phalconry_Mvc_Plugin_Manager, locatePlugin) {

	zend_class_entry *_1;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *name_param = NULL, *filepath = NULL, *classname = NULL, *dependencyInjector = NULL, *plugin = NULL, *_0 = NULL, *_2 = NULL, *_5;
	zval *name = NULL, *_3, *_4 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name_param);

	if (unlikely(Z_TYPE_P(name_param) != IS_STRING && Z_TYPE_P(name_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'name' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(name_param) == IS_STRING)) {
		zephir_get_strval(name, name_param);
	} else {
		ZEPHIR_INIT_VAR(name);
		ZVAL_EMPTY_STRING(name);
	}


	ZEPHIR_CALL_METHOD(&filepath, this_ptr, "getpluginfilepath", NULL, 0, name);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&classname, this_ptr, "getpluginclassname", NULL, 0, name);
	zephir_check_call_status();
	if (Z_TYPE_P(filepath) == IS_STRING) {
		if ((zephir_file_exists(filepath TSRMLS_CC) == SUCCESS)) {
			if (zephir_require_zval(filepath TSRMLS_CC) == FAILURE) {
				RETURN_MM_NULL();
			}
			if (zephir_class_exists(classname, zephir_is_true(ZEPHIR_GLOBAL(global_false))  TSRMLS_CC)) {
				zephir_fetch_safe_class(_0, classname);
				_1 = zend_fetch_class(Z_STRVAL_P(_0), Z_STRLEN_P(_0), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);
				object_init_ex(return_value, _1);
				if (zephir_has_constructor(return_value TSRMLS_CC)) {
					ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 0);
					zephir_check_call_status();
				}
				RETURN_MM();
			}
		}
	}
	ZEPHIR_CALL_METHOD(&dependencyInjector, this_ptr, "getdi", NULL, 0);
	zephir_check_call_status();
	if (Z_TYPE_P(dependencyInjector) == IS_OBJECT) {
		ZEPHIR_INIT_VAR(_3);
		ZEPHIR_CONCAT_VS(_3, name, "Plugin");
		ZEPHIR_CALL_METHOD(&_2, dependencyInjector, "has", NULL, 0, _3);
		zephir_check_call_status();
		if (zephir_is_true(_2)) {
			ZEPHIR_INIT_VAR(_4);
			ZEPHIR_CONCAT_VS(_4, name, "Plugin");
			ZEPHIR_CALL_METHOD(&plugin, dependencyInjector, "getshared", NULL, 0, _4);
			zephir_check_call_status();
		} else {
			ZEPHIR_CALL_METHOD(&plugin, dependencyInjector, "get", NULL, 0, classname);
			zephir_check_call_status();
		}
		if (Z_TYPE_P(plugin) == IS_OBJECT) {
			if (zephir_instance_of_ev(plugin, phalconry_mvc_plugininterface_ce TSRMLS_CC)) {
				RETURN_CCTOR(plugin);
			}
			ZEPHIR_INIT_VAR(_5);
			object_init_ex(_5, phalconry_mvc_plugin_exception_ce);
			ZEPHIR_INIT_LNVAR(_4);
			ZEPHIR_CONCAT_SV(_4, "Invalid injected plugin: ", name);
			ZEPHIR_CALL_METHOD(NULL, _5, "__construct", NULL, 4, _4);
			zephir_check_call_status();
			zephir_throw_exception_debug(_5, "phalconry/mvc/plugin/manager.zep", 317 TSRMLS_CC);
			ZEPHIR_MM_RESTORE();
			return;
		}
	}
	RETURN_MM_NULL();

}

static zend_object_value zephir_init_properties_Phalconry_Mvc_Plugin_Manager(zend_class_entry *class_type TSRMLS_DC) {

		zval *_0, *_1 = NULL, *_2;

		ZEPHIR_MM_GROW();
	
	{
		zval *this_ptr = NULL;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		_0 = zephir_fetch_nproperty_this(this_ptr, SL("_loaded"), PH_NOISY_CC);
		if (Z_TYPE_P(_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(_1);
			array_init(_1);
			zephir_update_property_this(this_ptr, SL("_loaded"), _1 TSRMLS_CC);
		}
		_2 = zephir_fetch_nproperty_this(this_ptr, SL("_plugins"), PH_NOISY_CC);
		if (Z_TYPE_P(_2) == IS_NULL) {
			ZEPHIR_INIT_NVAR(_1);
			array_init(_1);
			zephir_update_property_this(this_ptr, SL("_plugins"), _1 TSRMLS_CC);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJVAL_P(this_ptr);
	}

}

