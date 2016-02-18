namespace Phalconry\Mvc;

use Phalcon\Di\Injectable;
use Phalcon\Config;
use Phalconry\Mvc\Plugin\ManagerInterface;
use ReflectionClass;

abstract class Plugin extends Injectable implements PluginInterface
{

	/**
	 * @var string
	 */
	protected _path;

	/**
	 * @var \Phalconry\Mvc\Plugin\Manager
	 */
	protected _manager;

	/**
	 * @var \Phalcon\Config
	 */
	protected _config;

	/**
	 * Returns the plugin's name.
	 *
	 * @return string
	 */
	public function getName() -> string
    {
		return strtolower(basename(this->getPath()));
	}

	/**
	 * Returns the path to the plugin's directory.
	 *
	 * @return string
	 */
	public function getPath() -> string
    {
        var reflection;

		if typeof this->_path != "string" {
			let reflection = new ReflectionClass(get_class(this));
			let this->_path = dirname(reflection->getFileName());
		}

		return this->_path;
	}

	/**
	 * Sets the plugins manager.
	 *
	 * @param \Phalconry\Mvc\Plugin\ManagerInterface manager
	 * @return void
	 */
	public function setManager(<ManagerInterface> manager) -> void
    {
		let this->_manager = manager;
	}

	/**
	 * Returns the plugins manager.
	 *
	 * @return \Phalconry\Mvc\Plugin\ManagerInterface
	 */
	public function getManager() -> <ManagerInterface>
    {
		return this->_manager;
	}

	/**
	 * Returns the plugin's Config object.
	 *
	 * @return \Phalcon\Config|null
	 */
	public function getConfig() -> <Config> | null
    {
        var config, filepath;

        let config = this->_config;

		if typeof config != "object" {

			let filepath = this->getPath() . "/config/config.php";

			if file_exists(filepath) {
				let config = require filepath;
                let this->_config = config;
			}
		}

		return config;
	}

	/**
	 * Checks whether the plugin is loaded.
	 *
	 * @return boolean
	 */
	public function isLoaded() -> boolean
    {
        var manager;
        let manager = this->_manager;

		if typeof manager != "object" {
			return false;
		}

		return manager->isLoaded(this);
	}

}
