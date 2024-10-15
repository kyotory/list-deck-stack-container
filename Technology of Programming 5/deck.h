#pragma once
#include "base.h"

class deck : public queue
{
public:
	deck();

	deck(int n);

	deck(deck& other);

	~deck();

	Node* getHead() override;

	Node* getTail() override;

	void setHead(Node* a) override;

	void setTail(Node* a) override;

	void printData() override;

	void push(int data) override;

	void pop() override;

	void writeToFile(fstream& fileDatabase) override;
};
