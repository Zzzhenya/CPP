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

Node::Node(const Node &other)
{
	std::cout << "Node copy constructor\n";
	this->data = other.data;
	this->next = other.next;
}

Node &Node::operator=(const Node &other)
{
	std::cout << "Node copy assignment operator overload\n";
	this->data = other.data;
	this->next = other.next;
	return (*this);
}