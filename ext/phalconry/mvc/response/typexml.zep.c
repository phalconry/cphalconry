
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


ZEPHIR_INIT_CLASS(Phalconry_Mvc_Response_TypeXml) {

	ZEPHIR_REGISTER_CLASS_EX(Phalconry\\Mvc\\Response, TypeXml, phalconry, mvc_response_typexml, phalconry_mvc_response_abstractdatatype_ce, phalconry_mvc_response_typexml_method_entry, 0);

	return SUCCESS;

}

PHP_METHOD(Phalconry_Mvc_Response_TypeXml, formatResponse) {

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
	ZEPHIR_CALL_METHOD(&_0, response, "getheaders", NULL);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_1);
	ZVAL_STRING(_1, "Status", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&status, _0, "get", NULL, _1);
	zephir_check_temp_parameter(_1);
	zephir_check_call_status();
	if (!(zephir_is_true(status))) {
		ZEPHIR_INIT_NVAR(_1);
		ZVAL_LONG(_1, 200);
		ZEPHIR_INIT_VAR(_2);
		ZVAL_STRING(_2, "OK", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(NULL, response, "setstatuscode", NULL, _1, _2);
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
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "status", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_NVAR(_2);
	ZVAL_LONG(_2, zephir_get_intval(_5));
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "prepend", NULL, _1, _2);
	zephir_check_temp_parameter(_1);
	zephir_check_call_status();
	ZEPHIR_SINIT_NVAR(_3);
	ZVAL_LONG(&_3, 4);
	ZEPHIR_CALL_FUNCTION(&_7, "substr", &_6, status, &_3);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "message", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "prepend", NULL, _1, _7);
	zephir_check_temp_parameter(_1);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_8, response, "getdi", NULL);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_9, _8, "getrequest", NULL);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "dev", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&_10, _9, "hasquery", NULL, _1);
	zephir_check_temp_parameter(_1);
	zephir_check_call_status();
	if (zephir_is_true(_10)) {
		ZEPHIR_CALL_METHOD(&_11, response, "getdi", NULL);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(_1);
		ZVAL_STRING(_1, "diagnostics", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&_12, _11, "getshared", NULL, _1);
		zephir_check_temp_parameter(_1);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&_13, _12, "getall", NULL);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(_1);
		ZVAL_STRING(_1, "diagnostics", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "append", NULL, _1, _13);
		zephir_check_temp_parameter(_1);
		zephir_check_call_status();
	}
	ZEPHIR_CALL_METHOD(&_11, this_ptr, "encode", NULL);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, response, "setcontent", NULL, _11);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Phalconry_Mvc_Response_TypeXml, getContentType) {


	RETURN_STRING("application/xml", 1);

}

PHP_METHOD(Phalconry_Mvc_Response_TypeXml, encode) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *_0 = NULL;
	zend_class_entry *util_util_xml;

	ZEPHIR_MM_GROW();

	util_util_xml = zend_fetch_class(SL("\\Util\\Xml"), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getcontent", NULL);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_CE_STATIC(util_util_xml, "writedocument", NULL, _0);
	zephir_check_call_status();
	RETURN_MM();

}

