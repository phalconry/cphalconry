
/* This file was generated automatically by Zephir do not modify it! */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <php.h>

#if PHP_VERSION_ID < 50500
#include <locale.h>
#endif

#include "php_ext.h"
#include "phalconry.h"

#include <ext/standard/info.h>

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/globals.h"
#include "kernel/main.h"
#include "kernel/fcall.h"
#include "kernel/memory.h"



zend_class_entry *phalconry_http_client_adapter_adapterinterface_ce;
zend_class_entry *phalconry_mvc_applicationawareinterface_ce;
zend_class_entry *phalconry_mvc_application_bootstrapinterface_ce;
zend_class_entry *phalconry_mvc_application_handlerinterface_ce;
zend_class_entry *phalconry_mvc_applicationinterface_ce;
zend_class_entry *phalconry_mvc_environmentinterface_ce;
zend_class_entry *phalconry_mvc_module_managerinterface_ce;
zend_class_entry *phalconry_mvc_moduleinterface_ce;
zend_class_entry *phalconry_mvc_plugin_managerinterface_ce;
zend_class_entry *phalconry_mvc_plugininterface_ce;
zend_class_entry *phalconry_webservice_serviceinterface_ce;
zend_class_entry *phalconry_di_serviceproviderinterface_ce;
zend_class_entry *phalconry_exception_ce;
zend_class_entry *phalconry_http_client_message_ce;
zend_class_entry *phalconry_config_ce;
zend_class_entry *phalconry_http_client_exception_ce;
zend_class_entry *phalconry_events_globalmanager_ce;
zend_class_entry *phalconry_http_client_adapter_curl_ce;
zend_class_entry *phalconry_http_client_adapter_exception_ce;
zend_class_entry *phalconry_http_client_adapter_stream_ce;
zend_class_entry *phalconry_http_client_ce;
zend_class_entry *phalconry_http_client_header_ce;
zend_class_entry *phalconry_http_client_request_ce;
zend_class_entry *phalconry_http_client_response_ce;
zend_class_entry *phalconry_http_uri_ce;
zend_class_entry *phalconry_http_util_mimetype_ce;
zend_class_entry *phalconry_mvc_application_bootstrap_ce;
zend_class_entry *phalconry_mvc_application_ce;
zend_class_entry *phalconry_mvc_application_exception_ce;
zend_class_entry *phalconry_mvc_application_handler_ce;
zend_class_entry *phalconry_mvc_env_ce;
zend_class_entry *phalconry_mvc_hmvc_exception_ce;
zend_class_entry *phalconry_mvc_hmvc_request_ce;
zend_class_entry *phalconry_mvc_module_ce;
zend_class_entry *phalconry_mvc_module_manager_ce;
zend_class_entry *phalconry_mvc_plugin_ce;
zend_class_entry *phalconry_mvc_plugin_exception_ce;
zend_class_entry *phalconry_mvc_plugin_manager_ce;
zend_class_entry *phalconry_mvc_responder_ce;
zend_class_entry *phalconry_text_ce;
zend_class_entry *phalconry_vartype_ce;
zend_class_entry *phalconry_webservice_exception_ce;
zend_class_entry *phalconry_webservice_factory_ce;
zend_class_entry *phalconry_webservice_manager_ce;
zend_class_entry *phalconry_webservice_service_ce;

ZEND_DECLARE_MODULE_GLOBALS(phalconry)

PHP_INI_BEGIN()
	
PHP_INI_END()

static PHP_MINIT_FUNCTION(phalconry)
{
#if PHP_VERSION_ID < 50500
	char* old_lc_all = setlocale(LC_ALL, NULL);
	if (old_lc_all) {
		size_t len = strlen(old_lc_all);
		char *tmp  = calloc(len+1, 1);
		if (UNEXPECTED(!tmp)) {
			return FAILURE;
		}

		memcpy(tmp, old_lc_all, len);
		old_lc_all = tmp;
	}

	setlocale(LC_ALL, "C");
#endif
	REGISTER_INI_ENTRIES();
	ZEPHIR_INIT(Phalconry_Http_Client_Adapter_AdapterInterface);
	ZEPHIR_INIT(Phalconry_Mvc_ApplicationAwareInterface);
	ZEPHIR_INIT(Phalconry_Mvc_ApplicationInterface);
	ZEPHIR_INIT(Phalconry_Mvc_Application_BootstrapInterface);
	ZEPHIR_INIT(Phalconry_Mvc_Application_HandlerInterface);
	ZEPHIR_INIT(Phalconry_Mvc_EnvironmentInterface);
	ZEPHIR_INIT(Phalconry_Mvc_ModuleInterface);
	ZEPHIR_INIT(Phalconry_Mvc_Module_ManagerInterface);
	ZEPHIR_INIT(Phalconry_Mvc_PluginInterface);
	ZEPHIR_INIT(Phalconry_Mvc_Plugin_ManagerInterface);
	ZEPHIR_INIT(Phalconry_WebService_ServiceInterface);
	ZEPHIR_INIT(Phalconry_Di_ServiceProviderInterface);
	ZEPHIR_INIT(Phalconry_Exception);
	ZEPHIR_INIT(Phalconry_Http_Client_Message);
	ZEPHIR_INIT(Phalconry_Config);
	ZEPHIR_INIT(Phalconry_Http_Client_Exception);
	ZEPHIR_INIT(Phalconry_Events_GlobalManager);
	ZEPHIR_INIT(Phalconry_Http_Client);
	ZEPHIR_INIT(Phalconry_Http_Client_Adapter_Curl);
	ZEPHIR_INIT(Phalconry_Http_Client_Adapter_Exception);
	ZEPHIR_INIT(Phalconry_Http_Client_Adapter_Stream);
	ZEPHIR_INIT(Phalconry_Http_Client_Header);
	ZEPHIR_INIT(Phalconry_Http_Client_Request);
	ZEPHIR_INIT(Phalconry_Http_Client_Response);
	ZEPHIR_INIT(Phalconry_Http_Uri);
	ZEPHIR_INIT(Phalconry_Http_Util_MimeType);
	ZEPHIR_INIT(Phalconry_Mvc_Application);
	ZEPHIR_INIT(Phalconry_Mvc_Application_Bootstrap);
	ZEPHIR_INIT(Phalconry_Mvc_Application_Exception);
	ZEPHIR_INIT(Phalconry_Mvc_Application_Handler);
	ZEPHIR_INIT(Phalconry_Mvc_Env);
	ZEPHIR_INIT(Phalconry_Mvc_Hmvc_Exception);
	ZEPHIR_INIT(Phalconry_Mvc_Hmvc_Request);
	ZEPHIR_INIT(Phalconry_Mvc_Module);
	ZEPHIR_INIT(Phalconry_Mvc_Module_Manager);
	ZEPHIR_INIT(Phalconry_Mvc_Plugin);
	ZEPHIR_INIT(Phalconry_Mvc_Plugin_Exception);
	ZEPHIR_INIT(Phalconry_Mvc_Plugin_Manager);
	ZEPHIR_INIT(Phalconry_Mvc_Responder);
	ZEPHIR_INIT(Phalconry_Text);
	ZEPHIR_INIT(Phalconry_VarType);
	ZEPHIR_INIT(Phalconry_WebService_Exception);
	ZEPHIR_INIT(Phalconry_WebService_Factory);
	ZEPHIR_INIT(Phalconry_WebService_Manager);
	ZEPHIR_INIT(Phalconry_WebService_Service);

#if PHP_VERSION_ID < 50500
	setlocale(LC_ALL, old_lc_all);
	free(old_lc_all);
#endif
	return SUCCESS;
}

#ifndef ZEPHIR_RELEASE
static PHP_MSHUTDOWN_FUNCTION(phalconry)
{

	zephir_deinitialize_memory(TSRMLS_C);
	UNREGISTER_INI_ENTRIES();
	return SUCCESS;
}
#endif

/**
 * Initialize globals on each request or each thread started
 */
static void php_zephir_init_globals(zend_phalconry_globals *phalconry_globals TSRMLS_DC)
{
	phalconry_globals->initialized = 0;

	/* Memory options */
	phalconry_globals->active_memory = NULL;

	/* Virtual Symbol Tables */
	phalconry_globals->active_symbol_table = NULL;

	/* Cache Enabled */
	phalconry_globals->cache_enabled = 1;

	/* Recursive Lock */
	phalconry_globals->recursive_lock = 0;

	/* Static cache */
	memset(phalconry_globals->scache, '\0', sizeof(zephir_fcall_cache_entry*) * ZEPHIR_MAX_CACHE_SLOTS);


}

static PHP_RINIT_FUNCTION(phalconry)
{

	zend_phalconry_globals *phalconry_globals_ptr = ZEPHIR_VGLOBAL;

	php_zephir_init_globals(phalconry_globals_ptr TSRMLS_CC);
	//zephir_init_interned_strings(TSRMLS_C);

	zephir_initialize_memory(phalconry_globals_ptr TSRMLS_CC);


	return SUCCESS;
}

static PHP_RSHUTDOWN_FUNCTION(phalconry)
{

	

	zephir_deinitialize_memory(TSRMLS_C);
	return SUCCESS;
}

static PHP_MINFO_FUNCTION(phalconry)
{
	php_info_print_box_start(0);
	php_printf("%s", PHP_PHALCONRY_DESCRIPTION);
	php_info_print_box_end();

	php_info_print_table_start();
	php_info_print_table_header(2, PHP_PHALCONRY_NAME, "enabled");
	php_info_print_table_row(2, "Author", PHP_PHALCONRY_AUTHOR);
	php_info_print_table_row(2, "Version", PHP_PHALCONRY_VERSION);
	php_info_print_table_row(2, "Build Date", __DATE__ " " __TIME__ );
	php_info_print_table_row(2, "Powered by Zephir", "Version " PHP_PHALCONRY_ZEPVERSION);
	php_info_print_table_end();

	DISPLAY_INI_ENTRIES();
}

static PHP_GINIT_FUNCTION(phalconry)
{
	php_zephir_init_globals(phalconry_globals TSRMLS_CC);
}

static PHP_GSHUTDOWN_FUNCTION(phalconry)
{

}


zend_function_entry php_phalconry_functions[] = {
ZEND_FE_END

};

zend_module_entry phalconry_module_entry = {
	STANDARD_MODULE_HEADER_EX,
	NULL,
	NULL,
	PHP_PHALCONRY_EXTNAME,
	php_phalconry_functions,
	PHP_MINIT(phalconry),
#ifndef ZEPHIR_RELEASE
	PHP_MSHUTDOWN(phalconry),
#else
	NULL,
#endif
	PHP_RINIT(phalconry),
	PHP_RSHUTDOWN(phalconry),
	PHP_MINFO(phalconry),
	PHP_PHALCONRY_VERSION,
	ZEND_MODULE_GLOBALS(phalconry),
	PHP_GINIT(phalconry),
	PHP_GSHUTDOWN(phalconry),
	NULL,
	STANDARD_MODULE_PROPERTIES_EX
};

#ifdef COMPILE_DL_PHALCONRY
ZEND_GET_MODULE(phalconry)
#endif
