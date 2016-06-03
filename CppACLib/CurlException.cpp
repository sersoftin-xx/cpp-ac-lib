#include "CurlException.h"

namespace AccessControlLibrary
{
	namespace Exceptions
	{
		CurlException::CurlException(CURLcode curl_code)
			: exception(curl_easy_strerror(curl_code))
		{
			_curl_code = curl_code;
		}

		CURLcode CurlException::getCurlCode() const
		{
			return _curl_code;
		}

		CurlException::~CurlException()
		{

		}
	}
}