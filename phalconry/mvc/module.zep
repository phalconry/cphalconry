namespace Phalconry\Mvc;

use Phalcon\Di\InjectionAwareInterface;
use Phalcon\DiInterface;
use Phalconry\Mvc\Module\ManagerInterface;

abstract class Module implements ModuleInterface, InjectionAwareInterface
{

	/**
	 * Dependency injector.
	 *
	 * @param \Phalcon\DiInterface
	 */
	protected _dependencyInjector;

	/**
	 * Module name.
	 *
	 * @var string
	 */
	protected _name;

	/**
	 * Application.
	 *
	 * @var \Phalconry\Mvc\ApplicationInterface
	 */
	protected _application;

	/**
	 * Module manager.
	 *
	 * @var \Phalconry\Mvc\Module\ManagerInterface
	 */
	protected _manager;

	/**
	 * Sets the dependency injector.
	 *
	 * @param \Phalcon\DiInterface di
	 */
	public function setDI(<DiInterface> di) -> void
	{
		let this->_dependencyInjector = di;
	}

	/**
	 * Returns the dependency injector.
	 *
	 * @return \Phalcon\DiInterface
	 */
	public function getDI() -> <DiInterface>
	{
		return this->_dependencyInjector;
	}

	/**
	 * Sets the module's name.
	 *
	 * @param string name
	 */
	public function setName(string! name) -> void
	{
		let this->_name = name;
	}

	/**
	 * Returns the module's name.
	 *
	 * @return string
	 */
	public function getName() -> string
	{
		return this->_name;
	}

	/**
	 * Sets the module manager.
	 *
	 * @param \Phalconry\Mvc\Module\ManagerInterface manager
	 */
	public function setManager(<ManagerInterface> manager) -> void
	{
		let this->_manager = manager;
	}

	/**
	 * Returns the module manager.
	 *
	 * @return \Phalconry\Mvc\Module\ManagerInterface
	 */
	public function getManager() -> <ManagerInterface>
	{
		return this->_manager;
	}

	/**
	 * Sets the application.
	 *
	 * @param \Phalconry\Mvc\ApplicationInterface app
	 */
	public function setApp(<ApplicationInterface> app) -> void
	{
		let this->_application = app;
	}

	/**
	 * Returns the application.
	 *
	 * @return \Phalconry\Mvc\ApplicationInterface
	 */
	public function getApp() -> <ApplicationInterface>
	{
		return this->_application;
	}

	/**
	 * Checks whether the module is loaded.
	 *
	 * @return boolean
	 */
	public function isLoaded() -> boolean
	{
		return typeof this->_application == "object";
	}

	/**
	 * Checks whether the module is primary.
	 *
	 * @return boolean
	 */
	public function isPrimary() -> boolean
	{
		var manager;
		let manager = <ManagerInterface> this->_manager;

		if typeof manager != "object" {
			return false;
		}

		return manager->getPrimaryModuleName() === this->_name;
	}

	/**
	 * Checks whether the module is the default.
	 *
	 * @return boolean
	 */
	public function isDefault() -> boolean
	{
		var manager;
		let manager = <ManagerInterface> this->_manager;

		if typeof manager != "object" {
			return false;
		}

		return manager->getDefaultModuleName() === this->_name;
	}

	/**
	 * Registers the module autoloaders.
	 */
	public function registerAutoloaders(<DiInterface> di = null)
	{

	}

	/**
	 * Registers the module services.
	 */
	public function registerServices(<DiInterface> di)
	{

	}

}
