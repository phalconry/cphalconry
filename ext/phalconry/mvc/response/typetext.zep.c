
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
#include "kernel/fcall.h"
#include "kernel/memory.h"


ZEPHIR_INIT_CLASS(Phalconry_Mvc_Response_TypeText) {

	ZEPHIR_REGISTER_CLASS_EX(Phalconry\\Mvc\\Response, TypeText, phalconry, mvc_response_typetext, phalconry_mvc_response_abstracttype_ce, phalconry_mvc_response_typetext_method_entry, 0);

	return SUCCESS;

}

PHP_METHOD(Phalconry_Mvc_Response_TypeText, setModifiedContent) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_1 = NULL;
	zval *response, *content, *_0 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &response, &content);



	if (!(zephir_is_instance_of(response, SL("Phalcon\\Http\\ResponseInterface") TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "Parameter 'response' must be an instance of 'Phalcon\\Http\\ResponseInterface'", "", 0);
		return;
	}
	if (Z_TYPE_P(content) == IS_STRING) {
		ZEPHIR_CALL_FUNCTION(&_0, "strip_tags", &_1, content);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, response, "setcontent", NULL, _0);
		zephir_check_call_status();
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Phalconry_Mvc_Response_TypeText, getContentType) {


	RETURN_STRING("text/plain", 1);

}

