namespace Phalconry\Mvc\Response;

use Phalcon\Http\ResponseInterface;

abstract class AbstractDataType extends AbstractType
{

	/**
	 * Name of key to use for response data
	 * @var string
	 */
	const RESPONSE_DATA_KEY = "data";

	/**
	 * Response options
	 * @var int
	 */
	protected options;

	/**
	 * Response content data
	 * @var array
	 */
	protected data;

	/**
	 * Extra response content
	 * @var array
	 */
	protected extra;

	public function __construct(var data = null)
    {
		let this->options = 0;
		let this->extra = [
			"meta": [],
			"prepend": [],
			"append": []
		];

		if typeof data != "null" {
			this->setData(data);
		}
	}

	public function setModifiedContent(<ResponseInterface> response, var content)
    {
		this->setData(content);
	}

	public function setData(var data) -> <AbstractDataType>
    {
		let this->data = this->valueToArray(data);

		return this;
	}

	public function getData()
    {
		return this->data;
	}

	public function prepend(string! key, var value)  -> <AbstractDataType>
    {
		let this->extra["prepend"][key] = value;

		return this;
	}

	public function append(string! key, var value) -> <AbstractDataType>
    {
		let this->extra["append"][key] = value;

		return this;
	}

	public function setMeta(string! key, var value) -> <AbstractDataType>
    {
		let this->extra["meta"][key] = value;

		return this;
	}

	public function getMeta()
    {
		return this->extra["meta"];
	}

	public function setOptions(var options) -> <AbstractDataType>
    {
		let this->options = options;

        return this;
	}

	public function getOptions()
    {
		return this->options;
	}

	public function addOption(int option) -> <AbstractDataType>
    {
		let this->options = this->options|option;

        return this;
	}

	public function clearOptions() -> <AbstractDataType>
    {
		let this->options = 0;

        return this;
	}

	public function getContent() -> array
    {
		var content, key, value;
        let content = [];

        for key, value in this->extra["prepend"] {
			let content[key] = is_callable(value) ? call_user_func(value) : value;
		}

        for key, value in this->extra["meta"] {
			let content[key] = is_callable(value) ? call_user_func(value) : value;
		}

		let content[self::RESPONSE_DATA_KEY] = this->getData();

        for key, value in this->extra["append"] {
			let content[key] = is_callable(value) ? call_user_func(value) : value;
		}

    	return content;
	}

	protected function valueToArray(value)
	{

		if typeof value == "array" {
			return value;
		}

		if class_exists("Util\\Typecast") {
			return \Util\Typecast::toArray(value);
		}

		if typeof value == "object" {
			return (value instanceof \Traversable) ? iterator_to_array(value) : get_object_vars(value);
		}

		return (array)value;
	}

}
