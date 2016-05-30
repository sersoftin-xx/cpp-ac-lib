#include "Api.h"


namespace AccessControlLibrary
{
	Api::Api(std::string baseUrl, std::array<unsigned char, 20> certHash)
	{
		_certHash = certHash;
	}

	Api::~Api()
	{
	}
}

