
extern zend_class_entry *phalconry_mvc_application_ce;

ZEPHIR_INIT_CLASS(Phalconry_Mvc_Application);

PHP_METHOD(Phalconry_Mvc_Application, __construct);
PHP_METHOD(Phalconry_Mvc_Application, setDI);
PHP_METHOD(Phalconry_Mvc_Application, getDI);
PHP_METHOD(Phalconry_Mvc_Application, setEventsManager);
PHP_METHOD(Phalconry_Mvc_Application, getEventsManager);
PHP_METHOD(Phalconry_Mvc_Application, getModuleManager);
PHP_METHOD(Phalconry_Mvc_Application, getPrimaryModule);
PHP_METHOD(Phalconry_Mvc_Application, getDispatcher);
PHP_METHOD(Phalconry_Mvc_Application, getEnvironment);
PHP_METHOD(Phalconry_Mvc_Application, getConfig);
PHP_METHOD(Phalconry_Mvc_Application, env);
PHP_METHOD(Phalconry_Mvc_Application, getPath);
PHP_METHOD(Phalconry_Mvc_Application, setPath);
PHP_METHOD(Phalconry_Mvc_Application, setBootstrap);
PHP_METHOD(Phalconry_Mvc_Application, setHandler);
PHP_METHOD(Phalconry_Mvc_Application, isBooted);
PHP_METHOD(Phalconry_Mvc_Application, loadService);
PHP_METHOD(Phalconry_Mvc_Application, loadServices);
PHP_METHOD(Phalconry_Mvc_Application, run);
PHP_METHOD(Phalconry_Mvc_Application, bootstrap);
PHP_METHOD(Phalconry_Mvc_Application, handle);
PHP_METHOD(Phalconry_Mvc_Application, respond);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconry_mvc_application___construct, 0, 0, 0)
	ZEND_ARG_OBJ_INFO(0, di, Phalcon\\DiInterface, 1)
	ZEND_ARG_OBJ_INFO(0, env, Phalconry\\Mvc\\EnvironmentInterface, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconry_mvc_application_setdi, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, dependencyInjector, Phalcon\\DiInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconry_mvc_application_seteventsmanager, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, eventsManager, Phalcon\\Events\\ManagerInterface, 0)
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

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconry_mvc_application_setbootstrap, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, bootstrap, Phalconry\\Mvc\\Application\\BootstrapInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconry_mvc_application_sethandler, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, handler, Phalconry\\Mvc\\Application\\HandlerInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconry_mvc_application_loadservice, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, provider, Phalconry\\Di\\ServiceProviderInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconry_mvc_application_loadservices, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, providers, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconry_mvc_application_handle, 0, 0, 0)
	ZEND_ARG_INFO(0, uri)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconry_mvc_application_respond, 0, 0, 0)
	ZEND_ARG_INFO(0, response)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalconry_mvc_application_method_entry) {
	PHP_ME(Phalconry_Mvc_Application, __construct, arginfo_phalconry_mvc_application___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalconry_Mvc_Application, setDI, arginfo_phalconry_mvc_application_setdi, ZEND_ACC_PUBLIC)
	PHP_ME(Phalconry_Mvc_Application, getDI, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalconry_Mvc_Application, setEventsManager, arginfo_phalconry_mvc_application_seteventsmanager, ZEND_ACC_PUBLIC)
	PHP_ME(Phalconry_Mvc_Application, getEventsManager, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalconry_Mvc_Application, getModuleManager, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalconry_Mvc_Application, getPrimaryModule, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalconry_Mvc_Application, getDispatcher, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalconry_Mvc_Application, getEnvironment, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalconry_Mvc_Application, getConfig, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalconry_Mvc_Application, env, arginfo_phalconry_mvc_application_env, ZEND_ACC_PUBLIC)
	PHP_ME(Phalconry_Mvc_Application, getPath, arginfo_phalconry_mvc_application_getpath, ZEND_ACC_PUBLIC)
	PHP_ME(Phalconry_Mvc_Application, setPath, arginfo_phalconry_mvc_application_setpath, ZEND_ACC_PUBLIC)
	PHP_ME(Phalconry_Mvc_Application, setBootstrap, arginfo_phalconry_mvc_application_setbootstrap, ZEND_ACC_PUBLIC)
	PHP_ME(Phalconry_Mvc_Application, setHandler, arginfo_phalconry_mvc_application_sethandler, ZEND_ACC_PUBLIC)
	PHP_ME(Phalconry_Mvc_Application, isBooted, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalconry_Mvc_Application, loadService, arginfo_phalconry_mvc_application_loadservice, ZEND_ACC_PUBLIC)
	PHP_ME(Phalconry_Mvc_Application, loadServices, arginfo_phalconry_mvc_application_loadservices, ZEND_ACC_PUBLIC)
	PHP_ME(Phalconry_Mvc_Application, run, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalconry_Mvc_Application, bootstrap, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalconry_Mvc_Application, handle, arginfo_phalconry_mvc_application_handle, ZEND_ACC_PUBLIC)
	PHP_ME(Phalconry_Mvc_Application, respond, arginfo_phalconry_mvc_application_respond, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
