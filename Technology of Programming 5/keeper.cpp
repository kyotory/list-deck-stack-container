#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "keeper.h"

using namespace std;

keeper::keeper()
{
    head = nullptr;
    tail = nullptr;
}

keeper::keeper(fstream& fileDatabase)
{
    if (fileDatabase.peek() == EOF)
    {
        head = nullptr;
        tail = nullptr;
    }
    else
    {
        head = nullptr;
        tail = nullptr;

        string line;
        int cnt = 0;
        int _data = 0;

        while (getline(fileDatabase, line))
        {
            container* newContainer = new container;
            stringstream ss(line);
            char containerType;
            int flag_ft = 1;

            ss >> containerType;

            if (cnt == 0)
            {
                head = tail = newContainer;
                newContainer->next = nullptr;
            }
            else
            {
                newContainer->next = nullptr;
                tail->next = newContainer;
                tail = newContainer;
            }

            if (containerType == 'd')
            {
                deck* newDeck = new deck;
                newContainer->data = newDeck;
                while (ss >> _data)
                {
                    Node* newNode = new Node;
                    newNode->data = _data;

                    if (flag_ft == 1)
                    {
                        flag_ft = 0;
                        newDeck->setHead(newNode);
                        newDeck->setTail(newNode);
                        newNode->next = nullptr;
                    }
                    else
                    {
                        newNode->next = nullptr;
                        newDeck->getTail()->next = newNode;
                        newDeck->setTail(newNode);
                    }
                }
            }
            else if (containerType == 's')
            {
                stack* newStack = new stack;
                newContainer->data = newStack;
                while (ss >> _data)
                {
                    Node* newNode = new Node;
                    newNode->data = _data;

                    if (flag_ft == 1)
                    {
                        flag_ft = 0;
                        newStack->setHead(newNode);
                        newStack->setTail(newNode);
                        newNode->next = nullptr;
                    }
                    else
                    {
                        newNode->next = nullptr;
                        newStack->getTail()->next = newNode;
                        newStack->setTail(newNode);
                    }
                }
            }
            else if (containerType == 'l')
            {
                list* newList = new list;
                newContainer->data = newList;
                while (ss >> _data)
                {
                    Node* newNode = new Node;
                    newNode->data = _data;

                    if (flag_ft == 1)
                    {
                        flag_ft = 0;
                        newList->setHead(newNode);
                        newList->setTail(newNode);
                        newNode->next = nullptr;
                    }
                    else
                    {
                        newNode->next = nullptr;
                        newList->getTail()->next = newNode;
                        newList->setTail(newNode);
                    }
                }
            }
            cnt++;
        }
    }
}

keeper::~keeper()
{
    container* temp = getHead();

    while (temp != nullptr)
    {
        container* nextTempDeck = temp->next;
        delete temp;
        temp = nextTempDeck;
    }

    setTail(nullptr);
    setHead(nullptr);
}

void keeper::operator+(queue* data)
{
    container* newNode = new container;
    newNode->data = data;

    if (getTail() == nullptr) {
        setTail(newNode);
        setHead(newNode);
        newNode->next = nullptr;
        return;
    }

    newNode->next = getHead();
    setHead(newNode);
}

container* keeper::getHead()
{
    return head;
}

container* keeper::getTail()
{
    return tail;
}

void keeper::setHead(container* newHead)
{
    head = newHead;
}

void keeper::setTail(container* newTail)
{
    tail = newTail;
}

container* keeper::selectElem(int index)
{
    container* temp = getHead();
    for (int i = 0; i < index; i++) temp = temp->next;
    return temp;
}

void keeper::writeContainer()
{
    fstream clear_file("database.txt", ios::out);
    clear_file.close();

    fstream fileDatabase("database.txt");

    if (!fileDatabase.is_open())
    {
        cerr << "Can't open file" << endl;
        return;
    }

    container* temp = this->getHead();

    while (temp != nullptr) {
        temp->data->writeToFile(fileDatabase);
        temp = temp->next;
    }

    fileDatabase.close();
    cout << "Container have succesfully written to the file" << endl << endl;
}

void keeper::operator-(container* aim)
{
    container* temp = getHead(); container* tempPrev = temp;

    if (aim == nullptr) cout << "Select one of the element from the container to pop" << endl << endl;

    else if (aim == temp && aim == getTail())
    {
        delete(temp);
        setHead(nullptr); setTail(nullptr);
        cout << "Element has succesfully popped from the container" << endl << endl;
    }
    else if (aim == getHead())
    {
        container* memFree = getHead();
        setHead(memFree->next);
        delete(memFree);
        cout << "Element has succesfully popped from the container" << endl << endl;
    }
    else if (aim == getTail())
    {
        temp = getHead(); tempPrev = temp; container* tail = getTail();
        while (temp != tail)
        {
            tempPrev = temp;
            temp = temp->next;
        }
        delete(temp);
        setTail(tempPrev);
        tempPrev->next = nullptr;
        cout << "Element has succesfully popped from the container" << endl << endl;
    }
    else
    {
        temp = getHead(); tempPrev = temp;
        while (temp != aim)
        {
            tempPrev = temp;
            temp = temp->next;
        }
        tempPrev->next = temp->next;
        delete(temp);
        cout << "Element has succesfully popped from the container" << endl << endl;
    }
}

void keeper::printContainer()
{
    int cnt = 0;
    container* temp = head;
    while (temp != nullptr)
    {
        cout << "#" << cnt << " ";
        temp->data->printData();
        temp = temp->next;
        cnt++;
    }
}