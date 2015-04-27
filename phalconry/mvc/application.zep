namespace Phalconry\Mvc;

use Phalcon\Registry;
use Phalcon\DiInterface;
use Phalcon\Loader;
use Phalcon\Events\Event;
use Phalcon\Events\Manager as EventsManager;
use Phalcon\DI\FactoryDefault;
use Phalcon\Mvc\Application\Exception;
use Phalconry\Mvc\Application\Bootstrap;

class Application extends \Phalcon\Mvc\Application
{

	/**
	 * Application constructor.
	 *
	 * @param \Phalcon\DiInterface $di [Optional]
	 * @param \Phalconry\Mvc\Env $env [Optional]
	 */
	public function __construct(<DiInterface> di = null, <Env> env = null)
	{
		var eventsManager;

		if typeof di == "null" {
			let di = new FactoryDefault();
		}

		di->setShared("app", this);

		if typeof env == "object" {
			di->setShared("env", env);
		}

		if ! di->has("moduleManager") {
			di->setShared("moduleManager", "Phalconry\\Mvc\\Module\\Manager");
		}

		if ! di->has("responder") {
			di->setShared("responder", "Phalconry\\Mvc\\Responder");
		}

		if ! di->has("view") {
			di->setShared("view", "Phalcon\\Mvc\\View");
		}

		if ! di->has("viewEvents") {
			di->setShared("viewEvents", "Phalcon\\Events\\Manager");
		}

		if ! di->has("hmvcRequest") {
			di->setShared("hmvcRequest", "Phalconry\\Mvc\\HmvcRequest");
		}

		if ! di->has("httpClient") {
			di->setShared("httpClient", "Phalconry\\Http\\Client");
		}

		let eventsManager = new EventsManager();

		eventsManager->attach("application", new Bootstrap());

		this->setEventsManager(eventsManager);

		parent::__construct(di);
	}

	/**
	 * Returns the global environment instance or an item from it
	 *
	 * @param string key [Optional] Item to fetch from Env. If omitted, the Env object is returned.
	 * @return \Phalconry\Mvc\Env|\Phalcon\Config|mixed
	 */
	public function env(var key = null)
	{
		if typeof key == "null" {
			return this->getDI()->getShared("env");
		}

		return this->getDI()->getShared("env")->get(key);
	}

	/**
	 * Returns a directory path
	 *
	 * @param string $name Path name.
	 * @return string
	 */
	public function getPath(string name) -> string|null
	{
		return this->getDI()->getShared("env")->getPath(name);
	}

	/**
	 * Sets a named directory path.
	 *
	 * @param string $name Path name.
	 * @param string $value Absolute directory path.
	 */
	public function setPath(string name, string value) -> void
	{
		this->getDI()->getShared("env")->setPath(name, value);
	}

	/**
	 * Returns a module by name, or the primary module if none given.
	 *
	 * @param string $name [Optional] Module name
	 * @return \Phalconry\Mvc\Module
	 */
	public function getModuleObject(string name = null) -> <Module>
	{
		return this->getDI()->getShared("moduleManager")->get(name);
	}

	/**
	 * Sets the type of response
	 *
	 * @see \Phalconry\Mvc\Responder
	 *
	 * @param string
	 */
	public function setResponseType(string responseType) -> void
	{
		this->getDI()->getShared("responder")->setType(responseType);
	}

	/**
	 * Returns the type of response
	 *
	 * @see \Phalconry\Mvc\Responder
	 *
	 * @return string
	 */
	public function getResponseType() -> string
	{
		return this->getDI()->getShared("responder")->getType();
	}

	/**
	 * Runs the application and sends the response.
	 */
	public function run() -> void
	{
		var response;

		if unlikely ! this->getDI()->has("env") {
			throw new Exception("Env instance not set in DI container");
		}

		// this->handle(null) avoids errors in Zephir
		let response = this->handle(null);

		this->getDI()->getShared("responder")->respond(response);
	}

	/**
	 * Adds the default services to the DI
	 *
	 * @param \Phalcon\DiInterface $di
	 */
	public function setDefaultServices(<DiInterface> di) -> void
	{

	}

}
