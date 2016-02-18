namespace Phalconry\Mvc;

use Phalcon\DiInterface;
use Phalcon\Config;
use Phalconry\Mvc\Plugin\ManagerInterface;

interface PluginInterface
{

	/**
	 * Returns the plugin's name.
	 *
	 * @return string
	 */
	public function getName() -> string;

	/**
	 * Returns the path to the plugin's directory.
	 *
	 * @return string
	 */
	public function getPath() -> string;

	/**
	 * Sets the plugins manager.
	 *
	 * @param \Phalconry\Mvc\Plugin\ManagerInterface manager
	 * @return void
	 */
	public function setManager(<ManagerInterface> manager) -> void;

	/**
	 * Returns the plugins manager.
	 *
	 * @return \Phalconry\Mvc\Plugin\ManagerInterface
	 */
	public function getManager() -> <ManagerInterface>;

	/**
	 * Returns the plugin's Config object.
	 *
	 * @return \Phalcon\Config|null
	 */
	public function getConfig() -> <Config> | null;

	/**
	 * Checks whether the plugin is loaded.
	 *
	 * The simplest way to implement this method is to check if the manager exists.
	 *
	 * @return boolean
	 */
	public function isLoaded() -> boolean;

	/**
	 * Loads the plugin.
	 *
	 * @param \Phalcon\DiInterface di
	 *
	 * @throws \Phalconry\Mvc\Plugin\Exception
	 */
	public function load(<DiInterface> di);

}
