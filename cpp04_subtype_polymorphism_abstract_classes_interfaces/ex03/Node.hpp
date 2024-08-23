#ifndef NODE_HPP
# define NODE_HPP

# include <iostream>
# include "AMateria.hpp"

class Node
{
	public:
		Node 		*next;
		AMateria  	*data;

		Node();
		Node(AMateria  *val);
		~Node();
	private:
		Node(const Node &other);
		Node &operator=(const Node &other);
};

#endif