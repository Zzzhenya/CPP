#include "LinkedList.hpp"
#include <iostream>

int main(void)
{

	LinkedList lst;

	lst.insertNode(1);
	lst.insertNode(22);
	lst.insertNode(34);

	lst.printList();
	return (0);
}