#pragma once
#include <array>
#include "AccessRequest.h"
#include "Product.h"
#include "Bid.h"
#include <vector>
#include <curl/curl.h>
#include <sstream>

namespace AccessControlLibrary
{
	class Api
	{
	public:
		Api(std::string base_url, std::array<unsigned char, 20> cert_hash);

		std::vector<Entities::Product> getProductsList() const;
		Entities::Product getProductInfo(int product_id) const;

		Entities::Bid check(std::string pc_unique_key, int product_id);
		Entities::Bid add(std::string pc_name, std::string pc_unique_key, int product_id);

		~Api();
	private:
		std::array<unsigned char, 20> _certHash;
		std::string _base_url;

		CURL * _curl;

		std::string executeGetApiMethod(std::string method_name) const;
		std::string executePostApiMethod(std::string method_name, Entities::AccessRequest request_body) const;

		static size_t writeResponseCallback(void *ptr, size_t size, size_t nmemb, void *stream);
	};
}
