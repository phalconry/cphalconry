
extern zend_class_entry *phalconry_mvc_response_typetext_ce;

ZEPHIR_INIT_CLASS(Phalconry_Mvc_Response_TypeText);

PHP_METHOD(Phalconry_Mvc_Response_TypeText, setModifiedContent);
PHP_METHOD(Phalconry_Mvc_Response_TypeText, getContentType);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconry_mvc_response_typetext_setmodifiedcontent, 0, 0, 2)
	ZEND_ARG_OBJ_INFO(0, response, Phalcon\\Http\\ResponseInterface, 0)
	ZEND_ARG_INFO(0, content)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalconry_mvc_response_typetext_method_entry) {
	PHP_ME(Phalconry_Mvc_Response_TypeText, setModifiedContent, arginfo_phalconry_mvc_response_typetext_setmodifiedcontent, ZEND_ACC_PUBLIC)
	PHP_ME(Phalconry_Mvc_Response_TypeText, getContentType, NULL, ZEND_ACC_PUBLIC)
  PHP_FE_END
};
