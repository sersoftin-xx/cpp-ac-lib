#pragma once
#include <array>

namespace AccessControlLibrary
{
	class Configuration
	{
	public:
		Configuration();

		void setBaseApiUrl(std::string base_api_url);
		void setPublicKeyHash(std::array<unsigned char, 20> key_hash);
		void setProductId(int product_id);
		void setHashSalt(std::string hash_salt);
		void setCheckCertificate(bool check_cert);

		std::string getBaseApiUrl() const;
		std::array<unsigned char, 20> getPublicKeyHash() const;
		int getProductId() const;
		std::string getHashSalt() const;
		bool getCheckCert() const;

		~Configuration();
	private:
		std::string _base_api_url;
		std::array<unsigned char, 20> _key_hash;
		int _product_id;
		std::string _hash_salt;
		bool _check_cert;
	};
}