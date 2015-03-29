
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


ZEPHIR_INIT_CLASS(Phalconry_Mvc_Response_TypeNone) {

	ZEPHIR_REGISTER_CLASS_EX(Phalconry\\Mvc\\Response, TypeNone, phalconry, mvc_response_typenone, phalconry_mvc_response_abstracttype_ce, phalconry_mvc_response_typenone_method_entry, 0);

	return SUCCESS;

}

PHP_METHOD(Phalconry_Mvc_Response_TypeNone, getContentType) {


	RETURN_STRING("text/plain", 1);

}

