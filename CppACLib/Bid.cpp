#include "Bid.h"


namespace AccessControlLibrary
{
	namespace Entities
	{
		Bid::Bid()
			: _id(0),
			_product_id(0),
			_pc_id(0),
			_is_active(false),
			_is_expired(true)
		{
		}

		int Bid::getId() const
		{
			return _id;
		}

		int Bid::getProductId() const
		{
			return _product_id;
		}

		int Bid::getPcId() const
		{
			return _pc_id;
		}

		bool Bid::getIsActive() const
		{
			return _is_active;
		}

		bool Bid::getIsExpired() const
		{
			return _is_expired;
		}

		void Bid::setId(int id)
		{
			_id = id;
		}

		void Bid::setProductId(int product_id)
		{
			_product_id = product_id;
		}

		void Bid::setPcId(int pc_id)
		{
			_pc_id = pc_id;
		}

		void Bid::setIsActive(bool is_active)
		{
			_is_active = is_active;
		}

		void Bid::setIsExpired(bool is_expired)
		{
			_is_expired = is_expired;
		}

		std::string Bid::Serialize() const
		{
			Json::Value root;
			root["id"] = _id;
			root["product_id"] = _product_id;
			root["pc_id"] = _pc_id;
			root["is_active"] = _is_active;
			root["is_expired"] = _is_expired;
			Json::StyledWriter writer;
			return writer.write(root);
		}

		bool Bid::Deserialize(std::string json_content, std::string parent_root)
		{
			Json::Value root;
			Json::Reader reader;
			if (!reader.parse(json_content, root))
				return false;
			_id = root[parent_root].get("id", 0).asInt();
			_product_id = root[parent_root].get("product_id", 0).asInt();
			_pc_id = root[parent_root].get("pc_id", 0).asInt();
			_is_active = root[parent_root].get("is_active", false).asBool();
			_is_expired = root[parent_root].get("is_expired", true).asBool();
			return true;
		}

		Bid::~Bid()
		{
		}
	}
}
