
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
#include "ext/spl/spl_array.h"
#include "kernel/fcall.h"
#include "kernel/memory.h"
#include "kernel/operators.h"
#include "kernel/concat.h"
#include "kernel/object.h"
#include "kernel/array.h"
#include "kernel/exception.h"


ZEPHIR_INIT_CLASS(Phalconry_ArrayObject) {

	ZEPHIR_REGISTER_CLASS_EX(Phalconry, ArrayObject, phalconry, arrayobject, spl_ce_ArrayObject, phalconry_arrayobject_method_entry, 0);

	zend_class_implements(phalconry_arrayobject_ce TSRMLS_CC, 1, zephir_get_internal_ce(SS("jsonserializable") TSRMLS_CC));
	return SUCCESS;

}

PHP_METHOD(Phalconry_ArrayObject, __construct) {

	zval *iterator_class = NULL;
	int flags, ZEPHIR_LAST_CALL_STATUS;
	zval *input = NULL, *flags_param = NULL, *iterator_class_param = NULL, *_0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 3, &input, &flags_param, &iterator_class_param);

	if (!input) {
		ZEPHIR_INIT_VAR(input);
		array_init(input);
	}
	if (!flags_param) {
		flags = 2;
	} else {
		flags = zephir_get_intval(flags_param);
	}
	if (!iterator_class_param) {
		ZEPHIR_INIT_VAR(iterator_class);
		ZVAL_STRING(iterator_class, "ArrayIterator", 1);
	} else {
		zephir_get_strval(iterator_class, iterator_class_param);
	}


	ZEPHIR_INIT_VAR(_0);
	ZVAL_LONG(_0, flags);
	ZEPHIR_CALL_PARENT(NULL, phalconry_arrayobject_ce, this_ptr, "__construct", NULL, input, _0, iterator_class);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Phalconry_ArrayObject, __call) {

	zval *_2;
	int ZEPHIR_LAST_CALL_STATUS;
	zend_class_entry *phalcon_phalcon_text;
	zval *func_param = NULL, *args, *_0 = NULL, *_1, *fnArgs, *_3 = NULL, *_4;
	zval *func = NULL, *arrayFunc = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &func_param, &args);

	zephir_get_strval(func, func_param);


	phalcon_phalcon_text = zend_fetch_class(SL("\\Phalcon\\Text"), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);
	ZEPHIR_CALL_CE_STATIC(&_0, phalcon_phalcon_text, "uncamelize", NULL, func);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_1);
	ZEPHIR_CONCAT_SV(_1, "array_", _0);
	zephir_get_strval(arrayFunc, _1);
	if ((zephir_function_exists(arrayFunc TSRMLS_CC)  == SUCCESS)) {
		ZEPHIR_INIT_VAR(fnArgs);
		ZEPHIR_INIT_VAR(_2);
		array_init_size(_2, 2);
		ZEPHIR_CALL_METHOD(&_3, this_ptr, "getarraycopy", NULL);
		zephir_check_call_status();
		zephir_array_fast_append(_2, _3);
		zephir_fast_array_merge(fnArgs, &(_2), &(args) TSRMLS_CC);
		ZEPHIR_CALL_USER_FUNC_ARRAY(return_value, arrayFunc, fnArgs);
		zephir_check_call_status();
		RETURN_MM();
	} else {
		ZEPHIR_INIT_VAR(_4);
		object_init_ex(_4, spl_ce_BadMethodCallException);
		ZEPHIR_CALL_METHOD(NULL, _4, "__construct", NULL);
		zephir_check_call_status();
		zephir_throw_exception_debug(_4, "phalconry/arrayobject.zep", 25 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}

}

PHP_METHOD(Phalconry_ArrayObject, jsonSerialize) {

	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "getarraycopy", NULL);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Phalconry_ArrayObject, toArray) {

	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "getarraycopy", NULL);
	zephir_check_call_status();
	RETURN_MM();

}

