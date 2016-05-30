#pragma once
#include <array>
#include "AccessRequest.h"
#include "Product.h"
#include "Bid.h"
#include <vector>

namespace AccessControlLibrary
{
	class Api
	{
	public:
		Api(std::string base_url, std::array<unsigned char, 20> cert_hash);

		std::vector<Entities::Product> getProductsList();
		Entities::Product getProductInfo();

		Entities::Bid check(std::string pc_unique_key, int product_id);
		Entities::Bid add(std::string pc_name, std::string pc_unique_key, int product_id);

		~Api();
	private:
		std::array<unsigned char, 20> _certHash;
		std::string _base_url;

		std::string executeGetApiMethod(std::string method_name);
		std::string executePostApiMethod(std::string method_name, Entities::AccessRequest request_body);
	};
}
