#include <iostream>
#include <Windows.h>
#include "../CppACLib/Configuration.h"

int main()
{
	setlocale(LC_ALL, "rus");
	SetConsoleTitleW(L"ACTestApplication");
	std::cout << "ACTestApplication � ����������, ������� ��������� ������������������ ����������� ���������� AccessControl." << std::endl;
	std::cout << "������ ���������:" << std::endl;
	std::cout << "������� ����� ��������, �� ������� �� ������ ������ ������: ";
	getchar();
	return 0;
}
