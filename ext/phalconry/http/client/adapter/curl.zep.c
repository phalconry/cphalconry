
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
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/object.h"
#include "kernel/exception.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/array.h"
#include "kernel/operators.h"
#include "kernel/concat.h"
#include "kernel/string.h"
#include "kernel/hash.h"


ZEPHIR_INIT_CLASS(Phalconry_Http_Client_Adapter_Curl) {

	ZEPHIR_REGISTER_CLASS(Phalconry\\Http\\Client\\Adapter, Curl, phalconry, http_client_adapter_curl, phalconry_http_client_adapter_curl_method_entry, 0);

	/**
	 * cURL handle
	 * @var resource
	 */
	zend_declare_property_null(phalconry_http_client_adapter_curl_ce, SL("handle"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_class_implements(phalconry_http_client_adapter_curl_ce TSRMLS_CC, 1, phalconry_http_client_adapter_adapterinterface_ce);
	return SUCCESS;

}

PHP_METHOD(Phalconry_Http_Client_Adapter_Curl, isAvailable) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval _0;

	ZEPHIR_MM_GROW();

	ZEPHIR_SINIT_VAR(_0);
	ZVAL_STRING(&_0, "curl", 0);
	ZEPHIR_RETURN_CALL_FUNCTION("extension_loaded", NULL, 15, &_0);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Phalconry_Http_Client_Adapter_Curl, __construct) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *curlHandle = NULL, *_0 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &curlHandle);

	if (!curlHandle) {
		curlHandle = ZEPHIR_GLOBAL(global_null);
	}


	if (Z_TYPE_P(curlHandle) == IS_NULL) {
		ZEPHIR_CALL_FUNCTION(&_0, "curl_init", NULL, 16);
		zephir_check_call_status();
		zephir_update_property_this(this_ptr, SL("handle"), _0 TSRMLS_CC);
	} else {
		if (Z_TYPE_P(curlHandle) == IS_RESOURCE) {
			zephir_update_property_this(this_ptr, SL("handle"), curlHandle TSRMLS_CC);
		} else {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "Handle must be cURL resource", "phalconry/http/client/adapter/curl.zep", 49);
			return;
		}
	}
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "initoptions", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Phalconry_Http_Client_Adapter_Curl, __destruct) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *_0;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("handle"), PH_NOISY_CC);
	ZEPHIR_CALL_FUNCTION(NULL, "curl_close", NULL, 17, _0);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Phalconry_Http_Client_Adapter_Curl, __clone) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *_0, *_1 = NULL;

	ZEPHIR_MM_GROW();

	object_init_ex(return_value, phalconry_http_client_adapter_curl_ce);
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("handle"), PH_NOISY_CC);
	ZEPHIR_CALL_FUNCTION(&_1, "curl_copy_handle", NULL, 18, _0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 8, _1);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Phalconry_Http_Client_Adapter_Curl, setOption) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *option, *value, *_0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &option, &value);



	_0 = zephir_fetch_nproperty_this(this_ptr, SL("handle"), PH_NOISY_CC);
	ZEPHIR_RETURN_CALL_FUNCTION("curl_setopt", NULL, 19, _0, option, value);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Phalconry_Http_Client_Adapter_Curl, setOptions) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *options, *_0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &options);



	_0 = zephir_fetch_nproperty_this(this_ptr, SL("handle"), PH_NOISY_CC);
	ZEPHIR_RETURN_CALL_FUNCTION("curl_setopt_array", NULL, 20, _0, options);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Phalconry_Http_Client_Adapter_Curl, setTimeout) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *timeout, *_0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &timeout);



	ZEPHIR_INIT_VAR(_0);
	ZVAL_LONG(_0, 13);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "setoption", NULL, 0, _0, timeout);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Phalconry_Http_Client_Adapter_Curl, setConnectTimeout) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *timeout, *_0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &timeout);



	ZEPHIR_INIT_VAR(_0);
	ZVAL_LONG(_0, 78);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "setoption", NULL, 0, _0, timeout);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Phalconry_Http_Client_Adapter_Curl, setProxy) {

	zend_bool _1, _3;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *_0;
	zval *host, *port = NULL, *user = NULL, *pass = NULL, _2, *pair = NULL, _4, *_5, *_6;

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


	ZEPHIR_INIT_VAR(_0);
	zephir_create_array(_0, 2, 0 TSRMLS_CC);
	zephir_array_update_long(&_0, 10004, &host, PH_COPY, "phalconry/http/client/adapter/curl.zep", 91);
	zephir_array_update_long(&_0, 59, &port, PH_COPY, "phalconry/http/client/adapter/curl.zep", 91);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "setoptions", NULL, 0, _0);
	zephir_check_call_status();
	_1 = Z_TYPE_P(user) == IS_STRING;
	if (_1) {
		ZEPHIR_SINIT_VAR(_2);
		ZVAL_STRING(&_2, "", 0);
		_1 = !ZEPHIR_IS_IDENTICAL(&_2, user);
	}
	if (_1) {
		ZEPHIR_CPY_WRT(pair, user);
		_3 = Z_TYPE_P(pass) == IS_STRING;
		if (_3) {
			ZEPHIR_SINIT_VAR(_4);
			ZVAL_STRING(&_4, "", 0);
			_3 = !ZEPHIR_IS_IDENTICAL(&_4, pass);
		}
		if (_3) {
			ZEPHIR_INIT_VAR(_5);
			ZEPHIR_CONCAT_SV(_5, ":", pass);
			zephir_concat_self(&pair, _5 TSRMLS_CC);
		}
		ZEPHIR_INIT_VAR(_6);
		ZVAL_LONG(_6, 10006);
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "setoption", NULL, 0, _6, pair);
		zephir_check_call_status();
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Phalconry_Http_Client_Adapter_Curl, get) {

	zval *_1;
	int ZEPHIR_LAST_CALL_STATUS;
	zend_bool fullResponse;
	zval *request, *params = NULL, *customHeader = NULL, *fullResponse_param = NULL, *_0 = NULL, *_2 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 3, &request, &params, &customHeader, &fullResponse_param);

	if (!params) {
		ZEPHIR_INIT_VAR(params);
		array_init(params);
	}
	if (!customHeader) {
		ZEPHIR_INIT_VAR(customHeader);
		array_init(customHeader);
	}
	if (!fullResponse_param) {
		fullResponse = 0;
	} else {
		fullResponse = zephir_get_boolval(fullResponse_param);
	}


	if (!(ZEPHIR_IS_EMPTY(params))) {
		ZEPHIR_CALL_METHOD(&_0, request, "geturi", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, _0, "extendquery", NULL, 0, params);
		zephir_check_call_status();
	}
	ZEPHIR_INIT_VAR(_1);
	zephir_create_array(_1, 3, 0 TSRMLS_CC);
	ZEPHIR_CALL_METHOD(&_0, request, "geturi", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_2, _0, "build", NULL, 0);
	zephir_check_call_status();
	zephir_array_update_long(&_1, 10002, &_2, PH_COPY, "phalconry/http/client/adapter/curl.zep", 116);
	add_index_bool(_1, 80, 1);
	zephir_array_update_long(&_1, 80, &ZEPHIR_GLOBAL(global_true), PH_COPY, "phalconry/http/client/adapter/curl.zep", 116);
	add_index_stringl(_1, 10036, SL("GET"), 1);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "setoptions", NULL, 0, _1);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "send", NULL, 0, request, customHeader, (fullResponse ? ZEPHIR_GLOBAL(global_true) : ZEPHIR_GLOBAL(global_false)));
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Phalconry_Http_Client_Adapter_Curl, head) {

	zval *_1;
	int ZEPHIR_LAST_CALL_STATUS;
	zend_bool fullResponse;
	zval *request, *params = NULL, *customHeader = NULL, *fullResponse_param = NULL, *_0 = NULL, *_2 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 3, &request, &params, &customHeader, &fullResponse_param);

	if (!params) {
		ZEPHIR_INIT_VAR(params);
		array_init(params);
	}
	if (!customHeader) {
		ZEPHIR_INIT_VAR(customHeader);
		array_init(customHeader);
	}
	if (!fullResponse_param) {
		fullResponse = 0;
	} else {
		fullResponse = zephir_get_boolval(fullResponse_param);
	}


	if (!(ZEPHIR_IS_EMPTY(params))) {
		ZEPHIR_CALL_METHOD(&_0, request, "geturi", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, _0, "extendquery", NULL, 0, params);
		zephir_check_call_status();
	}
	ZEPHIR_INIT_VAR(_1);
	zephir_create_array(_1, 3, 0 TSRMLS_CC);
	ZEPHIR_CALL_METHOD(&_0, request, "geturi", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_2, _0, "build", NULL, 0);
	zephir_check_call_status();
	zephir_array_update_long(&_1, 10002, &_2, PH_COPY, "phalconry/http/client/adapter/curl.zep", 131);
	add_index_bool(_1, 80, 1);
	zephir_array_update_long(&_1, 80, &ZEPHIR_GLOBAL(global_true), PH_COPY, "phalconry/http/client/adapter/curl.zep", 131);
	add_index_stringl(_1, 10036, SL("HEAD"), 1);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "setoptions", NULL, 0, _1);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "send", NULL, 0, request, customHeader, (fullResponse ? ZEPHIR_GLOBAL(global_true) : ZEPHIR_GLOBAL(global_false)));
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Phalconry_Http_Client_Adapter_Curl, delete) {

	zval *_1;
	int ZEPHIR_LAST_CALL_STATUS;
	zend_bool fullResponse;
	zval *request, *params = NULL, *customHeader = NULL, *fullResponse_param = NULL, *_0 = NULL, *_2 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 3, &request, &params, &customHeader, &fullResponse_param);

	if (!params) {
		ZEPHIR_INIT_VAR(params);
		array_init(params);
	}
	if (!customHeader) {
		ZEPHIR_INIT_VAR(customHeader);
		array_init(customHeader);
	}
	if (!fullResponse_param) {
		fullResponse = 0;
	} else {
		fullResponse = zephir_get_boolval(fullResponse_param);
	}


	if (!(ZEPHIR_IS_EMPTY(params))) {
		ZEPHIR_CALL_METHOD(&_0, request, "geturi", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, _0, "extendquery", NULL, 0, params);
		zephir_check_call_status();
	}
	ZEPHIR_INIT_VAR(_1);
	zephir_create_array(_1, 3, 0 TSRMLS_CC);
	ZEPHIR_CALL_METHOD(&_0, request, "geturi", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_2, _0, "build", NULL, 0);
	zephir_check_call_status();
	zephir_array_update_long(&_1, 10002, &_2, PH_COPY, "phalconry/http/client/adapter/curl.zep", 146);
	add_index_bool(_1, 80, 1);
	zephir_array_update_long(&_1, 80, &ZEPHIR_GLOBAL(global_true), PH_COPY, "phalconry/http/client/adapter/curl.zep", 146);
	add_index_stringl(_1, 10036, SL("DELETE"), 1);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "setoptions", NULL, 0, _1);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "send", NULL, 0, customHeader, (fullResponse ? ZEPHIR_GLOBAL(global_true) : ZEPHIR_GLOBAL(global_false)));
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Phalconry_Http_Client_Adapter_Curl, post) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *_0;
	zend_bool urlEncode, fullResponse;
	zval *request, *params = NULL, *urlEncode_param = NULL, *customHeader = NULL, *fullResponse_param = NULL, *_1 = NULL, *_2 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 4, &request, &params, &urlEncode_param, &customHeader, &fullResponse_param);

	if (!params) {
		ZEPHIR_INIT_VAR(params);
		array_init(params);
	}
	if (!urlEncode_param) {
		urlEncode = 1;
	} else {
		urlEncode = zephir_get_boolval(urlEncode_param);
	}
	if (!customHeader) {
		ZEPHIR_INIT_VAR(customHeader);
		array_init(customHeader);
	}
	if (!fullResponse_param) {
		fullResponse = 0;
	} else {
		fullResponse = zephir_get_boolval(fullResponse_param);
	}


	ZEPHIR_INIT_VAR(_0);
	zephir_create_array(_0, 3, 0 TSRMLS_CC);
	ZEPHIR_CALL_METHOD(&_1, request, "geturi", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_2, _1, "build", NULL, 0);
	zephir_check_call_status();
	zephir_array_update_long(&_0, 10002, &_2, PH_COPY, "phalconry/http/client/adapter/curl.zep", 157);
	add_index_bool(_0, 47, 1);
	zephir_array_update_long(&_0, 47, &ZEPHIR_GLOBAL(global_true), PH_COPY, "phalconry/http/client/adapter/curl.zep", 157);
	add_index_stringl(_0, 10036, SL("POST"), 1);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "setoptions", NULL, 0, _0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "initpostfields", NULL, 0, params, (urlEncode ? ZEPHIR_GLOBAL(global_true) : ZEPHIR_GLOBAL(global_false)));
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "send", NULL, 0, customHeader, (fullResponse ? ZEPHIR_GLOBAL(global_true) : ZEPHIR_GLOBAL(global_false)));
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Phalconry_Http_Client_Adapter_Curl, put) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *_0;
	zend_bool urlEncode, fullResponse;
	zval *request, *params = NULL, *urlEncode_param = NULL, *customHeader = NULL, *fullResponse_param = NULL, *_1 = NULL, *_2 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 4, &request, &params, &urlEncode_param, &customHeader, &fullResponse_param);

	if (!params) {
		ZEPHIR_INIT_VAR(params);
		array_init(params);
	}
	if (!urlEncode_param) {
		urlEncode = 1;
	} else {
		urlEncode = zephir_get_boolval(urlEncode_param);
	}
	if (!customHeader) {
		ZEPHIR_INIT_VAR(customHeader);
		array_init(customHeader);
	}
	if (!fullResponse_param) {
		fullResponse = 0;
	} else {
		fullResponse = zephir_get_boolval(fullResponse_param);
	}


	ZEPHIR_INIT_VAR(_0);
	zephir_create_array(_0, 3, 0 TSRMLS_CC);
	ZEPHIR_CALL_METHOD(&_1, request, "geturi", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_2, _1, "build", NULL, 0);
	zephir_check_call_status();
	zephir_array_update_long(&_0, 10002, &_2, PH_COPY, "phalconry/http/client/adapter/curl.zep", 170);
	add_index_bool(_0, 47, 1);
	zephir_array_update_long(&_0, 47, &ZEPHIR_GLOBAL(global_true), PH_COPY, "phalconry/http/client/adapter/curl.zep", 170);
	add_index_stringl(_0, 10036, SL("PUT"), 1);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "setoptions", NULL, 0, _0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "initpostfields", NULL, 0, params, (urlEncode ? ZEPHIR_GLOBAL(global_true) : ZEPHIR_GLOBAL(global_false)), customHeader);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "send", NULL, 0, customHeader, (fullResponse ? ZEPHIR_GLOBAL(global_true) : ZEPHIR_GLOBAL(global_false)));
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Phalconry_Http_Client_Adapter_Curl, __invoke) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *request, *method, *_0 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &request);



	ZEPHIR_CALL_METHOD(&_0, request, "getmethod", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(method);
	zephir_fast_strtolower(method, _0);
	if ((zephir_method_exists(this_ptr, method TSRMLS_CC)  == SUCCESS)) {
		ZEPHIR_RETURN_CALL_METHOD_ZVAL(this_ptr, method, NULL, 0, request);
		zephir_check_call_status();
		RETURN_MM();
	}
	ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalconry_http_client_adapter_exception_ce, "Unknown HTTP method", "phalconry/http/client/adapter/curl.zep", 186);
	return;

}

PHP_METHOD(Phalconry_Http_Client_Adapter_Curl, send) {

	int ZEPHIR_LAST_CALL_STATUS;
	zend_bool fullResponse;
	zval *request, *customHeader = NULL, *fullResponse_param = NULL, *header = NULL, *content = NULL, *errorNo = NULL, *headerSize = NULL, *response, *_0, *_1, *_2 = NULL, *_3, *_4, *_5, *_6 = NULL, _7 = zval_used_for_init;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &request, &customHeader, &fullResponse_param);

	if (!customHeader) {
		ZEPHIR_INIT_VAR(customHeader);
		array_init(customHeader);
	}
	if (!fullResponse_param) {
		fullResponse = 0;
	} else {
		fullResponse = zephir_get_boolval(fullResponse_param);
	}


	if (!(ZEPHIR_IS_EMPTY(customHeader))) {
		ZEPHIR_CPY_WRT(header, customHeader);
	} else {
		ZEPHIR_INIT_NVAR(header);
		array_init(header);
		ZEPHIR_OBS_VAR(_0);
		zephir_read_property(&_0, request, SL("header"), PH_NOISY_CC);
		if (zephir_fast_count_int(_0 TSRMLS_CC) > 0) {
			ZEPHIR_OBS_VAR(_1);
			zephir_read_property(&_1, request, SL("header"), PH_NOISY_CC);
			ZEPHIR_CALL_METHOD(&header, _1, "build", NULL, 0);
			zephir_check_call_status();
		}
		ZEPHIR_INIT_VAR(_2);
		ZVAL_STRING(_2, "Expect:", 1);
		zephir_array_append(&header, _2, PH_SEPARATE, "phalconry/http/client/adapter/curl.zep", 203);
	}
	ZEPHIR_INIT_NVAR(_2);
	ZVAL_LONG(_2, 10023);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "setoption", NULL, 0, _2, header);
	zephir_check_call_status();
	_3 = zephir_fetch_nproperty_this(this_ptr, SL("handle"), PH_NOISY_CC);
	ZEPHIR_CALL_FUNCTION(&content, "curl_exec", NULL, 21, _3);
	zephir_check_call_status();
	_4 = zephir_fetch_nproperty_this(this_ptr, SL("handle"), PH_NOISY_CC);
	ZEPHIR_CALL_FUNCTION(&errorNo, "curl_errno", NULL, 22, _4);
	zephir_check_call_status();
	if (!ZEPHIR_IS_LONG_IDENTICAL(errorNo, 0)) {
		ZEPHIR_INIT_NVAR(_2);
		object_init_ex(_2, phalconry_http_client_exception_ce);
		_5 = zephir_fetch_nproperty_this(this_ptr, SL("handle"), PH_NOISY_CC);
		ZEPHIR_CALL_FUNCTION(&_6, "curl_error", NULL, 23, _5);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, _2, "__construct", NULL, 24, _6, errorNo);
		zephir_check_call_status();
		zephir_throw_exception_debug(_2, "phalconry/http/client/adapter/curl.zep", 212 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	_5 = zephir_fetch_nproperty_this(this_ptr, SL("handle"), PH_NOISY_CC);
	ZEPHIR_SINIT_VAR(_7);
	ZVAL_LONG(&_7, 2097163);
	ZEPHIR_CALL_FUNCTION(&headerSize, "curl_getinfo", NULL, 25, _5, &_7);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(response);
	object_init_ex(response, phalconry_http_client_response_ce);
	ZEPHIR_CALL_METHOD(NULL, response, "__construct", NULL, 26);
	zephir_check_call_status();
	ZEPHIR_SINIT_NVAR(_7);
	ZVAL_LONG(&_7, 0);
	ZEPHIR_INIT_NVAR(_2);
	zephir_substr(_2, content, 0 , zephir_get_intval(headerSize), 0);
	ZEPHIR_CALL_METHOD(NULL, response, "parseheaders", NULL, 27, _2);
	zephir_check_call_status();
	if (fullResponse) {
		ZEPHIR_CALL_METHOD(NULL, response, "setbody", NULL, 28, content);
		zephir_check_call_status();
	} else {
		ZEPHIR_INIT_NVAR(_2);
		zephir_substr(_2, content, zephir_get_intval(headerSize), 0, ZEPHIR_SUBSTR_NO_LENGTH);
		ZEPHIR_CALL_METHOD(NULL, response, "setbody", NULL, 28, _2);
		zephir_check_call_status();
	}
	RETURN_CCTOR(response);

}

/**
 * Prepare data for a cURL post.
 *
 * @param mixed   params      Data to send.
 * @param boolean urlEncode Whether to url-encode params. Defaults to true.
 *
 * @return void
 */
PHP_METHOD(Phalconry_Http_Client_Adapter_Curl, initPostFields) {

	int ZEPHIR_LAST_CALL_STATUS;
	HashTable *_1;
	HashPosition _0;
	zend_bool urlEncode, _3;
	zval *params = NULL, *urlEncode_param = NULL, *param = NULL, **_2, *_4 = NULL, *_5 = NULL, _6 = zval_used_for_init, *_7 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &params, &urlEncode_param);

	ZEPHIR_SEPARATE_PARAM(params);
	if (!urlEncode_param) {
		urlEncode = 1;
	} else {
		urlEncode = zephir_get_boolval(urlEncode_param);
	}


	if (Z_TYPE_P(params) == IS_ARRAY) {
		zephir_is_iterable(params, &_1, &_0, 0, 0, "phalconry/http/client/adapter/curl.zep", 248);
		for (
		  ; zephir_hash_get_current_data_ex(_1, (void**) &_2, &_0) == SUCCESS
		  ; zephir_hash_move_forward_ex(_1, &_0)
		) {
			ZEPHIR_GET_HVALUE(param, _2);
			_3 = Z_TYPE_P(param) == IS_STRING;
			if (_3) {
				ZEPHIR_INIT_NVAR(_4);
				ZEPHIR_INIT_NVAR(_5);
				ZEPHIR_SINIT_NVAR(_6);
				ZVAL_STRING(&_6, "/^@/", 0);
				zephir_preg_match(_5, &_6, param, _4, 0, 0 , 0  TSRMLS_CC);
				_3 = zephir_is_true(_5);
			}
			if (_3) {
				urlEncode = 0;
				break;
			}
		}
		if (urlEncode) {
			ZEPHIR_CALL_FUNCTION(&_7, "http_build_query", NULL, 29, params);
			zephir_check_call_status();
			ZEPHIR_CPY_WRT(params, _7);
		}
	}
	if (!(ZEPHIR_IS_EMPTY(params))) {
		ZEPHIR_INIT_NVAR(_5);
		ZVAL_LONG(_5, 10015);
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "setoption", NULL, 0, _5, params);
		zephir_check_call_status();
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Phalconry_Http_Client_Adapter_Curl, initOptions) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *_1;
	zval *_0;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(_0);
	zephir_create_array(_0, 10, 0 TSRMLS_CC);
	add_index_bool(_0, 19913, 1);
	zephir_array_update_long(&_0, 19913, &ZEPHIR_GLOBAL(global_true), PH_COPY, "phalconry/http/client/adapter/curl.zep", 271);
	add_index_bool(_0, 58, 1);
	zephir_array_update_long(&_0, 58, &ZEPHIR_GLOBAL(global_true), PH_COPY, "phalconry/http/client/adapter/curl.zep", 271);
	add_index_bool(_0, 52, 1);
	zephir_array_update_long(&_0, 52, &ZEPHIR_GLOBAL(global_true), PH_COPY, "phalconry/http/client/adapter/curl.zep", 271);
	add_index_long(_0, 68, 20);
	add_index_bool(_0, 42, 1);
	zephir_array_update_long(&_0, 42, &ZEPHIR_GLOBAL(global_true), PH_COPY, "phalconry/http/client/adapter/curl.zep", 271);
	add_index_long(_0, 181, (1 | 2));
	add_index_long(_0, 182, (1 | 2));
	ZEPHIR_INIT_VAR(_1);
	ZEPHIR_CONCAT_SSS(_1, "Phalcon HTTP/", "0.1", " (Curl)");
	zephir_array_update_long(&_0, 10018, &_1, PH_COPY, "phalconry/http/client/adapter/curl.zep", 271);
	add_index_long(_0, 78, 30);
	add_index_long(_0, 13, 30);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "setoptions", NULL, 0, _0);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

