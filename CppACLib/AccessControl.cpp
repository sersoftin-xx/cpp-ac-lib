#include "AccessControl.h"

namespace AccessControlLibrary
{

	AccessControl::~AccessControl()
	{
		delete _api;
	}

	AccessControl::AccessControl(Configuration* configuration)
	{
		_config = configuration;
		_api = new Api(_config->getBaseApiUrl(), _config->getPublicKeyHash());
	}

	bool AccessControl::accessAllowed() const
	{
		return accessAllowed(_config->getProductId());
	}

	bool AccessControl::accessAllowed(int product_id) const
	{
		try
		{
			std::shared_ptr<Hardware::Tower> tower(new Hardware::Tower(_config->getHashSalt()));
			auto bid = _api->check(tower->getUniqueKey(), product_id);
			return bid.getIsActive() && !bid.getIsExpired();
		}
		catch (std::exception ex)
		{
			return false;
		}
	}

	Entities::Bid AccessControl::requestAccess()
	{
		Entities::Bid bid;

		return bid;
	}

	Entities::Bid AccessControl::requestAccess(int product_id)
	{
		Entities::Bid bid;

		return bid;
	}

	std::vector<Entities::Product> AccessControl::getProducts() const
	{
		return _api->getProductsList();
	}

	Entities::Product AccessControl::getProductInfo(int product_id) const
	{
		return _api->getProductInfo(product_id);
	}
}
