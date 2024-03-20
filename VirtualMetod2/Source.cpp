#include <iostream>
#include <string>

class Robotnik
{
public:
	Robotnik()
	{
		std::cout << "Vizov konstruct" << std::endl;
	}
	
	~Robotnik()
	{
		std::cout << "Vizov destruct" << std::endl;
	}

	virtual void GoWork() = 0  // если после функции стоит 0, то это абстрактный класс. От него нельзя брать обьекты. 
	{
		std::cout << "GoWork" << std::endl;
	}
};

class Tails
{
private:
	int poop;
public:
	Tails()
	{
		std::cout << "work2" << std::endl;
	}
	
	~Tails()
	{
		std::cout << "decta7" << std::endl;
	}

	void setProp(int poop)
	{
		this->poop = poop;
	}
	int getProp()
	{
		return this->poop;
	}
};

class Designed : public Robotnik
{
	void GoWork()
	{
		std::cout << "Designed Go To Work!" << std::endl;
	}
};

class Sonic : public Robotnik
{
public:
	void GoWork()
	{
		std::cout << "Run to Robotnik" << std::endl;
	}
};

class Proger : public Robotnik
{
public:
	void GoWork()
	{
		std::cout << "Proger go to work" << std::endl;
	}
};

int main()
{
	Robotnik* robo;
	Designed* des = new Designed; // даю память этим указателям
	Sonic* spd = new Sonic;
	Proger* ptr = new Proger;
	Tails* fo = new Tails();
	
	fo->setProp(99);
	std::cout << (*fo).getProp() << std::endl;
	fo->getProp();
	delete fo;
	robo = des;
	//robo->GoWork();
	robo = spd;
	//robo->GoWork();
	Robotnik* mas[3];

	/*int* p;
	p = new int;
	int w = 0;
	*p = w;
	int mass = w;*/
	
	mas[0] = des;
	mas[1] = spd;
	mas[2] = ptr;

	for (int i = 0; i < 3; i++)
	{
		mas[i]->GoWork();
	}


	
	

	return 0;
}