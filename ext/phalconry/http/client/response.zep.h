
extern zend_class_entry *phalconry_http_client_response_ce;

ZEPHIR_INIT_CLASS(Phalconry_Http_Client_Response);

PHP_METHOD(Phalconry_Http_Client_Response, setBody);
PHP_METHOD(Phalconry_Http_Client_Response, getBody);
PHP_METHOD(Phalconry_Http_Client_Response, parseHeaders);
PHP_METHOD(Phalconry_Http_Client_Response, getBodyDecoded);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconry_http_client_response_setbody, 0, 0, 1)
	ZEND_ARG_INFO(0, body)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconry_http_client_response_parseheaders, 0, 0, 1)
	ZEND_ARG_INFO(0, headers)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalconry_http_client_response_method_entry) {
	PHP_ME(Phalconry_Http_Client_Response, setBody, arginfo_phalconry_http_client_response_setbody, ZEND_ACC_PUBLIC)
	PHP_ME(Phalconry_Http_Client_Response, getBody, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalconry_Http_Client_Response, parseHeaders, arginfo_phalconry_http_client_response_parseheaders, ZEND_ACC_PUBLIC)
	PHP_ME(Phalconry_Http_Client_Response, getBodyDecoded, NULL, ZEND_ACC_PUBLIC)
  PHP_FE_END
};
