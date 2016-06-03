#include "WebException.h"

namespace AccessControlLibrary
{
	namespace Exceptions
	{
		WebException::WebException(char const* const message, std::string & respose_content_string, int http_error_code)
			: exception(message),
			_response(respose_content_string, http_error_code)
		{
			if (!_error.Deserialize(respose_content_string))
				_error.setCode(http_error_code);
		}

		WebException::WebException(std::string& message, std::string & respose_content_string, int http_error_code)
			: exception(message.c_str()),
			_response(respose_content_string, http_error_code)
		{
			if (!_error.Deserialize(respose_content_string))
				_error.setCode(http_error_code);
		}

		WebException::Response WebException::getResponse() const
		{
			return _response;
		}

		Entities::Error WebException::getError() const
		{
			return _error;
		}

		WebException::~WebException()
		{
		}
	}
}