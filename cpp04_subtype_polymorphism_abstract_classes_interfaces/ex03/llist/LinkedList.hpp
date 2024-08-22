#ifndef LINKEDLIST_HPP
# define LINKEDLIST_HPP

# include <iostream>
# include "Node.hpp"

class LinkedList
{
	private:
		Node *head;
	public:
		LinkedList();
		void insertNode(int val);
		void printList();
		// void deleteNode(int val);
};

#endif