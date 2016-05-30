#include "Configuration.h"

namespace AccessControlLibrary
{
	Configuration::Configuration(): _product_id(0) {
	}

	void Configuration::setBaseApiUrl(std::string base_api_url)
	{
		_base_api_url = base_api_url;
	}

	void Configuration::setPublicKeyHash(std::array<unsigned char, 20> key_hash)
	{
		_key_hash = key_hash;
	}

	void Configuration::setProductId(int product_id)
	{
		_product_id = product_id;
	}

	void Configuration::setHashSalt(std::string hash_salt)
	{
		_hash_salt = hash_salt;
	}

	std::string Configuration::getBaseApiUrl()
	{
	}

	std::array<unsigned char, 20> Configuration::getPublicKeyHash()
	{
	}

	int Configuration::getProductId()
	{
	}

	std::string Configuration::getHashSalt()
	{
	}

	Configuration::~Configuration()
	{
	}
}