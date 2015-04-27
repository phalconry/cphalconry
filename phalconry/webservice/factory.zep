namespace Phalconry\WebService;

use Phalcon\Di\Injectable;
use UnexpectedValueException;

/**
 * Factory creates web services from definitions
 */
class Factory extends Injectable
{

	/**
	 * Create a web service from a definition
	 *
	 * @param mixed $definition Callable, classname, or file
	 * @return \Phalconry\WebService\ServiceInterface
	 * @throws \Phalconry\WebService\Exception if service cannot be created
	 * @throws \UnexpectedValueException if the definition does not resolve to an instance of ServiceInterface
	 */
	public function create(var definition) -> <ServiceInterface>
	{
        var dependencyInjector, service;
        string diKey;

		let dependencyInjector = this->getDI();

		if typeof definition == "string" {

			if dependencyInjector->has(definition) {
				return dependencyInjector->get(definition);
			}

            let diKey = camelize(definition . "_webService");

            if dependencyInjector->has(diKey) {
                return dependencyInjector->get(diKey);
            }

			if class_exists(definition) {
				let service = new {definition}();
			} elseif is_file(definition) {
				let service = require definition;
			}

		} elseif is_callable(definition) {
			let service = call_user_func(definition);
		}

		if typeof service == "null" {
			throw new Exception("Web service could not be created from definition");
		}

		if (service instanceof ServiceInterface) {
            service->setDI(dependencyInjector);
            return service;
        }

        throw new UnexpectedValueException("Expecting ServiceInterface");
	}

}
