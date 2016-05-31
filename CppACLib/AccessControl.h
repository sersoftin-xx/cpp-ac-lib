#pragma once
#include "Configuration.h"
#include "Bid.h"
#include "Product.h"
#include <vector>
#include "Api.h"
#include <memory>
#include "Tower.h"

namespace AccessControlLibrary
{
	class AccessControl
	{
	public:
		explicit AccessControl(Configuration * configuration);

		bool accessAllowed() const;
		bool accessAllowed(int product_id) const;

		Entities::Bid requestAccess();
		Entities::Bid requestAccess(int product_id);

		std::vector<Entities::Product> getProducts() const;
		Entities::Product getProductInfo(int product_id) const;

		~AccessControl();
	private:
		Configuration * _config;
		Api * _api;
	};
}