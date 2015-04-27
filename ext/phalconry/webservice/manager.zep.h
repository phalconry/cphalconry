
extern zend_class_entry *phalconry_webservice_manager_ce;

ZEPHIR_INIT_CLASS(Phalconry_WebService_Manager);

PHP_METHOD(Phalconry_WebService_Manager, set);
PHP_METHOD(Phalconry_WebService_Manager, has);
PHP_METHOD(Phalconry_WebService_Manager, get);
PHP_METHOD(Phalconry_WebService_Manager, setDefinition);
PHP_METHOD(Phalconry_WebService_Manager, hasDefinition);
PHP_METHOD(Phalconry_WebService_Manager, getDefinition);
PHP_METHOD(Phalconry_WebService_Manager, isAvailable);
PHP_METHOD(Phalconry_WebService_Manager, setFactory);
PHP_METHOD(Phalconry_WebService_Manager, getFactory);
PHP_METHOD(Phalconry_WebService_Manager, count);
PHP_METHOD(Phalconry_WebService_Manager, __construct);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconry_webservice_manager_set, 0, 0, 2)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_OBJ_INFO(0, service, Phalconry\\WebService\\ServiceInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconry_webservice_manager_has, 0, 0, 1)
	ZEND_ARG_INFO(0, service)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconry_webservice_manager_get, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconry_webservice_manager_setdefinition, 0, 0, 2)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, definition)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconry_webservice_manager_hasdefinition, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconry_webservice_manager_getdefinition, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconry_webservice_manager_isavailable, 0, 0, 1)
	ZEND_ARG_INFO(0, service)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconry_webservice_manager_setfactory, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, factory, Phalconry\\WebService\\Factory, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalconry_webservice_manager_method_entry) {
	PHP_ME(Phalconry_WebService_Manager, set, arginfo_phalconry_webservice_manager_set, ZEND_ACC_PUBLIC)
	PHP_ME(Phalconry_WebService_Manager, has, arginfo_phalconry_webservice_manager_has, ZEND_ACC_PUBLIC)
	PHP_ME(Phalconry_WebService_Manager, get, arginfo_phalconry_webservice_manager_get, ZEND_ACC_PUBLIC)
	PHP_ME(Phalconry_WebService_Manager, setDefinition, arginfo_phalconry_webservice_manager_setdefinition, ZEND_ACC_PUBLIC)
	PHP_ME(Phalconry_WebService_Manager, hasDefinition, arginfo_phalconry_webservice_manager_hasdefinition, ZEND_ACC_PUBLIC)
	PHP_ME(Phalconry_WebService_Manager, getDefinition, arginfo_phalconry_webservice_manager_getdefinition, ZEND_ACC_PUBLIC)
	PHP_ME(Phalconry_WebService_Manager, isAvailable, arginfo_phalconry_webservice_manager_isavailable, ZEND_ACC_PUBLIC)
	PHP_ME(Phalconry_WebService_Manager, setFactory, arginfo_phalconry_webservice_manager_setfactory, ZEND_ACC_PUBLIC)
	PHP_ME(Phalconry_WebService_Manager, getFactory, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalconry_WebService_Manager, count, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalconry_WebService_Manager, __construct, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
  PHP_FE_END
};
