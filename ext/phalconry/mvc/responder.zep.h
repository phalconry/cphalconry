
extern zend_class_entry *phalconry_mvc_responder_ce;

ZEPHIR_INIT_CLASS(Phalconry_Mvc_Responder);

PHP_METHOD(Phalconry_Mvc_Responder, setType);
PHP_METHOD(Phalconry_Mvc_Responder, getType);
PHP_METHOD(Phalconry_Mvc_Responder, isType);
PHP_METHOD(Phalconry_Mvc_Responder, isDataType);
PHP_METHOD(Phalconry_Mvc_Responder, setTypeClass);
PHP_METHOD(Phalconry_Mvc_Responder, getTypeClass);
PHP_METHOD(Phalconry_Mvc_Responder, fillEmptyContent);
PHP_METHOD(Phalconry_Mvc_Responder, respond);
PHP_METHOD(Phalconry_Mvc_Responder, __construct);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconry_mvc_responder_settype, 0, 0, 1)
	ZEND_ARG_INFO(0, type)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconry_mvc_responder_istype, 0, 0, 1)
	ZEND_ARG_INFO(0, type)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconry_mvc_responder_isdatatype, 0, 0, 0)
	ZEND_ARG_INFO(0, type)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconry_mvc_responder_settypeclass, 0, 0, 2)
	ZEND_ARG_INFO(0, type)
	ZEND_ARG_INFO(0, className)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconry_mvc_responder_gettypeclass, 0, 0, 1)
	ZEND_ARG_INFO(0, type)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconry_mvc_responder_fillemptycontent, 0, 0, 0)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconry_mvc_responder_respond, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, response, Phalcon\\Http\\ResponseInterface, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalconry_mvc_responder_method_entry) {
	PHP_ME(Phalconry_Mvc_Responder, setType, arginfo_phalconry_mvc_responder_settype, ZEND_ACC_PUBLIC)
	PHP_ME(Phalconry_Mvc_Responder, getType, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalconry_Mvc_Responder, isType, arginfo_phalconry_mvc_responder_istype, ZEND_ACC_PUBLIC)
	PHP_ME(Phalconry_Mvc_Responder, isDataType, arginfo_phalconry_mvc_responder_isdatatype, ZEND_ACC_PUBLIC)
	PHP_ME(Phalconry_Mvc_Responder, setTypeClass, arginfo_phalconry_mvc_responder_settypeclass, ZEND_ACC_PUBLIC)
	PHP_ME(Phalconry_Mvc_Responder, getTypeClass, arginfo_phalconry_mvc_responder_gettypeclass, ZEND_ACC_PUBLIC)
	PHP_ME(Phalconry_Mvc_Responder, fillEmptyContent, arginfo_phalconry_mvc_responder_fillemptycontent, ZEND_ACC_PUBLIC)
	PHP_ME(Phalconry_Mvc_Responder, respond, arginfo_phalconry_mvc_responder_respond, ZEND_ACC_PUBLIC)
	PHP_ME(Phalconry_Mvc_Responder, __construct, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
  PHP_FE_END
};
