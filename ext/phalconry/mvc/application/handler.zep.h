
extern zend_class_entry *phalconry_mvc_application_handler_ce;

ZEPHIR_INIT_CLASS(Phalconry_Mvc_Application_Handler);

PHP_METHOD(Phalconry_Mvc_Application_Handler, __construct);
PHP_METHOD(Phalconry_Mvc_Application_Handler, setApplication);
PHP_METHOD(Phalconry_Mvc_Application_Handler, getApplication);
PHP_METHOD(Phalconry_Mvc_Application_Handler, handle);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconry_mvc_application_handler___construct, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, app, Phalconry\\Mvc\\ApplicationInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconry_mvc_application_handler_setapplication, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, app, Phalconry\\Mvc\\ApplicationInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconry_mvc_application_handler_handle, 0, 0, 0)
	ZEND_ARG_INFO(0, uri)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalconry_mvc_application_handler_method_entry) {
	PHP_ME(Phalconry_Mvc_Application_Handler, __construct, arginfo_phalconry_mvc_application_handler___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalconry_Mvc_Application_Handler, setApplication, arginfo_phalconry_mvc_application_handler_setapplication, ZEND_ACC_PUBLIC)
	PHP_ME(Phalconry_Mvc_Application_Handler, getApplication, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalconry_Mvc_Application_Handler, handle, arginfo_phalconry_mvc_application_handler_handle, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
