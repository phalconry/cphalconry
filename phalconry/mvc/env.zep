namespace Phalconry\Mvc;

use Phalcon\Config;
use Phalcon\Registry;

class Env extends Config
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
			let config["paths"] = new Registry();
		}

		parent::__construct(config);

		// Set locale
		setlocale(LC_ALL, config["locale"]);

		// Set timezone
		date_default_timezone_set(config["timezone"]);
	}

	/**
	 * Sets the environment name
	 *
	 * @param string env
	 * @return \Phalconry\Mvc\Env
	 */
	public function setEnvironment(string! env) -> <Env>
	{
		let this->env = env;

		return this;
	}

	/**
	 * Returns the environment name
	 *
	 * @return string
	 */
	public function getEnvironment() -> string
	{
		return this->env;
	}

	/**
	 * Sets the timezone
	 *
	 * @param string timezone
	 * @return \Phalconry\Mvc\Env
	 */
	public function setTimezone(string! timezone) -> <Env>
	{
		let this->timezone = timezone;

		return this;
	}

	/**
	 * Returns the timezone
	 *
	 * @return string
	 */
	public function getTimezone() -> string
	{
		return this->timezone;
	}

	/**
	 * Sets the locale
	 *
	 * @param string locale
	 * @return \Phalconry\Mvc\Env
	 */
	public function setLocale(string! locale) -> <Env>
	{
		let this->locale = locale;

		return this;
	}

	/**
	 * Returns the environment name
	 *
	 * @return string
	 */
	public function getLocale() -> string
	{
		return this->locale;
	}

	/**
	 * Sets the directory paths
	 *
	 * @param array $paths Array of directory paths
	 * @return \Phalconry\Mvc\Env
	 */
	public function setPaths(array paths) -> <Env>
	{
		var key, value;
		for key, value in paths {
			this->setPath(key, value);
		}

		return this;
	}

	/**
	 * Returns the directory path registry
	 *
	 * @return \Phalcon\Registry
	 */
	public function getPaths() -> <Registry>
	{
		return this->paths;
	}

	/**
	 * Sets a directory path by name
	 *
	 * @param string $name
	 * @param string $path
	 * @return \Phalconry\Mvc\Env
	 */
	public function setPath(string name, string path) -> <Env>
	{
		let this->paths[name] = realpath(path).DIRECTORY_SEPARATOR;

		return this;
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
		return (typeof this->{section} == "object") ? this->{section}->get(key) : null;
	}

	/**
	 * Magic call
	 */
	public function __call(string! func, array! args)
	{
		if ends_with(func, "Path") {
			return this->getPath(substr(func, 0, strlen(func) - 4));
		}
	}

}
