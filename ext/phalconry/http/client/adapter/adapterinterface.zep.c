
#ifdef HAVE_CONFIG_H
#include "../../../../ext_config.h"
#endif

#include <php.h>
#include "../../../../php_ext.h"
#include "../../../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


ZEPHIR_INIT_CLASS(Phalconry_Http_Client_Adapter_AdapterInterface) {

	ZEPHIR_REGISTER_INTERFACE(Phalconry\\Http\\Client\\Adapter, AdapterInterface, phalconry, http_client_adapter_adapterinterface, phalconry_http_client_adapter_adapterinterface_method_entry);

	return SUCCESS;

}

ZEPHIR_DOC_METHOD(Phalconry_Http_Client_Adapter_AdapterInterface, setOption);

ZEPHIR_DOC_METHOD(Phalconry_Http_Client_Adapter_AdapterInterface, setOptions);

ZEPHIR_DOC_METHOD(Phalconry_Http_Client_Adapter_AdapterInterface, setTimeout);

ZEPHIR_DOC_METHOD(Phalconry_Http_Client_Adapter_AdapterInterface, setProxy);

ZEPHIR_DOC_METHOD(Phalconry_Http_Client_Adapter_AdapterInterface, get);

ZEPHIR_DOC_METHOD(Phalconry_Http_Client_Adapter_AdapterInterface, head);

ZEPHIR_DOC_METHOD(Phalconry_Http_Client_Adapter_AdapterInterface, delete);

ZEPHIR_DOC_METHOD(Phalconry_Http_Client_Adapter_AdapterInterface, post);

ZEPHIR_DOC_METHOD(Phalconry_Http_Client_Adapter_AdapterInterface, put);

ZEPHIR_DOC_METHOD(Phalconry_Http_Client_Adapter_AdapterInterface, __invoke);

