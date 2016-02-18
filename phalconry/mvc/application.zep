namespace Phalconry\Mvc;

use Phalcon\DiInterface;
use Phalcon\Config;
use Phalcon\Di\Injectable;
use Phalcon\Di\FactoryDefault;
use Phalcon\Http\ResponseInterface;
use Phalcon\Mvc\DispatcherInterface;
use Phalcon\Events\ManagerInterface as EventsManagerInterface;
use Phalconry\Mvc\Application\BootstrapInterface;
use Phalconry\Mvc\Application\HandlerInterface;
use Phalconry\Mvc\Application\Bootstrap;
use Phalconry\Mvc\Application\Handler;
use Phalconry\Mvc\Application\Exception;
use Phalconry\Di\ServiceProviderInterface;

class Application implements ApplicationInterface
{

	/**
	 * Dependency injection container.
	 *
	 * @var \Phalcon\DiInterface
	 */
	protected _dependencyInjector;

	/**
	 * Events manager.
	 *
	 * @var \Phalcon\Events\ManagerInterface
	 */
	protected _eventsManager;

	/**
	 * Application bootstrap.
	 *
	 * @var \Phalconry\Mvc\Application\BootstrapInterface
	 */
	protected _bootstrap;

	/**
	 * Main request handler.
	 *
	 * @var \Phalconry\Mvc\Application\HandlerInterface
	 */
	protected _handler;

	/**
	 * Whether the app has been booted.
	 *
	 * @var boolean
	 */
	protected _booted = false;

	/**
	 * Application constructor.
	 *
	 * @param \Phalcon\DiInterface di [Optional]
	 * @param \Phalconry\Mvc\EnvironmentInterface env [Optional]
	 */
	public function __construct(<DiInterface> di = null, <EnvironmentInterface> env = null)
	{
		if typeof di != "object" {
			let di = new FactoryDefault();
		}

		if typeof env == "object" {
			di->setShared("env", env);
		}

		di->setShared("app", this);

		this->setDI(di);
	}

	/**
	 * Sets the dependency injector
	 *
	 * @param \Phalcon\DiInterface dependencyInjector
	 */
	public function setDI(<DiInterface> dependencyInjector)
	{
		let this->_dependencyInjector = dependencyInjector;
	}

	/**
	 * Returns the internal dependency injector
	 *
	 * @return \Phalcon\DiInterface
	 */
	public function getDI() -> <DiInterface>
	{
		return this->_dependencyInjector;
	}

	/**
	 * Sets the events manager.
	 *
	 * @param \Phalcon\Events\ManagerInterface eventsManager
	 */
	public function setEventsManager(<EventsManagerInterface> eventsManager)
	{
		let this->_eventsManager = eventsManager;
	}

	/**
	 * Returns the internal event manager.
	 *
	 * @return \Phalcon\Events\ManagerInterface
	 */
	public function getEventsManager() -> <EventsManagerInterface>
	{
		return this->_eventsManager;
	}

	/**
	 * Returns the module manager.
	 *
	 * @return \Phalconry\Mvc\Module\ManagerInterface
	 */
	public function getModuleManager() -> <Module\ManagerInterface>
	{
		return this->getDI()->getShared("moduleManager");
	}

	/**
	 * Returns the primary module.
	 *
	 * @return \Phalconry\Mvc\ModuleInterface
	 */
	public function getPrimaryModule() -> <ModuleInterface>
	{
		return this->getModuleManager()->getPrimaryModule();
	}

	/**
	 * Returns the dispatcher.
	 *
	 * @return \Phalcon\Mvc\DispatcherInterface
	 */
	public function getDispatcher() -> <DispatcherInterface>
	{
		return this->getDI()->getShared("dispatcher");
	}

	/**
	 * Returns the Env object.
	 *
	 * @return \Phalconry\Mvc\EnvironmentInterface
	 */
	public function getEnvironment() -> <EnvironmentInterface>
	{
		return this->getDI()->getShared("env");
	}

	/**
	 * Returns the application Config object.
	 *
	 * @return \Phalcon\Config
	 */
	public function getConfig() -> <Config>
	{
		var env;
		let env = this->getEnvironment();

		if ! env->has("application") {
			env->set("application", new Config());
		}

		return env->get("application");
	}

	/**
	 * Returns the global environment instance or an item from it
	 *
	 * @param string key [Optional] Item to fetch from Env. If omitted, the Env object is returned.
	 * @return \Phalconry\Mvc\EnvironmentInterface|\Phalcon\Config|mixed
	 */
	public function env(var key = null)
	{
		if typeof key == "null" {
			return this->getEnvironment();
		}

		return this->getEnvironment()->get(key);
	}

	/**
	 * Returns a directory path
	 *
	 * @param string name Path name.
	 * @return string
	 */
	public function getPath(string name) -> string | null
	{
		return this->getEnvironment()->getPath(name);
	}

	/**
	 * Sets a named directory path.
	 *
	 * @param string name Path name.
	 * @param string value Absolute directory path.
	 */
	public function setPath(string name, string value) -> void
	{
		this->getEnvironment()->setPath(name, value);
	}

	/**
	 * Sets the bootstrap object.
	 *
	 * @param \Phalconry\Mvc\Application\BootstrapInterface bootstrap
	 */
	public function setBootstrap(<BootstrapInterface> bootstrap) -> void
	{
		let this->_bootstrap = bootstrap;
	}

	/**
	 * Sets the request handler.
	 *
	 * @param \Phalconry\Mvc\Application\HandlerInterface handler
	 */
	public function setHandler(<HandlerInterface> handler) -> void
	{
		let this->_handler = handler;
	}

	/**
	 * Whether the application has booted.
	 *
	 * @return boolean
	 */
	public function isBooted() -> boolean
	{
		return this->_booted;
	}

	/**
	 * Loads a service through its provider.
	 *
	 * @param \Phalconry\Di\ServiceProviderInterface provider
	 * @return \Phalconry\Mvc\ApplicationInterface
	 */
	public function loadService(<ServiceProviderInterface> provider) -> <ApplicationInterface>
	{
		provider->register(this->getDI());
		return this;
	}

	/**
	 * Loads an array of service providers.
	 *
	 * @param array providers
	 * @return \Phalconry\Mvc\ApplicationInterface
	 */
	public function loadServices(array! providers) -> <ApplicationInterface>
	{
		var dependencyInjector, provider;

		let dependencyInjector = this->getDI();

		for provider in providers {
			provider->register(dependencyInjector);
		}

		return this;
	}

	/**
	 * Runs the application and sends the response.
	 *
	 * @return void
	 */
	public function run() -> void
	{
		var response;

		if ! this->isBooted() {
			this->bootstrap();
		}

		// this->handle(null) avoids errors in Zephir
		let response = this->handle(null);

		if typeof response == "object" {
			this->respond(response);
		}
	}

	/**
	 * Boot the application.
	 *
	 * @return boolean
	 */
	public function bootstrap() -> void
	{
		var dependencyInjector, bootstrap, eventsManager, eventsConfig;

		if this->_booted === true {
			throw new Exception("Application has already booted.");
		}

		let this->_booted = true;

		let dependencyInjector = this->getDI();
		let bootstrap = <BootstrapInterface> this->_bootstrap;

		// Locate or create bootstrap if necessary
		if typeof bootstrap != "object" {
			if dependencyInjector->has("bootstrap") {
				let bootstrap = dependencyInjector->get("bootstrap");
			} else {
				let bootstrap = new Bootstrap();
			}
		}

		// Bootstrap the application
		bootstrap->boot(this);

		let eventsManager = <EventsManagerInterface> this->_eventsManager;

        if typeof eventsManager != "object" {
			// Inject global events manager
			if ! dependencyInjector->has("events") {
				return;
			}
			let eventsManager = dependencyInjector->getShared("events");
			this->setEventsManager(eventsManager);
		}

		let eventsConfig = this->getConfig()->get("events");

		if typeof eventsConfig == "object" {
			if eventsConfig->get("attach", false) {
				// Attach application to own events
				eventsManager->attach("application", this);
			}
		}

		// Call application:boot event
		eventsManager->fire("application:boot", this);
	}

	/**
	 * Handles a MVC request
	 *
	 * @param string uri
	 * @return mixed|\Phalcon\Http\ResponseInterface|boolean
	 */
	public function handle(uri = null) -> var | <ResponseInterface> | boolean
	{
		var handler;
		let handler = <HandlerInterface> this->_handler;

		if typeof handler != "object" {
			let handler = new Handler(this);
		}

		return handler->handle(uri);
	}

	/**
	 * Sends the response.
	 *
	 * @param mixed|\Phalcon\Http\ResponseInterface response
	 */
	public function respond(var response = null)
	{
		var eventsManager;

		if typeof response == "object" {

			let eventsManager = this->getEventsManager();

			// Call beforeSendResponse event
			if typeof eventsManager == "object" {
	            eventsManager->fire("application:beforeSendResponse", this, response);
	        }

			// Send the response
			this->getDI()->getShared("responder")->respond(response);
		}
	}

}
