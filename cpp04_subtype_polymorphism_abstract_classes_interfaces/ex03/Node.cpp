#include "Node.hpp"

Node::Node()
{
	data = NULL;
	next = NULL;
	std::cout << "Node default constructor\n";
}

Node:: Node(AMateria  *val)
{
	this->data = val->clone();
	this->next = NULL;
	std::cout << "Node value constructor\n";
}

Node::~Node()
{
	if (data != NULL)
		delete data;
	next = NULL;
	std::cout << "Node destructor\n";
}

Node::Node(const Node &other)
{
	std::cout << "Node copy constructor\n";
	this->data = other.data->clone();
	this->next = NULL;
}

Node &Node::operator=(const Node &other)
{
	std::cout << "Node copy assignment operator overload\n";
	this->data = other.data->clone();
	this->next = NULL;
	return (*this);
}