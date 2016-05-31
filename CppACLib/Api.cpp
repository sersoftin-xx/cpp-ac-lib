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
		std::vector<Entities::Product> products;

	}

	Entities::Product Api::getProductInfo(int product_id)
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

	std::string Api::executeGetApiMethod(std::string method_name) const
	{
		return std::string();
	}

	std::string Api::executePostApiMethod(std::string method_name, Entities::AccessRequest request_body) const
	{
		return std::string();
	}

	Api::~Api()
	{
	}
}

