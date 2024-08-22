#ifndef LINKEDLIST_HPP
# define LINKEDLIST_HPP

# include <iostream>
# include "Node.hpp"
# include "../AMateria.hpp"

class LinkedList
{
	public:
		LinkedList();
		~LinkedList();
		LinkedList(const LinkedList &other);
		LinkedList	&operator=(const LinkedList &other);

		void insertNode(AMateria *val);
		void printList();

	private:
		Node *head;

};

#endif