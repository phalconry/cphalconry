
extern zend_class_entry *phalconry_mvc_application_ce;

ZEPHIR_INIT_CLASS(Phalconry_Mvc_Application);

PHP_METHOD(Phalconry_Mvc_Application, __construct);
PHP_METHOD(Phalconry_Mvc_Application, getPath);
PHP_METHOD(Phalconry_Mvc_Application, setPath);
PHP_METHOD(Phalconry_Mvc_Application, getModuleName);
PHP_METHOD(Phalconry_Mvc_Application, getModule);
PHP_METHOD(Phalconry_Mvc_Application, setModule);
PHP_METHOD(Phalconry_Mvc_Application, loadModule);
PHP_METHOD(Phalconry_Mvc_Application, isModuleLoaded);
PHP_METHOD(Phalconry_Mvc_Application, getPrimaryModuleName);
PHP_METHOD(Phalconry_Mvc_Application, getPrimaryModule);
PHP_METHOD(Phalconry_Mvc_Application, getResponder);
PHP_METHOD(Phalconry_Mvc_Application, setResponseType);
PHP_METHOD(Phalconry_Mvc_Application, getResponseType);
PHP_METHOD(Phalconry_Mvc_Application, run);
PHP_METHOD(Phalconry_Mvc_Application, boot);
PHP_METHOD(Phalconry_Mvc_Application, afterStartModule);
PHP_METHOD(Phalconry_Mvc_Application, afterHandleRequest);
PHP_METHOD(Phalconry_Mvc_Application, _registerAutoloaders);
PHP_METHOD(Phalconry_Mvc_Application, _registerServices);
PHP_METHOD(Phalconry_Mvc_Application, _registerModules);
PHP_METHOD(Phalconry_Mvc_Application, setDefaultServices);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconry_mvc_application___construct, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, env, Phalconry\\Mvc\\Env, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconry_mvc_application_getpath, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconry_mvc_application_setpath, 0, 0, 2)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconry_mvc_application_getmodulename, 0, 0, 0)
	ZEND_ARG_OBJ_INFO(0, module, Phalconry\\Mvc\\Module, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconry_mvc_application_getmodule, 0, 0, 0)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconry_mvc_application_setmodule, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, module, Phalconry\\Mvc\\Module, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconry_mvc_application_loadmodule, 0, 0, 1)
	ZEND_ARG_INFO(0, module)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconry_mvc_application_ismoduleloaded, 0, 0, 1)
	ZEND_ARG_INFO(0, module)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconry_mvc_application_setresponsetype, 0, 0, 1)
	ZEND_ARG_INFO(0, type)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconry_mvc_application_boot, 0, 0, 3)
	ZEND_ARG_OBJ_INFO(0, event, Phalcon\\Events\\Event, 0)
	ZEND_ARG_OBJ_INFO(0, app, Phalcon\\Mvc\\Application, 0)
	ZEND_ARG_INFO(0, nothing)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconry_mvc_application_afterstartmodule, 0, 0, 3)
	ZEND_ARG_OBJ_INFO(0, event, Phalcon\\Events\\Event, 0)
	ZEND_ARG_OBJ_INFO(0, app, Phalcon\\Mvc\\Application, 0)
	ZEND_ARG_INFO(0, moduleName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconry_mvc_application_afterhandlerequest, 0, 0, 3)
	ZEND_ARG_OBJ_INFO(0, event, Phalcon\\Events\\Event, 0)
	ZEND_ARG_INFO(0, app)
	ZEND_ARG_INFO(0, moduleName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconry_mvc_application__registerautoloaders, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, env, Phalconry\\Mvc\\Env, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconry_mvc_application__registerservices, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, env, Phalconry\\Mvc\\Env, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconry_mvc_application__registermodules, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, env, Phalconry\\Mvc\\Env, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconry_mvc_application_setdefaultservices, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, di, Phalcon\\DiInterface, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalconry_mvc_application_method_entry) {
	PHP_ME(Phalconry_Mvc_Application, __construct, arginfo_phalconry_mvc_application___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalconry_Mvc_Application, getPath, arginfo_phalconry_mvc_application_getpath, ZEND_ACC_PUBLIC)
	PHP_ME(Phalconry_Mvc_Application, setPath, arginfo_phalconry_mvc_application_setpath, ZEND_ACC_PUBLIC)
	PHP_ME(Phalconry_Mvc_Application, getModuleName, arginfo_phalconry_mvc_application_getmodulename, ZEND_ACC_PUBLIC)
	PHP_ME(Phalconry_Mvc_Application, getModule, arginfo_phalconry_mvc_application_getmodule, ZEND_ACC_PUBLIC)
	PHP_ME(Phalconry_Mvc_Application, setModule, arginfo_phalconry_mvc_application_setmodule, ZEND_ACC_PUBLIC)
	PHP_ME(Phalconry_Mvc_Application, loadModule, arginfo_phalconry_mvc_application_loadmodule, ZEND_ACC_PUBLIC)
	PHP_ME(Phalconry_Mvc_Application, isModuleLoaded, arginfo_phalconry_mvc_application_ismoduleloaded, ZEND_ACC_PUBLIC)
	PHP_ME(Phalconry_Mvc_Application, getPrimaryModuleName, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalconry_Mvc_Application, getPrimaryModule, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalconry_Mvc_Application, getResponder, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalconry_Mvc_Application, setResponseType, arginfo_phalconry_mvc_application_setresponsetype, ZEND_ACC_PUBLIC)
	PHP_ME(Phalconry_Mvc_Application, getResponseType, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalconry_Mvc_Application, run, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalconry_Mvc_Application, boot, arginfo_phalconry_mvc_application_boot, ZEND_ACC_PUBLIC)
	PHP_ME(Phalconry_Mvc_Application, afterStartModule, arginfo_phalconry_mvc_application_afterstartmodule, ZEND_ACC_PUBLIC)
	PHP_ME(Phalconry_Mvc_Application, afterHandleRequest, arginfo_phalconry_mvc_application_afterhandlerequest, ZEND_ACC_PUBLIC)
	PHP_ME(Phalconry_Mvc_Application, _registerAutoloaders, arginfo_phalconry_mvc_application__registerautoloaders, ZEND_ACC_PROTECTED)
	PHP_ME(Phalconry_Mvc_Application, _registerServices, arginfo_phalconry_mvc_application__registerservices, ZEND_ACC_PROTECTED)
	PHP_ME(Phalconry_Mvc_Application, _registerModules, arginfo_phalconry_mvc_application__registermodules, ZEND_ACC_PROTECTED)
	PHP_ME(Phalconry_Mvc_Application, setDefaultServices, arginfo_phalconry_mvc_application_setdefaultservices, ZEND_ACC_PROTECTED)
  PHP_FE_END
};
