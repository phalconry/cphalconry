
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


ZEPHIR_INIT_CLASS(Phalconry_WebService_ServiceInterface) {

	ZEPHIR_REGISTER_INTERFACE(Phalconry\\WebService, ServiceInterface, phalconry, webservice_serviceinterface, phalconry_webservice_serviceinterface_method_entry);

	return SUCCESS;

}

/**
 * Returns the HTTP client
 *
 * @return \Phalconry\Http\Client
 */
ZEPHIR_DOC_METHOD(Phalconry_WebService_ServiceInterface, getClient);

/**
 * Returns a URL to the service using the given args
 *
 * @param array $args [Optional]
 * @return string
 */
ZEPHIR_DOC_METHOD(Phalconry_WebService_ServiceInterface, buildUrl);

/**
 * Returns a new HTTP request
 *
 * @param string $url [Optional] Request URL
 * @param string $method [Optional] HTTP request method
 * @param array $headers [Optional] Request headers
 * @return \Phalconry\Http\Client\Request
 */
ZEPHIR_DOC_METHOD(Phalconry_WebService_ServiceInterface, createRequest);

/**
 * Returns the response body decoded to a PHP object
 *
 * @param mixed $body
 * @return object
 */
ZEPHIR_DOC_METHOD(Phalconry_WebService_ServiceInterface, buildResponseBody);

