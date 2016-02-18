namespace Phalconry\Events;

use Phalcon\Events\Manager;
use RuntimeException;

class GlobalManager extends Manager
{

    /**
     * @var boolean
     */
    protected static _created;

    /**
     * Protected constructor.
     */
    protected function __construct() {
    }

    /**
     * Create the single GlobalManager instance.
     *
     * @return \Phalconry\Events\GlobalManager
     *
     * @throws \RuntimeException if called more than once per request.
     */
    public static function create() {
        if typeof self::_created !== "null" {
            throw new RuntimeException("Only one instance of the global events manager may exist.");
        }
        let self::_created = true;
        return new GlobalManager();
    }

}
