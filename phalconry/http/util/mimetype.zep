namespace Phalconry\Http\Util;

/**
 * Class ContentType
 *
 * @author Kachit
 * @link https://github.com/Kachit/phalcon-lib/blob/master/src/Kachit/Phalcon/Utils/MimeType.php
 */
class MimeType
{

	const DOWNLOAD = "application/octet-stream";
	const TEXT	= "text/plain";
	const HTML	= "text/html";
	const XML	= "application/xml";
	const JSON	= "application/json";
	const JS	= "application/javascript";
	const CSS	= "text/css";
	
    const DEFAULT_HTTP = "text/html";
    const DEFAULT_FILE = "application/octet-stream";

	protected static mimetypes;

	/**
	 * Returns a mime/type by file extension
	 *
	 * @param string extension Extension without dots (e.g. "html")
	 * @param string default [Optional] Default value to return if mime/type is not found. Default is null
	 * @return string
	 */
	public static function get(string! extension, var defaultValue = null) -> string|null
    {
		if ! isset self::mimetypes {
			let self::mimetypes = [
				"txt": "text/plain",
				// web
				"htm": "text/html",
				"html": "text/html",
				"php": "text/html",
				"css": "text/css",
				"js": "application/javascript",
				"json": "application/json",
				"xml": "application/xml",
				"swf": "application/x-shockwave-flash",
				"flv": "video/x-flv",
				// Images
				"png": "image/png",
				"jpe": "image/jpeg",
				"jpeg": "image/jpeg",
				"jpg": "image/jpeg",
				"gif": "image/gif",
				"bmp": "image/bmp",
				"ico": "image/vnd.microsoft.icon",
				"tiff": "image/tiff",
				"tif": "image/tiff",
				"svg": "image/svg+xml",
				"svgz": "image/svg+xml",
				// Archives
				"zip": "application/zip",
				"rar": "application/x-rar-compressed",
				"exe": "application/x-msdownload",
				"msi": "application/x-msdownload",
				"cab": "application/vnd.ms-cab-compressed",
				// Audio/video
				"mp3": "audio/mpeg",
				"qt": "video/quicktime",
				"mov": "video/quicktime",
				// Adobe
				"pdf": "application/pdf",
				"psd": "image/vnd.adobe.photoshop",
				"ai": "application/postscript",
				"eps": "application/postscript",
				"ps": "application/postscript",
				// MS Office
				"doc": "application/msword",
				"rtf": "application/rtf",
				"xls": "application/vnd.ms-excel",
				"ppt": "application/vnd.ms-powerpoint",
				// Open Office
				"odt": "application/vnd.oasis.opendocument.text",
				"ods": "application/vnd.oasis.opendocument.spreadsheet"
			];
		}

		return isset self::mimetypes[extension] ? self::mimetypes[extension] : defaultValue;
	}

	/**
	 * Attempts to return a mime/type for a file
	 *
	 * @param string filename The filename
	 * @return string Detected mime/type for the file, or the value of DEFAULT_FILE if not found
	 */
	public static function getForFile(string! filename) -> string
    {
        return self::get(pathinfo(filename, PATHINFO_EXTENSION), self::DEFAULT_FILE);
	}

	/**
	 * Attempts to return a mime/type for an HTTP response
	 *
	 * @param string extension
	 * @return string Mime/type for the extension, or the value of DEFAULT_HTTP if not found
	 */
	public static function getForHttp(string! extension) -> string
    {
        return self::get(extension, self::DEFAULT_HTTP);
	}

}
