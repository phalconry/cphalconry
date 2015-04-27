namespace Phalconry\Mvc\Application;

use Phalcon\Loader;
use Phalcon\Events\Event;
use Phalconry\Mvc\Application;
use Phalconry\Mvc\Module;

class Bootstrap
{

	/**
	 * application:boot event callback
	 *
	 * Boots the application using values from Env (DI key: "env").
	 *
	 * * Loader is set using the optional "loader" (array) arguments:
	 * 		* "namespaces" (array)
	 * 		* "dirs" (array)
	 * 		* "classes" (array)
	 * * If no "loader" argument is set, the file "loader.php" in directory "config" MUST exist, as it will be
	 * "require"-ed.
	 *
	 * * Application::setDefaultServices() is called, passing the DI as the only argument.
	 *
	 * * If "modules" (array) argument exists, they are registered and autoloaded. Otherwise, the file "modules.php" in
	 * directory "config" MUST exist and will be "require"-ed.
	 *
	 * * If a "default_module" (string) argument exists, it will be used to set the default module
	 * (via Application::setDefaultModule())
	 */
    public function boot(<Event> event, <Application> app, var nothing = null) -> void
    {
        var di, env, loader, configPath, loaderArgs, session;

        let di = app->getDI();
        let env = di->getShared("env");
		let loader = new Loader();
		let configPath = env->getPath("config");

		loader->register();

		// Add to symbol table
		let {"app"} = app;
		let {"di"} = di;
		let {"loader"} = loader;

		// Configure loader
		if typeof env->{"loader"} == "object" {

            let loaderArgs = env->{"loader"};

			if typeof loaderArgs->{"namespaces"} == "object" {
				loader->registerNamespaces(loaderArgs->{"namespaces"}->toArray());
			}

			if typeof loaderArgs->{"dirs"} == "object" {
				loader->registerDirs(loaderArgs->{"dirs"}->toArray());
			}

			if typeof loaderArgs->{"classes"} == "object" {
				loader->registerClasses(loaderArgs->{"classes"}->toArray());
			}

		} else {
			if file_exists(configPath."loader.php") {
    			require configPath."loader.php";
            }
		}

		// Configure services
		app->setDefaultServices(di);

        if file_exists(configPath . "services.php") {
            require configPath . "services.php";
        }

		// Configure modules
		if typeof env->{"modules"} == "object" {

			var modules, modArgs, moduleClasses;

			let modules = env->{"modules"}->toArray();
			let moduleClasses = [];

			app->registerModules(modules, false);

			for modArgs in modules {
				// Extract classes and their file paths to add to loader
				if isset modArgs["className"] {
                    if isset modArgs["path"] {
    					let moduleClasses[modArgs["className"]] = modArgs["path"];
                    }
				}
			}

			if ! empty moduleClasses {
				loader->registerClasses(moduleClasses);
			}

			// Set default module
			if typeof env->{"default_module"} == "string" {
				app->setDefaultModule(env->{"default_module"});
			}

		} else {
            if file_exists(configPath."modules.php") {
    			require configPath."modules.php";
            }
		}

        if typeof env->{"session"} == "object" {

            if env->{"session"}->get("auto_start") {
                di->getShared("session")->start();
            }
        }
    }

	/**
	 * application:afterStartModule event callback
	 *
	 * The active Module object will be set as the "primary" module with the module manager (DI key: "moduleManager").
	 *
	 * * The default "dispatch" namespace will be set on the dispatcher (DI key: "dispatcher")
	 * using the module's `getControllerNamespace()` method.
	 * * Finally the module receives the Application and its `onLoad()` method is called.
	 */
	public function afterStartModule(<Event> event, <Application> app, <Module> module) -> void
	{
		var di, moduleManager, viewEvents;

        let di = app->getDI();
		let moduleManager = di->getShared("moduleManager");
        let viewEvents = di->getShared("viewEvents");

		module->setName(moduleManager->getName(module));

		moduleManager->setPrimary(module);

		module->setApp(app);

		di->getShared("dispatcher")->setDefaultNamespace(module->getControllerNamespace());

        di->getShared("view")->setEventsManager(viewEvents);

        viewEvents->attach("view", module);

        module->onLoad();
	}

	/**
	 * application:afterHandleRequest event callback
	 *
	 * The view is retrieved from the DI (key: "view").
	 *
	 * If "view" == response type, as given by the responder (DI key: "responder"), the `onView()` method
	 * is called on the "primary" module.
	 *
	 * If the response type is not "view", the view component is disabled (via View::disable()).
	 */
	public function afterHandleRequest(<Event> event, <Application> app, var controller) -> void
	{
		var di, view;

        let di = app->getDI();
		let view = di->getShared("view");

        di->getShared("moduleManager")->getPrimary()->onView(view);

        // If responder mode is not "view" (default), disable the view
        if ! di->getShared("responder")->isType("view") {
			view->disable();
		}
	}

}
