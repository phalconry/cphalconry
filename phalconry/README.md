#`Phalconry`
The root namespace contains some useful utility classes.

##`VarType`
Provides consistent and performant methods for casting variables to various PHP types.
####Methods
  * __`toArray($arg)`__ Casts a variable to an array. If `$arg` is an array, it is returned. If `$arg` is not an object, it is cast to an array using `(array)$arg`. If `$arg` is an object, the function proceeds as follows:
    * Calls `toArray()` method, if it exists;
    * Calls `iterator_to_array()` if object implements `Traversable`
    * Calls `get_object_vars()`
  * __`toObject($arg)`__ Casts a variable to an object. If `$arg` is an object and not an instance of `stdClass`, it is first cast to an array using `VarType::toArray()` and subsequently cast to an object using `(object)$arg`. All other argument types are simply cast.
  * __`toArrays($arg)`__ Casts a variable to an array recursively. First, `$arg` is cast to an array using `VarType::toArray()`. It is then iterated over, and any array or object members are cast to an array (recursively) using `VarType::toArrays()`. 

##`Text`
__Extends `Phalcon\Text`__
####Methods
  * __`hasChars($str, $charlist)`__ Checks whether `$str` contains any (one or more) of the characters in `$charlist` and returns `boolean`.
  * __`pearCase($str)`__ Converts a string to a PEAR-style name (e.g. "Http_Request2_Response").
  * __`snakeCase($str)`__ Converts a string to snakecase. This is the same as `pearCase()` except lowercase.
  * __`studlyCase($str)`__ Converts a string to "studly caps" (e.g. "SomethingLikeThis").
  * __`camelCase($str)`__ Converts a string to camelcase. This is the same as `studlyCase()` except the first character is lowercase.
  * __`isJson($str)`__ Checks whether a string is valid JSON and returns `boolean`.
  * __`isXml($str)`__ Checks whether a string is valid XML and returns `boolean`.
  * __`isSerialized($str)`__ Checks whether a string is PHP serialized and returns `boolean`.
  * __`format($str, $template)`__ Replaces non-alphanumeric characters in `$template` with characters from `$str` in sequence.
  * __`between($str, $substr_start, $substr_end)`__ Returns the string found between two substrings within `$str`.
  * __`sentences($str, $num = 1, $strip_abbr = false)`__ Extracts a given number of sentences from a string. Accounts for some basic abbreviations (e.g. "Mr.", "Mrs.", "Co.", "Inc.") and allows the user to provide others so that the function does not interpret abbreviations containing `.` as the end of a sentence.
