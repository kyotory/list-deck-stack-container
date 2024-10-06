#pragma once
#include "base.h"

class deck: public queue
{
public:
	deck();

	deck(int n);

	deck(deck& other);

	~deck();

	void pushFront(int _data);

	void popFront();

	void pushBack(int _data);

	void popBack();
};
