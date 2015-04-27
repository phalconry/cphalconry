
extern zend_class_entry *phalconry_webservice_serviceinterface_ce;

ZEPHIR_INIT_CLASS(Phalconry_WebService_ServiceInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconry_webservice_serviceinterface_buildurl, 0, 0, 0)
	ZEND_ARG_ARRAY_INFO(0, args, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconry_webservice_serviceinterface_createrequest, 0, 0, 0)
	ZEND_ARG_INFO(0, url)
	ZEND_ARG_INFO(0, method)
	ZEND_ARG_ARRAY_INFO(0, headers, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconry_webservice_serviceinterface_buildresponsebody, 0, 0, 1)
	ZEND_ARG_INFO(0, body)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalconry_webservice_serviceinterface_method_entry) {
	PHP_ABSTRACT_ME(Phalconry_WebService_ServiceInterface, getClient, NULL)
	PHP_ABSTRACT_ME(Phalconry_WebService_ServiceInterface, buildUrl, arginfo_phalconry_webservice_serviceinterface_buildurl)
	PHP_ABSTRACT_ME(Phalconry_WebService_ServiceInterface, createRequest, arginfo_phalconry_webservice_serviceinterface_createrequest)
	PHP_ABSTRACT_ME(Phalconry_WebService_ServiceInterface, buildResponseBody, arginfo_phalconry_webservice_serviceinterface_buildresponsebody)
  PHP_FE_END
};
