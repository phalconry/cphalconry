namespace Phalconry\Mvc;

use Phalcon\DiInterface;
use Phalcon\Config;
use Phalcon\Mvc\DispatcherInterface;
use Phalcon\Http\ResponseInterface;
use Phalcon\Di\InjectionAwareInterface;
use Phalcon\Events\EventsAwareInterface;
use Phalconry\Mvc\Application\BootstrapInterface;
use Phalconry\Mvc\Application\HandlerInterface;
use Phalconry\Mvc\Application\MiddlewareInterface;
use Phalconry\Di\ServiceProviderInterface;

interface ApplicationInterface extends InjectionAwareInterface, EventsAwareInterface
{

	/**
	 * Sets the bootstrap object.
	 *
	 * @param \Phalconry\Mvc\Application\BootstrapInterface bootstrap
	 */
	public function setBootstrap(<BootstrapInterface> bootstrap) -> void;

	/**
	 * Sets the request handler.
	 *
	 * @param \Phalconry\Mvc\Application\HandlerInterface handler
	 */
	public function setHandler(<HandlerInterface> handler) -> void;

	/**
	 * Returns the Env object or an item from it.
	 *
	 * @param string key [Optional]
	 * @return mixed|\Phalconry\Mvc\EnvironmentInterface
	 */
	public function env(var key = null) -> <EnvironmentInterface> | var | null;

	/**
	 * Returns the Env object.
	 *
	 * @return \Phalconry\Mvc\EnvironmentInterface
	 */
	public function getEnvironment() -> <EnvironmentInterface>;

	/**
	 * Returns the application Config object.
	 *
	 * @return \Phalcon\Config
	 */
	public function getConfig() -> <Config>;

	/**
	 * Returns the module manager.
	 *
	 * @return Phalconry\Mvc\Module\ManagerInterface
	 */
	public function getModuleManager() -> <Module\ManagerInterface>;

	/**
	 * Returns the primary module.
	 *
	 * @return \Phalconry\Mvc\ModuleInterface
	 */
	public function getPrimaryModule() -> <ModuleInterface>;

	/**
	 * Returns the dispatcher.
	 *
	 * @return \Phalcon\DispatcherInterface
	 */
	public function getDispatcher() -> <DispatcherInterface>;

	/**
	 * Loads a service through its provider.
	 *
	 * @param \Phalconry\Di\ServiceProviderInterface provider
	 * @return \Phalconry\Mvc\ApplicationInterface
	 */
	public function loadService(<ServiceProviderInterface> provider) -> <ApplicationInterface>;

	/**
	 * Loads an array of service providers.
	 *
	 * @param array providers
	 * @return \Phalconry\Mvc\ApplicationInterface
	 */
	public function loadServices(array! providers) -> <ApplicationInterface>;

	/**
	 * Bootstraps the application.
	 *
	 * @return void
	 */
	public function bootstrap() -> void;

	/**
	 * Handles the request and returns a response.
	 *
	 * @param string uri [Optional]
	 * @return mixed|\Phalcon\Http\ResponseInterface|boolean
	 */
	public function handle(var uri = null) -> var | <ResponseInterface> | boolean;

	/**
	 * Sends the response.
	 *
	 * @param mixed|\Phalcon\Http\ResponseInterface response
	 */
	public function respond(var response = null) -> void;

	/**
	 * Checks whether the application has booted.
	 *
	 * @return boolean
	 */
	public function isBooted() -> boolean;

}
