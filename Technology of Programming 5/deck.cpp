#include <iostream>
#include "deck.h"

using namespace std;

deck::deck()
{
	setTail(nullptr);
	setHead(nullptr);
}

deck::~deck()
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

deck::deck(deck& other)
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

deck::deck(int n)
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

void deck::popBack()
{
	Node* temp = getHead(); Node* tempPrev = temp; Node* tail = getTail();

	if (tail == nullptr)
	{
		cout << "Deck is empty, nothing to pop here" << endl << endl;
		return;
	}

	if (tail == temp)
	{
		delete(temp);
		setTail(nullptr);
		setHead(nullptr);
		cout << "This deck is empty now\n\n";
		return;
	}

	while (temp != tail)
	{
		tempPrev = temp;
		temp = temp->next;
	}
	delete(temp);
	setTail(tempPrev);
	tempPrev->next = nullptr;
	cout << "Element has succesfully popped from the back of the deck" << endl << endl;
}

void deck::popFront()
{
	if (getTail() == nullptr)
	{
		cout << "Deck is empty, nothing to pop here" << endl << endl;
		return;
	}

	if (getTail() == getHead())
	{
		delete(getHead());
		setTail(nullptr);
		setHead(nullptr);
		cout << "This deck is empty now\n\n";
		return;
	}

	Node* memFree = getHead();
	setHead(memFree->next);
	delete(memFree);
	cout << "Element has succesfully popped from the front of the deck" << endl << endl;
}

void deck::pushBack(int _data)
{
	Node* newNode = new Node; newNode->data = _data;
	newNode->next = nullptr;

	if (getTail() == nullptr)
	{
		setTail(newNode);
		setHead(newNode);
		return;
	}

	getTail()->next = newNode;
	setTail(newNode);
}

void deck::pushFront(int _data)
{
	Node* newNode = new Node; newNode->data = _data;

	if (getTail() == nullptr)
	{
		setTail(newNode);
		setHead(newNode);
		newNode->next = nullptr;
		return;
	}

	newNode->next = getHead();
	setHead(newNode);
}