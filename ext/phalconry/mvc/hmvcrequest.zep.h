
extern zend_class_entry *phalconry_mvc_hmvcrequest_ce;

ZEPHIR_INIT_CLASS(Phalconry_Mvc_HmvcRequest);

PHP_METHOD(Phalconry_Mvc_HmvcRequest, __construct);
PHP_METHOD(Phalconry_Mvc_HmvcRequest, setLocation);
PHP_METHOD(Phalconry_Mvc_HmvcRequest, setModuleName);
PHP_METHOD(Phalconry_Mvc_HmvcRequest, hasModuleName);
PHP_METHOD(Phalconry_Mvc_HmvcRequest, getModuleName);
PHP_METHOD(Phalconry_Mvc_HmvcRequest, setControllerName);
PHP_METHOD(Phalconry_Mvc_HmvcRequest, hasControllerName);
PHP_METHOD(Phalconry_Mvc_HmvcRequest, getControllerName);
PHP_METHOD(Phalconry_Mvc_HmvcRequest, setActionName);
PHP_METHOD(Phalconry_Mvc_HmvcRequest, hasActionName);
PHP_METHOD(Phalconry_Mvc_HmvcRequest, getActionName);
PHP_METHOD(Phalconry_Mvc_HmvcRequest, setParams);
PHP_METHOD(Phalconry_Mvc_HmvcRequest, hasParams);
PHP_METHOD(Phalconry_Mvc_HmvcRequest, getParams);
PHP_METHOD(Phalconry_Mvc_HmvcRequest, __invoke);
PHP_METHOD(Phalconry_Mvc_HmvcRequest, getResponse);
PHP_METHOD(Phalconry_Mvc_HmvcRequest, getDispatcher);
PHP_METHOD(Phalconry_Mvc_HmvcRequest, prepareModuleForDispatch);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconry_mvc_hmvcrequest___construct, 0, 0, 0)
	ZEND_ARG_ARRAY_INFO(0, args, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconry_mvc_hmvcrequest_setlocation, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, args, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconry_mvc_hmvcrequest_setmodulename, 0, 0, 1)
	ZEND_ARG_INFO(0, module)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconry_mvc_hmvcrequest_setcontrollername, 0, 0, 1)
	ZEND_ARG_INFO(0, controller)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconry_mvc_hmvcrequest_setactionname, 0, 0, 1)
	ZEND_ARG_INFO(0, action)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconry_mvc_hmvcrequest_setparams, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, params, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconry_mvc_hmvcrequest___invoke, 0, 0, 0)
	ZEND_ARG_INFO(0, args)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconry_mvc_hmvcrequest_preparemodulefordispatch, 0, 0, 2)
	ZEND_ARG_OBJ_INFO(0, dispatcher, Phalcon\\Mvc\\Dispatcher, 0)
	ZEND_ARG_INFO(0, moduleName)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalconry_mvc_hmvcrequest_method_entry) {
	PHP_ME(Phalconry_Mvc_HmvcRequest, __construct, arginfo_phalconry_mvc_hmvcrequest___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalconry_Mvc_HmvcRequest, setLocation, arginfo_phalconry_mvc_hmvcrequest_setlocation, ZEND_ACC_PUBLIC)
	PHP_ME(Phalconry_Mvc_HmvcRequest, setModuleName, arginfo_phalconry_mvc_hmvcrequest_setmodulename, ZEND_ACC_PUBLIC)
	PHP_ME(Phalconry_Mvc_HmvcRequest, hasModuleName, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalconry_Mvc_HmvcRequest, getModuleName, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalconry_Mvc_HmvcRequest, setControllerName, arginfo_phalconry_mvc_hmvcrequest_setcontrollername, ZEND_ACC_PUBLIC)
	PHP_ME(Phalconry_Mvc_HmvcRequest, hasControllerName, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalconry_Mvc_HmvcRequest, getControllerName, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalconry_Mvc_HmvcRequest, setActionName, arginfo_phalconry_mvc_hmvcrequest_setactionname, ZEND_ACC_PUBLIC)
	PHP_ME(Phalconry_Mvc_HmvcRequest, hasActionName, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalconry_Mvc_HmvcRequest, getActionName, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalconry_Mvc_HmvcRequest, setParams, arginfo_phalconry_mvc_hmvcrequest_setparams, ZEND_ACC_PUBLIC)
	PHP_ME(Phalconry_Mvc_HmvcRequest, hasParams, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalconry_Mvc_HmvcRequest, getParams, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalconry_Mvc_HmvcRequest, __invoke, arginfo_phalconry_mvc_hmvcrequest___invoke, ZEND_ACC_PUBLIC)
	PHP_ME(Phalconry_Mvc_HmvcRequest, getResponse, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalconry_Mvc_HmvcRequest, getDispatcher, NULL, ZEND_ACC_PROTECTED)
	PHP_ME(Phalconry_Mvc_HmvcRequest, prepareModuleForDispatch, arginfo_phalconry_mvc_hmvcrequest_preparemodulefordispatch, ZEND_ACC_PROTECTED)
  PHP_FE_END
};
