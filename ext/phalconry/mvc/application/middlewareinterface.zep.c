
#ifdef HAVE_CONFIG_H
#include "../../../ext_config.h"
#endif

#include <php.h>
#include "../../../php_ext.h"
#include "../../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


ZEPHIR_INIT_CLASS(Phalconry_Mvc_Application_MiddlewareInterface) {

	ZEPHIR_REGISTER_INTERFACE(Phalconry\\Mvc\\Application, MiddlewareInterface, phalconry, mvc_application_middlewareinterface, phalconry_mvc_application_middlewareinterface_method_entry);

	/**
	 * Before handle request position.
	 *
	 * @var int
	 */
	zend_declare_class_constant_long(phalconry_mvc_application_middlewareinterface_ce, SL("POSITION_BEFORE_HANDLE"), 1 TSRMLS_CC);

	/**
	 * After handle request position.
	 *
	 * @var int
	 */
	zend_declare_class_constant_long(phalconry_mvc_application_middlewareinterface_ce, SL("POSITION_AFTER_HANDLE"), 2 TSRMLS_CC);

	return SUCCESS;

}

/**
 * Returns the position at which the middleware should be run.
 *
 * 1 = Before request handle
 * 2 = After request handle
 *
 * @return int
 */
ZEPHIR_DOC_METHOD(Phalconry_Mvc_Application_MiddlewareInterface, getPosition);

/**
 * Executes the middleware.
 *
 * @param \Phalcon\DiInterface di
 * @param \Phalconry\Mvc\ApplicationInterface app
 *
 * @return boolean
 */
ZEPHIR_DOC_METHOD(Phalconry_Mvc_Application_MiddlewareInterface, execute);

