
extern zend_class_entry *phalconry_mvc_response_typeinterface_ce;

ZEPHIR_INIT_CLASS(Phalconry_Mvc_Response_TypeInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconry_mvc_response_typeinterface_setmodifiedcontent, 0, 0, 2)
	ZEND_ARG_OBJ_INFO(0, response, Phalcon\\Http\\ResponseInterface, 0)
	ZEND_ARG_INFO(0, content)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconry_mvc_response_typeinterface_formatresponse, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, response, Phalcon\\Http\\ResponseInterface, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalconry_mvc_response_typeinterface_method_entry) {
	PHP_ABSTRACT_ME(Phalconry_Mvc_Response_TypeInterface, getContentType, NULL)
	PHP_ABSTRACT_ME(Phalconry_Mvc_Response_TypeInterface, setModifiedContent, arginfo_phalconry_mvc_response_typeinterface_setmodifiedcontent)
	PHP_ABSTRACT_ME(Phalconry_Mvc_Response_TypeInterface, formatResponse, arginfo_phalconry_mvc_response_typeinterface_formatresponse)
  PHP_FE_END
};
