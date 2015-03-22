
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
#include "kernel/array.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "kernel/hash.h"
#include "kernel/object.h"
#include "kernel/concat.h"


ZEPHIR_INIT_CLASS(Phalconry_Env) {

	ZEPHIR_REGISTER_CLASS_EX(Phalconry, Env, phalconry, env, zephir_get_internal_ce(SS("phalcon\\config") TSRMLS_CC), phalconry_env_method_entry, 0);

	/**
	 * Environment name
	 *
	 * @var string
	 */
	zend_declare_property_null(phalconry_env_ce, SL("env"), ZEND_ACC_PUBLIC TSRMLS_CC);

	/**
	 * Locale identifier
	 *
	 * @var string
	 */
	zend_declare_property_null(phalconry_env_ce, SL("locale"), ZEND_ACC_PUBLIC TSRMLS_CC);

	/**
	 * Timezone identifier
	 *
	 * @var string
	 */
	zend_declare_property_null(phalconry_env_ce, SL("timezone"), ZEND_ACC_PUBLIC TSRMLS_CC);

	/**
	 * Named directory paths
	 *
	 * @var \Phalcon\Registry
	 */
	zend_declare_property_null(phalconry_env_ce, SL("paths"), ZEND_ACC_PUBLIC TSRMLS_CC);

	/**
	 * Default environment identifier
	 *
	 * @var string
	 */
	zend_declare_class_constant_string(phalconry_env_ce, SL("DEFAULT_ENVIRONMENT"), "production" TSRMLS_CC);

	/**
	 * Default locale identifier
	 *
	 * @var string
	 */
	zend_declare_class_constant_string(phalconry_env_ce, SL("DEFAULT_LOCALE"), "en_US" TSRMLS_CC);

	/**
	 * Default timezone identifier
	 *
	 * @var string
	 */
	zend_declare_class_constant_string(phalconry_env_ce, SL("DEFAULT_TIMEZONE"), "UTC" TSRMLS_CC);

	return SUCCESS;

}

/**
 * Constructor
 * 
 * @param array $config
 */
PHP_METHOD(Phalconry_Env, __construct) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_3 = NULL, *_6 = NULL;
	zval *config_param = NULL, *_0 = NULL, _1 = zval_used_for_init, *_2 = NULL, *_4, *_5, *_7;
	zval *config = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &config_param);

	if (!config_param) {
		ZEPHIR_INIT_VAR(config);
		array_init(config);
	} else {
		zephir_get_arrval(config, config_param);
	}


	if (!(zephir_array_isset_string(config, SS("env")))) {
		ZEPHIR_INIT_VAR(_0);
		ZEPHIR_SINIT_VAR(_1);
		ZVAL_STRING(&_1, "ENVIRONMENT", 0);
		ZEPHIR_CALL_FUNCTION(&_2, "getenv", &_3, &_1);
		zephir_check_call_status();
		if (zephir_is_true(_2)) {
			ZEPHIR_SINIT_NVAR(_1);
			ZVAL_STRING(&_1, "ENVIRONMENT", 0);
			ZEPHIR_CALL_FUNCTION(&_0, "getenv", &_3, &_1);
			zephir_check_call_status();
		} else {
			ZEPHIR_INIT_NVAR(_0);
			ZVAL_STRING(_0, "production", 1);
		}
		zephir_array_update_string(&config, SL("env"), &_0, PH_COPY | PH_SEPARATE);
	}
	if (!(zephir_array_isset_string(config, SS("locale")))) {
		ZEPHIR_INIT_LNVAR(_0);
		ZEPHIR_SINIT_NVAR(_1);
		ZVAL_STRING(&_1, "LOCALE", 0);
		ZEPHIR_CALL_FUNCTION(&_2, "getenv", &_3, &_1);
		zephir_check_call_status();
		if (zephir_is_true(_2)) {
			ZEPHIR_SINIT_NVAR(_1);
			ZVAL_STRING(&_1, "LOCALE", 0);
			ZEPHIR_CALL_FUNCTION(&_0, "getenv", &_3, &_1);
			zephir_check_call_status();
		} else {
			ZEPHIR_INIT_NVAR(_0);
			ZVAL_STRING(_0, "en_US", 1);
		}
		zephir_array_update_string(&config, SL("locale"), &_0, PH_COPY | PH_SEPARATE);
	}
	if (!(zephir_array_isset_string(config, SS("timezone")))) {
		ZEPHIR_INIT_LNVAR(_0);
		ZEPHIR_SINIT_NVAR(_1);
		ZVAL_STRING(&_1, "TZ", 0);
		ZEPHIR_CALL_FUNCTION(&_2, "getenv", &_3, &_1);
		zephir_check_call_status();
		if (zephir_is_true(_2)) {
			ZEPHIR_SINIT_NVAR(_1);
			ZVAL_STRING(&_1, "TZ", 0);
			ZEPHIR_CALL_FUNCTION(&_0, "getenv", &_3, &_1);
			zephir_check_call_status();
		} else {
			ZEPHIR_INIT_NVAR(_0);
			ZVAL_STRING(_0, "UTC", 1);
		}
		zephir_array_update_string(&config, SL("timezone"), &_0, PH_COPY | PH_SEPARATE);
	}
	if (!(zephir_array_isset_string(config, SS("paths")))) {
		ZEPHIR_INIT_VAR(_4);
		object_init_ex(_4, zephir_get_internal_ce(SS("phalcon\\registry") TSRMLS_CC));
		if (zephir_has_constructor(_4 TSRMLS_CC)) {
			ZEPHIR_CALL_METHOD(NULL, _4, "__construct", NULL);
			zephir_check_call_status();
		}
		zephir_array_update_string(&config, SL("paths"), &_4, PH_COPY | PH_SEPARATE);
	}
	ZEPHIR_CALL_PARENT(NULL, phalconry_env_ce, this_ptr, "__construct", NULL, config);
	zephir_check_call_status();
	zephir_array_fetch_string(&_5, config, SL("locale"), PH_NOISY | PH_READONLY, "phalconry/env.zep", 82 TSRMLS_CC);
	ZEPHIR_SINIT_NVAR(_1);
	ZVAL_LONG(&_1, 0);
	ZEPHIR_CALL_FUNCTION(NULL, "setlocale", &_6, &_1, _5);
	zephir_check_call_status();
	zephir_array_fetch_string(&_7, config, SL("timezone"), PH_NOISY | PH_READONLY, "phalconry/env.zep", 85 TSRMLS_CC);
	ZEPHIR_CALL_FUNCTION(NULL, "date_default_timezone_set", NULL, _7);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * Sets the directory paths
 * 
 * @param array $paths Array of directory paths
 */
PHP_METHOD(Phalconry_Env, setPaths) {

	zephir_fcall_cache_entry *_3 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	HashTable *_1;
	HashPosition _0;
	zval *paths_param = NULL, *key = NULL, *value = NULL, **_2;
	zval *paths = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &paths_param);

	zephir_get_arrval(paths, paths_param);


	zephir_is_iterable(paths, &_1, &_0, 0, 0, "phalconry/env.zep", 99);
	for (
	  ; zephir_hash_get_current_data_ex(_1, (void**) &_2, &_0) == SUCCESS
	  ; zephir_hash_move_forward_ex(_1, &_0)
	) {
		ZEPHIR_GET_HMKEY(key, _1, _0);
		ZEPHIR_GET_HVALUE(value, _2);
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "setpath", &_3, key, value);
		zephir_check_call_status();
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Returns the directory path registry
 * 
 * @return \Phalcon\Registry
 */
PHP_METHOD(Phalconry_Env, getPaths) {


	RETURN_MEMBER(this_ptr, "paths");

}

/**
 * Sets a directory path by name
 * 
 * @param string $name
 * @param string $path
 */
PHP_METHOD(Phalconry_Env, setPath) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_1 = NULL;
	zval *name_param = NULL, *path_param = NULL, *_0 = NULL, *_2;
	zval *name = NULL, *path = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &name_param, &path_param);

	zephir_get_strval(name, name_param);
	zephir_get_strval(path, path_param);


	ZEPHIR_CALL_FUNCTION(&_0, "realpath", &_1, path);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_2);
	ZEPHIR_CONCAT_VS(_2, _0, "/");
	zephir_update_property_array(this_ptr, SL("paths"), name, _2 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

/**
 * Returns a directory path by name
 * 
 * @param string $name
 * @return string
 */
PHP_METHOD(Phalconry_Env, getPath) {

	zval *name_param = NULL, *_0, *_1;
	zval *name = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name_param);

	zephir_get_strval(name, name_param);


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("paths"), PH_NOISY_CC);
	zephir_array_fetch(&_1, _0, name, PH_NOISY | PH_READONLY, "phalconry/env.zep", 130 TSRMLS_CC);
	RETURN_CTOR(_1);

}

/**
 * Returns an entry value from a given section.
 * 
 * @param string $section Section name
 * @param string $key Item key in section
 * @return mixed Item value if exists, otherwise null
 */
PHP_METHOD(Phalconry_Env, getFrom) {

	zval *section_param = NULL, *key_param = NULL, *_0, *_1;
	zval *section = NULL, *key = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &section_param, &key_param);

	zephir_get_strval(section, section_param);
	zephir_get_strval(key, key_param);


	ZEPHIR_INIT_VAR(_0);
	if (zephir_array_isset(this_ptr, section)) {
		zephir_array_fetch(&_1, this_ptr, section, PH_NOISY | PH_READONLY, "phalconry/env.zep", 142 TSRMLS_CC);
		zephir_array_fetch(&_0, _1, key, PH_NOISY, "phalconry/env.zep", 142 TSRMLS_CC);
	} else {
		ZVAL_NULL(_0);
	}
	RETURN_CCTOR(_0);

}

