namespace Phalconry;

use Phalcon\Config as BaseConfig;
use InvalidArgumentException;

class Config extends BaseConfig
{

    /**
     * @var object
     */
    protected _configParent;

    /**
     * Sets the parent object.
     *
     * @param object parentObject
     */
    public function setParent(var parentObject) -> void
    {
        if typeof parentObject !== "object" {
            throw new InvalidArgumentException("Expecting object, given: " . gettype(parentObject));
        }

        let this->_configParent = parentObject;
    }

    /**
     * Returns the parent object.
     *
     * @return object|null
     */
    public function getParent() -> object | null
    {
        return this->_configParent;
    }

    /**
     * Checks whether the config has a parent object.
     *
     * @return boolean
     */
    public function hasParent() -> boolean
    {
        return (typeof this->_configParent == "object");
    }

	/**
	 * Sets an attribute using the array-syntax
	 *
	 *<code>
	 * $config['database'] = array('type' => 'Sqlite');
	 *</code>
	 */
	public function offsetSet(var index, var value)
	{
		let index = strval(index);

		if typeof value === "array" {
			let this->{index} = new self(value);
		} else {
			let this->{index} = value;
		}
	}

	/**
	 * Returns a Config object for a given section.
	 *
	 * @param string section Section name.
	 * @return \Phalconry\Config
	 *
	 * @throws \Phalconry\Exception if section exists but isn't a Config.
	 */
	public function getConfig(string! section) -> <Config>
	{
		var config;

		if fetch config, this->{section} {

			if typeof config != "object" {
				throw new Exception("Config section '" . section . "' is not an object");
			}

		} else {
			let config = new self();
			let this->{section} = config;
		}

		return config;
	}

    /**
     * Get an item using "dot" notation.
     *
     * @param  string  key
     * @param  mixed   defaultValue
     * @return mixed
     */
    public function get(var key, var defaultValue = null) -> var
    {
		let key = strval(key);

        if typeof this->{key} !== "null" {
            return this->{key};
        }

		var currentItem, segment;

		let currentItem = this;

		for segment in explode(".", key) {

            if typeof currentItem != "object" || typeof currentItem->{segment} == "null" {
                return defaultValue;
            }

			let currentItem = currentItem->{segment};
        }

        return currentItem;
    }

    /**
     * Set an item using "dot" notation.
     *
     * @param  string  key
     * @param  mixed   value
     * @return \Phalconry\Config
     */
    public function set(var key, var value) -> <Config>
    {
        var segments, segment, currentItem, realKey;

        let key = strval(key);

        if memstr(key, ".") {

			let segments = explode(".", key);
			let realKey = array_pop(segments);
			let currentItem = this;

			for segment in segments {

	            if typeof currentItem->{segment} != "object" {
					let currentItem->{segment} = new self();
	            }

				let currentItem = currentItem->{segment};
	        }

			if typeof value === "array" {
				let currentItem->{realKey} = new self(value);
			} else {
	        	let currentItem->{realKey} = value;
			}

		} else {

			if typeof value === "array" {
				let this->{key} = new self(value);
			} else {
	        	let this->{key} = value;
			}
		}

		return this;
    }

    /**
     * Check if an item exists using "dot" notation.
     *
     * @param  string  key
     * @return bool
     */
    public function has(var key) -> boolean
    {
		let key = strval(key);

        if typeof this->{key} !== "null" {
            return true;
        }

		var currentItem, segment;

		let currentItem = this;

		for segment in explode(".", key) {

            if typeof currentItem != "object" || typeof currentItem->{segment} == "null" {
                return false;
            }

			let currentItem = currentItem->{segment};
        }

        return true;
    }

	/**
	 * Restores the state of a Phalcon\Config object
	 */
	public static function __set_state(array! data) -> <Config>
	{
		return new self(data);
	}
}
