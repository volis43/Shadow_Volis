#include <iostream>
#include <time.h>

class pidoras
{
public:
	void pidrila()
	{
		int y = 2;
		int* Pty;
		Pty = &y;
		std::cout << &Pty << std::endl;
		std::cout << "Ahahahaah! FUCK YOU ALL! DIE ANYWHERE" << std::endl;
	}

	pidoras()
	{
		std::cout << "Do you remember me?" << std::endl;
	}
	
	~pidoras()
	{
		std::cout << "Fuck you gamed" << std::endl;
	}

	void virtual joke(std::string h) 
	{
		std::cout << "loli" << std::endl;
	}

};

int main()
{
	pidoras p;
	time_t start = time(0);
	std::cout << start << std::endl;

	double seconds_since_start = difftime(time(0), start);
	std::cout << "You must learn c++!" << std::endl;
	p.pidrila();
	std::cout << start << std::endl;
	
	return 0;
}