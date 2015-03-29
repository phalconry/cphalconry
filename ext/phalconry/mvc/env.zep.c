
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
#include "kernel/array.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"
#include "kernel/object.h"
#include "kernel/hash.h"
#include "kernel/concat.h"
#include "kernel/string.h"


ZEPHIR_INIT_CLASS(Phalconry_Mvc_Env) {

	ZEPHIR_REGISTER_CLASS_EX(Phalconry\\Mvc, Env, phalconry, mvc_env, zephir_get_internal_ce(SS("phalcon\\config") TSRMLS_CC), phalconry_mvc_env_method_entry, 0);

	/**
	 * Environment name
	 *
	 * @var string
	 */
	zend_declare_property_null(phalconry_mvc_env_ce, SL("env"), ZEND_ACC_PUBLIC TSRMLS_CC);

	/**
	 * Locale identifier
	 *
	 * @var string
	 */
	zend_declare_property_null(phalconry_mvc_env_ce, SL("locale"), ZEND_ACC_PUBLIC TSRMLS_CC);

	/**
	 * Timezone identifier
	 *
	 * @var string
	 */
	zend_declare_property_null(phalconry_mvc_env_ce, SL("timezone"), ZEND_ACC_PUBLIC TSRMLS_CC);

	/**
	 * Named directory paths
	 *
	 * @var \Phalcon\Registry
	 */
	zend_declare_property_null(phalconry_mvc_env_ce, SL("paths"), ZEND_ACC_PUBLIC TSRMLS_CC);

	/**
	 * Default environment identifier
	 *
	 * @var string
	 */
	zend_declare_class_constant_string(phalconry_mvc_env_ce, SL("DEFAULT_ENVIRONMENT"), "production" TSRMLS_CC);

	/**
	 * Default locale identifier
	 *
	 * @var string
	 */
	zend_declare_class_constant_string(phalconry_mvc_env_ce, SL("DEFAULT_LOCALE"), "en_US" TSRMLS_CC);

	/**
	 * Default timezone identifier
	 *
	 * @var string
	 */
	zend_declare_class_constant_string(phalconry_mvc_env_ce, SL("DEFAULT_TIMEZONE"), "UTC" TSRMLS_CC);

	return SUCCESS;

}

/**
 * Constructor
 *
 * @param array $config
 */
PHP_METHOD(Phalconry_Mvc_Env, __construct) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_1 = NULL, *_5 = NULL;
	zval *config_param = NULL, *_env = NULL, _0 = zval_used_for_init, *_2 = NULL, *_locale = NULL, *_timezone = NULL, *_3, *_4, *_6;
	zval *config = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &config_param);

	if (!config_param) {
		ZEPHIR_INIT_VAR(config);
		array_init(config);
	} else {
	config = config_param;

	}


	if (!(zephir_array_isset_string(config, SS("env")))) {
		ZEPHIR_SINIT_VAR(_0);
		ZVAL_STRING(&_0, "ENVIRONMENT", 0);
		ZEPHIR_CALL_FUNCTION(&_env, "getenv", &_1, &_0);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(_2);
		if (zephir_is_true(_env)) {
			ZEPHIR_CPY_WRT(_2, _env);
		} else {
			ZEPHIR_INIT_NVAR(_2);
			ZVAL_STRING(_2, "production", 1);
		}
		zephir_array_update_string(&config, SL("env"), &_2, PH_COPY | PH_SEPARATE);
	}
	if (!(zephir_array_isset_string(config, SS("locale")))) {
		ZEPHIR_SINIT_NVAR(_0);
		ZVAL_STRING(&_0, "LOCALE", 0);
		ZEPHIR_CALL_FUNCTION(&_locale, "getenv", &_1, &_0);
		zephir_check_call_status();
		ZEPHIR_INIT_LNVAR(_2);
		if (zephir_is_true(_locale)) {
			ZEPHIR_CPY_WRT(_2, _locale);
		} else {
			ZEPHIR_INIT_NVAR(_2);
			ZVAL_STRING(_2, "en_US", 1);
		}
		zephir_array_update_string(&config, SL("locale"), &_2, PH_COPY | PH_SEPARATE);
	}
	if (!(zephir_array_isset_string(config, SS("timezone")))) {
		ZEPHIR_SINIT_NVAR(_0);
		ZVAL_STRING(&_0, "TZ", 0);
		ZEPHIR_CALL_FUNCTION(&_timezone, "getenv", &_1, &_0);
		zephir_check_call_status();
		ZEPHIR_INIT_LNVAR(_2);
		if (zephir_is_true(_timezone)) {
			ZEPHIR_CPY_WRT(_2, _timezone);
		} else {
			ZEPHIR_INIT_NVAR(_2);
			ZVAL_STRING(_2, "UTC", 1);
		}
		zephir_array_update_string(&config, SL("timezone"), &_2, PH_COPY | PH_SEPARATE);
	}
	if (!(zephir_array_isset_string(config, SS("paths")))) {
		ZEPHIR_INIT_VAR(_3);
		object_init_ex(_3, zephir_get_internal_ce(SS("phalcon\\registry") TSRMLS_CC));
		ZEPHIR_CALL_METHOD(NULL, _3, "__construct", NULL);
		zephir_check_call_status();
		zephir_array_update_string(&config, SL("paths"), &_3, PH_COPY | PH_SEPARATE);
	}
	ZEPHIR_CALL_PARENT(NULL, phalconry_mvc_env_ce, this_ptr, "__construct", NULL, config);
	zephir_check_call_status();
	zephir_array_fetch_string(&_4, config, SL("locale"), PH_NOISY | PH_READONLY, "phalconry/mvc/env.zep", 91 TSRMLS_CC);
	ZEPHIR_SINIT_NVAR(_0);
	ZVAL_LONG(&_0, 0);
	ZEPHIR_CALL_FUNCTION(NULL, "setlocale", &_5, &_0, _4);
	zephir_check_call_status();
	zephir_array_fetch_string(&_6, config, SL("timezone"), PH_NOISY | PH_READONLY, "phalconry/mvc/env.zep", 94 TSRMLS_CC);
	ZEPHIR_CALL_FUNCTION(NULL, "date_default_timezone_set", NULL, _6);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * Sets the environment name
 *
 * @param string env
 * @return \Phalconry\Mvc\Env
 */
PHP_METHOD(Phalconry_Mvc_Env, setEnvironment) {

	zval *env_param = NULL;
	zval *env = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &env_param);

	if (unlikely(Z_TYPE_P(env_param) != IS_STRING && Z_TYPE_P(env_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'env' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(env_param) == IS_STRING)) {
		zephir_get_strval(env, env_param);
	} else {
		ZEPHIR_INIT_VAR(env);
		ZVAL_EMPTY_STRING(env);
	}


	zephir_update_property_this(this_ptr, SL("env"), env TSRMLS_CC);
	RETURN_THIS();

}

/**
 * Returns the environment name
 *
 * @return string
 */
PHP_METHOD(Phalconry_Mvc_Env, getEnvironment) {


	RETURN_MEMBER(this_ptr, "env");

}

/**
 * Sets the timezone
 *
 * @param string timezone
 * @return \Phalconry\Mvc\Env
 */
PHP_METHOD(Phalconry_Mvc_Env, setTimezone) {

	zval *timezone_param = NULL;
	zval *timezone = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &timezone_param);

	if (unlikely(Z_TYPE_P(timezone_param) != IS_STRING && Z_TYPE_P(timezone_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'timezone' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(timezone_param) == IS_STRING)) {
		zephir_get_strval(timezone, timezone_param);
	} else {
		ZEPHIR_INIT_VAR(timezone);
		ZVAL_EMPTY_STRING(timezone);
	}


	zephir_update_property_this(this_ptr, SL("timezone"), timezone TSRMLS_CC);
	RETURN_THIS();

}

/**
 * Returns the timezone
 *
 * @return string
 */
PHP_METHOD(Phalconry_Mvc_Env, getTimezone) {


	RETURN_MEMBER(this_ptr, "timezone");

}

/**
 * Sets the locale
 *
 * @param string locale
 * @return \Phalconry\Mvc\Env
 */
PHP_METHOD(Phalconry_Mvc_Env, setLocale) {

	zval *locale_param = NULL;
	zval *locale = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &locale_param);

	if (unlikely(Z_TYPE_P(locale_param) != IS_STRING && Z_TYPE_P(locale_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'locale' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(locale_param) == IS_STRING)) {
		zephir_get_strval(locale, locale_param);
	} else {
		ZEPHIR_INIT_VAR(locale);
		ZVAL_EMPTY_STRING(locale);
	}


	zephir_update_property_this(this_ptr, SL("locale"), locale TSRMLS_CC);
	RETURN_THIS();

}

/**
 * Returns the environment name
 *
 * @return string
 */
PHP_METHOD(Phalconry_Mvc_Env, getLocale) {


	RETURN_MEMBER(this_ptr, "locale");

}

/**
 * Sets the directory paths
 *
 * @param array $paths Array of directory paths
 * @return \Phalconry\Mvc\Env
 */
PHP_METHOD(Phalconry_Mvc_Env, setPaths) {

	zephir_fcall_cache_entry *_3 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	HashTable *_1;
	HashPosition _0;
	zval *paths_param = NULL, *key = NULL, *value = NULL, **_2;
	zval *paths = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &paths_param);

	zephir_get_arrval(paths, paths_param);


	zephir_is_iterable(paths, &_1, &_0, 0, 0, "phalconry/mvc/env.zep", 179);
	for (
	  ; zephir_hash_get_current_data_ex(_1, (void**) &_2, &_0) == SUCCESS
	  ; zephir_hash_move_forward_ex(_1, &_0)
	) {
		ZEPHIR_GET_HMKEY(key, _1, _0);
		ZEPHIR_GET_HVALUE(value, _2);
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "setpath", &_3, key, value);
		zephir_check_call_status();
	}
	RETURN_THIS();

}

/**
 * Returns the directory path registry
 *
 * @return \Phalcon\Registry
 */
PHP_METHOD(Phalconry_Mvc_Env, getPaths) {


	RETURN_MEMBER(this_ptr, "paths");

}

/**
 * Sets a directory path by name
 *
 * @param string $name
 * @param string $path
 * @return \Phalconry\Mvc\Env
 */
PHP_METHOD(Phalconry_Mvc_Env, setPath) {

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
	RETURN_THIS();

}

/**
 * Returns a directory path by name
 *
 * @param string $name
 * @return string
 */
PHP_METHOD(Phalconry_Mvc_Env, getPath) {

	zval *name_param = NULL, *_0, *_1;
	zval *name = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name_param);

	zephir_get_strval(name, name_param);


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("paths"), PH_NOISY_CC);
	zephir_array_fetch(&_1, _0, name, PH_NOISY | PH_READONLY, "phalconry/mvc/env.zep", 214 TSRMLS_CC);
	RETURN_CTOR(_1);

}

/**
 * Returns an entry value from a given section.
 *
 * @param string $section Section name
 * @param string $key Item key in section
 * @return mixed Item value if exists, otherwise null
 */
PHP_METHOD(Phalconry_Mvc_Env, getFrom) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *section_param = NULL, *key_param = NULL, *_0 = NULL, *_1, *_2;
	zval *section = NULL, *key = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &section_param, &key_param);

	zephir_get_strval(section, section_param);
	zephir_get_strval(key, key_param);


	ZEPHIR_INIT_VAR(_0);
	ZEPHIR_OBS_VAR(_1);
	zephir_read_property_zval(&_1, this_ptr, section, PH_NOISY_CC);
	if (Z_TYPE_P(_1) == IS_OBJECT) {
		ZEPHIR_OBS_VAR(_2);
		zephir_read_property_zval(&_2, this_ptr, section, PH_NOISY_CC);
		ZEPHIR_CALL_METHOD(&_0, _2, "get", NULL, key);
		zephir_check_call_status();
	} else {
		ZVAL_NULL(_0);
	}
	RETURN_CCTOR(_0);

}

/**
 * Magic call
 */
PHP_METHOD(Phalconry_Mvc_Env, __call) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_3 = NULL;
	zval *args = NULL;
	zval *func_param = NULL, *args_param = NULL, _0, _1, *_2 = NULL;
	zval *func = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &func_param, &args_param);

	if (unlikely(Z_TYPE_P(func_param) != IS_STRING && Z_TYPE_P(func_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'func' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(func_param) == IS_STRING)) {
		zephir_get_strval(func, func_param);
	} else {
		ZEPHIR_INIT_VAR(func);
		ZVAL_EMPTY_STRING(func);
	}
	args = args_param;



	if (zephir_end_with_str(func, SL("Path"))) {
		ZEPHIR_SINIT_VAR(_0);
		ZVAL_LONG(&_0, 0);
		ZEPHIR_SINIT_VAR(_1);
		ZVAL_LONG(&_1, (zephir_fast_strlen_ev(func) - 4));
		ZEPHIR_CALL_FUNCTION(&_2, "substr", &_3, func, &_0, &_1);
		zephir_check_call_status();
		ZEPHIR_RETURN_CALL_METHOD(this_ptr, "getpath", NULL, _2);
		zephir_check_call_status();
		RETURN_MM();
	}
	ZEPHIR_MM_RESTORE();

}

