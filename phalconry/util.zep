namespace Phalconry;

class Util
{

	/**
	 * Converts a value to an array
	 *
	 * @param mixed
	 * @return array
	 */
	public static function toArray(var arg) -> array
	{

		if typeof arg == "array" {
			return arg;
		}

		if typeof arg == "object" {

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

	/**
	 * Converts a value to an object
	 *
	 * @param mixed
	 * @return object
	 */
	public static function toObject(var arg) -> object
	{

		if typeof arg == "object" {

			if (arg instanceof \stdClass) {
				return arg;
			}

			var objVars;
			let objVars = Util::toArray(arg);

			return (object)objVars;
		}

		return (object)arg;
	}

	/**
	 * Returns whether the given variable is a valid JSON string.
	 *
	 * @param mixed
	 * @return boolean
	 */
	public static function isJson(var arg) -> boolean
	{

		if typeof arg == "string" {

			var jsonData;
			let jsonData = json_decode(arg, true);

			if json_last_error() === JSON_ERROR_NONE {
				return typeof jsonData == "array";
			}
		}

		return false;
	}

}
