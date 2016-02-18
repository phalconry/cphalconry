<?php

namespace Phalconry\Http\Util;

/**
 * Class ContentType
 *
 * @author Kachit
 * @link https://github.com/Kachit/phalcon-lib/blob/master/src/Kachit/Phalcon/Utils/MimeType.php
 */
class MimeType
{

    const DOWNLOAD = "application/octet-stream";


    const TEXT = "text/plain";


    const HTML = "text/html";


    const XML = "application/xml";


    const JSON = "application/json";


    const JS = "application/javascript";


    const CSS = "text/css";


    const DEFAULT_HTTP = "text/html";


    const DEFAULT_FILE = "application/octet-stream";


    static protected $mimetypes;


    /**
     * Returns a mime/type by file extension
     *
     * @param string $extension Extension without dots (e.g. "html")
     * @param mixed $defaultValue 
     * @param string $default [Optional] Default value to return if mime/type is not found. Default is null
     * @return string 
     */
    public static function get($extension, $defaultValue = null) {}

    /**
     * Attempts to return a mime/type for a file
     *
     * @param string $filename The filename
     * @return string mime/type for the file, or the value of DEFAULT_FILE if not found
     */
    public static function getForFile($filename) {}

    /**
     * Attempts to return a mime/type for an HTTP response
     *
     * @param string $extension 
     * @return string for the extension, or the value of DEFAULT_HTTP if not found
     */
    public static function getForHttp($extension) {}

}
