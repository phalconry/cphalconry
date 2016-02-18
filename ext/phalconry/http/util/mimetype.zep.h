
extern zend_class_entry *phalconry_http_util_mimetype_ce;

ZEPHIR_INIT_CLASS(Phalconry_Http_Util_MimeType);

PHP_METHOD(Phalconry_Http_Util_MimeType, get);
PHP_METHOD(Phalconry_Http_Util_MimeType, getForFile);
PHP_METHOD(Phalconry_Http_Util_MimeType, getForHttp);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconry_http_util_mimetype_get, 0, 0, 1)
	ZEND_ARG_INFO(0, extension)
	ZEND_ARG_INFO(0, defaultValue)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconry_http_util_mimetype_getforfile, 0, 0, 1)
	ZEND_ARG_INFO(0, filename)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconry_http_util_mimetype_getforhttp, 0, 0, 1)
	ZEND_ARG_INFO(0, extension)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalconry_http_util_mimetype_method_entry) {
	PHP_ME(Phalconry_Http_Util_MimeType, get, arginfo_phalconry_http_util_mimetype_get, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalconry_Http_Util_MimeType, getForFile, arginfo_phalconry_http_util_mimetype_getforfile, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalconry_Http_Util_MimeType, getForHttp, arginfo_phalconry_http_util_mimetype_getforhttp, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};
