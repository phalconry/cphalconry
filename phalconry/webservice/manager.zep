namespace Phalconry\WebService;

use Phalcon\Di\Injectable;
use InvalidArgumentException;

/**
 * Manager manages web services
 */
class Manager extends Injectable implements \Countable
{

	/**
	 * @var \Phalconry\WebService\Factory
	 */
	protected _factory;

	/**
	 * @var array
	 */
	protected _definitions = [];

	/**
	 * @var array
	 */
	protected _services = [];

	/**
	 * Sets a web service
	 *
	 * @param string name Web service name
	 * @param \Phalconry\WebService\ServiceInterface service
	 */
	public function set(string! name, <ServiceInterface> service)
	{
		let this->_services[name] = service;
	}

	/**
	 * Whether the given service exists
	 *
	 * @param string|\Phalconry\WebService\ServiceInterface
	 * @return boolean
	 */
	public function has(var service) -> boolean
	{
		if typeof service == "object" {
			return in_array(service, this->_services, true);
		}

		return isset this->_services[service];
	}

	/**
	 * Returns a web service by name
	 *
	 * @param string name Web service name
	 * @return \Phalconry\WebService\ServiceInterface
	 * @throws \Phalconry\WebService\Exception
	 */
	public function get(string! name) {

		if ! isset this->_services[name] {

			if ! isset this->_definitions[name] {
				throw new Exception("Service not available");
			}

			this->set(name, this->getFactory()->create(this->_definitions[name]));
		}

		return this->_services[name];
	}

	/**
	 * Sets a web service definition
	 *
	 * @param string name Web service name
	 * @param string|callable Web service classname, or a callback that returns the object
	 * @throws \InvalidArgumentException if definition is not string or callable
	 */
	public function setDefinition(string! name, var definition)
	{
		if typeof definition != "string" && ! is_callable(definition) {
			throw new InvalidArgumentException("Service definition must be string or callable");
		}

		let this->_definitions[name] = definition;
	}

	/**
	 * Whether a definition for the given web service exists
	 *
	 * @param string name Web service name
	 * @return boolean
	 */
	public function hasDefinition(string name) -> boolean
	{
		return isset this->_definitions[name];
	}

	/**
	 * Returns a web service definition
	 *
	 * @param string name
	 * @return string|callable|null
	 */
	public function getDefinition(string! name)
	{
		return isset this->_definitions[name] ? this->_definitions[name] : null;
	}

	/**
	 * Whether a given web service is available
	 *
	 * @param string service Web service name
	 * @return boolean
	 */
	public function isAvailable(string! service) -> boolean
	{
		return this->hasDefinition(service) || this->has(service);
	}

	/**
	 * Sets the web service factory
	 *
	 * @param \Phalconry\WebService\Factory factory
	 */
	public function setFactory(<Factory> factory)
	{
		let this->_factory = factory;
	}

	/**
	 * Returns the web service factory, creating if not set
	 *
	 * @return \Phalconry\WebService\Factory
	 */
	public function getFactory() -> <Factory>
	{
		return (typeof this->_factory == "object") ? this->_factory : this->getDI()->getShared("webServiceFactory");
	}

	/**
	 * Returns the number of registered web services
	 *
	 * @return int
	 */
	public function count() -> int
	{
		return count(this->_services);
	}

}
