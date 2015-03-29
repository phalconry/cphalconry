namespace Phalconry\Mvc\Response;

use Phalcon\Http\ResponseInterface;
use Phalconry\Http\Util\MimeType;

class TypeView extends AbstractType
{

	public function setModifiedContent(<ResponseInterface> response, var content)
    {
		response->setContent(content);
	}

	public function getContentType()
    {
		return MimeType::HTML;
	}

}
