#include "Baseboard.h"

namespace AccessControlLibrary
{
	namespace Hardware
	{
		Baseboard::Baseboard()
			: _manufacturer(""),
			_product(""),
			_serial_number("")
		{
		}

		std::string Baseboard::getManufacturer() const
		{
			return _manufacturer;
		}

		std::string Baseboard::getProduct() const
		{
			return _product;
		}

		std::string Baseboard::getSerialNumber() const
		{
			return _serial_number;
		}

		void Baseboard::setManufacturer(std::string manufacturer)
		{
			_manufacturer = manufacturer;
		}

		void Baseboard::setProduct(std::string product)
		{
			_product = product;
		}

		void Baseboard::setSerialNumber(std::string serial_number)
		{
			_serial_number = serial_number;
		}

		Baseboard::~Baseboard()
		{
		}
	}
}