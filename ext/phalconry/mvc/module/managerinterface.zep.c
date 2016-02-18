
#ifdef HAVE_CONFIG_H
#include "../../../ext_config.h"
#endif

#include <php.h>
#include "../../../php_ext.h"
#include "../../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


ZEPHIR_INIT_CLASS(Phalconry_Mvc_Module_ManagerInterface) {

	ZEPHIR_REGISTER_INTERFACE(Phalconry\\Mvc\\Module, ManagerInterface, phalconry, mvc_module_managerinterface, phalconry_mvc_module_managerinterface_method_entry);

	return SUCCESS;

}

/**
 * Sets the name of the primary module.
 *
 * @param string moduleName
 */
ZEPHIR_DOC_METHOD(Phalconry_Mvc_Module_ManagerInterface, setPrimaryModuleName);

/**
 * Returns the name of the primary module.
 *
 * @return string
 */
ZEPHIR_DOC_METHOD(Phalconry_Mvc_Module_ManagerInterface, getPrimaryModuleName);

/**
 * Sets the name of the default module.
 *
 * @param string moduleName
 */
ZEPHIR_DOC_METHOD(Phalconry_Mvc_Module_ManagerInterface, setDefaultModuleName);

/**
 * Returns the name of the default module.
 *
 * @return string
 */
ZEPHIR_DOC_METHOD(Phalconry_Mvc_Module_ManagerInterface, getDefaultModuleName);

/**
 * Registers an array of module definitions.
 *
 * @param array definitions
 * @return void
 */
ZEPHIR_DOC_METHOD(Phalconry_Mvc_Module_ManagerInterface, registerModules);

/**
 * Sets a module in the registry
 *
 * @param \Phalconry\Mvc\ModuleInterface module
 */
ZEPHIR_DOC_METHOD(Phalconry_Mvc_Module_ManagerInterface, addModule);

/**
 * Returns a module by name, or the primary module if no name is given
 *
 * @param string name Module name
 * @return \Phalconry\Mvc\ModuleInterface
 */
ZEPHIR_DOC_METHOD(Phalconry_Mvc_Module_ManagerInterface, getModule);

/**
 * Checks whether a module exists
 *
 * @param string|\Phalconry\Mvc\ModuleInterface name
 * @return boolean
 */
ZEPHIR_DOC_METHOD(Phalconry_Mvc_Module_ManagerInterface, hasModule);

/**
 * Returns the primary module
 *
 * @return \Phalconry\Mvc\ModuleInterface
 *
 * @throws \Phalcon\Mvc\Exception if primary module is not set
 */
ZEPHIR_DOC_METHOD(Phalconry_Mvc_Module_ManagerInterface, getPrimaryModule);

/**
 * Loads a module
 *
 * @param \Phalconry\Mvc\ModuleInterface module
 * @return \Phalconry\Mvc\ModuleInterface
 *
 * @throws \Phalcon\Mvc\Exception if module has already been loaded
 */
ZEPHIR_DOC_METHOD(Phalconry_Mvc_Module_ManagerInterface, loadModule);

/**
 * Whether a module has been loaded
 *
 * @param string|\Phalconry\Mvc\Module $module
 * @return boolean
 *
 * @throws \InvalidArgumentException if not given a Module object or string
 */
ZEPHIR_DOC_METHOD(Phalconry_Mvc_Module_ManagerInterface, isLoaded);

