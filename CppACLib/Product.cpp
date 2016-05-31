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

		Product::~Product()
		{
		}
	}
}