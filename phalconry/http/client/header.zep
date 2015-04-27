/*
  +------------------------------------------------------------------------+
  | Phalcon Framework                                                      |
  +------------------------------------------------------------------------+
  | Copyright (c) 2011-2012 Phalcon Team (http://www.phalconphp.com)       |
  +------------------------------------------------------------------------+
  | This source file is subject to the New BSD License that is bundled     |
  | with this package in the file docs/LICENSE.txt.                        |
  |                                                                        |
  | If you did not receive a copy of the license and are unable to         |
  | obtain it through the world-wide-web, please send an email             |
  | to license@phalconphp.com so we can send you a copy immediately.       |
  +------------------------------------------------------------------------+
  | Author: Tuğrul Topuz <tugrultopuz@gmail.com>                           |
  +------------------------------------------------------------------------+
*/
namespace Phalconry\Http\Client;

/**
 * Represents a collection of HTTP headers
 */
class Header implements \Countable
{

    const BUILD_STATUS = 1;
    const BUILD_FIELDS = 2;

    public version = "1.0";
    public statusCode = 0;
    public statusMessage = "";
    public status = "";
    private fields = [];

    protected static messages;

    /**
     * Sets a single header field
     *
     * @param string name
     * @param mixed value
     */
    public function set(string name, var value) -> void
    {
        let this->fields[name] = value;
    }

    /**
     * Sets an array of headers
     *
     * @param array fields
     */
    public function setMultiple(array fields) -> void
    {
        let this->fields = fields;
    }

    /**
     * Adds an array of headers
     *
     * @param array fields
     */
    public function addMultiple(array fields) -> void
    {
        let this->fields = array_combine(this->fields, fields);
    }

    /**
     * Returns a single header field
     *
     * @param string name
     * @return string
     */
    public function get(string name)
    {
        return this->fields[name];
    }

    /**
     * Returns all header fields
     *
     * @return array
     */
    public function getAll() -> array
    {
        return this->fields;
    }

    /**
     * Determine if a header exists with a specific key.
     *
     * @param string name Key to lookup
     * @return boolean
     */
    public function has(string name) -> boolean
    {
        var key, value;

        for key, value in this->getAll() {
            if starts_with(key, name, true) {
                return true;
            }
        }

        return false;
    }

    /**
     * Removes a single header by name
     *
     * @param string name
     */
    public function remove(string name) -> void
    {
        unset this->fields[name];
    }

    /**
     * Parses an array or string of headers into the object
     *
     * @param string|array content
     * @return boolean
     */
    public function parse(var content) -> boolean
    {
        var status, field;

        if empty content {
            return false;
        }

        if typeof content == "string" {
            let content = array_filter(explode("\r\n", content));
        } elseif typeof content != "array" {
            return false;
        }

        let status = [];

        if preg_match("/^HTTP\/(\d(?:\.\d)?)\s+(\d{3})\s+(.+)/i", content[0], status) {
            let this->status = array_shift(content);
            let this->version = status[1];
            let this->statusCode = intval(status[2]);
            let this->statusMessage = status[3];
        }

        for field in content {

            if typeof field != "array" {
                let field = array_map("trim", explode(":", field, 2));
            }

            if count(field) == 2 {
                this->set(field[0], field[1]);
            }
        }

        return true;
    }

    /**
     * Builds the headers and possibly the fields
     *
     * @param int flags [Optional] Bitwise BUILD_* class constants. Default 0
     * @return array Header lines
     */
    public function build(int flags = 0) -> array
    {
        var lines, statusMsg, field, value;
        let lines = [];

        if (flags & self::BUILD_FIELDS) {

            let statusMsg = self::getStatusMessage(this->statusCode);

            if typeof statusMsg == "string" {
                let lines[] = "HTTP/" . this->version . " " . this->statusCode . " " . statusMsg;
            }
        }

        for field, value in this->fields {
            let lines[] = field . ": " . value;
        }

        if (flags & self::BUILD_FIELDS) {
            return implode("\r\n", lines);
        }

        return lines;
    }

    /**
     * Returns the number of header fields
     *
     * @return int
     */
    public function count() -> int
    {
        return count(this->fields);
    }

    /**
     * Returns message text for a given HTTP status code
     *
     * @param int code
     * @return string|null
     */
    public static function getStatusMessage(int code) -> string|null
    {
        if typeof self::messages == "null" {
            let self::messages = [
                // Informational 1xx
                100: "Continue",
                101: "Switching Protocols",
                // Success 2xx
                200: "OK",
                201: "Created",
                202: "Accepted",
                203: "Non-Authoritative Information",
                204: "No Content",
                205: "Reset Content",
                206: "Partial Content",
                // Redirection 3xx
                300: "Multiple Choices",
                301: "Moved Permanently",
                302: "Found", // 1.1
                303: "See Other",
                304: "Not Modified",
                305: "Use Proxy",
                // 306 is deprecated but reserved
                307: "Temporary Redirect",
                // Client Error 4xx
                400: "Bad Request",
                401: "Unauthorized",
                402: "Payment Required",
                403: "Forbidden",
                404: "Not Found",
                405: "Method Not Allowed",
                406: "Not Acceptable",
                407: "Proxy Authentication Required",
                408: "Request Timeout",
                409: "Conflict",
                410: "Gone",
                411: "Length Required",
                412: "Precondition Failed",
                413: "Request Entity Too Large",
                414: "Request-URI Too Long",
                415: "Unsupported Media Type",
                416: "Requested Range Not Satisfiable",
                417: "Expectation Failed",
                // Server Error 5xx
                500: "Internal Server Error",
                501: "Not Implemented",
                502: "Bad Gateway",
                503: "Service Unavailable",
                504: "Gateway Timeout",
                505: "HTTP Version Not Supported",
                509: "Bandwidth Limit Exceeded"
            ];
        }
        return isset self::messages[code] ? self::messages[code] : null;
    }

}
