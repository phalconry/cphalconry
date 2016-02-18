
#ifdef HAVE_CONFIG_H
#include "../../../ext_config.h"
#endif

#include <php.h>
#include "../../../php_ext.h"
#include "../../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


ZEPHIR_INIT_CLASS(Phalconry_Mvc_Application_BootstrapInterface) {

	ZEPHIR_REGISTER_INTERFACE(Phalconry\\Mvc\\Application, BootstrapInterface, phalconry, mvc_application_bootstrapinterface, phalconry_mvc_application_bootstrapinterface_method_entry);

	return SUCCESS;

}

/**
 * Boots the application.
 *
 * @param \Phalconry\Mvc\ApplicationInterface app
 * @return void
 */
ZEPHIR_DOC_METHOD(Phalconry_Mvc_Application_BootstrapInterface, boot);

