
extern zend_class_entry *phalconry_mvc_plugin_ce;

ZEPHIR_INIT_CLASS(Phalconry_Mvc_Plugin);

PHP_METHOD(Phalconry_Mvc_Plugin, getName);
PHP_METHOD(Phalconry_Mvc_Plugin, getPath);
PHP_METHOD(Phalconry_Mvc_Plugin, setManager);
PHP_METHOD(Phalconry_Mvc_Plugin, getManager);
PHP_METHOD(Phalconry_Mvc_Plugin, getConfig);
PHP_METHOD(Phalconry_Mvc_Plugin, isLoaded);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconry_mvc_plugin_setmanager, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, manager, Phalconry\\Mvc\\Plugin\\ManagerInterface, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalconry_mvc_plugin_method_entry) {
	PHP_ME(Phalconry_Mvc_Plugin, getName, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalconry_Mvc_Plugin, getPath, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalconry_Mvc_Plugin, setManager, arginfo_phalconry_mvc_plugin_setmanager, ZEND_ACC_PUBLIC)
	PHP_ME(Phalconry_Mvc_Plugin, getManager, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalconry_Mvc_Plugin, getConfig, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalconry_Mvc_Plugin, isLoaded, NULL, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
