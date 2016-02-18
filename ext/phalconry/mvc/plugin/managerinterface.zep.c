
#ifdef HAVE_CONFIG_H
#include "../../../ext_config.h"
#endif

#include <php.h>
#include "../../../php_ext.h"
#include "../../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


/**
 * Contract for a plugin manager.
 */
ZEPHIR_INIT_CLASS(Phalconry_Mvc_Plugin_ManagerInterface) {

	ZEPHIR_REGISTER_INTERFACE(Phalconry\\Mvc\\Plugin, ManagerInterface, phalconry, mvc_plugin_managerinterface, phalconry_mvc_plugin_managerinterface_method_entry);

	return SUCCESS;

}

/**
 * Sets the plugin base namespace.
 *
 * @param string pluginNamespace
 * @return void
 */
ZEPHIR_DOC_METHOD(Phalconry_Mvc_Plugin_ManagerInterface, setNamespace);

/**
 * Returns the plugin base namespace.
 *
 * @return string
 */
ZEPHIR_DOC_METHOD(Phalconry_Mvc_Plugin_ManagerInterface, getNamespace);

/**
 * Sets the plugin directory path.
 *
 * @param string dirPath
 * @return void
 *
 * @throws \InvalidArgumentException if path is invalid.
 */
ZEPHIR_DOC_METHOD(Phalconry_Mvc_Plugin_ManagerInterface, setPath);

/**
 * Returns the plugin directory path.
 *
 * @return string|null
 */
ZEPHIR_DOC_METHOD(Phalconry_Mvc_Plugin_ManagerInterface, getPath);

/**
 * Returns the classname of a plugin.
 *
 * @param string name
 * @return string
 */
ZEPHIR_DOC_METHOD(Phalconry_Mvc_Plugin_ManagerInterface, getPluginClassname);

/**
 * Builds the path to a plugin file.
 *
 * @param string name
 * @return string|null
 */
ZEPHIR_DOC_METHOD(Phalconry_Mvc_Plugin_ManagerInterface, getPluginFilePath);

/**
 * Registers a plugin as an object or by class.
 *
 * @param string|\Phalconry\Mvc\PluginInterface classname
 * @return \Phalconry\Mvc\Plugin\ManagerInterface
 */
ZEPHIR_DOC_METHOD(Phalconry_Mvc_Plugin_ManagerInterface, register);

/**
 * Registers a plugin object.
 *
 * @param \Phalconry\Mvc\PluginInterface plugin
 * @return \Phalconry\Mvc\Plugin\ManagerInterface
 */
ZEPHIR_DOC_METHOD(Phalconry_Mvc_Plugin_ManagerInterface, add);

/**
 * Returns a plugin by name.
 *
 * If the plugin has not been registered, it will be located.
 *
 * @param string name
 * @return \Phalconry\Mvc\PluginInterface|null
 */
ZEPHIR_DOC_METHOD(Phalconry_Mvc_Plugin_ManagerInterface, get);

/**
 * Checks if a plugin has been registered.
 *
 * @param string|\Phalconry\Mvc\PluginInterface plugin
 * @return boolean
 */
ZEPHIR_DOC_METHOD(Phalconry_Mvc_Plugin_ManagerInterface, isRegistered);

/**
 * Checks if a plugin has been loaded.
 *
 * @param string|\Phalconry\Mvc\PluginInterface plugin
 * @return boolean
 */
ZEPHIR_DOC_METHOD(Phalconry_Mvc_Plugin_ManagerInterface, isLoaded);

/**
 * Loads a plugin.
 *
 * @param string|\Phalconry\Mvc\PluginInterface plugin
 * @return \Phalconry\Mvc\PluginInterface
 */
ZEPHIR_DOC_METHOD(Phalconry_Mvc_Plugin_ManagerInterface, load);

