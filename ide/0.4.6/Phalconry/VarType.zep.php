<?php

namespace Phalconry;


class VarType
{

    const CAST_NUMERIC = 0;


    const FORCE_STRING = 1;


    const IGNORE_ERROR = 5;


    static protected $decimalPoint;


    /**
     * Converts a value to an array
     *
     * @param mixed $arg 
     * @param mixed  
     * @return array 
     */
    public static function toArray($arg) {}

    /**
     * Converts a value to an object
     *
     * @param mixed $arg 
     * @param mixed  
     * @return object 
     */
    public static function toObject($arg) {}

    /**
     * Converts a value to arrays recursively.
     *
     * @param mixed $arg 
     * @param mixed  
     * @return array 
     */
    public static function toArrays($arg) {}

    /**
     * Converts a value to objects recursively.
     * Objects are converted to instances of stdClass
     *
     * @param mixed $arg 
     * @param mixed  
     * @return object 
     */
    public static function toObjects($arg) {}

    /**
     * Converts a variable to a boolean value
     *
     * @param mixed $arg 
     * @return boolean 
     */
    public static function toBool($arg) {}

    /**
     * Convert value to a scalar value.
     *
     * @throws InvalidArgumentException if value can not be scalarized.
     * @param mixed $arg 
     * @param int $flags 
     * @param string $Value we"d like to be scalar.
     * @param int $$flags SCALAR_* flag bitwise mask.
     * @return string 
     */
    public static function toScalar($arg, $flags = 0) {}

    /**
     * If $value is a numeric string, it is converted to a float or integer depending
     * on whether a decimal point is present. Otherwise the original value is returned.
     *
     * @param mixed $value 
     * @param mixed $$value If numeric string, converted to integer or float.
     * @return scalar as string, integer, or float.
     */
    public static function toNumber($value) {}

    /**
     * Returns the decimal point for the current locale
     *
     * @return string 
     */
    public static function getDecimalPoint() {}

}
