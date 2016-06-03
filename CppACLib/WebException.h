#pragma once
#include "vcruntime_exception.h"
#include <string>
#include "Error.h"

namespace AccessControlLibrary
{
	namespace Exceptions
	{
		class WebException :
			public std::exception
		{
			class Response
			{
			public:
				Response(std::string & response_string, int http_response_code)
				{
					_response_string = response_string;
					_http_response_code = http_response_code;
				}
				int getHttpResponseCode() const
				{
					return _http_response_code;
				}
				std::string getResponseString() const
				{
					return _response_string;
				}
				virtual ~Response()
				{

				}
			private:
				std::string _response_string;
				int _http_response_code;
			};
			Response _response;
			Entities::Error _error;
		public:
			explicit WebException(char const* const message, std::string & respose_content_string, int http_error_code);
			explicit WebException(std::string & message, std::string & respose_content_string, int http_error_code);
			Response getResponse() const;
			Entities::Error getError() const;
			virtual ~WebException();
		};
	}
}
