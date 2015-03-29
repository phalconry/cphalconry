
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
#include "kernel/array.h"
#include "kernel/fcall.h"
#include "kernel/exception.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/operators.h"
#include "kernel/hash.h"


ZEPHIR_INIT_CLASS(Phalconry_Mvc_Response_AbstractDataType) {

	ZEPHIR_REGISTER_CLASS_EX(Phalconry\\Mvc\\Response, AbstractDataType, phalconry, mvc_response_abstractdatatype, phalconry_mvc_response_abstracttype_ce, phalconry_mvc_response_abstractdatatype_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	/**
	 * Response options
	 * @var int
	 */
	zend_declare_property_null(phalconry_mvc_response_abstractdatatype_ce, SL("options"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * Response content data
	 * @var array
	 */
	zend_declare_property_null(phalconry_mvc_response_abstractdatatype_ce, SL("data"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * Extra response content
	 * @var array
	 */
	zend_declare_property_null(phalconry_mvc_response_abstractdatatype_ce, SL("extra"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * Name of key to use for response data
	 * @var string
	 */
	zend_declare_class_constant_string(phalconry_mvc_response_abstractdatatype_ce, SL("RESPONSE_DATA_KEY"), "data" TSRMLS_CC);

	return SUCCESS;

}

PHP_METHOD(Phalconry_Mvc_Response_AbstractDataType, __construct) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *_1;
	zval *data = NULL, *_0, *_2 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &data);

	if (!data) {
		data = ZEPHIR_GLOBAL(global_null);
	}


	ZEPHIR_INIT_ZVAL_NREF(_0);
	ZVAL_LONG(_0, 0);
	zephir_update_property_this(this_ptr, SL("options"), _0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_1);
	array_init_size(_1, 4);
	ZEPHIR_INIT_VAR(_2);
	array_init(_2);
	zephir_array_update_string(&_1, SL("meta"), &_2, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(_2);
	array_init(_2);
	zephir_array_update_string(&_1, SL("prepend"), &_2, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(_2);
	array_init(_2);
	zephir_array_update_string(&_1, SL("append"), &_2, PH_COPY | PH_SEPARATE);
	zephir_update_property_this(this_ptr, SL("extra"), _1 TSRMLS_CC);
	if (Z_TYPE_P(data) != IS_NULL) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "setdata", NULL, data);
		zephir_check_call_status();
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Phalconry_Mvc_Response_AbstractDataType, setModifiedContent) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *response, *content;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &response, &content);



	if (!(zephir_is_instance_of(response, SL("Phalcon\\Http\\ResponseInterface") TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "Parameter 'response' must be an instance of 'Phalcon\\Http\\ResponseInterface'", "", 0);
		return;
	}
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "setdata", NULL, content);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Phalconry_Mvc_Response_AbstractDataType, setData) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *data, *_0 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &data);



	ZEPHIR_CALL_METHOD(&_0, this_ptr, "valuetoarray", NULL, data);
	zephir_check_call_status();
	zephir_update_property_this(this_ptr, SL("data"), _0 TSRMLS_CC);
	RETURN_THIS();

}

PHP_METHOD(Phalconry_Mvc_Response_AbstractDataType, getData) {


	RETURN_MEMBER(this_ptr, "data");

}

PHP_METHOD(Phalconry_Mvc_Response_AbstractDataType, prepend) {

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


	zephir_update_property_array_multi(this_ptr, SL("extra"), &value TSRMLS_CC, SL("sz"), 3, SL("prepend"), key);
	RETURN_THIS();

}

PHP_METHOD(Phalconry_Mvc_Response_AbstractDataType, append) {

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


	zephir_update_property_array_multi(this_ptr, SL("extra"), &value TSRMLS_CC, SL("sz"), 3, SL("append"), key);
	RETURN_THIS();

}

PHP_METHOD(Phalconry_Mvc_Response_AbstractDataType, setMeta) {

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


	zephir_update_property_array_multi(this_ptr, SL("extra"), &value TSRMLS_CC, SL("sz"), 3, SL("meta"), key);
	RETURN_THIS();

}

PHP_METHOD(Phalconry_Mvc_Response_AbstractDataType, getMeta) {

	zval *_0, *_1;


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("extra"), PH_NOISY_CC);
	zephir_array_fetch_string(&_1, _0, SL("meta"), PH_NOISY | PH_READONLY, "phalconry/mvc/response/abstractdatatype.zep", 86 TSRMLS_CC);
	RETURN_CTORW(_1);

}

PHP_METHOD(Phalconry_Mvc_Response_AbstractDataType, setOptions) {

	zval *options;

	zephir_fetch_params(0, 1, 0, &options);



	zephir_update_property_this(this_ptr, SL("options"), options TSRMLS_CC);
	RETURN_THISW();

}

PHP_METHOD(Phalconry_Mvc_Response_AbstractDataType, getOptions) {


	RETURN_MEMBER(this_ptr, "options");

}

PHP_METHOD(Phalconry_Mvc_Response_AbstractDataType, addOption) {

	zval *option_param = NULL, *_0, *_1;
	int option;

	zephir_fetch_params(0, 1, 0, &option_param);

	option = zephir_get_intval(option_param);


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("options"), PH_NOISY_CC);
	ZEPHIR_INIT_ZVAL_NREF(_1);
	ZVAL_LONG(_1, ((int) (zephir_get_numberval(_0)) | option));
	zephir_update_property_this(this_ptr, SL("options"), _1 TSRMLS_CC);
	RETURN_THISW();

}

PHP_METHOD(Phalconry_Mvc_Response_AbstractDataType, clearOptions) {

	zval *_0;


	ZEPHIR_INIT_ZVAL_NREF(_0);
	ZVAL_LONG(_0, 0);
	zephir_update_property_this(this_ptr, SL("options"), _0 TSRMLS_CC);
	RETURN_THISW();

}

PHP_METHOD(Phalconry_Mvc_Response_AbstractDataType, getContent) {

	int ZEPHIR_LAST_CALL_STATUS;
	HashTable *_3, *_9, *_15;
	HashPosition _2, _8, _14;
	zval *content, *key = NULL, *value = NULL, *_0, *_1, **_4, *_5 = NULL, *_6, *_7, **_10, *_11 = NULL, *_12, *_13, **_16;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(content);
	array_init(content);
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("extra"), PH_NOISY_CC);
	zephir_array_fetch_string(&_1, _0, SL("prepend"), PH_NOISY | PH_READONLY, "phalconry/mvc/response/abstractdatatype.zep", 120 TSRMLS_CC);
	zephir_is_iterable(_1, &_3, &_2, 0, 0, "phalconry/mvc/response/abstractdatatype.zep", 124);
	for (
	  ; zephir_hash_get_current_data_ex(_3, (void**) &_4, &_2) == SUCCESS
	  ; zephir_hash_move_forward_ex(_3, &_2)
	) {
		ZEPHIR_GET_HMKEY(key, _3, _2);
		ZEPHIR_GET_HVALUE(value, _4);
		ZEPHIR_INIT_LNVAR(_5);
		if (zephir_is_callable(value TSRMLS_CC)) {
			ZEPHIR_INIT_NVAR(_5);
			ZEPHIR_CALL_USER_FUNC(_5, value);
			zephir_check_call_status();
		} else {
			ZEPHIR_CPY_WRT(_5, value);
		}
		zephir_array_update_zval(&content, key, &_5, PH_COPY | PH_SEPARATE);
	}
	_6 = zephir_fetch_nproperty_this(this_ptr, SL("extra"), PH_NOISY_CC);
	zephir_array_fetch_string(&_7, _6, SL("meta"), PH_NOISY | PH_READONLY, "phalconry/mvc/response/abstractdatatype.zep", 124 TSRMLS_CC);
	zephir_is_iterable(_7, &_9, &_8, 0, 0, "phalconry/mvc/response/abstractdatatype.zep", 128);
	for (
	  ; zephir_hash_get_current_data_ex(_9, (void**) &_10, &_8) == SUCCESS
	  ; zephir_hash_move_forward_ex(_9, &_8)
	) {
		ZEPHIR_GET_HMKEY(key, _9, _8);
		ZEPHIR_GET_HVALUE(value, _10);
		ZEPHIR_INIT_LNVAR(_5);
		if (zephir_is_callable(value TSRMLS_CC)) {
			ZEPHIR_INIT_NVAR(_5);
			ZEPHIR_CALL_USER_FUNC(_5, value);
			zephir_check_call_status();
		} else {
			ZEPHIR_CPY_WRT(_5, value);
		}
		zephir_array_update_zval(&content, key, &_5, PH_COPY | PH_SEPARATE);
	}
	ZEPHIR_CALL_METHOD(&_11, this_ptr, "getdata", NULL);
	zephir_check_call_status();
	zephir_array_update_string(&content, SL("data"), &_11, PH_COPY | PH_SEPARATE);
	_12 = zephir_fetch_nproperty_this(this_ptr, SL("extra"), PH_NOISY_CC);
	zephir_array_fetch_string(&_13, _12, SL("append"), PH_NOISY | PH_READONLY, "phalconry/mvc/response/abstractdatatype.zep", 130 TSRMLS_CC);
	zephir_is_iterable(_13, &_15, &_14, 0, 0, "phalconry/mvc/response/abstractdatatype.zep", 134);
	for (
	  ; zephir_hash_get_current_data_ex(_15, (void**) &_16, &_14) == SUCCESS
	  ; zephir_hash_move_forward_ex(_15, &_14)
	) {
		ZEPHIR_GET_HMKEY(key, _15, _14);
		ZEPHIR_GET_HVALUE(value, _16);
		ZEPHIR_INIT_LNVAR(_5);
		if (zephir_is_callable(value TSRMLS_CC)) {
			ZEPHIR_INIT_NVAR(_5);
			ZEPHIR_CALL_USER_FUNC(_5, value);
			zephir_check_call_status();
		} else {
			ZEPHIR_CPY_WRT(_5, value);
		}
		zephir_array_update_zval(&content, key, &_5, PH_COPY | PH_SEPARATE);
	}
	RETURN_CCTOR(content);

}

PHP_METHOD(Phalconry_Mvc_Response_AbstractDataType, valueToArray) {

	int ZEPHIR_LAST_CALL_STATUS;
	zend_class_entry *utils_utils_typecast;
	zval *value;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &value);



	utils_utils_typecast = zend_fetch_class(SL("\\Utils\\Typecast"), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);
	ZEPHIR_RETURN_CALL_CE_STATIC(utils_utils_typecast, "toarray", NULL, value);
	zephir_check_call_status();
	RETURN_MM();

}

