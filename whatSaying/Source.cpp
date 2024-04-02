#include <iostream>

class Sad
{
public:
	float sad = 100.0;

};

class Human : public Sad
{
public:
	void get(float sad)
	{
		this->sad = sad;
	    std::cout << sad << std::endl;
	}
};

struct LL
{
	short m = 10;
};


int main()
{
	Human n;
	n.get(89);
	LL l;
	l.m = 7;
	std::cout << l.m;
	int y;
	int n[y];
	std::cin >> y;
	
}