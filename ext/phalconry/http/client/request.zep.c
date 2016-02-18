
#ifdef HAVE_CONFIG_H
#include "../../../ext_config.h"
#endif

#include <php.h>
#include "../../../php_ext.h"
#include "../../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/fcall.h"
#include "kernel/memory.h"
#include "kernel/string.h"
#include "kernel/object.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"
#include "kernel/operators.h"


/**
 * Represents an outgoing HTTP message
 */
ZEPHIR_INIT_CLASS(Phalconry_Http_Client_Request) {

	ZEPHIR_REGISTER_CLASS_EX(Phalconry\\Http\\Client, Request, phalconry, http_client_request, phalconry_http_client_message_ce, phalconry_http_client_request_method_entry, 0);

	/**
	 * @var string
	 */
	zend_declare_property_string(phalconry_http_client_request_ce, SL("method"), "GET", ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * @var \Phalconry\Http\Uri
	 */
	zend_declare_property_null(phalconry_http_client_request_ce, SL("uri"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * @var \Phalconry\Http\Client\Response
	 */
	zend_declare_property_null(phalconry_http_client_request_ce, SL("response"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * @var \Phalconry\Http\Client
	 */
	zend_declare_property_null(phalconry_http_client_request_ce, SL("client"), ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

/**
 * Constructor
 *
 * @param string baseUri [Optional]
 */
PHP_METHOD(Phalconry_Http_Client_Request, __construct) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
	zval *baseUri = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &baseUri);

	if (!baseUri) {
		baseUri = ZEPHIR_GLOBAL(global_null);
	}


	ZEPHIR_CALL_PARENT(NULL, phalconry_http_client_request_ce, this_ptr, "__construct", &_0, 26);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "seturi", NULL, 0, baseUri);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * Sets the request method
 *
 * @param string httpMethod
 * @return \Phalconry\Http\Client\Request
 */
PHP_METHOD(Phalconry_Http_Client_Request, setMethod) {

	zval *httpMethod_param = NULL, *_0;
	zval *httpMethod = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &httpMethod_param);

	if (unlikely(Z_TYPE_P(httpMethod_param) != IS_STRING && Z_TYPE_P(httpMethod_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'httpMethod' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(httpMethod_param) == IS_STRING)) {
		zephir_get_strval(httpMethod, httpMethod_param);
	} else {
		ZEPHIR_INIT_VAR(httpMethod);
		ZVAL_EMPTY_STRING(httpMethod);
	}


	ZEPHIR_INIT_VAR(_0);
	zephir_fast_strtoupper(_0, httpMethod);
	zephir_update_property_this(this_ptr, SL("method"), _0 TSRMLS_CC);
	RETURN_THIS();

}

/**
 * Returns the request method
 *
 * Default method is "GET"
 *
 * @return string
 */
PHP_METHOD(Phalconry_Http_Client_Request, getMethod) {


	RETURN_MEMBER(this_ptr, "method");

}

/**
 * Sets the response message
 *
 * @param \Phalconry\Http\Client\Response response
 * @return \Phalconry\Http\Client\Request
 */
PHP_METHOD(Phalconry_Http_Client_Request, setResponse) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *response;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &response);



	ZEPHIR_CALL_METHOD(NULL, response, "setparent", NULL, 0, this_ptr);
	zephir_check_call_status();
	zephir_update_property_this(this_ptr, SL("response"), response TSRMLS_CC);
	RETURN_THIS();

}

/**
 * Returns the request's response
 *
 * @return \Phalconry\Http\Client\Response
 */
PHP_METHOD(Phalconry_Http_Client_Request, getResponse) {


	RETURN_MEMBER(this_ptr, "response");

}

/**
 * Sets the request URI
 *
 * @param mixed uri
 * @return \Phalconry\Http\Client\Request
 */
PHP_METHOD(Phalconry_Http_Client_Request, setUri) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *uri, *_0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &uri);



	ZEPHIR_INIT_VAR(_0);
	object_init_ex(_0, phalconry_http_uri_ce);
	ZEPHIR_CALL_METHOD(NULL, _0, "__construct", NULL, 33, uri);
	zephir_check_call_status();
	zephir_update_property_this(this_ptr, SL("uri"), _0 TSRMLS_CC);
	RETURN_THIS();

}

/**
 * Returns the request URI
 *
 * @return \Phalconry\Http\Uri
 */
PHP_METHOD(Phalconry_Http_Client_Request, getUri) {


	RETURN_MEMBER(this_ptr, "uri");

}

/**
 * Resolves the request URI using the given argument
 *
 * @see \Phalconry\Http\Uri::resolve()
 *
 * @param mixed uri
 * @return \Phalconry\Http\Uri
 */
PHP_METHOD(Phalconry_Http_Client_Request, resolveUri) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *uri, *_0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &uri);



	_0 = zephir_fetch_nproperty_this(this_ptr, SL("uri"), PH_NOISY_CC);
	ZEPHIR_RETURN_CALL_METHOD(_0, "resolve", NULL, 0, uri);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Adds an array of query parameters to the request URI
 *
 * @param array params
 * @return \Phalconry\Http\Client\Request
 */
PHP_METHOD(Phalconry_Http_Client_Request, addQueryParams) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *params_param = NULL, *_0;
	zval *params = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &params_param);

	zephir_get_arrval(params, params_param);


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("uri"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(NULL, _0, "extendquery", NULL, 0, params);
	zephir_check_call_status();
	RETURN_THIS();

}

/**
 * Adds an array of headers to the request
 *
 * @param array headers
 * @return \Phalconry\Http\Client\Request
 */
PHP_METHOD(Phalconry_Http_Client_Request, addHeaders) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *headers_param = NULL, *_0;
	zval *headers = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &headers_param);

	zephir_get_arrval(headers, headers_param);


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("header"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(NULL, _0, "addmultiple", NULL, 0, headers);
	zephir_check_call_status();
	RETURN_THIS();

}

/**
 * Sets a single request header
 *
 * @param string name
 * @param string value
 * @return \Phalconry\Http\Client\Request
 */
PHP_METHOD(Phalconry_Http_Client_Request, setHeader) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *name_param = NULL, *value_param = NULL, *_0;
	zval *name = NULL, *value = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &name_param, &value_param);

	zephir_get_strval(name, name_param);
	zephir_get_strval(value, value_param);


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("header"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(NULL, _0, "set", NULL, 0, name, value);
	zephir_check_call_status();
	RETURN_THIS();

}

/**
 * Builds the header fields
 *
 * @return \Phalconry\Http\Client\Request
 */
PHP_METHOD(Phalconry_Http_Client_Request, buildHeaderFields) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *_0, *_1;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("header"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_1);
	ZVAL_LONG(_1, 2);
	ZEPHIR_CALL_METHOD(NULL, _0, "build", NULL, 0, _1);
	zephir_check_call_status();
	RETURN_THIS();

}

/**
 * Sets the request client object
 *
 * @param \Phalconry\Http\Client client
 * @return \Phalconry\Http\Client\Request
 */
PHP_METHOD(Phalconry_Http_Client_Request, setClient) {

	zval *client;

	zephir_fetch_params(0, 1, 0, &client);



	zephir_update_property_this(this_ptr, SL("client"), client TSRMLS_CC);
	RETURN_THISW();

}

/**
 * Returns the request client object, if set
 *
 * @return \Phalconry\Http\Client
 */
PHP_METHOD(Phalconry_Http_Client_Request, getClient) {


	RETURN_MEMBER(this_ptr, "client");

}

/**
 * Sends the request
 *
 * @return \Phalconry\Http\Client\Request
 * @throws \RuntimeException if client is not set and cannot be retrieved from the default DI container
 */
PHP_METHOD(Phalconry_Http_Client_Request, send) {

	int ZEPHIR_LAST_CALL_STATUS;
	zend_class_entry *_2;
	zval *client = NULL, *_0, *_1 = NULL, *_3;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("client"), PH_NOISY_CC);
	ZEPHIR_CPY_WRT(client, _0);
	if (Z_TYPE_P(client) != IS_OBJECT) {
		_2 = zend_fetch_class(SL("Phalcon\\Di"), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);
		ZEPHIR_CALL_CE_STATIC(&_1, _2, "getdefault", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(_3);
		ZVAL_STRING(_3, "httpClient", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&client, _1, "getshared", NULL, 0, _3);
		zephir_check_temp_parameter(_3);
		zephir_check_call_status();
		if (Z_TYPE_P(client) != IS_OBJECT) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_RuntimeException, "Cannot locate Client", "phalconry/http/client/request.zep", 228);
			return;
		}
	}
	ZEPHIR_CALL_METHOD(NULL, client, "send", NULL, 0, this_ptr);
	zephir_check_call_status();
	RETURN_THIS();

}

/**
 * Alias of send()
 * @return \Phalconry\Http\Client\Request
 */
PHP_METHOD(Phalconry_Http_Client_Request, __invoke) {

	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "send", NULL, 0);
	zephir_check_call_status();
	RETURN_MM();

}

