namespace Phalconry\Mvc\Response;

use Phalcon\Http\ResponseInterface;
use Phalconry\Http\Util\MimeType;
use Util\Xml;

class TypeXml extends AbstractDataType
{

	public function formatResponse(<ResponseInterface> response)
    {
		var data, status;

        let data = this->getData();

		if ! data {
			let data = response->getContent();
		}

		this->setData(data);

        let status = response->getHeaders()->get("Status");

		if ! status {
			response->setStatusCode(200, "OK");
			let status = "200 OK";
		}

		this->prepend("status", (int)substr(status, 0, 3));
		this->prepend("message", substr(status, 4));

		if response->{"getDI"}()->getRequest()->hasQuery("dev") {
			this->append("diagnostics", response->{"getDI"}()->getShared("diagnostics")->getAll());
		}

		response->setContent(this->encode());
	}

	public function getContentType()
    {
		return MimeType::XML;
	}

	public function encode()
    {
        return Xml::writeDocument(this->getContent());
	}

}
