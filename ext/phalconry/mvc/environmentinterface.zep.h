
extern zend_class_entry *phalconry_mvc_environmentinterface_ce;

ZEPHIR_INIT_CLASS(Phalconry_Mvc_EnvironmentInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconry_mvc_environmentinterface_setlocale, 0, 0, 1)
	ZEND_ARG_INFO(0, locale)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconry_mvc_environmentinterface_setpaths, 0, 0, 1)
	ZEND_ARG_INFO(0, paths)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconry_mvc_environmentinterface_setpath, 0, 0, 2)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, path)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconry_mvc_environmentinterface_getpath, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconry_mvc_environmentinterface_getconfig, 0, 0, 1)
	ZEND_ARG_INFO(0, section)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconry_mvc_environmentinterface_get, 0, 0, 1)
	ZEND_ARG_INFO(0, key)
	ZEND_ARG_INFO(0, defaultValue)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconry_mvc_environmentinterface_set, 0, 0, 2)
	ZEND_ARG_INFO(0, key)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconry_mvc_environmentinterface_has, 0, 0, 1)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalconry_mvc_environmentinterface_method_entry) {
	PHP_ABSTRACT_ME(Phalconry_Mvc_EnvironmentInterface, isCli, NULL)
	PHP_ABSTRACT_ME(Phalconry_Mvc_EnvironmentInterface, getEnvironment, NULL)
	PHP_ABSTRACT_ME(Phalconry_Mvc_EnvironmentInterface, getTimezone, NULL)
	PHP_ABSTRACT_ME(Phalconry_Mvc_EnvironmentInterface, setLocale, arginfo_phalconry_mvc_environmentinterface_setlocale)
	PHP_ABSTRACT_ME(Phalconry_Mvc_EnvironmentInterface, getLocale, NULL)
	PHP_ABSTRACT_ME(Phalconry_Mvc_EnvironmentInterface, setPaths, arginfo_phalconry_mvc_environmentinterface_setpaths)
	PHP_ABSTRACT_ME(Phalconry_Mvc_EnvironmentInterface, getPaths, NULL)
	PHP_ABSTRACT_ME(Phalconry_Mvc_EnvironmentInterface, setPath, arginfo_phalconry_mvc_environmentinterface_setpath)
	PHP_ABSTRACT_ME(Phalconry_Mvc_EnvironmentInterface, getPath, arginfo_phalconry_mvc_environmentinterface_getpath)
	PHP_ABSTRACT_ME(Phalconry_Mvc_EnvironmentInterface, getConfig, arginfo_phalconry_mvc_environmentinterface_getconfig)
	PHP_ABSTRACT_ME(Phalconry_Mvc_EnvironmentInterface, get, arginfo_phalconry_mvc_environmentinterface_get)
	PHP_ABSTRACT_ME(Phalconry_Mvc_EnvironmentInterface, set, arginfo_phalconry_mvc_environmentinterface_set)
	PHP_ABSTRACT_ME(Phalconry_Mvc_EnvironmentInterface, has, arginfo_phalconry_mvc_environmentinterface_has)
	PHP_FE_END
};
