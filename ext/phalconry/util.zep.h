
extern zend_class_entry *phalconry_util_ce;

ZEPHIR_INIT_CLASS(Phalconry_Util);

PHP_METHOD(Phalconry_Util, toArray);
PHP_METHOD(Phalconry_Util, toObject);
PHP_METHOD(Phalconry_Util, isJson);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconry_util_toarray, 0, 0, 1)
	ZEND_ARG_INFO(0, arg)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconry_util_toobject, 0, 0, 1)
	ZEND_ARG_INFO(0, arg)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconry_util_isjson, 0, 0, 1)
	ZEND_ARG_INFO(0, arg)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalconry_util_method_entry) {
	PHP_ME(Phalconry_Util, toArray, arginfo_phalconry_util_toarray, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalconry_Util, toObject, arginfo_phalconry_util_toobject, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalconry_Util, isJson, arginfo_phalconry_util_isjson, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
  PHP_FE_END
};
