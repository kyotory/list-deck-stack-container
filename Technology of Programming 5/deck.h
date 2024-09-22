#pragma once
#include "base.h"

class deck: public queue
{
public:
	deck();

	deck(int n);

	deck(const deck& other);

	~deck();

	void pushFront(int data);

	void popFront();

	void pushBack(int data);

	void popBack();
};
