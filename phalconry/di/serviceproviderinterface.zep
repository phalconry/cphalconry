namespace Phalconry\DI;

use Phalcon\DiInterface;

interface ServiceProviderInterface
{

	/**
	 * Registers the service components
	 *
	 * @param \Phalcon\DiInterface $di
	 */
	public function register(<DiInterface> di);

}
