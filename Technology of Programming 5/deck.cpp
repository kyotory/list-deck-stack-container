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

void deck::writeToFile(fstream& fileDatabase)
{
	Node* temp = head;
	fileDatabase << "d ";
	while (temp != nullptr)
	{
		fileDatabase << temp->data;
		if (temp != tail) fileDatabase << " ";
		temp = temp->next;
	}
	fileDatabase << '\n';
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

Node* deck::getHead()
{
	return head;
}

void deck::setHead(Node* a)
{
	head = a;
}

Node* deck::getTail()
{
	return tail;
}

void deck::setTail(Node* a)
{
	tail = a;
}

void deck::printData()
{
	cout << "Deck - ";
	Node* temp = head;
	while (temp != nullptr)
	{
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << endl << endl;
}

void deck::pop()
{
	if (tail == nullptr)
	{
		cout << "Deck is empty, nothing to pop here" << endl << endl;
		return;
	}

	int choice;
	cout << "1 - Pop back element" << endl << endl;
	cout << "2 - Pop front element" << endl << endl;
	cout << "Select the option: ";
	cin >> choice;
	if (choice == 1)
	{
		Node* temp = getHead(); Node* tempPrev = temp; Node* tail = getTail();

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
		cout << endl << "Element has succesfully popped from the back of the deck" << endl << endl;
	}
	else if (choice == 2)
	{
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
		cout << endl << "Element has succesfully popped from the front of the deck" << endl << endl;
	}
	else
	{
		cout << endl << "Incorrect index";
		return;
	}
}

void deck::push(int data)
{
	int choice;
	cout << endl << "1 - Push back element" << endl << endl;
	cout << "2 - Push front element" << endl << endl;
	cout << "Select the option: ";
	cin >> choice;
	if (choice == 1)
	{
		Node* newNode = new Node; newNode->data = data;
		newNode->next = nullptr;

		if (getTail() == nullptr)
		{
			setTail(newNode);
			setHead(newNode);
			cout << endl << "Element has sucessfully pushed to the back of the deck" << endl << endl;
			return;
		}

		getTail()->next = newNode;
		setTail(newNode);
		cout << endl << "Element has sucessfully pushed to the back of the deck" << endl << endl;
	}
	else if (choice == 2)
	{
		Node* newNode = new Node; newNode->data = data;

		if (getTail() == nullptr)
		{
			setTail(newNode);
			setHead(newNode);
			newNode->next = nullptr;
			cout << endl << "Element has sucessfully pushed to the front of the deck" << endl << endl;
			return;
		}

		newNode->next = getHead();
		setHead(newNode);
		cout << endl << "Element has sucessfully pushed to the front of the deck" << endl << endl;
	}
	else
	{
		cout << endl << "Incorrect index";
		return;
	}
}