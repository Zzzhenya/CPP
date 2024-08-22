#include "LinkedList.hpp"
#include "../AMateria.hpp"
#include "../Cure.hpp"
#include "../Ice.hpp"
#include <iostream>

int main(void)
{

	AMateria *one = new Cure();
	AMateria *two = new Cure();
	LinkedList lst;
	LinkedList lst1;
	

	lst.insertNode(one);
	lst.insertNode(two);

	lst1.insertNode(one);

	lst.printList();
	lst1.printList();

	//LinkedList cpy = LinkedList(lst);
	lst1 = LinkedList(lst);
	delete one;
	delete two;
	return (0);
}