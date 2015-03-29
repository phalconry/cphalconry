
extern zend_class_entry *phalconry_mvc_response_abstractdatatype_ce;

ZEPHIR_INIT_CLASS(Phalconry_Mvc_Response_AbstractDataType);

PHP_METHOD(Phalconry_Mvc_Response_AbstractDataType, __construct);
PHP_METHOD(Phalconry_Mvc_Response_AbstractDataType, setModifiedContent);
PHP_METHOD(Phalconry_Mvc_Response_AbstractDataType, setData);
PHP_METHOD(Phalconry_Mvc_Response_AbstractDataType, getData);
PHP_METHOD(Phalconry_Mvc_Response_AbstractDataType, prepend);
PHP_METHOD(Phalconry_Mvc_Response_AbstractDataType, append);
PHP_METHOD(Phalconry_Mvc_Response_AbstractDataType, setMeta);
PHP_METHOD(Phalconry_Mvc_Response_AbstractDataType, getMeta);
PHP_METHOD(Phalconry_Mvc_Response_AbstractDataType, setOptions);
PHP_METHOD(Phalconry_Mvc_Response_AbstractDataType, getOptions);
PHP_METHOD(Phalconry_Mvc_Response_AbstractDataType, addOption);
PHP_METHOD(Phalconry_Mvc_Response_AbstractDataType, clearOptions);
PHP_METHOD(Phalconry_Mvc_Response_AbstractDataType, getContent);
PHP_METHOD(Phalconry_Mvc_Response_AbstractDataType, valueToArray);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconry_mvc_response_abstractdatatype___construct, 0, 0, 0)
	ZEND_ARG_INFO(0, data)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconry_mvc_response_abstractdatatype_setmodifiedcontent, 0, 0, 2)
	ZEND_ARG_OBJ_INFO(0, response, Phalcon\\Http\\ResponseInterface, 0)
	ZEND_ARG_INFO(0, content)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconry_mvc_response_abstractdatatype_setdata, 0, 0, 1)
	ZEND_ARG_INFO(0, data)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconry_mvc_response_abstractdatatype_prepend, 0, 0, 2)
	ZEND_ARG_INFO(0, key)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconry_mvc_response_abstractdatatype_append, 0, 0, 2)
	ZEND_ARG_INFO(0, key)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconry_mvc_response_abstractdatatype_setmeta, 0, 0, 2)
	ZEND_ARG_INFO(0, key)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconry_mvc_response_abstractdatatype_setoptions, 0, 0, 1)
	ZEND_ARG_INFO(0, options)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconry_mvc_response_abstractdatatype_addoption, 0, 0, 1)
	ZEND_ARG_INFO(0, option)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconry_mvc_response_abstractdatatype_valuetoarray, 0, 0, 1)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalconry_mvc_response_abstractdatatype_method_entry) {
	PHP_ME(Phalconry_Mvc_Response_AbstractDataType, __construct, arginfo_phalconry_mvc_response_abstractdatatype___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalconry_Mvc_Response_AbstractDataType, setModifiedContent, arginfo_phalconry_mvc_response_abstractdatatype_setmodifiedcontent, ZEND_ACC_PUBLIC)
	PHP_ME(Phalconry_Mvc_Response_AbstractDataType, setData, arginfo_phalconry_mvc_response_abstractdatatype_setdata, ZEND_ACC_PUBLIC)
	PHP_ME(Phalconry_Mvc_Response_AbstractDataType, getData, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalconry_Mvc_Response_AbstractDataType, prepend, arginfo_phalconry_mvc_response_abstractdatatype_prepend, ZEND_ACC_PUBLIC)
	PHP_ME(Phalconry_Mvc_Response_AbstractDataType, append, arginfo_phalconry_mvc_response_abstractdatatype_append, ZEND_ACC_PUBLIC)
	PHP_ME(Phalconry_Mvc_Response_AbstractDataType, setMeta, arginfo_phalconry_mvc_response_abstractdatatype_setmeta, ZEND_ACC_PUBLIC)
	PHP_ME(Phalconry_Mvc_Response_AbstractDataType, getMeta, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalconry_Mvc_Response_AbstractDataType, setOptions, arginfo_phalconry_mvc_response_abstractdatatype_setoptions, ZEND_ACC_PUBLIC)
	PHP_ME(Phalconry_Mvc_Response_AbstractDataType, getOptions, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalconry_Mvc_Response_AbstractDataType, addOption, arginfo_phalconry_mvc_response_abstractdatatype_addoption, ZEND_ACC_PUBLIC)
	PHP_ME(Phalconry_Mvc_Response_AbstractDataType, clearOptions, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalconry_Mvc_Response_AbstractDataType, getContent, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalconry_Mvc_Response_AbstractDataType, valueToArray, arginfo_phalconry_mvc_response_abstractdatatype_valuetoarray, ZEND_ACC_PROTECTED)
  PHP_FE_END
};
