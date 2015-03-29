
extern zend_class_entry *phalconry_mvc_response_abstracttype_ce;

ZEPHIR_INIT_CLASS(Phalconry_Mvc_Response_AbstractType);

PHP_METHOD(Phalconry_Mvc_Response_AbstractType, setModifiedContent);
PHP_METHOD(Phalconry_Mvc_Response_AbstractType, formatResponse);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconry_mvc_response_abstracttype_setmodifiedcontent, 0, 0, 2)
	ZEND_ARG_OBJ_INFO(0, response, Phalcon\\Http\\ResponseInterface, 0)
	ZEND_ARG_INFO(0, content)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconry_mvc_response_abstracttype_formatresponse, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, response, Phalcon\\Http\\ResponseInterface, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalconry_mvc_response_abstracttype_method_entry) {
	PHP_ME(Phalconry_Mvc_Response_AbstractType, setModifiedContent, arginfo_phalconry_mvc_response_abstracttype_setmodifiedcontent, ZEND_ACC_PUBLIC)
	PHP_ME(Phalconry_Mvc_Response_AbstractType, formatResponse, arginfo_phalconry_mvc_response_abstracttype_formatresponse, ZEND_ACC_PUBLIC)
  PHP_FE_END
};
