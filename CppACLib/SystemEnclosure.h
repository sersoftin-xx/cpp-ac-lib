#pragma once
#include <string>
#include "Util.h"

namespace AccessControlLibrary
{
	namespace Hardware
	{
		class SystemEnclosure
		{
		public:
			SystemEnclosure();

			void setManufacturer(std::string manufacturer);
			void setSerialNumber(std::string serial_number);

			std::string getManufacturer() const;
			std::string getSerialNumber() const;

			std::string getHash() const;

			~SystemEnclosure();
		private:
			std::string _manufacturer;
			std::string _serial_number;
		};
	}
}
