
extern zend_class_entry *phalconry_mvc_application_bootstrap_ce;

ZEPHIR_INIT_CLASS(Phalconry_Mvc_Application_Bootstrap);

PHP_METHOD(Phalconry_Mvc_Application_Bootstrap, boot);
PHP_METHOD(Phalconry_Mvc_Application_Bootstrap, registerLoader);
PHP_METHOD(Phalconry_Mvc_Application_Bootstrap, registerServices);
PHP_METHOD(Phalconry_Mvc_Application_Bootstrap, registerModules);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconry_mvc_application_bootstrap_boot, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, app, Phalconry\\Mvc\\ApplicationInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconry_mvc_application_bootstrap_registerloader, 0, 0, 3)
	ZEND_ARG_OBJ_INFO(0, di, Phalcon\\DiInterface, 0)
	ZEND_ARG_OBJ_INFO(0, app, Phalconry\\Mvc\\ApplicationInterface, 0)
	ZEND_ARG_OBJ_INFO(0, loader, Phalcon\\Loader, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconry_mvc_application_bootstrap_registerservices, 0, 0, 3)
	ZEND_ARG_OBJ_INFO(0, di, Phalcon\\DiInterface, 0)
	ZEND_ARG_OBJ_INFO(0, app, Phalconry\\Mvc\\ApplicationInterface, 0)
	ZEND_ARG_OBJ_INFO(0, loader, Phalcon\\Loader, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconry_mvc_application_bootstrap_registermodules, 0, 0, 3)
	ZEND_ARG_OBJ_INFO(0, di, Phalcon\\DiInterface, 0)
	ZEND_ARG_OBJ_INFO(0, app, Phalconry\\Mvc\\ApplicationInterface, 0)
	ZEND_ARG_OBJ_INFO(0, loader, Phalcon\\Loader, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalconry_mvc_application_bootstrap_method_entry) {
	PHP_ME(Phalconry_Mvc_Application_Bootstrap, boot, arginfo_phalconry_mvc_application_bootstrap_boot, ZEND_ACC_PUBLIC)
	PHP_ME(Phalconry_Mvc_Application_Bootstrap, registerLoader, arginfo_phalconry_mvc_application_bootstrap_registerloader, ZEND_ACC_PROTECTED)
	PHP_ME(Phalconry_Mvc_Application_Bootstrap, registerServices, arginfo_phalconry_mvc_application_bootstrap_registerservices, ZEND_ACC_PROTECTED)
	PHP_ME(Phalconry_Mvc_Application_Bootstrap, registerModules, arginfo_phalconry_mvc_application_bootstrap_registermodules, ZEND_ACC_PROTECTED)
	PHP_FE_END
};
