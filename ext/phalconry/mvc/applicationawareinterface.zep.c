
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


ZEPHIR_INIT_CLASS(Phalconry_Mvc_ApplicationAwareInterface) {

	ZEPHIR_REGISTER_INTERFACE(Phalconry\\Mvc, ApplicationAwareInterface, phalconry, mvc_applicationawareinterface, phalconry_mvc_applicationawareinterface_method_entry);

	return SUCCESS;

}

/**
 * Sets the application.
 *
 * @param \Phalconry\Mvc\ApplicationInterface app
 *
 * @return void
 */
ZEPHIR_DOC_METHOD(Phalconry_Mvc_ApplicationAwareInterface, setApplication);

/**
 * Returns the application.
 *
 * @return \Phalconry\Mvc\ApplicationInterface
 */
ZEPHIR_DOC_METHOD(Phalconry_Mvc_ApplicationAwareInterface, getApplication);

