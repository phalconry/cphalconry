namespace Phalconry\Mvc\Application;

use Phalconry\Mvc\ApplicationAwareInterface;
use Phalcon\Http\ResponseInterface;

interface HandlerInterface extends ApplicationAwareInterface
{

	/**
	 * Handles the request and returns a response.
	 *
	 * @param string uri [Optional]
	 * @return \Phalcon\Http\ResponseInterface
	 */
    public function handle(uri = null) -> <ResponseInterface> | boolean;

}
