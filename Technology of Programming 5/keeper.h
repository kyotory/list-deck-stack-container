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

	listContainer* tailList;

	deckContainer* tailDeck;

	stackContainer* tailStack;

public:
	keeper();

	~keeper();

	void push(list _data);

	void push(stack _data);

	void push(deck _data);

	void popList(listContainer* aim);

	void popStack(stackContainer* aim);

	void popDeck(deckContainer* aim);

	listContainer* getHeadList();

	deckContainer* getHeadDeck();

	stackContainer* getHeadStack();

	listContainer* getTailList();

	deckContainer* getTailDeck();

	stackContainer* getTailStack();

	listContainer* selectElemList(int index);

	deckContainer* selectElemDeck(int index);

	stackContainer* selectElemStack(int index);

	void setHeadList(listContainer* head);

	void setHeadDeck(deckContainer* head);

	void setHeadStack(stackContainer* head);

	void setTailList(listContainer* tail);

	void setTailDeck(deckContainer* tail);

	void setTailStack(stackContainer* tail);

	void writeContainer(deckContainer* deckptr);

	void writeContainer(stackContainer* stackptr);

	void writeContainer(listContainer* listptr);
};
