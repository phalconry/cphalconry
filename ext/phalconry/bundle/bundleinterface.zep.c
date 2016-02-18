
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


ZEPHIR_INIT_CLASS(Phalconry_Bundle_BundleInterface) {

	ZEPHIR_REGISTER_INTERFACE(Phalconry\\Bundle, BundleInterface, phalconry, bundle_bundleinterface, phalconry_bundle_bundleinterface_method_entry);

	zend_class_implements(phalconry_bundle_bundleinterface_ce TSRMLS_CC, 1, zephir_get_internal_ce(SS("phalcon\\di\\injectionawareinterface") TSRMLS_CC));
	return SUCCESS;

}

/**
 * Boots the bundle.
 */
ZEPHIR_DOC_METHOD(Phalconry_Bundle_BundleInterface, boot);

/**
 * Shuts down the bundle.
 */
ZEPHIR_DOC_METHOD(Phalconry_Bundle_BundleInterface, shutdown);

/**
 * Whether the bundle is booted.
 *
 * @return boolean
 */
ZEPHIR_DOC_METHOD(Phalconry_Bundle_BundleInterface, isBooted);

/**
 * Returns array of bundle names which this one overrides.
 *
 * @return array
 */
ZEPHIR_DOC_METHOD(Phalconry_Bundle_BundleInterface, getOverrides);

/**
 * Returns array of bundle names that this one requires.
 *
 * @return array
 */
ZEPHIR_DOC_METHOD(Phalconry_Bundle_BundleInterface, getDependencies);

/**
 * Returns the bundle type.
 *
 * @return string Bundle type.
 */
ZEPHIR_DOC_METHOD(Phalconry_Bundle_BundleInterface, getBundleType);

/**
 * Returns the bundle name.
 *
 * @return string Bundle name.
 */
ZEPHIR_DOC_METHOD(Phalconry_Bundle_BundleInterface, getName);

/**
 * Returns the bundle type and name like "<type>.<name>"
 *
 * @return string Bundle ID.
 */
ZEPHIR_DOC_METHOD(Phalconry_Bundle_BundleInterface, getIdentifier);

