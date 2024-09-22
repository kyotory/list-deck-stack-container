#pragma once
#include "base.h"

class stack : public queue
{
	stack();

	stack(int n);

	stack(const stack& other);

	~stack();

	void push(int data);

	void pop();
};
