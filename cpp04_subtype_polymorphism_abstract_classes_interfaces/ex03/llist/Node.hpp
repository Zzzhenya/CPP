#ifndef NODE_HPP
# define NODE_HPP

# include <iostream>
# include "../AMateria.hpp"

class Node
{
	public:
		Node 		*next;
		AMateria  	*data;

		Node();
		Node(AMateria  *val);
		~Node();
};

#endif