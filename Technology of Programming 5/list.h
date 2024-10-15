#pragma once
#include "base.h"

class list : public queue
{
public:
	list();

	list(int n);

	list(list& other);

	~list();

	Node* getHead() override;

	Node* getTail() override;

	void setHead(Node* a) override;

	void setTail(Node* a) override;

	void printData() override;

	void push(int data) override;

	void pop() override;

	void writeToFile(fstream& fileDatabase) override;
};
