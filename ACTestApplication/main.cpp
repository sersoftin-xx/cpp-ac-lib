#include <iostream>
#include "../CppACLib/AccessControl.h"


int main()
{
	try
	{
		setlocale(LC_ALL, "rus");
		SetConsoleTitleW(L"ACTestApplication");
		std::cout << "ACTestApplication — приложение, которое позволяет продемонстрировать возможности библиотеки AccessControl." << std::endl;
		std::cout << "Список продуктов:" << std::endl;
		AccessControlLibrary::Configuration * config = new AccessControlLibrary::Configuration();
		config->setBaseApiUrl("https://acs.sersoftin.xyz/3");
		config->setHashSalt("TestHash");
		config->setProductId(1);
		config->setPublicKeyHash({ 0x9f, 0x71, 0x41, 0x48, 0x67, 0x18, 0x73, 0xce, 0x77, 0x1b, 0xe6, 0x14, 0x0c, 0x25, 0x22, 0xb1, 0x4d, 0xda, 0xf5, 0x12 });
		AccessControlLibrary::AccessControl * acl = new AccessControlLibrary::AccessControl(config);
		try
		{
			std::cout << acl->getProductInfo(2).getId() << ":" << acl->getProductInfo(2).getName() << std::endl;
		}
		catch (AccessControlLibrary::Exceptions::CurlException & ex)
		{
			std::cout << "CurlException: " << ex.what() << std::endl;
		}
		catch (AccessControlLibrary::Exceptions::CertificateCheckException & ex)
		{
			std::cout << "CertificateCheckException: " << ex.what() << std::endl;
		}
		catch (AccessControlLibrary::Exceptions::WebException & ex)
		{
			std::cout << "WebException: " << ex.getError().getCode() << std::endl;
		}
		delete config;
		delete acl;
		std::cout << "Введите номер продукта, на который вы хотите подать заявку: ";
		getchar();
	}
	catch (std::runtime_error ex)
	{
		std::cout << ex.what() << std::endl;
		getchar();
	}
	return 0;
}
