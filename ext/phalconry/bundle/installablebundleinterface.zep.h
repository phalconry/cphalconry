
extern zend_class_entry *phalconry_bundle_installablebundleinterface_ce;

ZEPHIR_INIT_CLASS(Phalconry_Bundle_InstallableBundleInterface);

ZEPHIR_INIT_FUNCS(phalconry_bundle_installablebundleinterface_method_entry) {
	PHP_ABSTRACT_ME(Phalconry_Bundle_InstallableBundleInterface, isInstalled, NULL)
	PHP_ABSTRACT_ME(Phalconry_Bundle_InstallableBundleInterface, install, NULL)
	PHP_ABSTRACT_ME(Phalconry_Bundle_InstallableBundleInterface, uninstall, NULL)
  PHP_FE_END
};