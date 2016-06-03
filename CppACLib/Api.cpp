#include "Api.h"
#include "CurlException.h"

namespace AccessControlLibrary
{
	Api::Api(std::string base_url, std::array<unsigned char, 20> cert_hash)
	{
		_base_url = base_url;
		_certHash = cert_hash;
		_curl = curl_easy_init();
		curl_easy_setopt(_curl, CURLOPT_SSL_VERIFYPEER, 0L);
		curl_easy_setopt(_curl, CURLOPT_SSL_VERIFYHOST, 0L);
		curl_easy_setopt(_curl, CURLOPT_WRITEFUNCTION, writeResponseCallback);
		curl_easy_setopt(_curl, CURLOPT_CERTINFO, 1L);
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
		curl_easy_setopt(_curl, CURLOPT_CUSTOMREQUEST, "GET");
		std::string response;
		curl_easy_setopt(_curl, CURLOPT_WRITEDATA, &response);
		auto error_code = curl_easy_perform(_curl);
		if (error_code != CURLE_OK)
			throw Exceptions::CurlException(error_code);
		if (!checkCert(_curl, _certHash))
			throw Exceptions::CertificateCheckException("Invalid SSL sertificate accepted.");
		int respose_code;
		curl_easy_getinfo(_curl, CURLINFO_RESPONSE_CODE, &respose_code);
		if (respose_code != 200)
			throw Exceptions::WebException("Server error", response, respose_code);
		return response;
	}

	std::string Api::executePostApiMethod(std::string method_name, Entities::AccessRequest request_body) const
	{
		curl_easy_setopt(_curl, CURLOPT_URL, (_base_url + "client_api" + method_name).c_str());
		curl_easy_setopt(_curl, CURLOPT_CUSTOMREQUEST, "POST");
		curl_easy_setopt(_curl, CURLOPT_POSTFIELDS, request_body.Serialize());
		std::string response;
		curl_easy_setopt(_curl, CURLOPT_WRITEDATA, &response);
		auto error_code = curl_easy_perform(_curl);
		if (error_code != CURLE_OK)
			throw std::exception(curl_easy_strerror(error_code));
		if (!checkCert(_curl, _certHash))
			throw Exceptions::CertificateCheckException("Invalid SSL sertificate accepted.");
		int respose_code;
		curl_easy_getinfo(_curl, CURLINFO_RESPONSE_CODE, &respose_code);
		if (respose_code != 200)
			throw Exceptions::WebException("Server error", response, respose_code);
		return response;
	}

	size_t Api::writeResponseCallback(char* ptr, size_t size, size_t nmemb, std::string * str)
	{
		str->append(ptr, nmemb*size);
		return nmemb * size;
	}

	bool Api::checkCert(CURL* curl, std::array<unsigned char, 20> valid_fingerprint) const
	{
		union {
			struct curl_slist    *to_info;
			struct curl_certinfo *to_certinfo;
		} ptr;
		ptr.to_info = nullptr;

		auto res = curl_easy_getinfo(curl, CURLINFO_CERTINFO, &ptr.to_info);

		if (res == CURLE_OK && ptr.to_info && ptr.to_certinfo->num_of_certs)
		{
			for (auto slist = ptr.to_certinfo->certinfo[0]; slist; slist = slist->next)
			{
				if (strstr(slist->data, "Cert:"))
				{
					auto bio = BIO_new(BIO_s_mem());
					X509 *certificate;
					BIO_puts(bio, slist->data + strlen("Cert:"));
					certificate = PEM_read_bio_X509(bio, nullptr, nullptr, nullptr);
					unsigned char fprint[20];
					X509_digest(certificate, EVP_sha1(), fprint, nullptr);
					return memcmp(valid_fingerprint.data(), fprint, 20) == 0;
				}
			}
		}

		return false;
	}

	Api::~Api()
	{
		curl_easy_cleanup(_curl);
	}
}

