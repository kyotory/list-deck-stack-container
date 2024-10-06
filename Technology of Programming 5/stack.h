#pragma once
#include "base.h"

class stack : public queue
{
public:
	stack();

	stack(int n);

	stack(stack& other);

	~stack();

	void push(int _data);

	void pop();
};
