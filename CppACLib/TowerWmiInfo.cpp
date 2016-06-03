#include "TowerWmiInfo.h"

namespace AccessControlLibrary
{
	namespace Hardware
	{

		TowerWmiInfo::TowerWmiInfo()
		{
			HRESULT hres;
			hres = CoInitializeEx(nullptr, COINIT_MULTITHREADED);
			checkForError(hres);
			hres = CoInitializeSecurity(nullptr, -1, nullptr, nullptr, RPC_C_AUTHN_LEVEL_DEFAULT, RPC_C_IMP_LEVEL_IMPERSONATE, nullptr, EOAC_NONE, nullptr);
			checkForError(hres);
			hres = CoCreateInstance(CLSID_WbemLocator, nullptr, CLSCTX_INPROC_SERVER, IID_IWbemLocator, reinterpret_cast<LPVOID *>(&pLoc));
			checkForError(hres);
			hres = pLoc->ConnectServer(L"root\\CIMV2", nullptr, nullptr, nullptr, NULL, nullptr, nullptr, &pSvc);
			checkForError(hres);
		}

		std::string TowerWmiInfo::getPcUuid() const
		{
			std::string result;
			IEnumWbemClassObject* pEnumerator = nullptr;
			auto hres = pSvc->ExecQuery(L"WQL", L"SELECT UUID FROM Win32_ComputerSystemProduct", WBEM_FLAG_FORWARD_ONLY | WBEM_FLAG_RETURN_IMMEDIATELY, nullptr, &pEnumerator);
			checkForError(hres);
			IWbemClassObject *pclsObj = nullptr;
			ULONG uReturn = 0;

			hres = pEnumerator->Next(WBEM_INFINITE, 1, &pclsObj, &uReturn);
			if (uReturn)
			{
				checkForError(hres);
				VARIANT vtProp;
				hres = pclsObj->Get(L"UUID", 0, &vtProp, nullptr, nullptr);
				checkForError(hres);
				if ((vtProp.vt == VT_NULL) || (vtProp.vt == VT_EMPTY))
					result = vtProp.vt == VT_NULL ? "NULL" : "EMPTY";
				else
					result = _bstr_t(vtProp.bstrVal);
				VariantClear(&vtProp);
			}
			if (pclsObj != nullptr)
				pclsObj->Release();
			if (pEnumerator != nullptr)
				pEnumerator->Release();
			return result;
		}

		Baseboard TowerWmiInfo::getBaseboard() const
		{
			Baseboard baseboard;
			IEnumWbemClassObject* pEnumerator = nullptr;
			auto hres = pSvc->ExecQuery(L"WQL", L"SELECT Manufacturer,Product,SerialNumber FROM Win32_BaseBoard", WBEM_FLAG_FORWARD_ONLY | WBEM_FLAG_RETURN_IMMEDIATELY, nullptr, &pEnumerator);
			checkForError(hres);
			IWbemClassObject *pclsObj = nullptr;
			ULONG uReturn = 0;

			hres = pEnumerator->Next(WBEM_INFINITE, 1, &pclsObj, &uReturn);
			if (uReturn)
			{
				checkForError(hres);
				VARIANT vtProp;
				hres = pclsObj->Get(L"Manufacturer", 0, &vtProp, nullptr, nullptr);
				checkForError(hres);
				if ((vtProp.vt == VT_NULL) || (vtProp.vt == VT_EMPTY))
					baseboard.setManufacturer(vtProp.vt == VT_NULL ? "NULL" : "EMPTY");
				else
				{
					baseboard.setManufacturer(std::string(_bstr_t(vtProp.bstrVal)));
				}
				VariantClear(&vtProp);
				hres = pclsObj->Get(L"Product", 0, &vtProp, nullptr, nullptr);
				checkForError(hres);
				if ((vtProp.vt == VT_NULL) || (vtProp.vt == VT_EMPTY))
					baseboard.setProduct(vtProp.vt == VT_NULL ? "NULL" : "EMPTY");
				else
				{
					baseboard.setProduct(std::string(_bstr_t(vtProp.bstrVal)));
				}
				VariantClear(&vtProp);
				hres = pclsObj->Get(L"SerialNumber", 0, &vtProp, nullptr, nullptr);
				checkForError(hres);
				if ((vtProp.vt == VT_NULL) || (vtProp.vt == VT_EMPTY))
					baseboard.setSerialNumber(vtProp.vt == VT_NULL ? "NULL" : "EMPTY");
				else
				{
					baseboard.setSerialNumber(std::string(_bstr_t(vtProp.bstrVal)));
				}
				VariantClear(&vtProp);
			}
			if (pclsObj != nullptr)
				pclsObj->Release();
			if (pEnumerator != nullptr)
				pEnumerator->Release();
			return baseboard;
		}

		SystemEnclosure TowerWmiInfo::getSystemEnclosure() const
		{
			SystemEnclosure system_enclosure;
			IEnumWbemClassObject* pEnumerator = nullptr;
			auto hres = pSvc->ExecQuery(L"WQL", L"SELECT Manufacturer,SerialNumber FROM Win32_SystemEnclosure", WBEM_FLAG_FORWARD_ONLY | WBEM_FLAG_RETURN_IMMEDIATELY, nullptr, &pEnumerator);
			checkForError(hres);
			IWbemClassObject *pclsObj = nullptr;
			ULONG uReturn = 0;

			hres = pEnumerator->Next(WBEM_INFINITE, 1, &pclsObj, &uReturn);
			if (uReturn)
			{
				checkForError(hres);
				VARIANT vtProp;
				hres = pclsObj->Get(L"Manufacturer", 0, &vtProp, nullptr, nullptr);
				checkForError(hres);
				if ((vtProp.vt == VT_NULL) || (vtProp.vt == VT_EMPTY))
					system_enclosure.setManufacturer(vtProp.vt == VT_NULL ? "NULL" : "EMPTY");
				else
				{
					system_enclosure.setManufacturer(std::string(_bstr_t(vtProp.bstrVal)));
				}
				VariantClear(&vtProp);
				hres = pclsObj->Get(L"SerialNumber", 0, &vtProp, nullptr, nullptr);
				checkForError(hres);
				if ((vtProp.vt == VT_NULL) || (vtProp.vt == VT_EMPTY))
					system_enclosure.setSerialNumber(vtProp.vt == VT_NULL ? "NULL" : "EMPTY");
				else
				{
					system_enclosure.setSerialNumber(std::string(_bstr_t(vtProp.bstrVal)));
				}
				VariantClear(&vtProp);
			}
			if (pclsObj != nullptr)
				pclsObj->Release();
			if (pEnumerator != nullptr)
				pEnumerator->Release();
			return system_enclosure;
		}

		TowerWmiInfo::~TowerWmiInfo()
		{
			if (pSvc != nullptr)
				pSvc->Release();
			if (pLoc != nullptr)
				pLoc->Release();
			CoUninitialize();
		}

		void TowerWmiInfo::checkForError(HRESULT hresult) const
		{
			if (FAILED(hresult))
			{
				_bstr_t error_message = _com_error(hresult).ErrorMessage();
				throw Exceptions::WmiException(error_message);
			}
		}
	}
}
