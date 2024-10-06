#include <iostream>
#include "base.h"

using namespace std;

Node* queue::getHead()
{
	return head;
}

void queue::setHead(Node* a)
{
	head = a;
}

Node* queue::getTail()
{
	return tail;
}

void queue::setTail(Node* a)
{
	tail = a;
}

void queue::printData()
{
	Node* temp = head;
	while (temp != nullptr)
	{
		cout << temp->data << " ";
		temp = temp->next;
	}
}