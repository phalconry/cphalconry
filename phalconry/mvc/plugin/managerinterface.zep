namespace Phalconry\Mvc\Plugin;

use Phalconry\Mvc\PluginInterface;

/**
 * Contract for a plugin manager.
 */
interface ManagerInterface
{

	/**
	 * Sets the plugin base namespace.
	 *
	 * @param string pluginNamespace
	 * @return void
	 */
	public function setNamespace(string! pluginNamespace) -> void;

	/**
	 * Returns the plugin base namespace.
	 *
	 * @return string
	 */
	public function getNamespace() -> string;

	/**
	 * Sets the plugin directory path.
	 *
	 * @param string dirPath
	 * @return void
	 *
	 * @throws \InvalidArgumentException if path is invalid.
	 */
	public function setPath(string! dirPath) -> void;

	/**
	 * Returns the plugin directory path.
	 *
	 * @return string|null
	 */
	public function getPath() -> string | null;

	/**
	 * Returns the classname of a plugin.
	 *
	 * @param string name
	 * @return string
	 */
	public function getPluginClassname(string! name) -> string;

	/**
	 * Builds the path to a plugin file.
	 *
	 * @param string name
	 * @return string|null
	 */
	public function getPluginFilePath(string! name) -> string | null;

	/**
	 * Registers a plugin as an object or by class.
	 *
	 * @param string|\Phalconry\Mvc\PluginInterface classname
	 * @return \Phalconry\Mvc\Plugin\ManagerInterface
	 */
	public function register(var classname) -> <ManagerInterface>;

	/**
	 * Registers a plugin object.
	 *
	 * @param \Phalconry\Mvc\PluginInterface plugin
	 * @return \Phalconry\Mvc\Plugin\ManagerInterface
	 */
	public function add(<PluginInterface> plugin) -> <ManagerInterface>;

	/**
	 * Returns a plugin by name.
	 *
	 * If the plugin has not been registered, it will be located.
	 *
	 * @param string name
	 * @return \Phalconry\Mvc\PluginInterface|null
	 */
	public function get(string! name) -> <PluginInterface> | null;

	/**
	 * Checks if a plugin has been registered.
	 *
	 * @param string|\Phalconry\Mvc\PluginInterface plugin
	 * @return boolean
	 */
	public function isRegistered(var plugin) -> boolean;

	/**
	 * Checks if a plugin has been loaded.
	 *
	 * @param string|\Phalconry\Mvc\PluginInterface plugin
	 * @return boolean
	 */
	public function isLoaded(var plugin) -> boolean;

	/**
	 * Loads a plugin.
	 *
	 * @param string|\Phalconry\Mvc\PluginInterface plugin
	 * @return \Phalconry\Mvc\PluginInterface
	 */
	public function load(var plugin) -> <PluginInterface>;

}
