
extern zend_class_entry *phalconry_arrayobject_ce;

ZEPHIR_INIT_CLASS(Phalconry_ArrayObject);

PHP_METHOD(Phalconry_ArrayObject, __construct);
PHP_METHOD(Phalconry_ArrayObject, __call);
PHP_METHOD(Phalconry_ArrayObject, jsonSerialize);
PHP_METHOD(Phalconry_ArrayObject, toArray);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconry_arrayobject___construct, 0, 0, 0)
	ZEND_ARG_INFO(0, input)
	ZEND_ARG_INFO(0, flags)
	ZEND_ARG_INFO(0, iterator_class)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconry_arrayobject___call, 0, 0, 2)
	ZEND_ARG_INFO(0, func)
	ZEND_ARG_INFO(0, args)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalconry_arrayobject_method_entry) {
	PHP_ME(Phalconry_ArrayObject, __construct, arginfo_phalconry_arrayobject___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalconry_ArrayObject, __call, arginfo_phalconry_arrayobject___call, ZEND_ACC_PUBLIC)
	PHP_ME(Phalconry_ArrayObject, jsonSerialize, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalconry_ArrayObject, toArray, NULL, ZEND_ACC_PUBLIC)
  PHP_FE_END
};
