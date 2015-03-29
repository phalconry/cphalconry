namespace Phalconry\Mvc\Module;

use Phalcon\DI\Injectable;
use Phalcon\Registry;
use Phalcon\Mvc\Exception;
use Phalconry\Mvc\Module;
use InvalidArgumentException;

class Manager extends Injectable
{

    /**
     * Primary module name
     *
     * @var string
     */
    protected _primary;

    /**
     * Module registry
     *
     * @var \Phalcon\Registry
     */
    protected _registry;

    /**
     * Constructor.
     */
    public function __construct()
    {
        let this->_registry = new Registry();
    }

    /**
     * Sets a module in the registry
     *
     * @param \Phalconry\Mvc\Module $module
     */
    public function set(<Module> module) -> void
    {
        let this->_registry[module->getName()] = module;
    }

	/**
	 * Returns a module by name, or the primary module if no name is given
	 *
	 * @param string $name [Optional] Module name
	 * @return \Phalconry\Mvc\Module
	 */
    public function get(string name = null) -> <Module>
    {
        return "" == name ? this->getPrimary() : this->_registry[name];
    }

    /**
     * Sets the primary module in the registry
     *
     * @param \Phalconry\Mvc\Module $module
     * @throws \Phalcon\Mvc\Exception if primary module is already set
     */
    public function setPrimary(<Module> module) -> void
    {
        if typeof this->_primary == "string" {
            throw new Exception("Primary module already set");
        }

        this->set(module);

        let this->_primary = module->getName();
    }

	/**
	 * Returns the primary module
	 *
	 * @return \Phalconry\Mvc\Module
     * @throws \Phalcon\Mvc\Exception if primary module is not set
	 */
    public function getPrimary() -> <Module>
    {
        if typeof this->_primary != "string" {
            throw new Exception("No primary module set");
        }

        return this->_registry[this->_primary];
    }

	/**
	 * Loads a module
	 *
	 * @param string|\Phalconry\Mvc\Module $module
	 * @return \Phalconry\Mvc\Module
     * @throws \InvalidArgumentException if module is not a string or object
     * @throws \Phalcon\Mvc\Exception if module has already been loaded
	 */
	public function load(var module) -> <Module>
	{

		if typeof module == "string" {
            let module = this->create(module);
		}

		if typeof module != "object" {
            throw new InvalidArgumentException("Invalid module given");
		}

        if module->isLoaded() {
            throw new Exception("Cannot reload module");
        }

		this->set(module);

        var di;
		let di = this->getDI();

		module->registerAutoloaders(di);
		module->registerServices(di);

		module->setApp(di->getShared("app"));
		module->onLoad();

		return module;
	}

	/**
	 * Whether a module has been loaded
	 *
	 * @param string|\Phalconry\Mvc\Module $module
	 * @return boolean
	 * @throws \InvalidArgumentException if not given a Module object or string
	 */
	public function isLoaded(var module) -> boolean
	{

		if typeof module == "object" {
			return module->isLoaded();
		}

		if typeof module == "string" {
            return isset this->_registry[module];
		}

        throw new InvalidArgumentException("Expecting string or Module");
	}

	/**
	 * Returns the name of a module from an object
	 *
	 * @param \Phalconry\Mvc\Module $module [Optional]
	 * @return string
     * @throws \Phalcon\Mvc\Exception if module name not found
	 */
	public function getName(<Module> module = null) -> string
	{
		if typeof module == "null" {
			return this->_primary;
		}

		var className, key, value;
		let className = get_class(module);

		for key, value in this->getDI()->getShared("app")->getModules() {
			if value["className"] === className {
				return key;
			}
		}

		throw new Exception("Invalid module name");
	}

    /**
     * Creates a module object from its name
     *
     * @param string $name Module name
     * @return \Phalconry\Mvc\Module
     * @throws \Phalcon\Mvc\Exception if module is not defined
     */
    protected function create(string! name) -> <Module>
    {
        var moduleList, className, moduleObject;

        let moduleList = this->getDI()->getShared("app")->getModules();

		if ! isset moduleList[name] {
			throw new Exception("Unknown module");
		}

    	let className = moduleList[name]["className"];
		let moduleObject = new {className}();

        moduleObject->setName(name);

        return moduleObject;
    }

}
