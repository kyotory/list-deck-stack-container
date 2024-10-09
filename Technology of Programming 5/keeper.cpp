#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "keeper.h"

using namespace std;

keeper::keeper()
{
	fstream deckFile("deck.txt");

	if (!deckFile.is_open())
	{
		std::cerr << "Can't open deck file" << std::endl;
		return;
	}

	fstream stackFile("stack.txt");

	if (!stackFile.is_open())
	{
		std::cerr << "Can't open stack file" << std::endl;
		return;
	}

	fstream listFile("list.txt");

	if (!listFile.is_open())
	{
		std::cerr << "Can't open list file" << std::endl;
		return;
	}

	if (deckFile.peek() == EOF)
	{
		headDeck = nullptr;
		tailDeck = nullptr;
	}
	else
	{
		string line; int cnt = 0;

		while (getline(deckFile, line)) cnt++;

		deckContainer* prevNodeDeck = nullptr;

		for (int i = 0; i < cnt; i++)
		{
			deckContainer* newNodeDeck = new deckContainer; 
			deck* newNode = new deck;
			newNodeDeck->data = *newNode;

			if (i == 0)
			{
				headDeck = newNodeDeck;
				newNodeDeck->next = nullptr;
				prevNodeDeck = newNodeDeck;
			}
			else
			{
				newNodeDeck->next = nullptr;
				prevNodeDeck->next = newNodeDeck;
				prevNodeDeck = newNodeDeck;
			}
		}
		tailDeck = prevNodeDeck;

		line.clear(); deckFile.close(); fstream deckFile("deck.txt");

		deckContainer* temp = headDeck; Node* prevNode = nullptr; int _data = 0;

		for (int i = 0; i < cnt; i++)
		{
			int flag_ft = 1;

			getline(deckFile, line); stringstream ss(line);

			while (ss >> _data)
			{
				Node* newNode = new Node;
				newNode->data = _data;

				if (flag_ft == 1)
				{
					flag_ft = 0;
					temp->data.setHead(newNode);
					newNode->next = nullptr;
					prevNode = newNode;
				}
				else
				{
					newNode->next = nullptr;
					prevNode->next = newNode;
					prevNode = newNode;
				}
			}
			temp->data.setTail(prevNode);
			temp = temp->next;
		}
	}

	if (stackFile.peek() == EOF)
	{
		headStack = nullptr;
		tailStack = nullptr;
	}
	else
	{
		string line; int cnt = 0;

		while (getline(stackFile, line)) cnt++;

		stackContainer* prevNodeStack = nullptr;

		for (int i = 0; i < cnt; i++)
		{
			stackContainer* newNodeStack = new stackContainer;
			stack* newNode = new stack;
			newNodeStack->data = *newNode;

			if (i == 0)
			{
				headStack = newNodeStack;
				newNodeStack->next = nullptr;
				prevNodeStack = newNodeStack;
			}
			else
			{
				newNodeStack->next = nullptr;
				prevNodeStack->next = newNodeStack;
				prevNodeStack = newNodeStack;
			}
		}
		tailStack = prevNodeStack;

		line.clear(); stackFile.close(); fstream stackFile("stack.txt");

		stackContainer* temp = headStack; Node* prevNode = nullptr; int _data = 0;

		for (int i = 0; i < cnt; i++)
		{
			int flag_ft = 1;

			getline(stackFile, line); stringstream ss(line);

			while (ss >> _data)
			{
				Node* newNode = new Node;
				newNode->data = _data;

				if (flag_ft == 1)
				{
					flag_ft = 0;
					temp->data.setHead(newNode);
					newNode->next = nullptr;
					prevNode = newNode;
				}
				else
				{
					newNode->next = nullptr;
					prevNode->next = newNode;
					prevNode = newNode;
				}
			}
			temp->data.setTail(prevNode);
			temp = temp->next;
		}
	}

	if (listFile.peek() == EOF)
	{
		headList = nullptr;
		tailList = nullptr;
	}
	else
	{
		string line; int cnt = 0;

		while (getline(listFile, line)) cnt++;

		listContainer* prevNodeList = nullptr;

		for (int i = 0; i < cnt; i++)
		{
			listContainer* newNodeList = new listContainer;
			list* newNode = new list;
			newNodeList->data = *newNode;

			if (i == 0)
			{
				headList = newNodeList;
				newNodeList->next = nullptr;
				prevNodeList = newNodeList;
			}
			else
			{
				newNodeList->next = nullptr;
				prevNodeList->next = newNodeList;
				prevNodeList = newNodeList;
			}
		}
		tailList = prevNodeList;

		line.clear(); listFile.close(); fstream listFile("list.txt");

		listContainer* temp = headList; Node* prevNode = nullptr; int _data = 0;

		for (int i = 0; i < cnt; i++)
		{
			int flag_ft = 1;

			getline(listFile, line); stringstream ss(line);

			while (ss >> _data)
			{
				Node* newNode = new Node;
				newNode->data = _data;

				if (flag_ft == 1)
				{
					flag_ft = 0;
					temp->data.setHead(newNode);
					newNode->next = nullptr;
					prevNode = newNode;
				}
				else
				{
					newNode->next = nullptr;
					prevNode->next = newNode;
					prevNode = newNode;
				}
			}
			temp->data.setTail(prevNode);
			temp = temp->next;
		}
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

void keeper::writeContainer(deckContainer* deckptr)
{
	fstream clear_file("deck.txt", ios::out);
	clear_file.close();

	fstream deckFile("deck.txt");

	if (!deckFile.is_open()) 
	{
		std::cerr << "Can't open file" << std::endl;
		return;
	}

	deckContainer* tempDeck = this->getHeadDeck();

	while (tempDeck != nullptr)
	{
		Node* tempNode = tempDeck->data.getHead();
		while (tempNode != nullptr)
		{
			deckFile << tempNode->data;
			if (tempNode != tempDeck->data.getTail()) deckFile << " ";
			tempNode = tempNode->next;
		}
		if (tempDeck != this->getTailDeck()) deckFile << "\n";
		tempDeck = tempDeck->next;
	}

	deckFile.close();
	cout << "Decks have succesfully written to the file" << endl << endl;
}

void keeper::writeContainer(stackContainer* stackptr)
{
	fstream clear_file("stack.txt", ios::out);
	clear_file.close();

	fstream stackFile("stack.txt");

	if (!stackFile.is_open())
	{
		std::cerr << "Can't open file" << std::endl;
		return;
	}

	stackContainer* tempStack = this->getHeadStack();

	while (tempStack != nullptr)
	{
		Node* tempNode = tempStack->data.getHead();
		while (tempNode != nullptr)
		{
			stackFile << tempNode->data;
			if (tempNode != tempStack->data.getTail()) stackFile << " ";
			tempNode = tempNode->next;
		}
		if (tempStack != this->getTailStack()) stackFile << "\n";
		tempStack = tempStack->next;
	}

	stackFile.close();
	cout << "Stacks have succesfully written to the file" << endl << endl;
}

void keeper::writeContainer(listContainer* listptr)
{
	fstream clear_file("list.txt", ios::out);
	clear_file.close();

	fstream listFile("list.txt");

	if (!listFile.is_open())
	{
		std::cerr << "Can't open file" << std::endl;
		return;
	}

	listContainer* tempList = this->getHeadList();

	while (tempList != nullptr)
	{
		Node* tempNode = tempList->data.getHead();
		while (tempNode != nullptr)
		{
			listFile << tempNode->data;
			if (tempNode != tempList->data.getTail()) listFile << " ";
			tempNode = tempNode->next;
		}
		if (tempList != this->getTailList()) listFile << "\n";
		tempList = tempList->next;
	}

	listFile.close();
	cout << "Lists have succesfully written to the file" << endl << endl;
}

void keeper::popList(listContainer* aim)
{
	listContainer* temp = getHeadList(); listContainer* tempPrev = temp;

	if (aim == nullptr) cout << "Select one of the lists from the container to pop" << endl << endl;

	else if (aim == temp && aim == getTailList())
	{
		delete(temp);
		setHeadList(nullptr); setTailList(nullptr);
		cout << "List has succesfully popped from the container" << endl << endl;
	}

	else if (aim == getHeadList())
	{
		listContainer* memFree = getHeadList();
		setHeadList(memFree->next);
		delete(memFree);
		cout << "List has succesfully popped from the container" << endl << endl;
	}

	else if (aim == getTailList())
	{
		temp = getHeadList(); tempPrev = temp; listContainer* tail = getTailList();
		while (temp != tail)
		{
			tempPrev = temp;
			temp = temp->next;
		}
		delete(temp);
		setTailList(tempPrev);
		tempPrev->next = nullptr;
		cout << "List has succesfully popped from the container" << endl << endl;
	}

	else
	{
		temp = getHeadList(); tempPrev = temp;
		while (temp != aim)
		{
			tempPrev = temp;
			temp = temp->next;
		}
		tempPrev->next = temp->next;
		delete(temp);
		cout << "List has succesfully popped from the container" << endl << endl;
	}
}

void keeper::popStack(stackContainer* aim)
{
	stackContainer* temp = getHeadStack(); stackContainer* tempPrev = temp;

	if (aim == nullptr) cout << "Select one of the stacks from the container to pop" << endl << endl;

	else if (aim == temp && aim == getTailStack())
	{
		delete(temp);
		setHeadStack(nullptr); setTailStack(nullptr);
		cout << "Stack has succesfully popped from the container" << endl << endl;
	}

	else if (aim == getHeadStack())
	{
		stackContainer* memFree = getHeadStack();
		setHeadStack(memFree->next);
		delete(memFree);
		cout << "Stack has succesfully popped from the container" << endl << endl;
	}

	else if (aim == getTailStack())
	{
		temp = getHeadStack(); tempPrev = temp; stackContainer* tail = getTailStack();
		while (temp != tail)
		{
			tempPrev = temp;
			temp = temp->next;
		}
		delete(temp);
		setTailStack(tempPrev);
		tempPrev->next = nullptr;
		cout << "Stack has succesfully popped from the container" << endl << endl;
	}

	else
	{
		temp = getHeadStack(); tempPrev = temp;
		while (temp != aim)
		{
			tempPrev = temp;
			temp = temp->next;
		}
		tempPrev->next = temp->next;
		delete(temp);
		cout << "Stack has succesfully popped from the container" << endl << endl;
	}
}

void keeper::popDeck(deckContainer* aim)
{
	deckContainer* temp = getHeadDeck(); deckContainer* tempPrev = temp;

	if (aim == nullptr) cout << "Select one of the decks from the container to pop" << endl << endl;

	else if (aim == temp && aim == getTailDeck())
	{
		delete(temp);
		setHeadDeck(nullptr); setTailDeck(nullptr);
		cout << "Deck has succesfully popped from the container" << endl << endl;
	}

	else if (aim == getHeadDeck())
	{
		deckContainer* memFree = getHeadDeck();
		setHeadDeck(memFree->next);
		delete(memFree);
		cout << "Deck has succesfully popped from the container" << endl << endl;
	}

	else if (aim == getTailDeck())
	{
		temp = getHeadDeck(); tempPrev = temp; deckContainer* tail = getTailDeck();
		while (temp != tail)
		{
			tempPrev = temp;
			temp = temp->next;
		}
		delete(temp);
		setTailDeck(tempPrev);
		tempPrev->next = nullptr;
		cout << "Deck has succesfully popped from the container" << endl << endl;
	}

	else
	{
		temp = getHeadDeck(); tempPrev = temp;
		while (temp != aim)
		{
			tempPrev = temp;
			temp = temp->next;
		}
		tempPrev->next = temp->next;
		delete(temp);
		cout << "Deck has succesfully popped from the container" << endl << endl;
	}
}