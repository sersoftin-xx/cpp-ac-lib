#pragma once
#include <string>

namespace AccessContolLibrary
{
	namespace Hardware
	{
		class Baseboard
		{
		public:
			Baseboard();

			std::string getManufacturer() const;
			std::string getProduct() const;
			std::string getSerialNumber() const;

			void setManufacturer() const;
			void setProduct() const;
			void setSerialNumber() const;

			~Baseboard();

		private:
			std::string _manufacturer;
			std::string _product;
			std::string _serial_number;
		};
	}
}

