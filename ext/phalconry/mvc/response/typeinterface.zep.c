
#ifdef HAVE_CONFIG_H
#include "../../../ext_config.h"
#endif

#include <php.h>
#include "../../../php_ext.h"
#include "../../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


ZEPHIR_INIT_CLASS(Phalconry_Mvc_Response_TypeInterface) {

	ZEPHIR_REGISTER_INTERFACE(Phalconry\\Mvc\\Response, TypeInterface, phalconry, mvc_response_typeinterface, phalconry_mvc_response_typeinterface_method_entry);

	return SUCCESS;

}

ZEPHIR_DOC_METHOD(Phalconry_Mvc_Response_TypeInterface, getContentType);

ZEPHIR_DOC_METHOD(Phalconry_Mvc_Response_TypeInterface, setModifiedContent);

ZEPHIR_DOC_METHOD(Phalconry_Mvc_Response_TypeInterface, formatResponse);

