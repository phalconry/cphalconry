
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


ZEPHIR_INIT_CLASS(Phalconry_Mvc_EnvironmentInterface) {

	ZEPHIR_REGISTER_INTERFACE(Phalconry\\Mvc, EnvironmentInterface, phalconry, mvc_environmentinterface, phalconry_mvc_environmentinterface_method_entry);

	return SUCCESS;

}

/**
 * Whether currently using command line.
 *
 * @return boolean
 */
ZEPHIR_DOC_METHOD(Phalconry_Mvc_EnvironmentInterface, isCli);

/**
 * Returns the environment name.
 *
 * @return string
 */
ZEPHIR_DOC_METHOD(Phalconry_Mvc_EnvironmentInterface, getEnvironment);

/**
 * Returns the timezone.
 *
 * @return string
 */
ZEPHIR_DOC_METHOD(Phalconry_Mvc_EnvironmentInterface, getTimezone);

/**
 * Sets the locale.
 *
 * @param string locale
 * @return \Phalconry\Mvc\EnvironmentInterface
 */
ZEPHIR_DOC_METHOD(Phalconry_Mvc_EnvironmentInterface, setLocale);

/**
 * Returns the locale name.
 *
 * @return string|null
 */
ZEPHIR_DOC_METHOD(Phalconry_Mvc_EnvironmentInterface, getLocale);

/**
 * Sets the directory paths.
 *
 * @param mixed paths Directory paths
 * @return \Phalconry\Mvc\EnvironmentInterface
 */
ZEPHIR_DOC_METHOD(Phalconry_Mvc_EnvironmentInterface, setPaths);

/**
 * Returns the directory paths.
 *
 * @return \Phalcon\Registry|\Phalcon\Config
 */
ZEPHIR_DOC_METHOD(Phalconry_Mvc_EnvironmentInterface, getPaths);

/**
 * Sets a directory path by name.
 *
 * @param string name
 * @param string path
 * @return \Phalconry\Mvc\EnvironmentInterface
 */
ZEPHIR_DOC_METHOD(Phalconry_Mvc_EnvironmentInterface, setPath);

/**
 * Returns a directory path by name.
 *
 * @param string name
 * @return string
 */
ZEPHIR_DOC_METHOD(Phalconry_Mvc_EnvironmentInterface, getPath);

/**
 * Returns a Config object for a given section.
 *
 * @param string section Section name.
 * @return \Phalconry\Config
 *
 * @throws \Phalconry\Exception if section exists but isn't a Config.
 */
ZEPHIR_DOC_METHOD(Phalconry_Mvc_EnvironmentInterface, getConfig);

/**
 * Get an item using "dot" notation.
 *
 * @param  string  key
 * @param  mixed   defaultValue [Optional]
 * @return mixed
 */
ZEPHIR_DOC_METHOD(Phalconry_Mvc_EnvironmentInterface, get);

/**
 * Set an item using "dot" notation.
 *
 * @param  string  key
 * @param  mixed   defaultValue
 * @return mixed
 */
ZEPHIR_DOC_METHOD(Phalconry_Mvc_EnvironmentInterface, set);

/**
 * Check if an item exists using "dot" notation.
 *
 * @param  string  key
 * @return bool
 */
ZEPHIR_DOC_METHOD(Phalconry_Mvc_EnvironmentInterface, has);

