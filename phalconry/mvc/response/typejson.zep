namespace Phalconry\Mvc\Response;

use Phalcon\Http\ResponseInterface;
use Phalconry\Http\Util\MimeType;

class TypeJson extends AbstractDataType implements \JsonSerializable
{

	public function formatResponse(<ResponseInterface> response)
    {
        var data, status;

		let data = this->getData();

		if ! data {
			let data = response->getContent();
		}

		this->setData(data);
		this->addOption(JSON_NUMERIC_CHECK);

        let status = response->getHeaders()->get("Status");

		if ! status {
			response->setStatusCode(200, "OK");
			let status = "200 OK";
		}

		this->prepend("status", (int)substr(status, 0, 3));
		this->prepend("message", substr(status, 4));

		if response->{"getDI"}()->getShared("request")->hasQuery("dev") {

			this->addOption(JSON_PRETTY_PRINT);

			this->append("diagnostics", response->{"getDI"}()->getShared("diagnostics")->getAll());
		}

		response->setContent(this->encode());
	}

	public function getContentType()
    {
		return MimeType::JSON;
	}

	public function encode()
    {
		return json_encode(this->getContent(), this->getOptions());
	}

	public function jsonSerialize()
    {
		return this->getContent();
	}

	protected function valueToArray(value) {

        if (is_object(value)) {
			if (method_exists(value, "jsonSerialize")) {
				return (array)value->jsonSerialize();
			}
        }

        return parent::valueToArray(value);
	}

}
