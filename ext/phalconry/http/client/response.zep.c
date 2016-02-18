
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
#include "kernel/object.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/string.h"


/**
 * Represents an incoming HTTP message (in response to a sent Request).
 */
ZEPHIR_INIT_CLASS(Phalconry_Http_Client_Response) {

	ZEPHIR_REGISTER_CLASS_EX(Phalconry\\Http\\Client, Response, phalconry, http_client_response, phalconry_http_client_message_ce, phalconry_http_client_response_method_entry, 0);

	/**
	 * @var mixed
	 */
	zend_declare_property_null(phalconry_http_client_response_ce, SL("body"), ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

/**
 * Sets the response body
 *
 * @param mixed body
 * @return \Phalconry\Http\Client\Response
 */
PHP_METHOD(Phalconry_Http_Client_Response, setBody) {

	zval *body;

	zephir_fetch_params(0, 1, 0, &body);



	zephir_update_property_this(this_ptr, SL("body"), body TSRMLS_CC);
	RETURN_THISW();

}

/**
 * Returns the response body
 *
 * @return mixed
 */
PHP_METHOD(Phalconry_Http_Client_Response, getBody) {


	RETURN_MEMBER(this_ptr, "body");

}

/**
 * Parses a string or array of headers into the object
 *
 * @param string|array headers
 * @return \Phalconry\Http\Client\Response
 */
PHP_METHOD(Phalconry_Http_Client_Response, parseHeaders) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *headers, *_0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &headers);



	_0 = zephir_fetch_nproperty_this(this_ptr, SL("header"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(NULL, _0, "parse", NULL, 0, headers);
	zephir_check_call_status();
	RETURN_THIS();

}

/**
 * Returns the response body decoded to a object, if possible, otherwise boolean false.
 *
 * Uses the "Content-Type" header to determine if the body can be decoded.
 *
 * Currently, the following formats can be decoded:
 *  * JSON - with Content-Type header "application/json"
 *  * XML - with Content-Type header "application/xml" or "text/xml"
 *
 * @return object|boolean
 */
PHP_METHOD(Phalconry_Http_Client_Response, getBodyDecoded) {

	zend_bool _2;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *contentType = NULL, *_0, *_1;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(_0);
	ZVAL_STRING(_0, "Content-Type", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&contentType, this_ptr, "getheader", NULL, 0, _0);
	zephir_check_temp_parameter(_0);
	zephir_check_call_status();
	if (zephir_start_with_str(contentType, SL("application/json"))) {
		_1 = zephir_fetch_nproperty_this(this_ptr, SL("body"), PH_NOISY_CC);
		zephir_json_decode(return_value, &(return_value), _1, 0  TSRMLS_CC);
		RETURN_MM();
	}
	_2 = zephir_start_with_str(contentType, SL("application/xml"));
	if (!(_2)) {
		_2 = zephir_start_with_str(contentType, SL("text/xml"));
	}
	if (_2) {
		_1 = zephir_fetch_nproperty_this(this_ptr, SL("body"), PH_NOISY_CC);
		ZEPHIR_RETURN_CALL_FUNCTION("simplexml_load_string", NULL, 42, _1);
		zephir_check_call_status();
		RETURN_MM();
	}
	RETURN_MM_BOOL(0);

}

