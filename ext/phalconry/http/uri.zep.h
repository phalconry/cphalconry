
extern zend_class_entry *phalconry_http_uri_ce;

ZEPHIR_INIT_CLASS(Phalconry_Http_Uri);

PHP_METHOD(Phalconry_Http_Uri, __construct);
PHP_METHOD(Phalconry_Http_Uri, __toString);
PHP_METHOD(Phalconry_Http_Uri, __unset);
PHP_METHOD(Phalconry_Http_Uri, __set);
PHP_METHOD(Phalconry_Http_Uri, __get);
PHP_METHOD(Phalconry_Http_Uri, __isset);
PHP_METHOD(Phalconry_Http_Uri, build);
PHP_METHOD(Phalconry_Http_Uri, buildQuery);
PHP_METHOD(Phalconry_Http_Uri, resolve);
PHP_METHOD(Phalconry_Http_Uri, extend);
PHP_METHOD(Phalconry_Http_Uri, extendQuery);
PHP_METHOD(Phalconry_Http_Uri, extendPath);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconry_http_uri___construct, 0, 0, 0)
	ZEND_ARG_INFO(0, uri)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconry_http_uri___unset, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconry_http_uri___set, 0, 0, 2)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconry_http_uri___get, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconry_http_uri___isset, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconry_http_uri_buildquery, 0, 0, 1)
	ZEND_ARG_INFO(0, query)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconry_http_uri_resolve, 0, 0, 1)
	ZEND_ARG_INFO(0, uri)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconry_http_uri_extend, 0, 0, 1)
	ZEND_ARG_INFO(0, uri)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconry_http_uri_extendquery, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, params, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconry_http_uri_extendpath, 0, 0, 1)
	ZEND_ARG_INFO(0, path)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalconry_http_uri_method_entry) {
	PHP_ME(Phalconry_Http_Uri, __construct, arginfo_phalconry_http_uri___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalconry_Http_Uri, __toString, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalconry_Http_Uri, __unset, arginfo_phalconry_http_uri___unset, ZEND_ACC_PUBLIC)
	PHP_ME(Phalconry_Http_Uri, __set, arginfo_phalconry_http_uri___set, ZEND_ACC_PUBLIC)
	PHP_ME(Phalconry_Http_Uri, __get, arginfo_phalconry_http_uri___get, ZEND_ACC_PUBLIC)
	PHP_ME(Phalconry_Http_Uri, __isset, arginfo_phalconry_http_uri___isset, ZEND_ACC_PUBLIC)
	PHP_ME(Phalconry_Http_Uri, build, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalconry_Http_Uri, buildQuery, arginfo_phalconry_http_uri_buildquery, ZEND_ACC_PUBLIC)
	PHP_ME(Phalconry_Http_Uri, resolve, arginfo_phalconry_http_uri_resolve, ZEND_ACC_PUBLIC)
	PHP_ME(Phalconry_Http_Uri, extend, arginfo_phalconry_http_uri_extend, ZEND_ACC_PUBLIC)
	PHP_ME(Phalconry_Http_Uri, extendQuery, arginfo_phalconry_http_uri_extendquery, ZEND_ACC_PUBLIC)
	PHP_ME(Phalconry_Http_Uri, extendPath, arginfo_phalconry_http_uri_extendpath, ZEND_ACC_PUBLIC)
  PHP_FE_END
};
