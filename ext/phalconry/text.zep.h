
extern zend_class_entry *phalconry_text_ce;

ZEPHIR_INIT_CLASS(Phalconry_Text);

PHP_METHOD(Phalconry_Text, hasChars);
PHP_METHOD(Phalconry_Text, pearCase);
PHP_METHOD(Phalconry_Text, snakeCase);
PHP_METHOD(Phalconry_Text, studlyCase);
PHP_METHOD(Phalconry_Text, camelCase);
PHP_METHOD(Phalconry_Text, isJson);
PHP_METHOD(Phalconry_Text, isXml);
PHP_METHOD(Phalconry_Text, isSerialized);
PHP_METHOD(Phalconry_Text, format);
PHP_METHOD(Phalconry_Text, between);
PHP_METHOD(Phalconry_Text, sentences);
PHP_METHOD(Phalconry_Text, _handleError);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconry_text_haschars, 0, 0, 2)
	ZEND_ARG_INFO(0, str)
	ZEND_ARG_INFO(0, charlist)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconry_text_pearcase, 0, 0, 1)
	ZEND_ARG_INFO(0, str)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconry_text_snakecase, 0, 0, 1)
	ZEND_ARG_INFO(0, str)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconry_text_studlycase, 0, 0, 1)
	ZEND_ARG_INFO(0, str)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconry_text_camelcase, 0, 0, 1)
	ZEND_ARG_INFO(0, str)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconry_text_isjson, 0, 0, 1)
	ZEND_ARG_INFO(0, str)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconry_text_isxml, 0, 0, 1)
	ZEND_ARG_INFO(0, str)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconry_text_isserialized, 0, 0, 1)
	ZEND_ARG_INFO(0, str)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconry_text_format, 0, 0, 2)
	ZEND_ARG_INFO(0, str)
	ZEND_ARG_INFO(0, template)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconry_text_between, 0, 0, 3)
	ZEND_ARG_INFO(0, str)
	ZEND_ARG_INFO(0, substr_start)
	ZEND_ARG_INFO(0, substr_end)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconry_text_sentences, 0, 0, 1)
	ZEND_ARG_INFO(0, str)
	ZEND_ARG_INFO(0, num)
	ZEND_ARG_INFO(0, strip_abbr)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconry_text__handleerror, 0, 0, 2)
	ZEND_ARG_INFO(0, errorNum)
	ZEND_ARG_INFO(0, errorMsg)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalconry_text_method_entry) {
	PHP_ME(Phalconry_Text, hasChars, arginfo_phalconry_text_haschars, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalconry_Text, pearCase, arginfo_phalconry_text_pearcase, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalconry_Text, snakeCase, arginfo_phalconry_text_snakecase, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalconry_Text, studlyCase, arginfo_phalconry_text_studlycase, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalconry_Text, camelCase, arginfo_phalconry_text_camelcase, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalconry_Text, isJson, arginfo_phalconry_text_isjson, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalconry_Text, isXml, arginfo_phalconry_text_isxml, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalconry_Text, isSerialized, arginfo_phalconry_text_isserialized, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalconry_Text, format, arginfo_phalconry_text_format, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalconry_Text, between, arginfo_phalconry_text_between, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalconry_Text, sentences, arginfo_phalconry_text_sentences, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalconry_Text, _handleError, arginfo_phalconry_text__handleerror, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};
