#include "base.h"
#pragma once

class list : public queue
{
public:
	list();

	list(int n);

	list(const list& other);

	~list();

	void push(int data, int index);

	void pop(int index);
};
