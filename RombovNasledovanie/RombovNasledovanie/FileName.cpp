#include <iostream>

class A
{
public:
	int i;
};

//class B : public A
class B : virtual public A
{
public:
	int j;
};

//class C : public A
class C : virtual public A
{
public:
	int k;
};

class D : public B, public C
{
public:
	int m;
};


int main()
{
	D d;
	/*d.i = 1;*/ // we have ref error :(
	/*d.A::i = 1;*/
	d.i = 0;
	d.j = 1;
	d.k = 2;
	d.m = 3;

	return 0;
}