
extern zend_class_entry *phalconry_http_client_message_ce;

ZEPHIR_INIT_CLASS(Phalconry_Http_Client_Message);

PHP_METHOD(Phalconry_Http_Client_Message, __construct);
PHP_METHOD(Phalconry_Http_Client_Message, getHeader);
PHP_METHOD(Phalconry_Http_Client_Message, getParent);
PHP_METHOD(Phalconry_Http_Client_Message, hasParent);
PHP_METHOD(Phalconry_Http_Client_Message, setParent);
PHP_METHOD(Phalconry_Http_Client_Message, __get);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconry_http_client_message_getheader, 0, 0, 0)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconry_http_client_message_setparent, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, parentMessage, Phalconry\\Http\\Client\\Message, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconry_http_client_message___get, 0, 0, 1)
	ZEND_ARG_INFO(0, prop)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalconry_http_client_message_method_entry) {
	PHP_ME(Phalconry_Http_Client_Message, __construct, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalconry_Http_Client_Message, getHeader, arginfo_phalconry_http_client_message_getheader, ZEND_ACC_PUBLIC)
	PHP_ME(Phalconry_Http_Client_Message, getParent, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalconry_Http_Client_Message, hasParent, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalconry_Http_Client_Message, setParent, arginfo_phalconry_http_client_message_setparent, ZEND_ACC_PUBLIC)
	PHP_ME(Phalconry_Http_Client_Message, __get, arginfo_phalconry_http_client_message___get, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
