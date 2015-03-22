
extern zend_class_entry *phalconry_mvc_dispatcher_ce;

ZEPHIR_INIT_CLASS(Phalconry_Mvc_Dispatcher);

PHP_METHOD(Phalconry_Mvc_Dispatcher, setDefaultNamespace);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconry_mvc_dispatcher_setdefaultnamespace, 0, 0, 1)
	ZEND_ARG_INFO(0, namespaceName)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalconry_mvc_dispatcher_method_entry) {
	PHP_ME(Phalconry_Mvc_Dispatcher, setDefaultNamespace, arginfo_phalconry_mvc_dispatcher_setdefaultnamespace, ZEND_ACC_PUBLIC)
  PHP_FE_END
};
