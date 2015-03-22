namespace Phalconry;

class Util
{

	public static function toArray(var arg) -> array
	{
	
		if (typeof arg == "array") {
			return arg;
		}
		
		if (typeof arg == "object") {
			
			if method_exists(arg, "toArray") {
				return arg->toArray();
			}
			
			if (arg instanceof \Traversable) {
				return iterator_to_array(arg);
			}
			
			return get_object_vars(arg);
		}
		
		return (array)arg;
	}
	
	public static function toObject(var arg) -> object
	{
		
		if (typeof arg == "object") {
			
			if (arg instanceof \stdClass) {
				return arg;
			}
			
			var objVars;
			
			let objVars = Util::toArray(arg);
			
			return (object)objVars;
		}
		
		return (object)arg;
	}
	
	public static function isJson(var arg) -> boolean
	{
		
		if (typeof arg == "string") {
		
			var jsonData;
		
			let jsonData = json_decode(arg, true);
			
			if (json_last_error() === JSON_ERROR_NONE) {
				return typeof jsonData == "array";
			}	
		}
		
		return false;
	}

}