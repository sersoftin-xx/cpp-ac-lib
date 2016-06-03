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
		config->setBaseApiUrl("http://acs.sersoftin.xyz/");
		config->setHashSalt("TestHash");
		config->setProductId(1);
		config->setCheckCertificate(false);
		config->setPublicKeyHash({ 0x9f, 0x71, 0x41, 0x48, 0x67, 0x18, 0x73, 0xce, 0x77, 0x1b, 0xe6, 0x14, 0x0c, 0x25, 0x22, 0xb1, 0x4d, 0xda, 0xf5, 0x12 });
		AccessControlLibrary::AccessControl * acl = new AccessControlLibrary::AccessControl(config);
		
		auto request_id = 0;
		std::cout << "Введите номер продукта, на который вы хотите подать заявку: ";
		std::cin >> request_id;

		try
		{
			auto bid = acl->requestAccess(request_id);
			std::cout << "bid id: " << bid.getId() << std::endl;
		}
		catch (AccessControlLibrary::Exceptions::WebException & ex)
		{
			std::cout << "WebException: " << ex.getError().getCode() << ":" << ex.getError().getMessage() << ":" << ex.getError().getUrl() << std::endl;
		}
		delete config;
		delete acl;
		getchar();
		getchar();
	}
	catch (std::runtime_error ex)
	{
		std::cout << ex.what() << std::endl;
		getchar();
	}
	return 0;
}
