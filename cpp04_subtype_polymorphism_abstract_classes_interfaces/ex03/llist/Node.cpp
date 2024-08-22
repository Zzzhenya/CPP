#include "Node.hpp"

Node::Node()
{
	data = NULL;
	next = NULL;
	std::cout << "Node default constructor\n";
}

Node:: Node(AMateria  *val)
{
	this->data = val;
	this->next = NULL;
	std::cout << "Node Int constructor\n";
}

Node::~Node()
{
	std::cout << "Node destructor\n";
}