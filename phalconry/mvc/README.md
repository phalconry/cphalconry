#`Phalconry\Mvc`
This library extends `Phalcon\Mvc` to provide a set of common structural components to create MVC-based applications.

####Core interfaces
  * `ApplicationInterface` - Interface for the application; provides easy access to core components.
  * `EnvironmentInterface` - Extends `Phalcon\Config` and serves as the "parent" application configuration.
  * `Module\ManagerInterface` - Manages modules, including location, loading, and storage.
  * `Application\BootstrapInterface` - Bootstraps the application.
  * `Application\HandlerInterface` - Handles the main request (previously handled in `Phalcon\Mvc\Application::handle()`).
  
##Usage

Set up the application. The application constructor accepts two optional arguments: a `Phalcon\DiInterface` and `Phalconry\Mvc\EnvironmentInterface`
```php
// Load config data and create an EnvironmentInterface
$configArray = require "../path/to/config.php";
$env = new Phalconry\Mvc\Env($configArray);

// Create a Phalcon\DiInterface (optional) - Phalcon\Di\FactoryDefault will be created if omitted
$di = new Phalcon\Di\FactoryDefault();

// Create an ApplicationInterface
$app = new Phalconry\Mvc\Application($di, $env);
```

If desired, set your own bootstrap and/or request handler. This step is optional - the default bootstrap and handler (as seen below) will be created if omitted.
```php
// Create a Application\BootstrapInterface (optional)
$bootstrap = new Phalconry\Mvc\Application\Bootstrap();
$app->setBootstrap($bootstrap);

// Create a Application\HandlerInterface (optional)
$handler = new Phalconry\Mvc\Application\Handler($app);
$app->setHandler($handler);
```

Bootstrap the application, handle the request, and send the response.
If using the default `Phalconry\Mvc\Application`, the code below is wrapped in the `run()` method.
```php
// Calls BootstrapInterface::boot() and "application:boot" event.
$app->bootstrap();

// Calls HandlerInterface::handle()
$response = $app->handle();

if ($response instanceof Phalcon\Http\ResponseInterface) {
  $app->respond($response);
}
```

##Features
This section describes the additional features and functionality provided Phalconry\Mvc.

###ApplicationInterface
`ApplicationInterface` is both DI- and event-aware. It contains the following methods:

#####`setBootstrap(Phalconry\Mvc\Application\BootstrapInterface $bootstrap)`
  Sets the application bootstrap.

#####`setHandler(Phalconry\Mvc\Application\HandlerInterface $handler);`
  Sets the request handler.
  
#####`env($key = null)` 
  Returns an item from the environment config or the object itself.

#####`getEnvironment()`
  Returns a `Phalconry\Mvc\EnvironmentInterface`.

#####`getConfig()`
  Returns a `Phalcon\Config` for the _application_ (i.e. this should not return the environment).
  
#####`getModuleManager()`
  Returns a `Phalconry\Mvc\Module\ManagerInterface`

#####`getPrimaryModule()`
  Returns a `Phalconry\Mvc\ModuleInterface`, the module active for the current request.

#####`getDispatcher()`
  Returns a `Phalcon\Mvc\DispatcherInterface`

#####`loadService(Phalconry\Di\ServiceProviderInterface $provider)`
  Loads a service into the DI container.

#####`loadServices(array $services)`
  Loads multiple services into the DI container.

#####`bootstrap()`
  Bootstraps the application.

#####`handle($uri = null)`
  Handles the main request. Returns a `Phalcon\Http\ResponseInterface` or `boolean`.

#####`respond($response = null)`
  Sends the response.

#####`isBooted()`
    Checks whether `bootstrap()` has been called and returns `boolean`.
