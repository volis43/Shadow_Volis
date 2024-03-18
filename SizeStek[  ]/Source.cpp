#include <iostream>

int main()
{
	int lenght;
	std::cin >> lenght;
	int* Pm = new int[lenght];
	std::cout << Pm << " " << &Pm<< " " << lenght;
	delete[] Pm;
	return 0;
}