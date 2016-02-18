
#ifdef HAVE_CONFIG_H
#include "../../../ext_config.h"
#endif

#include <php.h>
#include "../../../php_ext.h"
#include "../../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


ZEPHIR_INIT_CLASS(Phalconry_Mvc_Application_HandlerInterface) {

	ZEPHIR_REGISTER_INTERFACE(Phalconry\\Mvc\\Application, HandlerInterface, phalconry, mvc_application_handlerinterface, phalconry_mvc_application_handlerinterface_method_entry);

	zend_class_implements(phalconry_mvc_application_handlerinterface_ce TSRMLS_CC, 1, phalconry_mvc_applicationawareinterface_ce);
	return SUCCESS;

}

/**
 * Handles the request and returns a response.
 *
 * @param string uri [Optional]
 * @return \Phalcon\Http\ResponseInterface
 */
ZEPHIR_DOC_METHOD(Phalconry_Mvc_Application_HandlerInterface, handle);

