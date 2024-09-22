#pragma once

struct Node
{
	int data;
	Node* next;
};

class queue
{
private:
	Node* head;
	Node* tail;

public:
	Node* getHead();

	void setHead(Node* a);

	Node* getTail();

	void setTail(Node* a);

	void printData();
};
