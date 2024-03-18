#include <iostream>
#include "BaseNode.h"

class C : public BaseNode
{
public:
	C(const NodeName& name)
		: BaseNode(name)
	{

	}

};


class A : public BaseNode 
{
public:
	A(const NodeName& name)
		: BaseNode(name)
	{
		
	}
private:
	C NODE_DECL(_c);
};
class B : public BaseNode 
{
public:
	B(const NodeName& name)
		: BaseNode(name)
	{
		
	}
private:
	C NODE_DECL(_c);
};


class Parent : public BaseNode
{
public:
	Parent(const NodeName& name)
		: BaseNode(name)
	{
		
	}
private:
	A NODE_DECL(_a);
	B NODE_DECL(_b);
};

int main()
{
	Parent NODE_DECL(parent);
	return 0;
}