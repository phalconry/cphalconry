namespace Phalconry\Mvc\Response;

use Phalcon\Http\ResponseInterface;

abstract class AbstractType implements TypeInterface
{

	public function setModifiedContent(<ResponseInterface> response, var content)
    {
		// do nothing
	}

	public function formatResponse(<ResponseInterface> response) 
    {
		// do nothing
	}

}
