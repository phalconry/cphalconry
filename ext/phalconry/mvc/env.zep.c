
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
#include "kernel/object.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"
#include "kernel/hash.h"
#include "kernel/concat.h"
#include "kernel/string.h"


ZEPHIR_INIT_CLASS(Phalconry_Mvc_Env) {

	ZEPHIR_REGISTER_CLASS_EX(Phalconry\\Mvc, Env, phalconry, mvc_env, phalconry_config_ce, phalconry_mvc_env_method_entry, 0);

	/**
	 * Environment name
	 *
	 * @var string
	 */
	zend_declare_property_null(phalconry_mvc_env_ce, SL("env"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * Timezone identifier
	 *
	 * @var string
	 */
	zend_declare_property_null(phalconry_mvc_env_ce, SL("timezone"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * Named directory paths
	 *
	 * @var \Phalcon\Registry
	 */
	zend_declare_property_null(phalconry_mvc_env_ce, SL("paths"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * Whether in command line mode.
	 *
	 * @var boolean
	 */
	zend_declare_property_null(phalconry_mvc_env_ce, SL("cli"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * Default environment identifier
	 *
	 * @var string
	 */
	zend_declare_class_constant_string(phalconry_mvc_env_ce, SL("DEFAULT_ENVIRONMENT"), "production" TSRMLS_CC);

	/**
	 * Default timezone identifier
	 *
	 * @var string
	 */
	zend_declare_class_constant_string(phalconry_mvc_env_ce, SL("DEFAULT_TIMEZONE"), "UTC" TSRMLS_CC);

	zend_class_implements(phalconry_mvc_env_ce TSRMLS_CC, 1, phalconry_mvc_environmentinterface_ce);
	return SUCCESS;

}

/**
 * Constructor.
 *
 * @param array config
 */
PHP_METHOD(Phalconry_Mvc_Env, __construct) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_1 = NULL;
	zval *config_param = NULL, *environment = NULL, *timezone = NULL, _0 = zval_used_for_init, *_2 = NULL, *_3 = NULL, *_4, *_5, *_6;
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
		ZEPHIR_CALL_FUNCTION(&environment, "getenv", &_1, 55, &_0);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(_2);
		if (zephir_is_true(environment)) {
			ZEPHIR_CPY_WRT(_2, environment);
		} else {
			ZEPHIR_INIT_NVAR(_2);
			ZVAL_STRING(_2, "production", 1);
		}
		zephir_array_update_string(&config, SL("env"), &_2, PH_COPY | PH_SEPARATE);
	}
	ZEPHIR_OBS_VAR(timezone);
	if (!(zephir_array_isset_string_fetch(&timezone, config, SS("timezone"), 0 TSRMLS_CC))) {
		ZEPHIR_SINIT_NVAR(_0);
		ZVAL_STRING(&_0, "TZ", 0);
		ZEPHIR_CALL_FUNCTION(&timezone, "getenv", &_1, 55, &_0);
		zephir_check_call_status();
		ZEPHIR_INIT_LNVAR(_2);
		if (zephir_is_true(timezone)) {
			ZEPHIR_CPY_WRT(_2, timezone);
		} else {
			ZEPHIR_INIT_NVAR(_2);
			ZVAL_STRING(_2, "UTC", 1);
		}
		zephir_array_update_string(&config, SL("timezone"), &_2, PH_COPY | PH_SEPARATE);
	}
	ZEPHIR_CALL_FUNCTION(&_3, "php_sapi_name", NULL, 56);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_4);
	ZVAL_BOOL(_4, ZEPHIR_IS_STRING_IDENTICAL(_3, "cli"));
	zephir_array_update_string(&config, SL("cli"), &_4, PH_COPY | PH_SEPARATE);
	ZEPHIR_CALL_PARENT(NULL, phalconry_mvc_env_ce, this_ptr, "__construct", NULL, 0, config);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(NULL, "date_default_timezone_set", NULL, 57, timezone);
	zephir_check_call_status();
	ZEPHIR_OBS_VAR(_5);
	zephir_read_property_this(&_5, this_ptr, SL("paths"), PH_NOISY_CC);
	if (Z_TYPE_P(_5) == IS_NULL) {
		ZEPHIR_INIT_VAR(_6);
		object_init_ex(_6, zephir_get_internal_ce(SS("phalcon\\registry") TSRMLS_CC));
		ZEPHIR_CALL_METHOD(NULL, _6, "__construct", NULL, 0);
		zephir_check_call_status();
		zephir_update_property_this(this_ptr, SL("paths"), _6 TSRMLS_CC);
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Returns the environment name.
 *
 * @return string
 */
PHP_METHOD(Phalconry_Mvc_Env, getEnvironment) {


	RETURN_MEMBER(this_ptr, "env");

}

/**
 * Returns the timezone.
 *
 * @return string
 */
PHP_METHOD(Phalconry_Mvc_Env, getTimezone) {


	RETURN_MEMBER(this_ptr, "timezone");

}

/**
 * Sets the locale.
 *
 * @param string locale
 * @return \Phalconry\Mvc\EnvironmentInterface
 */
PHP_METHOD(Phalconry_Mvc_Env, setLocale) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *locale_param = NULL, *_0, _1;
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


	ZEPHIR_INIT_VAR(_0);
	ZVAL_STRING(_0, "locale", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "offsetset", NULL, 0, _0, locale);
	zephir_check_temp_parameter(_0);
	zephir_check_call_status();
	ZEPHIR_SINIT_VAR(_1);
	ZVAL_LONG(&_1, 0);
	ZEPHIR_CALL_FUNCTION(NULL, "setlocale", NULL, 58, &_1, locale);
	zephir_check_call_status();
	RETURN_THIS();

}

/**
 * Returns the locale name.
 *
 * @return string
 */
PHP_METHOD(Phalconry_Mvc_Env, getLocale) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *_0;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(_0);
	ZVAL_STRING(_0, "locale", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "offsetget", NULL, 0, _0);
	zephir_check_temp_parameter(_0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Sets the directory paths.
 *
 * @param mixed paths Directory paths
 * @return \Phalconry\Mvc\EnvironmentInterface
 */
PHP_METHOD(Phalconry_Mvc_Env, setPaths) {

	zephir_fcall_cache_entry *_3 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	HashTable *_1;
	HashPosition _0;
	zval *paths, *key = NULL, *value = NULL, **_2;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &paths);



	zephir_is_iterable(paths, &_1, &_0, 0, 0, "phalconry/mvc/env.zep", 140);
	for (
	  ; zephir_hash_get_current_data_ex(_1, (void**) &_2, &_0) == SUCCESS
	  ; zephir_hash_move_forward_ex(_1, &_0)
	) {
		ZEPHIR_GET_HMKEY(key, _1, _0);
		ZEPHIR_GET_HVALUE(value, _2);
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "setpath", &_3, 0, key, value);
		zephir_check_call_status();
	}
	RETURN_THIS();

}

/**
 * Returns the directory paths.
 *
 * @return \Phalcon\Registry
 */
PHP_METHOD(Phalconry_Mvc_Env, getPaths) {


	RETURN_MEMBER(this_ptr, "paths");

}

/**
 * Sets a directory path by name.
 *
 * @param string name
 * @param string path
 * @return \Phalconry\Mvc\EnvironmentInterface
 */
PHP_METHOD(Phalconry_Mvc_Env, setPath) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *name_param = NULL, *path_param = NULL, *_0 = NULL, *_1;
	zval *name = NULL, *path = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &name_param, &path_param);

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
	if (unlikely(Z_TYPE_P(path_param) != IS_STRING && Z_TYPE_P(path_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'path' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(path_param) == IS_STRING)) {
		zephir_get_strval(path, path_param);
	} else {
		ZEPHIR_INIT_VAR(path);
		ZVAL_EMPTY_STRING(path);
	}


	ZEPHIR_CALL_FUNCTION(&_0, "realpath", NULL, 59, path);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_1);
	ZEPHIR_CONCAT_VS(_1, _0, "/");
	zephir_update_property_array(this_ptr, SL("paths"), name, _1 TSRMLS_CC);
	RETURN_THIS();

}

/**
 * Returns a directory path by name.
 *
 * @param string name
 * @return string
 */
PHP_METHOD(Phalconry_Mvc_Env, getPath) {

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


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("paths"), PH_NOISY_CC);
	zephir_array_fetch(&_1, _0, name, PH_NOISY | PH_READONLY, "phalconry/mvc/env.zep", 174 TSRMLS_CC);
	RETURN_CTOR(_1);

}

/**
 * Returns a Config object for a given section.
 *
 * @param string section Section name.
 * @return \Phalcon\Config
 *
 * @throws \Phalcon\Exception if section exists but isn't a Config.
 */
PHP_METHOD(Phalconry_Mvc_Env, getConfig) {

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
			object_init_ex(_0, zephir_get_internal_ce(SS("phalcon\\exception") TSRMLS_CC));
			ZEPHIR_INIT_VAR(_1);
			ZEPHIR_CONCAT_SVS(_1, "Config section '", section, "' is not an object");
			ZEPHIR_CALL_METHOD(NULL, _0, "__construct", NULL, 0, _1);
			zephir_check_call_status();
			zephir_throw_exception_debug(_0, "phalconry/mvc/env.zep", 192 TSRMLS_CC);
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
 * Whether currently using command line.
 *
 * @return boolean
 */
PHP_METHOD(Phalconry_Mvc_Env, isCli) {


	RETURN_MEMBER(this_ptr, "cli");

}

/**
 * Allow read-only access to protected properties.
 *
 * @param string key
 * @return mixed
 */
PHP_METHOD(Phalconry_Mvc_Env, __get) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *key = NULL, *_0 = NULL, *_1;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &key);

	ZEPHIR_SEPARATE_PARAM(key);


	ZEPHIR_CALL_FUNCTION(&_0, "strval", NULL, 2, key);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(key, _0);
	if (zephir_isset_property_zval(this_ptr, key TSRMLS_CC)) {
		ZEPHIR_OBS_VAR(_1);
		zephir_read_property_zval(&_1, this_ptr, key, PH_NOISY_CC);
		RETURN_CCTOR(_1);
	}
	RETURN_MM_NULL();

}

/**
 * Allow read-only access to protected properties.
 *
 * @param string key
 * @return boolean
 */
PHP_METHOD(Phalconry_Mvc_Env, __isset) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *key = NULL, *_0 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &key);

	ZEPHIR_SEPARATE_PARAM(key);


	ZEPHIR_CALL_FUNCTION(&_0, "strval", NULL, 2, key);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(key, _0);
	RETURN_MM_BOOL(zephir_isset_property_zval(this_ptr, key TSRMLS_CC));

}

/**
 * Magic call
 */
PHP_METHOD(Phalconry_Mvc_Env, __call) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *args = NULL;
	zval *func_param = NULL, *args_param = NULL, _0 = zval_used_for_init, _1, *_2 = NULL, *_3 = NULL;
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
		ZEPHIR_INIT_VAR(_2);
		zephir_substr(_2, func, 0 , zephir_get_intval(&_1), 0);
		ZEPHIR_RETURN_CALL_METHOD(this_ptr, "getpath", NULL, 0, _2);
		zephir_check_call_status();
		RETURN_MM();
	}
	if (zephir_start_with_str(func, SL("get"))) {
		ZEPHIR_SINIT_NVAR(_0);
		ZVAL_LONG(&_0, 3);
		ZEPHIR_INIT_NVAR(_2);
		zephir_substr(_2, func, 3 , 0, ZEPHIR_SUBSTR_NO_LENGTH);
		ZEPHIR_CALL_FUNCTION(&_3, "lcfirst", NULL, 60, _2);
		zephir_check_call_status();
		ZEPHIR_RETURN_CALL_METHOD(this_ptr, "offsetget", NULL, 0, _3);
		zephir_check_call_status();
		RETURN_MM();
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Returns the environment name.
 *
 * @return string
 */
PHP_METHOD(Phalconry_Mvc_Env, __toString) {


	RETURN_MEMBER(this_ptr, "env");

}

