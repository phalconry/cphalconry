
extern zend_class_entry *phalconry_mvc_module_ce;

ZEPHIR_INIT_CLASS(Phalconry_Mvc_Module);

PHP_METHOD(Phalconry_Mvc_Module, setDI);
PHP_METHOD(Phalconry_Mvc_Module, getDI);
PHP_METHOD(Phalconry_Mvc_Module, setName);
PHP_METHOD(Phalconry_Mvc_Module, getName);
PHP_METHOD(Phalconry_Mvc_Module, setManager);
PHP_METHOD(Phalconry_Mvc_Module, getManager);
PHP_METHOD(Phalconry_Mvc_Module, setApp);
PHP_METHOD(Phalconry_Mvc_Module, getApp);
PHP_METHOD(Phalconry_Mvc_Module, isLoaded);
PHP_METHOD(Phalconry_Mvc_Module, isPrimary);
PHP_METHOD(Phalconry_Mvc_Module, isDefault);
PHP_METHOD(Phalconry_Mvc_Module, registerAutoloaders);
PHP_METHOD(Phalconry_Mvc_Module, registerServices);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconry_mvc_module_setdi, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, di, Phalcon\\DiInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconry_mvc_module_setname, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconry_mvc_module_setmanager, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, manager, Phalconry\\Mvc\\Module\\ManagerInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconry_mvc_module_setapp, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, app, Phalconry\\Mvc\\ApplicationInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconry_mvc_module_registerautoloaders, 0, 0, 0)
	ZEND_ARG_OBJ_INFO(0, di, Phalcon\\DiInterface, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconry_mvc_module_registerservices, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, di, Phalcon\\DiInterface, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalconry_mvc_module_method_entry) {
	PHP_ME(Phalconry_Mvc_Module, setDI, arginfo_phalconry_mvc_module_setdi, ZEND_ACC_PUBLIC)
	PHP_ME(Phalconry_Mvc_Module, getDI, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalconry_Mvc_Module, setName, arginfo_phalconry_mvc_module_setname, ZEND_ACC_PUBLIC)
	PHP_ME(Phalconry_Mvc_Module, getName, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalconry_Mvc_Module, setManager, arginfo_phalconry_mvc_module_setmanager, ZEND_ACC_PUBLIC)
	PHP_ME(Phalconry_Mvc_Module, getManager, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalconry_Mvc_Module, setApp, arginfo_phalconry_mvc_module_setapp, ZEND_ACC_PUBLIC)
	PHP_ME(Phalconry_Mvc_Module, getApp, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalconry_Mvc_Module, isLoaded, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalconry_Mvc_Module, isPrimary, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalconry_Mvc_Module, isDefault, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalconry_Mvc_Module, registerAutoloaders, arginfo_phalconry_mvc_module_registerautoloaders, ZEND_ACC_PUBLIC)
	PHP_ME(Phalconry_Mvc_Module, registerServices, arginfo_phalconry_mvc_module_registerservices, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
