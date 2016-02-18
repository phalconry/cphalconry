namespace Phalconry\Mvc;

use Phalconry\Mvc\Module\ManagerInterface;
use Phalcon\Mvc\ModuleDefinitionInterface;

interface ModuleInterface extends ModuleDefinitionInterface
{

	/**
	 * Returns the module's controller namespace.
	 *
	 * @return string
	 */
	public function getControllerNamespace() -> string;

	/**
	 * Sets the module's name.
	 *
	 * @param string name
	 */
	public function setName(string name);

	/**
	 * Returns the module's name.
	 *
	 * @return string
	 */
	public function getName() -> string;

	/**
	 * Sets the module manager.
	 *
	 * @param \Phalconry\Mvc\Module\ManagerInterface manager
	 */
	public function setManager(<ManagerInterface> manager) -> void;

	/**
	 * Returns the module manager.
	 *
	 * @return \Phalconry\Mvc\Module\ManagerInterface
	 */
	public function getManager() -> <ManagerInterface>;

	/**
	 * Sets the application.
	 *
	 * @param \Phalconry\Mvc\ApplicationInterface app
	 */
	public function setApp(<ApplicationInterface> app);

	/**
	 * Returns the application.
	 *
	 * @return \Phalconry\Mvc\ApplicationInterface
	 */
	public function getApp() -> <ApplicationInterface>;

	/**
	 * Checks whether the module is loaded.
	 *
	 * @return boolean
	 */
	public function isLoaded() -> boolean;

	/**
	 * Checks whether the module is primary.
	 *
	 * @return boolean
	 */
	public function isPrimary() -> boolean;

	/**
	 * Checks whether the module is the default.
	 *
	 * @return boolean
	 */
	public function isDefault() -> boolean;

}
