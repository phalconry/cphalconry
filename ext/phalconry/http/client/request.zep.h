
extern zend_class_entry *phalconry_http_client_request_ce;

ZEPHIR_INIT_CLASS(Phalconry_Http_Client_Request);

PHP_METHOD(Phalconry_Http_Client_Request, __construct);
PHP_METHOD(Phalconry_Http_Client_Request, setMethod);
PHP_METHOD(Phalconry_Http_Client_Request, getMethod);
PHP_METHOD(Phalconry_Http_Client_Request, setResponse);
PHP_METHOD(Phalconry_Http_Client_Request, getResponse);
PHP_METHOD(Phalconry_Http_Client_Request, setUri);
PHP_METHOD(Phalconry_Http_Client_Request, getUri);
PHP_METHOD(Phalconry_Http_Client_Request, resolveUri);
PHP_METHOD(Phalconry_Http_Client_Request, addQueryParams);
PHP_METHOD(Phalconry_Http_Client_Request, addHeaders);
PHP_METHOD(Phalconry_Http_Client_Request, setHeader);
PHP_METHOD(Phalconry_Http_Client_Request, buildHeaderFields);
PHP_METHOD(Phalconry_Http_Client_Request, setClient);
PHP_METHOD(Phalconry_Http_Client_Request, getClient);
PHP_METHOD(Phalconry_Http_Client_Request, send);
PHP_METHOD(Phalconry_Http_Client_Request, __invoke);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconry_http_client_request___construct, 0, 0, 0)
	ZEND_ARG_INFO(0, baseUri)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconry_http_client_request_setmethod, 0, 0, 1)
	ZEND_ARG_INFO(0, httpMethod)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconry_http_client_request_setresponse, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, response, Phalconry\\Http\\Client\\Response, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconry_http_client_request_seturi, 0, 0, 1)
	ZEND_ARG_INFO(0, uri)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconry_http_client_request_resolveuri, 0, 0, 1)
	ZEND_ARG_INFO(0, uri)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconry_http_client_request_addqueryparams, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, params, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconry_http_client_request_addheaders, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, headers, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconry_http_client_request_setheader, 0, 0, 2)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconry_http_client_request_setclient, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, client, Phalconry\\Http\\Client, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalconry_http_client_request_method_entry) {
	PHP_ME(Phalconry_Http_Client_Request, __construct, arginfo_phalconry_http_client_request___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalconry_Http_Client_Request, setMethod, arginfo_phalconry_http_client_request_setmethod, ZEND_ACC_PUBLIC)
	PHP_ME(Phalconry_Http_Client_Request, getMethod, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalconry_Http_Client_Request, setResponse, arginfo_phalconry_http_client_request_setresponse, ZEND_ACC_PUBLIC)
	PHP_ME(Phalconry_Http_Client_Request, getResponse, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalconry_Http_Client_Request, setUri, arginfo_phalconry_http_client_request_seturi, ZEND_ACC_PUBLIC)
	PHP_ME(Phalconry_Http_Client_Request, getUri, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalconry_Http_Client_Request, resolveUri, arginfo_phalconry_http_client_request_resolveuri, ZEND_ACC_PUBLIC)
	PHP_ME(Phalconry_Http_Client_Request, addQueryParams, arginfo_phalconry_http_client_request_addqueryparams, ZEND_ACC_PUBLIC)
	PHP_ME(Phalconry_Http_Client_Request, addHeaders, arginfo_phalconry_http_client_request_addheaders, ZEND_ACC_PUBLIC)
	PHP_ME(Phalconry_Http_Client_Request, setHeader, arginfo_phalconry_http_client_request_setheader, ZEND_ACC_PUBLIC)
	PHP_ME(Phalconry_Http_Client_Request, buildHeaderFields, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalconry_Http_Client_Request, setClient, arginfo_phalconry_http_client_request_setclient, ZEND_ACC_PUBLIC)
	PHP_ME(Phalconry_Http_Client_Request, getClient, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalconry_Http_Client_Request, send, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalconry_Http_Client_Request, __invoke, NULL, ZEND_ACC_PUBLIC)
  PHP_FE_END
};
