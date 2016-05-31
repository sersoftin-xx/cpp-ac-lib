#pragma once
#include <json/json.h>

namespace AccessControlLibrary
{
	namespace Entities
	{
		class Bid
		{
		public:
			Bid();

			int getId() const;
			int getProductId() const;
			int getPcId() const;
			bool getIsActive() const;
			bool getIsExpired() const;

			void setId(int id);
			void setProductId(int product_id);
			void setPcId(int pc_id);
			void setIsActive(bool is_active);
			void setIsExpired(bool is_expired);

			std::string Serialize() const;
			bool Deserialize(std::string json_content, std::string parent_root);

			~Bid();

		private:
			int _id;
			int _product_id;
			int _pc_id;
			bool _is_active;
			bool _is_expired;
		};
	}
}

