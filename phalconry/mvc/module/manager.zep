namespace Phalconry\Mvc\Module;

use Phalcon\Di\Injectable;
use Phalcon\Di\InjectionAwareInterface;
use Phalcon\Mvc\Application\Exception;
use Phalconry\Mvc\ModuleInterface;
use InvalidArgumentException;

class Manager extends Injectable implements ManagerInterface
{

    /**
     * Modules
     *
     * @var array
     */
    protected _modules = [];

    /**
     * Primary module name
     *
     * @var string
     */
    protected _primaryName;

    /**
     * Default module name
     *
     * @var string
     */
    protected _defaultName;

    /**
     * Sets the name of the primary module.
     *
     * @param string moduleName
     */
    public function setPrimaryModuleName(string moduleName) -> void
    {
        let this->_primaryName = moduleName;
    }

    /**
     * Returns the name of the primary module.
     *
     * @return string
     */
	public function getPrimaryModuleName() -> string
    {
		return this->_primaryName;
	}

    /**
     * Sets the name of the default module.
     *
     * @param string moduleName
     */
	public function setDefaultModuleName(string moduleName) -> void
    {
		let this->_defaultName = moduleName;
	}

    /**
     * Returns the name of the default module.
     *
     * @return string
     */
	public function getDefaultModuleName() -> string
    {
		return this->_defaultName;
	}

    /**
     * Registers an array of module definitions.
     *
     * @param array definitions
     * @return void
     */
	public function registerModules(array! definitions) -> void
    {
        var name, def, module;

		for name, def in definitions {

            let module = this->createFromDefinition(def);

			if typeof module == "object" {
				module->setName(name);
				module->setManager(this);
				this->addModule(module);
			}
		}
	}

    /**
     * Sets a module in the registry
     *
     * @param \Phalconry\Mvc\ModuleInterface module
     */
    public function addModule(<ModuleInterface> module) -> void
    {
        let this->_modules[module->getName()] = module;
    }

	/**
	 * Returns a module by name, or the primary module if no name is given
	 *
	 * @param string name Module name
	 * @return \Phalconry\Mvc\ModuleInterface
	 */
    public function getModule(string name) -> <ModuleInterface> | null
    {
        var module;

        if fetch module, this->_modules[name] {
            return module;
        }

        return null;
    }

    /**
     * Checks whether a module exists
     *
     * @param string|\Phalconry\Mvc\ModuleInterface name
     * @return boolean
     */
    public function hasModule(var name) -> boolean
    {
        if typeof name == "string" {
            return isset this->_modules[name];
        }

        return typeof name == "object" ? in_array(name, this->_modules, true) : false;
    }

	/**
	 * Returns the primary module
	 *
	 * @return \Phalconry\Mvc\ModuleInterface
	 *
     * @throws \Phalcon\Mvc\Exception if primary module is not set
	 */
    public function getPrimaryModule() -> <ModuleInterface>
    {
        if unlikely typeof this->_primaryName != "string" {
            throw new Exception("No primary module set");
        }

        return this->_modules[this->_primaryName];
    }

	/**
	 * Loads a module
	 *
	 * @param \Phalconry\Mvc\ModuleInterface module
	 * @return \Phalconry\Mvc\ModuleInterface
	 *
     * @throws \Phalcon\Mvc\Exception if module has already been loaded
	 */
	public function loadModule(<ModuleInterface> module) -> <ModuleInterface>
	{
        var moduleName, di;

        if module->isLoaded() {
            throw new Exception("Cannot reload module");
        }

        if ! this->hasModule(module) {
            this->addModule(module);
        }

        let moduleName = module->getName();
        let di = this->getDI();

        if typeof this->_primaryName != "string" {
            let this->_primaryName = moduleName;
        }

		if (module instanceof InjectionAwareInterface) {
			module->setDI(di);
		}

		module->setApp(di->getShared("app"));
        module->registerAutoloaders(di);
		module->registerServices(di);

        if method_exists(module, "onLoad") {
            module->{"onLoad"}();
        }

		return module;
	}

	/**
	 * Whether a module has been loaded
	 *
	 * @param string|\Phalconry\Mvc\Module $module
	 * @return boolean
	 *
	 * @throws \InvalidArgumentException if not given a Module object or string
	 */
	public function isLoaded(var module) -> boolean
	{

		if typeof module == "object" {
			return module->isLoaded();
		}

		if typeof module == "string" {

            var moduleObject;

            if fetch moduleObject, this->_modules[module] {
                return moduleObject->isLoaded();
            }

            return false;
		}

        throw new InvalidArgumentException("Expecting string or Module");
	}

    /**
     * Creates a module object from its name
     *
     * @param string $name Module name
     * @return \Phalconry\Mvc\ModuleInterface
     * @throws \Phalcon\Mvc\Exception if module is not defined
     */
    protected function createFromDefinition(var definition) -> <ModuleInterface>
    {
        var di, className, filePath, moduleObject;

        let di = this->getDI();

        if typeof definition == "array" {

            if !fetch className, definition["className"] {
                let className = "Module";
            }

            if fetch filePath, definition["path"] {
                if ! class_exists(className, false) {
                    if file_exists(filePath) {
                        require filePath;
                    } else {
                        throw new Exception("Invalid module file path: " . filePath);
                    }
                }
            }

            let moduleObject = di->get(className);

        } else {

            if ! (definition instanceof \Closure) {
                throw new Exception("Invalid module definition.");
            }

            let moduleObject = call_user_func(definition, di);
        }

        return moduleObject;
    }

}
