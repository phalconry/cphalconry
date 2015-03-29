namespace Phalconry\Mvc\Response;

use Phalcon\Http\ResponseInterface;

interface TypeInterface
{

	public function getContentType();

	public function setModifiedContent(<ResponseInterface> response, var content);

	public function formatResponse(<ResponseInterface> response);

}
