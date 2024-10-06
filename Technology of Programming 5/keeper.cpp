#include <iostream>
#include "keeper.h"
#include <fstream>

using namespace std;

keeper::keeper()
{
	fstream deck("deck.txt");
	fstream stack("stack.txt");
	fstream list("list.txt");

	if (deck.peek() == EOF)
	{
		headDeck = nullptr;
		tailDeck = nullptr;
	}

	if (stack.peek() == EOF)
	{
		headStack = nullptr;
		tailStack = nullptr;
	}

	if (list.peek() == EOF)
	{
		headList = nullptr;
		tailList = nullptr;
	}

	if (deck.peek() != EOF)
	{
		// readDeck
	}

	if (stack.peek() != EOF)
	{
		// readStack
	}

	if (list.peek() != EOF)
	{
		// readList
	}
}

keeper::~keeper()
{
	deckContainer* tempDeck = getHeadDeck();

	while (tempDeck != nullptr)
	{
		deckContainer* nextTempDeck = tempDeck->next;
		delete tempDeck;
		tempDeck = nextTempDeck;
	}

	setTailDeck(nullptr);
	setHeadDeck(nullptr);

	stackContainer* tempStack = getHeadStack();

	while (tempStack != nullptr)
	{
		stackContainer* nextTempStack = tempStack->next;
		delete tempStack;
		tempStack = nextTempStack;
	}

	setTailStack(nullptr);
	setHeadStack(nullptr);

	listContainer* tempList = getHeadList();

	while (tempList != nullptr)
	{
		listContainer* nextTempList = tempList->next;
		delete tempList;
		tempList = nextTempList;
	}

	setTailList(nullptr);
	setHeadList(nullptr);
}

void keeper::push(list _data)
{
	listContainer* newNode = new listContainer;
	newNode->data = _data;

	if (getTailList() == nullptr) {
		setTailList(newNode);
		setHeadList(newNode);
		newNode->next = nullptr;
		return;
	}

	newNode->next = getHeadList();
	setHeadList(newNode);
}

void keeper::push(stack _data)
{
	stackContainer* newNode = new stackContainer;
	newNode->data = _data;

	if (getTailStack() == nullptr) {
		setTailStack(newNode);
		setHeadStack(newNode);
		newNode->next = nullptr;
		return;
	}

	newNode->next = getHeadStack();
	setHeadStack(newNode);
}

void keeper::push(deck _data)
{
	deckContainer* newNode = new deckContainer;
	newNode->data = _data;

	if (getTailDeck() == nullptr) {
		setTailDeck(newNode);
		setHeadDeck(newNode);
		newNode->next = nullptr;
		return;
	}

	newNode->next = getHeadDeck();
	setHeadDeck(newNode);
}

listContainer* keeper::getHeadList()
{
	return headList;
}

deckContainer* keeper::getHeadDeck()
{
	return headDeck;
}

stackContainer* keeper::getHeadStack()
{
	return headStack;
}

listContainer* keeper::getTailList()
{
	return tailList;
}

deckContainer* keeper::getTailDeck()
{
	return tailDeck;
}

stackContainer* keeper::getTailStack()
{
	return tailStack;
}

void keeper::setHeadList(listContainer* head)
{
	headList = head;
}

void keeper::setHeadDeck(deckContainer* head)
{
	headDeck = head;
}

void keeper::setHeadStack(stackContainer* head)
{
	headStack = head;
}

void keeper::setTailList(listContainer* tail)
{
	tailList = tail;
}

void keeper::setTailDeck(deckContainer* tail)
{
	tailDeck = tail;
}

void keeper::setTailStack(stackContainer* tail)
{
	tailStack = tail;
}

listContainer* keeper::selectElemList(int index)
{
	listContainer* temp = getHeadList();

	for (int i = 0; i < index; i++)
	{
		temp = temp->next;
	}

	return temp;
}
deckContainer* keeper::selectElemDeck(int index)
{
	deckContainer* temp = getHeadDeck();

	for (int i = 0; i < index; i++)
	{
		temp = temp->next;
	}

	return temp;
}
stackContainer* keeper::selectElemStack(int index)
{
	stackContainer* temp = getHeadStack();

	for (int i = 0; i < index; i++)
	{
		temp = temp->next;
	}

	return temp;
}

void keeper::writeContainer(listContainer* head)
{

}

void keeper::writeContainer(deckContainer* head)
{

}

void keeper::writeContainer(stackContainer* head)
{

}