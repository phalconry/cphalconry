namespace Phalconry\Mvc\Response;
use Phalconry\Http\Util\MimeType;

class TypeNone extends AbstractType
{

	public function getContentType()
    {
		return MimeType::TEXT;
	}

}
