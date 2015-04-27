
extern zend_class_entry *phalconry_http_client_header_ce;

ZEPHIR_INIT_CLASS(Phalconry_Http_Client_Header);

PHP_METHOD(Phalconry_Http_Client_Header, set);
PHP_METHOD(Phalconry_Http_Client_Header, setMultiple);
PHP_METHOD(Phalconry_Http_Client_Header, addMultiple);
PHP_METHOD(Phalconry_Http_Client_Header, get);
PHP_METHOD(Phalconry_Http_Client_Header, getAll);
PHP_METHOD(Phalconry_Http_Client_Header, has);
PHP_METHOD(Phalconry_Http_Client_Header, remove);
PHP_METHOD(Phalconry_Http_Client_Header, parse);
PHP_METHOD(Phalconry_Http_Client_Header, build);
PHP_METHOD(Phalconry_Http_Client_Header, count);
PHP_METHOD(Phalconry_Http_Client_Header, getStatusMessage);
PHP_METHOD(Phalconry_Http_Client_Header, __construct);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconry_http_client_header_set, 0, 0, 2)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconry_http_client_header_setmultiple, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, fields, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconry_http_client_header_addmultiple, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, fields, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconry_http_client_header_get, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconry_http_client_header_has, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconry_http_client_header_remove, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconry_http_client_header_parse, 0, 0, 1)
	ZEND_ARG_INFO(0, content)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconry_http_client_header_build, 0, 0, 0)
	ZEND_ARG_INFO(0, flags)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconry_http_client_header_getstatusmessage, 0, 0, 1)
	ZEND_ARG_INFO(0, code)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalconry_http_client_header_method_entry) {
	PHP_ME(Phalconry_Http_Client_Header, set, arginfo_phalconry_http_client_header_set, ZEND_ACC_PUBLIC)
	PHP_ME(Phalconry_Http_Client_Header, setMultiple, arginfo_phalconry_http_client_header_setmultiple, ZEND_ACC_PUBLIC)
	PHP_ME(Phalconry_Http_Client_Header, addMultiple, arginfo_phalconry_http_client_header_addmultiple, ZEND_ACC_PUBLIC)
	PHP_ME(Phalconry_Http_Client_Header, get, arginfo_phalconry_http_client_header_get, ZEND_ACC_PUBLIC)
	PHP_ME(Phalconry_Http_Client_Header, getAll, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalconry_Http_Client_Header, has, arginfo_phalconry_http_client_header_has, ZEND_ACC_PUBLIC)
	PHP_ME(Phalconry_Http_Client_Header, remove, arginfo_phalconry_http_client_header_remove, ZEND_ACC_PUBLIC)
	PHP_ME(Phalconry_Http_Client_Header, parse, arginfo_phalconry_http_client_header_parse, ZEND_ACC_PUBLIC)
	PHP_ME(Phalconry_Http_Client_Header, build, arginfo_phalconry_http_client_header_build, ZEND_ACC_PUBLIC)
	PHP_ME(Phalconry_Http_Client_Header, count, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalconry_Http_Client_Header, getStatusMessage, arginfo_phalconry_http_client_header_getstatusmessage, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalconry_Http_Client_Header, __construct, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
  PHP_FE_END
};
