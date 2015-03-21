namespace Phalconry;

class ArrayObject extends \ArrayObject implements \JsonSerializable
{
	
	public function __construct(var input = [], int flags = \ArrayObject::ARRAY_AS_PROPS, string iterator_class = "ArrayIterator") 
	{
		parent::__construct(input, flags, iterator_class);
	}
	
	public function __call(string func, var args) 
	{
		
		string arrayFunc;
		
		let arrayFunc = "array_" . \Phalcon\Text::uncamelize(func);
		
		if function_exists(arrayFunc) {
			
			var fnArgs;
			
			let fnArgs = array_merge([this->getArrayCopy()], args);
			
			return call_user_func_array(arrayFunc, fnArgs);
		
		} else {
			throw new \BadMethodCallException();
		}
	}
	
	public function jsonSerialize() 
	{
		return this->getArrayCopy();
	}
	
	public function toArray() -> array 
	{
		return this->getArrayCopy();
	}
	
}
