#include <iostream>
#include "../CppACLib/AccessControl.h"


int main()
{
	setlocale(LC_ALL, "rus");
	SetConsoleTitleW(L"AC Test Application");
	std::cout << "AC Test - программа, которая позволяет проверить доступ ПО." << std::endl;

	auto config = new AccessControlLibrary::Configuration();
	config->setBaseApiUrl("https://acs.sersoftin.xyz/");
	config->setHashSalt("TestHash");
	config->setProductId(1);
	config->setCheckCertificate(true);
	config->setPublicKeyHash({ 0x9f, 0x71, 0x41, 0x48, 0x67, 0x18, 0x73, 0xce, 0x77, 0x1b, 0xe6, 0x14, 0x0c, 0x25, 0x22, 0xb1, 0x4d, 0xda, 0xf5, 0x12 });
	auto acl = new AccessControlLibrary::AccessControl(config);

	std::cout << (acl->accessAllowed() ? "Доступ разрешен!" : "Вы не имете права на использование этой программы.") << std::endl;
	delete config;
	delete acl;
	getchar();
	return 0;
}
