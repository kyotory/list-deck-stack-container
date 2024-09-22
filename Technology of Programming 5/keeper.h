#pragma once
#include "list.h"
#include "stack.h"
#include "deck.h"

struct listContainer
{
	list data;
	listContainer* next;
};

struct deckContainer
{
	deck data;
	deckContainer* next;
};

struct stackContainer
{
	stack data;
	stackContainer* next;
};

class keeper
{
private:
	listContainer* headList;

	deckContainer* headDeck;

	stackContainer* headStack;

public:
	listContainer* getHeadList();

	deckContainer* getHeadDeck();

	stackContainer* getHeadStack();

	void setHead(listContainer* head);

	void setHead(deckContainer* head);

	void setHead(stackContainer* head);

	void writeContainer(listContainer* head);

	void writeContainer(deckContainer* head);

	void writeContainer(stackContainer* head);

	void readContainer();
};
