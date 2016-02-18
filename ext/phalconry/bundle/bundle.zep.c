
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
#include "kernel/exception.h"
#include "kernel/memory.h"
#include "kernel/concat.h"
#include "kernel/fcall.h"


ZEPHIR_INIT_CLASS(Phalconry_Bundle_Bundle) {

	ZEPHIR_REGISTER_CLASS(Phalconry\\Bundle, Bundle, phalconry, bundle_bundle, phalconry_bundle_bundle_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	zend_declare_property_null(phalconry_bundle_bundle_ce, SL("_dependencyInjector"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_class_implements(phalconry_bundle_bundle_ce TSRMLS_CC, 1, phalconry_bundle_bundleinterface_ce);
	return SUCCESS;

}

/**
 * Sets the dependency injector
 */
PHP_METHOD(Phalconry_Bundle_Bundle, setDI) {

	zval *dependencyInjector;

	zephir_fetch_params(0, 1, 0, &dependencyInjector);



	if (!(zephir_is_instance_of(dependencyInjector, SL("Phalcon\\DiInterface") TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STRW(spl_ce_InvalidArgumentException, "Parameter 'dependencyInjector' must be an instance of 'Phalcon\\DiInterface'", "", 0);
		return;
	}
	zephir_update_property_this(this_ptr, SL("_dependencyInjector"), dependencyInjector TSRMLS_CC);

}

/**
 * Returns the internal dependency injector
 */
PHP_METHOD(Phalconry_Bundle_Bundle, getDI) {


	RETURN_MEMBER(this_ptr, "_dependencyInjector");

}

PHP_METHOD(Phalconry_Bundle_Bundle, getOverrides) {


	array_init(return_value);
	return;

}

PHP_METHOD(Phalconry_Bundle_Bundle, getDependencies) {


	array_init(return_value);
	return;

}

PHP_METHOD(Phalconry_Bundle_Bundle, getIdentifier) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *_0 = NULL, *_1 = NULL;

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getbundletype", NULL);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "getname", NULL);
	zephir_check_call_status();
	ZEPHIR_CONCAT_VSV(return_value, _0, ".", _1);
	RETURN_MM();

}

