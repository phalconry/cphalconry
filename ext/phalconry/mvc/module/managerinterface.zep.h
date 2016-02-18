
extern zend_class_entry *phalconry_mvc_module_managerinterface_ce;

ZEPHIR_INIT_CLASS(Phalconry_Mvc_Module_ManagerInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconry_mvc_module_managerinterface_setprimarymodulename, 0, 0, 1)
	ZEND_ARG_INFO(0, moduleName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconry_mvc_module_managerinterface_setdefaultmodulename, 0, 0, 1)
	ZEND_ARG_INFO(0, moduleName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconry_mvc_module_managerinterface_registermodules, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, definitions, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconry_mvc_module_managerinterface_addmodule, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, module, Phalconry\\Mvc\\ModuleInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconry_mvc_module_managerinterface_getmodule, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconry_mvc_module_managerinterface_hasmodule, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconry_mvc_module_managerinterface_loadmodule, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, module, Phalconry\\Mvc\\ModuleInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconry_mvc_module_managerinterface_isloaded, 0, 0, 1)
	ZEND_ARG_INFO(0, module)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalconry_mvc_module_managerinterface_method_entry) {
	PHP_ABSTRACT_ME(Phalconry_Mvc_Module_ManagerInterface, setPrimaryModuleName, arginfo_phalconry_mvc_module_managerinterface_setprimarymodulename)
	PHP_ABSTRACT_ME(Phalconry_Mvc_Module_ManagerInterface, getPrimaryModuleName, NULL)
	PHP_ABSTRACT_ME(Phalconry_Mvc_Module_ManagerInterface, setDefaultModuleName, arginfo_phalconry_mvc_module_managerinterface_setdefaultmodulename)
	PHP_ABSTRACT_ME(Phalconry_Mvc_Module_ManagerInterface, getDefaultModuleName, NULL)
	PHP_ABSTRACT_ME(Phalconry_Mvc_Module_ManagerInterface, registerModules, arginfo_phalconry_mvc_module_managerinterface_registermodules)
	PHP_ABSTRACT_ME(Phalconry_Mvc_Module_ManagerInterface, addModule, arginfo_phalconry_mvc_module_managerinterface_addmodule)
	PHP_ABSTRACT_ME(Phalconry_Mvc_Module_ManagerInterface, getModule, arginfo_phalconry_mvc_module_managerinterface_getmodule)
	PHP_ABSTRACT_ME(Phalconry_Mvc_Module_ManagerInterface, hasModule, arginfo_phalconry_mvc_module_managerinterface_hasmodule)
	PHP_ABSTRACT_ME(Phalconry_Mvc_Module_ManagerInterface, getPrimaryModule, NULL)
	PHP_ABSTRACT_ME(Phalconry_Mvc_Module_ManagerInterface, loadModule, arginfo_phalconry_mvc_module_managerinterface_loadmodule)
	PHP_ABSTRACT_ME(Phalconry_Mvc_Module_ManagerInterface, isLoaded, arginfo_phalconry_mvc_module_managerinterface_isloaded)
	PHP_FE_END
};
