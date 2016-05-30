#include "Api.h"


namespace AccessControlLibrary
{
	Api::Api(std::string base_url, std::array<unsigned char, 20> cert_hash)
	{
		_base_url = base_url;
		_certHash = cert_hash;
	}

	std::vector<Entities::Product> Api::getProductsList()
	{
	}

	Entities::Product Api::getProductInfo()
	{
	}

	Entities::Bid Api::check(std::string pc_unique_key, int product_id)
	{
		Entities::Bid bid;
		return bid;
	}

	Entities::Bid Api::add(std::string pc_name, std::string pc_unique_key, int product_id)
	{
		Entities::Bid bid;
		return bid;
	}

	std::string Api::executeGetApiMethod(std::string method_name)
	{
		return std::string();
	}

	std::string Api::executePostApiMethod(std::string method_name, Entities::AccessRequest request_body)
	{
		return std::string();
	}

	Api::~Api()
	{
	}
}

