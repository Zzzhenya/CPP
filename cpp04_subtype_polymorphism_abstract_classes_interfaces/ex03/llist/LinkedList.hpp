#ifndef LINKEDLIST_HPP
# define LINKEDLIST_HPP

# include <iostream>
# include "Node.hpp"
# include "../AMateria.hpp"

class LinkedList
{
	private:
		Node *head;

	public:
		LinkedList();
		~LinkedList();
		void insertNode(AMateria *val);
		void printList();
		// void deleteNode(int val);
};

#endif