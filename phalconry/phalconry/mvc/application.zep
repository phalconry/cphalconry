namespace Phalconry\Mvc;

class Application extends \Phalcon\Mvc\Application
{

	/**
	 * Name of the primary module
	 * @var string
	 */
	protected _moduleName;

	/**
	 * Module registry
	 * @var \Phalcon\Registry
	 */
	protected _moduleRegistry;

	/**
	 * Responder
	 * @var \Phalconry\Mvc\Responder
	 */
	protected _responder;

	/**
	 * Application constructor.
	 *
	 * @param Env $env Environment instance
	 */
	public function __construct(<Env> env)
	{
		var di, eventsManager;

		let di = new \Phalcon\DI\FactoryDefault();

		di->setShared("app", this);
		di->setShared("config", env);

		parent::__construct(di);

		let this->_moduleRegistry = new \Phalcon\Registry();

		let eventsManager = new \Phalcon\Events\Manager();
		eventsManager->attach("application", this);
		this->setEventsManager(eventsManager);
	}

	/**
	 * Returns a directory path
	 *
	 * @param string $name Path name.
	 * @return string
	 */
	public function getPath(string name) {
		return this->getDI()->getShared("config")->getPath(name);
	}

	/**
	 * Sets a named directory path.
	 *
	 * @param string $name Path name.
	 * @param string $value Absolute directory path.
	 */
	public function setPath(string name, string value) {
		this->getDI()->getShared("config")->setPath(name, value);
	}

	/**
	 * Returns the name of a module from an object
	 *
	 * @param \Phalconry\Mvc\Module $module [Optional]
	 * @return string
	 */
	public function getModuleName(<\Phalconry\Mvc\Module> module = null) {

		if (typeof module == "null") {
			return this->_moduleName;
		}

		string className;
		var modules;

		let className = get_class(module);
		let modules = this->getModules();

		var key, value;

		for key, value in modules {
			if value["className"] === className {
				return key;
			}
		}

		return null;
	}

	/**
	 * Returns a module by name, or the primary module if none given.
	 *
	 * @param string $name [Optional] Module name
	 * @return \Phalconry\Mvc\Module
	 */
	public function getModule(string name = null) {

		if (typeof name == "null") {
			return this->{"_moduleObject"};
		}

		return this->_moduleRegistry[name];
	}

	/**
	 * Adds a module to the registry
	 *
	 * @param \Phalconry\Mvc\Module $module
	 */
	public function setModule(<\Phalconry\Mvc\Module> module) {

		var name;
		let name = this->getModuleName(module);

		if isset this->_moduleRegistry[name] {
			throw new \RuntimeException("Module already set");
		}

		module->setName(name);

		let this->_moduleRegistry[name] = module;
	}

	/**
	 * Loads a module
	 *
	 * @param string|\Phalconry\Mvc\Module $module
	 * @return \Phalconry\Mvc\Module
	 */
	public function loadModule(var module) {

		if (typeof module == "string") {

			var moduleList;
			let moduleList = this->getModules();

			if ! isset moduleList[module] {
				throw new \InvalidArgumentException("Unknown module");
			}

			var className;
			let className = moduleList[module]["className"];

			let module = new {className}();
		}

		if (module instanceof \Phalconry\Mvc\Module) {
			if module->isLoaded() {
				throw new \RuntimeException("Cannot reload module");
			}
		} else {
			throw new \InvalidArgumentException("Invalid module given");
		}

		this->setModule(module);

		var di;
		let di = this->getDI();

		module->registerAutoloaders(di);
		module->registerServices(di);
		module->setApp(this);
		module->onLoad();

		return module;
	}

	/**
	 * Whether a module has been loaded
	 *
	 * @param string|\Phalconry\Mvc\Module $module
	 * @return boolean
	 * @throws \InvalidArgumentException if not given a Module object or string
	 */
	public function isModuleLoaded(var module) {

		if (module instanceof \Phalconry\Mvc\Module) {
			return module->isLoaded();
		}

		if (typeof module != "string") {
			throw new \InvalidArgumentException("Expecting string or Module");
		}

		if module === this->_moduleName {
			return isset this->{"_moduleObject"} ? this->{"_moduleObject"}->isLoaded() : false;
		}

		return isset this->_moduleRegistry[module];
	}

	/**
	 * Returns the primary module name.
	 *
	 * @return string
	 */
	public function getPrimaryModuleName() {
		return this->_moduleName;
	}

	/**
	 * Returns the primary module
	 *
	 * @return \Phalconry\Mvc\Module
	 */
	public function getPrimaryModule() {
		return this->{"_moduleObject"};
	}

	/**
	 * Returns the responder
	 *
	 * @return \Phalconry\Mvc\Responder
	 */
	public function getResponder() {

		if (typeof this->_responder == "null") {
			let this->_responder = this->getDI()->getShared("responder");
		}

		return this->_responder;
	}

	/**
	 * Sets the type of response
	 *
	 * @param string
	 */
	public function setResponseType(string type) {
		this->getResponder()->setType(type);
	}

	/**
	 * Returns the type of response
	 *
	 * @return string
	 */
	public function getResponseType() {
		return this->getResponder()->getType();
	}

	/**
	 * Runs the application and sends the response.
	 */
	public function run() {

		var response;
		// handle(null) is a weird error avoidance hack for Zephir
		let response = this->handle(null);

		this->getResponder()->respond(response);
	}

	/**
	 * application:boot event callback
	 */
	public function boot(<\Phalcon\Events\Event> event, <\Phalcon\Mvc\Application> app, var nothing) {

		var env;
		let env = this->getDI()->getShared("config");

		this->_registerAutoloaders(env);
		this->_registerServices(env);
		this->_registerModules(env);
	}

	/**
	 * application:afterStartModule event callback
	 */
	public function afterStartModule(<\Phalcon\Events\Event> event, <\Phalcon\Mvc\Application> app, string moduleName) {

		let this->_moduleName = moduleName;

		var module;
		let module = this->getPrimaryModule();

		module->setName(moduleName);

		this->getDI()->getShared("dispatcher")->setDefaultNamespace(module->getControllerNamespace());

		module->setApp(this);

		module->onLoad();
	}

	/**
	 * application:afterHandleRequest event callback
	 */
	public function afterHandleRequest(<\Phalcon\Events\Event> event, var app, var moduleName) {

		var view;
		let view = this->getDI()->getShared("view");

		if (this->getResponder()->isType("view")) {
			this->getPrimaryModule()->onView(view);
		} else {
			view->disable();
		}
	}

	/**
	 * Registers class loader(s)
	 */
	protected function _registerAutoloaders(<Env> env) {

		var loader;
		let loader = new \Phalcon\Loader();
		loader->register();

		if isset env->{"loader"} {

			var args;
			let args = env->{"loader"};

			if isset args->{"namespaces"} {
				loader->registerNamespaces(args->{"namespaces"}->toArray());
			}

			if isset args->{"dirs"} {
				loader->registerDirs(args->{"dirs"}->toArray());
			}

			if isset args->{"classes"} {
				loader->registerClasses(args->{"classes"}->toArray());
			}

		} else {
			// Add to symbol table in PHP
			let {"app"} = this;
			let {"loader"} = loader;
			require env->getPath("config")."loader.php";
		}
	}

	/**
	 * Registers global services
	 */
	protected function _registerServices(<Env> env) {

		this->setDefaultServices(this->getDI());

		let {"app"} = this;
		let {"di"} = this->getDI();

		require env->getPath("config")."services.php";
	}

	/**
	 * Registers modules
	 */
	protected function _registerModules(<Env> env) {

		if isset env->{"modules"} {

			this->registerModules(env->{"modules"}->toArray(), false);

			if isset env->{"default_module"} {
				this->setDefaultModule(env->{"default_module"});
			}

		} else {
			let {"app"} = this;
			require env->getPath("config")."modules.php";
		}
	}

	/**
	 * Adds the default services to the DI
	 */
	protected function setDefaultServices(<\Phalcon\DiInterface> di) {

	}

}
