
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
#include "kernel/fcall.h"
#include "kernel/memory.h"
#include "kernel/operators.h"
#include "kernel/string.h"
#include "kernel/concat.h"
#include "kernel/object.h"
#include "kernel/require.h"
#include "kernel/exception.h"
#include "ext/spl/spl_exceptions.h"


/**
 * Factory creates web services from definitions
 */
ZEPHIR_INIT_CLASS(Phalconry_WebService_Factory) {

	ZEPHIR_REGISTER_CLASS_EX(Phalconry\\WebService, Factory, phalconry, webservice_factory, zephir_get_internal_ce(SS("phalcon\\di\\injectable") TSRMLS_CC), phalconry_webservice_factory_method_entry, 0);

	return SUCCESS;

}

/**
 * Create a web service from a definition
 *
 * @param mixed $definition Callable, classname, or file
 * @return \Phalconry\WebService\ServiceInterface
 * @throws \Phalconry\WebService\Exception if service cannot be created
 * @throws \UnexpectedValueException if the definition does not resolve to an instance of ServiceInterface
 */
PHP_METHOD(Phalconry_WebService_Factory, create) {

	zend_class_entry *_5;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *diKey = NULL;
	zval *definition, *dependencyInjector = NULL, *service = NULL, *_0 = NULL, *_1, *_2 = NULL, *_3 = NULL, *_4 = NULL, *_6 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &definition);



	ZEPHIR_CALL_METHOD(&dependencyInjector, this_ptr, "getdi", NULL, 0);
	zephir_check_call_status();
	if (Z_TYPE_P(definition) == IS_STRING) {
		ZEPHIR_CALL_METHOD(&_0, dependencyInjector, "has", NULL, 0, definition);
		zephir_check_call_status();
		if (zephir_is_true(_0)) {
			ZEPHIR_RETURN_CALL_METHOD(dependencyInjector, "get", NULL, 0, definition);
			zephir_check_call_status();
			RETURN_MM();
		}
		ZEPHIR_INIT_VAR(diKey);
		ZEPHIR_INIT_VAR(_1);
		ZEPHIR_CONCAT_VS(_1, definition, "_webService");
		zephir_camelize(diKey, _1);
		ZEPHIR_CALL_METHOD(&_2, dependencyInjector, "has", NULL, 0, diKey);
		zephir_check_call_status();
		if (zephir_is_true(_2)) {
			ZEPHIR_RETURN_CALL_METHOD(dependencyInjector, "get", NULL, 0, diKey);
			zephir_check_call_status();
			RETURN_MM();
		}
		ZEPHIR_CALL_FUNCTION(&_3, "is_file", NULL, 79, definition);
		zephir_check_call_status();
		if (zephir_class_exists(definition, 1 TSRMLS_CC)) {
			ZEPHIR_INIT_VAR(service);
			zephir_fetch_safe_class(_4, definition);
			_5 = zend_fetch_class(Z_STRVAL_P(_4), Z_STRLEN_P(_4), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);
			object_init_ex(service, _5);
			if (zephir_has_constructor(service TSRMLS_CC)) {
				ZEPHIR_CALL_METHOD(NULL, service, "__construct", NULL, 0);
				zephir_check_call_status();
			}
		} else if (zephir_is_true(_3)) {
			ZEPHIR_OBSERVE_OR_NULLIFY_PPZV(&_6);
			if (zephir_require_zval_ret(&_6, definition TSRMLS_CC) == FAILURE) {
				RETURN_MM_NULL();
			}
			ZEPHIR_CPY_WRT(service, _6);
		}
	} else if (zephir_is_callable(definition TSRMLS_CC)) {
		ZEPHIR_INIT_NVAR(service);
		ZEPHIR_CALL_USER_FUNC(service, definition);
		zephir_check_call_status();
	}
	if (Z_TYPE_P(service) == IS_NULL) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalconry_webservice_exception_ce, "Web service could not be created from definition", "phalconry/webservice/factory.zep", 50);
		return;
	}
	if (zephir_instance_of_ev(service, phalconry_webservice_serviceinterface_ce TSRMLS_CC)) {
		ZEPHIR_CALL_METHOD(NULL, service, "setdi", NULL, 0, dependencyInjector);
		zephir_check_call_status();
		RETURN_CCTOR(service);
	}
	ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_UnexpectedValueException, "Expecting ServiceInterface", "phalconry/webservice/factory.zep", 58);
	return;

}

