
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
#include "kernel/fcall.h"
#include "kernel/object.h"
#include "kernel/operators.h"
#include "kernel/memory.h"


ZEPHIR_INIT_CLASS(Phalconry_Mvc_Dispatcher) {

	ZEPHIR_REGISTER_CLASS_EX(Phalconry\\Mvc, Dispatcher, phalconry, mvc_dispatcher, zephir_get_internal_ce(SS("phalcon\\mvc\\dispatcher") TSRMLS_CC), phalconry_mvc_dispatcher_method_entry, 0);

	return SUCCESS;

}

PHP_METHOD(Phalconry_Mvc_Dispatcher, setDefaultNamespace) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *namespaceName_param = NULL;
	zval *namespaceName = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &namespaceName_param);

	zephir_get_strval(namespaceName, namespaceName_param);


	ZEPHIR_CALL_PARENT(NULL, phalconry_mvc_dispatcher_ce, this_ptr, "setdefaultnamespace", NULL, namespaceName);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, SL("_namespaceName"), namespaceName TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

