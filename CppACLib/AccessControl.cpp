#include "AccessControl.h"

namespace AccessControlLibrary
{

	AccessControl::~AccessControl()
	{
	}

	AccessControl::AccessControl(Configuration* configuration)
	{
		_config = configuration;
	}

	bool AccessControl::accessAllowed()
	{
		return false;
	}

	bool AccessControl::accessAllowed(int product_id)
	{
		return false;
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

	std::vector<Entities::Product> AccessControl::getProducts()
	{
		std::vector<Entities::Product> products;
		return products;
	}

	Entities::Product AccessControl::getProductInfo(int product_id)
	{
		Entities::Product product;
		return product;
	}
}
