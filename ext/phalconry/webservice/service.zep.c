
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"
#include "kernel/object.h"


/**
 * Represents a web service
 */
ZEPHIR_INIT_CLASS(Phalconry_WebService_Service) {

	ZEPHIR_REGISTER_CLASS_EX(Phalconry\\WebService, Service, phalconry, webservice_service, zephir_get_internal_ce(SS("phalcon\\di\\injectable") TSRMLS_CC), phalconry_webservice_service_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	zend_class_implements(phalconry_webservice_service_ce TSRMLS_CC, 1, phalconry_webservice_serviceinterface_ce);
	return SUCCESS;

}

/**
 * Returns the HTTP client from the DI container
 *
 * @return \Phalconry\Http\Client
 */
PHP_METHOD(Phalconry_WebService_Service, getClient) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *_0 = NULL, *_1;

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getdi", NULL);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_1);
	ZVAL_STRING(_1, "httpClient", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_RETURN_CALL_METHOD(_0, "get", NULL, _1);
	zephir_check_temp_parameter(_1);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Returns a new HTTP request
 *
 * @param string|array url [Optional] Request URL or args for buildUrl()
 * @param string method [Optional] HTTP request method
 * @param array headers [Optional] Request headers
 * @return \Phalconry\Http\Client\Request
 */
PHP_METHOD(Phalconry_WebService_Service, createRequest) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *headers = NULL;
	zval *url = NULL, *method = NULL, *headers_param = NULL, *request, *_0 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 3, &url, &method, &headers_param);

	if (!url) {
		ZEPHIR_CPY_WRT(url, ZEPHIR_GLOBAL(global_null));
	} else {
		ZEPHIR_SEPARATE_PARAM(url);
	}
	if (!method) {
		method = ZEPHIR_GLOBAL(global_null);
	}
	if (!headers_param) {
		ZEPHIR_INIT_VAR(headers);
		array_init(headers);
	} else {
	headers = headers_param;

	}


	if (Z_TYPE_P(url) == IS_ARRAY) {
		ZEPHIR_CALL_METHOD(&_0, this_ptr, "buildurl", NULL, url);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(url, _0);
	}
	ZEPHIR_INIT_VAR(request);
	object_init_ex(request, phalconry_http_client_request_ce);
	ZEPHIR_CALL_METHOD(NULL, request, "__construct", NULL, url);
	zephir_check_call_status();
	if (Z_TYPE_P(method) == IS_STRING) {
		ZEPHIR_CALL_METHOD(NULL, request, "setmethod", NULL, method);
		zephir_check_call_status();
	}
	if (!(ZEPHIR_IS_EMPTY(headers))) {
		ZEPHIR_CALL_METHOD(NULL, request, "addheaders", NULL, headers);
		zephir_check_call_status();
	}
	RETURN_CCTOR(request);

}

/**
 * Sends a request and returns the response
 *
 * @param \Phalconry\Http\Client\Request request
 * @return \Phalconry\Http\Client\Response
 */
PHP_METHOD(Phalconry_WebService_Service, send) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *request, *_0 = NULL, *_1 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &request);



	if (!(zephir_instance_of_ev(request, phalconry_http_client_request_ce TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "Parameter 'request' must be an instance of 'Phalconry\\Http\\Client\\Request'", "", 0);
		return;
	}
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getclient", NULL);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_1, _0, "send", NULL, request);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(_1, "getresponse", NULL);
	zephir_check_call_status();
	RETURN_MM();

}

