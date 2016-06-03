#include "WmiException.h"

namespace AccessControlLibrary
{
	namespace Exceptions
	{
		WmiException::WmiException(char const* const message)
			: exception(message)
		{
		}

		WmiException::WmiException(std::string& message)
			: exception(message.c_str())
		{
		}

		WmiException::~WmiException()
		{
		}
	}
}