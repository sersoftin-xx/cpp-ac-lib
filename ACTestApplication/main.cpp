#include <iostream>
#include <Windows.h>

int main()
{
	SetConsoleTitleW(L"ACTestApplication");
	std::cout << "ACTestApplication � ����������, ������� ��������� ������������������ ����������� ���������� AccessControl." << std::endl;
	std::cout << "������ ���������:" << std::endl;
	std::cout << "������� ����� ��������, �� ������� �� ������ ������ ������: ";
	getchar();
	return 0;
}