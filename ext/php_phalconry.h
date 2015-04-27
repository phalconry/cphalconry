
/* This file was generated automatically by Zephir do not modify it! */

#ifndef PHP_PHALCONRY_H
#define PHP_PHALCONRY_H 1

#ifdef PHP_WIN32
#define ZEPHIR_RELEASE 1
#endif

#include "kernel/globals.h"

#define PHP_PHALCONRY_NAME        "phalconry"
#define PHP_PHALCONRY_VERSION     "0.0.4"
#define PHP_PHALCONRY_EXTNAME     "phalconry"
#define PHP_PHALCONRY_AUTHOR      "wells5609"
#define PHP_PHALCONRY_ZEPVERSION  "0.6.0a"
#define PHP_PHALCONRY_DESCRIPTION "A PHP extension for PhalconPHP providing additional MVC components and an HTTP client library."



ZEND_BEGIN_MODULE_GLOBALS(phalconry)

	int initialized;

	/* Memory */
	zephir_memory_entry *start_memory; /**< The first preallocated frame */
	zephir_memory_entry *end_memory; /**< The last preallocate frame */
	zephir_memory_entry *active_memory; /**< The current memory frame */

	/* Virtual Symbol Tables */
	zephir_symbol_table *active_symbol_table;

	/** Function cache */
	HashTable *fcache;

	/* Cache enabled */
	unsigned int cache_enabled;

	/* Max recursion control */
	unsigned int recursive_lock;

	/* Global constants */
	zval *global_true;
	zval *global_false;
	zval *global_null;
	
ZEND_END_MODULE_GLOBALS(phalconry)

#ifdef ZTS
#include "TSRM.h"
#endif

ZEND_EXTERN_MODULE_GLOBALS(phalconry)

#ifdef ZTS
	#define ZEPHIR_GLOBAL(v) TSRMG(phalconry_globals_id, zend_phalconry_globals *, v)
#else
	#define ZEPHIR_GLOBAL(v) (phalconry_globals.v)
#endif

#ifdef ZTS
	#define ZEPHIR_VGLOBAL ((zend_phalconry_globals *) (*((void ***) tsrm_ls))[TSRM_UNSHUFFLE_RSRC_ID(phalconry_globals_id)])
#else
	#define ZEPHIR_VGLOBAL &(phalconry_globals)
#endif

#define ZEPHIR_API ZEND_API

#define zephir_globals_def phalconry_globals
#define zend_zephir_globals_def zend_phalconry_globals

extern zend_module_entry phalconry_module_entry;
#define phpext_phalconry_ptr &phalconry_module_entry

#endif
