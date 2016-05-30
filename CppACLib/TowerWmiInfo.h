#pragma once
#include <string>
#include <comdef.h>
#include <Wbemidl.h>
#include "Baseboard.h"

namespace AccessControlLibrary
{
	namespace Hardware
	{
		class TowerWmiInfo
		{
		public:
			TowerWmiInfo();

			std::string getPcUuid() const;
			AccessContolLibrary::Hardware::Baseboard getBaseboard() const;

			~TowerWmiInfo();
		private:
			IWbemLocator * pLoc = nullptr;
			IWbemServices * pSvc = nullptr;

			void checkForError(HRESULT hresult) const;
		};
	}
}