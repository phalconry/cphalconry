# Phalconry
Phalconry is a PHP extension that builds on Phalcon.

##About
Phalconry is composed of a few distinct parts:

####MVC
Extends the MVC portion of Phalcon. Notable features include:
 1. __Bootstrapping__: A stand-alone bootstrapper is used for running "application" event callbacks
 2. __Integrated modules__: Modules assume a larger role, enabling the developer to implement module-specific functionality
 3. __HMVC__: HMVC requests can now be sent between modules
 4. __Responder__: Response data and formatting can be altered in a dynamic, "controller-unaware" way

####HTTP Client
A (heavily) modified extension of the library in Phalcon incubator. Features include:
 1. __Request & Response__: `Request` and `Response` classes implement an common abstract `Message` class
 2. __Adapters__: Adapters allow for the use of different HTTP transports; cURL and stream adapters are included
 3. __Client__: The `Client` class provides a simple API to the underlying messages and adapters
 
####Web Services
Allows the developer to create interfaces that interact with web-based APIs.
