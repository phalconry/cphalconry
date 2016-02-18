var ZephirApi = {"allClasses":{"Phalconry\\DI\\ServiceProviderInterface":{"type":"interface","name":"Phalconry\\DI\\ServiceProviderInterface","shortname":"ServiceProviderInterface"},"Phalconry\\Http\\Client":{"type":"class","name":"Phalconry\\Http\\Client","shortname":"Client"},"Phalconry\\Http\\Client\\Adapter\\AdapterInterface":{"type":"interface","name":"Phalconry\\Http\\Client\\Adapter\\AdapterInterface","shortname":"AdapterInterface"},"Phalconry\\Http\\Client\\Adapter\\Curl":{"type":"class","name":"Phalconry\\Http\\Client\\Adapter\\Curl","shortname":"Curl"},"Phalconry\\Http\\Client\\Adapter\\Exception":{"type":"class","name":"Phalconry\\Http\\Client\\Adapter\\Exception","shortname":"Exception"},"Phalconry\\Http\\Client\\Adapter\\Stream":{"type":"class","name":"Phalconry\\Http\\Client\\Adapter\\Stream","shortname":"Stream"},"Phalconry\\Http\\Client\\Exception":{"type":"class","name":"Phalconry\\Http\\Client\\Exception","shortname":"Exception"},"Phalconry\\Http\\Client\\Header":{"type":"class","name":"Phalconry\\Http\\Client\\Header","shortname":"Header"},"Phalconry\\Http\\Client\\Message":{"type":"class","name":"Phalconry\\Http\\Client\\Message","shortname":"Message"},"Phalconry\\Http\\Client\\Request":{"type":"class","name":"Phalconry\\Http\\Client\\Request","shortname":"Request"},"Phalconry\\Http\\Client\\Response":{"type":"class","name":"Phalconry\\Http\\Client\\Response","shortname":"Response"},"Phalconry\\Http\\Uri":{"type":"class","name":"Phalconry\\Http\\Uri","shortname":"Uri"},"Phalconry\\Http\\Util\\MimeType":{"type":"class","name":"Phalconry\\Http\\Util\\MimeType","shortname":"MimeType"},"Phalconry\\Mvc\\Application":{"type":"class","name":"Phalconry\\Mvc\\Application","shortname":"Application"},"Phalconry\\Mvc\\Application\\Bootstrap":{"type":"class","name":"Phalconry\\Mvc\\Application\\Bootstrap","shortname":"Bootstrap"},"Phalconry\\Mvc\\Env":{"type":"class","name":"Phalconry\\Mvc\\Env","shortname":"Env"},"Phalconry\\Mvc\\HmvcRequest":{"type":"class","name":"Phalconry\\Mvc\\HmvcRequest","shortname":"HmvcRequest"},"Phalconry\\Mvc\\Module":{"type":"class","name":"Phalconry\\Mvc\\Module","shortname":"Module"},"Phalconry\\Mvc\\Module\\Manager":{"type":"class","name":"Phalconry\\Mvc\\Module\\Manager","shortname":"Manager"},"Phalconry\\Mvc\\Responder":{"type":"class","name":"Phalconry\\Mvc\\Responder","shortname":"Responder"},"Phalconry\\Mvc\\Response\\AbstractDataType":{"type":"class","name":"Phalconry\\Mvc\\Response\\AbstractDataType","shortname":"AbstractDataType"},"Phalconry\\Mvc\\Response\\AbstractType":{"type":"class","name":"Phalconry\\Mvc\\Response\\AbstractType","shortname":"AbstractType"},"Phalconry\\Mvc\\Response\\TypeInterface":{"type":"interface","name":"Phalconry\\Mvc\\Response\\TypeInterface","shortname":"TypeInterface"},"Phalconry\\Mvc\\Response\\TypeJson":{"type":"class","name":"Phalconry\\Mvc\\Response\\TypeJson","shortname":"TypeJson"},"Phalconry\\Mvc\\Response\\TypeNone":{"type":"class","name":"Phalconry\\Mvc\\Response\\TypeNone","shortname":"TypeNone"},"Phalconry\\Mvc\\Response\\TypeText":{"type":"class","name":"Phalconry\\Mvc\\Response\\TypeText","shortname":"TypeText"},"Phalconry\\Mvc\\Response\\TypeView":{"type":"class","name":"Phalconry\\Mvc\\Response\\TypeView","shortname":"TypeView"},"Phalconry\\Mvc\\Response\\TypeXml":{"type":"class","name":"Phalconry\\Mvc\\Response\\TypeXml","shortname":"TypeXml"},"Phalconry\\WebService\\Factory":{"type":"class","name":"Phalconry\\WebService\\Factory","shortname":"Factory"},"Phalconry\\WebService\\Manager":{"type":"class","name":"Phalconry\\WebService\\Manager","shortname":"Manager"},"Phalconry\\WebService\\Service":{"type":"class","name":"Phalconry\\WebService\\Service","shortname":"Service"},"Phalconry\\WebService\\ServiceInterface":{"type":"interface","name":"Phalconry\\WebService\\ServiceInterface","shortname":"ServiceInterface"}},"allNamespaces":{"Phalconry":{"name":"Phalconry","shortName":"Phalconry","parentName":"","classes":[],"namespaces":["Phalconry\\DI","Phalconry\\Http","Phalconry\\Mvc","Phalconry\\WebService"]},"Phalconry\\DI":{"name":"Phalconry\\DI","shortName":"DI","parentName":"Phalconry","classes":["Phalconry\\DI\\ServiceProviderInterface"],"namespaces":[]},"Phalconry\\Http":{"name":"Phalconry\\Http","shortName":"Http","parentName":"Phalconry","classes":["Phalconry\\Http\\Client","Phalconry\\Http\\Uri"],"namespaces":["Phalconry\\Http\\Client","Phalconry\\Http\\Util"]},"Phalconry\\Http\\Client":{"name":"Phalconry\\Http\\Client","shortName":"Client","parentName":"Phalconry\\Http","classes":["Phalconry\\Http\\Client\\Exception","Phalconry\\Http\\Client\\Header","Phalconry\\Http\\Client\\Message","Phalconry\\Http\\Client\\Request","Phalconry\\Http\\Client\\Response"],"namespaces":["Phalconry\\Http\\Client\\Adapter"]},"Phalconry\\Http\\Client\\Adapter":{"name":"Phalconry\\Http\\Client\\Adapter","shortName":"Adapter","parentName":"Phalconry\\Http\\Client","classes":["Phalconry\\Http\\Client\\Adapter\\AdapterInterface","Phalconry\\Http\\Client\\Adapter\\Curl","Phalconry\\Http\\Client\\Adapter\\Exception","Phalconry\\Http\\Client\\Adapter\\Stream"],"namespaces":[]},"Phalconry\\Http\\Util":{"name":"Phalconry\\Http\\Util","shortName":"Util","parentName":"Phalconry\\Http","classes":["Phalconry\\Http\\Util\\MimeType"],"namespaces":[]},"Phalconry\\Mvc":{"name":"Phalconry\\Mvc","shortName":"Mvc","parentName":"Phalconry","classes":["Phalconry\\Mvc\\Application","Phalconry\\Mvc\\Env","Phalconry\\Mvc\\HmvcRequest","Phalconry\\Mvc\\Module","Phalconry\\Mvc\\Responder"],"namespaces":["Phalconry\\Mvc\\Application","Phalconry\\Mvc\\Module","Phalconry\\Mvc\\Response"]},"Phalconry\\Mvc\\Application":{"name":"Phalconry\\Mvc\\Application","shortName":"Application","parentName":"Phalconry\\Mvc","classes":["Phalconry\\Mvc\\Application\\Bootstrap"],"namespaces":[]},"Phalconry\\Mvc\\Module":{"name":"Phalconry\\Mvc\\Module","shortName":"Module","parentName":"Phalconry\\Mvc","classes":["Phalconry\\Mvc\\Module\\Manager"],"namespaces":[]},"Phalconry\\Mvc\\Response":{"name":"Phalconry\\Mvc\\Response","shortName":"Response","parentName":"Phalconry\\Mvc","classes":["Phalconry\\Mvc\\Response\\AbstractDataType","Phalconry\\Mvc\\Response\\AbstractType","Phalconry\\Mvc\\Response\\TypeInterface","Phalconry\\Mvc\\Response\\TypeJson","Phalconry\\Mvc\\Response\\TypeNone","Phalconry\\Mvc\\Response\\TypeText","Phalconry\\Mvc\\Response\\TypeView","Phalconry\\Mvc\\Response\\TypeXml"],"namespaces":[]},"Phalconry\\WebService":{"name":"Phalconry\\WebService","shortName":"WebService","parentName":"Phalconry","classes":["Phalconry\\WebService\\Factory","Phalconry\\WebService\\Manager","Phalconry\\WebService\\Service","Phalconry\\WebService\\ServiceInterface"],"namespaces":[]}},"classes":[],"namespaces":["Phalconry"]};