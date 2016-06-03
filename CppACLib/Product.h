#pragma once
#include <json/json.h>

namespace AccessControlLibrary
{
	namespace Entities
	{
		class Product
		{
		public:
			Product();

			int getId() const;
			std::string getName() const;
			std::string getDescription() const;

			void setId(int id);
			void setName(std::string name);
			void setDescription(std::string description);

			std::string Serialize() const;
			bool Deserialize(std::string json_content);
			bool Deserialize(std::string json_content, std::string parent_root);

			~Product();
		private:
			int _id;
			std::string _name;
			std::string _description;
		};
	}
}
