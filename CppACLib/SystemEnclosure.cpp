#include "SystemEnclosure.h"

namespace AccessControlLibrary
{
	namespace Hardware
	{
		SystemEnclosure::SystemEnclosure()
			:_manufacturer(""),
			_serial_number("")
		{
		}

		void SystemEnclosure::setManufacturer(std::string manufacturer)
		{
			_manufacturer = manufacturer;
		}

		void SystemEnclosure::setSerialNumber(std::string serial_number)
		{
			_serial_number = serial_number;
		}

		std::string SystemEnclosure::getManufacturer() const
		{
			return _manufacturer;
		}

		std::string SystemEnclosure::getSerialNumber() const
		{
			return _serial_number;
		}

		std::string SystemEnclosure::getHash() const
		{
			return Util::sha256(_manufacturer + ":" + _serial_number);
		}

		SystemEnclosure::~SystemEnclosure()
		{
		}
	}
}
