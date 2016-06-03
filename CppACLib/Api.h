#pragma once
#include <array>
#include "CertificateCheckException.h"
#include "CurlException.h"
#include "WebException.h"
#include "AccessRequest.h"
#include "Product.h"
#include "Bid.h"
#include <vector>
#include <curl/curl.h>
#include <openssl/bio.h>
#include <openssl/pem.h>

namespace AccessControlLibrary
{
	class Api
	{
	public:
		Api(std::string base_url, bool check_cert);

		std::vector<Entities::Product> getProductsList() const;
		Entities::Product getProductInfo(int product_id) const;

		void setPublicKeyHash(std::array<unsigned char, 20> cert_hash);

		Entities::Bid check(std::string pc_unique_key, int product_id) const;
		Entities::Bid add(std::string pc_name, std::string pc_unique_key, int product_id) const;

		~Api();
	private:
		std::array<unsigned char, 20> _certHash;
		std::string _base_url;
		bool _check_cert;

		CURL * _curl;
		struct curl_slist * _headers;

		std::string executeGetApiMethod(std::string method_name) const;
		std::string executePostApiMethod(std::string method_name, Entities::AccessRequest request_body) const;

		static size_t writeResponseCallback(char* ptr, size_t size, size_t nmemb, std::string * str);
		bool checkCert(CURL * curl, std::array<unsigned char, 20> valid_fingerprint) const;
	};
}
