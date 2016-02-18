
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
#include "ext/spl/spl_iterators.h"
#include "kernel/object.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"
#include "kernel/operators.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/array.h"


/**
 * Manager manages web services
 */
ZEPHIR_INIT_CLASS(Phalconry_WebService_Manager) {

	ZEPHIR_REGISTER_CLASS_EX(Phalconry\\WebService, Manager, phalconry, webservice_manager, zephir_get_internal_ce(SS("phalcon\\di\\injectable") TSRMLS_CC), phalconry_webservice_manager_method_entry, 0);

	/**
	 * @var \Phalconry\WebService\Factory
	 */
	zend_declare_property_null(phalconry_webservice_manager_ce, SL("_factory"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * @var array
	 */
	zend_declare_property_null(phalconry_webservice_manager_ce, SL("_definitions"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * @var array
	 */
	zend_declare_property_null(phalconry_webservice_manager_ce, SL("_services"), ZEND_ACC_PROTECTED TSRMLS_CC);

	phalconry_webservice_manager_ce->create_object = zephir_init_properties_Phalconry_WebService_Manager;

	zend_class_implements(phalconry_webservice_manager_ce TSRMLS_CC, 1, spl_ce_Countable);
	return SUCCESS;

}

/**
 * Sets a web service
 *
 * @param string name Web service name
 * @param \Phalconry\WebService\ServiceInterface service
 */
PHP_METHOD(Phalconry_WebService_Manager, set) {

	zval *name_param = NULL, *service;
	zval *name = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &name_param, &service);

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


	zephir_update_property_array(this_ptr, SL("_services"), name, service TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

/**
 * Whether the given service exists
 *
 * @param string|\Phalconry\WebService\ServiceInterface
 * @return boolean
 */
PHP_METHOD(Phalconry_WebService_Manager, has) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *service, *_0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &service);



	if (Z_TYPE_P(service) == IS_OBJECT) {
		_0 = zephir_fetch_nproperty_this(this_ptr, SL("_services"), PH_NOISY_CC);
		ZEPHIR_RETURN_CALL_FUNCTION("in_array", NULL, 61, service, _0, ZEPHIR_GLOBAL(global_true));
		zephir_check_call_status();
		RETURN_MM();
	}
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_services"), PH_NOISY_CC);
	RETURN_MM_BOOL(zephir_array_isset(_0, service));

}

/**
 * Returns a web service by name
 *
 * @param string name Web service name
 * @return \Phalconry\WebService\ServiceInterface
 * @throws \Phalconry\WebService\Exception
 */
PHP_METHOD(Phalconry_WebService_Manager, get) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *name_param = NULL, *_0, *_1, *_2 = NULL, *_3 = NULL, *_4, *_5;
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


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_services"), PH_NOISY_CC);
	if (!(zephir_array_isset(_0, name))) {
		_1 = zephir_fetch_nproperty_this(this_ptr, SL("_definitions"), PH_NOISY_CC);
		if (!(zephir_array_isset(_1, name))) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalconry_webservice_exception_ce, "Service not available", "phalconry/webservice/manager.zep", 65);
			return;
		}
		ZEPHIR_CALL_METHOD(&_2, this_ptr, "getfactory", NULL, 0);
		zephir_check_call_status();
		_4 = zephir_fetch_nproperty_this(this_ptr, SL("_definitions"), PH_NOISY_CC);
		zephir_array_fetch(&_5, _4, name, PH_NOISY | PH_READONLY, "phalconry/webservice/manager.zep", 68 TSRMLS_CC);
		ZEPHIR_CALL_METHOD(&_3, _2, "create", NULL, 0, _5);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "set", NULL, 0, name, _3);
		zephir_check_call_status();
	}
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("_services"), PH_NOISY_CC);
	zephir_array_fetch(&_5, _1, name, PH_NOISY | PH_READONLY, "phalconry/webservice/manager.zep", 71 TSRMLS_CC);
	RETURN_CTOR(_5);

}

/**
 * Sets a web service definition
 *
 * @param string name Web service name
 * @param string|callable Web service classname, or a callback that returns the object
 * @throws \InvalidArgumentException if definition is not string or callable
 */
PHP_METHOD(Phalconry_WebService_Manager, setDefinition) {

	zend_bool _0;
	zval *name_param = NULL, *definition;
	zval *name = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &name_param, &definition);

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


	_0 = Z_TYPE_P(definition) != IS_STRING;
	if (_0) {
		_0 = !(zephir_is_callable(definition TSRMLS_CC));
	}
	if (_0) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "Service definition must be string or callable", "phalconry/webservice/manager.zep", 84);
		return;
	}
	zephir_update_property_array(this_ptr, SL("_definitions"), name, definition TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

/**
 * Whether a definition for the given web service exists
 *
 * @param string name Web service name
 * @return boolean
 */
PHP_METHOD(Phalconry_WebService_Manager, hasDefinition) {

	zval *name_param = NULL, *_0;
	zval *name = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name_param);

	zephir_get_strval(name, name_param);


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_definitions"), PH_NOISY_CC);
	RETURN_MM_BOOL(zephir_array_isset(_0, name));

}

/**
 * Returns a web service definition
 *
 * @param string name
 * @return string|callable|null
 */
PHP_METHOD(Phalconry_WebService_Manager, getDefinition) {

	zval *name_param = NULL, *_0, *_1, *_2;
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


	ZEPHIR_INIT_VAR(_0);
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("_definitions"), PH_NOISY_CC);
	if (zephir_array_isset(_1, name)) {
		_2 = zephir_fetch_nproperty_this(this_ptr, SL("_definitions"), PH_NOISY_CC);
		zephir_array_fetch(&_0, _2, name, PH_NOISY, "phalconry/webservice/manager.zep", 109 TSRMLS_CC);
	} else {
		ZVAL_NULL(_0);
	}
	RETURN_CCTOR(_0);

}

/**
 * Whether a given web service is available
 *
 * @param string service Web service name
 * @return boolean
 */
PHP_METHOD(Phalconry_WebService_Manager, isAvailable) {

	zend_bool _1;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *service_param = NULL, *_0 = NULL, *_2 = NULL;
	zval *service = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &service_param);

	if (unlikely(Z_TYPE_P(service_param) != IS_STRING && Z_TYPE_P(service_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'service' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(service_param) == IS_STRING)) {
		zephir_get_strval(service, service_param);
	} else {
		ZEPHIR_INIT_VAR(service);
		ZVAL_EMPTY_STRING(service);
	}


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "hasdefinition", NULL, 0, service);
	zephir_check_call_status();
	_1 = zephir_is_true(_0);
	if (!(_1)) {
		ZEPHIR_CALL_METHOD(&_2, this_ptr, "has", NULL, 0, service);
		zephir_check_call_status();
		_1 = zephir_is_true(_2);
	}
	RETURN_MM_BOOL(_1);

}

/**
 * Sets the web service factory
 *
 * @param \Phalconry\WebService\Factory factory
 */
PHP_METHOD(Phalconry_WebService_Manager, setFactory) {

	zval *factory;

	zephir_fetch_params(0, 1, 0, &factory);



	zephir_update_property_this(this_ptr, SL("_factory"), factory TSRMLS_CC);

}

/**
 * Returns the web service factory, creating if not set
 *
 * @return \Phalconry\WebService\Factory
 */
PHP_METHOD(Phalconry_WebService_Manager, getFactory) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *_0 = NULL, *_1, *_2 = NULL, *_3;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(_0);
	ZEPHIR_OBS_VAR(_1);
	zephir_read_property_this(&_1, this_ptr, SL("_factory"), PH_NOISY_CC);
	if (Z_TYPE_P(_1) == IS_OBJECT) {
		zephir_read_property_this(&_0, this_ptr, SL("_factory"), PH_NOISY_CC);
	} else {
		ZEPHIR_CALL_METHOD(&_2, this_ptr, "getdi", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(_3);
		ZVAL_STRING(_3, "webServiceFactory", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&_0, _2, "getshared", NULL, 0, _3);
		zephir_check_temp_parameter(_3);
		zephir_check_call_status();
	}
	RETURN_CCTOR(_0);

}

/**
 * Returns the number of registered web services
 *
 * @return int
 */
PHP_METHOD(Phalconry_WebService_Manager, count) {

	zval *_0;


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_services"), PH_NOISY_CC);
	RETURN_LONG(zephir_fast_count_int(_0 TSRMLS_CC));

}

static zend_object_value zephir_init_properties_Phalconry_WebService_Manager(zend_class_entry *class_type TSRMLS_DC) {

		zval *_0, *_1 = NULL, *_2;

		ZEPHIR_MM_GROW();
	
	{
		zval *this_ptr = NULL;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		_0 = zephir_fetch_nproperty_this(this_ptr, SL("_services"), PH_NOISY_CC);
		if (Z_TYPE_P(_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(_1);
			array_init(_1);
			zephir_update_property_this(this_ptr, SL("_services"), _1 TSRMLS_CC);
		}
		_2 = zephir_fetch_nproperty_this(this_ptr, SL("_definitions"), PH_NOISY_CC);
		if (Z_TYPE_P(_2) == IS_NULL) {
			ZEPHIR_INIT_NVAR(_1);
			array_init(_1);
			zephir_update_property_this(this_ptr, SL("_definitions"), _1 TSRMLS_CC);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJVAL_P(this_ptr);
	}

}

