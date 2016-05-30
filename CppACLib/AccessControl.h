#pragma once
#include "Configuration.h"
#include "Bid.h"
#include "Product.h"
#include <vector>

namespace AccessControlLibrary
{
	class AccessControl
	{
	public:
		explicit AccessControl(Configuration * configuration);

		bool accessAllowed();
		bool accessAllowed(int product_id);

		Entities::Bid requestAccess();
		Entities::Bid requestAccess(int product_id);

		std::vector<Entities::Product> getProducts();
		Entities::Product getProductInfo(int product_id);

		~AccessControl();
	private:
		Configuration * _config;
	};
}