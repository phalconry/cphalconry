
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
#include "kernel/fcall.h"
#include "kernel/object.h"
#include "kernel/exception.h"


/**
 * Represents an HTTP message
 */
ZEPHIR_INIT_CLASS(Phalconry_Http_Client_Message) {

	ZEPHIR_REGISTER_CLASS(Phalconry\\Http\\Client, Message, phalconry, http_client_message, phalconry_http_client_message_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	/**
	 * The message's header object
	 *
	 * @var \Phalconry\Http\Client\Header
	 */
	zend_declare_property_null(phalconry_http_client_message_ce, SL("header"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * The message's parent message.
	 *
	 * @var \Phalconry\Http\Client\Message
	 */
	zend_declare_property_null(phalconry_http_client_message_ce, SL("parentMessage"), ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

/**
 * Constructor.
 */
PHP_METHOD(Phalconry_Http_Client_Message, __construct) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *_0;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(_0);
	object_init_ex(_0, phalconry_http_client_header_ce);
	ZEPHIR_CALL_METHOD(NULL, _0, "__construct", NULL);
	zephir_check_call_status();
	zephir_update_property_this(this_ptr, SL("header"), _0 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

/**
 * Returns the header object, or a specific header value if a name is given
 *
 * @param string name [Optional]
 * @return \Phalconry\Http\Client\Header|string|null
 */
PHP_METHOD(Phalconry_Http_Client_Message, getHeader) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *name = NULL, *_0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &name);

	if (!name) {
		name = ZEPHIR_GLOBAL(global_null);
	}


	if (Z_TYPE_P(name) == IS_STRING) {
		_0 = zephir_fetch_nproperty_this(this_ptr, SL("header"), PH_NOISY_CC);
		ZEPHIR_RETURN_CALL_METHOD(_0, "get", NULL, name);
		zephir_check_call_status();
		RETURN_MM();
	}
	RETURN_MM_MEMBER(this_ptr, "header");

}

/**
 * Returns the message's parent message, if any
 *
 * @return \Phalconry\Http\Client\Message|null
 */
PHP_METHOD(Phalconry_Http_Client_Message, getParent) {


	RETURN_MEMBER(this_ptr, "parentMessage");

}

/**
 * Whether the message has a parent message
 *
 * @return boolean
 */
PHP_METHOD(Phalconry_Http_Client_Message, hasParent) {

	zval *_0;

	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(_0);
	zephir_read_property_this(&_0, this_ptr, SL("parentMessage"), PH_NOISY_CC);
	RETURN_MM_BOOL(Z_TYPE_P(_0) == IS_OBJECT);

}

/**
 * Sets the message's parent message
 *
 * @param \Phalconry\Http\Client\Message parentMessage
 */
PHP_METHOD(Phalconry_Http_Client_Message, setParent) {

	zval *parentMessage;

	zephir_fetch_params(0, 1, 0, &parentMessage);



	if (!(zephir_instance_of_ev(parentMessage, phalconry_http_client_message_ce TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STRW(spl_ce_InvalidArgumentException, "Parameter 'parentMessage' must be an instance of 'Phalconry\\Http\\Client\\Message'", "", 0);
		return;
	}
	zephir_update_property_this(this_ptr, SL("parentMessage"), parentMessage TSRMLS_CC);

}

/**
 * Read-only access to properties
 *
 * @param string prop Property name
 * @throws \OutOfBoundsException if invalid property requested
 */
PHP_METHOD(Phalconry_Http_Client_Message, __get) {

	zval *prop, *_0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &prop);



	if (zephir_isset_property_zval(this_ptr, prop TSRMLS_CC)) {
		ZEPHIR_OBS_VAR(_0);
		zephir_read_property_zval(&_0, this_ptr, prop, PH_NOISY_CC);
		RETURN_CCTOR(_0);
	}
	ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_OutOfBoundsException, "Invalid property", "phalconry/http/client/message.zep", 90);
	return;

}

