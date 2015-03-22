namespace Phalconry\Mvc;

class Dispatcher extends \Phalcon\Mvc\Dispatcher
{

	public function setDefaultNamespace(string namespaceName)
	{
		parent::setDefaultNamespace(namespaceName);
		let this->{"_namespaceName"} = namespaceName;
	}
	
}