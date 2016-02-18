
extern zend_class_entry *phalconry_mvc_module_manager_ce;

ZEPHIR_INIT_CLASS(Phalconry_Mvc_Module_Manager);

PHP_METHOD(Phalconry_Mvc_Module_Manager, setPrimaryModuleName);
PHP_METHOD(Phalconry_Mvc_Module_Manager, getPrimaryModuleName);
PHP_METHOD(Phalconry_Mvc_Module_Manager, setDefaultModuleName);
PHP_METHOD(Phalconry_Mvc_Module_Manager, getDefaultModuleName);
PHP_METHOD(Phalconry_Mvc_Module_Manager, registerModules);
PHP_METHOD(Phalconry_Mvc_Module_Manager, addModule);
PHP_METHOD(Phalconry_Mvc_Module_Manager, getModule);
PHP_METHOD(Phalconry_Mvc_Module_Manager, hasModule);
PHP_METHOD(Phalconry_Mvc_Module_Manager, getPrimaryModule);
PHP_METHOD(Phalconry_Mvc_Module_Manager, loadModule);
PHP_METHOD(Phalconry_Mvc_Module_Manager, isLoaded);
PHP_METHOD(Phalconry_Mvc_Module_Manager, createFromDefinition);
static zend_object_value zephir_init_properties_Phalconry_Mvc_Module_Manager(zend_class_entry *class_type TSRMLS_DC);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconry_mvc_module_manager_setprimarymodulename, 0, 0, 1)
	ZEND_ARG_INFO(0, moduleName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconry_mvc_module_manager_setdefaultmodulename, 0, 0, 1)
	ZEND_ARG_INFO(0, moduleName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconry_mvc_module_manager_registermodules, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, definitions, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconry_mvc_module_manager_addmodule, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, module, Phalconry\\Mvc\\ModuleInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconry_mvc_module_manager_getmodule, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconry_mvc_module_manager_hasmodule, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconry_mvc_module_manager_loadmodule, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, module, Phalconry\\Mvc\\ModuleInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconry_mvc_module_manager_isloaded, 0, 0, 1)
	ZEND_ARG_INFO(0, module)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconry_mvc_module_manager_createfromdefinition, 0, 0, 1)
	ZEND_ARG_INFO(0, definition)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalconry_mvc_module_manager_method_entry) {
	PHP_ME(Phalconry_Mvc_Module_Manager, setPrimaryModuleName, arginfo_phalconry_mvc_module_manager_setprimarymodulename, ZEND_ACC_PUBLIC)
	PHP_ME(Phalconry_Mvc_Module_Manager, getPrimaryModuleName, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalconry_Mvc_Module_Manager, setDefaultModuleName, arginfo_phalconry_mvc_module_manager_setdefaultmodulename, ZEND_ACC_PUBLIC)
	PHP_ME(Phalconry_Mvc_Module_Manager, getDefaultModuleName, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalconry_Mvc_Module_Manager, registerModules, arginfo_phalconry_mvc_module_manager_registermodules, ZEND_ACC_PUBLIC)
	PHP_ME(Phalconry_Mvc_Module_Manager, addModule, arginfo_phalconry_mvc_module_manager_addmodule, ZEND_ACC_PUBLIC)
	PHP_ME(Phalconry_Mvc_Module_Manager, getModule, arginfo_phalconry_mvc_module_manager_getmodule, ZEND_ACC_PUBLIC)
	PHP_ME(Phalconry_Mvc_Module_Manager, hasModule, arginfo_phalconry_mvc_module_manager_hasmodule, ZEND_ACC_PUBLIC)
	PHP_ME(Phalconry_Mvc_Module_Manager, getPrimaryModule, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalconry_Mvc_Module_Manager, loadModule, arginfo_phalconry_mvc_module_manager_loadmodule, ZEND_ACC_PUBLIC)
	PHP_ME(Phalconry_Mvc_Module_Manager, isLoaded, arginfo_phalconry_mvc_module_manager_isloaded, ZEND_ACC_PUBLIC)
	PHP_ME(Phalconry_Mvc_Module_Manager, createFromDefinition, arginfo_phalconry_mvc_module_manager_createfromdefinition, ZEND_ACC_PROTECTED)
	PHP_FE_END
};
