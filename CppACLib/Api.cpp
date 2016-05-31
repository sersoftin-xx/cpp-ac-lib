#include "Api.h"

namespace AccessControlLibrary
{
	Api::Api(std::string base_url, std::array<unsigned char, 20> cert_hash)
	{
		_base_url = base_url;
		_certHash = cert_hash;
		if (curl_global_init(CURL_GLOBAL_ALL) != CURLE_OK)
			throw std::exception("Failed curl initilization");
		_curl = curl_easy_init();
		curl_easy_setopt(_curl, CURLOPT_SSL_VERIFYPEER, 1L);
		curl_easy_setopt(_curl, CURLOPT_SSL_VERIFYHOST, 1L);
	}

	std::vector<Entities::Product> Api::getProductsList() const
	{
		auto json_response = executeGetApiMethod("/products/list");
		std::vector<Entities::Product> products;
		Json::Value root;
		Json::Reader reader;
		Json::FastWriter fastWriter;
		if (!reader.parse(json_response, root))
			throw std::exception("Ivalid json data accepted.");
		for (auto & product : root["products"])
		{
			Entities::Product product_entity;
			if (!product_entity.Deserialize(fastWriter.write(product)))
				throw std::exception("Ivalid json data accepted.");
			products.push_back(product_entity);
		}
		return products;
	}

	Entities::Product Api::getProductInfo(int product_id) const
	{
		Entities::Product product;
		auto json_response = executeGetApiMethod("/products/info/" + std::to_string(product_id));
		if (!product.Deserialize(json_response, "product"))
			throw std::exception("Ivalid json data accepted.");
		return product;
	}

	Entities::Bid Api::check(std::string pc_unique_key, int product_id)
	{
		Entities::Bid bid;
		Entities::AccessRequest request_body;
		request_body.setPcUniqueKey(pc_unique_key);
		request_body.setProductId(product_id);
		auto json_response = executePostApiMethod("/bids/check", request_body);
		if (!bid.Deserialize(json_response, "bid"))
			throw std::exception("Ivalid json data accepted.");
		return bid;
	}

	Entities::Bid Api::add(std::string pc_name, std::string pc_unique_key, int product_id)
	{
		Entities::Bid bid;
		return bid;
	}

	std::string Api::executeGetApiMethod(std::string method_name) const
	{
		curl_easy_setopt(_curl, CURLOPT_URL, (_base_url + "client_api" + method_name).c_str());
		curl_easy_setopt(_curl, CURLOPT_WRITEFUNCTION, writeResponseCallback);
		std::stringstream response_stream;
		curl_easy_setopt(_curl, CURLOPT_WRITEDATA, &response_stream);
		auto error_code = curl_easy_perform(_curl);
		if (error_code != CURLE_OK)
		{
			throw std::exception(curl_easy_strerror(error_code));
		}
		return response_stream.str();
	}

	std::string Api::executePostApiMethod(std::string method_name, Entities::AccessRequest request_body) const
	{
		return std::string();
	}

	size_t Api::writeResponseCallback(void* ptr, size_t size, size_t nmemb, void * stream)
	{
		fwrite(ptr, size, nmemb, static_cast<FILE*>(stream));
		return (nmemb*size);
	}

	Api::~Api()
	{
		curl_easy_cleanup(_curl);
		curl_global_cleanup();
	}
}

