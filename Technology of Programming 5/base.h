#pragma once
#include <fstream>

using namespace std;

struct Node
{
	int data;
	Node* next;
};

class queue
{
protected:
	Node* head;
	Node* tail;

public:
	virtual Node* getHead() = 0;

	virtual Node* getTail() = 0;

	virtual void setHead(Node* a) = 0;

	virtual void setTail(Node* a) = 0;

	virtual void printData() = 0;

	virtual void pop() = 0;

	virtual void push(int data) = 0;

	virtual void writeToFile(fstream& fileDatabase) = 0;
};
