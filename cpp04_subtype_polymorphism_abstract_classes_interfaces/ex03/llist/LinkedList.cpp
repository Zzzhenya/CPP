#include "LinkedList.hpp"

/*
	private:
		Node *head;
	public:
		LinkedList()
		void insertNode(int val);
		void printList();
		void deleteNode(int val);
*/

LinkedList::LinkedList()
{
	head = NULL;
	std::cout << "LL default constructor\n";
}

LinkedList::~LinkedList()
{
	std::cout << "LL destructor\n";
	if (this->head == NULL)
		return;
	Node *curr = head;
	Node *temp = NULL;

	while(curr != NULL)
	{
		temp = curr;
		curr = curr->next;
		delete temp;
	}
}

void LinkedList::insertNode(AMateria *val)
{

	Node *newNode = new Node(val);

	if (head == NULL)
	{
		head = newNode;
		return;
	}

	Node *temp = head;

	while (temp->next != NULL)
		temp = temp->next;
	temp->next = newNode;
}

void LinkedList::printList()
{
	Node *temp = head;

	if (head == NULL)
	{
		std::cout << "Empty list\n";
		return;
	}

	while (temp != NULL)
	{
		//std::cout << temp->data << " ";
		std::cout << temp->data->getType() << " ";
		temp = temp->next;
	}
	std::cout << std::endl;
}
// void deleteNode(int val);