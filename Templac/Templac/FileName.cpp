#include <iostream>


template <typename T, int lenght>

class Array
{
public:
	T array[lenght];

	void fill(T value)
	{
		for (int i = 0; i < lenght; i++)
		{
			array[i] = value;
		}
	}

	T at(int index)
	{
		return array[index];
	}
};


int main()
{
	Array <int, 10> intArr;

	intArr.fill(3);

	std::cout << "intArray[6]: " << intArr.at(6) << std::endl;
	
	Array<std::string, 8> strArr;

	strArr.fill("avoid");
	strArr.at(2) = "33434";
	for (int i = 0; i < 8; i++)
		std::cout << "StrArr[" << i << "]: " << strArr.at(i) << std::endl;

	return 0;
}