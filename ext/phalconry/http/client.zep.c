
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
#include "kernel/object.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "kernel/exception.h"
#include "ext/spl/spl_exceptions.h"


ZEPHIR_INIT_CLASS(Phalconry_Http_Client) {

	ZEPHIR_REGISTER_CLASS_EX(Phalconry\\Http, Client, phalconry, http_client, zephir_get_internal_ce(SS("phalcon\\di\\injectable") TSRMLS_CC), phalconry_http_client_method_entry, 0);

	/**
	 * The last request sent
	 * @var \Phalconry\Http\Client\Request
	 */
	zend_declare_property_null(phalconry_http_client_ce, SL("_lastRequest"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * The adapter classname
	 * @var string
	 */
	zend_declare_property_null(phalconry_http_client_ce, SL("adapterClass"), ZEND_ACC_PRIVATE|ZEND_ACC_STATIC TSRMLS_CC);

	/**
	 * HTTP client library version
	 * @var string
	 */
	zend_declare_class_constant_string(phalconry_http_client_ce, SL("VERSION"), "0.0.2" TSRMLS_CC);

	return SUCCESS;

}

/**
 * Returns the client adapter
 *
 * @return \Phalconry\Http\Client\Adapter\AdapterInterface
 * @throws \Phalconry\Http\Client\Adapter\Exception if no adapters are available
 */
PHP_METHOD(Phalconry_Http_Client, getAdapter) {

	zephir_nts_static zephir_fcall_cache_entry *_3 = NULL, *_5 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *_0, *_1 = NULL, *_2 = NULL, *_4 = NULL;

	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(_0);
	zephir_read_static_property_ce(&_0, phalconry_http_client_ce, SL("adapterClass") TSRMLS_CC);
	if (Z_TYPE_P(_0) == IS_STRING) {
		_1 = zephir_fetch_static_property_ce(phalconry_http_client_ce, SL("adapterClass") TSRMLS_CC);
		ZEPHIR_LAST_CALL_STATUS = zephir_create_instance(return_value, _1 TSRMLS_CC);
		zephir_check_call_status();
		RETURN_MM();
	}
	ZEPHIR_CALL_CE_STATIC(&_2, phalconry_http_client_adapter_curl_ce, "isavailable", &_3);
	zephir_check_call_status();
	if (zephir_is_true(_2)) {
		ZEPHIR_INIT_ZVAL_NREF(_1);
		ZEPHIR_INIT_VAR(_1);
		ZVAL_STRING(_1, "Phalconry\\Http\\Client\\Adapter\\Curl", 1);
		zephir_update_static_property_ce(phalconry_http_client_ce, SL("adapterClass"), &_1 TSRMLS_CC);
		object_init_ex(return_value, phalconry_http_client_adapter_curl_ce);
		ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL);
		zephir_check_call_status();
		RETURN_MM();
	}
	ZEPHIR_CALL_CE_STATIC(&_4, phalconry_http_client_adapter_stream_ce, "isavailable", &_5);
	zephir_check_call_status();
	if (zephir_is_true(_4)) {
		ZEPHIR_INIT_ZVAL_NREF(_1);
		ZEPHIR_INIT_NVAR(_1);
		ZVAL_STRING(_1, "Phalconry\\Http\\Client\\Adapter\\Stream", 1);
		zephir_update_static_property_ce(phalconry_http_client_ce, SL("adapterClass"), &_1 TSRMLS_CC);
		object_init_ex(return_value, phalconry_http_client_adapter_stream_ce);
		ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL);
		zephir_check_call_status();
		RETURN_MM();
	}
	ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalconry_http_client_adapter_exception_ce, "No client adapters are available", "phalconry/http/client.zep", 56);
	return;

}

/**
 * Creates and returns a new request object
 *
 * @param string uri
 * @param string method [Optional] Default "GET"
 * @param array params [Optional] Query parameters
 * @param array headers [Optional] Extra headers
 * @return \Phalconry\Http\Client\Request
 */
PHP_METHOD(Phalconry_Http_Client, createHttpRequest) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *params = NULL, *headers = NULL;
	zval *method = NULL;
	zval *uri, *method_param = NULL, *params_param = NULL, *headers_param = NULL, *request;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 3, &uri, &method_param, &params_param, &headers_param);

	if (!method_param) {
		ZEPHIR_INIT_VAR(method);
		ZVAL_STRING(method, "GET", 1);
	} else {
	if (unlikely(Z_TYPE_P(method_param) != IS_STRING && Z_TYPE_P(method_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'method' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(method_param) == IS_STRING)) {
		zephir_get_strval(method, method_param);
	} else {
		ZEPHIR_INIT_VAR(method);
		ZVAL_EMPTY_STRING(method);
	}
	}
	if (!params_param) {
		ZEPHIR_INIT_VAR(params);
		array_init(params);
	} else {
		zephir_get_arrval(params, params_param);
	}
	if (!headers_param) {
		ZEPHIR_INIT_VAR(headers);
		array_init(headers);
	} else {
		zephir_get_arrval(headers, headers_param);
	}


	ZEPHIR_INIT_VAR(request);
	object_init_ex(request, phalconry_http_client_request_ce);
	ZEPHIR_CALL_METHOD(NULL, request, "__construct", NULL, uri);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, request, "setmethod", NULL, method);
	zephir_check_call_status();
	if (!(ZEPHIR_IS_EMPTY(params))) {
		ZEPHIR_CALL_METHOD(NULL, request, "addqueryparams", NULL, params);
		zephir_check_call_status();
	}
	if (!(ZEPHIR_IS_EMPTY(headers))) {
		ZEPHIR_CALL_METHOD(NULL, request, "addheaders", NULL, headers);
		zephir_check_call_status();
	}
	RETURN_CCTOR(request);

}

/**
 * Creates and returns a new request object
 *
 * @param string uri
 * @param string method [Optional] Default "GET"
 * @param array params [Optional] Query parameters
 * @param array headers [Optional] Extra headers
 * @return \Phalconry\Http\Client\Request
 */
PHP_METHOD(Phalconry_Http_Client, createRequest) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *params = NULL, *headers = NULL;
	zval *method = NULL, *_0 = NULL, *_2 = NULL;
	zval *uri, *method_param = NULL, *params_param = NULL, *headers_param = NULL, *request = NULL, *_1, *_3, *_4;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 3, &uri, &method_param, &params_param, &headers_param);

	if (!method_param) {
		ZEPHIR_INIT_VAR(method);
		ZVAL_STRING(method, "GET", 1);
	} else {
	if (unlikely(Z_TYPE_P(method_param) != IS_STRING && Z_TYPE_P(method_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'method' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(method_param) == IS_STRING)) {
		zephir_get_strval(method, method_param);
	} else {
		ZEPHIR_INIT_VAR(method);
		ZVAL_EMPTY_STRING(method);
	}
	}
	if (!params_param) {
		ZEPHIR_INIT_VAR(params);
		array_init(params);
	} else {
		zephir_get_arrval(params, params_param);
	}
	if (!headers_param) {
		ZEPHIR_INIT_VAR(headers);
		array_init(headers);
	} else {
		zephir_get_arrval(headers, headers_param);
	}


	ZEPHIR_CALL_SELF(&request, "createhttprequest", NULL, uri, method, params, headers);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, request, "setclient", NULL, this_ptr);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_0);
	ZEPHIR_INIT_NVAR(_0);
	ZVAL_STRING(_0, "_eventsManager", 1);
	ZEPHIR_OBS_VAR(_1);
	zephir_read_property_zval(&_1, this_ptr, _0, PH_NOISY_CC);
	if (Z_TYPE_P(_1) == IS_OBJECT) {
		ZEPHIR_INIT_VAR(_2);
		ZEPHIR_INIT_NVAR(_2);
		ZVAL_STRING(_2, "_eventsManager", 1);
		ZEPHIR_OBS_VAR(_3);
		zephir_read_property_zval(&_3, this_ptr, _2, PH_NOISY_CC);
		ZEPHIR_INIT_VAR(_4);
		ZVAL_STRING(_4, "http-client:createRequest", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(NULL, _3, "fire", NULL, _4, this_ptr, request);
		zephir_check_temp_parameter(_4);
		zephir_check_call_status();
	}
	RETURN_CCTOR(request);

}

/**
 * Sends a request.
 *
 * @param \Phalconry\Http\Client\Request request
 * @return \Phalconry\Http\Client
 */
PHP_METHOD(Phalconry_Http_Client, send) {

	zval *_2 = NULL, *_4 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *request, *_0 = NULL, *_1 = NULL, *_3, *_5, *_6;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &request);



	if (!(zephir_instance_of_ev(request, phalconry_http_client_request_ce TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "Parameter 'request' must be an instance of 'Phalconry\\Http\\Client\\Request'", "", 0);
		return;
	}
	ZEPHIR_CALL_SELF(&_0, "getadapter", NULL);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_1, _0, "__invoke", NULL, request);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, request, "setresponse", NULL, _1);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_2);
	ZEPHIR_INIT_NVAR(_2);
	ZVAL_STRING(_2, "_eventsManager", 1);
	ZEPHIR_OBS_VAR(_3);
	zephir_read_property_zval(&_3, this_ptr, _2, PH_NOISY_CC);
	if (Z_TYPE_P(_3) == IS_OBJECT) {
		ZEPHIR_INIT_VAR(_4);
		ZEPHIR_INIT_NVAR(_4);
		ZVAL_STRING(_4, "_eventsManager", 1);
		ZEPHIR_OBS_VAR(_5);
		zephir_read_property_zval(&_5, this_ptr, _4, PH_NOISY_CC);
		ZEPHIR_INIT_VAR(_6);
		ZVAL_STRING(_6, "http-client:send", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(NULL, _5, "fire", NULL, _6, this_ptr, request);
		zephir_check_temp_parameter(_6);
		zephir_check_call_status();
	}
	zephir_update_property_this(this_ptr, SL("_lastRequest"), request TSRMLS_CC);
	RETURN_THIS();

}

/**
 * Returns the response associated with a given request or the last request sent if none given.
 *
 * @param \Phalconry\Http\Client\Request request [Optional]
 * @return \Phalconry\Http\Client\Response
 * @throws \Phalconry\Http\Client\Exception if no requests have been sent
 */
PHP_METHOD(Phalconry_Http_Client, getResponse) {

	int ZEPHIR_LAST_CALL_STATUS;
	zend_bool _0;
	zval *request = NULL, *_1, *_2;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &request);

	if (!request) {
		request = ZEPHIR_GLOBAL(global_null);
	}


	_0 = Z_TYPE_P(request) != IS_NULL;
	if (_0) {
		_0 = !(zephir_instance_of_ev(request, phalconry_http_client_request_ce TSRMLS_CC));
	}
	if (_0) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "Parameter 'request' must be an instance of 'Phalconry\\Http\\Client\\Request'", "", 0);
		return;
	}
	if (Z_TYPE_P(request) == IS_OBJECT) {
		ZEPHIR_RETURN_CALL_METHOD(request, "getresponse", NULL);
		zephir_check_call_status();
		RETURN_MM();
	}
	ZEPHIR_OBS_VAR(_1);
	zephir_read_property_this(&_1, this_ptr, SL("_lastRequest"), PH_NOISY_CC);
	if (Z_TYPE_P(_1) == IS_OBJECT) {
		_2 = zephir_fetch_nproperty_this(this_ptr, SL("_lastRequest"), PH_NOISY_CC);
		ZEPHIR_RETURN_CALL_METHOD(_2, "getresponse", NULL);
		zephir_check_call_status();
		RETURN_MM();
	}
	ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalconry_http_client_exception_ce, "No requests have been sent", "phalconry/http/client.zep", 146);
	return;

}

