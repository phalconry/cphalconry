namespace Phalconry\Mvc;

use Phalcon\Mvc\ModuleDefinitionInterface;
use Phalcon\Mvc\View;
use Phalcon\DiInterface;
use Phalcon\DI as DiContainer;
use RuntimeException;

/**
 * Module
 *
 * This class is "pseudo-DI-aware" in that its getDI() method returns the
 * default DI container using DI::getDefault()
 */
abstract class Module implements ModuleDefinitionInterface
{

	/**
	 * The module name
	 * @var string
	 */
	protected _name;

	/**
	 * The application
	 * @var \Phalconry\Mvc\Application
	 */
	protected _application;

	/**
	 * Returns the DI container
	 *
	 * @return \Phalcon\DiInterface
	 */
	public function getDI() -> <DiInterface>
	{
		return DiContainer::getDefault();
	}

	/**
	 * Returns a shared item from the DI container
	 *
	 * @param string $key
	 * @return mixed
	 */
	public function __get(string! key)
	{
		return this->getDI()->getShared(key);
	}

	/**
	 * Sets the module name
	 *
	 * @param string $name
	 */
	public function setName(string! name) -> void
	{
		let this->_name = name;
	}

	/**
	 * Returns the module name
	 *
	 * @return string
	 */
	public function getName() -> string
	{
		return this->_name;
	}

	/**
	 * Sets the application
	 *
	 * @param \Phalconry\Mvc\Application $app
	 */
	public function setApp(<Application> app) -> void
	{
		let this->_application = app;
	}

	/**
	 * Returns the application
	 *
	 * @return \Phalconry\Mvc\Application
	 * @throws \RuntimeException if app is not set
	 */
	public function getApp() -> <Application>
	{

		if typeof this->_application == "null" {
			throw new RuntimeException("Module is not active");
		}

		return this->_application;
	}

	/**
	 * Whether the module has been loaded
	 *
	 * @return boolean
	 */
	public function isLoaded() -> boolean
	{
		return (typeof this->_application == "object");
	}

	/**
	 * Whether this is the primary module
	 *
	 * @return boolean
	 */
	public function isPrimary() -> boolean
	{

		if typeof this->_application == "object" {
			return this === this->_application->getModuleObject();
		}

		return false;
	}

	/**
	 * Whether this is the default module
	 *
	 * @return boolean
	 */
	public function isDefault() -> boolean
	{

		if typeof this->_application == "object" {
			return this->_name === this->_application->getDefaultModule();
		}

		return false;
	}

	/**
	 * Returns the default namespace to use for controllers
	 *
	 * Called in Application on "application:afterStartModule"
	 *
	 * @return string
	 */
	abstract public function getControllerNamespace();

	/**
	 * Register separate autoloaders for the module, if any
	 *
	 * @param \Phalcon\DiInterface
	 */
	public function registerAutoloaders(<DiInterface> di = null) -> void
	{

	}

	/**
	 * Register services for the module
	 *
	 * @param \Phalcon\DiInterface
	 */
	public function registerServices(<DiInterface> di = null) -> void
	{

	}

	/**
	 * Allows the module to perform start-up tasks
	 *
	 * Called in Application on "application:afterStartModule"
	 */
	public function onLoad() -> void
	{

	}

	/**
	 * Allows the PRIMARY module to perform additional operations when responding with a view
	 *
	 * Called in Application on "application:afterHandleRequest"
	 * ONLY IF respondse mode is 'view' - otherwise, the view is disabled
	 *
	 * @param \Phalcon\Mvc\View $view
	 */
	public function onView(<View> view) -> void
	{

	}

}
