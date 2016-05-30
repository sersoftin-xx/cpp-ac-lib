#include "Configuration.h"

namespace AccessControlLibrary
{
	Configuration::Configuration(): _product_id(0) {
	}

	void Configuration::setBaseApiUrl(std::string base_api_url)
	{
		_base_api_url = base_api_url;
	}

	void Configuration::setPublicKeyHash(unsigned char* public_key_hash, size_t public_key_hash_len)
	{
		if (sizeof(_public_key_hash) != public_key_hash_len)
			throw std::exception("Public key hash len more or small 20 bytes.");
		memcpy(_public_key_hash, public_key_hash, public_key_hash_len);
	}

	void Configuration::setProductId(int product_id)
	{
		_product_id = product_id;
	}

	void Configuration::setHashSalt(std::string hash_salt)
	{
		_hash_salt = hash_salt;
	}

	Configuration::~Configuration()
	{
	}
}