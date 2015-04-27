
extern zend_class_entry *phalconry_mvc_module_manager_ce;

ZEPHIR_INIT_CLASS(Phalconry_Mvc_Module_Manager);

PHP_METHOD(Phalconry_Mvc_Module_Manager, set);
PHP_METHOD(Phalconry_Mvc_Module_Manager, get);
PHP_METHOD(Phalconry_Mvc_Module_Manager, setPrimary);
PHP_METHOD(Phalconry_Mvc_Module_Manager, getPrimary);
PHP_METHOD(Phalconry_Mvc_Module_Manager, load);
PHP_METHOD(Phalconry_Mvc_Module_Manager, isLoaded);
PHP_METHOD(Phalconry_Mvc_Module_Manager, getName);
PHP_METHOD(Phalconry_Mvc_Module_Manager, create);
PHP_METHOD(Phalconry_Mvc_Module_Manager, __construct);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconry_mvc_module_manager_set, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, module, Phalconry\\Mvc\\Module, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconry_mvc_module_manager_get, 0, 0, 0)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconry_mvc_module_manager_setprimary, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, module, Phalconry\\Mvc\\Module, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconry_mvc_module_manager_load, 0, 0, 1)
	ZEND_ARG_INFO(0, module)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconry_mvc_module_manager_isloaded, 0, 0, 1)
	ZEND_ARG_INFO(0, module)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconry_mvc_module_manager_getname, 0, 0, 0)
	ZEND_ARG_OBJ_INFO(0, module, Phalconry\\Mvc\\Module, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconry_mvc_module_manager_create, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalconry_mvc_module_manager_method_entry) {
	PHP_ME(Phalconry_Mvc_Module_Manager, set, arginfo_phalconry_mvc_module_manager_set, ZEND_ACC_PUBLIC)
	PHP_ME(Phalconry_Mvc_Module_Manager, get, arginfo_phalconry_mvc_module_manager_get, ZEND_ACC_PUBLIC)
	PHP_ME(Phalconry_Mvc_Module_Manager, setPrimary, arginfo_phalconry_mvc_module_manager_setprimary, ZEND_ACC_PUBLIC)
	PHP_ME(Phalconry_Mvc_Module_Manager, getPrimary, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalconry_Mvc_Module_Manager, load, arginfo_phalconry_mvc_module_manager_load, ZEND_ACC_PUBLIC)
	PHP_ME(Phalconry_Mvc_Module_Manager, isLoaded, arginfo_phalconry_mvc_module_manager_isloaded, ZEND_ACC_PUBLIC)
	PHP_ME(Phalconry_Mvc_Module_Manager, getName, arginfo_phalconry_mvc_module_manager_getname, ZEND_ACC_PUBLIC)
	PHP_ME(Phalconry_Mvc_Module_Manager, create, arginfo_phalconry_mvc_module_manager_create, ZEND_ACC_PROTECTED)
	PHP_ME(Phalconry_Mvc_Module_Manager, __construct, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
  PHP_FE_END
};
