
extern zend_class_entry *phalconry_http_client_ce;

ZEPHIR_INIT_CLASS(Phalconry_Http_Client);

PHP_METHOD(Phalconry_Http_Client, getAdapter);
PHP_METHOD(Phalconry_Http_Client, createHttpRequest);
PHP_METHOD(Phalconry_Http_Client, createRequest);
PHP_METHOD(Phalconry_Http_Client, send);
PHP_METHOD(Phalconry_Http_Client, getResponse);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconry_http_client_createhttprequest, 0, 0, 1)
	ZEND_ARG_INFO(0, uri)
	ZEND_ARG_INFO(0, method)
	ZEND_ARG_ARRAY_INFO(0, params, 1)
	ZEND_ARG_ARRAY_INFO(0, headers, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconry_http_client_createrequest, 0, 0, 1)
	ZEND_ARG_INFO(0, uri)
	ZEND_ARG_INFO(0, method)
	ZEND_ARG_ARRAY_INFO(0, params, 1)
	ZEND_ARG_ARRAY_INFO(0, headers, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconry_http_client_send, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, request, Phalconry\\Http\\Client\\Request, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconry_http_client_getresponse, 0, 0, 0)
	ZEND_ARG_OBJ_INFO(0, request, Phalconry\\Http\\Client\\Request, 1)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalconry_http_client_method_entry) {
	PHP_ME(Phalconry_Http_Client, getAdapter, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalconry_Http_Client, createHttpRequest, arginfo_phalconry_http_client_createhttprequest, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalconry_Http_Client, createRequest, arginfo_phalconry_http_client_createrequest, ZEND_ACC_PUBLIC)
	PHP_ME(Phalconry_Http_Client, send, arginfo_phalconry_http_client_send, ZEND_ACC_PUBLIC)
	PHP_ME(Phalconry_Http_Client, getResponse, arginfo_phalconry_http_client_getresponse, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
