#pragma once
#include <string>
#include <vector>

#define NODE_DECL(obj) obj{#obj}

struct NodeName
{
	NodeName(const char* name);
	NodeName(const std::string& name);
	~NodeName();

	std::string _name;
};

class BaseNode
{
public:
	BaseNode(const NodeName& name);
protected:
	std::string _name;
	std::vector<BaseNode*> _chilldren;
};





