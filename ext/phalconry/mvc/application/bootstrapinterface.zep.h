
extern zend_class_entry *phalconry_mvc_application_bootstrapinterface_ce;

ZEPHIR_INIT_CLASS(Phalconry_Mvc_Application_BootstrapInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconry_mvc_application_bootstrapinterface_boot, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, app, Phalconry\\Mvc\\ApplicationInterface, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalconry_mvc_application_bootstrapinterface_method_entry) {
	PHP_ABSTRACT_ME(Phalconry_Mvc_Application_BootstrapInterface, boot, arginfo_phalconry_mvc_application_bootstrapinterface_boot)
	PHP_FE_END
};
