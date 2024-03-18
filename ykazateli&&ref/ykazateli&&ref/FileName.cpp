#include <iostream>



int main()
{
	int x = 0;
	int* p = &x;
	std::cout << p << std::endl;
	*p = 9;
	std::cout << *p << std::endl;
	int l = 110;
	int& ref = l;
	std::cout << &ref << std::endl;
	
	

}