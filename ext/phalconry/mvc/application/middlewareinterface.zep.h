
extern zend_class_entry *phalconry_mvc_application_middlewareinterface_ce;

ZEPHIR_INIT_CLASS(Phalconry_Mvc_Application_MiddlewareInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconry_mvc_application_middlewareinterface_execute, 0, 0, 2)
	ZEND_ARG_OBJ_INFO(0, di, Phalcon\\DiInterface, 0)
	ZEND_ARG_OBJ_INFO(0, app, Phalconry\\Mvc\\ApplicationInterface, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalconry_mvc_application_middlewareinterface_method_entry) {
	PHP_ABSTRACT_ME(Phalconry_Mvc_Application_MiddlewareInterface, getPosition, NULL)
	PHP_ABSTRACT_ME(Phalconry_Mvc_Application_MiddlewareInterface, execute, arginfo_phalconry_mvc_application_middlewareinterface_execute)
	PHP_FE_END
};
