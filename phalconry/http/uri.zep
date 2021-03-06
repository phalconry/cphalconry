namespace Phalconry\Http;
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
class Uri
{

    protected parts = [];

    public function __construct(var uri = null)
    {
        var query;

        if typeof uri != "null" {

            if typeof uri == "string" {

                let this->parts = parse_url(uri);

                if isset this->parts["query"] && ! empty this->parts["query"] {
                    let query = [];
                    parse_str(this->parts["query"], query);
                    let this->parts["query"] = query;
                }

            } elseif typeof uri == "array" {
                let this->parts = uri;
            } elseif (uri instanceof Uri) {
                let this->parts = uri->parts;
            }
        }
    }

    public function __toString() -> string
    {
        return this->build();
    }

    public function __unset(string! name) -> void
    {
        unset this->parts[name];
    }

    public function __set(string! name, var value) -> void
    {
        let this->parts[name] = value;
    }

    public function __get(string! name)
    {
        return this->parts[name];
    }

    public function __isset(string! name) -> boolean
    {
        return isset this->parts[name];
    }

    public function build() -> string
    {
        var uri, parts;

        let uri = "",
            parts = this->parts;

        if isset parts["scheme"] && ! empty parts["scheme"] {

            let uri .= parts["scheme"] . ":";

            if isset parts["host"] && ! empty parts["host"] {

                let uri .= "//";

                if isset parts["user"] && ! empty parts["user"] {

                    let uri .= parts["user"];

                    if isset parts["pass"] && ! empty parts["pass"] {
                        let uri .= ":" . parts["pass"];
                    }

                    let uri .= "@";
                }

                let uri .= parts["host"];
            }
        }

        if isset parts["port"] && ! empty parts["port"] {
            let uri .= ":" . parts["port"];
        }

        if isset parts["path"] && ! empty parts["path"] {
            let uri .= parts["path"];
        }

        if isset parts["query"] && ! empty parts["query"] {
            let uri .= "?" . this->buildQuery(parts["query"]);
        }

        if isset parts["fragment"] && ! empty parts["fragment"] {
            let uri .= "#" . parts["fragment"];
        }

        return uri;
    }

    public function buildQuery(var query) -> string
    {
        return (typeof query == "array") ? http_build_query(query) : query;
    }

    public function resolve(var uri) -> <Uri>
    {
        var newUri;
        let newUri = new Uri(this);

        newUri->extend(uri);

        return newUri;
    }

    public function extend(var uri) -> <Uri>
    {
        if typeof uri == "object" && uri instanceof Uri {
            let uri = new Uri(uri);
        }

        let this->parts = array_merge(
            this->parts,
            array_diff_key(uri->parts, array_flip(["query", "path"]))
        );

        if ! empty uri->parts["query"] {
            this->extendQuery(uri->parts["query"]);
        }

        if ! empty uri->parts["path"] {
            this->extendPath(uri->parts["path"]);
        }

        return this;
    }

    public function extendQuery(array params) -> <Uri>
    {

        if isset this->parts["query"] && ! empty this->parts["query"] {
            let this->parts["query"] = array_merge(this->parts["query"], params);
        } else {
            let this->parts["query"] = params;
        }

        return this;
    }

    public function extendPath(string path) -> <Uri>
    {

        if "" === path {
            return this;
        }

        if starts_with(path, "/") {
            let this->parts["path"] = path;
            return this;
        }

        if ! isset this->parts["path"] || empty this->parts["path"] {
            let this->parts["path"] = "/" . path;
            return this;
        }

        let this->parts["path"] = substr(this->parts["path"], 0, strrpos(this->parts["path"], "/") + 1) . path;

        return this;
    }

}
