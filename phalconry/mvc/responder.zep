namespace Phalconry\Mvc;

use Phalcon\Mvc\User\Component;
use Phalcon\Http\ResponseInterface;

class Responder extends Component
{

	/**
	 * Disables the responder
	 * @var boolean
	 */
	const TYPE_NONE = "";

	/**
	 * Designates a "text" response
	 * @var string
	 */
	const TYPE_TEXT = "text";

	/**
	 * Designates a "view" response
	 * @var string
	 */
	const TYPE_VIEW = "view";

	/**
	 * Designates a "json" response
	 * @var string
	 */
	const TYPE_JSON = "json";

	/**
	 * Designates an "xml" response
	 * @var string
	 */
	const TYPE_XML = "xml";

	/**
	 * Response type
	 * @var string
	 */
	protected _type = "view";

	/**
	 * Response type classes
	 * @var array
	 */
	protected _typeClasses = [
		"": "Phalconry\\Mvc\\Response\\TypeNone",
		"view": "Phalconry\\Mvc\\Response\\TypeView",
		"text": "Phalconry\\Mvc\\Response\\TypeText",
		"json": "Phalconry\\Mvc\\Response\\TypeJson",
		"xml": "Phalconry\\Mvc\\Response\\TypeXml"
	];

	/**
	 * Response types that send structured data
	 * @var array
	 */
	protected _dataTypes = ["json", "xml"];

	/**
	 * Whether to fill empty content with the retuned value
	 * @var boolean
	 */
	protected _fillEmptyContent = true;

	public function setType(string type) -> void
    {
		let this->_type = type;
	}

	public function getType() -> string
    {
		return this->_type;
	}

	public function isType(string type) -> boolean
    {
		return this->_type === type;
	}

	public function isDataType(var type = null) -> boolean
    {

        if typeof type == "null" {
			let type = this->_type;
		}

		return in_array(type, this->_dataTypes, true);
	}

	public function setTypeClass(string type, string! className) -> void
    {
		let this->_typeClasses[type] = className;
	}

	public function getTypeClass(string type) -> string|null
    {
		return isset this->_typeClasses[type] ? this->_typeClasses[type] : null;
	}

	public function fillEmptyContent(var value = null) -> boolean
    {
        if typeof value != "null" {
			let this->_fillEmptyContent = (bool)value;
		}

		return this->_fillEmptyContent;
	}

	/**
	 * Modifies and sends the response
	 *
	 * @param \Phalcon\Http\ResponseInterface response
	 */
	public function respond(<ResponseInterface> response) -> void
    {
        var typeClass, responseType, returnedValue, content;

		let typeClass = this->getTypeClass(this->getType());
		let responseType = new {typeClass}();
		let returnedValue = response->{"getDI"}()->getShared("dispatcher")->getReturnedValue();

		// If controller returns boolean false or the response object, no modification takes place
		if returnedValue !== false {
            if returnedValue !== response {

                if this->fillEmptyContent() {

        			let content = response->getContent();

        			// If content is empty, use the returned value
        			if empty content {
                        if ! empty returnedValue {
                            responseType->setModifiedContent(response, returnedValue);
                        }
                    }
                }

    			// Allow the response type to format the response
    			responseType->formatResponse(response);
            }
		}

		response->setContentType(responseType->getContentType());

		response->send();
	}

}
