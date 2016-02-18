
#ifdef HAVE_CONFIG_H
#include "../../../../ext_config.h"
#endif

#include <php.h>
#include "../../../../php_ext.h"
#include "../../../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/fcall.h"
#include "kernel/array.h"
#include "kernel/memory.h"
#include "kernel/object.h"
#include "kernel/operators.h"
#include "kernel/string.h"
#include "kernel/exception.h"
#include "kernel/concat.h"


ZEPHIR_INIT_CLASS(Phalconry_Http_Client_Adapter_Stream) {

	ZEPHIR_REGISTER_CLASS(Phalconry\\Http\\Client\\Adapter, Stream, phalconry, http_client_adapter_stream, phalconry_http_client_adapter_stream_method_entry, 0);

	/**
	 * Stream context
	 * @var resource
	 */
	zend_declare_property_null(phalconry_http_client_adapter_stream_ce, SL("context"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_class_implements(phalconry_http_client_adapter_stream_ce TSRMLS_CC, 1, phalconry_http_client_adapter_adapterinterface_ce);
	return SUCCESS;

}

PHP_METHOD(Phalconry_Http_Client_Adapter_Stream, isAvailable) {

	zend_bool _1;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *wrappers = NULL, _0, _2;

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_FUNCTION(&wrappers, "stream_get_wrappers", NULL, 30);
	zephir_check_call_status();
	ZEPHIR_SINIT_VAR(_0);
	ZVAL_STRING(&_0, "http", 0);
	_1 = zephir_fast_in_array(&_0, wrappers TSRMLS_CC);
	if (_1) {
		ZEPHIR_SINIT_VAR(_2);
		ZVAL_STRING(&_2, "https", 0);
		_1 = zephir_fast_in_array(&_2, wrappers TSRMLS_CC);
	}
	RETURN_MM_BOOL(_1);

}

PHP_METHOD(Phalconry_Http_Client_Adapter_Stream, __construct) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *_0 = NULL;

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_FUNCTION(&_0, "stream_context_create", NULL, 31);
	zephir_check_call_status();
	zephir_update_property_this(this_ptr, SL("context"), _0 TSRMLS_CC);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "initoptions", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Phalconry_Http_Client_Adapter_Stream, __destruct) {


	zephir_update_property_this(this_ptr, SL("context"), ZEPHIR_GLOBAL(global_null) TSRMLS_CC);

}

PHP_METHOD(Phalconry_Http_Client_Adapter_Stream, setOption) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *option, *value, *_0, _1;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &option, &value);



	_0 = zephir_fetch_nproperty_this(this_ptr, SL("context"), PH_NOISY_CC);
	ZEPHIR_SINIT_VAR(_1);
	ZVAL_STRING(&_1, "http", 0);
	ZEPHIR_RETURN_CALL_FUNCTION("stream_context_set_option", NULL, 32, _0, &_1, option, value);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Phalconry_Http_Client_Adapter_Stream, setOptions) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *_1;
	zval *options, *_0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &options);



	_0 = zephir_fetch_nproperty_this(this_ptr, SL("context"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_1);
	zephir_create_array(_1, 1, 0 TSRMLS_CC);
	zephir_array_update_string(&_1, SL("http"), &options, PH_COPY | PH_SEPARATE);
	ZEPHIR_RETURN_CALL_FUNCTION("stream_context_set_option", NULL, 32, _0, _1, ZEPHIR_GLOBAL(global_null), ZEPHIR_GLOBAL(global_null));
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Phalconry_Http_Client_Adapter_Stream, setTimeout) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *timeout, *_0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &timeout);



	ZEPHIR_INIT_VAR(_0);
	ZVAL_STRING(_0, "timeout", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "setoption", NULL, 0, _0, timeout);
	zephir_check_temp_parameter(_0);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Phalconry_Http_Client_Adapter_Stream, setProxy) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *_0;
	zval *host, *port = NULL, *user = NULL, *pass = NULL, *uri, *_1 = NULL, *_2;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 3, &host, &port, &user, &pass);

	if (!port) {
		ZEPHIR_INIT_VAR(port);
		ZVAL_LONG(port, 8080);
	}
	if (!user) {
		user = ZEPHIR_GLOBAL(global_null);
	}
	if (!pass) {
		pass = ZEPHIR_GLOBAL(global_null);
	}


	ZEPHIR_INIT_VAR(uri);
	object_init_ex(uri, phalconry_http_uri_ce);
	ZEPHIR_INIT_VAR(_0);
	zephir_create_array(_0, 3, 0 TSRMLS_CC);
	add_assoc_stringl_ex(_0, SS("scheme"), SL("tcp"), 1);
	zephir_array_update_string(&_0, SL("host"), &host, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&_0, SL("port"), &port, PH_COPY | PH_SEPARATE);
	ZEPHIR_CALL_METHOD(NULL, uri, "__construct", NULL, 33, _0);
	zephir_check_call_status();
	if (Z_TYPE_P(user) == IS_STRING) {
		zephir_update_property_zval(uri, SL("user"), user TSRMLS_CC);
		if (Z_TYPE_P(pass) == IS_STRING) {
			zephir_update_property_zval(uri, SL("pass"), pass TSRMLS_CC);
		}
	}
	ZEPHIR_CALL_METHOD(&_1, uri, "build", NULL, 34);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_2);
	ZVAL_STRING(_2, "proxy", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "setoption", NULL, 0, _2, _1);
	zephir_check_temp_parameter(_2);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Phalconry_Http_Client_Adapter_Stream, get) {

	zval *_1;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *request, *params = NULL, *_0 = NULL, *_2, *_3;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &request, &params);

	if (!params) {
		ZEPHIR_INIT_VAR(params);
		array_init(params);
	}


	if (!(ZEPHIR_IS_EMPTY(params))) {
		ZEPHIR_CALL_METHOD(&_0, request, "geturi", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, _0, "extendquery", NULL, 0, params);
		zephir_check_call_status();
	}
	ZEPHIR_INIT_VAR(_1);
	zephir_create_array(_1, 2, 0 TSRMLS_CC);
	add_assoc_stringl_ex(_1, SS("method"), SL("GET"), 1);
	add_assoc_stringl_ex(_1, SS("content"), SL(""), 1);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "setoptions", NULL, 0, _1);
	zephir_check_call_status();
	ZEPHIR_OBS_VAR(_2);
	zephir_read_property(&_2, request, SL("header"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_3);
	ZVAL_STRING(_3, "Content-Type", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(NULL, _2, "remove", NULL, 0, _3);
	zephir_check_temp_parameter(_3);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "send", NULL, 0, request);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Phalconry_Http_Client_Adapter_Stream, head) {

	zval *_1;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *request, *params = NULL, *_0 = NULL, *_2, *_3;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &request, &params);

	if (!params) {
		ZEPHIR_INIT_VAR(params);
		array_init(params);
	}


	if (!(ZEPHIR_IS_EMPTY(params))) {
		ZEPHIR_CALL_METHOD(&_0, request, "geturi", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, _0, "extendquery", NULL, 0, params);
		zephir_check_call_status();
	}
	ZEPHIR_INIT_VAR(_1);
	zephir_create_array(_1, 2, 0 TSRMLS_CC);
	add_assoc_stringl_ex(_1, SS("method"), SL("HEAD"), 1);
	add_assoc_stringl_ex(_1, SS("content"), SL(""), 1);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "setoptions", NULL, 0, _1);
	zephir_check_call_status();
	ZEPHIR_OBS_VAR(_2);
	zephir_read_property(&_2, request, SL("header"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_3);
	ZVAL_STRING(_3, "Content-Type", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(NULL, _2, "remove", NULL, 0, _3);
	zephir_check_temp_parameter(_3);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "send", NULL, 0, request);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Phalconry_Http_Client_Adapter_Stream, delete) {

	zval *_1;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *request, *params = NULL, *_0 = NULL, *_2, *_3;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &request, &params);

	if (!params) {
		ZEPHIR_INIT_VAR(params);
		array_init(params);
	}


	if (!(ZEPHIR_IS_EMPTY(params))) {
		ZEPHIR_CALL_METHOD(&_0, request, "geturi", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, _0, "extendquery", NULL, 0, params);
		zephir_check_call_status();
	}
	ZEPHIR_INIT_VAR(_1);
	zephir_create_array(_1, 2, 0 TSRMLS_CC);
	add_assoc_stringl_ex(_1, SS("method"), SL("DELETE"), 1);
	add_assoc_stringl_ex(_1, SS("content"), SL(""), 1);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "setoptions", NULL, 0, _1);
	zephir_check_call_status();
	ZEPHIR_OBS_VAR(_2);
	zephir_read_property(&_2, request, SL("header"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_3);
	ZVAL_STRING(_3, "Content-Type", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(NULL, _2, "remove", NULL, 0, _3);
	zephir_check_temp_parameter(_3);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "send", NULL, 0, request);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Phalconry_Http_Client_Adapter_Stream, post) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *request, *params = NULL, *_0, *_1;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &request, &params);

	if (!params) {
		ZEPHIR_INIT_VAR(params);
		array_init(params);
	}


	ZEPHIR_INIT_VAR(_0);
	ZVAL_STRING(_0, "method", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_VAR(_1);
	ZVAL_STRING(_1, "POST", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "setoption", NULL, 0, _0, _1);
	zephir_check_temp_parameter(_0);
	zephir_check_temp_parameter(_1);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "initpostfields", NULL, 0, request, params);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "send", NULL, 0, request);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Phalconry_Http_Client_Adapter_Stream, put) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *request, *params = NULL, *_0, *_1;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &request, &params);

	if (!params) {
		ZEPHIR_INIT_VAR(params);
		array_init(params);
	}


	ZEPHIR_INIT_VAR(_0);
	ZVAL_STRING(_0, "method", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_VAR(_1);
	ZVAL_STRING(_1, "PUT", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "setoption", NULL, 0, _0, _1);
	zephir_check_temp_parameter(_0);
	zephir_check_temp_parameter(_1);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "initpostfields", NULL, 0, request, params);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "send", NULL, 0, request);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Phalconry_Http_Client_Adapter_Stream, __invoke) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *request, *params = NULL, *method, *_0 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &request, &params);

	if (!params) {
		ZEPHIR_INIT_VAR(params);
		array_init(params);
	}


	ZEPHIR_CALL_METHOD(&_0, request, "getmethod", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(method);
	zephir_fast_strtolower(method, _0);
	if ((zephir_method_exists(this_ptr, method TSRMLS_CC)  == SUCCESS)) {
		ZEPHIR_RETURN_CALL_METHOD_ZVAL(this_ptr, method, NULL, 0, request, params);
		zephir_check_call_status();
		RETURN_MM();
	}
	ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalconry_http_client_adapter_exception_ce, "Unknown HTTP method", "phalconry/http/client/adapter/stream.zep", 152);
	return;

}

PHP_METHOD(Phalconry_Http_Client_Adapter_Stream, errorHandler) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *errorNumber, *errorString, *_0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &errorNumber, &errorString);



	ZEPHIR_INIT_VAR(_0);
	object_init_ex(_0, phalconry_http_client_exception_ce);
	ZEPHIR_CALL_METHOD(NULL, _0, "__construct", NULL, 24, errorString, errorNumber);
	zephir_check_call_status();
	zephir_throw_exception_debug(_0, "phalconry/http/client/adapter/stream.zep", 156 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();
	return;

}

PHP_METHOD(Phalconry_Http_Client_Adapter_Stream, send) {

	zval *_3;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *request, *content = NULL, *response, *http_response_header, *_0, *_1 = NULL, *_2 = NULL, *_4 = NULL, *_5;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &request);



	ZEPHIR_INIT_VAR(http_response_header);
	ZVAL_STRING(http_response_header, "", 1);
	ZEPHIR_OBS_VAR(_0);
	zephir_read_property(&_0, request, SL("header"), PH_NOISY_CC);
	if (zephir_fast_count_int(_0 TSRMLS_CC) > 0) {
		ZEPHIR_CALL_METHOD(&_1, request, "buildheaderfields", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(_2);
		ZVAL_STRING(_2, "header", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "setoption", NULL, 0, _2, _1);
		zephir_check_temp_parameter(_2);
		zephir_check_call_status();
	}
	ZEPHIR_INIT_VAR(_3);
	zephir_create_array(_3, 2, 0 TSRMLS_CC);
	zephir_array_fast_append(_3, this_ptr);
	ZEPHIR_INIT_NVAR(_2);
	ZVAL_STRING(_2, "errorHandler", 1);
	zephir_array_fast_append(_3, _2);
	ZEPHIR_CALL_FUNCTION(NULL, "set_error_handler", NULL, 35, _3);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_1, request, "geturi", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_4, _1, "build", NULL, 0);
	zephir_check_call_status();
	_5 = zephir_fetch_nproperty_this(this_ptr, SL("context"), PH_NOISY_CC);
	ZEPHIR_CALL_FUNCTION(&content, "file_get_contents", NULL, 36, _4, ZEPHIR_GLOBAL(global_false), _5);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(NULL, "restore_error_handler", NULL, 37);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(response);
	object_init_ex(response, phalconry_http_client_response_ce);
	ZEPHIR_CALL_METHOD(NULL, response, "__construct", NULL, 26);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, response, "parseheaders", NULL, 27, http_response_header);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, response, "setbody", NULL, 28, content);
	zephir_check_call_status();
	RETURN_CCTOR(response);

}

PHP_METHOD(Phalconry_Http_Client_Adapter_Stream, initPostFields) {

	int ZEPHIR_LAST_CALL_STATUS;
	zend_bool _0;
	zval *request, *params = NULL, *_1 = NULL, *_2, *_3 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &request, &params);

	if (!params) {
		ZEPHIR_INIT_VAR(params);
		array_init(params);
	}


	_0 = Z_TYPE_P(params) == IS_ARRAY;
	if (_0) {
		_0 = !(ZEPHIR_IS_EMPTY(params));
	}
	if (_0) {
		ZEPHIR_INIT_VAR(_1);
		ZVAL_STRING(_1, "Content-Type", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_INIT_VAR(_2);
		ZVAL_STRING(_2, "application/x-www-form-urlencoded", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(NULL, request, "setheader", NULL, 0, _1, _2);
		zephir_check_temp_parameter(_1);
		zephir_check_temp_parameter(_2);
		zephir_check_call_status();
		ZEPHIR_CALL_FUNCTION(&_3, "http_build_query", NULL, 29, params);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(_1);
		ZVAL_STRING(_1, "content", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "setoption", NULL, 0, _1, _3);
		zephir_check_temp_parameter(_1);
		zephir_check_call_status();
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Phalconry_Http_Client_Adapter_Stream, initOptions) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *_1;
	zval *_0;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(_0);
	zephir_create_array(_0, 4, 0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_1);
	ZEPHIR_CONCAT_SSS(_1, "Phalcon HTTP/", "0.1", " (Stream)");
	zephir_array_update_string(&_0, SL("user_agent"), &_1, PH_COPY | PH_SEPARATE);
	add_assoc_long_ex(_0, SS("follow_location"), 1);
	add_assoc_long_ex(_0, SS("max_redirects"), 20);
	add_assoc_long_ex(_0, SS("timeout"), 30);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "setoptions", NULL, 0, _0);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

