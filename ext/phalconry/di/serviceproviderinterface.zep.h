
extern zend_class_entry *phalconry_di_serviceproviderinterface_ce;

ZEPHIR_INIT_CLASS(Phalconry_Di_ServiceProviderInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconry_di_serviceproviderinterface_register, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, di, Phalcon\\DiInterface, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalconry_di_serviceproviderinterface_method_entry) {
	PHP_ABSTRACT_ME(Phalconry_Di_ServiceProviderInterface, register, arginfo_phalconry_di_serviceproviderinterface_register)
	PHP_FE_END
};
