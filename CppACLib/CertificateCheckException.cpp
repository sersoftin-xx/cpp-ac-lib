#include "CertificateCheckException.h"


namespace AccessControlLibrary
{
	namespace Exceptions
	{
		CertificateCheckException::CertificateCheckException(char const* const message)
			: exception(message)
		{
			
		}

		CertificateCheckException::CertificateCheckException(std::string& message)
			: exception(message.c_str())
		{

		}

		CertificateCheckException::~CertificateCheckException()
		{
		}
	}
}