
#ifdef HAVE_CONFIG_H
#include "../../../ext_config.h"
#endif

#include <php.h>
#include "../../../php_ext.h"
#include "../../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/object.h"
#include "kernel/exception.h"
#include "kernel/memory.h"


ZEPHIR_INIT_CLASS(Phalconry_Mvc_Response_AbstractType) {

	ZEPHIR_REGISTER_CLASS(Phalconry\\Mvc\\Response, AbstractType, phalconry, mvc_response_abstracttype, phalconry_mvc_response_abstracttype_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	zend_class_implements(phalconry_mvc_response_abstracttype_ce TSRMLS_CC, 1, phalconry_mvc_response_typeinterface_ce);
	return SUCCESS;

}

PHP_METHOD(Phalconry_Mvc_Response_AbstractType, setModifiedContent) {

	zval *response, *content;

	zephir_fetch_params(0, 2, 0, &response, &content);



	if (!(zephir_is_instance_of(response, SL("Phalcon\\Http\\ResponseInterface") TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STRW(spl_ce_InvalidArgumentException, "Parameter 'response' must be an instance of 'Phalcon\\Http\\ResponseInterface'", "", 0);
		return;
	}

}

PHP_METHOD(Phalconry_Mvc_Response_AbstractType, formatResponse) {

	zval *response;

	zephir_fetch_params(0, 1, 0, &response);



	if (!(zephir_is_instance_of(response, SL("Phalcon\\Http\\ResponseInterface") TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STRW(spl_ce_InvalidArgumentException, "Parameter 'response' must be an instance of 'Phalcon\\Http\\ResponseInterface'", "", 0);
		return;
	}

}

