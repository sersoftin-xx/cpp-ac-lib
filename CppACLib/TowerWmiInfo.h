#pragma once
#include <string>
#include <comdef.h>
#include <Wbemidl.h>
#include "Baseboard.h"
#include "SystemEnclosure.h"
#include "WmiException.h"

namespace AccessControlLibrary
{
	namespace Hardware
	{
		class TowerWmiInfo
		{
		public:
			TowerWmiInfo();

			std::string getPcUuid() const;
			Baseboard getBaseboard() const;
			SystemEnclosure getSystemEnclosure() const;

			~TowerWmiInfo();
		private:
			IWbemLocator * pLoc = nullptr;
			IWbemServices * pSvc = nullptr;

			void checkForError(HRESULT hresult) const;
		};
	}
}