
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


ZEPHIR_INIT_CLASS(Phalconry_Mvc_PluginInterface) {

	ZEPHIR_REGISTER_INTERFACE(Phalconry\\Mvc, PluginInterface, phalconry, mvc_plugininterface, phalconry_mvc_plugininterface_method_entry);

	return SUCCESS;

}

/**
 * Returns the plugin's name.
 *
 * @return string
 */
ZEPHIR_DOC_METHOD(Phalconry_Mvc_PluginInterface, getName);

/**
 * Returns the path to the plugin's directory.
 *
 * @return string
 */
ZEPHIR_DOC_METHOD(Phalconry_Mvc_PluginInterface, getPath);

/**
 * Sets the plugins manager.
 *
 * @param \Phalconry\Mvc\Plugin\ManagerInterface manager
 * @return void
 */
ZEPHIR_DOC_METHOD(Phalconry_Mvc_PluginInterface, setManager);

/**
 * Returns the plugins manager.
 *
 * @return \Phalconry\Mvc\Plugin\ManagerInterface
 */
ZEPHIR_DOC_METHOD(Phalconry_Mvc_PluginInterface, getManager);

/**
 * Returns the plugin's Config object.
 *
 * @return \Phalcon\Config|null
 */
ZEPHIR_DOC_METHOD(Phalconry_Mvc_PluginInterface, getConfig);

/**
 * Checks whether the plugin is loaded.
 *
 * The simplest way to implement this method is to check if the manager exists.
 *
 * @return boolean
 */
ZEPHIR_DOC_METHOD(Phalconry_Mvc_PluginInterface, isLoaded);

/**
 * Loads the plugin.
 *
 * @param \Phalcon\DiInterface di
 *
 * @throws \Phalconry\Mvc\Plugin\Exception
 */
ZEPHIR_DOC_METHOD(Phalconry_Mvc_PluginInterface, load);

