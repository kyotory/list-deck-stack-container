#include <iostream>
#include <conio.h>
#include "keeper.h"

using namespace std;

void mainMenu()
{
    cout << "Select section:\n\n" << endl;
    cout << "1 - Deck section\n\n" << endl;
    cout << "2 - List section\n\n" << endl;
    cout << "3 - Stack section\n\n" << endl;
    cout << "4 - Exit program\n\n" << endl;
}

void mainMenuDeck()
{
    cout << "Select action:\n\n" << endl;
    cout << "1 - Select the deck\n\n" << endl;
    cout << "2 - Create new deck\n\n" << endl;
    cout << "3 - Push front element\n\n" << endl;
    cout << "4 - Pop front element\n\n" << endl;
    cout << "5 - Push back element\n\n" << endl;
    cout << "6 - Pop back element\n\n" << endl;
    cout << "7 - Save the decks\n\n" << endl;
    cout << "8 - Print all decks\n\n" << endl;
    cout << "9 - Delete the deck from the container\n\n" << endl;
    cout << "0 - Back to the main menu\n" << endl;
}

void mainMenuList()
{
    cout << "Select action:\n\n" << endl;
    cout << "1 - Select the list\n\n" << endl;
    cout << "2 - Create new list\n\n" << endl;
    cout << "3 - Push the element by index\n\n" << endl;
    cout << "4 - Pop the element by index\n\n" << endl;
    cout << "5 - Save the lists\n\n" << endl;
    cout << "6 - Print all lists\n\n" << endl;
    cout << "7 - Delete the list from the container\n\n" << endl;
    cout << "8 - Back to the main menu\n" << endl;
}

void mainMenuStack()
{
    cout << "Select action:\n\n" << endl;
    cout << "1 - Select the stack\n\n" << endl;
    cout << "2 - Create new stack\n\n" << endl;
    cout << "3 - Push the element\n\n" << endl;
    cout << "4 - Pop the element\n\n" << endl;
    cout << "5 - Save the stacks\n\n" << endl;
    cout << "6 - Print all stacks\n\n" << endl;
    cout << "7 - Delete the stack from the container\n\n" << endl;
    cout << "8 - Back to the main menu\n" << endl;
}

int main()
{
    keeper container; deckContainer* deckptr = nullptr; stackContainer* stackptr = nullptr; listContainer* listptr = nullptr;

    mainMenu();

    char actionMainMenu = _getch();

    while (actionMainMenu != '4')
    {
        switch (actionMainMenu)
        {
        case '1':
        {
            system("cls");
            mainMenuDeck();
            char actionDeckMenu = _getch();
            while (actionDeckMenu != '0')
            {
                switch (actionDeckMenu)
                {
                case '1':
                {
                    system("cls");
                    if (container.getHeadDeck() == nullptr) 
                    {
                        cout << "There are no decks in the container\n\nTry to create new deck\n\n";
                    }
                    else
                    {
                        int number = 0; deckContainer* temp = container.getHeadDeck();
                        while (temp != nullptr)
                        {
                            cout << "Deck #" << number << " -> ";
                            temp->data.printData();
                            number++;
                            temp = temp->next;
                            cout << "\n\n";
                        }
                        cout << "What deck do you want to choose?\n\n";
                        int index = 0;
                        cin >> index;
                        if (index >= number)
                        {
                            cout << "\nWrite a correct index to choose a deck\n\n";
                        }
                        else
                        {
                            deckptr = container.selectElemDeck(index);
                            cout << "\nYou have chosen a deck #" << index << "\n\n";
                        }
                    }
                    actionDeckMenu = _getch();
                    system("cls");
                    mainMenuDeck();
                    break;
                }
                case '2':
                {
                    system("cls");
                    deck* newNode = new deck;
                    container.push(*newNode);
                    deckptr = container.selectElemDeck(0);
                    cout << "New deck has completely created";
                    actionDeckMenu = _getch();
                    system("cls");
                    mainMenuDeck();
                    break;
                }
                case '3':
                {
                    system("cls");
                    if (deckptr == nullptr)
                    {
                        cout << "You should choose a deck to push a front element to the deck" << endl << endl;
                    }
                    else
                    {
                        int temp;
                        cout << "Write an amount of the element" << endl << endl;
                        cin >> temp;
                        deckptr->data.pushFront(temp);
                        cout << "\nElement has succesfully pushed to the front of the deck" << endl << endl;
                    }
                    actionDeckMenu = _getch();
                    system("cls");
                    mainMenuDeck();
                    break;
                }
                case '4':
                {
                    system("cls");
                    if (deckptr == nullptr)
                    {
                        cout << "You should choose a deck to pop a front element from the deck" << endl << endl;
                    }
                    else
                    {
                        deckptr->data.popFront();
                    }
                    actionDeckMenu = _getch();
                    system("cls");
                    mainMenuDeck();
                    break;
                }
                case '5':
                {
                    system("cls");
                    if (deckptr == nullptr)
                    {
                        cout << "You should choose a deck to push a back element to the deck" << endl << endl;
                    }
                    else
                    {
                        int temp;
                        cout << "Write an amount of the element" << endl << endl;
                        cin >> temp;
                        deckptr->data.pushBack(temp);
                        cout << "\nElement has succesfully pushed to the back of the deck" << endl << endl;
                    }
                    actionDeckMenu = _getch();
                    system("cls");
                    mainMenuDeck();
                    break;
                }
                case '6':
                {
                    system("cls");
                    if (deckptr == nullptr)
                    {
                        cout << "You should choose a deck to pop a back element from the deck" << endl << endl;
                    }
                    else
                    {
                        deckptr->data.popBack();
                    }
                    actionDeckMenu = _getch();
                    system("cls");
                    mainMenuDeck();
                    break;
                }
                case '7':
                {
                    system("cls");
                    container.writeContainer(deckptr);
                    actionDeckMenu = _getch();
                    system("cls");
                    mainMenuDeck();
                    break;
                }
                case '8':
                {
                    system("cls");
                    if (container.getHeadDeck() == nullptr)
                    {
                        cout << "There are no decks in the container\n\nTry to create new deck\n\n";
                    }
                    else
                    {
                        cout << "All decks that you have in the container:\n\n";
                        int number = 0; deckContainer* temp = container.getHeadDeck();
                        while (temp != nullptr)
                        {
                            cout << "Deck #" << number << " -> ";
                            temp->data.printData();
                            number++;
                            temp = temp->next;
                            cout << "\n\n";
                        }
                    }
                    actionDeckMenu = _getch();
                    system("cls");
                    mainMenuDeck();
                    break;
                }
                case '9':
                {
                    system("cls");
                    container.popDeck(deckptr);
                    actionDeckMenu = _getch();
                    system("cls");
                    mainMenuDeck();
                    break;
                }
                default:
                {
                    system("cls");
                    cout << "Unknown command\n\n" << endl;
                    actionDeckMenu = _getch();
                    system("cls");
                    mainMenuDeck();
                    break;
                }
                }
                actionDeckMenu = _getch();
            }
            system("cls");
            mainMenu();
            break;
        }
        case '2':
        {
            system("cls");
            mainMenuList();
            char actionListMenu = _getch();
            while (actionListMenu != '8')
            {
                switch (actionListMenu)
                {
                case '1':
                {
                    system("cls");
                    if (container.getHeadList() == nullptr)
                    {
                        cout << "There are no lists in the container\n\nTry to create new list\n\n";
                    }
                    else
                    {
                        int number = 0; listContainer* temp = container.getHeadList();
                        while (temp != nullptr)
                        {
                            cout << "List #" << number << " -> ";
                            temp->data.printData();
                            number++;
                            temp = temp->next;
                            cout << "\n\n";
                        }
                        cout << "What list do you want to choose?\n\n";
                        int index = 0;
                        cin >> index;
                        if (index >= number)
                        {
                            cout << "\nWrite a correct index to choose a list\n\n";
                        }
                        else
                        {
                            listptr = container.selectElemList(index);
                            cout << "\nYou have chosen a list #" << index << "\n\n";
                        }
                    }
                    actionListMenu = _getch();
                    system("cls");
                    mainMenuList();
                    break;
                }
                case '2':
                {
                    system("cls");
                    list* newNode = new list;
                    container.push(*newNode);
                    listptr = container.selectElemList(0);
                    cout << "New list has completely created";
                    actionListMenu = _getch();
                    system("cls");
                    mainMenuList();
                    break;
                }
                case '3':
                {
                    system("cls");
                    if (listptr == nullptr)
                    {
                        cout << "You should choose a list to push an element" << endl << endl;
                    }
                    else
                    {
                        int temp; int _data;
                        cout << "Write an amount of the element" << endl << endl;
                        cin >> _data;
                        cout << "\nWrite an index of the element" << endl << endl;
                        cin >> temp;
                        listptr->data.push(_data, temp);
                        cout << "\nElement has succesfully pushed to the list" << endl << endl;
                    }
                    actionListMenu = _getch();
                    system("cls");
                    mainMenuList();
                    break;
                }
                case '4':
                {
                    system("cls");
                    if (listptr == nullptr)
                    {
                        cout << "You should choose a list to pop an element" << endl << endl;
                    }
                    else
                    {
                        cout << "Write an index of the element" << endl << endl; 
                        int temp;
                        cin >> temp;
                        listptr->data.pop(temp);
                    }
                    actionListMenu = _getch();
                    system("cls");
                    mainMenuList();
                    break;
                }
                case '5':
                {
                    system("cls");
                    container.writeContainer(listptr);
                    actionListMenu = _getch();
                    system("cls");
                    mainMenuList();
                    break;
                }
                case '6':
                {
                    system("cls");
                    if (container.getHeadList() == nullptr)
                    {
                        cout << "There are no lists in the container\n\nTry to create new list\n\n";
                    }
                    else
                    {
                        cout << "All lists that you have in the container:\n\n";
                        int number = 0; listContainer* temp = container.getHeadList();
                        while (temp != nullptr)
                        {
                            cout << "List #" << number << " -> ";
                            temp->data.printData();
                            number++;
                            temp = temp->next;
                            cout << "\n\n";
                        }
                    }
                    actionListMenu = _getch();
                    system("cls");
                    mainMenuList();
                    break;
                }
                case '7':
                {
                    system("cls");
                    container.popList(listptr);
                    actionListMenu = _getch();
                    system("cls");
                    mainMenuList();
                    break;
                }
                default:
                {
                    system("cls");
                    cout << "Unknown command\n\n" << endl;
                    actionListMenu = _getch();
                    system("cls");
                    mainMenuList();
                    break;
                }
                }
                actionListMenu = _getch();
            }
            system("cls");
            mainMenu();
            break;
        }
        case '3':
        {
            system("cls");
            mainMenuStack();
            char actionStackMenu = _getch();
            while (actionStackMenu != '8')
            {
                switch (actionStackMenu)
                {
                case '1':
                {
                    system("cls");
                    if (container.getHeadStack() == nullptr)
                    {
                        cout << "There are no stacks in the container\n\nTry to create new stack\n\n";
                    }
                    else
                    {
                        int number = 0; stackContainer* temp = container.getHeadStack();
                        while (temp != nullptr)
                        {
                            cout << "Stack #" << number << " -> ";
                            temp->data.printData();
                            number++;
                            temp = temp->next;
                            cout << "\n\n";
                        }
                        cout << "What stack do you want to choose?\n\n";
                        int index = 0;
                        cin >> index;
                        if (index >= number)
                        {
                            cout << "\nWrite a correct index to choose a stack\n\n";
                        }
                        else
                        {
                            stackptr = container.selectElemStack(index);
                            cout << "\nYou have chosen a stack #" << index << "\n\n";
                        }
                    }
                    actionStackMenu = _getch();
                    system("cls");
                    mainMenuStack();
                    break;
                }
                case '2':
                {
                    system("cls");
                    stack* newNode = new stack;
                    container.push(*newNode);
                    stackptr = container.selectElemStack(0);
                    cout << "New stack has completely created";
                    actionStackMenu = _getch();
                    system("cls");
                    mainMenuStack();
                    break;
                }
                case '3':
                {
                    system("cls");
                    if (stackptr == nullptr)
                    {
                        cout << "You should choose a stack to push an element" << endl << endl;
                    }
                    else
                    {
                        int temp;
                        cout << "Write an amount of the element" << endl << endl;
                        cin >> temp;
                        stackptr->data.push(temp);
                        cout << "\nElement has succesfully pushed to the stack" << endl << endl;
                    }
                    actionStackMenu = _getch();
                    system("cls");
                    mainMenuStack();
                    break;
                }
                case '4':
                {
                    system("cls");
                    if (stackptr == nullptr)
                    {
                        cout << "You should choose a stack to pop an element" << endl << endl;
                    }
                    else
                    {
                        stackptr->data.pop();
                    }
                    actionStackMenu = _getch();
                    system("cls");
                    mainMenuStack();
                    break;
                }
                case '5':
                {
                    system("cls");
                    container.writeContainer(stackptr);
                    actionStackMenu = _getch();
                    system("cls");
                    mainMenuStack();
                    break;
                }
                case '6':
                {
                    system("cls");
                    if (container.getHeadStack() == nullptr)
                    {
                        cout << "There are no stacks in the container\n\nTry to create new stack\n\n";
                    }
                    else
                    {
                        cout << "All stacks that you have in the container:\n\n";
                        int number = 0; stackContainer* temp = container.getHeadStack();
                        while (temp != nullptr)
                        {
                            cout << "Stack #" << number << " -> ";
                            temp->data.printData();
                            number++;
                            temp = temp->next;
                            cout << "\n\n";
                        }
                    }
                    actionStackMenu = _getch();
                    system("cls");
                    mainMenuStack();
                    break;
                }
                case '7':
                {
                    system("cls");
                    container.popStack(stackptr);
                    actionStackMenu = _getch();
                    system("cls");
                    mainMenuStack();
                    break;
                }
                default:
                {
                    system("cls");
                    cout << "Unknown command\n\n" << endl;
                    actionStackMenu = _getch();
                    system("cls");
                    mainMenuStack();
                    break;
                }
                }
                actionStackMenu = _getch();
            }
            system("cls");
            mainMenu();
            break;
        }
        default:
        {
            system("cls");
            cout << "Unknown command\n\n" << endl;
            actionMainMenu = _getch();
            system("cls");
            mainMenuStack();
            break;
        }
        }
        actionMainMenu = _getch();
    }
	return 0;
}