
extern zend_class_entry *phalconry_bundle_bundle_ce;

ZEPHIR_INIT_CLASS(Phalconry_Bundle_Bundle);

PHP_METHOD(Phalconry_Bundle_Bundle, setDI);
PHP_METHOD(Phalconry_Bundle_Bundle, getDI);
PHP_METHOD(Phalconry_Bundle_Bundle, getOverrides);
PHP_METHOD(Phalconry_Bundle_Bundle, getDependencies);
PHP_METHOD(Phalconry_Bundle_Bundle, getIdentifier);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconry_bundle_bundle_setdi, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, dependencyInjector, Phalcon\\DiInterface, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalconry_bundle_bundle_method_entry) {
	PHP_ME(Phalconry_Bundle_Bundle, setDI, arginfo_phalconry_bundle_bundle_setdi, ZEND_ACC_PUBLIC)
	PHP_ME(Phalconry_Bundle_Bundle, getDI, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalconry_Bundle_Bundle, getOverrides, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalconry_Bundle_Bundle, getDependencies, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalconry_Bundle_Bundle, getIdentifier, NULL, ZEND_ACC_PUBLIC)
  PHP_FE_END
};
