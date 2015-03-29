
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/object.h"
#include "kernel/operators.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"
#include "kernel/array.h"

ZEPHIR_INIT_CLASS(Phalconry_Mvc_Responder) {

	ZEPHIR_REGISTER_CLASS_EX(Phalconry\\Mvc, Responder, phalconry, mvc_responder, zephir_get_internal_ce(SS("phalcon\\mvc\\user\\component") TSRMLS_CC), phalconry_mvc_responder_method_entry, 0);

	/**
	 * Response type
	 * @var string
	 */
	zend_declare_property_string(phalconry_mvc_responder_ce, SL("_type"), "view", ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * Response type classes
	 * @var array
	 */
	zend_declare_property_null(phalconry_mvc_responder_ce, SL("_typeClasses"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * Response types that send structured data
	 * @var array
	 */
	zend_declare_property_null(phalconry_mvc_responder_ce, SL("_dataTypes"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * Whether to fill empty content with the retuned value
	 * @var boolean
	 */
	zend_declare_property_bool(phalconry_mvc_responder_ce, SL("_fillEmptyContent"), 1, ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * Disables the responder
	 * @var boolean
	 */
	zend_declare_class_constant_string(phalconry_mvc_responder_ce, SL("TYPE_NONE"), "" TSRMLS_CC);

	/**
	 * Designates a "text" response
	 * @var string
	 */
	zend_declare_class_constant_string(phalconry_mvc_responder_ce, SL("TYPE_TEXT"), "text" TSRMLS_CC);

	/**
	 * Designates a "view" response
	 * @var string
	 */
	zend_declare_class_constant_string(phalconry_mvc_responder_ce, SL("TYPE_VIEW"), "view" TSRMLS_CC);

	/**
	 * Designates a "json" response
	 * @var string
	 */
	zend_declare_class_constant_string(phalconry_mvc_responder_ce, SL("TYPE_JSON"), "json" TSRMLS_CC);

	/**
	 * Designates an "xml" response
	 * @var string
	 */
	zend_declare_class_constant_string(phalconry_mvc_responder_ce, SL("TYPE_XML"), "xml" TSRMLS_CC);

	return SUCCESS;

}

PHP_METHOD(Phalconry_Mvc_Responder, setType) {

	zval *type_param = NULL;
	zval *type = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &type_param);

	zephir_get_strval(type, type_param);


	zephir_update_property_this(this_ptr, SL("_type"), type TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Phalconry_Mvc_Responder, getType) {


	RETURN_MEMBER(this_ptr, "_type");

}

PHP_METHOD(Phalconry_Mvc_Responder, isType) {

	zval *type_param = NULL, *_0;
	zval *type = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &type_param);

	zephir_get_strval(type, type_param);


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_type"), PH_NOISY_CC);
	RETURN_MM_BOOL(ZEPHIR_IS_IDENTICAL(_0, type));

}

PHP_METHOD(Phalconry_Mvc_Responder, isDataType) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_1 = NULL;
	zval *type = NULL, *_0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &type);

	if (!type) {
		ZEPHIR_CPY_WRT(type, ZEPHIR_GLOBAL(global_null));
	} else {
		ZEPHIR_SEPARATE_PARAM(type);
	}


	if (Z_TYPE_P(type) == IS_NULL) {
		ZEPHIR_OBS_NVAR(type);
		zephir_read_property_this(&type, this_ptr, SL("_type"), PH_NOISY_CC);
	}
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_dataTypes"), PH_NOISY_CC);
	ZEPHIR_RETURN_CALL_FUNCTION("in_array", &_1, type, _0, ZEPHIR_GLOBAL(global_true));
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Phalconry_Mvc_Responder, setTypeClass) {

	zval *type_param = NULL, *className_param = NULL;
	zval *type = NULL, *className = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &type_param, &className_param);

	zephir_get_strval(type, type_param);
	if (unlikely(Z_TYPE_P(className_param) != IS_STRING && Z_TYPE_P(className_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'className' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(className_param) == IS_STRING)) {
		zephir_get_strval(className, className_param);
	} else {
		ZEPHIR_INIT_VAR(className);
		ZVAL_EMPTY_STRING(className);
	}


	zephir_update_property_array(this_ptr, SL("_typeClasses"), type, className TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Phalconry_Mvc_Responder, getTypeClass) {

	zval *type_param = NULL, *_0, *_1, *_2;
	zval *type = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &type_param);

	zephir_get_strval(type, type_param);


	ZEPHIR_INIT_VAR(_0);
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("_typeClasses"), PH_NOISY_CC);
	if (zephir_array_isset(_1, type)) {
		_2 = zephir_fetch_nproperty_this(this_ptr, SL("_typeClasses"), PH_NOISY_CC);
		zephir_array_fetch(&_0, _2, type, PH_NOISY, "phalconry/mvc/responder.zep", 101 TSRMLS_CC);
	} else {
		ZVAL_NULL(_0);
	}
	RETURN_CCTOR(_0);

}

PHP_METHOD(Phalconry_Mvc_Responder, fillEmptyContent) {

	zval *value = NULL;

	zephir_fetch_params(0, 0, 1, &value);

	if (!value) {
		value = ZEPHIR_GLOBAL(global_null);
	}


	if (Z_TYPE_P(value) != IS_NULL) {
		zephir_update_property_this(this_ptr, SL("_fillEmptyContent"), (zephir_get_boolval(value)) ? ZEPHIR_GLOBAL(global_true) : ZEPHIR_GLOBAL(global_false) TSRMLS_CC);
	}
	RETURN_MEMBER(this_ptr, "_fillEmptyContent");

}

/**
 * Modifies and sends the response
 *
 * @param \Phalcon\Http\ResponseInterface response
 */
PHP_METHOD(Phalconry_Mvc_Responder, respond) {

	zend_class_entry *_2;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *response, *typeClass = NULL, *responseType, *returnedValue = NULL, *content = NULL, *_0 = NULL, *_1 = NULL, *_3 = NULL, *_4 = NULL, *_5, *_6 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &response);



	if (!(zephir_is_instance_of(response, SL("Phalcon\\Http\\ResponseInterface") TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "Parameter 'response' must be an instance of 'Phalcon\\Http\\ResponseInterface'", "", 0);
		return;
	}
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "gettype", NULL);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&typeClass, this_ptr, "gettypeclass", NULL, _0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(responseType);
	zephir_fetch_safe_class(_1, typeClass);
	_2 = zend_fetch_class(Z_STRVAL_P(_1), Z_STRLEN_P(_1), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);
	object_init_ex(responseType, _2);
	if (zephir_has_constructor(responseType TSRMLS_CC)) {
		ZEPHIR_CALL_METHOD(NULL, responseType, "__construct", NULL);
		zephir_check_call_status();
	}
	ZEPHIR_CALL_METHOD(&_3, response, "getdi", NULL);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_5);
	ZVAL_STRING(_5, "dispatcher", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&_4, _3, "getshared", NULL, _5);
	zephir_check_temp_parameter(_5);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&returnedValue, _4, "getreturnedvalue", NULL);
	zephir_check_call_status();
	if (!ZEPHIR_IS_FALSE_IDENTICAL(returnedValue)) {
		if (!ZEPHIR_IS_IDENTICAL(returnedValue, response)) {
			ZEPHIR_CALL_METHOD(&_6, this_ptr, "fillemptycontent", NULL);
			zephir_check_call_status();
			if (zephir_is_true(_6)) {
				ZEPHIR_CALL_METHOD(&content, response, "getcontent", NULL);
				zephir_check_call_status();
				if (ZEPHIR_IS_EMPTY(content)) {
					if (!(ZEPHIR_IS_EMPTY(returnedValue))) {
						ZEPHIR_CALL_METHOD(NULL, responseType, "setmodifiedcontent", NULL, response, returnedValue);
						zephir_check_call_status();
					}
				}
			}
			ZEPHIR_CALL_METHOD(NULL, responseType, "formatresponse", NULL, response);
			zephir_check_call_status();
		}
	}
	ZEPHIR_CALL_METHOD(&_6, responseType, "getcontenttype", NULL);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, response, "setcontenttype", NULL, _6);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, response, "send", NULL);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Phalconry_Mvc_Responder, __construct) {

	zval *_1 = NULL;
	zval *_0, *_2;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(_0);
	array_init_size(_0, 3);
	ZEPHIR_INIT_VAR(_1);
	ZVAL_STRING(_1, "json", 1);
	zephir_array_fast_append(_0, _1);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "xml", 1);
	zephir_array_fast_append(_0, _1);
	zephir_update_property_this(this_ptr, SL("_dataTypes"), _0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_2);
	array_init_size(_2, 7);
	add_assoc_stringl_ex(_2, SS(""), SL("Phalconry\\Mvc\\Response\\TypeNone"), 1);
	add_assoc_stringl_ex(_2, SS("view"), SL("Phalconry\\Mvc\\Response\\TypeView"), 1);
	add_assoc_stringl_ex(_2, SS("text"), SL("Phalconry\\Mvc\\Response\\TypeText"), 1);
	add_assoc_stringl_ex(_2, SS("json"), SL("Phalconry\\Mvc\\Response\\TypeJson"), 1);
	add_assoc_stringl_ex(_2, SS("xml"), SL("Phalconry\\Mvc\\Response\\TypeXml"), 1);
	zephir_update_property_this(this_ptr, SL("_typeClasses"), _2 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

