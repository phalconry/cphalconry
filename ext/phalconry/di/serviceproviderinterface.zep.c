
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


ZEPHIR_INIT_CLASS(Phalconry_DI_ServiceProviderInterface) {

	ZEPHIR_REGISTER_INTERFACE(Phalconry\\DI, ServiceProviderInterface, phalconry, di_serviceproviderinterface, phalconry_di_serviceproviderinterface_method_entry);

	return SUCCESS;

}

/**
 * Registers the service components
 *
 * @param \Phalcon\DiInterface $di
 */
ZEPHIR_DOC_METHOD(Phalconry_DI_ServiceProviderInterface, register);

