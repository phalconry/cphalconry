
extern zend_class_entry *phalconry_mvc_response_typexml_ce;

ZEPHIR_INIT_CLASS(Phalconry_Mvc_Response_TypeXml);

PHP_METHOD(Phalconry_Mvc_Response_TypeXml, formatResponse);
PHP_METHOD(Phalconry_Mvc_Response_TypeXml, getContentType);
PHP_METHOD(Phalconry_Mvc_Response_TypeXml, encode);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconry_mvc_response_typexml_formatresponse, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, response, Phalcon\\Http\\ResponseInterface, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalconry_mvc_response_typexml_method_entry) {
	PHP_ME(Phalconry_Mvc_Response_TypeXml, formatResponse, arginfo_phalconry_mvc_response_typexml_formatresponse, ZEND_ACC_PUBLIC)
	PHP_ME(Phalconry_Mvc_Response_TypeXml, getContentType, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalconry_Mvc_Response_TypeXml, encode, NULL, ZEND_ACC_PUBLIC)
  PHP_FE_END
};
