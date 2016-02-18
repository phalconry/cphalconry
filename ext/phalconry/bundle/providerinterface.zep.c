
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


ZEPHIR_INIT_CLASS(Phalconry_Bundle_ProviderInterface) {

	ZEPHIR_REGISTER_INTERFACE(Phalconry\\Bundle, ProviderInterface, phalconry, bundle_providerinterface, phalconry_bundle_providerinterface_method_entry);

	return SUCCESS;

}

/**
 * Provides a bundle by type and name.
 *
 * @param string $type Bundle type.
 * @param string $name Bundle name.
 */
ZEPHIR_DOC_METHOD(Phalconry_Bundle_ProviderInterface, provideBundle);

/**
 * Returns the bundle(s) or bundle type that the class provides.
 *
 * @return string|array Bundle name(s) or bundle type.
 */
ZEPHIR_DOC_METHOD(Phalconry_Bundle_ProviderInterface, getProvided);

