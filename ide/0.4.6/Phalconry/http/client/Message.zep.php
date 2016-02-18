<?php

namespace Phalconry\Http\Client;

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
    protected $header;

    /**
     * The message's parent message.
     *
     * @var \Phalconry\Http\Client\Message
     */
    protected $parentMessage;


    /**
     * Constructor.
     */
    public function __construct() {}

    /**
     * Returns the header object, or a specific header value if a name is given
     *
     * @param string $name [Optional]
     * @return \Phalconry\Http\Client\Header|string|null 
     */
    public function getHeader($name = null) {}

    /**
     * Returns the message's parent message, if any
     *
     * @return \Phalconry\Http\Client\Message|null 
     */
    public function getParent() {}

    /**
     * Whether the message has a parent message
     *
     * @return boolean 
     */
    public function hasParent() {}

    /**
     * Sets the message's parent message
     *
     * @param \Phalconry\Http\Client\Message $parentMessage 
     */
    public function setParent(Message $parentMessage) {}

    /**
     * Read-only access to properties
     *
     * @throws \OutOfBoundsException if invalid property requested
     * @param string $prop Property name
     * @return mixed 
     */
    public function __get($prop) {}

}
