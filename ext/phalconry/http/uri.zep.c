
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
#include "kernel/object.h"
#include "kernel/fcall.h"
#include "kernel/array.h"
#include "kernel/operators.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"
#include "kernel/concat.h"
#include "kernel/string.h"

ZEPHIR_INIT_CLASS(Phalconry_Http_Uri) {

	ZEPHIR_REGISTER_CLASS(Phalconry\\Http, Uri, phalconry, http_uri, phalconry_http_uri_method_entry, 0);

	zend_declare_property_null(phalconry_http_uri_ce, SL("parts"), ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

PHP_METHOD(Phalconry_Http_Uri, __construct) {

	zend_bool _4;
	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_2 = NULL, *_9 = NULL;
	zval *uri = NULL, *_0, *query, *_1 = NULL, *_3, *_5, *_6, *_7, *_8, *_10, *_11;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &uri);

	if (!uri) {
		uri = ZEPHIR_GLOBAL(global_null);
	}


	ZEPHIR_INIT_VAR(_0);
	array_init(_0);
	zephir_update_property_this(this_ptr, SL("parts"), _0 TSRMLS_CC);
	if (Z_TYPE_P(uri) != IS_NULL) {
		if (Z_TYPE_P(uri) == IS_STRING) {
			ZEPHIR_CALL_FUNCTION(&_1, "parse_url", &_2, uri);
			zephir_check_call_status();
			zephir_update_property_this(this_ptr, SL("parts"), _1 TSRMLS_CC);
			_3 = zephir_fetch_nproperty_this(this_ptr, SL("parts"), PH_NOISY_CC);
			_4 = zephir_array_isset_string(_3, SS("query"));
			if (_4) {
				_5 = zephir_fetch_nproperty_this(this_ptr, SL("parts"), PH_NOISY_CC);
				zephir_array_fetch_string(&_6, _5, SL("query"), PH_NOISY | PH_READONLY, "phalconry/http/uri.zep", 33 TSRMLS_CC);
				_4 = !(ZEPHIR_IS_EMPTY(_6));
			}
			if (_4) {
				ZEPHIR_INIT_VAR(query);
				array_init(query);
				_7 = zephir_fetch_nproperty_this(this_ptr, SL("parts"), PH_NOISY_CC);
				zephir_array_fetch_string(&_8, _7, SL("query"), PH_NOISY | PH_READONLY, "phalconry/http/uri.zep", 35 TSRMLS_CC);
				Z_SET_ISREF_P(query);
				ZEPHIR_CALL_FUNCTION(NULL, "parse_str", &_9, _8, query);
				Z_UNSET_ISREF_P(query);
				zephir_check_call_status();
				ZEPHIR_INIT_VAR(_10);
				ZVAL_STRING(_10, "query", 1);
				zephir_update_property_array(this_ptr, SL("parts"), _10, query TSRMLS_CC);
			}
		} else if (Z_TYPE_P(uri) == IS_ARRAY) {
			zephir_update_property_this(this_ptr, SL("parts"), uri TSRMLS_CC);
		} else if (zephir_instance_of_ev(uri, phalconry_http_uri_ce TSRMLS_CC)) {
			ZEPHIR_OBS_VAR(_11);
			zephir_read_property(&_11, uri, SL("parts"), PH_NOISY_CC);
			zephir_update_property_this(this_ptr, SL("parts"), _11 TSRMLS_CC);
		}
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Phalconry_Http_Uri, __toString) {

	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "build", NULL);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Phalconry_Http_Uri, __unset) {

	zval *name_param = NULL, *_0;
	zval *name = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name_param);

	if (unlikely(Z_TYPE_P(name_param) != IS_STRING && Z_TYPE_P(name_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'name' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(name_param) == IS_STRING)) {
		zephir_get_strval(name, name_param);
	} else {
		ZEPHIR_INIT_VAR(name);
		ZVAL_EMPTY_STRING(name);
	}


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("parts"), PH_NOISY_CC);
	zephir_array_unset(&_0, name, PH_SEPARATE);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Phalconry_Http_Uri, __set) {

	zval *name_param = NULL, *value;
	zval *name = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &name_param, &value);

	if (unlikely(Z_TYPE_P(name_param) != IS_STRING && Z_TYPE_P(name_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'name' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(name_param) == IS_STRING)) {
		zephir_get_strval(name, name_param);
	} else {
		ZEPHIR_INIT_VAR(name);
		ZVAL_EMPTY_STRING(name);
	}


	zephir_update_property_array(this_ptr, SL("parts"), name, value TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Phalconry_Http_Uri, __get) {

	zval *name_param = NULL, *_0, *_1;
	zval *name = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name_param);

	if (unlikely(Z_TYPE_P(name_param) != IS_STRING && Z_TYPE_P(name_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'name' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(name_param) == IS_STRING)) {
		zephir_get_strval(name, name_param);
	} else {
		ZEPHIR_INIT_VAR(name);
		ZVAL_EMPTY_STRING(name);
	}


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("parts"), PH_NOISY_CC);
	zephir_array_fetch(&_1, _0, name, PH_NOISY | PH_READONLY, "phalconry/http/uri.zep", 64 TSRMLS_CC);
	RETURN_CTOR(_1);

}

PHP_METHOD(Phalconry_Http_Uri, __isset) {

	zval *name_param = NULL, *_0;
	zval *name = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name_param);

	if (unlikely(Z_TYPE_P(name_param) != IS_STRING && Z_TYPE_P(name_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'name' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(name_param) == IS_STRING)) {
		zephir_get_strval(name, name_param);
	} else {
		ZEPHIR_INIT_VAR(name);
		ZVAL_EMPTY_STRING(name);
	}


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("parts"), PH_NOISY_CC);
	RETURN_MM_BOOL(zephir_array_isset(_0, name));

}

PHP_METHOD(Phalconry_Http_Uri, build) {

	int ZEPHIR_LAST_CALL_STATUS;
	zend_bool _1, _5, _7, _10;
	zval *uri, *parts = NULL, *_0, *_2, *_3, *_4 = NULL, *_6, *_8, *_9, *_11, *_12, *_13, *_14 = NULL;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(uri);
	ZVAL_STRING(uri, "", 1);
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("parts"), PH_NOISY_CC);
	ZEPHIR_CPY_WRT(parts, _0);
	_1 = zephir_array_isset_string(parts, SS("scheme"));
	if (_1) {
		zephir_array_fetch_string(&_2, parts, SL("scheme"), PH_NOISY | PH_READONLY, "phalconry/http/uri.zep", 79 TSRMLS_CC);
		_1 = !(ZEPHIR_IS_EMPTY(_2));
	}
	if (_1) {
		zephir_array_fetch_string(&_3, parts, SL("scheme"), PH_NOISY | PH_READONLY, "phalconry/http/uri.zep", 81 TSRMLS_CC);
		ZEPHIR_INIT_VAR(_4);
		ZEPHIR_CONCAT_VS(_4, _3, ":");
		zephir_concat_self(&uri, _4 TSRMLS_CC);
		_5 = zephir_array_isset_string(parts, SS("host"));
		if (_5) {
			zephir_array_fetch_string(&_6, parts, SL("host"), PH_NOISY | PH_READONLY, "phalconry/http/uri.zep", 83 TSRMLS_CC);
			_5 = !(ZEPHIR_IS_EMPTY(_6));
		}
		if (_5) {
			zephir_concat_self_str(&uri, SL("//") TSRMLS_CC);
			_7 = zephir_array_isset_string(parts, SS("user"));
			if (_7) {
				zephir_array_fetch_string(&_8, parts, SL("user"), PH_NOISY | PH_READONLY, "phalconry/http/uri.zep", 87 TSRMLS_CC);
				_7 = !(ZEPHIR_IS_EMPTY(_8));
			}
			if (_7) {
				zephir_array_fetch_string(&_9, parts, SL("user"), PH_NOISY | PH_READONLY, "phalconry/http/uri.zep", 89 TSRMLS_CC);
				zephir_concat_self(&uri, _9 TSRMLS_CC);
				_10 = zephir_array_isset_string(parts, SS("pass"));
				if (_10) {
					zephir_array_fetch_string(&_11, parts, SL("pass"), PH_NOISY | PH_READONLY, "phalconry/http/uri.zep", 91 TSRMLS_CC);
					_10 = !(ZEPHIR_IS_EMPTY(_11));
				}
				if (_10) {
					zephir_array_fetch_string(&_12, parts, SL("pass"), PH_NOISY | PH_READONLY, "phalconry/http/uri.zep", 92 TSRMLS_CC);
					ZEPHIR_INIT_VAR(_13);
					ZEPHIR_CONCAT_SV(_13, ":", _12);
					zephir_concat_self(&uri, _13 TSRMLS_CC);
				}
				zephir_concat_self_str(&uri, SL("@") TSRMLS_CC);
			}
			zephir_array_fetch_string(&_9, parts, SL("host"), PH_NOISY | PH_READONLY, "phalconry/http/uri.zep", 98 TSRMLS_CC);
			zephir_concat_self(&uri, _9 TSRMLS_CC);
		}
	}
	_5 = zephir_array_isset_string(parts, SS("port"));
	if (_5) {
		zephir_array_fetch_string(&_3, parts, SL("port"), PH_NOISY | PH_READONLY, "phalconry/http/uri.zep", 102 TSRMLS_CC);
		_5 = !(ZEPHIR_IS_EMPTY(_3));
	}
	if (_5) {
		zephir_array_fetch_string(&_6, parts, SL("port"), PH_NOISY | PH_READONLY, "phalconry/http/uri.zep", 103 TSRMLS_CC);
		ZEPHIR_INIT_LNVAR(_4);
		ZEPHIR_CONCAT_SV(_4, ":", _6);
		zephir_concat_self(&uri, _4 TSRMLS_CC);
	}
	_5 = zephir_array_isset_string(parts, SS("path"));
	if (_5) {
		zephir_array_fetch_string(&_3, parts, SL("path"), PH_NOISY | PH_READONLY, "phalconry/http/uri.zep", 106 TSRMLS_CC);
		_5 = !(ZEPHIR_IS_EMPTY(_3));
	}
	if (_5) {
		zephir_array_fetch_string(&_6, parts, SL("path"), PH_NOISY | PH_READONLY, "phalconry/http/uri.zep", 107 TSRMLS_CC);
		zephir_concat_self(&uri, _6 TSRMLS_CC);
	}
	_5 = zephir_array_isset_string(parts, SS("query"));
	if (_5) {
		zephir_array_fetch_string(&_3, parts, SL("query"), PH_NOISY | PH_READONLY, "phalconry/http/uri.zep", 110 TSRMLS_CC);
		_5 = !(ZEPHIR_IS_EMPTY(_3));
	}
	if (_5) {
		zephir_array_fetch_string(&_6, parts, SL("query"), PH_NOISY | PH_READONLY, "phalconry/http/uri.zep", 111 TSRMLS_CC);
		ZEPHIR_CALL_METHOD(&_14, this_ptr, "buildquery", NULL, _6);
		zephir_check_call_status();
		ZEPHIR_INIT_LNVAR(_4);
		ZEPHIR_CONCAT_SV(_4, "?", _14);
		zephir_concat_self(&uri, _4 TSRMLS_CC);
	}
	_5 = zephir_array_isset_string(parts, SS("fragment"));
	if (_5) {
		zephir_array_fetch_string(&_3, parts, SL("fragment"), PH_NOISY | PH_READONLY, "phalconry/http/uri.zep", 114 TSRMLS_CC);
		_5 = !(ZEPHIR_IS_EMPTY(_3));
	}
	if (_5) {
		zephir_array_fetch_string(&_6, parts, SL("fragment"), PH_NOISY | PH_READONLY, "phalconry/http/uri.zep", 115 TSRMLS_CC);
		ZEPHIR_INIT_LNVAR(_4);
		ZEPHIR_CONCAT_SV(_4, "#", _6);
		zephir_concat_self(&uri, _4 TSRMLS_CC);
	}
	RETURN_CCTOR(uri);

}

PHP_METHOD(Phalconry_Http_Uri, buildQuery) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_1 = NULL;
	zval *query, *_0 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &query);



	ZEPHIR_INIT_VAR(_0);
	if (Z_TYPE_P(query) == IS_ARRAY) {
		ZEPHIR_CALL_FUNCTION(&_0, "http_build_query", &_1, query);
		zephir_check_call_status();
	} else {
		ZEPHIR_CPY_WRT(_0, query);
	}
	RETURN_CCTOR(_0);

}

PHP_METHOD(Phalconry_Http_Uri, resolve) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *uri, *newUri;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &uri);



	ZEPHIR_INIT_VAR(newUri);
	object_init_ex(newUri, phalconry_http_uri_ce);
	ZEPHIR_CALL_METHOD(NULL, newUri, "__construct", NULL, this_ptr);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, newUri, "extend", NULL, uri);
	zephir_check_call_status();
	RETURN_CCTOR(newUri);

}

PHP_METHOD(Phalconry_Http_Uri, extend) {

	zephir_nts_static zephir_fcall_cache_entry *_7 = NULL, *_9 = NULL;
	zval *_4;
	int ZEPHIR_LAST_CALL_STATUS;
	zend_bool _0;
	zval *uri = NULL, *_1, *_2, *_3, *_5 = NULL, *_6 = NULL, *_8 = NULL, *_10, *_11, *_12, *_13, *_14, *_15;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &uri);

	ZEPHIR_SEPARATE_PARAM(uri);


	_0 = Z_TYPE_P(uri) == IS_OBJECT;
	if (_0) {
		_0 = zephir_instance_of_ev(uri, phalconry_http_uri_ce TSRMLS_CC);
	}
	if (_0) {
		ZEPHIR_INIT_NVAR(uri);
		object_init_ex(uri, phalconry_http_uri_ce);
		ZEPHIR_CALL_METHOD(NULL, uri, "__construct", NULL, uri);
		zephir_check_call_status();
	}
	ZEPHIR_INIT_VAR(_1);
	_2 = zephir_fetch_nproperty_this(this_ptr, SL("parts"), PH_NOISY_CC);
	_3 = zephir_fetch_nproperty_this(uri, SL("parts"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_4);
	array_init_size(_4, 3);
	ZEPHIR_INIT_VAR(_5);
	ZVAL_STRING(_5, "query", 1);
	zephir_array_fast_append(_4, _5);
	ZEPHIR_INIT_NVAR(_5);
	ZVAL_STRING(_5, "path", 1);
	zephir_array_fast_append(_4, _5);
	ZEPHIR_CALL_FUNCTION(&_6, "array_flip", &_7, _4);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&_8, "array_diff_key", &_9, _3, _6);
	zephir_check_call_status();
	zephir_fast_array_merge(_1, &(_2), &(_8) TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("parts"), _1 TSRMLS_CC);
	_10 = zephir_fetch_nproperty_this(uri, SL("parts"), PH_NOISY_CC);
	zephir_array_fetch_string(&_11, _10, SL("query"), PH_NOISY | PH_READONLY, "phalconry/http/uri.zep", 147 TSRMLS_CC);
	if (!(ZEPHIR_IS_EMPTY(_11))) {
		_12 = zephir_fetch_nproperty_this(uri, SL("parts"), PH_NOISY_CC);
		zephir_array_fetch_string(&_13, _12, SL("query"), PH_NOISY | PH_READONLY, "phalconry/http/uri.zep", 148 TSRMLS_CC);
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "extendquery", NULL, _13);
		zephir_check_call_status();
	}
	_12 = zephir_fetch_nproperty_this(uri, SL("parts"), PH_NOISY_CC);
	zephir_array_fetch_string(&_13, _12, SL("path"), PH_NOISY | PH_READONLY, "phalconry/http/uri.zep", 151 TSRMLS_CC);
	if (!(ZEPHIR_IS_EMPTY(_13))) {
		_14 = zephir_fetch_nproperty_this(uri, SL("parts"), PH_NOISY_CC);
		zephir_array_fetch_string(&_15, _14, SL("path"), PH_NOISY | PH_READONLY, "phalconry/http/uri.zep", 152 TSRMLS_CC);
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "extendpath", NULL, _15);
		zephir_check_call_status();
	}
	RETURN_THIS();

}

PHP_METHOD(Phalconry_Http_Uri, extendQuery) {

	zend_bool _1;
	zval *params_param = NULL, *_0, *_2, *_3, *_4 = NULL, *_5, *_6, *_7;
	zval *params = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &params_param);

	zephir_get_arrval(params, params_param);


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("parts"), PH_NOISY_CC);
	_1 = zephir_array_isset_string(_0, SS("query"));
	if (_1) {
		_2 = zephir_fetch_nproperty_this(this_ptr, SL("parts"), PH_NOISY_CC);
		zephir_array_fetch_string(&_3, _2, SL("query"), PH_NOISY | PH_READONLY, "phalconry/http/uri.zep", 161 TSRMLS_CC);
		_1 = !(ZEPHIR_IS_EMPTY(_3));
	}
	if (_1) {
		ZEPHIR_INIT_VAR(_4);
		_5 = zephir_fetch_nproperty_this(this_ptr, SL("parts"), PH_NOISY_CC);
		zephir_array_fetch_string(&_6, _5, SL("query"), PH_NOISY | PH_READONLY, "phalconry/http/uri.zep", 162 TSRMLS_CC);
		zephir_fast_array_merge(_4, &(_6), &(params) TSRMLS_CC);
		ZEPHIR_INIT_VAR(_7);
		ZVAL_STRING(_7, "query", 1);
		zephir_update_property_array(this_ptr, SL("parts"), _7, _4 TSRMLS_CC);
	} else {
		ZEPHIR_INIT_NVAR(_4);
		ZVAL_STRING(_4, "query", 1);
		zephir_update_property_array(this_ptr, SL("parts"), _4, params TSRMLS_CC);
	}
	RETURN_THIS();

}

PHP_METHOD(Phalconry_Http_Uri, extendPath) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_13 = NULL, *_16 = NULL;
	zend_bool _3;
	zval *path_param = NULL, _0, *_1 = NULL, *_2, *_4, *_5, *_7, *_8, *_9, *_10, _11 = zval_used_for_init, *_12 = NULL, _14, *_15 = NULL, *_17;
	zval *path = NULL, *_6;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &path_param);

	zephir_get_strval(path, path_param);


	ZEPHIR_SINIT_VAR(_0);
	ZVAL_STRING(&_0, "", 0);
	if (ZEPHIR_IS_IDENTICAL(&_0, path)) {
		RETURN_THIS();
	}
	if (zephir_start_with_str(path, SL("/"))) {
		ZEPHIR_INIT_VAR(_1);
		ZVAL_STRING(_1, "path", 1);
		zephir_update_property_array(this_ptr, SL("parts"), _1, path TSRMLS_CC);
		RETURN_THIS();
	}
	_2 = zephir_fetch_nproperty_this(this_ptr, SL("parts"), PH_NOISY_CC);
	_3 = !(zephir_array_isset_string(_2, SS("path")));
	if (!(_3)) {
		_4 = zephir_fetch_nproperty_this(this_ptr, SL("parts"), PH_NOISY_CC);
		zephir_array_fetch_string(&_5, _4, SL("path"), PH_NOISY | PH_READONLY, "phalconry/http/uri.zep", 182 TSRMLS_CC);
		_3 = ZEPHIR_IS_EMPTY(_5);
	}
	if (_3) {
		ZEPHIR_INIT_VAR(_6);
		ZEPHIR_CONCAT_SV(_6, "/", path);
		ZEPHIR_INIT_NVAR(_1);
		ZVAL_STRING(_1, "path", 1);
		zephir_update_property_array(this_ptr, SL("parts"), _1, _6 TSRMLS_CC);
		RETURN_THIS();
	}
	_7 = zephir_fetch_nproperty_this(this_ptr, SL("parts"), PH_NOISY_CC);
	zephir_array_fetch_string(&_8, _7, SL("path"), PH_NOISY | PH_READONLY, "phalconry/http/uri.zep", 187 TSRMLS_CC);
	_9 = zephir_fetch_nproperty_this(this_ptr, SL("parts"), PH_NOISY_CC);
	zephir_array_fetch_string(&_10, _9, SL("path"), PH_NOISY | PH_READONLY, "phalconry/http/uri.zep", 187 TSRMLS_CC);
	ZEPHIR_SINIT_VAR(_11);
	ZVAL_STRING(&_11, "/", 0);
	ZEPHIR_CALL_FUNCTION(&_12, "strrpos", &_13, _10, &_11);
	zephir_check_call_status();
	ZEPHIR_SINIT_NVAR(_11);
	ZVAL_LONG(&_11, 0);
	ZEPHIR_SINIT_VAR(_14);
	ZVAL_LONG(&_14, (zephir_get_numberval(_12) + 1));
	ZEPHIR_CALL_FUNCTION(&_15, "substr", &_16, _8, &_11, &_14);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_17);
	ZEPHIR_CONCAT_VV(_17, _15, path);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "path", 1);
	zephir_update_property_array(this_ptr, SL("parts"), _1, _17 TSRMLS_CC);
	RETURN_THIS();

}

