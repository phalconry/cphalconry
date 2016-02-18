
extern zend_class_entry *phalconry_mvc_plugin_manager_ce;

ZEPHIR_INIT_CLASS(Phalconry_Mvc_Plugin_Manager);

PHP_METHOD(Phalconry_Mvc_Plugin_Manager, setNamespace);
PHP_METHOD(Phalconry_Mvc_Plugin_Manager, getNamespace);
PHP_METHOD(Phalconry_Mvc_Plugin_Manager, setPath);
PHP_METHOD(Phalconry_Mvc_Plugin_Manager, getPath);
PHP_METHOD(Phalconry_Mvc_Plugin_Manager, getPluginClassname);
PHP_METHOD(Phalconry_Mvc_Plugin_Manager, getPluginFilePath);
PHP_METHOD(Phalconry_Mvc_Plugin_Manager, register);
PHP_METHOD(Phalconry_Mvc_Plugin_Manager, add);
PHP_METHOD(Phalconry_Mvc_Plugin_Manager, get);
PHP_METHOD(Phalconry_Mvc_Plugin_Manager, isRegistered);
PHP_METHOD(Phalconry_Mvc_Plugin_Manager, isLoaded);
PHP_METHOD(Phalconry_Mvc_Plugin_Manager, load);
PHP_METHOD(Phalconry_Mvc_Plugin_Manager, locatePlugin);
static zend_object_value zephir_init_properties_Phalconry_Mvc_Plugin_Manager(zend_class_entry *class_type TSRMLS_DC);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconry_mvc_plugin_manager_setnamespace, 0, 0, 1)
	ZEND_ARG_INFO(0, pluginNamespace)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconry_mvc_plugin_manager_setpath, 0, 0, 1)
	ZEND_ARG_INFO(0, dirPath)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconry_mvc_plugin_manager_getpluginclassname, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconry_mvc_plugin_manager_getpluginfilepath, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconry_mvc_plugin_manager_register, 0, 0, 1)
	ZEND_ARG_INFO(0, classname)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconry_mvc_plugin_manager_add, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, plugin, Phalconry\\Mvc\\PluginInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconry_mvc_plugin_manager_get, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconry_mvc_plugin_manager_isregistered, 0, 0, 1)
	ZEND_ARG_INFO(0, plugin)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconry_mvc_plugin_manager_isloaded, 0, 0, 1)
	ZEND_ARG_INFO(0, plugin)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconry_mvc_plugin_manager_load, 0, 0, 1)
	ZEND_ARG_INFO(0, plugin)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconry_mvc_plugin_manager_locateplugin, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalconry_mvc_plugin_manager_method_entry) {
	PHP_ME(Phalconry_Mvc_Plugin_Manager, setNamespace, arginfo_phalconry_mvc_plugin_manager_setnamespace, ZEND_ACC_PUBLIC)
	PHP_ME(Phalconry_Mvc_Plugin_Manager, getNamespace, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalconry_Mvc_Plugin_Manager, setPath, arginfo_phalconry_mvc_plugin_manager_setpath, ZEND_ACC_PUBLIC)
	PHP_ME(Phalconry_Mvc_Plugin_Manager, getPath, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalconry_Mvc_Plugin_Manager, getPluginClassname, arginfo_phalconry_mvc_plugin_manager_getpluginclassname, ZEND_ACC_PUBLIC)
	PHP_ME(Phalconry_Mvc_Plugin_Manager, getPluginFilePath, arginfo_phalconry_mvc_plugin_manager_getpluginfilepath, ZEND_ACC_PUBLIC)
	PHP_ME(Phalconry_Mvc_Plugin_Manager, register, arginfo_phalconry_mvc_plugin_manager_register, ZEND_ACC_PUBLIC)
	PHP_ME(Phalconry_Mvc_Plugin_Manager, add, arginfo_phalconry_mvc_plugin_manager_add, ZEND_ACC_PUBLIC)
	PHP_ME(Phalconry_Mvc_Plugin_Manager, get, arginfo_phalconry_mvc_plugin_manager_get, ZEND_ACC_PUBLIC)
	PHP_ME(Phalconry_Mvc_Plugin_Manager, isRegistered, arginfo_phalconry_mvc_plugin_manager_isregistered, ZEND_ACC_PUBLIC)
	PHP_ME(Phalconry_Mvc_Plugin_Manager, isLoaded, arginfo_phalconry_mvc_plugin_manager_isloaded, ZEND_ACC_PUBLIC)
	PHP_ME(Phalconry_Mvc_Plugin_Manager, load, arginfo_phalconry_mvc_plugin_manager_load, ZEND_ACC_PUBLIC)
	PHP_ME(Phalconry_Mvc_Plugin_Manager, locatePlugin, arginfo_phalconry_mvc_plugin_manager_locateplugin, ZEND_ACC_PROTECTED)
	PHP_FE_END
};
