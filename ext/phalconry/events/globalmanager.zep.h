
extern zend_class_entry *phalconry_events_globalmanager_ce;

ZEPHIR_INIT_CLASS(Phalconry_Events_GlobalManager);

PHP_METHOD(Phalconry_Events_GlobalManager, __construct);
PHP_METHOD(Phalconry_Events_GlobalManager, create);

ZEPHIR_INIT_FUNCS(phalconry_events_globalmanager_method_entry) {
	PHP_ME(Phalconry_Events_GlobalManager, __construct, NULL, ZEND_ACC_PROTECTED|ZEND_ACC_CTOR)
	PHP_ME(Phalconry_Events_GlobalManager, create, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};
