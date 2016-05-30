#include "Api.h"


namespace AccessControlLibrary
{
	Api::Api(std::string base_url, std::array<unsigned char, 20> cert_hash)
	{
		_base_url = base_url;
		_certHash = cert_hash;
	}

	Api::~Api()
	{
	}

	std::string Api::executeGetApiMethod(std::string method_name)
	{
		return std::string();
	}
}

