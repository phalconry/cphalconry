
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
#include "kernel/operators.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/array.h"
#include "kernel/hash.h"
#include "kernel/string.h"
#include "kernel/concat.h"

ZEPHIR_INIT_CLASS(Phalconry_Http_Client_Header) {

	ZEPHIR_REGISTER_CLASS(Phalconry\\Http\\Client, Header, phalconry, http_client_header, phalconry_http_client_header_method_entry, 0);

	zend_declare_property_string(phalconry_http_client_header_ce, SL("version"), "1.0", ZEND_ACC_PUBLIC TSRMLS_CC);

	zend_declare_property_long(phalconry_http_client_header_ce, SL("statusCode"), 0, ZEND_ACC_PUBLIC TSRMLS_CC);

	zend_declare_property_string(phalconry_http_client_header_ce, SL("statusMessage"), "", ZEND_ACC_PUBLIC TSRMLS_CC);

	zend_declare_property_string(phalconry_http_client_header_ce, SL("status"), "", ZEND_ACC_PUBLIC TSRMLS_CC);

	zend_declare_property_null(phalconry_http_client_header_ce, SL("fields"), ZEND_ACC_PRIVATE TSRMLS_CC);

	zend_declare_property_null(phalconry_http_client_header_ce, SL("messages"), ZEND_ACC_PROTECTED|ZEND_ACC_STATIC TSRMLS_CC);

	zend_declare_class_constant_long(phalconry_http_client_header_ce, SL("BUILD_STATUS"), 1 TSRMLS_CC);

	zend_declare_class_constant_long(phalconry_http_client_header_ce, SL("BUILD_FIELDS"), 2 TSRMLS_CC);

	zend_class_implements(phalconry_http_client_header_ce TSRMLS_CC, 1, spl_ce_Countable);
	return SUCCESS;

}

/**
 * Sets a single header field
 *
 * @param string name
 * @param mixed value
 */
PHP_METHOD(Phalconry_Http_Client_Header, set) {

	zval *name_param = NULL, *value;
	zval *name = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &name_param, &value);

	zephir_get_strval(name, name_param);


	zephir_update_property_array(this_ptr, SL("fields"), name, value TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

/**
 * Sets an array of headers
 *
 * @param array fields
 */
PHP_METHOD(Phalconry_Http_Client_Header, setMultiple) {

	zval *fields_param = NULL;
	zval *fields = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &fields_param);

	zephir_get_arrval(fields, fields_param);


	zephir_update_property_this(this_ptr, SL("fields"), fields TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

/**
 * Adds an array of headers
 *
 * @param array fields
 */
PHP_METHOD(Phalconry_Http_Client_Header, addMultiple) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_2 = NULL;
	zval *fields_param = NULL, *_0, *_1 = NULL;
	zval *fields = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &fields_param);

	zephir_get_arrval(fields, fields_param);


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("fields"), PH_NOISY_CC);
	ZEPHIR_CALL_FUNCTION(&_1, "array_combine", &_2, _0, fields);
	zephir_check_call_status();
	zephir_update_property_this(this_ptr, SL("fields"), _1 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

/**
 * Returns a single header field
 *
 * @param string name
 * @return string
 */
PHP_METHOD(Phalconry_Http_Client_Header, get) {

	zval *name_param = NULL, *_0, *_1;
	zval *name = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name_param);

	zephir_get_strval(name, name_param);


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("fields"), PH_NOISY_CC);
	zephir_array_fetch(&_1, _0, name, PH_NOISY | PH_READONLY, "phalconry/http/client/header.zep", 75 TSRMLS_CC);
	RETURN_CTOR(_1);

}

/**
 * Returns all header fields
 *
 * @return array
 */
PHP_METHOD(Phalconry_Http_Client_Header, getAll) {


	RETURN_MEMBER(this_ptr, "fields");

}

/**
 * Determine if a header exists with a specific key.
 *
 * @param string name Key to lookup
 * @return boolean
 */
PHP_METHOD(Phalconry_Http_Client_Header, has) {

	HashTable *_2;
	HashPosition _1;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *name_param = NULL, *key = NULL, *value = NULL, *_0 = NULL, **_3;
	zval *name = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name_param);

	zephir_get_strval(name, name_param);


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getall", NULL);
	zephir_check_call_status();
	zephir_is_iterable(_0, &_2, &_1, 0, 0, "phalconry/http/client/header.zep", 104);
	for (
	  ; zephir_hash_get_current_data_ex(_2, (void**) &_3, &_1) == SUCCESS
	  ; zephir_hash_move_forward_ex(_2, &_1)
	) {
		ZEPHIR_GET_HMKEY(key, _2, _1);
		ZEPHIR_GET_HVALUE(value, _3);
		if (zephir_start_with(key, name, ZEPHIR_GLOBAL(global_true))) {
			RETURN_MM_BOOL(1);
		}
	}
	RETURN_MM_BOOL(0);

}

/**
 * Removes a single header by name
 *
 * @param string name
 */
PHP_METHOD(Phalconry_Http_Client_Header, remove) {

	zval *name_param = NULL, *_0;
	zval *name = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name_param);

	zephir_get_strval(name, name_param);


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("fields"), PH_NOISY_CC);
	zephir_array_unset(&_0, name, PH_SEPARATE);
	ZEPHIR_MM_RESTORE();

}

/**
 * Parses an array or string of headers into the object
 *
 * @param string|array content
 * @return boolean
 */
PHP_METHOD(Phalconry_Http_Client_Header, parse) {

	zephir_fcall_cache_entry *_16 = NULL;
	HashTable *_12;
	HashPosition _11;
	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_1 = NULL, *_4 = NULL, *_6 = NULL, *_15 = NULL;
	zval *content = NULL, *status, *field = NULL, *_0 = NULL, *_2, *_3 = NULL, *_5 = NULL, *_7, *_8, *_9, *_10, **_13, _14 = zval_used_for_init;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &content);

	ZEPHIR_SEPARATE_PARAM(content);


	if (ZEPHIR_IS_EMPTY(content)) {
		RETURN_MM_BOOL(0);
	}
	if (Z_TYPE_P(content) == IS_STRING) {
		ZEPHIR_INIT_VAR(_0);
		zephir_fast_explode_str(_0, SL("\r\n"), content, LONG_MAX TSRMLS_CC);
		ZEPHIR_CALL_FUNCTION(&content, "array_filter", &_1, _0);
		zephir_check_call_status();
	} else if (Z_TYPE_P(content) != IS_ARRAY) {
		RETURN_MM_BOOL(0);
	}
	ZEPHIR_INIT_VAR(status);
	array_init(status);
	zephir_array_fetch_long(&_2, content, 0, PH_NOISY | PH_READONLY, "phalconry/http/client/header.zep", 139 TSRMLS_CC);
	ZEPHIR_INIT_NVAR(_0);
	ZVAL_STRING(_0, "/^HTTP\\/(\\d(?:\\.\\d)?)\\s+(\\d{3})\\s+(.+)/i", ZEPHIR_TEMP_PARAM_COPY);
	Z_SET_ISREF_P(status);
	ZEPHIR_CALL_FUNCTION(&_3, "preg_match", &_4, _0, _2, status);
	zephir_check_temp_parameter(_0);
	Z_UNSET_ISREF_P(status);
	zephir_check_call_status();
	if (zephir_is_true(_3)) {
		Z_SET_ISREF_P(content);
		ZEPHIR_CALL_FUNCTION(&_5, "array_shift", &_6, content);
		Z_UNSET_ISREF_P(content);
		zephir_check_call_status();
		zephir_update_property_this(this_ptr, SL("status"), _5 TSRMLS_CC);
		zephir_array_fetch_long(&_7, status, 1, PH_NOISY | PH_READONLY, "phalconry/http/client/header.zep", 141 TSRMLS_CC);
		zephir_update_property_this(this_ptr, SL("version"), _7 TSRMLS_CC);
		zephir_array_fetch_long(&_8, status, 2, PH_NOISY | PH_READONLY, "phalconry/http/client/header.zep", 142 TSRMLS_CC);
		ZEPHIR_INIT_ZVAL_NREF(_9);
		ZVAL_LONG(_9, zephir_get_intval(_8));
		zephir_update_property_this(this_ptr, SL("statusCode"), _9 TSRMLS_CC);
		zephir_array_fetch_long(&_10, status, 3, PH_NOISY | PH_READONLY, "phalconry/http/client/header.zep", 143 TSRMLS_CC);
		zephir_update_property_this(this_ptr, SL("statusMessage"), _10 TSRMLS_CC);
	}
	zephir_is_iterable(content, &_12, &_11, 0, 0, "phalconry/http/client/header.zep", 157);
	for (
	  ; zephir_hash_get_current_data_ex(_12, (void**) &_13, &_11) == SUCCESS
	  ; zephir_hash_move_forward_ex(_12, &_11)
	) {
		ZEPHIR_GET_HVALUE(field, _13);
		if (Z_TYPE_P(field) != IS_ARRAY) {
			ZEPHIR_INIT_NVAR(_0);
			zephir_fast_explode_str(_0, SL(":"), field, 2  TSRMLS_CC);
			ZEPHIR_SINIT_NVAR(_14);
			ZVAL_STRING(&_14, "trim", 0);
			ZEPHIR_CALL_FUNCTION(&field, "array_map", &_15, &_14, _0);
			zephir_check_call_status();
		}
		if (zephir_fast_count_int(field TSRMLS_CC) == 2) {
			zephir_array_fetch_long(&_7, field, 0, PH_NOISY | PH_READONLY, "phalconry/http/client/header.zep", 153 TSRMLS_CC);
			zephir_array_fetch_long(&_8, field, 1, PH_NOISY | PH_READONLY, "phalconry/http/client/header.zep", 153 TSRMLS_CC);
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "set", &_16, _7, _8);
			zephir_check_call_status();
		}
	}
	RETURN_MM_BOOL(1);

}

/**
 * Builds the headers and possibly the fields
 *
 * @param int flags [Optional] Bitwise BUILD_* class constants. Default 0
 * @return array Header lines
 */
PHP_METHOD(Phalconry_Http_Client_Header, build) {

	HashTable *_5;
	HashPosition _4;
	zval *flags_param = NULL, *lines, *statusMsg = NULL, *field = NULL, *value = NULL, *_0, *_1, *_2, *_3 = NULL, **_6;
	int flags, ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &flags_param);

	if (!flags_param) {
		flags = 0;
	} else {
		flags = zephir_get_intval(flags_param);
	}


	ZEPHIR_INIT_VAR(lines);
	array_init(lines);
	if ((flags & 2)) {
		_0 = zephir_fetch_nproperty_this(this_ptr, SL("statusCode"), PH_NOISY_CC);
		ZEPHIR_CALL_SELF(&statusMsg, "getstatusmessage", NULL, _0);
		zephir_check_call_status();
		if (Z_TYPE_P(statusMsg) == IS_STRING) {
			_1 = zephir_fetch_nproperty_this(this_ptr, SL("version"), PH_NOISY_CC);
			_2 = zephir_fetch_nproperty_this(this_ptr, SL("statusCode"), PH_NOISY_CC);
			ZEPHIR_INIT_VAR(_3);
			ZEPHIR_CONCAT_SVSVSV(_3, "HTTP/", _1, " ", _2, " ", statusMsg);
			zephir_array_append(&lines, _3, PH_SEPARATE, "phalconry/http/client/header.zep", 176);
		}
	}
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("fields"), PH_NOISY_CC);
	zephir_is_iterable(_0, &_5, &_4, 0, 0, "phalconry/http/client/header.zep", 184);
	for (
	  ; zephir_hash_get_current_data_ex(_5, (void**) &_6, &_4) == SUCCESS
	  ; zephir_hash_move_forward_ex(_5, &_4)
	) {
		ZEPHIR_GET_HMKEY(field, _5, _4);
		ZEPHIR_GET_HVALUE(value, _6);
		ZEPHIR_INIT_LNVAR(_3);
		ZEPHIR_CONCAT_VSV(_3, field, ": ", value);
		zephir_array_append(&lines, _3, PH_SEPARATE, "phalconry/http/client/header.zep", 181);
	}
	if ((flags & 2)) {
		zephir_fast_join_str(return_value, SL("\r\n"), lines TSRMLS_CC);
		RETURN_MM();
	}
	RETURN_CCTOR(lines);

}

/**
 * Returns the number of header fields
 *
 * @return int
 */
PHP_METHOD(Phalconry_Http_Client_Header, count) {

	zval *_0;


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("fields"), PH_NOISY_CC);
	RETURN_LONG(zephir_fast_count_int(_0 TSRMLS_CC));

}

/**
 * Returns message text for a given HTTP status code
 *
 * @param int code
 * @return string|null
 */
PHP_METHOD(Phalconry_Http_Client_Header, getStatusMessage) {

	zval *_1;
	zval *code_param = NULL, *_0, *_2, *_3, *_4;
	int code;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &code_param);

	code = zephir_get_intval(code_param);


	ZEPHIR_OBS_VAR(_0);
	zephir_read_static_property_ce(&_0, phalconry_http_client_header_ce, SL("messages") TSRMLS_CC);
	if (Z_TYPE_P(_0) == IS_NULL) {
		ZEPHIR_INIT_VAR(_1);
		array_init_size(_1, 52);
		add_index_stringl(_1, 100, SL("Continue"), 1);
		add_index_stringl(_1, 101, SL("Switching Protocols"), 1);
		add_index_stringl(_1, 200, SL("OK"), 1);
		add_index_stringl(_1, 201, SL("Created"), 1);
		add_index_stringl(_1, 202, SL("Accepted"), 1);
		add_index_stringl(_1, 203, SL("Non-Authoritative Information"), 1);
		add_index_stringl(_1, 204, SL("No Content"), 1);
		add_index_stringl(_1, 205, SL("Reset Content"), 1);
		add_index_stringl(_1, 206, SL("Partial Content"), 1);
		add_index_stringl(_1, 300, SL("Multiple Choices"), 1);
		add_index_stringl(_1, 301, SL("Moved Permanently"), 1);
		add_index_stringl(_1, 302, SL("Found"), 1);
		add_index_stringl(_1, 303, SL("See Other"), 1);
		add_index_stringl(_1, 304, SL("Not Modified"), 1);
		add_index_stringl(_1, 305, SL("Use Proxy"), 1);
		add_index_stringl(_1, 307, SL("Temporary Redirect"), 1);
		add_index_stringl(_1, 400, SL("Bad Request"), 1);
		add_index_stringl(_1, 401, SL("Unauthorized"), 1);
		add_index_stringl(_1, 402, SL("Payment Required"), 1);
		add_index_stringl(_1, 403, SL("Forbidden"), 1);
		add_index_stringl(_1, 404, SL("Not Found"), 1);
		add_index_stringl(_1, 405, SL("Method Not Allowed"), 1);
		add_index_stringl(_1, 406, SL("Not Acceptable"), 1);
		add_index_stringl(_1, 407, SL("Proxy Authentication Required"), 1);
		add_index_stringl(_1, 408, SL("Request Timeout"), 1);
		add_index_stringl(_1, 409, SL("Conflict"), 1);
		add_index_stringl(_1, 410, SL("Gone"), 1);
		add_index_stringl(_1, 411, SL("Length Required"), 1);
		add_index_stringl(_1, 412, SL("Precondition Failed"), 1);
		add_index_stringl(_1, 413, SL("Request Entity Too Large"), 1);
		add_index_stringl(_1, 414, SL("Request-URI Too Long"), 1);
		add_index_stringl(_1, 415, SL("Unsupported Media Type"), 1);
		add_index_stringl(_1, 416, SL("Requested Range Not Satisfiable"), 1);
		add_index_stringl(_1, 417, SL("Expectation Failed"), 1);
		add_index_stringl(_1, 500, SL("Internal Server Error"), 1);
		add_index_stringl(_1, 501, SL("Not Implemented"), 1);
		add_index_stringl(_1, 502, SL("Bad Gateway"), 1);
		add_index_stringl(_1, 503, SL("Service Unavailable"), 1);
		add_index_stringl(_1, 504, SL("Gateway Timeout"), 1);
		add_index_stringl(_1, 505, SL("HTTP Version Not Supported"), 1);
		add_index_stringl(_1, 509, SL("Bandwidth Limit Exceeded"), 1);
		zephir_update_static_property_ce(phalconry_http_client_header_ce, SL("messages"), &_1 TSRMLS_CC);
	}
	ZEPHIR_INIT_VAR(_2);
	_3 = zephir_fetch_static_property_ce(phalconry_http_client_header_ce, SL("messages") TSRMLS_CC);
	if (zephir_array_isset_long(_3, code)) {
		_4 = zephir_fetch_static_property_ce(phalconry_http_client_header_ce, SL("messages") TSRMLS_CC);
		zephir_array_fetch_long(&_2, _4, code, PH_NOISY, "phalconry/http/client/header.zep", 260 TSRMLS_CC);
	} else {
		ZVAL_NULL(_2);
	}
	RETURN_CCTOR(_2);

}

PHP_METHOD(Phalconry_Http_Client_Header, __construct) {

	zval *_0;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(_0);
	array_init(_0);
	zephir_update_property_this(this_ptr, SL("fields"), _0 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

