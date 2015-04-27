namespace Phalconry\Mvc;

use Phalcon\DiInterface;
use Phalcon\DI\Injectable;
use Phalcon\Http\ResponseInterface;
use Phalcon\Http\Response;
use Phalcon\Mvc\Dispatcher;
use RuntimeException;

/**
 * Wrapper for an HMVC request.
 */
class HmvcRequest extends Injectable
{

	/**
	 * Module name
	 * @var string
	 */
	protected _module;

	/**
	 * Controller name
	 * @var string
	 */
	protected _controller;

	/**
	 * Action name
	 * @var string
	 */
	protected _action;

	/**
	 * Request parameters
	 * @var array
	 */
	protected _params;

	/**
	 * Request response
	 * @var mixed
	 */
	protected _response;

	/**
	 * HmvcRequest constructor.
	 *
	 * @param array args [Optional] Request args {@see HmvcRequest::set()}
	 */
	public function __construct(array! args = []) {
		if ! empty args {
			this->setLocation(args);
		}
	}

	/**
	 * Sets module, controller, action, and/or params from an array.
	 *
	 * @param array args
	 * @return \Phalconry\Mvc\HmvcRequest
	 */
	public function setLocation(array! args) -> <HmvcRequest>
    {

		if isset args["module"] {
			this->setModuleName(args["module"]);
		}

		if isset args["controller"] {
			this->setControllerName(args["controller"]);
		}

		if isset args["action"] {
			this->setActionName(args["action"]);
		}

		if isset args["params"] {
			this->setParams(args["params"]);
		}

		return this;
	}

	/**
	 * Sets the module name
	 *
	 * @param string module Module name
	 * @return \Phalconry\Mvc\HmvcRequest
	 */
	public function setModuleName(string! module) -> <HmvcRequest>
    {
		let this->_module = module;
		return this;
	}

	/**
	 * Whether a module name is set
	 *
	 * @return boolean
	 */
	public function hasModuleName() -> boolean
    {
		return (typeof this->_module == "string");
	}

	/**
	 * Returns the module name
	 *
	 * @return string
	 */
	public function getModuleName() -> string|null
    {
		return this->_module;
	}

	/**
	 * Sets the controller name
	 *
	 * @param string controller Controller name
	 * @return \Phalconry\Mvc\HmvcRequest
	 */
	public function setControllerName(string! controller) -> <HmvcRequest>
    {
		let this->_controller = controller;
		return this;
	}

	/**
	 * Whether the controller name is set
	 *
	 * @return boolean
	 */
	public function hasControllerName() -> boolean
    {
		return (typeof this->_controller == "string");
	}

	/**
	 * Returns the controller name
	 *
	 * @return string
	 */
	public function getControllerName() -> string|null
    {
		return this->_controller;
	}

	/**
	 * Sets the action name
	 *
	 * @param string action Action name
	 * @return \Phalconry\Mvc\HmvcRequest
	 */
	public function setActionName(string! action) -> <HmvcRequest>
    {
		let this->_action = action;
		return this;
	}

	/**
	 * Whether the action name is set
	 *
	 * @return boolean
	 */
	public function hasActionName() -> boolean
    {
		return (typeof this->_action == "string");
	}

	/**
	 * Returns the action name
	 *
	 * @return string
	 */
	public function getActionName() -> string|null
    {
		return this->_action;
	}

	/**
	 * Sets the request parameters
	 *
	 * @param array params
	 * @return \Phalconry\Mvc\HmvcRequest
	 */
	public function setParams(array! params) -> <HmvcRequest>
    {
		let this->_params = params;
		return this;
	}

	/**
	 * Whether any parameters are set
	 *
	 * @return boolean
	 */
	public function hasParams() -> boolean
    {
		if typeof this->_params == "array" {
            return ! empty this->_params;
        }

        return false;
	}

	/**
	 * Returns the request parameters
	 *
	 * @return array
	 */
	public function getParams() -> array
    {
		return this->hasParams() ? this->_params : [];
	}

	/**
	 * Dispatches the request and returns a response
	 *
	 * @param array args [Optional]
	 * @return mixed
	 */
	public function __invoke(var args = null)
    {
        var dependencyInjector, dispatcher, response;

		if typeof args == "array" {
			this->setLocation(args);
		}

		let dependencyInjector = this->getDI();

		if typeof dependencyInjector != "object" {

			let dependencyInjector = \Phalcon\Di::getDefault();

			if typeof dependencyInjector != "object" {
				throw new RuntimeException("Could not locate dependency injector");
			}
		}

		let dispatcher = clone dependencyInjector->getShared("dispatcher");

		if typeof this->_module == "string" {
			this->prepareModule(dispatcher, this->_module);
		}

		if typeof this->_controller == "string" {
			dispatcher->setControllerName(this->_controller);
		}

		if typeof this->_action == "string" {
			dispatcher->setActionName(this->_action);
		}

		if typeof this->_params == "array" && !empty this->_params {
			dispatcher->setParams(this->_params);
		}

		dispatcher->dispatch();

		let response = dispatcher->getReturnedValue();
		let this->_response = response;

		if (response instanceof ResponseInterface) {
			return response->getContent();
		}

		return response;
	}

	/**
	 * Returns the response
	 *
	 * @return mixed
	 */
	public function getResponse()
    {
		return this->_response;
	}

	/**
	 * Prepares to dispatch to a module
	 *
	 * The module is loaded if not already. If it's not the primary module, the
	 * default controller namespace is reset on the cloned dispatcher.
	 *
	 * @param \Phalcon\Mvc\Dispatcher dispatcher
	 * @param string moduleName
	 */
	protected function prepareModule(<Dispatcher> dispatcher, string moduleName) -> void
    {
        var dependencyInjector, moduleManager, module;

		let dependencyInjector = this->getDI();

		if typeof dependencyInjector != "object" {

			let dependencyInjector = \Phalcon\Di::getDefault();

			if typeof dependencyInjector != "object" {
				throw new RuntimeException("Could not locate dependency injector");
			}
		}

		let moduleManager = dependencyInjector->getShared("moduleManager");

		if typeof moduleManager != "object" {
			throw new RuntimeException("Invalid injected module manager");
		}

		if moduleName != moduleManager->getPrimary()->getName() {

			if moduleManager->isLoaded(moduleName) {
				let module = moduleManager->get(moduleName);
			} else {
				let module = moduleManager->load(moduleName);
			}

			if typeof module != "object" {
				throw new RuntimeException("Invalid module provided");
			}

			dispatcher->setNamespaceName(module->getControllerNamespace());
		}

		dispatcher->setModuleName(moduleName);
	}

}
