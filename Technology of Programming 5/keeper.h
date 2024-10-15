#pragma once
#include "list.h"
#include "stack.h"
#include "deck.h"
#include <fstream>

using namespace std;

struct container
{
	queue* data;
	container* next;
};

class keeper
{
private:
	container* tail;
	container* head;

public:
	keeper();

	keeper(fstream& f);

	~keeper();

	void operator+(queue* _data);

	void operator-(container* aim);

	container* getHead();

	container* getTail();

	void setHead(container* newHead);

	void setTail(container* newTail);

	container* selectElem(int index);

	void writeContainer();

	void printContainer();
};
