#pragma once
#include <json/json.h>

namespace AccessControlLibrary
{
	namespace Entities
	{
		class AccessRequest
		{
		public:
			AccessRequest();
			AccessRequest(const std::string& pc_name, const std::string& pc_unique_key, int product_id);

			std::string getPcName() const;
			std::string getPcUniqueKey() const;
			int getProductId() const;

			void setPcName(std::string pc_name);
			void setPcUniqueKey(std::string pc_unique_key);
			void setProductId(int product_id);

			std::string Serialize() const;
			bool Deserialize(std::string json_content);

		private:
			std::string _pc_name;
			std::string _pc_unique_key;
			int _product_id;
		};
	}
}