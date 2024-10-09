#include <iostream>
#include "list.h"

using namespace std;

list::list()
{
	setTail(nullptr);
	setHead(nullptr);
}

list::list(list& other)
{
	setHead(nullptr);
	setTail(nullptr);
	Node* temp = other.getHead();

	while (temp != nullptr)
	{
		Node* newNode = new Node;
		newNode->data = temp->data;
		if (other.getTail() == other.getHead()) {
			setTail(newNode);
			setHead(newNode);
			return;
		}
		temp = temp->next;
		setHead(newNode);
	}
}

list::list(int n)
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

list::~list()
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

void list::push(int _data, int index)
{
	if (index < 0)
	{
		cout << "Incorrect index" << endl << endl;
		return;
	}

	Node* newNode = new Node;
	newNode->data = _data;

	if (getTail() == nullptr) {
		setTail(newNode);
		setHead(newNode);
		newNode->next = nullptr;
		return;
	}

	if (index == 0)
	{
		newNode->next = getHead();
		setHead(newNode);
		return;
	}

	Node* temp = getHead(); int cnt = 0;
	Node* tempPrev = temp;

	while (temp != nullptr)
	{
		cnt++;
		temp = temp->next;
	}

	if (index > cnt)
	{
		newNode->next = nullptr;
		getTail()->next = newNode;
		setTail(newNode);
		return;
	}

	temp = getHead();
	
	for (int i = 0; i < index; i++)
	{
		tempPrev = temp;
		temp = temp->next;
	}

	tempPrev->next = newNode;
	newNode->next = temp;
}

void list::pop(int index)
{
	if (index < 0)
	{
		cout << "\nIncorrect index" << endl << endl;
		return;
	}

	Node* temp = getHead(); Node* tempPrev = temp; int cnt = 0;

	if (temp == nullptr)
	{
		cout << "\nNo elements for deleting";
		return;
	}

	if (temp == getTail())
	{
		delete(temp);
		setHead(nullptr); setTail(nullptr);
		cout << "\nElement has succesfully popped from the list" << endl << endl;
		return;
	}

	while (temp != nullptr)
	{
		cnt++;
		tempPrev = temp;
		temp = temp->next;
	}

	if (index == 0)
	{
		Node* memFree = getHead();
		setHead(memFree->next);
		delete(memFree);
		cout << "\nElement has succesfully popped from the list" << endl << endl;
		return;
	}

	if (index >= (cnt - 1))
	{
		temp = getHead(); tempPrev = temp; Node* tail = getTail();
		while (temp != tail)
		{
			tempPrev = temp;
			temp = temp->next;
		}
		delete(temp);
		setTail(tempPrev);
		tempPrev->next = nullptr;
		cout << "\nElement has succesfully popped from the list" << endl << endl;
		return;
	}

	temp = getHead(); tempPrev = temp;

	for (int i = 0; i < index; i++)
	{
		tempPrev = temp;
		temp = temp->next;
	}

	tempPrev->next = temp->next;
	delete(temp);
	cout << "\nElement has succesfully popped from the list" << endl << endl;
}