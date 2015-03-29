
extern zend_class_entry *phalconry_mvc_application_ce;

ZEPHIR_INIT_CLASS(Phalconry_Mvc_Application);

PHP_METHOD(Phalconry_Mvc_Application, __construct);
PHP_METHOD(Phalconry_Mvc_Application, env);
PHP_METHOD(Phalconry_Mvc_Application, getPath);
PHP_METHOD(Phalconry_Mvc_Application, setPath);
PHP_METHOD(Phalconry_Mvc_Application, getModuleObject);
PHP_METHOD(Phalconry_Mvc_Application, getResponder);
PHP_METHOD(Phalconry_Mvc_Application, setResponseType);
PHP_METHOD(Phalconry_Mvc_Application, getResponseType);
PHP_METHOD(Phalconry_Mvc_Application, run);
PHP_METHOD(Phalconry_Mvc_Application, setDefaultServices);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconry_mvc_application___construct, 0, 0, 0)
	ZEND_ARG_OBJ_INFO(0, di, Phalcon\\DiInterface, 1)
	ZEND_ARG_OBJ_INFO(0, env, Phalconry\\Mvc\\Env, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconry_mvc_application_env, 0, 0, 0)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconry_mvc_application_getpath, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconry_mvc_application_setpath, 0, 0, 2)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconry_mvc_application_getmoduleobject, 0, 0, 0)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconry_mvc_application_setresponsetype, 0, 0, 1)
	ZEND_ARG_INFO(0, responseType)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconry_mvc_application_setdefaultservices, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, di, Phalcon\\DiInterface, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalconry_mvc_application_method_entry) {
	PHP_ME(Phalconry_Mvc_Application, __construct, arginfo_phalconry_mvc_application___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalconry_Mvc_Application, env, arginfo_phalconry_mvc_application_env, ZEND_ACC_PUBLIC)
	PHP_ME(Phalconry_Mvc_Application, getPath, arginfo_phalconry_mvc_application_getpath, ZEND_ACC_PUBLIC)
	PHP_ME(Phalconry_Mvc_Application, setPath, arginfo_phalconry_mvc_application_setpath, ZEND_ACC_PUBLIC)
	PHP_ME(Phalconry_Mvc_Application, getModuleObject, arginfo_phalconry_mvc_application_getmoduleobject, ZEND_ACC_PUBLIC)
	PHP_ME(Phalconry_Mvc_Application, getResponder, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalconry_Mvc_Application, setResponseType, arginfo_phalconry_mvc_application_setresponsetype, ZEND_ACC_PUBLIC)
	PHP_ME(Phalconry_Mvc_Application, getResponseType, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalconry_Mvc_Application, run, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalconry_Mvc_Application, setDefaultServices, arginfo_phalconry_mvc_application_setdefaultservices, ZEND_ACC_PUBLIC)
  PHP_FE_END
};
