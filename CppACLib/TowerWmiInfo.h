#pragma once
#include <string>
#include <comdef.h>
#include <Wbemidl.h>

namespace AccessControlLibrary
{
	namespace Hardware
	{
		class TowerWmiInfo
		{
		public:
			TowerWmiInfo();

			std::string getPcUuid() const;

			~TowerWmiInfo();
		private:
			IWbemLocator * pLoc = nullptr;
			IWbemServices * pSvc = nullptr;

			void checkForError(HRESULT hresult) const;
		};
	}
}