
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
#include "kernel/memory.h"
#include "kernel/array.h"
#include "kernel/object.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"
#include "kernel/operators.h"
#include "kernel/fcall.h"


/**
 * Class ContentType
 *
 * @author Kachit
 * @link https://github.com/Kachit/phalcon-lib/blob/master/src/Kachit/Phalcon/Utils/MimeType.php
 */
ZEPHIR_INIT_CLASS(Phalconry_Http_Util_MimeType) {

	ZEPHIR_REGISTER_CLASS(Phalconry\\Http\\Util, MimeType, phalconry, http_util_mimetype, phalconry_http_util_mimetype_method_entry, 0);

	zend_declare_property_null(phalconry_http_util_mimetype_ce, SL("mimetypes"), ZEND_ACC_PROTECTED|ZEND_ACC_STATIC TSRMLS_CC);

	zend_declare_class_constant_string(phalconry_http_util_mimetype_ce, SL("DOWNLOAD"), "application/octet-stream" TSRMLS_CC);

	zend_declare_class_constant_string(phalconry_http_util_mimetype_ce, SL("TEXT"), "text/plain" TSRMLS_CC);

	zend_declare_class_constant_string(phalconry_http_util_mimetype_ce, SL("HTML"), "text/html" TSRMLS_CC);

	zend_declare_class_constant_string(phalconry_http_util_mimetype_ce, SL("XML"), "application/xml" TSRMLS_CC);

	zend_declare_class_constant_string(phalconry_http_util_mimetype_ce, SL("JSON"), "application/json" TSRMLS_CC);

	zend_declare_class_constant_string(phalconry_http_util_mimetype_ce, SL("JS"), "application/javascript" TSRMLS_CC);

	zend_declare_class_constant_string(phalconry_http_util_mimetype_ce, SL("CSS"), "text/css" TSRMLS_CC);

	zend_declare_class_constant_string(phalconry_http_util_mimetype_ce, SL("DEFAULT_HTTP"), "text/html" TSRMLS_CC);

	zend_declare_class_constant_string(phalconry_http_util_mimetype_ce, SL("DEFAULT_FILE"), "application/octet-stream" TSRMLS_CC);

	return SUCCESS;

}

/**
 * Returns a mime/type by file extension
 *
 * @param string extension Extension without dots (e.g. "html")
 * @param string default [Optional] Default value to return if mime/type is not found. Default is null
 * @return string
 */
PHP_METHOD(Phalconry_Http_Util_MimeType, get) {

	zval *_0;
	zval *extension_param = NULL, *defaultValue = NULL, *_1 = NULL, *_2, *_3;
	zval *extension = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &extension_param, &defaultValue);

	if (unlikely(Z_TYPE_P(extension_param) != IS_STRING && Z_TYPE_P(extension_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'extension' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(extension_param) == IS_STRING)) {
		zephir_get_strval(extension, extension_param);
	} else {
		ZEPHIR_INIT_VAR(extension);
		ZVAL_EMPTY_STRING(extension);
	}
	if (!defaultValue) {
		defaultValue = ZEPHIR_GLOBAL(global_null);
	}


	if (!((0 == 0))) {
		ZEPHIR_INIT_VAR(_0);
		zephir_create_array(_0, 40, 0 TSRMLS_CC);
		add_assoc_stringl_ex(_0, SS("txt"), SL("text/plain"), 1);
		add_assoc_stringl_ex(_0, SS("htm"), SL("text/html"), 1);
		add_assoc_stringl_ex(_0, SS("html"), SL("text/html"), 1);
		add_assoc_stringl_ex(_0, SS("php"), SL("text/html"), 1);
		add_assoc_stringl_ex(_0, SS("css"), SL("text/css"), 1);
		add_assoc_stringl_ex(_0, SS("js"), SL("application/javascript"), 1);
		add_assoc_stringl_ex(_0, SS("json"), SL("application/json"), 1);
		add_assoc_stringl_ex(_0, SS("xml"), SL("application/xml"), 1);
		add_assoc_stringl_ex(_0, SS("swf"), SL("application/x-shockwave-flash"), 1);
		add_assoc_stringl_ex(_0, SS("flv"), SL("video/x-flv"), 1);
		add_assoc_stringl_ex(_0, SS("png"), SL("image/png"), 1);
		add_assoc_stringl_ex(_0, SS("jpe"), SL("image/jpeg"), 1);
		add_assoc_stringl_ex(_0, SS("jpeg"), SL("image/jpeg"), 1);
		add_assoc_stringl_ex(_0, SS("jpg"), SL("image/jpeg"), 1);
		add_assoc_stringl_ex(_0, SS("gif"), SL("image/gif"), 1);
		add_assoc_stringl_ex(_0, SS("bmp"), SL("image/bmp"), 1);
		add_assoc_stringl_ex(_0, SS("ico"), SL("image/vnd.microsoft.icon"), 1);
		add_assoc_stringl_ex(_0, SS("tiff"), SL("image/tiff"), 1);
		add_assoc_stringl_ex(_0, SS("tif"), SL("image/tiff"), 1);
		add_assoc_stringl_ex(_0, SS("svg"), SL("image/svg+xml"), 1);
		add_assoc_stringl_ex(_0, SS("svgz"), SL("image/svg+xml"), 1);
		add_assoc_stringl_ex(_0, SS("zip"), SL("application/zip"), 1);
		add_assoc_stringl_ex(_0, SS("rar"), SL("application/x-rar-compressed"), 1);
		add_assoc_stringl_ex(_0, SS("exe"), SL("application/x-msdownload"), 1);
		add_assoc_stringl_ex(_0, SS("msi"), SL("application/x-msdownload"), 1);
		add_assoc_stringl_ex(_0, SS("cab"), SL("application/vnd.ms-cab-compressed"), 1);
		add_assoc_stringl_ex(_0, SS("mp3"), SL("audio/mpeg"), 1);
		add_assoc_stringl_ex(_0, SS("qt"), SL("video/quicktime"), 1);
		add_assoc_stringl_ex(_0, SS("mov"), SL("video/quicktime"), 1);
		add_assoc_stringl_ex(_0, SS("pdf"), SL("application/pdf"), 1);
		add_assoc_stringl_ex(_0, SS("psd"), SL("image/vnd.adobe.photoshop"), 1);
		add_assoc_stringl_ex(_0, SS("ai"), SL("application/postscript"), 1);
		add_assoc_stringl_ex(_0, SS("eps"), SL("application/postscript"), 1);
		add_assoc_stringl_ex(_0, SS("ps"), SL("application/postscript"), 1);
		add_assoc_stringl_ex(_0, SS("doc"), SL("application/msword"), 1);
		add_assoc_stringl_ex(_0, SS("rtf"), SL("application/rtf"), 1);
		add_assoc_stringl_ex(_0, SS("xls"), SL("application/vnd.ms-excel"), 1);
		add_assoc_stringl_ex(_0, SS("ppt"), SL("application/vnd.ms-powerpoint"), 1);
		add_assoc_stringl_ex(_0, SS("odt"), SL("application/vnd.oasis.opendocument.text"), 1);
		add_assoc_stringl_ex(_0, SS("ods"), SL("application/vnd.oasis.opendocument.spreadsheet"), 1);
		zephir_update_static_property_ce(phalconry_http_util_mimetype_ce, SL("mimetypes"), &_0 TSRMLS_CC);
	}
	ZEPHIR_INIT_VAR(_1);
	_2 = zephir_fetch_static_property_ce(phalconry_http_util_mimetype_ce, SL("mimetypes") TSRMLS_CC);
	if (zephir_array_isset(_2, extension)) {
		_3 = zephir_fetch_static_property_ce(phalconry_http_util_mimetype_ce, SL("mimetypes") TSRMLS_CC);
		zephir_array_fetch(&_1, _3, extension, PH_NOISY, "phalconry/http/util/mimetype.zep", 86 TSRMLS_CC);
	} else {
		ZEPHIR_CPY_WRT(_1, defaultValue);
	}
	RETURN_CCTOR(_1);

}

/**
 * Attempts to return a mime/type for a file
 *
 * @param string filename The filename
 * @return string Detected mime/type for the file, or the value of DEFAULT_FILE if not found
 */
PHP_METHOD(Phalconry_Http_Util_MimeType, getForFile) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *filename_param = NULL, _0, *_1 = NULL, *_2;
	zval *filename = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &filename_param);

	if (unlikely(Z_TYPE_P(filename_param) != IS_STRING && Z_TYPE_P(filename_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'filename' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(filename_param) == IS_STRING)) {
		zephir_get_strval(filename, filename_param);
	} else {
		ZEPHIR_INIT_VAR(filename);
		ZVAL_EMPTY_STRING(filename);
	}


	ZEPHIR_SINIT_VAR(_0);
	ZVAL_LONG(&_0, 4);
	ZEPHIR_CALL_FUNCTION(&_1, "pathinfo", NULL, 49, filename, &_0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_2);
	ZVAL_STRING(_2, "application/octet-stream", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_RETURN_CALL_SELF("get", NULL, 0, _1, _2);
	zephir_check_temp_parameter(_2);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Attempts to return a mime/type for an HTTP response
 *
 * @param string extension
 * @return string Mime/type for the extension, or the value of DEFAULT_HTTP if not found
 */
PHP_METHOD(Phalconry_Http_Util_MimeType, getForHttp) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *extension_param = NULL, *_0;
	zval *extension = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &extension_param);

	if (unlikely(Z_TYPE_P(extension_param) != IS_STRING && Z_TYPE_P(extension_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'extension' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(extension_param) == IS_STRING)) {
		zephir_get_strval(extension, extension_param);
	} else {
		ZEPHIR_INIT_VAR(extension);
		ZVAL_EMPTY_STRING(extension);
	}


	ZEPHIR_INIT_VAR(_0);
	ZVAL_STRING(_0, "text/html", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_RETURN_CALL_SELF("get", NULL, 0, extension, _0);
	zephir_check_temp_parameter(_0);
	zephir_check_call_status();
	RETURN_MM();

}

