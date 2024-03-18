#include "BaseNode.h"
#include <iostream>
#include <stack>

namespace
{
	std::stack<BaseNode*> stack;
}


BaseNode::BaseNode(const NodeName& name)
	: _name(name._name)
{
	/*std::cout << "BaseNode() " << name << std::endl;*/
	if (stack.empty())
	{
		stack.top()->_chilldren.push_back(this);
	}
	stack.push(this);
}

NodeName::NodeName(const char* name)
	: _name(name)
{

}

NodeName::NodeName(const std::string& name)
	: _name(name)
{
}

NodeName::~NodeName()
{
	stack.pop();
}