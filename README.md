# Phalconry
Phalconry is a PHP extension that builds on Phalcon.

##About
Phalconry is composed of several distinct component libraries:

####MVC
Extends the MVC portion of Phalcon. 

Major features include:
 1. __Contract-based applications__: Allows the developer to implement custom routines (e.g. bootstrapping, handling, etc.) using a common set of interfaces.
  * Introduces: `ApplicationInterface`, `ApplicationAwareInterface`, `EnvironmentInterface`, `Application\BootstrapInterface`, `Application\HandlerInterface`
 2. __Integrated modules__: Modules are no longer just structural objects but can now more easily implement module-specific logic. A "manager" now assumes responsibility for modules (instead of Application).
  * Introduces: `ModuleInterface`, `Module\ManagerInterface`
 3. __HMVC__: Provides a simple HMVC request implementation which can even be sent to controllers in other modules.
  * Introduces: `Hmvc\Request`
 4. __Plugins__: Provides a set of simple classes to implement a pluggable component system ("plugins", or "packages", "add-ins", etc.).
  * Introduces: `PluginInterface`, `Plugin\ManagerInterface`

[Go to the full MVC README](/Mvc/README.md)

####HTTP Client
A (heavily) modified version of the same library from [Phalcon/Incubator](https://github.com/phalcon/incubator/tree/master/Library/Phalcon/Http). 

Major features include:
 1. __URI__: Provides a simple wrapper for a URI.
 2. __Request & Response__: Provides `Request` and `Response` classes for sending HTTP requests and receiving responses. Both classes extend the `Message` parent class.
 3. __Adapters__: Allow for the use of different HTTP transports; cURL and stream adapters are included.

The primary difference from the Incubator library is that in Phalconry, the developer does not directly interface with the adapters; Phalconry's `Client` provides a single interface to the underlying functionality, regardless of the HTTP transport used.
 
####Web Services
Allows the developer to create interfaces to web service APIs.


