#include <iostream>
#include "../CppACLib/AccessControl.h"


int main()
{
	setlocale(LC_ALL, "rus");
	SetConsoleTitleW(L"ACTestApplication");
	std::cout << "ACTestApplication � ����������, ������� ��������� ������������������ ����������� ���������� AccessControl." << std::endl;
	std::cout << "������ ���������:" << std::endl;
	AccessControlLibrary::Configuration * config = new AccessControlLibrary::Configuration();
	config->setBaseApiUrl("https://acs.sersoftin.xyz/");
	config->setHashSalt("TestHash");
	config->setProductId(1);
	AccessControlLibrary::AccessControl * acl = new AccessControlLibrary::AccessControl(config);
	std::cout << acl->getProductInfo(1).getId() << ":" << acl->getProductInfo(1).getName() << std::endl;
	delete config;
	delete acl;
	std::cout << "������� ����� ��������, �� ������� �� ������ ������ ������: ";
	getchar();
	return 0;
}
