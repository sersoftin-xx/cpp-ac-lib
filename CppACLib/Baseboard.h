#pragma once
#include <string>
#include "Util.h"

namespace AccessControlLibrary
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

			void setManufacturer(std::string manufacturer);
			void setProduct(std::string product);
			void setSerialNumber(std::string serial_number);
			std::string getHash() const;

			~Baseboard();

		private:
			std::string _manufacturer;
			std::string _product;
			std::string _serial_number;
		};
	}
}

