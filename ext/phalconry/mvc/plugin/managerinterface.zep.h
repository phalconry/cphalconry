
extern zend_class_entry *phalconry_mvc_plugin_managerinterface_ce;

ZEPHIR_INIT_CLASS(Phalconry_Mvc_Plugin_ManagerInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconry_mvc_plugin_managerinterface_setnamespace, 0, 0, 1)
	ZEND_ARG_INFO(0, pluginNamespace)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconry_mvc_plugin_managerinterface_setpath, 0, 0, 1)
	ZEND_ARG_INFO(0, dirPath)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconry_mvc_plugin_managerinterface_getpluginclassname, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconry_mvc_plugin_managerinterface_getpluginfilepath, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconry_mvc_plugin_managerinterface_register, 0, 0, 1)
	ZEND_ARG_INFO(0, classname)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconry_mvc_plugin_managerinterface_add, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, plugin, Phalconry\\Mvc\\PluginInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconry_mvc_plugin_managerinterface_get, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconry_mvc_plugin_managerinterface_isregistered, 0, 0, 1)
	ZEND_ARG_INFO(0, plugin)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconry_mvc_plugin_managerinterface_isloaded, 0, 0, 1)
	ZEND_ARG_INFO(0, plugin)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconry_mvc_plugin_managerinterface_load, 0, 0, 1)
	ZEND_ARG_INFO(0, plugin)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalconry_mvc_plugin_managerinterface_method_entry) {
	PHP_ABSTRACT_ME(Phalconry_Mvc_Plugin_ManagerInterface, setNamespace, arginfo_phalconry_mvc_plugin_managerinterface_setnamespace)
	PHP_ABSTRACT_ME(Phalconry_Mvc_Plugin_ManagerInterface, getNamespace, NULL)
	PHP_ABSTRACT_ME(Phalconry_Mvc_Plugin_ManagerInterface, setPath, arginfo_phalconry_mvc_plugin_managerinterface_setpath)
	PHP_ABSTRACT_ME(Phalconry_Mvc_Plugin_ManagerInterface, getPath, NULL)
	PHP_ABSTRACT_ME(Phalconry_Mvc_Plugin_ManagerInterface, getPluginClassname, arginfo_phalconry_mvc_plugin_managerinterface_getpluginclassname)
	PHP_ABSTRACT_ME(Phalconry_Mvc_Plugin_ManagerInterface, getPluginFilePath, arginfo_phalconry_mvc_plugin_managerinterface_getpluginfilepath)
	PHP_ABSTRACT_ME(Phalconry_Mvc_Plugin_ManagerInterface, register, arginfo_phalconry_mvc_plugin_managerinterface_register)
	PHP_ABSTRACT_ME(Phalconry_Mvc_Plugin_ManagerInterface, add, arginfo_phalconry_mvc_plugin_managerinterface_add)
	PHP_ABSTRACT_ME(Phalconry_Mvc_Plugin_ManagerInterface, get, arginfo_phalconry_mvc_plugin_managerinterface_get)
	PHP_ABSTRACT_ME(Phalconry_Mvc_Plugin_ManagerInterface, isRegistered, arginfo_phalconry_mvc_plugin_managerinterface_isregistered)
	PHP_ABSTRACT_ME(Phalconry_Mvc_Plugin_ManagerInterface, isLoaded, arginfo_phalconry_mvc_plugin_managerinterface_isloaded)
	PHP_ABSTRACT_ME(Phalconry_Mvc_Plugin_ManagerInterface, load, arginfo_phalconry_mvc_plugin_managerinterface_load)
	PHP_FE_END
};
