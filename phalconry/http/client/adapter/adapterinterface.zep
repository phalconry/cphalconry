namespace Phalconry\Http\Client\Adapter;

use Phalconry\Http\Client\Request;

interface AdapterInterface
{

    public function setOption(var option, var value);

    public function setOptions(var options);

    public function setTimeout(var timeout);

	public function setProxy(var host, var port = 8080, var user = null, var pass = null);

    public function get(<Request> request, var params = []);

    public function head(<Request> request, var params = []);

    public function delete(<Request> request, var params = []);

    public function post(<Request> request, var params = []);

    public function put(<Request> request, var params = []);

	public function __invoke(<Request> request);

}
