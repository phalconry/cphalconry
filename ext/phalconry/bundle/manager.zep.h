
extern zend_class_entry *phalconry_bundle_manager_ce;

ZEPHIR_INIT_CLASS(Phalconry_Bundle_Manager);

PHP_METHOD(Phalconry_Bundle_Manager, provide);
PHP_METHOD(Phalconry_Bundle_Manager, provideType);
PHP_METHOD(Phalconry_Bundle_Manager, provideBundle);
PHP_METHOD(Phalconry_Bundle_Manager, provideMultiple);
PHP_METHOD(Phalconry_Bundle_Manager, setBundle);
PHP_METHOD(Phalconry_Bundle_Manager, getBundle);
PHP_METHOD(Phalconry_Bundle_Manager, getBootedBundle);
PHP_METHOD(Phalconry_Bundle_Manager, exists);
PHP_METHOD(Phalconry_Bundle_Manager, isBooted);
PHP_METHOD(Phalconry_Bundle_Manager, boot);
PHP_METHOD(Phalconry_Bundle_Manager, shutdown);
PHP_METHOD(Phalconry_Bundle_Manager, getProviderFor);
PHP_METHOD(Phalconry_Bundle_Manager, setBundleFromProvider);
PHP_METHOD(Phalconry_Bundle_Manager, bootDependencies);
PHP_METHOD(Phalconry_Bundle_Manager, shutdownOverrides);
PHP_METHOD(Phalconry_Bundle_Manager, __construct);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconry_bundle_manager_provide, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, provider, Phalconry\\Bundle\\ProviderInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconry_bundle_manager_providetype, 0, 0, 2)
	ZEND_ARG_INFO(0, bundleType)
	ZEND_ARG_INFO(0, provider)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconry_bundle_manager_providebundle, 0, 0, 2)
	ZEND_ARG_INFO(0, bundleName)
	ZEND_ARG_INFO(0, provider)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconry_bundle_manager_providemultiple, 0, 0, 2)
	ZEND_ARG_ARRAY_INFO(0, bundles, 0)
	ZEND_ARG_INFO(0, provider)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconry_bundle_manager_setbundle, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, bundle, Phalconry\\Bundle\\BundleInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconry_bundle_manager_getbundle, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconry_bundle_manager_getbootedbundle, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconry_bundle_manager_exists, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconry_bundle_manager_isbooted, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconry_bundle_manager_boot, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconry_bundle_manager_shutdown, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconry_bundle_manager_getproviderfor, 0, 0, 2)
	ZEND_ARG_INFO(0, type)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconry_bundle_manager_setbundlefromprovider, 0, 0, 1)
	ZEND_ARG_INFO(0, id)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconry_bundle_manager_bootdependencies, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, bundle, Phalconry\\Bundle\\BundleInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconry_bundle_manager_shutdownoverrides, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, bundle, Phalconry\\Bundle\\BundleInterface, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalconry_bundle_manager_method_entry) {
	PHP_ME(Phalconry_Bundle_Manager, provide, arginfo_phalconry_bundle_manager_provide, ZEND_ACC_PUBLIC)
	PHP_ME(Phalconry_Bundle_Manager, provideType, arginfo_phalconry_bundle_manager_providetype, ZEND_ACC_PUBLIC)
	PHP_ME(Phalconry_Bundle_Manager, provideBundle, arginfo_phalconry_bundle_manager_providebundle, ZEND_ACC_PUBLIC)
	PHP_ME(Phalconry_Bundle_Manager, provideMultiple, arginfo_phalconry_bundle_manager_providemultiple, ZEND_ACC_PUBLIC)
	PHP_ME(Phalconry_Bundle_Manager, setBundle, arginfo_phalconry_bundle_manager_setbundle, ZEND_ACC_PUBLIC)
	PHP_ME(Phalconry_Bundle_Manager, getBundle, arginfo_phalconry_bundle_manager_getbundle, ZEND_ACC_PUBLIC)
	PHP_ME(Phalconry_Bundle_Manager, getBootedBundle, arginfo_phalconry_bundle_manager_getbootedbundle, ZEND_ACC_PUBLIC)
	PHP_ME(Phalconry_Bundle_Manager, exists, arginfo_phalconry_bundle_manager_exists, ZEND_ACC_PUBLIC)
	PHP_ME(Phalconry_Bundle_Manager, isBooted, arginfo_phalconry_bundle_manager_isbooted, ZEND_ACC_PUBLIC)
	PHP_ME(Phalconry_Bundle_Manager, boot, arginfo_phalconry_bundle_manager_boot, ZEND_ACC_PUBLIC)
	PHP_ME(Phalconry_Bundle_Manager, shutdown, arginfo_phalconry_bundle_manager_shutdown, ZEND_ACC_PUBLIC)
	PHP_ME(Phalconry_Bundle_Manager, getProviderFor, arginfo_phalconry_bundle_manager_getproviderfor, ZEND_ACC_PUBLIC)
	PHP_ME(Phalconry_Bundle_Manager, setBundleFromProvider, arginfo_phalconry_bundle_manager_setbundlefromprovider, ZEND_ACC_PROTECTED)
	PHP_ME(Phalconry_Bundle_Manager, bootDependencies, arginfo_phalconry_bundle_manager_bootdependencies, ZEND_ACC_PROTECTED)
	PHP_ME(Phalconry_Bundle_Manager, shutdownOverrides, arginfo_phalconry_bundle_manager_shutdownoverrides, ZEND_ACC_PROTECTED)
	PHP_ME(Phalconry_Bundle_Manager, __construct, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
  PHP_FE_END
};
