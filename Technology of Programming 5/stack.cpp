#include <iostream>
#include "stack.h"

using namespace std;

stack::stack()
{
	setTail(nullptr);
	setHead(nullptr);
}

stack::stack(int n)
{
	if (n == 0)
	{
		setTail(nullptr);
		setHead(nullptr);
		return;
	}

	for (int i = 0; i < n; i++)
	{
		Node* newNode = new Node;

		if (getTail() == nullptr)
		{
			setTail(newNode);
			setHead(newNode);
		}

		int temp;
		cin >> temp;
		newNode->data = temp;
		getTail()->next = newNode;
		newNode->next = nullptr;
		setTail(newNode);
	}
}

stack::stack(stack& other)
{
	setHead(nullptr);
	setTail(nullptr);
	Node* temp = other.getHead();

	while (temp != nullptr)
	{
		Node* newNode = new Node;
		newNode->data = temp->data;

		if (other.getTail() == other.getHead())
		{
			setTail(newNode);
			setHead(newNode);
			return;
		}

		temp = temp->next;
		setHead(newNode);
	}
}

stack::~stack()
{
	Node* temp = getHead();

	while (temp != nullptr)
	{
		Node* nextTemp = temp->next;
		delete temp;
		temp = nextTemp;
	}

	setTail(nullptr);
	setHead(nullptr);
}

Node* stack::getHead()
{
	return head;
}

void stack::setHead(Node* a)
{
	head = a;
}

Node* stack::getTail()
{
	return tail;
}

void stack::setTail(Node* a)
{
	tail = a;
}

void stack::writeToFile(fstream& fileDatabase)
{
	Node* temp = head;
	fileDatabase << "s ";
	while (temp != nullptr)
	{
		fileDatabase << temp->data;
		if (temp != tail) fileDatabase << " ";
		temp = temp->next;
	}
	fileDatabase << '\n';
}

void stack::printData()
{
	cout << "Stack - ";
	Node* temp = head;
	while (temp != nullptr)
	{
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << endl << endl;
}

void stack::push(int _data)
{
	Node* newNode = new Node;
	newNode->data = _data;

	if (getTail() == nullptr) {
		setTail(newNode);
		setHead(newNode);
		newNode->next = nullptr;
		cout << endl << "Element has sucessfully pushed to the stack" << endl << endl;
		return;
	}

	newNode->next = getHead();
	setHead(newNode);
	cout << endl << "Element has sucessfully pushed to the stack" << endl << endl;
}

void stack::pop()
{
	Node* temp = getHead();
	if (temp == nullptr)
	{
		cout << "No elements for deleting";
		return;
	}

	if (temp == getTail())
	{
		delete(temp);
		setHead(nullptr); setTail(nullptr);
		cout << "Element has succesfully popped from the stack" << endl << endl;
		return;
	}

	setHead(getHead()->next);
	delete(temp);
	cout << "Element has succesfully popped from the stack" << endl << endl;
}