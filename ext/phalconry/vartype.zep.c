
#ifdef HAVE_CONFIG_H
#include "../ext_config.h"
#endif

#include <php.h>
#include "../php_ext.h"
#include "../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/object.h"
#include "kernel/fcall.h"
#include "kernel/memory.h"
#include "kernel/operators.h"
#include "kernel/hash.h"
#include "kernel/array.h"
#include "kernel/string.h"
#include "kernel/exception.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/concat.h"


ZEPHIR_INIT_CLASS(Phalconry_VarType) {

	ZEPHIR_REGISTER_CLASS(Phalconry, VarType, phalconry, vartype, phalconry_vartype_method_entry, 0);

	zend_declare_property_null(phalconry_vartype_ce, SL("decimalPoint"), ZEND_ACC_PROTECTED|ZEND_ACC_STATIC TSRMLS_CC);

	zend_declare_class_constant_long(phalconry_vartype_ce, SL("CAST_NUMERIC"), 0 TSRMLS_CC);

	zend_declare_class_constant_long(phalconry_vartype_ce, SL("FORCE_STRING"), 1 TSRMLS_CC);

	zend_declare_class_constant_long(phalconry_vartype_ce, SL("IGNORE_ERROR"), 5 TSRMLS_CC);

	return SUCCESS;

}

/**
 * Converts a value to an array
 *
 * @param mixed
 * @return array
 */
PHP_METHOD(Phalconry_VarType, toArray) {

	zval *_1 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *arg, *_0 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &arg);



	if (Z_TYPE_P(arg) == IS_ARRAY) {
		RETVAL_ZVAL(arg, 1, 0);
		RETURN_MM();
	}
	if (Z_TYPE_P(arg) == IS_OBJECT) {
		if ((zephir_method_exists_ex(arg, SS("toarray") TSRMLS_CC) == SUCCESS)) {
			ZEPHIR_RETURN_CALL_METHOD(arg, "toarray", NULL, 0);
			zephir_check_call_status();
			RETURN_MM();
		}
		ZEPHIR_INIT_VAR(_0);
		if (zephir_zval_is_traversable(arg TSRMLS_CC)) {
			ZEPHIR_CALL_FUNCTION(&_0, "iterator_to_array", NULL, 76, arg);
			zephir_check_call_status();
		} else {
			ZEPHIR_CALL_FUNCTION(&_0, "get_object_vars", NULL, 77, arg);
			zephir_check_call_status();
		}
		RETURN_CCTOR(_0);
	}
	zephir_get_arrval(_1, arg);
	RETURN_CTOR(_1);

}

/**
 * Converts a value to an object
 *
 * @param mixed
 * @return object
 */
PHP_METHOD(Phalconry_VarType, toObject) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *arg, *_0 = NULL, *_1 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &arg);



	if (Z_TYPE_P(arg) == IS_OBJECT) {
		ZEPHIR_INIT_VAR(_0);
		if (zephir_instance_of_ev(arg, zend_standard_class_def TSRMLS_CC)) {
			ZEPHIR_CPY_WRT(_0, arg);
		} else {
			ZEPHIR_CALL_SELF(&_1, "toarray", NULL, 0, arg);
			zephir_check_call_status();
			zephir_convert_to_object(_1);
			ZEPHIR_CPY_WRT(_0, _1);
		}
		RETURN_CCTOR(_0);
	}
	zephir_convert_to_object(arg);
	RETVAL_ZVAL(arg, 1, 0);
	RETURN_MM();

}

/**
 * Converts a value to arrays recursively.
 *
 * @param mixed
 * @return array
 */
PHP_METHOD(Phalconry_VarType, toArrays) {

	zephir_fcall_cache_entry *_6 = NULL;
	zend_bool _4;
	HashTable *_2;
	HashPosition _1;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *arg, *arr, *key = NULL, *value = NULL, *_0 = NULL, **_3, *_5 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &arg);



	ZEPHIR_INIT_VAR(arr);
	array_init(arr);
	ZEPHIR_CALL_SELF(&_0, "toarray", NULL, 0, arg);
	zephir_check_call_status();
	zephir_is_iterable(_0, &_2, &_1, 0, 0, "phalconry/vartype.zep", 74);
	for (
	  ; zephir_hash_get_current_data_ex(_2, (void**) &_3, &_1) == SUCCESS
	  ; zephir_hash_move_forward_ex(_2, &_1)
	) {
		ZEPHIR_GET_HMKEY(key, _2, _1);
		ZEPHIR_GET_HVALUE(value, _3);
		_4 = Z_TYPE_P(value) == IS_ARRAY;
		if (!(_4)) {
			_4 = Z_TYPE_P(value) == IS_OBJECT;
		}
		if (_4) {
			ZEPHIR_CALL_SELF(&_5, "toarrays", &_6, 0, value);
			zephir_check_call_status();
			zephir_array_update_zval(&arr, key, &_5, PH_COPY | PH_SEPARATE);
		} else {
			zephir_array_update_zval(&arr, key, &value, PH_COPY | PH_SEPARATE);
		}
	}
	RETURN_CCTOR(arr);

}

/**
 * Converts a value to objects recursively.
 *
 * Objects are converted to instances of stdClass
 *
 * @param mixed
 * @return object
 */
PHP_METHOD(Phalconry_VarType, toObjects) {

	zephir_fcall_cache_entry *_6 = NULL;
	zend_bool _4;
	HashTable *_2;
	HashPosition _1;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *arg, *arr, *key = NULL, *value = NULL, *_0 = NULL, **_3, *_5 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &arg);



	ZEPHIR_INIT_VAR(arr);
	array_init(arr);
	ZEPHIR_CALL_SELF(&_0, "toarray", NULL, 0, arg);
	zephir_check_call_status();
	zephir_is_iterable(_0, &_2, &_1, 0, 0, "phalconry/vartype.zep", 100);
	for (
	  ; zephir_hash_get_current_data_ex(_2, (void**) &_3, &_1) == SUCCESS
	  ; zephir_hash_move_forward_ex(_2, &_1)
	) {
		ZEPHIR_GET_HMKEY(key, _2, _1);
		ZEPHIR_GET_HVALUE(value, _3);
		_4 = Z_TYPE_P(value) == IS_ARRAY;
		if (!(_4)) {
			_4 = Z_TYPE_P(value) == IS_OBJECT;
		}
		if (_4) {
			ZEPHIR_CALL_SELF(&_5, "toobjects", &_6, 0, value);
			zephir_check_call_status();
			zephir_array_update_zval(&arr, key, &_5, PH_COPY | PH_SEPARATE);
		} else {
			zephir_array_update_zval(&arr, key, &value, PH_COPY | PH_SEPARATE);
		}
	}
	zephir_convert_to_object(arr);
	RETURN_CCTOR(arr);

}

/**
 * Converts a variable to a boolean value
 *
 * @param mixed arg
 * @return boolean
 */
PHP_METHOD(Phalconry_VarType, toBool) {

	zend_bool _2, _4, _7, _9;
	zval *arg = NULL, *_0, _1, _3, _5, _6, _8, _10;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &arg);

	ZEPHIR_SEPARATE_PARAM(arg);


	if (Z_TYPE_P(arg) == IS_BOOL) {
		RETVAL_ZVAL(arg, 1, 0);
		RETURN_MM();
	}
	if (zephir_is_numeric(arg)) {
		RETURN_MM_BOOL(ZEPHIR_GT_LONG(arg, 0));
	}
	if (Z_TYPE_P(arg) == IS_STRING) {
		ZEPHIR_INIT_VAR(_0);
		zephir_fast_strtolower(_0, arg);
		ZEPHIR_CPY_WRT(arg, _0);
		ZEPHIR_SINIT_VAR(_1);
		ZVAL_STRING(&_1, "y", 0);
		_2 = ZEPHIR_IS_IDENTICAL(&_1, arg);
		if (!(_2)) {
			ZEPHIR_SINIT_VAR(_3);
			ZVAL_STRING(&_3, "yes", 0);
			_2 = ZEPHIR_IS_IDENTICAL(&_3, arg);
		}
		_4 = _2;
		if (!(_4)) {
			ZEPHIR_SINIT_VAR(_5);
			ZVAL_STRING(&_5, "true", 0);
			_4 = ZEPHIR_IS_IDENTICAL(&_5, arg);
		}
		if (_4) {
			RETURN_MM_BOOL(1);
		}
		ZEPHIR_SINIT_VAR(_6);
		ZVAL_STRING(&_6, "n", 0);
		_7 = ZEPHIR_IS_IDENTICAL(&_6, arg);
		if (!(_7)) {
			ZEPHIR_SINIT_VAR(_8);
			ZVAL_STRING(&_8, "no", 0);
			_7 = ZEPHIR_IS_IDENTICAL(&_8, arg);
		}
		_9 = _7;
		if (!(_9)) {
			ZEPHIR_SINIT_VAR(_10);
			ZVAL_STRING(&_10, "false", 0);
			_9 = ZEPHIR_IS_IDENTICAL(&_10, arg);
		}
		if (_9) {
			RETURN_MM_BOOL(0);
		}
	}
	RETURN_MM_BOOL(zephir_get_boolval(arg));

}

/**
 * Convert value to a scalar value.
 *
 * @param string Value we"d like to be scalar.
 * @param int $flags SCALAR_* flag bitwise mask.
 * @return string
 * @throws InvalidArgumentException if value can not be scalarized.
 */
PHP_METHOD(Phalconry_VarType, toScalar) {

	zval *_2 = NULL;
	int flags, ZEPHIR_LAST_CALL_STATUS;
	zval *arg, *flags_param = NULL, *_0, *_1 = NULL, *_3, *_4;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &arg, &flags_param);

	if (!flags_param) {
		flags = 0;
	} else {
		flags = zephir_get_intval(flags_param);
	}


	ZEPHIR_INIT_VAR(_0);
	zephir_gettype(_0, arg TSRMLS_CC);
	do {
		if (ZEPHIR_IS_STRING(_0, "string")) {
			ZEPHIR_INIT_VAR(_1);
			if ((flags & 0)) {
				ZEPHIR_CALL_SELF(&_1, "tonumber", NULL, 0, arg);
				zephir_check_call_status();
			} else {
				ZEPHIR_CPY_WRT(_1, arg);
			}
			RETURN_CCTOR(_1);
		}
		if (ZEPHIR_IS_STRING(_0, "double") || ZEPHIR_IS_STRING(_0, "integer")) {
			if ((flags & 1)) {
				zephir_get_strval(_2, arg);
				ZEPHIR_CPY_WRT(_1, _2);
			} else {
				ZEPHIR_CPY_WRT(_1, arg);
			}
			RETURN_CCTOR(_1);
		}
		if (ZEPHIR_IS_STRING(_0, "boolean")) {
			if ((flags & 1)) {
				if (zephir_is_true(arg)) {
					ZVAL_LONG(_1, 1);
				} else {
					ZVAL_LONG(_1, 0);
				}
			} else {
				if (zephir_is_true(arg)) {
					ZVAL_LONG(_1, 1);
				} else {
					ZEPHIR_INIT_NVAR(_1);
					ZVAL_LONG(_1, 0);
				}
			}
			RETURN_CCTOR(_1);
		}
		if (ZEPHIR_IS_STRING(_0, "NULL")) {
			RETURN_MM_STRING("", 1);
		}
		if (ZEPHIR_IS_STRING(_0, "object")) {
			if ((zephir_method_exists_ex(arg, SS("__tostring") TSRMLS_CC) == SUCCESS)) {
				ZEPHIR_RETURN_CALL_METHOD(arg, "__tostring", NULL, 0);
				zephir_check_call_status();
				RETURN_MM();
			}
		}
	} while(0);

	if ((flags & 5)) {
		RETURN_MM_STRING("", 1);
	}
	ZEPHIR_INIT_NVAR(_1);
	object_init_ex(_1, spl_ce_InvalidArgumentException);
	ZEPHIR_INIT_VAR(_3);
	zephir_gettype(_3, arg TSRMLS_CC);
	ZEPHIR_INIT_VAR(_4);
	ZEPHIR_CONCAT_SVS(_4, "Cannot cast value to scalar (given: '", _3, "').");
	ZEPHIR_CALL_METHOD(NULL, _1, "__construct", NULL, 1, _4);
	zephir_check_call_status();
	zephir_throw_exception_debug(_1, "phalconry/vartype.zep", 171 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();
	return;

}

/**
 * If $value is a numeric string, it is converted to a float or integer depending
 * on whether a decimal point is present. Otherwise the original value is returned.
 *
 * @param mixed $value If numeric string, converted to integer or float.
 * @return scalar Value as string, integer, or float.
 */
PHP_METHOD(Phalconry_VarType, toNumber) {

	int ZEPHIR_LAST_CALL_STATUS;
	zend_bool _0;
	zval *value, *_1, *_2 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &value);



	_0 = Z_TYPE_P(value) == IS_STRING;
	if (_0) {
		_0 = zephir_is_numeric(value);
	}
	if (_0) {
		ZEPHIR_INIT_VAR(_1);
		ZEPHIR_CALL_SELF(&_2, "getdecimalpoint", NULL, 0);
		zephir_check_call_status();
		if (zephir_memnstr(value, _2, "phalconry/vartype.zep", 184)) {
			ZVAL_DOUBLE(_1, zephir_get_doubleval(value));
		} else {
			ZVAL_LONG(_1, zephir_get_intval(value));
		}
		RETURN_CCTOR(_1);
	}
	RETVAL_ZVAL(value, 1, 0);
	RETURN_MM();

}

/**
 * Returns the decimal point for the current locale
 *
 * @return string
 */
PHP_METHOD(Phalconry_VarType, getDecimalPoint) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *decimal = NULL, *loc = NULL;

	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(decimal);
	zephir_read_static_property_ce(&decimal, phalconry_vartype_ce, SL("decimalPoint") TSRMLS_CC);
	if (Z_TYPE_P(decimal) == IS_NULL) {
		ZEPHIR_CALL_FUNCTION(&loc, "localeconv", NULL, 78);
		zephir_check_call_status();
		if (zephir_array_isset_string(loc, SS("decimal_point"))) {
			ZEPHIR_OBS_NVAR(decimal);
			zephir_array_fetch_string(&decimal, loc, SL("decimal_point"), PH_NOISY, "phalconry/vartype.zep", 203 TSRMLS_CC);
		} else {
			ZEPHIR_INIT_NVAR(decimal);
			ZVAL_STRING(decimal, ".", 1);
		}
		zephir_update_static_property_ce(phalconry_vartype_ce, SL("decimalPoint"), &decimal TSRMLS_CC);
	}
	RETURN_CCTOR(decimal);

}

