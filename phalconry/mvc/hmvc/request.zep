namespace Phalconry\Mvc\Hmvc;

use Phalcon\DiInterface;
use Phalcon\Di\Injectable;
use Phalcon\Http\ResponseInterface;
use Phalcon\Mvc\DispatcherInterface;
use Phalconry\Mvc\ModuleInterface;
use Phalconry\Mvc\Module\Manager;

/**
 * Wrapper for an HMVC request.
 */
class Request extends Injectable
{

	/**
	 * Module name
	 *
	 * @var string
	 */
	protected _module;

	/**
	 * Controller name
	 *
	 * @var string
	 */
	protected _controller;

	/**
	 * Action name
	 *
	 * @var string
	 */
	protected _action;

	/**
	 * Request parameters
	 *
	 * @var array
	 */
	protected _params;

	/**
	 * Request response
	 *
	 * @var mixed
	 */
	protected _response;

	/**
	 * HmvcRequest constructor.
	 *
	 * @param array args [Optional] Request args {@see Request::set()}
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
	 * @return \Phalconry\Mvc\Hmvc\Request
	 */
	public function setLocation(array! args) -> <Request>
    {
		var module, controller, action, params;

		if fetch module, args["module"] {
			this->setModuleName(module);
		}

		if fetch controller, args["controller"] {
			this->setControllerName(controller);
		}

		if fetch action, args["action"] {
			this->setActionName(action);
		}

		if fetch params, args["params"] {
			this->setParams(params);
		}

		return this;
	}

	/**
	 * Sets the module name
	 *
	 * @param string module Module name
	 * @return \Phalconry\Mvc\Hmvc\Request
	 */
	public function setModuleName(string! module) -> <Request>
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
	public function getModuleName() -> string | null
    {
		return this->_module;
	}

	/**
	 * Sets the controller name
	 *
	 * @param string controller Controller name
	 * @return \Phalconry\Mvc\Hmvc\Request
	 */
	public function setControllerName(string! controller) -> <Request>
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
	public function getControllerName() -> string | null
    {
		return this->_controller;
	}

	/**
	 * Sets the action name
	 *
	 * @param string action Action name
	 * @return \Phalconry\Mvc\Hmvc\Request
	 */
	public function setActionName(string! action) -> <Request>
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
	public function getActionName() -> string | null
    {
		return this->_action;
	}

	/**
	 * Sets the request parameters
	 *
	 * @param array params
	 * @return \Phalconry\Mvc\Hmvc\Request
	 */
	public function setParams(array! params) -> <Request>
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
            return count(this->_params) > 0;
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
		return (typeof this->_params == "array") ? this->_params : [];
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
	 * Dispatches the request and returns a response
	 *
	 * @param array args [Optional]
	 * @return mixed
	 */
	public function __invoke(var args = null)
    {
		var moduleName, controllerName, actionName, params, dependencyInjector,
			origDispatcher, dispatcher, moduleManager, module, response;

		if typeof args == "array" {
			this->setLocation(args);
		}

		let dependencyInjector = this->getDI();

		if typeof dependencyInjector != "object" {
			let dependencyInjector = \Phalcon\Di::getDefault();
			if unlikely typeof dependencyInjector != "object" {
				throw new Exception("Could not locate dependency injector");
			}
		}

		let moduleName = this->_module;
		let controllerName = this->_controller;
		let actionName = this->_action;
		let params = this->_params;
		let origDispatcher = <DispatcherInterface> dependencyInjector->getShared("dispatcher");
		let dispatcher = clone origDispatcher;

		if typeof moduleName == "string" {

			let moduleManager = <Manager> dependencyInjector->getShared("moduleManager");
			if typeof moduleManager != "object" {
				throw new Exception("Invalid injected module manager");
			}

			if moduleName != moduleManager->getPrimaryModuleName() {

				let module = <ModuleInterface> moduleManager->getModule(moduleName);

				if typeof module == "object" {
					if ! module->isLoaded() {
						moduleManager->loadModule(module);
					}
				} else {
					throw new Exception("Could not locate module: '" . moduleName . "'");
				}

				dispatcher->setNamespaceName(module->getControllerNamespace());
			}

			dispatcher->setModuleName(moduleName);
		}

		if typeof controllerName == "string" {
			dispatcher->setControllerName(controllerName);
		}

		if typeof actionName == "string" {
			dispatcher->setActionName(actionName);
		}

		if typeof params == "array" {
			dispatcher->setParams(params);
		}

		dispatcher->dispatch();

		let response = dispatcher->getReturnedValue();
		let this->_response = response;

		if (response instanceof ResponseInterface) {
			return response->getContent();
		}

		return response;
	}

}
