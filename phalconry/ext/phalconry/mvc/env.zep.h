
extern zend_class_entry *phalconry_mvc_env_ce;

ZEPHIR_INIT_CLASS(Phalconry_Mvc_Env);

PHP_METHOD(Phalconry_Mvc_Env, __construct);
PHP_METHOD(Phalconry_Mvc_Env, setPaths);
PHP_METHOD(Phalconry_Mvc_Env, getPaths);
PHP_METHOD(Phalconry_Mvc_Env, setPath);
PHP_METHOD(Phalconry_Mvc_Env, getPath);
PHP_METHOD(Phalconry_Mvc_Env, getFrom);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconry_mvc_env___construct, 0, 0, 0)
	ZEND_ARG_ARRAY_INFO(0, config, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconry_mvc_env_setpaths, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, paths, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconry_mvc_env_setpath, 0, 0, 2)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, path)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconry_mvc_env_getpath, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconry_mvc_env_getfrom, 0, 0, 2)
	ZEND_ARG_INFO(0, section)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalconry_mvc_env_method_entry) {
	PHP_ME(Phalconry_Mvc_Env, __construct, arginfo_phalconry_mvc_env___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalconry_Mvc_Env, setPaths, arginfo_phalconry_mvc_env_setpaths, ZEND_ACC_PUBLIC)
	PHP_ME(Phalconry_Mvc_Env, getPaths, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalconry_Mvc_Env, setPath, arginfo_phalconry_mvc_env_setpath, ZEND_ACC_PUBLIC)
	PHP_ME(Phalconry_Mvc_Env, getPath, arginfo_phalconry_mvc_env_getpath, ZEND_ACC_PUBLIC)
	PHP_ME(Phalconry_Mvc_Env, getFrom, arginfo_phalconry_mvc_env_getfrom, ZEND_ACC_PUBLIC)
  PHP_FE_END
};
