
extern zend_class_entry *phalconry_mvc_plugininterface_ce;

ZEPHIR_INIT_CLASS(Phalconry_Mvc_PluginInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconry_mvc_plugininterface_setmanager, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, manager, Phalconry\\Mvc\\Plugin\\ManagerInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconry_mvc_plugininterface_load, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, di, Phalcon\\DiInterface, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalconry_mvc_plugininterface_method_entry) {
	PHP_ABSTRACT_ME(Phalconry_Mvc_PluginInterface, getName, NULL)
	PHP_ABSTRACT_ME(Phalconry_Mvc_PluginInterface, getPath, NULL)
	PHP_ABSTRACT_ME(Phalconry_Mvc_PluginInterface, setManager, arginfo_phalconry_mvc_plugininterface_setmanager)
	PHP_ABSTRACT_ME(Phalconry_Mvc_PluginInterface, getManager, NULL)
	PHP_ABSTRACT_ME(Phalconry_Mvc_PluginInterface, getConfig, NULL)
	PHP_ABSTRACT_ME(Phalconry_Mvc_PluginInterface, isLoaded, NULL)
	PHP_ABSTRACT_ME(Phalconry_Mvc_PluginInterface, load, arginfo_phalconry_mvc_plugininterface_load)
	PHP_FE_END
};
