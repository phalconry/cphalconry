
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
#include "kernel/operators.h"
#include "kernel/memory.h"
#include "kernel/string.h"


ZEPHIR_INIT_CLASS(Phalconry_Util) {

	ZEPHIR_REGISTER_CLASS(Phalconry, Util, phalconry, util, phalconry_util_method_entry, 0);

	return SUCCESS;

}

PHP_METHOD(Phalconry_Util, toArray) {

	zval *_1 = NULL;
	zephir_nts_static zephir_fcall_cache_entry *_0 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *arg;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &arg);



	if (Z_TYPE_P(arg) == IS_ARRAY) {
		RETVAL_ZVAL(arg, 1, 0);
		RETURN_MM();
	}
	if (Z_TYPE_P(arg) == IS_OBJECT) {
		if ((zephir_method_exists_ex(arg, SS("toarray") TSRMLS_CC) == SUCCESS)) {
			ZEPHIR_RETURN_CALL_METHOD(arg, "toarray", NULL);
			zephir_check_call_status();
			RETURN_MM();
		}
		if (zephir_is_instance_of(arg, SL("Traversable") TSRMLS_CC)) {
			ZEPHIR_RETURN_CALL_FUNCTION("iterator_to_array", NULL, arg);
			zephir_check_call_status();
			RETURN_MM();
		}
		ZEPHIR_RETURN_CALL_FUNCTION("get_object_vars", &_0, arg);
		zephir_check_call_status();
		RETURN_MM();
	}
	zephir_get_arrval(_1, arg);
	RETURN_CTOR(_1);

}

PHP_METHOD(Phalconry_Util, toObject) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *arg, *objVars = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &arg);



	if (Z_TYPE_P(arg) == IS_OBJECT) {
		if (zephir_instance_of_ev(arg, zend_standard_class_def TSRMLS_CC)) {
			RETVAL_ZVAL(arg, 1, 0);
			RETURN_MM();
		}
		ZEPHIR_CALL_SELF(&objVars, "toarray", NULL, arg);
		zephir_check_call_status();
		zephir_convert_to_object(objVars);
		RETURN_CCTOR(objVars);
	}
	zephir_convert_to_object(arg);
	RETVAL_ZVAL(arg, 1, 0);
	RETURN_MM();

}

PHP_METHOD(Phalconry_Util, isJson) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *arg, *jsonData, *_0 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &arg);



	if (Z_TYPE_P(arg) == IS_STRING) {
		ZEPHIR_INIT_VAR(jsonData);
		zephir_json_decode(jsonData, &(jsonData), arg, zephir_get_intval(ZEPHIR_GLOBAL(global_true))  TSRMLS_CC);
		ZEPHIR_CALL_FUNCTION(&_0, "json_last_error", NULL);
		zephir_check_call_status();
		if (ZEPHIR_IS_LONG_IDENTICAL(_0, 0)) {
			RETURN_MM_BOOL(Z_TYPE_P(jsonData) == IS_ARRAY);
		}
	}
	RETURN_MM_BOOL(0);

}

