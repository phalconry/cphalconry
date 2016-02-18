<?php

namespace Phalconry;


class Text extends Phalcon\Phalcon\Text
{
    /**
     * Last error
     *
     * @var string
     */
    static protected $lastError;


    /**
     * Whether the given string contains any of the characters in charlist
     *
     * @param string $str 
     * @param string $charlist 
     * @return boolean if str contains any of the characters in charlist, otherwise false
     */
    public static function hasChars($str, $charlist) {}

    /**
     * Converts a string to a PEAR-like class name. (e.g. "Http_Request2_Response")
     *
     * @param string $str 
     * @param string  
     * @return string 
     */
    public static function pearCase($str) {}

    /**
     * Converts a string to "snake_case"
     *
     * @param string $str 
     * @param string  
     * @return string 
     */
    public static function snakeCase($str) {}

    /**
     * Converts a string to "StudlyCaps"
     *
     * @param string $str 
     * @param string  
     * @return string 
     */
    public static function studlyCase($str) {}

    /**
     * Converts a string to "camelCase"
     *
     * @param string $str 
     * @param string  
     * @return string 
     */
    public static function camelCase($str) {}

    /**
     * Returns whether the given variable is a valid JSON string.
     *
     * @param string $str 
     * @param string  
     * @return boolean 
     */
    public static function isJson($str) {}

    /**
     * Checks whether the given value is a valid XML string.
     *
     * @param string $str 
     * @param string $$arg Value to check if XML.
     * @return boolean if value is a valid XML string, otherwise false.
     */
    public static function isXml($str) {}

    /**
     * Checks whether the given value is a valid serialized string.
     *
     * @param string $str 
     * @param string $$data Value to check if serialized
     * @return boolean If value is a valid serialized string, otherwise false.
     */
    public static function isSerialized($str) {}

    /**
     * Formats a string by injecting non-numeric characters into
     * the string in the positions they appear in the template.
     *
     * @param string $str 
     * @param string $template 
     * @param string $$string The string to format
     * @param string $$template String format to apply
     * @return string string.
     */
    public static function format($str, $template) {}

    /**
     * Returns 1st occurance of text between two strings.
     * The "between" strings are not included in output.
     *
     * @param string $str 
     * @param string $substr_start 
     * @param string $substr_end 
     * @param string $$string The string in which to search.
     * @param string $$substr_start The starting string.
     * @param string $$substr_end The ending string.
     * @return string between $start and $end.
     */
    public static function between($str, $substr_start, $substr_end) {}

    /**
     * Get a given number of sentences from a string.
     *
     * @param boolean|array $strip_abbr Whether to strip abbreviations (they break the function).
     * Pass an array to account for those abbreviations as well.
     * @param string $str 
     * @param int $num 
     * @param mixed $strip_abbr 
     * @param string $$text The full string of sentences.
     * @param int $$num Number of sentences to return. Default 1.
     * @return string number of sentences.
     */
    public static function sentences($str, $num = 1, $strip_abbr = false) {}

    /**
     * Class error handler
     *
     * @param int $errorNum 
     * @param string $errorMsg 
     * @return boolean 
     */
    public static function _handleError($errorNum, $errorMsg) {}

}
