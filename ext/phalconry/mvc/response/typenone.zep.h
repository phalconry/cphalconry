
extern zend_class_entry *phalconry_mvc_response_typenone_ce;

ZEPHIR_INIT_CLASS(Phalconry_Mvc_Response_TypeNone);

PHP_METHOD(Phalconry_Mvc_Response_TypeNone, getContentType);

ZEPHIR_INIT_FUNCS(phalconry_mvc_response_typenone_method_entry) {
	PHP_ME(Phalconry_Mvc_Response_TypeNone, getContentType, NULL, ZEND_ACC_PUBLIC)
  PHP_FE_END
};
