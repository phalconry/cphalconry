
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
#include "kernel/operators.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"
#include "kernel/concat.h"
#include "kernel/string.h"
#include "kernel/hash.h"
#include "kernel/array.h"


ZEPHIR_INIT_CLASS(Phalconry_Mvc_Responder) {

	ZEPHIR_REGISTER_CLASS_EX(Phalconry\\Mvc, Responder, phalconry, mvc_responder, zephir_get_internal_ce(SS("phalcon\\mvc\\user\\component") TSRMLS_CC), phalconry_mvc_responder_method_entry, 0);

	/**
	 * Response type
	 * @var string
	 */
	zend_declare_property_string(phalconry_mvc_responder_ce, SL("_type"), "view", ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * Response types that send structured data
	 * @var array
	 */
	zend_declare_property_null(phalconry_mvc_responder_ce, SL("_dataTypes"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * The response
	 * @var \Phalcon\Http\ResponseInterface
	 */
	zend_declare_property_null(phalconry_mvc_responder_ce, SL("_response"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * Response data
	 * @var mixed
	 */
	zend_declare_property_null(phalconry_mvc_responder_ce, SL("_responseData"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * Prepended response data
	 * @var array
	 */
	zend_declare_property_null(phalconry_mvc_responder_ce, SL("_beforeData"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * Appended response data
	 * @var array
	 */
	zend_declare_property_null(phalconry_mvc_responder_ce, SL("_afterData"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * Response options
	 * @var int
	 */
	zend_declare_property_long(phalconry_mvc_responder_ce, SL("_options"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);

	phalconry_mvc_responder_ce->create_object = zephir_init_properties_Phalconry_Mvc_Responder;
	/**
	 * Designates a "view" response
	 * @var string
	 */
	zend_declare_class_constant_string(phalconry_mvc_responder_ce, SL("TYPE_VIEW"), "view" TSRMLS_CC);

	/**
	 * Designates a "text" response
	 * @var string
	 */
	zend_declare_class_constant_string(phalconry_mvc_responder_ce, SL("TYPE_TEXT"), "text" TSRMLS_CC);

	/**
	 * Designates a "json" response
	 * @var string
	 */
	zend_declare_class_constant_string(phalconry_mvc_responder_ce, SL("TYPE_JSON"), "json" TSRMLS_CC);

	/**
	 * Designates an "xml" response
	 * @var string
	 */
	zend_declare_class_constant_string(phalconry_mvc_responder_ce, SL("TYPE_XML"), "xml" TSRMLS_CC);

	return SUCCESS;

}

/**
 * Sets the type of response
 *
 * @param string type Response type
 */
PHP_METHOD(Phalconry_Mvc_Responder, setType) {

	zval *type_param = NULL;
	zval *type = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &type_param);

	zephir_get_strval(type, type_param);


	zephir_update_property_this(this_ptr, SL("_type"), type TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

/**
 * Returns the response type
 *
 * @return string
 */
PHP_METHOD(Phalconry_Mvc_Responder, getType) {


	RETURN_MEMBER(this_ptr, "_type");

}

/**
 * Whether the current response type is identical to the type given
 *
 * @param string type
 */
PHP_METHOD(Phalconry_Mvc_Responder, isType) {

	zval *type_param = NULL, *_0;
	zval *type = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &type_param);

	zephir_get_strval(type, type_param);


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_type"), PH_NOISY_CC);
	RETURN_MM_BOOL(ZEPHIR_IS_IDENTICAL(_0, type));

}

/**
 * Whether the given or current response type returns structured data
 *
 * @param string type [Optional] Default is null, returns if current type is data
 */
PHP_METHOD(Phalconry_Mvc_Responder, isDataType) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *type = NULL, *_0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &type);

	if (!type) {
		ZEPHIR_CPY_WRT(type, ZEPHIR_GLOBAL(global_null));
	} else {
		ZEPHIR_SEPARATE_PARAM(type);
	}


	if (Z_TYPE_P(type) == IS_NULL) {
		ZEPHIR_OBS_NVAR(type);
		zephir_read_property_this(&type, this_ptr, SL("_type"), PH_NOISY_CC);
	}
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_dataTypes"), PH_NOISY_CC);
	ZEPHIR_RETURN_CALL_FUNCTION("in_array", NULL, 61, type, _0, ZEPHIR_GLOBAL(global_true));
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Modifies and sends the response
 *
 * If the controller returns boolean false or the response object, no modification takes place.
 *
 * If this->fillEmptyContent() == true (default), attempts to fill empty response content with
 * the value returned by the controller.
 *
 * @param \Phalcon\Http\ResponseInterface response
 */
PHP_METHOD(Phalconry_Mvc_Responder, respond) {

	zend_bool _3, _4;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *response, *eventsManager = NULL, *rtnVal = NULL, *content = NULL, *_0 = NULL, *_1 = NULL, *_2 = NULL, *_5, _6;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &response);



	zephir_update_property_this(this_ptr, SL("_response"), response TSRMLS_CC);
	ZEPHIR_CALL_METHOD(&eventsManager, this_ptr, "geteventsmanager", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_0, response, "getdi", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_2);
	ZVAL_STRING(_2, "dispatcher", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&_1, _0, "getshared", NULL, 0, _2);
	zephir_check_temp_parameter(_2);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&rtnVal, _1, "getreturnedvalue", NULL, 0);
	zephir_check_call_status();
	if (Z_TYPE_P(eventsManager) == IS_OBJECT) {
		ZEPHIR_INIT_NVAR(_2);
		ZVAL_STRING(_2, "responder:beforeRespond", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(NULL, eventsManager, "fire", NULL, 0, _2, this_ptr, response);
		zephir_check_temp_parameter(_2);
		zephir_check_call_status();
	}
	_3 = !ZEPHIR_IS_FALSE_IDENTICAL(rtnVal);
	if (_3) {
		_3 = !ZEPHIR_IS_IDENTICAL(rtnVal, response);
	}
	if (_3) {
		ZEPHIR_CALL_METHOD(&content, response, "getcontent", NULL, 0);
		zephir_check_call_status();
		_4 = ZEPHIR_IS_EMPTY(content);
		if (_4) {
			_4 = !(ZEPHIR_IS_EMPTY(rtnVal));
		}
		if (_4) {
			_5 = zephir_fetch_nproperty_this(this_ptr, SL("_type"), PH_NOISY_CC);
			ZEPHIR_SINIT_VAR(_6);
			ZVAL_STRING(&_6, "view", 0);
			if (ZEPHIR_IS_IDENTICAL(&_6, _5)) {
				ZEPHIR_CALL_METHOD(NULL, response, "setcontent", NULL, 0, rtnVal);
				zephir_check_call_status();
			} else {
				zephir_update_property_this(this_ptr, SL("_responseData"), rtnVal TSRMLS_CC);
			}
		}
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "formatresponse", NULL, 0, response);
		zephir_check_call_status();
	}
	if (Z_TYPE_P(eventsManager) == IS_OBJECT) {
		ZEPHIR_INIT_NVAR(_2);
		ZVAL_STRING(_2, "responder:respond", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(NULL, eventsManager, "fire", NULL, 0, _2, this_ptr, response);
		zephir_check_temp_parameter(_2);
		zephir_check_call_status();
	}
	ZEPHIR_CALL_METHOD(NULL, response, "send", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Phalconry_Mvc_Responder, setOptions) {

	zval *options;

	zephir_fetch_params(0, 1, 0, &options);



	zephir_update_property_this(this_ptr, SL("_options"), options TSRMLS_CC);

}

PHP_METHOD(Phalconry_Mvc_Responder, getOptions) {


	RETURN_MEMBER(this_ptr, "_options");

}

PHP_METHOD(Phalconry_Mvc_Responder, addOption) {

	zval *option_param = NULL, *_0, *_1;
	int option;

	zephir_fetch_params(0, 1, 0, &option_param);

	option = zephir_get_intval(option_param);


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_options"), PH_NOISY_CC);
	ZEPHIR_INIT_ZVAL_NREF(_1);
	ZVAL_LONG(_1, ((int) (zephir_get_numberval(_0)) | option));
	zephir_update_property_this(this_ptr, SL("_options"), _1 TSRMLS_CC);

}

PHP_METHOD(Phalconry_Mvc_Responder, prependResponseData) {

	zval *key_param = NULL, *value;
	zval *key = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &key_param, &value);

	if (unlikely(Z_TYPE_P(key_param) != IS_STRING && Z_TYPE_P(key_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'key' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(key_param) == IS_STRING)) {
		zephir_get_strval(key, key_param);
	} else {
		ZEPHIR_INIT_VAR(key);
		ZVAL_EMPTY_STRING(key);
	}


	zephir_update_property_array(this_ptr, SL("_beforeData"), key, value TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Phalconry_Mvc_Responder, appendResponseData) {

	zval *key_param = NULL, *value;
	zval *key = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &key_param, &value);

	if (unlikely(Z_TYPE_P(key_param) != IS_STRING && Z_TYPE_P(key_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'key' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(key_param) == IS_STRING)) {
		zephir_get_strval(key, key_param);
	} else {
		ZEPHIR_INIT_VAR(key);
		ZVAL_EMPTY_STRING(key);
	}


	zephir_update_property_array(this_ptr, SL("_afterData"), key, value TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Phalconry_Mvc_Responder, formatResponse) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *method = NULL;
	zval *response, *_0, *_1, *_2;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &response);



	ZEPHIR_INIT_VAR(_0);
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("_type"), PH_NOISY_CC);
	zephir_ucfirst(_0, _1);
	ZEPHIR_INIT_VAR(_2);
	ZEPHIR_CONCAT_SV(_2, "format", _0);
	zephir_get_strval(method, _2);
	if ((zephir_method_exists(this_ptr, method TSRMLS_CC)  == SUCCESS)) {
		ZEPHIR_CALL_METHOD_ZVAL(NULL, this_ptr, method, NULL, 0, response);
		zephir_check_call_status();
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Phalconry_Mvc_Responder, formatText) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *response, *_0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &response);



	ZEPHIR_INIT_VAR(_0);
	ZVAL_STRING(_0, "text/plain", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(NULL, response, "setcontenttype", NULL, 0, _0);
	zephir_check_temp_parameter(_0);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Phalconry_Mvc_Responder, formatJson) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *response, *_0 = NULL, *_1 = NULL, *_2;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &response);



	ZEPHIR_CALL_METHOD(NULL, this_ptr, "formatdataresponse", NULL, 0, response);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_0);
	ZVAL_LONG(_0, 32);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "addoption", NULL, 0, _0);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(_0);
	ZVAL_STRING(_0, "application/json", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(NULL, response, "setcontenttype", NULL, 0, _0);
	zephir_check_temp_parameter(_0);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(_0);
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "builddataresponsecontent", NULL, 0);
	zephir_check_call_status();
	_2 = zephir_fetch_nproperty_this(this_ptr, SL("_options"), PH_NOISY_CC);
	zephir_json_encode(_0, &(_0), _1, zephir_get_intval(_2)  TSRMLS_CC);
	ZEPHIR_CALL_METHOD(NULL, response, "setcontent", NULL, 0, _0);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Phalconry_Mvc_Responder, formatXml) {

	zend_class_entry *_2;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *response, *_0, *_1 = NULL, *_3 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &response);



	ZEPHIR_CALL_METHOD(NULL, this_ptr, "formatdataresponse", NULL, 0, response);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_0);
	ZVAL_STRING(_0, "application/xml", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(NULL, response, "setcontenttype", NULL, 0, _0);
	zephir_check_temp_parameter(_0);
	zephir_check_call_status();
	_2 = zend_fetch_class(SL("Util\\Xml"), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);
	ZEPHIR_CALL_METHOD(&_3, this_ptr, "builddataresponsecontent", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_CE_STATIC(&_1, _2, "writedocument", NULL, 0, _3);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, response, "setcontent", NULL, 0, _1);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Phalconry_Mvc_Responder, formatDataResponse) {

	zephir_fcall_cache_entry *_6 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *response, *data = NULL, *status = NULL, *di = NULL, *_0 = NULL, *_1 = NULL, *_2 = NULL, _3, _4, *_5 = NULL, _7, *_8 = NULL, *_9 = NULL, *_10, _11, *_12 = NULL, *_13 = NULL, *_14 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &response);



	ZEPHIR_OBS_VAR(data);
	zephir_read_property_this(&data, this_ptr, SL("_responseData"), PH_NOISY_CC);
	if (Z_TYPE_P(data) == IS_NULL) {
		ZEPHIR_CALL_METHOD(&data, response, "getcontent", NULL, 0);
		zephir_check_call_status();
	}
	ZEPHIR_CALL_METHOD(&_0, response, "getheaders", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_1);
	ZVAL_STRING(_1, "Status", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&status, _0, "get", NULL, 0, _1);
	zephir_check_temp_parameter(_1);
	zephir_check_call_status();
	if (!(zephir_is_true(status))) {
		ZEPHIR_INIT_NVAR(_1);
		ZVAL_LONG(_1, 200);
		ZEPHIR_INIT_VAR(_2);
		ZVAL_STRING(_2, "OK", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(NULL, response, "setstatuscode", NULL, 0, _1, _2);
		zephir_check_temp_parameter(_2);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(status);
		ZVAL_STRING(status, "200 OK", 1);
	}
	ZEPHIR_SINIT_VAR(_3);
	ZVAL_LONG(&_3, 0);
	ZEPHIR_SINIT_VAR(_4);
	ZVAL_LONG(&_4, 3);
	ZEPHIR_INIT_NVAR(_1);
	zephir_substr(_1, status, 0 , 3 , 0);
	ZEPHIR_INIT_NVAR(_2);
	ZVAL_STRING(_2, "status", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_VAR(_5);
	ZVAL_LONG(_5, zephir_get_intval(_1));
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "prependresponsedata", &_6, 0, _2, _5);
	zephir_check_temp_parameter(_2);
	zephir_check_call_status();
	ZEPHIR_SINIT_VAR(_7);
	ZVAL_LONG(&_7, 4);
	ZEPHIR_INIT_NVAR(_2);
	zephir_substr(_2, status, 4 , 0, ZEPHIR_SUBSTR_NO_LENGTH);
	ZEPHIR_INIT_NVAR(_5);
	ZVAL_STRING(_5, "message", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "prependresponsedata", &_6, 0, _5, _2);
	zephir_check_temp_parameter(_5);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&di, response, "getdi", NULL, 0);
	zephir_check_call_status();
	if (Z_TYPE_P(di) == IS_OBJECT) {
		ZEPHIR_INIT_NVAR(_5);
		ZVAL_STRING(_5, "request", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&_8, di, "getshared", NULL, 0, _5);
		zephir_check_temp_parameter(_5);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(_5);
		ZVAL_STRING(_5, "dev", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&_9, _8, "hasquery", NULL, 0, _5);
		zephir_check_temp_parameter(_5);
		zephir_check_call_status();
		if (zephir_is_true(_9)) {
			_10 = zephir_fetch_nproperty_this(this_ptr, SL("_type"), PH_NOISY_CC);
			ZEPHIR_SINIT_VAR(_11);
			ZVAL_STRING(&_11, "json", 0);
			if (ZEPHIR_IS_IDENTICAL(&_11, _10)) {
				ZEPHIR_INIT_NVAR(_5);
				ZVAL_LONG(_5, 128);
				ZEPHIR_CALL_METHOD(NULL, this_ptr, "addoption", NULL, 0, _5);
				zephir_check_call_status();
			}
			ZEPHIR_INIT_NVAR(_5);
			ZVAL_STRING(_5, "diagnostics", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(&_12, di, "has", NULL, 0, _5);
			zephir_check_temp_parameter(_5);
			zephir_check_call_status();
			if (zephir_is_true(_12)) {
				ZEPHIR_INIT_NVAR(_5);
				ZVAL_STRING(_5, "diagnostics", ZEPHIR_TEMP_PARAM_COPY);
				ZEPHIR_CALL_METHOD(&_13, di, "getshared", NULL, 0, _5);
				zephir_check_temp_parameter(_5);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&_14, _13, "getall", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(_5);
				ZVAL_STRING(_5, "diagnostics", ZEPHIR_TEMP_PARAM_COPY);
				ZEPHIR_CALL_METHOD(NULL, this_ptr, "appendresponsedata", NULL, 0, _5, _14);
				zephir_check_temp_parameter(_5);
				zephir_check_call_status();
			}
		}
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Phalconry_Mvc_Responder, buildDataResponseContent) {

	int ZEPHIR_LAST_CALL_STATUS;
	HashTable *_2, *_8;
	HashPosition _1, _7;
	zval *content, *key = NULL, *value = NULL, *_0, **_3, *_4 = NULL, *_5, *_6, **_9;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(content);
	array_init(content);
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_beforeData"), PH_NOISY_CC);
	zephir_is_iterable(_0, &_2, &_1, 0, 0, "phalconry/mvc/responder.zep", 271);
	for (
	  ; zephir_hash_get_current_data_ex(_2, (void**) &_3, &_1) == SUCCESS
	  ; zephir_hash_move_forward_ex(_2, &_1)
	) {
		ZEPHIR_GET_HMKEY(key, _2, _1);
		ZEPHIR_GET_HVALUE(value, _3);
		ZEPHIR_INIT_LNVAR(_4);
		if (zephir_is_callable(value TSRMLS_CC)) {
			ZEPHIR_INIT_NVAR(_4);
			ZEPHIR_CALL_USER_FUNC(_4, value);
			zephir_check_call_status();
		} else {
			ZEPHIR_CPY_WRT(_4, value);
		}
		zephir_array_update_zval(&content, key, &_4, PH_COPY | PH_SEPARATE);
	}
	_5 = zephir_fetch_nproperty_this(this_ptr, SL("_responseData"), PH_NOISY_CC);
	zephir_array_update_string(&content, SL("data"), &_5, PH_COPY | PH_SEPARATE);
	_6 = zephir_fetch_nproperty_this(this_ptr, SL("_afterData"), PH_NOISY_CC);
	zephir_is_iterable(_6, &_8, &_7, 0, 0, "phalconry/mvc/responder.zep", 277);
	for (
	  ; zephir_hash_get_current_data_ex(_8, (void**) &_9, &_7) == SUCCESS
	  ; zephir_hash_move_forward_ex(_8, &_7)
	) {
		ZEPHIR_GET_HMKEY(key, _8, _7);
		ZEPHIR_GET_HVALUE(value, _9);
		ZEPHIR_INIT_LNVAR(_4);
		if (zephir_is_callable(value TSRMLS_CC)) {
			ZEPHIR_INIT_NVAR(_4);
			ZEPHIR_CALL_USER_FUNC(_4, value);
			zephir_check_call_status();
		} else {
			ZEPHIR_CPY_WRT(_4, value);
		}
		zephir_array_update_zval(&content, key, &_4, PH_COPY | PH_SEPARATE);
	}
	RETURN_CCTOR(content);

}

static zend_object_value zephir_init_properties_Phalconry_Mvc_Responder(zend_class_entry *class_type TSRMLS_DC) {

		zval *_4;
		zval *_0, *_1 = NULL, *_2, *_3;

		ZEPHIR_MM_GROW();
	
	{
		zval *this_ptr = NULL;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		_0 = zephir_fetch_nproperty_this(this_ptr, SL("_afterData"), PH_NOISY_CC);
		if (Z_TYPE_P(_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(_1);
			array_init(_1);
			zephir_update_property_this(this_ptr, SL("_afterData"), _1 TSRMLS_CC);
		}
		_2 = zephir_fetch_nproperty_this(this_ptr, SL("_beforeData"), PH_NOISY_CC);
		if (Z_TYPE_P(_2) == IS_NULL) {
			ZEPHIR_INIT_NVAR(_1);
			array_init(_1);
			zephir_update_property_this(this_ptr, SL("_beforeData"), _1 TSRMLS_CC);
		}
		_3 = zephir_fetch_nproperty_this(this_ptr, SL("_dataTypes"), PH_NOISY_CC);
		if (Z_TYPE_P(_3) == IS_NULL) {
			ZEPHIR_INIT_VAR(_4);
			zephir_create_array(_4, 2, 0 TSRMLS_CC);
			ZEPHIR_INIT_NVAR(_1);
			ZVAL_STRING(_1, "json", 1);
			zephir_array_fast_append(_4, _1);
			ZEPHIR_INIT_NVAR(_1);
			ZVAL_STRING(_1, "xml", 1);
			zephir_array_fast_append(_4, _1);
			zephir_update_property_this(this_ptr, SL("_dataTypes"), _4 TSRMLS_CC);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJVAL_P(this_ptr);
	}

}

