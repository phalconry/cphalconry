
extern zend_class_entry *phalconry_mvc_applicationinterface_ce;

ZEPHIR_INIT_CLASS(Phalconry_Mvc_ApplicationInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconry_mvc_applicationinterface_setbootstrap, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, bootstrap, Phalconry\\Mvc\\Application\\BootstrapInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconry_mvc_applicationinterface_sethandler, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, handler, Phalconry\\Mvc\\Application\\HandlerInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconry_mvc_applicationinterface_env, 0, 0, 0)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconry_mvc_applicationinterface_loadservice, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, provider, Phalconry\\Di\\ServiceProviderInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconry_mvc_applicationinterface_loadservices, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, providers, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconry_mvc_applicationinterface_handle, 0, 0, 0)
	ZEND_ARG_INFO(0, uri)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconry_mvc_applicationinterface_respond, 0, 0, 0)
	ZEND_ARG_INFO(0, response)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalconry_mvc_applicationinterface_method_entry) {
	PHP_ABSTRACT_ME(Phalconry_Mvc_ApplicationInterface, setBootstrap, arginfo_phalconry_mvc_applicationinterface_setbootstrap)
	PHP_ABSTRACT_ME(Phalconry_Mvc_ApplicationInterface, setHandler, arginfo_phalconry_mvc_applicationinterface_sethandler)
	PHP_ABSTRACT_ME(Phalconry_Mvc_ApplicationInterface, env, arginfo_phalconry_mvc_applicationinterface_env)
	PHP_ABSTRACT_ME(Phalconry_Mvc_ApplicationInterface, getEnvironment, NULL)
	PHP_ABSTRACT_ME(Phalconry_Mvc_ApplicationInterface, getConfig, NULL)
	PHP_ABSTRACT_ME(Phalconry_Mvc_ApplicationInterface, getModuleManager, NULL)
	PHP_ABSTRACT_ME(Phalconry_Mvc_ApplicationInterface, getPrimaryModule, NULL)
	PHP_ABSTRACT_ME(Phalconry_Mvc_ApplicationInterface, getDispatcher, NULL)
	PHP_ABSTRACT_ME(Phalconry_Mvc_ApplicationInterface, loadService, arginfo_phalconry_mvc_applicationinterface_loadservice)
	PHP_ABSTRACT_ME(Phalconry_Mvc_ApplicationInterface, loadServices, arginfo_phalconry_mvc_applicationinterface_loadservices)
	PHP_ABSTRACT_ME(Phalconry_Mvc_ApplicationInterface, bootstrap, NULL)
	PHP_ABSTRACT_ME(Phalconry_Mvc_ApplicationInterface, handle, arginfo_phalconry_mvc_applicationinterface_handle)
	PHP_ABSTRACT_ME(Phalconry_Mvc_ApplicationInterface, respond, arginfo_phalconry_mvc_applicationinterface_respond)
	PHP_ABSTRACT_ME(Phalconry_Mvc_ApplicationInterface, isBooted, NULL)
	PHP_FE_END
};
