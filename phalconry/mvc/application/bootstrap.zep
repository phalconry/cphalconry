namespace Phalconry\Mvc\Application;

use Phalcon\Loader;
use Phalcon\DiInterface;
use Phalconry\Mvc\ApplicationInterface;
use Phalconry\Events\GlobalManager;

class Bootstrap implements BootstrapInterface
{

    /**
     * @var \Phalcon\Loader
     */
    protected loader;

    /**
     * Boots the application.
     *
     * @param \Phalconry\Mvc\ApplicationInterface app
     * @return void
     */
    public function boot(<ApplicationInterface> app) -> void
    {
        var dependencyInjector, loader, cfgPath, loaderFile, servicesFile, modulesFile;

        let dependencyInjector = app->getDI();
        let loader = new Loader();
        loader->register();

        this->registerLoader(dependencyInjector, app, loader);
        this->registerServices(dependencyInjector, app, loader);
        this->registerModules(dependencyInjector, app, loader);

        let cfgPath = dependencyInjector->getShared("env")->getPath("config");

        if is_dir(cfgPath) {

            let loaderFile = cfgPath . "loader.php";
            let servicesFile = cfgPath . "services.php";
            let modulesFile = cfgPath . "modules.php";

            let {"di"} = dependencyInjector;
            let {"app"} = app;
            let {"loader"} = loader;

            if file_exists(loaderFile) {
                require loaderFile;
            }

            if file_exists(servicesFile) {
                require servicesFile;
            }

            if file_exists(modulesFile) {
                require modulesFile;
            }
        }
    }

	/**
	 * Configure loader
	 */
    protected function registerLoader(<DiInterface> di, <ApplicationInterface> app, <Loader> loader)
    {
        var args;
        let args = app->env("loader");

		if typeof args != "object" {
            return false;
        }

		if typeof args->{"namespaces"} == "object" {
			loader->registerNamespaces(args->{"namespaces"}->toArray());
		}

		if typeof args->{"dirs"} == "object" {
			loader->registerDirs(args->{"dirs"}->toArray());
		}

		if typeof args->{"classes"} == "object" {
			loader->registerClasses(args->{"classes"}->toArray());
		}
    }

	/**
	 * Configure services
	 */
    protected function registerServices(<DiInterface> di, <ApplicationInterface> app, <Loader> loader)
    {
        if ! di->has("events") {
            di->setShared("events", GlobalManager::create());
        }

    	if ! di->has("view") {
			di->setShared("view", "Phalcon\\Mvc\\View");
		}

		if ! di->has("moduleManager") {
			di->setShared("moduleManager", "Phalconry\\Mvc\\Module\\Manager");
		}

		if ! di->has("responder") {
			di->setShared("responder", "Phalconry\\Mvc\\Responder");
		}

		if ! di->has("hmvcRequest") {
			di->setShared("hmvcRequest", "Phalconry\\Mvc\\Hmvc\\Request");
		}

		if ! di->has("httpClient") {
			di->setShared("httpClient", "Phalconry\\Http\\Client");
		}
    }

    /**
     * Configure modules
     */
    protected function registerModules(<DiInterface> di, <ApplicationInterface> app, <Loader> loader)
    {
        var modules;
        let modules = app->env("modules");

		if typeof modules == "object" {

    		var moduleManager, modulesArray, modArgs, moduleClasses, defaultModule;

            let moduleManager = app->getDI()->getShared("moduleManager");
    		let modulesArray = modules->toArray();
    		let moduleClasses = [];

    		moduleManager->registerModules(modulesArray);

    		for modArgs in modulesArray {
                var modClassName, modPath;
    			// Extract classes and their file paths to add to loader
    			if fetch modClassName, modArgs["className"] {
                    if fetch modPath, modArgs["path"] {
    					let moduleClasses[modClassName] = modPath;
                    }
    			}
    		}

    		if ! empty moduleClasses {
    			loader->registerClasses(moduleClasses);
    		}

            // Set default module
            let defaultModule = app->env("default_module");

            if typeof defaultModule == "string" {
    			moduleManager->setDefaultModuleName(defaultModule);
    		}
        }
    }

}
