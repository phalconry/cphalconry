
extern zend_class_entry *phalconry_mvc_application_bootstrap_ce;

ZEPHIR_INIT_CLASS(Phalconry_Mvc_Application_Bootstrap);

PHP_METHOD(Phalconry_Mvc_Application_Bootstrap, boot);
PHP_METHOD(Phalconry_Mvc_Application_Bootstrap, afterStartModule);
PHP_METHOD(Phalconry_Mvc_Application_Bootstrap, afterHandleRequest);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconry_mvc_application_bootstrap_boot, 0, 0, 2)
	ZEND_ARG_OBJ_INFO(0, event, Phalcon\\Events\\Event, 0)
	ZEND_ARG_OBJ_INFO(0, app, Phalconry\\Mvc\\Application, 0)
	ZEND_ARG_INFO(0, nothing)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconry_mvc_application_bootstrap_afterstartmodule, 0, 0, 3)
	ZEND_ARG_OBJ_INFO(0, event, Phalcon\\Events\\Event, 0)
	ZEND_ARG_OBJ_INFO(0, app, Phalconry\\Mvc\\Application, 0)
	ZEND_ARG_OBJ_INFO(0, module, Phalconry\\Mvc\\Module, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconry_mvc_application_bootstrap_afterhandlerequest, 0, 0, 3)
	ZEND_ARG_OBJ_INFO(0, event, Phalcon\\Events\\Event, 0)
	ZEND_ARG_OBJ_INFO(0, app, Phalconry\\Mvc\\Application, 0)
	ZEND_ARG_INFO(0, controller)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalconry_mvc_application_bootstrap_method_entry) {
	PHP_ME(Phalconry_Mvc_Application_Bootstrap, boot, arginfo_phalconry_mvc_application_bootstrap_boot, ZEND_ACC_PUBLIC)
	PHP_ME(Phalconry_Mvc_Application_Bootstrap, afterStartModule, arginfo_phalconry_mvc_application_bootstrap_afterstartmodule, ZEND_ACC_PUBLIC)
	PHP_ME(Phalconry_Mvc_Application_Bootstrap, afterHandleRequest, arginfo_phalconry_mvc_application_bootstrap_afterhandlerequest, ZEND_ACC_PUBLIC)
  PHP_FE_END
};
