#include "base.h"
#pragma once

class list : public queue
{
public:
	list();

	list(int n);

	list(list& other);

	~list();

	void push(int _data, int index);

	void pop(int index);
};
