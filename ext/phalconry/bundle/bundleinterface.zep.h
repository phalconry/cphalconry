
extern zend_class_entry *phalconry_bundle_bundleinterface_ce;

ZEPHIR_INIT_CLASS(Phalconry_Bundle_BundleInterface);

ZEPHIR_INIT_FUNCS(phalconry_bundle_bundleinterface_method_entry) {
	PHP_ABSTRACT_ME(Phalconry_Bundle_BundleInterface, boot, NULL)
	PHP_ABSTRACT_ME(Phalconry_Bundle_BundleInterface, shutdown, NULL)
	PHP_ABSTRACT_ME(Phalconry_Bundle_BundleInterface, isBooted, NULL)
	PHP_ABSTRACT_ME(Phalconry_Bundle_BundleInterface, getOverrides, NULL)
	PHP_ABSTRACT_ME(Phalconry_Bundle_BundleInterface, getDependencies, NULL)
	PHP_ABSTRACT_ME(Phalconry_Bundle_BundleInterface, getBundleType, NULL)
	PHP_ABSTRACT_ME(Phalconry_Bundle_BundleInterface, getName, NULL)
	PHP_ABSTRACT_ME(Phalconry_Bundle_BundleInterface, getIdentifier, NULL)
  PHP_FE_END
};
