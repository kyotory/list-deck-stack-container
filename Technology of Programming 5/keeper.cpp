#include <iostream>
#include "keeper.h"

using namespace std;

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

void keeper::setHead(listContainer* head)
{
	headList = head;
}

void keeper::setHead(deckContainer* head)
{
	headDeck = head;
}

void keeper::setHead(stackContainer* head)
{
	headStack = head;
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

void keeper::readContainer()
{

}