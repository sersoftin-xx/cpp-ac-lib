#include "Product.h"

namespace AccessControlLibrary
{
	namespace Entities
	{
		Product::Product(): _id(0) {
		}

		int Product::getId() const
		{
			return _id;
		}

		std::string Product::getName() const
		{
			return _name;
		}

		std::string Product::getDescription() const
		{
			return _description;
		}

		void Product::setId(int id)
		{
			_id = id;
		}

		void Product::setName(std::string name)
		{
			_name = name;
		}

		void Product::setDescription(std::string description)
		{
			_description = description;
		}

		std::string Product::Serialize() const
		{
			Json::Value root;
			root["id"] = _id;
			root["name"] = _name;
			root["description"] = _description;
			Json::StyledWriter writer;
			return writer.write(root);
		}

		bool Product::Deserialize(std::string json_content)
		{
			Json::Value root;
			Json::Reader reader;
			if (!reader.parse(json_content, root))
				return false;
			_id = root.get("id", 0).asInt();
			_name = root.get("name", "").asString();
			_description = root.get("description", "").asString();
			return true;
		}

		bool Product::Deserialize(std::string json_content, std::string parent_root)
		{
			Json::Value root;
			Json::Reader reader;
			if (!reader.parse(json_content, root))
				return false;
			_id = root[parent_root].get("id", 0).asInt();
			_name = root[parent_root].get("name", "").asString();
			_description = root[parent_root].get("description", "").asString();
			return true;
		}

		Product::~Product()
		{
		}
	}
}
