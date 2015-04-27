namespace Phalconry\Mvc;

use Phalcon\Mvc\User\Component;
use Phalcon\Http\ResponseInterface;
use InvalidArgumentException;

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

	/**
	 * Sets the type of response
	 *
	 * @param string type Response type
	 * @throws \InvalidArgumentException if type does not have an associated class
	 */
	public function setType(string type) -> void
    {
		if ! isset this->_typeClasses[type] {
			throw new InvalidArgumentException();
		}

		let this->_type = type;
	}

	/**
	 * Returns the response type
	 *
	 * @return string
	 */
	public function getType() -> string
    {
		return this->_type;
	}

	/**
	 * Whether the current response type is identical to the type given
	 *
	 * @param string type
	 */
	public function isType(string type) -> boolean
    {
		return this->_type === type;
	}

	/**
	 * Whether the given or current response type returns structured data
	 *
	 * @param string type [Optional] Default is null, returns if current type is data
	 */
	public function isDataType(var type = null) -> boolean
    {
        if typeof type == "null" {
			let type = this->_type;
		}

		return in_array(type, this->_dataTypes, true);
	}

	/**
	 * Sets the classname for a given response type
	 *
	 * @param string type
	 * @param string className
	 */
	public function setTypeClass(string type, string! className) -> void
    {
		let this->_typeClasses[type] = className;
	}

	/**
	 * Returns the classname for a given response type, or null if none exists
	 *
	 * @param string type
	 * @return string|null
	 */
	public function getTypeClass(string type) -> string|null
    {
		return isset this->_typeClasses[type] ? this->_typeClasses[type] : null;
	}

	/**
	 * Gets/sets whether to try to fill empty response content
	 *
	 * If true (default), attempts to fill empty response content with the value returned by the controller.
	 *
	 * @param bool value [Optional] New value
	 * @return bool Current value
	 */
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
	 * If the controller returns boolean false or the response object, no modification takes place.
	 *
	 * If this->fillEmptyContent() == true (default), attempts to fill empty response content with
	 * the value returned by the controller.
	 *
	 * @param \Phalcon\Http\ResponseInterface response
	 */
	public function respond(<ResponseInterface> response) -> void
    {
        var eventsManager, typeClass, responseType, returnedValue, content;

		let eventsManager = this->getEventsManager();
		let typeClass = this->_typeClasses[this->_type];
		let responseType = new {typeClass}();
		let returnedValue = response->{"getDI"}()->getShared("dispatcher")->getReturnedValue();

		if typeof eventsManager == "object" {
			eventsManager->fire("responder:beforeRespond", this, response);
		}

		// If controller returns boolean false or the response object, no modification takes place
		if returnedValue !== false && returnedValue !== response {

            if this->_fillEmptyContent {

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

			response->setContentType(responseType->getContentType());
		}

		if typeof eventsManager == "object" {
			eventsManager->fire("responder:respond", this, response);
		}

		response->send();
	}

}
