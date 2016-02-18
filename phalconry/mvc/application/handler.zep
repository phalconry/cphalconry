namespace Phalconry\Mvc\Application;

use Phalcon\DiInterface;
use Phalcon\Config;
use Phalcon\Mvc\ViewInterface;
use Phalcon\Mvc\RouterInterface;
use Phalcon\Mvc\DispatcherInterface;
use Phalcon\Http\ResponseInterface;
use Phalcon\Events\ManagerInterface as EventsManagerInterface;
use Phalconry\Mvc\ModuleInterface;
use Phalconry\Mvc\ApplicationInterface;
use Phalconry\Mvc\Module\ManagerInterface as ModuleManagerInterface;

class Handler implements HandlerInterface
{

    /**
     * The application instance.
     *
     * @var \Phalconry\Mvc\ApplicationInterface
     */
    protected _application;

    /**
     * Constructor - sets the application.
     *
     * @param \Phalconry\Mvc\ApplicationInterface app
     */
    public function __construct(<ApplicationInterface> app)
    {
        this->setApplication(app);
    }

    /**
     * Sets the application.
     *
     * @param \Phalconry\Mvc\ApplicationInterface app
     * @return void
     */
    public function setApplication(<ApplicationInterface> app) -> void
    {
        let this->_application = app;
    }

    /**
     * Returns the application.
     *
     * @return \Phalconry\Mvc\ApplicationInterface
     */
    public function getApplication() -> <ApplicationInterface>
    {
        return this->_application;
    }

	/**
	 * Handles a MVC request
	 *
	 * @param string uri
	 * @return \Phalcon\Http\ResponseInterface|boolean
	 */
	public function handle(uri = null) -> <ResponseInterface> | boolean
	{
        boolean hasEvents, returnedResponse;
        var app, dependencyInjector, eventsManager, router, dispatcher,
            implicitView, response, view, moduleName, moduleManager,
            module, controller, possibleResponse, renderStatus;

        let app = <ApplicationInterface> this->_application;
		let dependencyInjector = <DiInterface> app->getDI();
        let eventsManager = <EventsManagerInterface> app->getEventsManager();
        let router = <RouterInterface> dependencyInjector->getShared("router");
		let moduleManager = <ModuleManagerInterface> dependencyInjector->getShared("moduleManager");
		let dispatcher = <DispatcherInterface> dependencyInjector->getShared("dispatcher");
        let implicitView = app->getConfig()->get("implicitView", true);
        let hasEvents = (typeof eventsManager == "object");

		// Handle the URI pattern (if any)
		router->handle(uri);

		// If the router doesn't return a valid module we use the default module
		let moduleName = router->getModuleName();
		if !moduleName {
			let moduleName = moduleManager->getDefaultModuleName();
		}

		if moduleName {

            /**
             * Call beforeStartModule event
             */
    		if hasEvents === true {
        	    if eventsManager->fire("application:beforeStartModule", app, moduleName) === false {
                    return false;
                }
            }

            // Get the module
            let module = <ModuleInterface> moduleManager->getModule(moduleName);

            // Loads the module
			moduleManager->loadModule(module);

            // Set dispatcher default namespace
			dispatcher->setDefaultNamespace(module->getControllerNamespace());

            /**
             * Call afterStartModule event
             */
            if hasEvents === true {
                eventsManager->fire("application:afterStartModule", app, module);
            }
		}

		// We get the parameters from the router and assign them to the dispatcher
		dispatcher->setModuleName(moduleName);
		dispatcher->setNamespaceName(router->getNamespaceName());
		dispatcher->setControllerName(router->getControllerName());
		dispatcher->setActionName(router->getActionName());
		dispatcher->setParams(router->getParams());

		// Start the view component (start output buffering)
		if implicitView === true {
            let view = <ViewInterface> dependencyInjector->getShared("view");
            view->start();
		}

        /**
         * Call beforeHandleRequest event
         */
        if hasEvents === true {
    		if eventsManager->fire("application:beforeHandleRequest", app, dispatcher) === false {
    			return false;
    		}
        }

		// The dispatcher must return an object
		let controller = dispatcher->dispatch();

		// Get the latest value returned by an action
		let possibleResponse = dispatcher->getReturnedValue();

        if possibleResponse === false {
            /**
             * Return response from DI if controller returns false
             */
            return dependencyInjector->getShared("response");
        }

        /**
         * Call afterHandleRequest event
         */
        if hasEvents === true {
            eventsManager->fire("application:afterHandleRequest", app, controller);
        }

		if typeof possibleResponse == "object" {
			// Check if the returned object is already a response
			let returnedResponse = (possibleResponse instanceof ResponseInterface);
		} else {
			let returnedResponse = false;
		}

		// If the dispatcher returns an object we try to render the view in auto-rendering mode
		if returnedResponse === false {
			if implicitView === true {
				if typeof controller == "object" {
					let renderStatus = true;
                    if hasEvents === true {
                        /**
                         * This allows to make a custom view render
                         */
					    let renderStatus = eventsManager->fire("application:viewRender", app, view);
                    }
					// Check if the view process has been treated by the developer.
					// If not, automatic render based on the latest controller executed.
                    if renderStatus !== false {
						view->render(
							dispatcher->getControllerName(),
							dispatcher->getActionName(),
							dispatcher->getParams()
						);
					}
				}
			}
		}

		// Finish the view component (stop output buffering)
		if implicitView === true {
			view->finish();
		}

		if returnedResponse === false {
			let response = <ResponseInterface> dependencyInjector->getShared("response");
			if implicitView === true {
				// The content returned by the view is passed to the response service
				response->setContent(view->getContent());
			}
		} else {
			// We don't need to create a response because there is one already created
			let response = possibleResponse;
		}

		// Return the response
		return response;
	}

}
