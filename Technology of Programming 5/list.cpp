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

Node* list::getHead()
{
	return head;
}

void list::setHead(Node* a)
{
	head = a;
}

Node* list::getTail()
{
	return tail;
}

void list::setTail(Node* a)
{
	tail = a;
}

void list::printData()
{
	cout << "List - ";
	Node* temp = head;
	while (temp != nullptr)
	{
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << endl << endl;
}

void list::push(int data)
{
	cout << endl << "Write an index that you want push to: ";
	int index;
	cin >> index;

	if (index < 0)
	{
		cout << "Incorrect index" << endl << endl;
		return;
	}

	Node* newNode = new Node;
	newNode->data = data;

	if (getTail() == nullptr) {
		setTail(newNode);
		setHead(newNode);
		newNode->next = nullptr;
		cout << endl << "Element has sucessfully pushed to the list by index" << endl << endl;
		return;
	}

	if (index == 0)
	{
		newNode->next = getHead();
		setHead(newNode);
		cout << endl << "Element has sucessfully pushed to the list by index" << endl << endl;
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
		cout << endl << "Element has sucessfully pushed to the list by index" << endl << endl;
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
	cout << endl << "Element has sucessfully pushed to the list by index" << endl << endl;
}

void list::writeToFile(fstream& fileDatabase)
{
	Node* temp = head;
	fileDatabase << "l ";
	while (temp != nullptr)
	{
		fileDatabase << temp->data;
		if (temp != tail) fileDatabase << " ";
		temp = temp->next;
	}
	fileDatabase << '\n';
}

void list::pop()
{
	cout << "Write an index that you want pop by" << endl << endl;
	int index;
	cin >> index;

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