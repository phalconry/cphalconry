
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
#include "kernel/operators.h"
#include "kernel/memory.h"
#include "kernel/string.h"


ZEPHIR_INIT_CLASS(Phalconry_Mvc_Response_TypeJson) {

	ZEPHIR_REGISTER_CLASS_EX(Phalconry\\Mvc\\Response, TypeJson, phalconry, mvc_response_typejson, phalconry_mvc_response_abstractdatatype_ce, phalconry_mvc_response_typejson_method_entry, 0);

	zend_class_implements(phalconry_mvc_response_typejson_ce TSRMLS_CC, 1, zephir_get_internal_ce(SS("jsonserializable") TSRMLS_CC));
	return SUCCESS;

}

PHP_METHOD(Phalconry_Mvc_Response_TypeJson, formatResponse) {

	zephir_nts_static zephir_fcall_cache_entry *_6 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *response, *data = NULL, *status = NULL, *_0 = NULL, *_1 = NULL, *_2 = NULL, _3 = zval_used_for_init, _4, *_5 = NULL, *_7 = NULL, *_8 = NULL, *_9 = NULL, *_10 = NULL, *_11 = NULL, *_12 = NULL, *_13 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &response);



	if (!(zephir_is_instance_of(response, SL("Phalcon\\Http\\ResponseInterface") TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "Parameter 'response' must be an instance of 'Phalcon\\Http\\ResponseInterface'", "", 0);
		return;
	}
	ZEPHIR_CALL_METHOD(&data, this_ptr, "getdata", NULL);
	zephir_check_call_status();
	if (!(zephir_is_true(data))) {
		ZEPHIR_CALL_METHOD(&data, response, "getcontent", NULL);
		zephir_check_call_status();
	}
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "setdata", NULL, data);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_0);
	ZVAL_LONG(_0, 32);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "addoption", NULL, _0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_1, response, "getheaders", NULL);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(_0);
	ZVAL_STRING(_0, "Status", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&status, _1, "get", NULL, _0);
	zephir_check_temp_parameter(_0);
	zephir_check_call_status();
	if (!(zephir_is_true(status))) {
		ZEPHIR_INIT_NVAR(_0);
		ZVAL_LONG(_0, 200);
		ZEPHIR_INIT_VAR(_2);
		ZVAL_STRING(_2, "OK", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(NULL, response, "setstatuscode", NULL, _0, _2);
		zephir_check_temp_parameter(_2);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(status);
		ZVAL_STRING(status, "200 OK", 1);
	}
	ZEPHIR_SINIT_VAR(_3);
	ZVAL_LONG(&_3, 0);
	ZEPHIR_SINIT_VAR(_4);
	ZVAL_LONG(&_4, 3);
	ZEPHIR_CALL_FUNCTION(&_5, "substr", &_6, status, &_3, &_4);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(_0);
	ZVAL_STRING(_0, "status", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_NVAR(_2);
	ZVAL_LONG(_2, zephir_get_intval(_5));
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "prepend", NULL, _0, _2);
	zephir_check_temp_parameter(_0);
	zephir_check_call_status();
	ZEPHIR_SINIT_NVAR(_3);
	ZVAL_LONG(&_3, 4);
	ZEPHIR_CALL_FUNCTION(&_7, "substr", &_6, status, &_3);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(_0);
	ZVAL_STRING(_0, "message", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "prepend", NULL, _0, _7);
	zephir_check_temp_parameter(_0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_8, response, "getdi", NULL);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(_0);
	ZVAL_STRING(_0, "request", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&_9, _8, "getshared", NULL, _0);
	zephir_check_temp_parameter(_0);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(_0);
	ZVAL_STRING(_0, "dev", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&_10, _9, "hasquery", NULL, _0);
	zephir_check_temp_parameter(_0);
	zephir_check_call_status();
	if (zephir_is_true(_10)) {
		ZEPHIR_INIT_NVAR(_0);
		ZVAL_LONG(_0, 128);
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "addoption", NULL, _0);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&_11, response, "getdi", NULL);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(_0);
		ZVAL_STRING(_0, "diagnostics", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&_12, _11, "getshared", NULL, _0);
		zephir_check_temp_parameter(_0);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&_13, _12, "getall", NULL);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(_0);
		ZVAL_STRING(_0, "diagnostics", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "append", NULL, _0, _13);
		zephir_check_temp_parameter(_0);
		zephir_check_call_status();
	}
	ZEPHIR_CALL_METHOD(&_11, this_ptr, "encode", NULL);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, response, "setcontent", NULL, _11);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Phalconry_Mvc_Response_TypeJson, getContentType) {


	RETURN_STRING("application/json", 1);

}

PHP_METHOD(Phalconry_Mvc_Response_TypeJson, encode) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *_0 = NULL, *_1 = NULL;

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getcontent", NULL);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "getoptions", NULL);
	zephir_check_call_status();
	zephir_json_encode(return_value, &(return_value), _0, zephir_get_intval(_1)  TSRMLS_CC);
	RETURN_MM();

}

PHP_METHOD(Phalconry_Mvc_Response_TypeJson, jsonSerialize) {

	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "getcontent", NULL);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Phalconry_Mvc_Response_TypeJson, valueToArray) {

	zephir_nts_static zephir_fcall_cache_entry *_2 = NULL;
	zval *_1 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *value, *_0 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &value);



	if (Z_TYPE_P(value) == IS_OBJECT) {
		if ((zephir_method_exists_ex(value, SS("jsonserialize") TSRMLS_CC) == SUCCESS)) {
			ZEPHIR_CALL_METHOD(&_0, value, "jsonserialize", NULL);
			zephir_check_call_status();
			zephir_get_arrval(_1, _0);
			RETURN_CTOR(_1);
		}
	}
	ZEPHIR_RETURN_CALL_PARENT(phalconry_mvc_response_typejson_ce, this_ptr, "valuetoarray", &_2, value);
	zephir_check_call_status();
	RETURN_MM();

}

