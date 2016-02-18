namespace Phalconry;

use InvalidArgumentException;

class VarType
{

	const CAST_NUMERIC = 0;
	const FORCE_STRING = 1;
	const IGNORE_ERROR = 5;

	protected static decimalPoint;

	/**
	 * Converts a value to an array
	 *
	 * @param mixed
	 * @return array
	 */
	public static function toArray(var arg) -> array
	{
		if typeof arg === "array" {
			return arg;
		}

		if typeof arg === "object" {

			if method_exists(arg, "toArray") {
				return arg->toArray();
			}

			return (arg instanceof \Traversable) ? iterator_to_array(arg) : get_object_vars(arg);
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
		if typeof arg === "object" {
			return (arg instanceof \stdClass) ? arg : (object)VarType::toArray(arg);
		}

		return (object)arg;
	}

	/**
	 * Converts a value to arrays recursively.
	 *
	 * @param mixed
	 * @return array
	 */
	public static function toArrays(var arg) -> array
	{
		var arr, key, value;

		let arr = [];

		for key, value in VarType::toArray(arg) {

			if typeof value === "array" || typeof value === "object" {
				let arr[key] = VarType::toArrays(value);
			} else {
				let arr[key] = value;
			}
		}

		return arr;
	}

	/**
	 * Converts a value to objects recursively.
	 *
	 * Objects are converted to instances of stdClass
	 *
	 * @param mixed
	 * @return object
	 */
	public static function toObjects(var arg) -> object
	{
		var arr, key, value;

		let arr = [];

		for key, value in VarType::toArray(arg) {

			if typeof value === "array" || typeof value === "object" {
				let arr[key] = VarType::toObjects(value);
			} else {
				let arr[key] = value;
			}
		}

		return (object)arr;
	}

	/**
	 * Converts a variable to a boolean value
	 *
	 * @param mixed arg
	 * @return boolean
	 */
	public static function toBool(var arg) -> boolean
	{
		if typeof arg === "boolean" {
			return arg;
		}

		if is_numeric(arg) {
			return arg > 0;
		}

		if typeof arg === "string" {

			let arg = strtolower(arg);

			if "y" === arg || "yes" === arg || "true" === arg {
				return true;
			}

			if "n" === arg || "no" === arg || "false" === arg {
				return false;
			}
		}

		return (boolean)arg;
	}

	/**
	 * Convert value to a scalar value.
	 *
	 * @param string Value we"d like to be scalar.
	 * @param int $flags SCALAR_* flag bitwise mask.
	 * @return string
	 * @throws InvalidArgumentException if value can not be scalarized.
	 */
	public static function toScalar(var arg, int flags = 0)
	{
		switch gettype(arg) {

			case "string":
				return (flags & self::CAST_NUMERIC) ? VarType::toNumber(arg) : arg;

			case "double":
			case "integer":
				return (flags & self::FORCE_STRING) ? (string)arg : arg;

			case "boolean":
				return (flags & self::FORCE_STRING) ? (arg ? "1" : "0") : (arg ? 1 : 0);

			case "NULL":
				return "";

			case "object":
				if method_exists(arg, "__toString") {
					return arg->__toString();
				}
				// allow pass-thru
		}

		if (flags & self::IGNORE_ERROR) {
			return "";
		}

		throw new InvalidArgumentException("Cannot cast value to scalar (given: '" . gettype(arg) . "').");
	}

	/**
	 * If $value is a numeric string, it is converted to a float or integer depending
	 * on whether a decimal point is present. Otherwise the original value is returned.
	 *
	 * @param mixed $value If numeric string, converted to integer or float.
	 * @return scalar Value as string, integer, or float.
	 */
	public static function toNumber(var value)
	{
		if typeof value === "string" && is_numeric(value) {
			return memstr(value, self::getDecimalPoint()) ? (float)value : (int)value;
		}

		return value;
	}

	/**
	 * Returns the decimal point for the current locale
	 *
	 * @return string
	 */
	public static function getDecimalPoint() -> string
	{
		var decimal;
		let decimal = self::decimalPoint;

		if typeof decimal === "null" {
			var loc;
			let loc = localeconv();
			let decimal = isset loc["decimal_point"] ? loc["decimal_point"] : ".";
			let self::decimalPoint = decimal;
		}

		return decimal;
	}

}
