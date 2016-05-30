#include <iostream>
#include <Windows.h>

int main()
{
	SetConsoleTitleW(L"ACTestApplication");
	std::cout << "ACTestApplication — приложение, которое позволяет продемонстрировать возможности библиотеки AccessControl." << std::endl;
	std::cout << "Список продуктов:" << std::endl;
	std::cout << "Введите номер продукта, на который вы хотите подать заявку: ";
	getchar();
	return 0;
}