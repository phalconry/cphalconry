
extern zend_class_entry *phalconry_bundle_providerinterface_ce;

ZEPHIR_INIT_CLASS(Phalconry_Bundle_ProviderInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconry_bundle_providerinterface_providebundle, 0, 0, 2)
	ZEND_ARG_INFO(0, type)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalconry_bundle_providerinterface_method_entry) {
	PHP_ABSTRACT_ME(Phalconry_Bundle_ProviderInterface, provideBundle, arginfo_phalconry_bundle_providerinterface_providebundle)
	PHP_ABSTRACT_ME(Phalconry_Bundle_ProviderInterface, getProvided, NULL)
  PHP_FE_END
};
