
extern zend_class_entry *phalconry_webservice_service_ce;

ZEPHIR_INIT_CLASS(Phalconry_WebService_Service);

PHP_METHOD(Phalconry_WebService_Service, getClient);
PHP_METHOD(Phalconry_WebService_Service, createRequest);
PHP_METHOD(Phalconry_WebService_Service, send);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconry_webservice_service_createrequest, 0, 0, 0)
	ZEND_ARG_INFO(0, url)
	ZEND_ARG_INFO(0, method)
	ZEND_ARG_ARRAY_INFO(0, headers, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconry_webservice_service_send, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, request, Phalconry\\Http\\Client\\Request, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalconry_webservice_service_method_entry) {
	PHP_ME(Phalconry_WebService_Service, getClient, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalconry_WebService_Service, createRequest, arginfo_phalconry_webservice_service_createrequest, ZEND_ACC_PUBLIC)
	PHP_ME(Phalconry_WebService_Service, send, arginfo_phalconry_webservice_service_send, ZEND_ACC_PUBLIC)
  PHP_FE_END
};
