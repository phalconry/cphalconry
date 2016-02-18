
extern zend_class_entry *phalconry_mvc_hmvc_request_ce;

ZEPHIR_INIT_CLASS(Phalconry_Mvc_Hmvc_Request);

PHP_METHOD(Phalconry_Mvc_Hmvc_Request, __construct);
PHP_METHOD(Phalconry_Mvc_Hmvc_Request, setLocation);
PHP_METHOD(Phalconry_Mvc_Hmvc_Request, setModuleName);
PHP_METHOD(Phalconry_Mvc_Hmvc_Request, hasModuleName);
PHP_METHOD(Phalconry_Mvc_Hmvc_Request, getModuleName);
PHP_METHOD(Phalconry_Mvc_Hmvc_Request, setControllerName);
PHP_METHOD(Phalconry_Mvc_Hmvc_Request, hasControllerName);
PHP_METHOD(Phalconry_Mvc_Hmvc_Request, getControllerName);
PHP_METHOD(Phalconry_Mvc_Hmvc_Request, setActionName);
PHP_METHOD(Phalconry_Mvc_Hmvc_Request, hasActionName);
PHP_METHOD(Phalconry_Mvc_Hmvc_Request, getActionName);
PHP_METHOD(Phalconry_Mvc_Hmvc_Request, setParams);
PHP_METHOD(Phalconry_Mvc_Hmvc_Request, hasParams);
PHP_METHOD(Phalconry_Mvc_Hmvc_Request, getParams);
PHP_METHOD(Phalconry_Mvc_Hmvc_Request, getResponse);
PHP_METHOD(Phalconry_Mvc_Hmvc_Request, __invoke);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconry_mvc_hmvc_request___construct, 0, 0, 0)
	ZEND_ARG_ARRAY_INFO(0, args, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconry_mvc_hmvc_request_setlocation, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, args, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconry_mvc_hmvc_request_setmodulename, 0, 0, 1)
	ZEND_ARG_INFO(0, module)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconry_mvc_hmvc_request_setcontrollername, 0, 0, 1)
	ZEND_ARG_INFO(0, controller)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconry_mvc_hmvc_request_setactionname, 0, 0, 1)
	ZEND_ARG_INFO(0, action)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconry_mvc_hmvc_request_setparams, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, params, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconry_mvc_hmvc_request___invoke, 0, 0, 0)
	ZEND_ARG_INFO(0, args)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalconry_mvc_hmvc_request_method_entry) {
	PHP_ME(Phalconry_Mvc_Hmvc_Request, __construct, arginfo_phalconry_mvc_hmvc_request___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalconry_Mvc_Hmvc_Request, setLocation, arginfo_phalconry_mvc_hmvc_request_setlocation, ZEND_ACC_PUBLIC)
	PHP_ME(Phalconry_Mvc_Hmvc_Request, setModuleName, arginfo_phalconry_mvc_hmvc_request_setmodulename, ZEND_ACC_PUBLIC)
	PHP_ME(Phalconry_Mvc_Hmvc_Request, hasModuleName, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalconry_Mvc_Hmvc_Request, getModuleName, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalconry_Mvc_Hmvc_Request, setControllerName, arginfo_phalconry_mvc_hmvc_request_setcontrollername, ZEND_ACC_PUBLIC)
	PHP_ME(Phalconry_Mvc_Hmvc_Request, hasControllerName, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalconry_Mvc_Hmvc_Request, getControllerName, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalconry_Mvc_Hmvc_Request, setActionName, arginfo_phalconry_mvc_hmvc_request_setactionname, ZEND_ACC_PUBLIC)
	PHP_ME(Phalconry_Mvc_Hmvc_Request, hasActionName, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalconry_Mvc_Hmvc_Request, getActionName, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalconry_Mvc_Hmvc_Request, setParams, arginfo_phalconry_mvc_hmvc_request_setparams, ZEND_ACC_PUBLIC)
	PHP_ME(Phalconry_Mvc_Hmvc_Request, hasParams, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalconry_Mvc_Hmvc_Request, getParams, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalconry_Mvc_Hmvc_Request, getResponse, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalconry_Mvc_Hmvc_Request, __invoke, arginfo_phalconry_mvc_hmvc_request___invoke, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
