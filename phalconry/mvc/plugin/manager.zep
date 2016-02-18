namespace Phalconry\Mvc\Plugin;

use Phalconry\Mvc\PluginInterface;
use Phalcon\Di\InjectionAwareInterface;
use Phalcon\Di\Injectable;
use InvalidArgumentException;

class Manager extends Injectable implements ManagerInterface
{

	/**
	 * @var string
	 */
	protected _namespace = "Plugin\\";

	/**
	 * @var string
	 */
	protected _path;

	/**
	 * @var array
	 */
	protected _plugins = [];

	/**
	 * @var array
	 */
	protected _loaded = [];

	/**
	 * Sets the plugin base namespace.
	 *
	 * @param string namespace
	 * @return void
	 */
	public function setNamespace(string! pluginNamespace) -> void
    {
		let this->_namespace = rtrim(pluginNamespace, "\\") . "\\";
	}

	/**
	 * Returns the plugin base namespace.
	 *
	 * Default is "Plugin\"
	 *
	 * @return string
	 */
	public function getNamespace() -> string
    {
		return this->_namespace;
	}

	/**
	 * Sets the plugin directory path.
	 *
	 * @param string dirPath
	 * @return void
	 */
	public function setPath(string! dirPath) -> void
    {
        var realpath;
        let realpath = realpath(dirPath);

		if ! realpath {
			throw new InvalidArgumentException("Invalid plugins directory: " . dirPath);
		}

		let this->_path = realpath . DIRECTORY_SEPARATOR;
	}

	/**
	 * Returns the plugin directory path.
	 *
	 * @return string|null
	 */
	public function getPath() -> string | null
    {
		return this->_path;
	}

	/**
	 * Returns the classname of a plugin.
	 *
	 * @param string name
	 * @return string
	 */
	public function getPluginClassname(string! name) -> string
    {
        var ucName;
        let ucName = ucfirst(name);

        return this->_namespace . ucName . "\\" . ucName . "Plugin";
	}

	/**
	 * Builds the path to a plugin file.
	 *
	 * @param string name
	 * @return string|null
	 */
	public function getPluginFilePath(string! name) -> string | null
    {
		if typeof this->_path != "string" {
			return null;
		}

        var classPath;
		let classPath = substr(this->getPluginClassname(name), strlen(this->_namespace));

		return this->_path . str_replace("\\", "/", classPath) . ".php";
	}

	/**
	 * Registers a plugin as an object or by class.
	 *
	 * @param string|\Phalconry\Mvc\PluginInterface classname
	 * @return \Phalconry\Mvc\Plugin\ManagerInterface
	 *
	 * @throws \InvalidArgumentException if plugin is not string or PluginInterface.
	 * @throws \Phalconry\Mvc\Plugin\Exception if plugin class cannot be found.
	 */
	public function register(var classname) -> <ManagerInterface>
    {
        if typeof classname == "object" {

            if (classname instanceof \Closure) {
                let classname = call_user_func(classname, this);
            }

            if ! (classname instanceof PluginInterface) {
                throw new InvalidArgumentException("Invalid plugin object");
            }

			this->add(classname);

        } else {

			if typeof classname != "string" {
				throw new InvalidArgumentException("Expecting string or PluginInterface, given: " . gettype(classname));
			}

			if ! class_exists(classname) {
				throw new Exception("Could not locate plugin class: " . classname);
			}

			this->add(new {classname}());
		}

        return this;
	}

	/**
	 * Registers a plugin object.
	 *
	 * @param \Phalconry\Mvc\PluginInterface plugin
	 * @return \Phalconry\Mvc\Plugin\ManagerInterface
	 */
	public function add(<PluginInterface> plugin) -> <ManagerInterface>
    {
		let this->_plugins[plugin->getName()] = plugin;
        return this;
	}

	/**
	 * Returns a plugin by name.
	 *
	 * If the plugin has not been registered, it will be located.
	 *
	 * @param string name
	 * @return \Phalconry\Mvc\PluginInterface
	 */
	public function get(string! name) -> <PluginInterface> | null
    {
        var plugin;

        if fetch plugin, this->_plugins[name] {
            return plugin;
        }

        let plugin = this->locatePlugin(name);

		if typeof plugin == "object" {
			this->add(plugin);
			return plugin;
		}

		return null;
	}

	/**
	 * Checks if a plugin has been registered.
	 *
	 * @param string|\Phalconry\Mvc\PluginInterface plugin
	 * @return boolean
	 */
	public function isRegistered(var plugin) -> boolean
    {
		if typeof plugin == "object" {
			return in_array(plugin, this->_plugins, true);
		}

		return isset this->_plugins[plugin];
	}

	/**
	 * Checks if a plugin has been loaded.
	 *
	 * @param string|\Phalconry\Mvc\PluginInterface plugin
	 * @return boolean
	 */
	public function isLoaded(var plugin) -> boolean
    {
		if typeof plugin == "object" {

			if ! this->isRegistered(plugin) {
				this->add(plugin);
				return false;
			}

			return isset this->_loaded[plugin->getName()];
		}

		return isset this->_loaded[plugin];
	}

	/**
	 * Loads a plugin.
	 *
	 * @param string|\Phalconry\Mvc\PluginInterface plugin
	 * @return \Phalconry\Mvc\PluginInterface
	 */
	public function load(var plugin) -> <PluginInterface>
    {
        var pluginObject, dependencyInjector, eventsManager;

		if typeof plugin == "object" {
            let pluginObject = plugin;
		} else {
        	let pluginObject = this->get(plugin);
            if typeof pluginObject != "object" {
				throw new Exception("Could not locate plugin: " . plugin);
			}
		}

		if this->isLoaded(pluginObject) {
			throw new Exception("Cannot reload plugin: " . pluginObject->getName());
		}

        let dependencyInjector = this->getDI();
		let eventsManager = this->getEventsManager();

		pluginObject->setManager(this);

		if (pluginObject instanceof InjectionAwareInterface) {
			pluginObject->setDI(dependencyInjector);
		}

		if typeof eventsManager == "object" {
			eventsManager->fire("plugins:beforeLoad", this, pluginObject);
		}

		pluginObject->load(dependencyInjector);

		if typeof eventsManager == "object" {
			eventsManager->fire("plugins:afterLoad", this, pluginObject);
		}

		let this->_loaded[pluginObject->getName()] = true;

		return pluginObject;
	}

	/**
	 * Locates a plugin in the plugin directory.
	 *
	 * @param string name
	 * @return \Phalconry\Mvc\PluginInterface|null
	 *
	 * @throws \Phalconry\Mvc\Plugin\Exception if an invalid plugin is injected.
	 */
	protected function locatePlugin(string! name) -> <PluginInterface> | null
    {
        var filepath, classname, dependencyInjector, plugin;

		let filepath = this->getPluginFilePath(name);
        let classname = this->getPluginClassname(name);

        if typeof filepath == "string" {

    		if file_exists(filepath) {

        		require filepath;

                if class_exists(classname, false) {
                    return new {classname}();
                }
    		}
        }

        let dependencyInjector = this->getDI();

        if typeof dependencyInjector == "object" {

            if dependencyInjector->has(name . "Plugin") {
                let plugin = dependencyInjector->getShared(name . "Plugin");
            } else {
                let plugin = dependencyInjector->get(classname);
            }

            if typeof plugin == "object" {

                if (plugin instanceof PluginInterface) {
                    return plugin;
                }

                throw new Exception("Invalid injected plugin: " . name);
            }
        }

        return null;
	}

}
