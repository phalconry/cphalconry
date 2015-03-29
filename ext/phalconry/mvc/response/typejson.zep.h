
extern zend_class_entry *phalconry_mvc_response_typejson_ce;

ZEPHIR_INIT_CLASS(Phalconry_Mvc_Response_TypeJson);

PHP_METHOD(Phalconry_Mvc_Response_TypeJson, formatResponse);
PHP_METHOD(Phalconry_Mvc_Response_TypeJson, getContentType);
PHP_METHOD(Phalconry_Mvc_Response_TypeJson, encode);
PHP_METHOD(Phalconry_Mvc_Response_TypeJson, jsonSerialize);
PHP_METHOD(Phalconry_Mvc_Response_TypeJson, valueToArray);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconry_mvc_response_typejson_formatresponse, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, response, Phalcon\\Http\\ResponseInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconry_mvc_response_typejson_valuetoarray, 0, 0, 1)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalconry_mvc_response_typejson_method_entry) {
	PHP_ME(Phalconry_Mvc_Response_TypeJson, formatResponse, arginfo_phalconry_mvc_response_typejson_formatresponse, ZEND_ACC_PUBLIC)
	PHP_ME(Phalconry_Mvc_Response_TypeJson, getContentType, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalconry_Mvc_Response_TypeJson, encode, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalconry_Mvc_Response_TypeJson, jsonSerialize, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalconry_Mvc_Response_TypeJson, valueToArray, arginfo_phalconry_mvc_response_typejson_valuetoarray, ZEND_ACC_PROTECTED)
  PHP_FE_END
};
