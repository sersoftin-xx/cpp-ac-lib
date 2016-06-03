#pragma once
#include "vcruntime_exception.h"
#include <string>

namespace AccessControlLibrary
{
	namespace Exceptions
	{
		class WmiException :
			public std::exception
		{
		public:
			explicit WmiException(char const* const message);
			explicit WmiException(std::string & message);
			virtual ~WmiException();
		};
	}
}
