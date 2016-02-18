
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
#include "kernel/memory.h"
#include "kernel/exception.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/fcall.h"


ZEPHIR_INIT_CLASS(Phalconry_Events_GlobalManager) {

	ZEPHIR_REGISTER_CLASS_EX(Phalconry\\Events, GlobalManager, phalconry, events_globalmanager, zephir_get_internal_ce(SS("phalcon\\events\\manager") TSRMLS_CC), phalconry_events_globalmanager_method_entry, 0);

	/**
	 * @var boolean
	 */
	zend_declare_property_null(phalconry_events_globalmanager_ce, SL("_created"), ZEND_ACC_PROTECTED|ZEND_ACC_STATIC TSRMLS_CC);

	return SUCCESS;

}

/**
 * Protected constructor.
 */
PHP_METHOD(Phalconry_Events_GlobalManager, __construct) {



}

/**
 * Create the single GlobalManager instance.
 *
 * @return \Phalconry\Events\GlobalManager
 *
 * @throws \RuntimeException if called more than once per request.
 */
PHP_METHOD(Phalconry_Events_GlobalManager, create) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *_0;

	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(_0);
	zephir_read_static_property_ce(&_0, phalconry_events_globalmanager_ce, SL("_created") TSRMLS_CC);
	if (Z_TYPE_P(_0) != IS_NULL) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_RuntimeException, "Only one instance of the global events manager may exist.", "phalconry/events/globalmanager.zep", 29);
		return;
	}
	zephir_update_static_property_ce(phalconry_events_globalmanager_ce, SL("_created"), &(ZEPHIR_GLOBAL(global_true)) TSRMLS_CC);
	object_init_ex(return_value, phalconry_events_globalmanager_ce);
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 6);
	zephir_check_call_status();
	RETURN_MM();

}

