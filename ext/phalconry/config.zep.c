
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
#include "kernel/exception.h"
#include "kernel/memory.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/fcall.h"
#include "kernel/concat.h"
#include "kernel/object.h"
#include "kernel/array.h"
#include "kernel/operators.h"
#include "kernel/string.h"
#include "kernel/hash.h"


ZEPHIR_INIT_CLASS(Phalconry_Config) {

	ZEPHIR_REGISTER_CLASS_EX(Phalconry, Config, phalconry, config, zephir_get_internal_ce(SS("phalcon\\config") TSRMLS_CC), phalconry_config_method_entry, 0);

	/**
	 * @var object
	 */
	zend_declare_property_null(phalconry_config_ce, SL("_configParent"), ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

/**
 * Sets the parent object.
 *
 * @param object parentObject
 */
PHP_METHOD(Phalconry_Config, setParent) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *parentObject, *_0, *_1, *_2;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &parentObject);



	if (Z_TYPE_P(parentObject) != IS_OBJECT) {
		ZEPHIR_INIT_VAR(_0);
		object_init_ex(_0, spl_ce_InvalidArgumentException);
		ZEPHIR_INIT_VAR(_1);
		zephir_gettype(_1, parentObject TSRMLS_CC);
		ZEPHIR_INIT_VAR(_2);
		ZEPHIR_CONCAT_SV(_2, "Expecting object, given: ", _1);
		ZEPHIR_CALL_METHOD(NULL, _0, "__construct", NULL, 1, _2);
		zephir_check_call_status();
		zephir_throw_exception_debug(_0, "phalconry/config.zep", 22 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_update_property_this(this_ptr, SL("_configParent"), parentObject TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

/**
 * Returns the parent object.
 *
 * @return object|null
 */
PHP_METHOD(Phalconry_Config, getParent) {


	RETURN_MEMBER(this_ptr, "_configParent");

}

/**
 * Checks whether the config has a parent object.
 *
 * @return boolean
 */
PHP_METHOD(Phalconry_Config, hasParent) {

	zval *_0;

	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(_0);
	zephir_read_property_this(&_0, this_ptr, SL("_configParent"), PH_NOISY_CC);
	RETURN_MM_BOOL(Z_TYPE_P(_0) == IS_OBJECT);

}

/**
 * Sets an attribute using the array-syntax
 *
 *<code>
 * $config['database'] = array('type' => 'Sqlite');
 *</code>
 */
PHP_METHOD(Phalconry_Config, offsetSet) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *index = NULL, *value, *_0 = NULL, *_1;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &index, &value);

	ZEPHIR_SEPARATE_PARAM(index);


	ZEPHIR_CALL_FUNCTION(&_0, "strval", NULL, 2, index);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(index, _0);
	if (Z_TYPE_P(value) == IS_ARRAY) {
		ZEPHIR_INIT_VAR(_1);
		object_init_ex(_1, phalconry_config_ce);
		ZEPHIR_CALL_METHOD(NULL, _1, "__construct", NULL, 3, value);
		zephir_check_call_status();
		zephir_update_property_zval_zval(this_ptr, index, _1 TSRMLS_CC);
	} else {
		zephir_update_property_zval_zval(this_ptr, index, value TSRMLS_CC);
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Returns a Config object for a given section.
 *
 * @param string section Section name.
 * @return \Phalconry\Config
 *
 * @throws \Phalconry\Exception if section exists but isn't a Config.
 */
PHP_METHOD(Phalconry_Config, getConfig) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *section_param = NULL, *config = NULL, *_0;
	zval *section = NULL, *_1;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &section_param);

	if (unlikely(Z_TYPE_P(section_param) != IS_STRING && Z_TYPE_P(section_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'section' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(section_param) == IS_STRING)) {
		zephir_get_strval(section, section_param);
	} else {
		ZEPHIR_INIT_VAR(section);
		ZVAL_EMPTY_STRING(section);
	}


	ZEPHIR_OBS_VAR(config);
	if (zephir_fetch_property_zval(&config, this_ptr, section, PH_SILENT_CC)) {
		if (Z_TYPE_P(config) != IS_OBJECT) {
			ZEPHIR_INIT_VAR(_0);
			object_init_ex(_0, phalconry_exception_ce);
			ZEPHIR_INIT_VAR(_1);
			ZEPHIR_CONCAT_SVS(_1, "Config section '", section, "' is not an object");
			ZEPHIR_CALL_METHOD(NULL, _0, "__construct", NULL, 4, _1);
			zephir_check_call_status();
			zephir_throw_exception_debug(_0, "phalconry/config.zep", 81 TSRMLS_CC);
			ZEPHIR_MM_RESTORE();
			return;
		}
	} else {
		ZEPHIR_INIT_NVAR(config);
		object_init_ex(config, phalconry_config_ce);
		ZEPHIR_CALL_METHOD(NULL, config, "__construct", NULL, 3);
		zephir_check_call_status();
		zephir_update_property_zval_zval(this_ptr, section, config TSRMLS_CC);
	}
	RETURN_CCTOR(config);

}

/**
 * Get an item using "dot" notation.
 *
 * @param  string  key
 * @param  mixed   defaultValue
 * @return mixed
 */
PHP_METHOD(Phalconry_Config, get) {

	zend_bool _7;
	HashTable *_5;
	HashPosition _4;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *key = NULL, *defaultValue = NULL, *_0 = NULL, *_1, *_2 = NULL, *currentItem = NULL, *segment = NULL, *_3, **_6, *_8 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &key, &defaultValue);

	ZEPHIR_SEPARATE_PARAM(key);
	if (!defaultValue) {
		defaultValue = ZEPHIR_GLOBAL(global_null);
	}


	ZEPHIR_CALL_FUNCTION(&_0, "strval", NULL, 2, key);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(key, _0);
	ZEPHIR_OBS_VAR(_1);
	zephir_read_property_zval(&_1, this_ptr, key, PH_NOISY_CC);
	if (Z_TYPE_P(_1) != IS_NULL) {
		ZEPHIR_OBS_VAR(_2);
		zephir_read_property_zval(&_2, this_ptr, key, PH_NOISY_CC);
		RETURN_CCTOR(_2);
	}
	ZEPHIR_CPY_WRT(currentItem, this_ptr);
	ZEPHIR_INIT_VAR(_3);
	zephir_fast_explode_str(_3, SL("."), key, LONG_MAX TSRMLS_CC);
	zephir_is_iterable(_3, &_5, &_4, 0, 0, "phalconry/config.zep", 120);
	for (
	  ; zephir_hash_get_current_data_ex(_5, (void**) &_6, &_4) == SUCCESS
	  ; zephir_hash_move_forward_ex(_5, &_4)
	) {
		ZEPHIR_GET_HVALUE(segment, _6);
		_7 = Z_TYPE_P(currentItem) != IS_OBJECT;
		if (!(_7)) {
			ZEPHIR_OBS_NVAR(_2);
			zephir_read_property_zval(&_2, currentItem, segment, PH_NOISY_CC);
			_7 = Z_TYPE_P(_2) == IS_NULL;
		}
		if (_7) {
			RETVAL_ZVAL(defaultValue, 1, 0);
			RETURN_MM();
		}
		ZEPHIR_OBS_NVAR(_8);
		zephir_read_property_zval(&_8, currentItem, segment, PH_NOISY_CC);
		ZEPHIR_CPY_WRT(currentItem, _8);
	}
	RETURN_CCTOR(currentItem);

}

/**
 * Set an item using "dot" notation.
 *
 * @param  string  key
 * @param  mixed   value
 * @return \Phalconry\Config
 */
PHP_METHOD(Phalconry_Config, set) {

	zephir_fcall_cache_entry *_6 = NULL;
	HashTable *_2;
	HashPosition _1;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *key = NULL, *value, *segments, *segment = NULL, *currentItem = NULL, *realKey = NULL, *_0 = NULL, **_3, *_4 = NULL, *_5 = NULL, *_7 = NULL, *_8;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &key, &value);

	ZEPHIR_SEPARATE_PARAM(key);


	ZEPHIR_CALL_FUNCTION(&_0, "strval", NULL, 2, key);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(key, _0);
	if (zephir_memnstr_str(key, SL("."), "phalconry/config.zep", 136)) {
		ZEPHIR_INIT_VAR(segments);
		zephir_fast_explode_str(segments, SL("."), key, LONG_MAX TSRMLS_CC);
		Z_SET_ISREF_P(segments);
		ZEPHIR_CALL_FUNCTION(&realKey, "array_pop", NULL, 5, segments);
		Z_UNSET_ISREF_P(segments);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(currentItem, this_ptr);
		zephir_is_iterable(segments, &_2, &_1, 0, 0, "phalconry/config.zep", 151);
		for (
		  ; zephir_hash_get_current_data_ex(_2, (void**) &_3, &_1) == SUCCESS
		  ; zephir_hash_move_forward_ex(_2, &_1)
		) {
			ZEPHIR_GET_HVALUE(segment, _3);
			ZEPHIR_OBS_NVAR(_4);
			zephir_read_property_zval(&_4, currentItem, segment, PH_NOISY_CC);
			if (Z_TYPE_P(_4) != IS_OBJECT) {
				ZEPHIR_INIT_NVAR(_5);
				object_init_ex(_5, phalconry_config_ce);
				ZEPHIR_CALL_METHOD(NULL, _5, "__construct", &_6, 3);
				zephir_check_call_status();
				zephir_update_property_zval_zval(currentItem, segment, _5 TSRMLS_CC);
			}
			ZEPHIR_OBS_NVAR(_7);
			zephir_read_property_zval(&_7, currentItem, segment, PH_NOISY_CC);
			ZEPHIR_CPY_WRT(currentItem, _7);
		}
		if (Z_TYPE_P(value) == IS_ARRAY) {
			ZEPHIR_INIT_NVAR(_5);
			object_init_ex(_5, phalconry_config_ce);
			ZEPHIR_CALL_METHOD(NULL, _5, "__construct", &_6, 3, value);
			zephir_check_call_status();
			zephir_update_property_zval_zval(currentItem, realKey, _5 TSRMLS_CC);
		} else {
			zephir_update_property_zval_zval(currentItem, realKey, value TSRMLS_CC);
		}
	} else {
		if (Z_TYPE_P(value) == IS_ARRAY) {
			ZEPHIR_INIT_VAR(_8);
			object_init_ex(_8, phalconry_config_ce);
			ZEPHIR_CALL_METHOD(NULL, _8, "__construct", &_6, 3, value);
			zephir_check_call_status();
			zephir_update_property_zval_zval(this_ptr, key, _8 TSRMLS_CC);
		} else {
			zephir_update_property_zval_zval(this_ptr, key, value TSRMLS_CC);
		}
	}
	RETURN_THIS();

}

/**
 * Check if an item exists using "dot" notation.
 *
 * @param  string  key
 * @return bool
 */
PHP_METHOD(Phalconry_Config, has) {

	zend_bool _6;
	HashTable *_4;
	HashPosition _3;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *key = NULL, *_0 = NULL, *_1, *currentItem = NULL, *segment = NULL, *_2, **_5, *_7 = NULL, *_8 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &key);

	ZEPHIR_SEPARATE_PARAM(key);


	ZEPHIR_CALL_FUNCTION(&_0, "strval", NULL, 2, key);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(key, _0);
	ZEPHIR_OBS_VAR(_1);
	zephir_read_property_zval(&_1, this_ptr, key, PH_NOISY_CC);
	if (Z_TYPE_P(_1) != IS_NULL) {
		RETURN_MM_BOOL(1);
	}
	ZEPHIR_CPY_WRT(currentItem, this_ptr);
	ZEPHIR_INIT_VAR(_2);
	zephir_fast_explode_str(_2, SL("."), key, LONG_MAX TSRMLS_CC);
	zephir_is_iterable(_2, &_4, &_3, 0, 0, "phalconry/config.zep", 196);
	for (
	  ; zephir_hash_get_current_data_ex(_4, (void**) &_5, &_3) == SUCCESS
	  ; zephir_hash_move_forward_ex(_4, &_3)
	) {
		ZEPHIR_GET_HVALUE(segment, _5);
		_6 = Z_TYPE_P(currentItem) != IS_OBJECT;
		if (!(_6)) {
			ZEPHIR_OBS_NVAR(_7);
			zephir_read_property_zval(&_7, currentItem, segment, PH_NOISY_CC);
			_6 = Z_TYPE_P(_7) == IS_NULL;
		}
		if (_6) {
			RETURN_MM_BOOL(0);
		}
		ZEPHIR_OBS_NVAR(_8);
		zephir_read_property_zval(&_8, currentItem, segment, PH_NOISY_CC);
		ZEPHIR_CPY_WRT(currentItem, _8);
	}
	RETURN_MM_BOOL(1);

}

/**
 * Restores the state of a Phalcon\Config object
 */
PHP_METHOD(Phalconry_Config, __set_state) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *data_param = NULL;
	zval *data = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &data_param);

	data = data_param;



	object_init_ex(return_value, phalconry_config_ce);
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 3, data);
	zephir_check_call_status();
	RETURN_MM();

}

