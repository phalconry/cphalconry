
extern zend_class_entry *phalconry_http_client_adapter_stream_ce;

ZEPHIR_INIT_CLASS(Phalconry_Http_Client_Adapter_Stream);

PHP_METHOD(Phalconry_Http_Client_Adapter_Stream, isAvailable);
PHP_METHOD(Phalconry_Http_Client_Adapter_Stream, __construct);
PHP_METHOD(Phalconry_Http_Client_Adapter_Stream, __destruct);
PHP_METHOD(Phalconry_Http_Client_Adapter_Stream, setOption);
PHP_METHOD(Phalconry_Http_Client_Adapter_Stream, setOptions);
PHP_METHOD(Phalconry_Http_Client_Adapter_Stream, setTimeout);
PHP_METHOD(Phalconry_Http_Client_Adapter_Stream, setProxy);
PHP_METHOD(Phalconry_Http_Client_Adapter_Stream, get);
PHP_METHOD(Phalconry_Http_Client_Adapter_Stream, head);
PHP_METHOD(Phalconry_Http_Client_Adapter_Stream, delete);
PHP_METHOD(Phalconry_Http_Client_Adapter_Stream, post);
PHP_METHOD(Phalconry_Http_Client_Adapter_Stream, put);
PHP_METHOD(Phalconry_Http_Client_Adapter_Stream, __invoke);
PHP_METHOD(Phalconry_Http_Client_Adapter_Stream, errorHandler);
PHP_METHOD(Phalconry_Http_Client_Adapter_Stream, send);
PHP_METHOD(Phalconry_Http_Client_Adapter_Stream, initPostFields);
PHP_METHOD(Phalconry_Http_Client_Adapter_Stream, initOptions);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconry_http_client_adapter_stream_setoption, 0, 0, 2)
	ZEND_ARG_INFO(0, option)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconry_http_client_adapter_stream_setoptions, 0, 0, 1)
	ZEND_ARG_INFO(0, options)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconry_http_client_adapter_stream_settimeout, 0, 0, 1)
	ZEND_ARG_INFO(0, timeout)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconry_http_client_adapter_stream_setproxy, 0, 0, 1)
	ZEND_ARG_INFO(0, host)
	ZEND_ARG_INFO(0, port)
	ZEND_ARG_INFO(0, user)
	ZEND_ARG_INFO(0, pass)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconry_http_client_adapter_stream_get, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, request, Phalconry\\Http\\Client\\Request, 0)
	ZEND_ARG_INFO(0, params)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconry_http_client_adapter_stream_head, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, request, Phalconry\\Http\\Client\\Request, 0)
	ZEND_ARG_INFO(0, params)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconry_http_client_adapter_stream_delete, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, request, Phalconry\\Http\\Client\\Request, 0)
	ZEND_ARG_INFO(0, params)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconry_http_client_adapter_stream_post, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, request, Phalconry\\Http\\Client\\Request, 0)
	ZEND_ARG_INFO(0, params)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconry_http_client_adapter_stream_put, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, request, Phalconry\\Http\\Client\\Request, 0)
	ZEND_ARG_INFO(0, params)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconry_http_client_adapter_stream___invoke, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, request, Phalconry\\Http\\Client\\Request, 0)
	ZEND_ARG_INFO(0, params)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconry_http_client_adapter_stream_errorhandler, 0, 0, 2)
	ZEND_ARG_INFO(0, errorNumber)
	ZEND_ARG_INFO(0, errorString)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconry_http_client_adapter_stream_send, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, request, Phalconry\\Http\\Client\\Request, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconry_http_client_adapter_stream_initpostfields, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, request, Phalconry\\Http\\Client\\Request, 0)
	ZEND_ARG_INFO(0, params)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalconry_http_client_adapter_stream_method_entry) {
	PHP_ME(Phalconry_Http_Client_Adapter_Stream, isAvailable, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalconry_Http_Client_Adapter_Stream, __construct, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalconry_Http_Client_Adapter_Stream, __destruct, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_DTOR)
	PHP_ME(Phalconry_Http_Client_Adapter_Stream, setOption, arginfo_phalconry_http_client_adapter_stream_setoption, ZEND_ACC_PUBLIC)
	PHP_ME(Phalconry_Http_Client_Adapter_Stream, setOptions, arginfo_phalconry_http_client_adapter_stream_setoptions, ZEND_ACC_PUBLIC)
	PHP_ME(Phalconry_Http_Client_Adapter_Stream, setTimeout, arginfo_phalconry_http_client_adapter_stream_settimeout, ZEND_ACC_PUBLIC)
	PHP_ME(Phalconry_Http_Client_Adapter_Stream, setProxy, arginfo_phalconry_http_client_adapter_stream_setproxy, ZEND_ACC_PUBLIC)
	PHP_ME(Phalconry_Http_Client_Adapter_Stream, get, arginfo_phalconry_http_client_adapter_stream_get, ZEND_ACC_PUBLIC)
	PHP_ME(Phalconry_Http_Client_Adapter_Stream, head, arginfo_phalconry_http_client_adapter_stream_head, ZEND_ACC_PUBLIC)
	PHP_ME(Phalconry_Http_Client_Adapter_Stream, delete, arginfo_phalconry_http_client_adapter_stream_delete, ZEND_ACC_PUBLIC)
	PHP_ME(Phalconry_Http_Client_Adapter_Stream, post, arginfo_phalconry_http_client_adapter_stream_post, ZEND_ACC_PUBLIC)
	PHP_ME(Phalconry_Http_Client_Adapter_Stream, put, arginfo_phalconry_http_client_adapter_stream_put, ZEND_ACC_PUBLIC)
	PHP_ME(Phalconry_Http_Client_Adapter_Stream, __invoke, arginfo_phalconry_http_client_adapter_stream___invoke, ZEND_ACC_PUBLIC)
	PHP_ME(Phalconry_Http_Client_Adapter_Stream, errorHandler, arginfo_phalconry_http_client_adapter_stream_errorhandler, ZEND_ACC_PROTECTED)
	PHP_ME(Phalconry_Http_Client_Adapter_Stream, send, arginfo_phalconry_http_client_adapter_stream_send, ZEND_ACC_PROTECTED)
	PHP_ME(Phalconry_Http_Client_Adapter_Stream, initPostFields, arginfo_phalconry_http_client_adapter_stream_initpostfields, ZEND_ACC_PROTECTED)
	PHP_ME(Phalconry_Http_Client_Adapter_Stream, initOptions, NULL, ZEND_ACC_PROTECTED)
  PHP_FE_END
};
