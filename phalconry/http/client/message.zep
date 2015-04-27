namespace Phalconry\Http\Client;

use OutOfBoundsException;

/**
 * Represents an HTTP message
 */
abstract class Message
{

	/**
	 * The message's header object
	 *
	 * @var \Phalconry\Http\Client\Header
	 */
	protected header;

	/**
	 * The message's parent message.
	 *
	 * @var \Phalconry\Http\Client\Message
	 */
	protected parentMessage;

	/**
	 * Constructor.
	 */
    public function __construct()
	{
        let this->header = new Header();
    }

	/**
	 * Returns the header object, or a specific header value if a name is given
	 *
	 * @param string name [Optional]
	 * @return \Phalconry\Http\Client\Header|string|null
	 */
	public function getHeader(var name = null)
	{
		if typeof name == "string" {
			return this->header->get(name);
		}

		return this->header;
	}

	/**
	 * Returns the message's parent message, if any
	 *
	 * @return \Phalconry\Http\Client\Message|null
	 */
	public function getParent()
	{
		return this->parentMessage;
	}

	/**
	 * Whether the message has a parent message
	 *
	 * @return boolean
	 */
	public function hasParent() -> boolean
	{
		return (typeof this->parentMessage == "object");
	}

	/**
	 * Sets the message's parent message
	 *
	 * @param \Phalconry\Http\Client\Message parentMessage
	 */
	public function setParent(<Message> parentMessage) -> void
	{
		let this->parentMessage = parentMessage;
	}

	/**
	 * Read-only access to properties
	 *
	 * @param string prop Property name
	 * @throws \OutOfBoundsException if invalid property requested
	 */
	public function __get(var prop)
	{
        if isset this->{prop} {
			return this->{prop};
		}

		throw new OutOfBoundsException("Invalid property");
	}

}
