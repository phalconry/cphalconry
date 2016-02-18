
extern zend_class_entry *phalconry_mvc_applicationawareinterface_ce;

ZEPHIR_INIT_CLASS(Phalconry_Mvc_ApplicationAwareInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconry_mvc_applicationawareinterface_setapplication, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, app, Phalconry\\Mvc\\ApplicationInterface, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalconry_mvc_applicationawareinterface_method_entry) {
	PHP_ABSTRACT_ME(Phalconry_Mvc_ApplicationAwareInterface, setApplication, arginfo_phalconry_mvc_applicationawareinterface_setapplication)
	PHP_ABSTRACT_ME(Phalconry_Mvc_ApplicationAwareInterface, getApplication, NULL)
	PHP_FE_END
};
