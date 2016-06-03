#pragma once
#include "vcruntime_exception.h"
#include <string>

namespace AccessControlLibrary
{
	namespace Exceptions
	{
		class CertificateCheckException : public std::exception
		{
		public:
			explicit CertificateCheckException(char const* const message);
			explicit CertificateCheckException(std::string & message);


			virtual ~CertificateCheckException();
		};
	}
}
