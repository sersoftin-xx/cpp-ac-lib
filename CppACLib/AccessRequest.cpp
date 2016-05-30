#include "AccessRequest.h"

namespace AccessControlLibrary
{
	namespace Entities
	{
		AccessRequest::AccessRequest(const std::string& pc_name, const std::string& pc_unique_key, int product_id)
			: _pc_name(pc_name),
			_pc_unique_key(pc_unique_key),
			_product_id(product_id)
		{

		}

		std::string AccessRequest::getPcName() const
		{
			return _pc_name;
		}

		std::string AccessRequest::getPcUniqueKey() const
		{
			return _pc_unique_key;
		}

		int AccessRequest::getProductId() const
		{
			return _product_id;
		}

		void AccessRequest::setPcName(std::string pc_name)
		{
			_pc_name = pc_name;
		}

		void AccessRequest::setPcUniqueKey(std::string pc_unique_key)
		{
			_pc_unique_key = pc_unique_key;
		}

		void AccessRequest::setProductId(int product_id)
		{
			_product_id = product_id;
		}

		std::string AccessRequest::Serialize() const
		{
			Json::Value root;
			root["pc_name"] = _pc_name;
			root["pc_unique_key"] = _pc_unique_key;
			root["product_id"] = _product_id;
			Json::StyledWriter writer;
			return writer.write(root);
		}

		bool AccessRequest::Deserialize(std::string json_content)
		{
			Json::Value root;
			Json::Reader reader;
			if (!reader.parse(json_content, root))
				return false;
			_pc_name = root.get("pc_name", "").asString();
			_pc_unique_key = root.get("pc_unique_key", "").asString();
			_product_id = root.get("product_id", "").asInt();
			return true;
		}
	}
}