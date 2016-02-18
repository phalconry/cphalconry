
extern zend_class_entry *phalconry_webservice_factory_ce;

ZEPHIR_INIT_CLASS(Phalconry_WebService_Factory);

PHP_METHOD(Phalconry_WebService_Factory, create);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconry_webservice_factory_create, 0, 0, 1)
	ZEND_ARG_INFO(0, definition)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalconry_webservice_factory_method_entry) {
	PHP_ME(Phalconry_WebService_Factory, create, arginfo_phalconry_webservice_factory_create, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
