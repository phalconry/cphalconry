
extern zend_class_entry *phalconry_config_ce;

ZEPHIR_INIT_CLASS(Phalconry_Config);

PHP_METHOD(Phalconry_Config, setParent);
PHP_METHOD(Phalconry_Config, getParent);
PHP_METHOD(Phalconry_Config, hasParent);
PHP_METHOD(Phalconry_Config, offsetSet);
PHP_METHOD(Phalconry_Config, getConfig);
PHP_METHOD(Phalconry_Config, get);
PHP_METHOD(Phalconry_Config, set);
PHP_METHOD(Phalconry_Config, has);
PHP_METHOD(Phalconry_Config, __set_state);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconry_config_setparent, 0, 0, 1)
	ZEND_ARG_INFO(0, parentObject)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconry_config_offsetset, 0, 0, 2)
	ZEND_ARG_INFO(0, index)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconry_config_getconfig, 0, 0, 1)
	ZEND_ARG_INFO(0, section)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconry_config_get, 0, 0, 1)
	ZEND_ARG_INFO(0, key)
	ZEND_ARG_INFO(0, defaultValue)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconry_config_set, 0, 0, 2)
	ZEND_ARG_INFO(0, key)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconry_config_has, 0, 0, 1)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconry_config___set_state, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, data, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalconry_config_method_entry) {
	PHP_ME(Phalconry_Config, setParent, arginfo_phalconry_config_setparent, ZEND_ACC_PUBLIC)
	PHP_ME(Phalconry_Config, getParent, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalconry_Config, hasParent, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalconry_Config, offsetSet, arginfo_phalconry_config_offsetset, ZEND_ACC_PUBLIC)
	PHP_ME(Phalconry_Config, getConfig, arginfo_phalconry_config_getconfig, ZEND_ACC_PUBLIC)
	PHP_ME(Phalconry_Config, get, arginfo_phalconry_config_get, ZEND_ACC_PUBLIC)
	PHP_ME(Phalconry_Config, set, arginfo_phalconry_config_set, ZEND_ACC_PUBLIC)
	PHP_ME(Phalconry_Config, has, arginfo_phalconry_config_has, ZEND_ACC_PUBLIC)
	PHP_ME(Phalconry_Config, __set_state, arginfo_phalconry_config___set_state, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};
