namespace Phalconry\Mvc\Module;

use Phalconry\Mvc\ModuleInterface;

interface ManagerInterface
{

    /**
     * Sets the name of the primary module.
     *
     * @param string moduleName
     */
    public function setPrimaryModuleName(string moduleName) -> void;

    /**
     * Returns the name of the primary module.
     *
     * @return string
     */
	public function getPrimaryModuleName() -> string;

    /**
     * Sets the name of the default module.
     *
     * @param string moduleName
     */
	public function setDefaultModuleName(string moduleName) -> void;

    /**
     * Returns the name of the default module.
     *
     * @return string
     */
	public function getDefaultModuleName() -> string;

    /**
     * Registers an array of module definitions.
     *
     * @param array definitions
     * @return void
     */
	public function registerModules(array! definitions) -> void;

    /**
     * Sets a module in the registry
     *
     * @param \Phalconry\Mvc\ModuleInterface module
     */
    public function addModule(<ModuleInterface> module) -> void;

	/**
	 * Returns a module by name, or the primary module if no name is given
	 *
	 * @param string name Module name
	 * @return \Phalconry\Mvc\ModuleInterface
	 */
    public function getModule(string name) -> <ModuleInterface> | null;

    /**
     * Checks whether a module exists
     *
     * @param string|\Phalconry\Mvc\ModuleInterface name
     * @return boolean
     */
    public function hasModule(var name) -> boolean;

	/**
	 * Returns the primary module
	 *
	 * @return \Phalconry\Mvc\ModuleInterface
	 *
     * @throws \Phalcon\Mvc\Exception if primary module is not set
	 */
    public function getPrimaryModule() -> <ModuleInterface>;

	/**
	 * Loads a module
	 *
	 * @param \Phalconry\Mvc\ModuleInterface module
	 * @return \Phalconry\Mvc\ModuleInterface
	 *
     * @throws \Phalcon\Mvc\Exception if module has already been loaded
	 */
	public function loadModule(<ModuleInterface> module) -> <ModuleInterface>;

	/**
	 * Whether a module has been loaded
	 *
	 * @param string|\Phalconry\Mvc\Module $module
	 * @return boolean
	 *
	 * @throws \InvalidArgumentException if not given a Module object or string
	 */
	public function isLoaded(var module) -> boolean;

}
