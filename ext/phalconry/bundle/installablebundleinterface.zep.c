
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


ZEPHIR_INIT_CLASS(Phalconry_Bundle_InstallableBundleInterface) {

	ZEPHIR_REGISTER_INTERFACE(Phalconry\\Bundle, InstallableBundleInterface, phalconry, bundle_installablebundleinterface, phalconry_bundle_installablebundleinterface_method_entry);

	zend_class_implements(phalconry_bundle_installablebundleinterface_ce TSRMLS_CC, 1, phalconry_bundle_bundleinterface_ce);
	return SUCCESS;

}

/**
 * Whether the bundle is installed
 *
 * @return boolean
 */
ZEPHIR_DOC_METHOD(Phalconry_Bundle_InstallableBundleInterface, isInstalled);

/**
 * Installs the bundle
 *
 * @return void
 */
ZEPHIR_DOC_METHOD(Phalconry_Bundle_InstallableBundleInterface, install);

/**
 * Uninstalls the bundle
 *
 * @return void
 */
ZEPHIR_DOC_METHOD(Phalconry_Bundle_InstallableBundleInterface, uninstall);

