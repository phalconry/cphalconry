namespace Phalconry\Mvc\Application;

use Phalconry\Mvc\ApplicationInterface;

interface BootstrapInterface
{

    /**
     * Boots the application.
     *
     * @param \Phalconry\Mvc\ApplicationInterface app
     * @return void
     */
    public function boot(<ApplicationInterface> app) -> void;

}
