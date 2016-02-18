
extern zend_class_entry *phalconry_mvc_responder_ce;

ZEPHIR_INIT_CLASS(Phalconry_Mvc_Responder);

PHP_METHOD(Phalconry_Mvc_Responder, setType);
PHP_METHOD(Phalconry_Mvc_Responder, getType);
PHP_METHOD(Phalconry_Mvc_Responder, isType);
PHP_METHOD(Phalconry_Mvc_Responder, isDataType);
PHP_METHOD(Phalconry_Mvc_Responder, respond);
PHP_METHOD(Phalconry_Mvc_Responder, setOptions);
PHP_METHOD(Phalconry_Mvc_Responder, getOptions);
PHP_METHOD(Phalconry_Mvc_Responder, addOption);
PHP_METHOD(Phalconry_Mvc_Responder, prependResponseData);
PHP_METHOD(Phalconry_Mvc_Responder, appendResponseData);
PHP_METHOD(Phalconry_Mvc_Responder, formatResponse);
PHP_METHOD(Phalconry_Mvc_Responder, formatText);
PHP_METHOD(Phalconry_Mvc_Responder, formatJson);
PHP_METHOD(Phalconry_Mvc_Responder, formatXml);
PHP_METHOD(Phalconry_Mvc_Responder, formatDataResponse);
PHP_METHOD(Phalconry_Mvc_Responder, buildDataResponseContent);
static zend_object_value zephir_init_properties_Phalconry_Mvc_Responder(zend_class_entry *class_type TSRMLS_DC);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconry_mvc_responder_settype, 0, 0, 1)
	ZEND_ARG_INFO(0, type)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconry_mvc_responder_istype, 0, 0, 1)
	ZEND_ARG_INFO(0, type)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconry_mvc_responder_isdatatype, 0, 0, 0)
	ZEND_ARG_INFO(0, type)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconry_mvc_responder_respond, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, response, Phalcon\\Http\\ResponseInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconry_mvc_responder_setoptions, 0, 0, 1)
	ZEND_ARG_INFO(0, options)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconry_mvc_responder_addoption, 0, 0, 1)
	ZEND_ARG_INFO(0, option)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconry_mvc_responder_prependresponsedata, 0, 0, 2)
	ZEND_ARG_INFO(0, key)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconry_mvc_responder_appendresponsedata, 0, 0, 2)
	ZEND_ARG_INFO(0, key)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconry_mvc_responder_formatresponse, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, response, Phalcon\\Http\\ResponseInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconry_mvc_responder_formattext, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, response, Phalcon\\Http\\ResponseInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconry_mvc_responder_formatjson, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, response, Phalcon\\Http\\ResponseInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconry_mvc_responder_formatxml, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, response, Phalcon\\Http\\ResponseInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconry_mvc_responder_formatdataresponse, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, response, Phalcon\\Http\\ResponseInterface, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalconry_mvc_responder_method_entry) {
	PHP_ME(Phalconry_Mvc_Responder, setType, arginfo_phalconry_mvc_responder_settype, ZEND_ACC_PUBLIC)
	PHP_ME(Phalconry_Mvc_Responder, getType, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalconry_Mvc_Responder, isType, arginfo_phalconry_mvc_responder_istype, ZEND_ACC_PUBLIC)
	PHP_ME(Phalconry_Mvc_Responder, isDataType, arginfo_phalconry_mvc_responder_isdatatype, ZEND_ACC_PUBLIC)
	PHP_ME(Phalconry_Mvc_Responder, respond, arginfo_phalconry_mvc_responder_respond, ZEND_ACC_PUBLIC)
	PHP_ME(Phalconry_Mvc_Responder, setOptions, arginfo_phalconry_mvc_responder_setoptions, ZEND_ACC_PUBLIC)
	PHP_ME(Phalconry_Mvc_Responder, getOptions, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalconry_Mvc_Responder, addOption, arginfo_phalconry_mvc_responder_addoption, ZEND_ACC_PUBLIC)
	PHP_ME(Phalconry_Mvc_Responder, prependResponseData, arginfo_phalconry_mvc_responder_prependresponsedata, ZEND_ACC_PUBLIC)
	PHP_ME(Phalconry_Mvc_Responder, appendResponseData, arginfo_phalconry_mvc_responder_appendresponsedata, ZEND_ACC_PUBLIC)
	PHP_ME(Phalconry_Mvc_Responder, formatResponse, arginfo_phalconry_mvc_responder_formatresponse, ZEND_ACC_PROTECTED)
	PHP_ME(Phalconry_Mvc_Responder, formatText, arginfo_phalconry_mvc_responder_formattext, ZEND_ACC_PROTECTED)
	PHP_ME(Phalconry_Mvc_Responder, formatJson, arginfo_phalconry_mvc_responder_formatjson, ZEND_ACC_PROTECTED)
	PHP_ME(Phalconry_Mvc_Responder, formatXml, arginfo_phalconry_mvc_responder_formatxml, ZEND_ACC_PROTECTED)
	PHP_ME(Phalconry_Mvc_Responder, formatDataResponse, arginfo_phalconry_mvc_responder_formatdataresponse, ZEND_ACC_PROTECTED)
	PHP_ME(Phalconry_Mvc_Responder, buildDataResponseContent, NULL, ZEND_ACC_PROTECTED)
	PHP_FE_END
};
