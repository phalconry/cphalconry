
extern zend_class_entry *phalconry_http_client_adapter_adapterinterface_ce;

ZEPHIR_INIT_CLASS(Phalconry_Http_Client_Adapter_AdapterInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconry_http_client_adapter_adapterinterface_setoption, 0, 0, 2)
	ZEND_ARG_INFO(0, option)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconry_http_client_adapter_adapterinterface_setoptions, 0, 0, 1)
	ZEND_ARG_INFO(0, options)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconry_http_client_adapter_adapterinterface_settimeout, 0, 0, 1)
	ZEND_ARG_INFO(0, timeout)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconry_http_client_adapter_adapterinterface_setproxy, 0, 0, 1)
	ZEND_ARG_INFO(0, host)
	ZEND_ARG_INFO(0, port)
	ZEND_ARG_INFO(0, user)
	ZEND_ARG_INFO(0, pass)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconry_http_client_adapter_adapterinterface_get, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, request, Phalconry\\Http\\Client\\Request, 0)
	ZEND_ARG_INFO(0, params)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconry_http_client_adapter_adapterinterface_head, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, request, Phalconry\\Http\\Client\\Request, 0)
	ZEND_ARG_INFO(0, params)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconry_http_client_adapter_adapterinterface_delete, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, request, Phalconry\\Http\\Client\\Request, 0)
	ZEND_ARG_INFO(0, params)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconry_http_client_adapter_adapterinterface_post, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, request, Phalconry\\Http\\Client\\Request, 0)
	ZEND_ARG_INFO(0, params)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconry_http_client_adapter_adapterinterface_put, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, request, Phalconry\\Http\\Client\\Request, 0)
	ZEND_ARG_INFO(0, params)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconry_http_client_adapter_adapterinterface___invoke, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, request, Phalconry\\Http\\Client\\Request, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalconry_http_client_adapter_adapterinterface_method_entry) {
	PHP_ABSTRACT_ME(Phalconry_Http_Client_Adapter_AdapterInterface, setOption, arginfo_phalconry_http_client_adapter_adapterinterface_setoption)
	PHP_ABSTRACT_ME(Phalconry_Http_Client_Adapter_AdapterInterface, setOptions, arginfo_phalconry_http_client_adapter_adapterinterface_setoptions)
	PHP_ABSTRACT_ME(Phalconry_Http_Client_Adapter_AdapterInterface, setTimeout, arginfo_phalconry_http_client_adapter_adapterinterface_settimeout)
	PHP_ABSTRACT_ME(Phalconry_Http_Client_Adapter_AdapterInterface, setProxy, arginfo_phalconry_http_client_adapter_adapterinterface_setproxy)
	PHP_ABSTRACT_ME(Phalconry_Http_Client_Adapter_AdapterInterface, get, arginfo_phalconry_http_client_adapter_adapterinterface_get)
	PHP_ABSTRACT_ME(Phalconry_Http_Client_Adapter_AdapterInterface, head, arginfo_phalconry_http_client_adapter_adapterinterface_head)
	PHP_ABSTRACT_ME(Phalconry_Http_Client_Adapter_AdapterInterface, delete, arginfo_phalconry_http_client_adapter_adapterinterface_delete)
	PHP_ABSTRACT_ME(Phalconry_Http_Client_Adapter_AdapterInterface, post, arginfo_phalconry_http_client_adapter_adapterinterface_post)
	PHP_ABSTRACT_ME(Phalconry_Http_Client_Adapter_AdapterInterface, put, arginfo_phalconry_http_client_adapter_adapterinterface_put)
	PHP_ABSTRACT_ME(Phalconry_Http_Client_Adapter_AdapterInterface, __invoke, arginfo_phalconry_http_client_adapter_adapterinterface___invoke)
  PHP_FE_END
};
