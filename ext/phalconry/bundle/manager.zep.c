
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
#include "kernel/fcall.h"
#include "kernel/memory.h"
#include "kernel/string.h"
#include "kernel/operators.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/hash.h"
#include "kernel/array.h"
#include "kernel/concat.h"

ZEPHIR_INIT_CLASS(Phalconry_Bundle_Manager) {

	ZEPHIR_REGISTER_CLASS_EX(Phalconry\\Bundle, Manager, phalconry, bundle_manager, zephir_get_internal_ce(SS("phalcon\\di\\injectable") TSRMLS_CC), phalconry_bundle_manager_method_entry, 0);

	/**
	 * Bundles of joy.
	 * @var array
	 */
	zend_declare_property_null(phalconry_bundle_manager_ce, SL("_bundles"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * Callbacks or ProviderInterfaces that provide bundles.
	 * @var array
	 */
	zend_declare_property_null(phalconry_bundle_manager_ce, SL("_providers"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * Callbacks or ProviderInterfaces that provide a type of bundle.
	 * @var array
	 */
	zend_declare_property_null(phalconry_bundle_manager_ce, SL("_typeProviders"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * Bundles currently being booted.
	 * @var array
	 */
	zend_declare_property_null(phalconry_bundle_manager_ce, SL("_buildStack"), ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

/**
 * Sets an object that provides a bundle upon request.
 *
 * @param \Phalconry\Bundle\ProviderInterface provider
 * @return void
 */
PHP_METHOD(Phalconry_Bundle_Manager, provide) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *provider, *provides = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &provider);



	if (!(zephir_instance_of_ev(provider, phalconry_bundle_providerinterface_ce TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "Parameter 'provider' must be an instance of 'Phalconry\\Bundle\\ProviderInterface'", "", 0);
		return;
	}
	ZEPHIR_CALL_METHOD(&provides, provider, "provides", NULL);
	zephir_check_call_status();
	if (zephir_is_instance_of(provider, SL("Phalconry\\Bundle\\TypeProviderInterface") TSRMLS_CC)) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "providetype", NULL, provides, provider);
		zephir_check_call_status();
	} else if (Z_TYPE_P(provides) == IS_ARRAY) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "providemultiple", NULL, provides, provider);
		zephir_check_call_status();
	} else {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "providebundle", NULL, provides, provider);
		zephir_check_call_status();
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Sets an object or callback that provides bundles of a specific type.
 *
 * @param string bundle_type Type of bundle.
 * @param \Phalconry\Bundle\ProviderInterface|callable provider
 * @return void
 */
PHP_METHOD(Phalconry_Bundle_Manager, provideType) {

	zval *bundleType_param = NULL, *provider, *_0;
	zval *bundleType = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &bundleType_param, &provider);

	if (unlikely(Z_TYPE_P(bundleType_param) != IS_STRING && Z_TYPE_P(bundleType_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'bundleType' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(bundleType_param) == IS_STRING)) {
		zephir_get_strval(bundleType, bundleType_param);
	} else {
		ZEPHIR_INIT_VAR(bundleType);
		ZVAL_EMPTY_STRING(bundleType);
	}


	if (!(zephir_instance_of_ev(provider, phalconry_bundle_providerinterface_ce TSRMLS_CC))) {
		if (!(zephir_is_callable(provider TSRMLS_CC))) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalconry_bundle_exception_ce, "Invalid bundle provider", "phalconry/bundle/manager.zep", 67);
			return;
		}
	}
	ZEPHIR_INIT_VAR(_0);
	zephir_fast_strtolower(_0, bundleType);
	zephir_get_strval(bundleType, _0);
	zephir_update_property_array(this_ptr, SL("_typeProviders"), bundleType, provider TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

/**
 * Sets an object or callback that provides a bundle upon request.
 *
 * @param string bundle_name
 * @param \Phalconry\Bundle\ProviderInterface|callable provider
 * @return void
 */
PHP_METHOD(Phalconry_Bundle_Manager, provideBundle) {

	zval *bundleName_param = NULL, *provider, *_0;
	zval *bundleName = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &bundleName_param, &provider);

	if (unlikely(Z_TYPE_P(bundleName_param) != IS_STRING && Z_TYPE_P(bundleName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'bundleName' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(bundleName_param) == IS_STRING)) {
		zephir_get_strval(bundleName, bundleName_param);
	} else {
		ZEPHIR_INIT_VAR(bundleName);
		ZVAL_EMPTY_STRING(bundleName);
	}


	if (!(zephir_instance_of_ev(provider, phalconry_bundle_providerinterface_ce TSRMLS_CC))) {
		if (!(zephir_is_callable(provider TSRMLS_CC))) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalconry_bundle_exception_ce, "Invalid bundle provider", "phalconry/bundle/manager.zep", 87);
			return;
		}
	}
	ZEPHIR_INIT_VAR(_0);
	zephir_fast_strtolower(_0, bundleName);
	zephir_get_strval(bundleName, _0);
	zephir_update_property_array(this_ptr, SL("_providers"), bundleName, provider TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

/**
 * Sets an object or callback that provides multiple bundles.
 *
 * @param array bundles Array of bundle names.
 * @param \Phalconry\Bundle\ProviderInterface|callable provider
 * @return void
 */
PHP_METHOD(Phalconry_Bundle_Manager, provideMultiple) {

	zephir_fcall_cache_entry *_3 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	HashTable *_1;
	HashPosition _0;
	zval *bundles_param = NULL, *provider, *bundle = NULL, **_2;
	zval *bundles = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &bundles_param, &provider);

	bundles = bundles_param;



	zephir_is_iterable(bundles, &_1, &_0, 0, 0, "phalconry/bundle/manager.zep", 109);
	for (
	  ; zephir_hash_get_current_data_ex(_1, (void**) &_2, &_0) == SUCCESS
	  ; zephir_hash_move_forward_ex(_1, &_0)
	) {
		ZEPHIR_GET_HVALUE(bundle, _2);
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "providebundle", &_3, bundle, provider);
		zephir_check_call_status();
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Sets a bundle.
 *
 * Overwrite this function to, for example, create DI-aware bundles.
 *
 * @param \Phalconry\Bundle\BundleInterface bundle
 * @return void
 */
PHP_METHOD(Phalconry_Bundle_Manager, setBundle) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *bundle, *_0, *_1 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &bundle);



	if (!(zephir_instance_of_ev(bundle, phalconry_bundle_bundleinterface_ce TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "Parameter 'bundle' must be an instance of 'Phalconry\\Bundle\\BundleInterface'", "", 0);
		return;
	}
	ZEPHIR_INIT_VAR(_0);
	ZEPHIR_CALL_METHOD(&_1, bundle, "getidentifier", NULL);
	zephir_check_call_status();
	zephir_fast_strtolower(_0, _1);
	zephir_update_property_array(this_ptr, SL("_bundles"), _0, bundle TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

/**
 * Returns a bundle by name, booting from provider if necessary.
 *
 * @param string name Bundle name.
 * @return \Phalconry\Bundle\BundleInterface Bundle or null on failure.
 */
PHP_METHOD(Phalconry_Bundle_Manager, getBundle) {

	zend_bool _4;
	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_2 = NULL;
	zval *name = NULL, *_0, *_1 = NULL, *_3, *_5, *_6;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name);

	ZEPHIR_SEPARATE_PARAM(name);


	if (zephir_instance_of_ev(name, phalconry_bundle_bundleinterface_ce TSRMLS_CC)) {
		_0 = zephir_fetch_nproperty_this(this_ptr, SL("_bundles"), PH_NOISY_CC);
		ZEPHIR_CALL_FUNCTION(&_1, "in_array", &_2, name, _0, ZEPHIR_GLOBAL(global_true));
		zephir_check_call_status();
		if (!(zephir_is_true(_1))) {
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "setbundle", NULL, name);
			zephir_check_call_status();
		}
		RETVAL_ZVAL(name, 1, 0);
		RETURN_MM();
	}
	ZEPHIR_INIT_VAR(_3);
	zephir_fast_strtolower(_3, name);
	ZEPHIR_CPY_WRT(name, _3);
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_bundles"), PH_NOISY_CC);
	_4 = zephir_array_isset(_0, name);
	if (!(_4)) {
		ZEPHIR_CALL_METHOD(&_1, this_ptr, "setbundlefromprovider", NULL, name);
		zephir_check_call_status();
		_4 = zephir_is_true(_1);
	}
	if (_4) {
		_5 = zephir_fetch_nproperty_this(this_ptr, SL("_bundles"), PH_NOISY_CC);
		zephir_array_fetch(&_6, _5, name, PH_NOISY | PH_READONLY, "phalconry/bundle/manager.zep", 145 TSRMLS_CC);
		RETURN_CTOR(_6);
	}
	RETURN_MM_NULL();

}

/**
 * Returns a bundle, booting first if not done so already.
 *
 * @param string name Bundle name.
 * @return \Phalconry\Bundle\BundleInterface
 */
PHP_METHOD(Phalconry_Bundle_Manager, getBootedBundle) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *name_param = NULL, *bundle = NULL, *_0 = NULL;
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


	ZEPHIR_CALL_METHOD(&bundle, this_ptr, "getbundle", NULL, name);
	zephir_check_call_status();
	if (zephir_is_true(bundle)) {
		ZEPHIR_CALL_METHOD(&_0, bundle, "isbooted", NULL);
		zephir_check_call_status();
		if (!(zephir_is_true(_0))) {
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "boot", NULL, bundle);
			zephir_check_call_status();
		}
		RETURN_CCTOR(bundle);
	}
	RETURN_MM_NULL();

}

/**
 * Checks whether a bundle exists.
 *
 * A bundle exists when it:
 * (a) has been retrieved (and/or possibly booted), or
 * (b) has a provider registered (for it exclusively, or for its type)
 *
 * @param string name Bundle name.
 * @return boolean True if bundle exists, otherwise false.
 */
PHP_METHOD(Phalconry_Bundle_Manager, exists) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_8 = NULL;
	zend_bool _2;
	zval *name_param = NULL, *_0, *_1, *_3, *_4, *_5, _6, *_7 = NULL;
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
	zephir_fast_strtolower(_0, name);
	zephir_get_strval(name, _0);
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("_bundles"), PH_NOISY_CC);
	_2 = zephir_array_isset(_1, name);
	if (!(_2)) {
		_3 = zephir_fetch_nproperty_this(this_ptr, SL("_providers"), PH_NOISY_CC);
		_2 = zephir_array_isset(_3, name);
	}
	if (_2) {
		RETURN_MM_BOOL(1);
	}
	_4 = zephir_fetch_nproperty_this(this_ptr, SL("_typeProviders"), PH_NOISY_CC);
	if (!(ZEPHIR_IS_EMPTY(_4))) {
		_5 = zephir_fetch_nproperty_this(this_ptr, SL("_typeProviders"), PH_NOISY_CC);
		ZEPHIR_SINIT_VAR(_6);
		ZVAL_STRING(&_6, ".", 0);
		ZEPHIR_CALL_FUNCTION(&_7, "strstr", &_8, name, &_6, ZEPHIR_GLOBAL(global_true));
		zephir_check_call_status();
		RETURN_MM_BOOL(zephir_array_isset(_5, _7));
	}
	RETURN_MM_BOOL(0);

}

/**
 * Checks whether a given bundle exists and has been booted.
 *
 * @param string name Bundle name.
 * @return boolean True if exists and booted, otherwise false.
 */
PHP_METHOD(Phalconry_Bundle_Manager, isBooted) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *name_param = NULL, *_0, *_1 = NULL, *_2, *_3, *_4;
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
	zephir_fast_strtolower(_0, name);
	zephir_get_strval(name, _0);
	ZEPHIR_INIT_VAR(_1);
	_2 = zephir_fetch_nproperty_this(this_ptr, SL("_bundles"), PH_NOISY_CC);
	if (zephir_array_isset(_2, name)) {
		_3 = zephir_fetch_nproperty_this(this_ptr, SL("_bundles"), PH_NOISY_CC);
		zephir_array_fetch(&_4, _3, name, PH_NOISY | PH_READONLY, "phalconry/bundle/manager.zep", 210 TSRMLS_CC);
		ZEPHIR_CALL_METHOD(&_1, _4, "isbooted", NULL);
		zephir_check_call_status();
	} else {
		ZVAL_BOOL(_1, 0);
	}
	RETURN_CCTOR(_1);

}

/**
 * Boots a bundle.
 *
 * @param string name Bundle name.
 * @return boolean True if booted, otherwise false.
 * @throws \Phalconry\Bundle\Exception\BundleNotFoundException if bundle cannot be found
 */
PHP_METHOD(Phalconry_Bundle_Manager, boot) {

	zend_bool _2;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *name_param = NULL, *bundle = NULL, *id = NULL, *dependencyInjector = NULL, *_0 = NULL, *_3 = NULL, *_4;
	zval *name = NULL, *_1;

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


	ZEPHIR_CALL_METHOD(&bundle, this_ptr, "getbundle", NULL, name);
	zephir_check_call_status();
	if (!(zephir_is_true(bundle))) {
		ZEPHIR_INIT_VAR(_0);
		object_init_ex(_0, phalconry_bundle_exception_ce);
		ZEPHIR_INIT_VAR(_1);
		ZEPHIR_CONCAT_SVS(_1, "Could not get bundle: '", name, "'");
		ZEPHIR_CALL_METHOD(NULL, _0, "__construct", NULL, _1);
		zephir_check_call_status();
		zephir_throw_exception_debug(_0, "phalconry/bundle/manager.zep", 227 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CALL_METHOD(&id, bundle, "getidentifier", NULL);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(_0);
	ZVAL_LONG(_0, 1);
	zephir_update_property_array(this_ptr, SL("_buildStack"), id, _0 TSRMLS_CC);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "bootdependencies", NULL, bundle);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "shutdownoverrides", NULL, bundle);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&dependencyInjector, this_ptr, "getdi", NULL);
	zephir_check_call_status();
	if (Z_TYPE_P(dependencyInjector) == IS_OBJECT) {
		ZEPHIR_CALL_METHOD(NULL, bundle, "setdi", NULL, dependencyInjector);
		zephir_check_call_status();
	}
	_2 = zephir_instance_of_ev(bundle, phalconry_bundle_installablebundleinterface_ce TSRMLS_CC);
	if (_2) {
		ZEPHIR_CALL_METHOD(&_3, bundle, "isinstalled", NULL);
		zephir_check_call_status();
		_2 = !zephir_is_true(_3);
	}
	if (_2) {
		ZEPHIR_CALL_METHOD(NULL, bundle, "install", NULL);
		zephir_check_call_status();
	}
	ZEPHIR_CALL_METHOD(NULL, bundle, "boot", NULL);
	zephir_check_call_status();
	_4 = zephir_fetch_nproperty_this(this_ptr, SL("_buildStack"), PH_NOISY_CC);
	zephir_array_unset(&_4, id, PH_SEPARATE);
	RETURN_MM_BOOL(1);

}

/**
 * Shuts down a bundle.
 *
 * @param string name Bundle name.
 * @return boolean
 */
PHP_METHOD(Phalconry_Bundle_Manager, shutdown) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *name_param = NULL, *bundle = NULL, *_0, *_1 = NULL;
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


	ZEPHIR_CALL_METHOD(&bundle, this_ptr, "getbundle", NULL, name);
	zephir_check_call_status();
	if (!(zephir_is_true(bundle))) {
		RETURN_MM_BOOL(0);
	}
	ZEPHIR_CALL_METHOD(NULL, bundle, "shutdown", NULL);
	zephir_check_call_status();
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_bundles"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(&_1, bundle, "getidentifier", NULL);
	zephir_check_call_status();
	zephir_array_unset(&_0, _1, PH_SEPARATE);
	RETURN_MM_BOOL(1);

}

/**
 * Returns the provider, if any, for the given bundle type and name.
 *
 * @param string type Bundle type.
 * @param string name Bundle name.
 * @return \Phalconry\Bundle\ProviderInterface|null
 */
PHP_METHOD(Phalconry_Bundle_Manager, getProviderFor) {

	zval *type_param = NULL, *name_param = NULL, *_0, *_1, *_2, *_3;
	zval *type = NULL, *name = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &type_param, &name_param);

	if (unlikely(Z_TYPE_P(type_param) != IS_STRING && Z_TYPE_P(type_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'type' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(type_param) == IS_STRING)) {
		zephir_get_strval(type, type_param);
	} else {
		ZEPHIR_INIT_VAR(type);
		ZVAL_EMPTY_STRING(type);
	}
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


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_providers"), PH_NOISY_CC);
	if (zephir_array_isset(_0, name)) {
		_1 = zephir_fetch_nproperty_this(this_ptr, SL("_providers"), PH_NOISY_CC);
		zephir_array_fetch(&_2, _1, name, PH_NOISY | PH_READONLY, "phalconry/bundle/manager.zep", 287 TSRMLS_CC);
		RETURN_CTOR(_2);
	}
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("_typeProviders"), PH_NOISY_CC);
	if (zephir_array_isset(_1, type)) {
		_3 = zephir_fetch_nproperty_this(this_ptr, SL("_typeProviders"), PH_NOISY_CC);
		zephir_array_fetch(&_2, _3, type, PH_NOISY | PH_READONLY, "phalconry/bundle/manager.zep", 292 TSRMLS_CC);
		RETURN_CTOR(_2);
	}
	RETURN_MM_NULL();

}

/**
 * Sets a bundle object from its provider.
 *
 * @param string id Bundle identifier.
 * @return boolean True if bundle was set, or false if no provider exists.
 * @throws \UnexpectedValueException if provider does not return a BundleInterface.
 */
PHP_METHOD(Phalconry_Bundle_Manager, setBundleFromProvider) {

	zephir_nts_static zephir_fcall_cache_entry *_0 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *id_param = NULL, *parts, *type, *name, *provider = NULL, *bundle = NULL, *_1;
	zval *id = NULL, *_2;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &id_param);

	zephir_get_strval(id, id_param);


	ZEPHIR_INIT_VAR(parts);
	zephir_fast_explode_str(parts, SL("."), id, 2  TSRMLS_CC);
	ZEPHIR_OBS_VAR(type);
	zephir_array_fetch_long(&type, parts, 0, PH_NOISY, "phalconry/bundle/manager.zep", 310 TSRMLS_CC);
	ZEPHIR_OBS_VAR(name);
	zephir_array_fetch_long(&name, parts, 1, PH_NOISY, "phalconry/bundle/manager.zep", 311 TSRMLS_CC);
	ZEPHIR_CALL_METHOD(&provider, this_ptr, "getproviderfor", NULL, type, name);
	zephir_check_call_status();
	if (!(zephir_is_true(provider))) {
		RETURN_MM_BOOL(0);
	}
	if (zephir_instance_of_ev(provider, phalconry_bundle_providerinterface_ce TSRMLS_CC)) {
		ZEPHIR_CALL_METHOD(&bundle, provider, "providebundle", NULL, type, name);
		zephir_check_call_status();
	} else {
		ZEPHIR_CALL_FUNCTION(&bundle, "call_user_func", &_0, provider, type, name);
		zephir_check_call_status();
	}
	if (!(zephir_instance_of_ev(bundle, phalconry_bundle_bundleinterface_ce TSRMLS_CC))) {
		ZEPHIR_INIT_VAR(_1);
		object_init_ex(_1, spl_ce_UnexpectedValueException);
		ZEPHIR_INIT_VAR(_2);
		ZEPHIR_CONCAT_SVS(_2, "A valid bundle was not provided for '", id, "'");
		ZEPHIR_CALL_METHOD(NULL, _1, "__construct", NULL, _2);
		zephir_check_call_status();
		zephir_throw_exception_debug(_1, "phalconry/bundle/manager.zep", 326 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "setbundle", NULL, bundle);
	zephir_check_call_status();
	RETURN_MM_BOOL(1);

}

/**
 * Loads a bundle"s dependencies.
 *
 * @param \Phalconry\Bundle\BundleInterface bundle
 * @throws \Phalconry\Bundle\Exception\DependencyException if missing dependency bundles.
 */
PHP_METHOD(Phalconry_Bundle_Manager, bootDependencies) {

	zephir_nts_static zephir_fcall_cache_entry *_13 = NULL;
	zend_bool _5, _7;
	zephir_fcall_cache_entry *_3 = NULL, *_9 = NULL;
	HashTable *_1;
	HashPosition _0;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *bundle, *dependencies = NULL, *missing = NULL, *id = NULL, *dependency = NULL, *e = NULL, *exception, **_2, *_4 = NULL, *_6, *_8 = NULL, *_10 = NULL, _11, *_12 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &bundle);



	if (!(zephir_instance_of_ev(bundle, phalconry_bundle_bundleinterface_ce TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "Parameter 'bundle' must be an instance of 'Phalconry\\Bundle\\BundleInterface'", "", 0);
		return;
	}
	ZEPHIR_CALL_METHOD(&dependencies, bundle, "getdependencies", NULL);
	zephir_check_call_status();
	if (ZEPHIR_IS_EMPTY(dependencies)) {
		RETURN_MM_NULL();
	}
	ZEPHIR_INIT_VAR(missing);
	array_init(missing);
	zephir_is_iterable(dependencies, &_1, &_0, 0, 0, "phalconry/bundle/manager.zep", 372);
	for (
	  ; zephir_hash_get_current_data_ex(_1, (void**) &_2, &_0) == SUCCESS
	  ; zephir_hash_move_forward_ex(_1, &_0)
	) {
		ZEPHIR_GET_HVALUE(id, _2);

		/* try_start_1: */

			ZEPHIR_CALL_METHOD(&dependency, this_ptr, "getbundle", &_3, id);
			zephir_check_call_status_or_jump(try_end_1);
			if (!(zephir_is_true(dependency))) {
				zephir_array_append(&missing, id, PH_SEPARATE, "phalconry/bundle/manager.zep", 359);
			} else {
				ZEPHIR_CALL_METHOD(&_4, dependency, "isbooted", NULL);
				zephir_check_call_status_or_jump(try_end_1);
				_5 = !zephir_is_true(_4);
				if (_5) {
					_6 = zephir_fetch_nproperty_this(this_ptr, SL("_buildStack"), PH_NOISY_CC);
					_5 = !(zephir_array_isset(_6, id));
				}
				_7 = _5;
				if (_7) {
					ZEPHIR_CALL_METHOD(&_8, this_ptr, "boot", &_9, dependency);
					zephir_check_call_status_or_jump(try_end_1);
					_7 = !zephir_is_true(_8);
				}
				if (_7) {
					zephir_array_append(&missing, id, PH_SEPARATE, "phalconry/bundle/manager.zep", 362);
				}
			}

		try_end_1:

		if (EG(exception)) {
			ZEPHIR_CPY_WRT(e, EG(exception));
			if (zephir_instance_of_ev(e, phalconry_bundle_exception_dependencyexception_ce TSRMLS_CC)) {
				zend_clear_exception(TSRMLS_C);
				ZEPHIR_INIT_NVAR(_10);
				ZEPHIR_CALL_METHOD(&_4, e, "getmissing", NULL);
				zephir_check_call_status();
				zephir_fast_array_merge(_10, &(missing), &(_4) TSRMLS_CC);
				ZEPHIR_CPY_WRT(missing, _10);
			}
		}
	}
	if (!(ZEPHIR_IS_EMPTY(missing))) {
		ZEPHIR_INIT_VAR(exception);
		object_init_ex(exception, phalconry_bundle_exception_dependencyexception_ce);
		ZEPHIR_CALL_METHOD(&_8, bundle, "getname", NULL);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(_10);
		zephir_fast_join_str(_10, SL(", "), missing TSRMLS_CC);
		ZEPHIR_SINIT_VAR(_11);
		ZVAL_STRING(&_11, "Could not boot bundle '%s' (missing dependencies: %s).", 0);
		ZEPHIR_CALL_FUNCTION(&_12, "sprintf", &_13, &_11, _8, _10);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, exception, "__construct", NULL, _12);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, exception, "setmissing", NULL, missing);
		zephir_check_call_status();
		zephir_throw_exception_debug(exception, "phalconry/bundle/manager.zep", 382 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Shuts down bundles that are overridden by the given bundle.
 *
 * @param \Phalconry\Bundle\BundleInterface bundle Bundle that may override others.
 */
PHP_METHOD(Phalconry_Bundle_Manager, shutdownOverrides) {

	zephir_fcall_cache_entry *_4 = NULL;
	HashTable *_2;
	HashPosition _1;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *bundle, *override = NULL, *_0 = NULL, **_3;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &bundle);



	if (!(zephir_instance_of_ev(bundle, phalconry_bundle_bundleinterface_ce TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "Parameter 'bundle' must be an instance of 'Phalconry\\Bundle\\BundleInterface'", "", 0);
		return;
	}
	ZEPHIR_CALL_METHOD(&_0, bundle, "getoverrides", NULL);
	zephir_check_call_status();
	zephir_is_iterable(_0, &_2, &_1, 0, 0, "phalconry/bundle/manager.zep", 397);
	for (
	  ; zephir_hash_get_current_data_ex(_2, (void**) &_3, &_1) == SUCCESS
	  ; zephir_hash_move_forward_ex(_2, &_1)
	) {
		ZEPHIR_GET_HVALUE(override, _3);
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "shutdown", &_4, override);
		zephir_check_call_status();
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Phalconry_Bundle_Manager, __construct) {

	zval *_0, *_1, *_2, *_3;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(_0);
	array_init(_0);
	zephir_update_property_this(this_ptr, SL("_buildStack"), _0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_1);
	array_init(_1);
	zephir_update_property_this(this_ptr, SL("_typeProviders"), _1 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_2);
	array_init(_2);
	zephir_update_property_this(this_ptr, SL("_providers"), _2 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_3);
	array_init(_3);
	zephir_update_property_this(this_ptr, SL("_bundles"), _3 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

