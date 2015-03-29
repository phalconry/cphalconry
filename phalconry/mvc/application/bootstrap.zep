namespace Phalconry\Mvc\Application;

use Phalcon\Loader;
use Phalcon\Events\Event;
use Phalconry\Mvc\Application;
use Phalconry\Mvc\Module;

class Bootstrap
{

	/**
	 * application:boot event callback
	 */
    public function boot(<Event> event, <Application> app, var nothing = null)
    {
        var env, loader, configPath;

        let env = app->getDI()->getShared("env");
		let loader = new Loader();
		let configPath = env->getPath("config");

		loader->register();

		// Add to symbol table (makes available as PHP variables)
		let {"app"} = app;
		let {"di"} = app->getDI();
		let {"loader"} = loader;

		// Configure loader
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
			require configPath."loader.php";
		}

		// Configure services
		app->setDefaultServices(app->getDI());

		require configPath."services.php";

		// Configure modules
		if isset env->{"modules"} {

			var modules, moduleArgs, moduleClasses;

			let modules = env->{"modules"}->toArray();
			let moduleClasses = [];

			app->registerModules(modules, false);

			for moduleArgs in modules {
				// Extract classes and their file paths to add to loader
				if isset moduleArgs["className"] {
					if isset moduleArgs["path"] {
						let moduleClasses[moduleArgs["className"]] = moduleArgs["path"];
					}
				}
			}

			if ! empty moduleClasses {
				loader->registerClasses(moduleClasses);
			}

			// Set default module
			if isset env->{"default_module"} {
				app->setDefaultModule(env->{"default_module"});
			}

		} else {
			require configPath."modules.php";
		}
    }

	/**
	 * application:afterStartModule event callback
	 */
	public function afterStartModule(<Event> event, <Application> app, <Module> module)
	{
		var manager;
		let manager = app->getDI()->getShared("moduleManager");

		module->setName(manager->getName(module));

		manager->setPrimary(module);

		app->getDI()->getShared("dispatcher")->setDefaultNamespace(module->getControllerNamespace());

		module->setApp(app);

		module->onLoad();
	}

	/**
	 * application:afterHandleRequest event callback
	 */
	public function afterHandleRequest(<Event> event, <Application> app, var controller)
	{
		var view;
		let view = app->getDI()->getShared("view");

		if typeof view == "object" {
			if app->getDI()->getShared("responder")->isType("view") {
				app->getDI()->getShared("moduleManager")->getPrimary()->onView(view);
			} else {
				view->disable();
			}
		}
	}


}
