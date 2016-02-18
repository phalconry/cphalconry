
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
#include "kernel/operators.h"
#include "kernel/memory.h"


ZEPHIR_INIT_CLASS(Phalconry_Bundle_Exception_DependencyException) {

	ZEPHIR_REGISTER_CLASS_EX(Phalconry\\Bundle\\Exception, DependencyException, phalconry, bundle_exception_dependencyexception, phalconry_bundle_exception_ce, phalconry_bundle_exception_dependencyexception_method_entry, 0);

	zend_declare_property_null(phalconry_bundle_exception_dependencyexception_ce, SL("missing"), ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

PHP_METHOD(Phalconry_Bundle_Exception_DependencyException, setMissing) {

	zval *missing_param = NULL;
	zval *missing = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &missing_param);

	zephir_get_arrval(missing, missing_param);


	zephir_update_property_this(this_ptr, SL("missing"), missing TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Phalconry_Bundle_Exception_DependencyException, getMissing) {

	zval *_0, *_1;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(_0);
	ZEPHIR_OBS_VAR(_1);
	zephir_read_property_this(&_1, this_ptr, SL("missing"), PH_NOISY_CC);
	if (Z_TYPE_P(_1) == IS_ARRAY) {
		zephir_read_property_this(&_0, this_ptr, SL("missing"), PH_NOISY_CC);
	} else {
		array_init(_0);
	}
	RETURN_CCTOR(_0);

}

