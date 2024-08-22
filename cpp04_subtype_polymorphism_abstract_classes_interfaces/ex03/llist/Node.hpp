#ifndef NODE_HPP
# define NODE_HPP

# include <iostream>

class Node
{
	public:
		Node 	*next;
		int  	data;

		Node();
		Node(int val);
		~Node();
};

#endif