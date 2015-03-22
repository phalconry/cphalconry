namespace Phalconry\Mvc;

class Env extends \Phalcon\Config
{

	/**
	 * Default environment identifier
	 *
	 * @var string
	 */
	const DEFAULT_ENVIRONMENT = "production";

	/**
	 * Default locale identifier
	 *
	 * @var string
	 */
	const DEFAULT_LOCALE = "en_US";

	/**
	 * Default timezone identifier
	 *
	 * @var string
	 */
	const DEFAULT_TIMEZONE = "UTC";

	/**
	 * Environment name
	 *
	 * @var string
	 */
	public env;

	/**
	 * Locale identifier
	 *
	 * @var string
	 */
	public locale;

	/**
	 * Timezone identifier
	 *
	 * @var string
	 */
	public timezone;

	/**
	 * Named directory paths
	 *
	 * @var \Phalcon\Registry
	 */
	public paths;

	/**
	 * Constructor
	 *
	 * @param array $config
	 */
	public function __construct(array! config = [])
	{

		if ! isset config["env"] {
			var _env;
			let _env = getenv("ENVIRONMENT");
			let config["env"] = _env ? _env : Env::DEFAULT_ENVIRONMENT;
		}

		if ! isset config["locale"] {
			var _locale;
			let _locale = getenv("LOCALE");
			let config["locale"] = _locale ? _locale : Env::DEFAULT_LOCALE;
		}

		if ! isset config["timezone"] {
			var _timezone;
			let _timezone = getenv("TZ");
			let config["timezone"] = _timezone ? _timezone : Env::DEFAULT_TIMEZONE;
		}

		if ! isset config["paths"] {
			let config["paths"] = new \Phalcon\Registry();
		}

		parent::__construct(config);

		// Set locale
		setlocale(LC_ALL, config["locale"]);

		// Set timezone
		date_default_timezone_set(config["timezone"]);
	}

	/**
	 * Sets the directory paths
	 *
	 * @param array $paths Array of directory paths
	 */
	public function setPaths(array paths) -> void
	{
		var key, value;
		for key, value in paths {
			this->setPath(key, value);
		}
	}

	/**
	 * Returns the directory path registry
	 *
	 * @return \Phalcon\Registry
	 */
	public function getPaths() -> <\Phalcon\Registry>
	{
		return this->paths;
	}

	/**
	 * Sets a directory path by name
	 *
	 * @param string $name
	 * @param string $path
	 */
	public function setPath(string name, string path) -> void
	{
		let this->paths[name] = realpath(path).DIRECTORY_SEPARATOR;
	}

	/**
	 * Returns a directory path by name
	 *
	 * @param string $name
	 * @return string
	 */
	public function getPath(string name) -> string|null
	{
		return this->paths[name];
	}

	/**
	 * Returns an entry value from a given section.
	 *
	 * @param string $section Section name
	 * @param string $key Item key in section
	 * @return mixed Item value if exists, otherwise null
	 */
	public function getFrom(string section, string key)
	{
		return isset this[section] ? this[section][key] : null;
	}

}
