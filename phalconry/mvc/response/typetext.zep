namespace Phalconry\Mvc\Response;

use Phalcon\Http\ResponseInterface;
use Phalconry\Http\Util\MimeType;

class TypeText extends AbstractType
{

	public function setModifiedContent(<ResponseInterface> response, var content)
    {
		if is_string(content) {
			response->setContent(strip_tags(content));
		}
	}

	public function getContentType()
    {
		return MimeType::TEXT;
	}

}
