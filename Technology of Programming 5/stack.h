#pragma once
#include "base.h"

class stack : public queue
{
public:
	stack();

	stack(int n);

	stack(stack& other);

	~stack();

	Node* getHead() override;

	Node* getTail() override;

	void setHead(Node* a) override;

	void setTail(Node* a) override;

	void printData() override;

	void push(int data) override;

	void pop() override;

	void writeToFile(fstream& fileDatabase) override;
};
