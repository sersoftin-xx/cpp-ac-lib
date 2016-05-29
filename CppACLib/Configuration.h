#pragma once
#include <string>

namespace AccessControlLibrary
{
	class Configuration
	{
	public:
		Configuration();

		void setBaseApiUrl(std::string base_api_url);
		void setPublicKeyHash(unsigned char * public_key_hash, size_t public_key_hash_len);
		void setProductId(int product_id);
		void setHashSalt(std::string hash_salt);

		~Configuration();
	private:
		std::string _base_api_url;
		unsigned char _public_key_hash[20];
		int _product_id;
		std::string _hash_salt;
	};
}