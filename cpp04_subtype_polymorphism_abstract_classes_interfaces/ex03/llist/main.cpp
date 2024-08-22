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

	lst.insertNode(one);
	lst.insertNode(two);

	lst.printList();

	delete one;
	delete two;
	return (0);
}