
extern zend_class_entry *phalconry_mvc_application_bootstrapper_ce;

ZEPHIR_INIT_CLASS(Phalconry_Mvc_Application_Bootstrapper);

PHP_METHOD(Phalconry_Mvc_Application_Bootstrapper, boot);
PHP_METHOD(Phalconry_Mvc_Application_Bootstrapper, afterStartModule);
PHP_METHOD(Phalconry_Mvc_Application_Bootstrapper, afterHandleRequest);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconry_mvc_application_bootstrapper_boot, 0, 0, 2)
	ZEND_ARG_OBJ_INFO(0, event, Phalcon\\Events\\Event, 0)
	ZEND_ARG_OBJ_INFO(0, app, Phalconry\\Mvc\\Application, 0)
	ZEND_ARG_INFO(0, nothing)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconry_mvc_application_bootstrapper_afterstartmodule, 0, 0, 3)
	ZEND_ARG_OBJ_INFO(0, event, Phalcon\\Events\\Event, 0)
	ZEND_ARG_OBJ_INFO(0, app, Phalconry\\Mvc\\Application, 0)
	ZEND_ARG_OBJ_INFO(0, module, Phalconry\\Mvc\\Module, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconry_mvc_application_bootstrapper_afterhandlerequest, 0, 0, 3)
	ZEND_ARG_OBJ_INFO(0, event, Phalcon\\Events\\Event, 0)
	ZEND_ARG_OBJ_INFO(0, app, Phalconry\\Mvc\\Application, 0)
	ZEND_ARG_INFO(0, controller)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalconry_mvc_application_bootstrapper_method_entry) {
	PHP_ME(Phalconry_Mvc_Application_Bootstrapper, boot, arginfo_phalconry_mvc_application_bootstrapper_boot, ZEND_ACC_PUBLIC)
	PHP_ME(Phalconry_Mvc_Application_Bootstrapper, afterStartModule, arginfo_phalconry_mvc_application_bootstrapper_afterstartmodule, ZEND_ACC_PUBLIC)
	PHP_ME(Phalconry_Mvc_Application_Bootstrapper, afterHandleRequest, arginfo_phalconry_mvc_application_bootstrapper_afterhandlerequest, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
