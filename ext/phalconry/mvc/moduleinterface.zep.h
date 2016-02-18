
extern zend_class_entry *phalconry_mvc_moduleinterface_ce;

ZEPHIR_INIT_CLASS(Phalconry_Mvc_ModuleInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconry_mvc_moduleinterface_setname, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconry_mvc_moduleinterface_setmanager, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, manager, Phalconry\\Mvc\\Module\\ManagerInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconry_mvc_moduleinterface_setapp, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, app, Phalconry\\Mvc\\ApplicationInterface, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalconry_mvc_moduleinterface_method_entry) {
	PHP_ABSTRACT_ME(Phalconry_Mvc_ModuleInterface, getControllerNamespace, NULL)
	PHP_ABSTRACT_ME(Phalconry_Mvc_ModuleInterface, setName, arginfo_phalconry_mvc_moduleinterface_setname)
	PHP_ABSTRACT_ME(Phalconry_Mvc_ModuleInterface, getName, NULL)
	PHP_ABSTRACT_ME(Phalconry_Mvc_ModuleInterface, setManager, arginfo_phalconry_mvc_moduleinterface_setmanager)
	PHP_ABSTRACT_ME(Phalconry_Mvc_ModuleInterface, getManager, NULL)
	PHP_ABSTRACT_ME(Phalconry_Mvc_ModuleInterface, setApp, arginfo_phalconry_mvc_moduleinterface_setapp)
	PHP_ABSTRACT_ME(Phalconry_Mvc_ModuleInterface, getApp, NULL)
	PHP_ABSTRACT_ME(Phalconry_Mvc_ModuleInterface, isLoaded, NULL)
	PHP_ABSTRACT_ME(Phalconry_Mvc_ModuleInterface, isPrimary, NULL)
	PHP_ABSTRACT_ME(Phalconry_Mvc_ModuleInterface, isDefault, NULL)
	PHP_FE_END
};
