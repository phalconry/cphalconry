namespace Phalconry\Mvc;

use Phalconry\Config;

interface EnvironmentInterface
{

	/**
	 * Whether currently using command line.
	 *
	 * @return boolean
	 */
	public function isCli() -> boolean;

	/**
	 * Returns the environment name.
	 *
	 * @return string
	 */
	public function getEnvironment() -> string;

	/**
	 * Returns the timezone.
	 *
	 * @return string
	 */
	public function getTimezone() -> string;

	/**
	 * Sets the locale.
	 *
	 * @param string locale
	 * @return \Phalconry\Mvc\EnvironmentInterface
	 */
	public function setLocale(string! locale) -> <EnvironmentInterface>;

	/**
	 * Returns the locale name.
	 *
	 * @return string|null
	 */
	public function getLocale() -> string | null;

	/**
	 * Sets the directory paths.
	 *
	 * @param mixed paths Directory paths
	 * @return \Phalconry\Mvc\EnvironmentInterface
	 */
	public function setPaths(var paths) -> <EnvironmentInterface>;

	/**
	 * Returns the directory paths.
	 *
	 * @return \Phalcon\Registry|\Phalcon\Config
	 */
	public function getPaths();

	/**
	 * Sets a directory path by name.
	 *
	 * @param string name
	 * @param string path
	 * @return \Phalconry\Mvc\EnvironmentInterface
	 */
	public function setPath(string name, string path) -> <EnvironmentInterface>;

	/**
	 * Returns a directory path by name.
	 *
	 * @param string name
	 * @return string
	 */
	public function getPath(string name) -> string | null;

	/**
	 * Returns a Config object for a given section.
	 *
	 * @param string section Section name.
	 * @return \Phalconry\Config
	 *
	 * @throws \Phalconry\Exception if section exists but isn't a Config.
	 */
	public function getConfig(string section) -> <Config>;

    /**
     * Get an item using "dot" notation.
     *
     * @param  string  key
     * @param  mixed   defaultValue [Optional]
     * @return mixed
     */
    public function get(var key, var defaultValue = null) -> var;

    /**
     * Set an item using "dot" notation.
     *
     * @param  string  key
     * @param  mixed   defaultValue
     * @return mixed
     */
    public function set(var key, var value);

    /**
     * Check if an item exists using "dot" notation.
     *
     * @param  string  key
     * @return bool
     */
    public function has(var key) -> boolean;

}
