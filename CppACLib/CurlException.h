#pragma once
#include "vcruntime_exception.h"
#include <curl/curl.h>

namespace AccessControlLibrary
{
	namespace Exceptions
	{
		class CurlException : public std::exception
		{
		public:
			explicit CurlException(CURLcode curl_code);

			CURLcode getCurlCode() const;

			virtual ~CurlException();
		private:
			CURLcode _curl_code;
		};
	}
}
