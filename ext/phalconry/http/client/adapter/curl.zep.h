
extern zend_class_entry *phalconry_http_client_adapter_curl_ce;

ZEPHIR_INIT_CLASS(Phalconry_Http_Client_Adapter_Curl);

PHP_METHOD(Phalconry_Http_Client_Adapter_Curl, isAvailable);
PHP_METHOD(Phalconry_Http_Client_Adapter_Curl, __construct);
PHP_METHOD(Phalconry_Http_Client_Adapter_Curl, __destruct);
PHP_METHOD(Phalconry_Http_Client_Adapter_Curl, __clone);
PHP_METHOD(Phalconry_Http_Client_Adapter_Curl, setOption);
PHP_METHOD(Phalconry_Http_Client_Adapter_Curl, setOptions);
PHP_METHOD(Phalconry_Http_Client_Adapter_Curl, setTimeout);
PHP_METHOD(Phalconry_Http_Client_Adapter_Curl, setConnectTimeout);
PHP_METHOD(Phalconry_Http_Client_Adapter_Curl, setProxy);
PHP_METHOD(Phalconry_Http_Client_Adapter_Curl, get);
PHP_METHOD(Phalconry_Http_Client_Adapter_Curl, head);
PHP_METHOD(Phalconry_Http_Client_Adapter_Curl, delete);
PHP_METHOD(Phalconry_Http_Client_Adapter_Curl, post);
PHP_METHOD(Phalconry_Http_Client_Adapter_Curl, put);
PHP_METHOD(Phalconry_Http_Client_Adapter_Curl, __invoke);
PHP_METHOD(Phalconry_Http_Client_Adapter_Curl, send);
PHP_METHOD(Phalconry_Http_Client_Adapter_Curl, initPostFields);
PHP_METHOD(Phalconry_Http_Client_Adapter_Curl, initOptions);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconry_http_client_adapter_curl___construct, 0, 0, 0)
	ZEND_ARG_INFO(0, curlHandle)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconry_http_client_adapter_curl_setoption, 0, 0, 2)
	ZEND_ARG_INFO(0, option)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconry_http_client_adapter_curl_setoptions, 0, 0, 1)
	ZEND_ARG_INFO(0, options)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconry_http_client_adapter_curl_settimeout, 0, 0, 1)
	ZEND_ARG_INFO(0, timeout)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconry_http_client_adapter_curl_setconnecttimeout, 0, 0, 1)
	ZEND_ARG_INFO(0, timeout)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconry_http_client_adapter_curl_setproxy, 0, 0, 1)
	ZEND_ARG_INFO(0, host)
	ZEND_ARG_INFO(0, port)
	ZEND_ARG_INFO(0, user)
	ZEND_ARG_INFO(0, pass)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconry_http_client_adapter_curl_get, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, request, Phalconry\\Http\\Client\\Request, 0)
	ZEND_ARG_INFO(0, params)
	ZEND_ARG_INFO(0, customHeader)
	ZEND_ARG_INFO(0, fullResponse)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconry_http_client_adapter_curl_head, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, request, Phalconry\\Http\\Client\\Request, 0)
	ZEND_ARG_INFO(0, params)
	ZEND_ARG_INFO(0, customHeader)
	ZEND_ARG_INFO(0, fullResponse)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconry_http_client_adapter_curl_delete, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, request, Phalconry\\Http\\Client\\Request, 0)
	ZEND_ARG_INFO(0, params)
	ZEND_ARG_INFO(0, customHeader)
	ZEND_ARG_INFO(0, fullResponse)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconry_http_client_adapter_curl_post, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, request, Phalconry\\Http\\Client\\Request, 0)
	ZEND_ARG_INFO(0, params)
	ZEND_ARG_INFO(0, urlEncode)
	ZEND_ARG_INFO(0, customHeader)
	ZEND_ARG_INFO(0, fullResponse)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconry_http_client_adapter_curl_put, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, request, Phalconry\\Http\\Client\\Request, 0)
	ZEND_ARG_INFO(0, params)
	ZEND_ARG_INFO(0, urlEncode)
	ZEND_ARG_INFO(0, customHeader)
	ZEND_ARG_INFO(0, fullResponse)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconry_http_client_adapter_curl___invoke, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, request, Phalconry\\Http\\Client\\Request, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconry_http_client_adapter_curl_send, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, request, Phalconry\\Http\\Client\\Request, 0)
	ZEND_ARG_INFO(0, customHeader)
	ZEND_ARG_INFO(0, fullResponse)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconry_http_client_adapter_curl_initpostfields, 0, 0, 1)
	ZEND_ARG_INFO(0, params)
	ZEND_ARG_INFO(0, urlEncode)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalconry_http_client_adapter_curl_method_entry) {
	PHP_ME(Phalconry_Http_Client_Adapter_Curl, isAvailable, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalconry_Http_Client_Adapter_Curl, __construct, arginfo_phalconry_http_client_adapter_curl___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalconry_Http_Client_Adapter_Curl, __destruct, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_DTOR)
	PHP_ME(Phalconry_Http_Client_Adapter_Curl, __clone, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalconry_Http_Client_Adapter_Curl, setOption, arginfo_phalconry_http_client_adapter_curl_setoption, ZEND_ACC_PUBLIC)
	PHP_ME(Phalconry_Http_Client_Adapter_Curl, setOptions, arginfo_phalconry_http_client_adapter_curl_setoptions, ZEND_ACC_PUBLIC)
	PHP_ME(Phalconry_Http_Client_Adapter_Curl, setTimeout, arginfo_phalconry_http_client_adapter_curl_settimeout, ZEND_ACC_PUBLIC)
	PHP_ME(Phalconry_Http_Client_Adapter_Curl, setConnectTimeout, arginfo_phalconry_http_client_adapter_curl_setconnecttimeout, ZEND_ACC_PUBLIC)
	PHP_ME(Phalconry_Http_Client_Adapter_Curl, setProxy, arginfo_phalconry_http_client_adapter_curl_setproxy, ZEND_ACC_PUBLIC)
	PHP_ME(Phalconry_Http_Client_Adapter_Curl, get, arginfo_phalconry_http_client_adapter_curl_get, ZEND_ACC_PUBLIC)
	PHP_ME(Phalconry_Http_Client_Adapter_Curl, head, arginfo_phalconry_http_client_adapter_curl_head, ZEND_ACC_PUBLIC)
	PHP_ME(Phalconry_Http_Client_Adapter_Curl, delete, arginfo_phalconry_http_client_adapter_curl_delete, ZEND_ACC_PUBLIC)
	PHP_ME(Phalconry_Http_Client_Adapter_Curl, post, arginfo_phalconry_http_client_adapter_curl_post, ZEND_ACC_PUBLIC)
	PHP_ME(Phalconry_Http_Client_Adapter_Curl, put, arginfo_phalconry_http_client_adapter_curl_put, ZEND_ACC_PUBLIC)
	PHP_ME(Phalconry_Http_Client_Adapter_Curl, __invoke, arginfo_phalconry_http_client_adapter_curl___invoke, ZEND_ACC_PUBLIC)
	PHP_ME(Phalconry_Http_Client_Adapter_Curl, send, arginfo_phalconry_http_client_adapter_curl_send, ZEND_ACC_PROTECTED)
	PHP_ME(Phalconry_Http_Client_Adapter_Curl, initPostFields, arginfo_phalconry_http_client_adapter_curl_initpostfields, ZEND_ACC_PROTECTED)
	PHP_ME(Phalconry_Http_Client_Adapter_Curl, initOptions, NULL, ZEND_ACC_PROTECTED)
  PHP_FE_END
};
