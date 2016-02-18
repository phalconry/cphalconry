namespace Phalconry\Mvc;

use Phalcon\Registry;
use Phalcon\Exception;
use Phalconry\Config;

class Env extends Config implements EnvironmentInterface
{

	/**
	 * Default environment identifier
	 *
	 * @var string
	 */
	const DEFAULT_ENVIRONMENT = "production";

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
	protected env;

	/**
	 * Timezone identifier
	 *
	 * @var string
	 */
	protected timezone;

	/**
	 * Named directory paths
	 *
	 * @var \Phalcon\Registry
	 */
	protected paths;

	/**
	 * Whether in command line mode.
	 *
	 * @var boolean
	 */
	protected cli;

	/**
	 * Constructor.
	 *
	 * @param array config
	 */
	public function __construct(array! config = []) -> void
	{
		var environment, timezone;

		if ! isset config["env"] {
			let environment = getenv("ENVIRONMENT");
			let config["env"] = environment ? environment : Env::DEFAULT_ENVIRONMENT;
		}

		if ! fetch timezone, config["timezone"] {
			let timezone = getenv("TZ");
			let config["timezone"] = timezone ? timezone : Env::DEFAULT_TIMEZONE;
		}

		let config["cli"] = php_sapi_name() === "cli";

		parent::__construct(config);

		date_default_timezone_set(timezone);

		if typeof this->paths == "null" {
			let this->paths = new Registry();
		}
	}

	/**
	 * Returns the environment name.
	 *
	 * @return string
	 */
	public function getEnvironment() -> string
	{
		return this->env;
	}

	/**
	 * Returns the timezone.
	 *
	 * @return string
	 */
	public function getTimezone() -> string
	{
		return this->timezone;
	}

	/**
	 * Sets the locale.
	 *
	 * @param string locale
	 * @return \Phalconry\Mvc\EnvironmentInterface
	 */
	public function setLocale(string! locale) -> <EnvironmentInterface>
	{
		this->offsetSet("locale", locale);

		setlocale(LC_ALL, locale);

		return this;
	}

	/**
	 * Returns the locale name.
	 *
	 * @return string
	 */
	public function getLocale() -> string | null
	{
		return this->offsetGet("locale");
	}

	/**
	 * Sets the directory paths.
	 *
	 * @param mixed paths Directory paths
	 * @return \Phalconry\Mvc\EnvironmentInterface
	 */
	public function setPaths(var paths) -> <EnvironmentInterface>
	{
		var key, value;
		for key, value in paths {
			this->setPath(key, value);
		}

		return this;
	}

	/**
	 * Returns the directory paths.
	 *
	 * @return \Phalcon\Registry
	 */
	public function getPaths() -> <Registry>
	{
		return this->paths;
	}

	/**
	 * Sets a directory path by name.
	 *
	 * @param string name
	 * @param string path
	 * @return \Phalconry\Mvc\EnvironmentInterface
	 */
	public function setPath(string! name, string! path) -> <EnvironmentInterface>
	{
		let this->paths[name] = realpath(path) . DIRECTORY_SEPARATOR;
		return this;
	}

	/**
	 * Returns a directory path by name.
	 *
	 * @param string name
	 * @return string
	 */
	public function getPath(string! name) -> string | null
	{
		return this->paths[name];
	}

	/**
	 * Returns a Config object for a given section.
	 *
	 * @param string section Section name.
	 * @return \Phalcon\Config
	 *
	 * @throws \Phalcon\Exception if section exists but isn't a Config.
	 */
	public function getConfig(string! section) -> <Config>
	{
		var config;

		if fetch config, this->{section} {

			if typeof config != "object" {
				throw new Exception("Config section '" . section . "' is not an object");
			}

		} else {
			let config = new Config();
			let this->{section} = config;
		}

		return config;
	}
	
	/**
	 * Whether currently using command line.
	 *
	 * @return boolean
	 */
	public function isCli() -> boolean
	{
		return this->cli;
	}

	/**
	 * Allow read-only access to protected properties.
	 *
	 * @param string key
	 * @return mixed
	 */
	public function __get(var key) -> var | null
	{
		let key = strval(key);

		if isset this->{key} {
			return this->{key};
		}

		return null;
	}

	/**
	 * Allow read-only access to protected properties.
	 *
	 * @param string key
	 * @return boolean
	 */
	public function __isset(var key) -> boolean
	{
		let key = strval(key);

		return isset this->{key};
	}

	/**
	 * Magic call
	 */
	public function __call(string! func, array! args)
	{
		if ends_with(func, "Path") {
			return this->getPath(substr(func, 0, strlen(func) - 4));
		}

		if starts_with(func, "get") {
			return this->offsetGet(lcfirst(substr(func, 3)));
		}
	}

	/**
	 * Returns the environment name.
	 *
	 * @return string
	 */
	public function __toString() -> string
	{
		return this->env;
	}

}
