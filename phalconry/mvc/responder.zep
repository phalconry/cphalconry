namespace Phalconry\Mvc;

use Phalcon\Mvc\User\Component;
use Phalcon\Http\ResponseInterface;
use Phalconry\Http\Util\MimeType;
use InvalidArgumentException;
use Util\Xml;

class Responder extends Component
{
	/**
	 * Designates a "view" response
	 * @var string
	 */
	const TYPE_VIEW = "view";

	/**
	 * Designates a "text" response
	 * @var string
	 */
	const TYPE_TEXT = "text";

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
	 * Response types that send structured data
	 * @var array
	 */
	protected _dataTypes = ["json", "xml"];

	/**
	 * The response
	 * @var \Phalcon\Http\ResponseInterface
	 */
	protected _response;

	/**
	 * Response data
	 * @var mixed
	 */
	protected _responseData;

	/**
	 * Prepended response data
	 * @var array
	 */
	protected _beforeData = [];

	/**
	 * Appended response data
	 * @var array
	 */
	protected _afterData = [];

	/**
	 * Response options
	 * @var int
	 */
	protected _options = 0;

	/**
	 * Sets the type of response
	 *
	 * @param string type Response type
	 */
	public function setType(string type) -> void
    {
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
        var eventsManager, rtnVal, content;

		let this->_response = response;
		let eventsManager = this->getEventsManager();
		let rtnVal = response->{"getDI"}()->getShared("dispatcher")->getReturnedValue();

		if typeof eventsManager == "object" {
			eventsManager->fire("responder:beforeRespond", this, response);
		}

		// If controller returns boolean false or the response object, no modification takes place
		if rtnVal !== false && rtnVal !== response {

			let content = response->getContent();

			// If content is empty, use the returned value
			if empty content && !empty rtnVal {

				if "view" === this->_type {
					response->setContent(rtnVal);
				} else {
					let this->_responseData = rtnVal;
				}
            }

			// Format the response
			this->formatResponse(response);
		}

		if typeof eventsManager == "object" {
			eventsManager->fire("responder:respond", this, response);
		}

		response->send();
	}

	public function setOptions(var options) -> void
    {
		let this->_options = options;
	}

	public function getOptions()
    {
		return this->_options;
	}

	public function addOption(int option) -> void
    {
		let this->_options = this->_options | option;
	}

	public function prependResponseData(string! key, var value) -> void
    {
		let this->_beforeData[key] = value;
	}

	public function appendResponseData(string! key, var value) -> void
    {
		let this->_afterData[key] = value;
	}

	protected function formatResponse(<ResponseInterface> response) -> void
	{
		string method;

		let method = "format" . ucfirst(this->_type);

		if method_exists(this, method) {
			this->{method}(response);
		}
	}

	protected function formatText(<ResponseInterface> response) -> void
	{
		response->setContentType(MimeType::TEXT);
	}

	protected function formatJson(<ResponseInterface> response) -> void
	{
		this->formatDataResponse(response);
		this->addOption(JSON_NUMERIC_CHECK);
		response->setContentType(MimeType::JSON);
		response->setContent(json_encode(this->buildDataResponseContent(), this->_options));
	}

	protected function formatXml(<ResponseInterface> response) -> void
	{
		this->formatDataResponse(response);
		response->setContentType(MimeType::XML);
		response->setContent(Xml::writeDocument(this->buildDataResponseContent()));
	}

	protected function formatDataResponse(<ResponseInterface> response) -> void
	{
		var data, status, di;

		let data = this->_responseData;

		if typeof data == "null" {
			let data = response->getContent();
		}

        let status = response->getHeaders()->get("Status");

		if ! status {
			response->setStatusCode(200, "OK");
			let status = "200 OK";
		}

		this->prependResponseData("status", (int)substr(status, 0, 3));
		this->prependResponseData("message", substr(status, 4));

		let di = response->{"getDI"}();

		if typeof di == "object" {

			if di->getShared("request")->hasQuery("dev") {

				if "json" === this->_type {
					this->addOption(JSON_PRETTY_PRINT);
				}

				if di->has("diagnostics") {
					this->appendResponseData("diagnostics", di->getShared("diagnostics")->getAll());
				}
			}
		}
	}

	protected function buildDataResponseContent() -> array
    {
		var content, key, value;
        let content = [];

        for key, value in this->_beforeData {
			let content[key] = is_callable(value) ? call_user_func(value) : value;
		}

		let content["data"] = this->_responseData;

        for key, value in this->_afterData {
			let content[key] = is_callable(value) ? call_user_func(value) : value;
		}

    	return content;
	}

}
