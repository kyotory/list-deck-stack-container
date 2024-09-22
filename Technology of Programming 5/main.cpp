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
    cout << "1 - Select deck\n\n" << endl;
    cout << "2 - Create new deck\n\n" << endl;
    cout << "3 - Push front element\n\n" << endl;
    cout << "4 - Pop front element\n\n" << endl;
    cout << "5 - Push back element\n\n" << endl;
    cout << "6 - Pop back element\n\n" << endl;
    cout << "7 - Save deck\n\n" << endl;
    cout << "8 - Print all decks\n\n" << endl;
    cout << "9 - Back to the main menu\n" << endl;
}

void mainMenuList()
{
    cout << "Select action:\n\n" << endl;
    cout << "1 - Select list\n\n" << endl;
    cout << "2 - Create new list\n\n" << endl;
    cout << "3 - Push the element by index\n\n" << endl;
    cout << "4 - Pop the elemet by index\n\n" << endl;
    cout << "5 - Save list\n\n" << endl;
    cout << "6 - Print all lists\n\n" << endl;
    cout << "7 - Back to the main menu\n" << endl;
}

void mainMenuStack()
{
    cout << "Select action:\n\n" << endl;
    cout << "1 - Select stack\n\n" << endl;
    cout << "2 - Create new stack\n\n" << endl;
    cout << "3 - Push the element\n\n" << endl;
    cout << "4 - Pop the elemet\n\n" << endl;
    cout << "5 - Save stack\n\n" << endl;
    cout << "6 - Print all stacks\n\n" << endl;
    cout << "7 - Back to the main menu\n" << endl;
}

int main()
{
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
            while (actionDeckMenu != '9')
            {
                switch (actionDeckMenu)
                {
                case '1':
                {
                    actionDeckMenu = _getch();
                    system("cls");
                    mainMenuDeck();
                    break;
                }
                case '2':
                {
                    actionDeckMenu = _getch();
                    system("cls");
                    mainMenuDeck();
                    break;
                }
                case '3':
                {
                    actionDeckMenu = _getch();
                    system("cls");
                    mainMenuDeck();
                    break;
                }
                case '4':
                {
                    actionDeckMenu = _getch();
                    system("cls");
                    mainMenuDeck();
                    break;
                }
                case '5':
                {
                    actionDeckMenu = _getch();
                    system("cls");
                    mainMenuDeck();
                    break;
                }
                case '6':
                {
                    actionDeckMenu = _getch();
                    system("cls");
                    mainMenuDeck();
                    break;
                }
                case '7':
                {
                    actionDeckMenu = _getch();
                    system("cls");
                    mainMenuDeck();
                    break;
                }
                case '8':
                {
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
            while (actionListMenu != '7')
            {
                switch (actionListMenu)
                {
                case '1':
                {
                    actionListMenu = _getch();
                    system("cls");
                    mainMenuList();
                    break;
                }
                case '2':
                {
                    actionListMenu = _getch();
                    system("cls");
                    mainMenuList();
                    break;
                }
                case '3':
                {
                    actionListMenu = _getch();
                    system("cls");
                    mainMenuList();
                    break;
                }
                case '4':
                {
                    actionListMenu = _getch();
                    system("cls");
                    mainMenuList();
                    break;
                }
                case '5':
                {
                    actionListMenu = _getch();
                    system("cls");
                    mainMenuList();
                    break;
                }
                case '6':
                {
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
            while (actionStackMenu != '7')
            {
                switch (actionStackMenu)
                {
                case '1':
                {
                    actionStackMenu = _getch();
                    system("cls");
                    mainMenuStack();
                    break;
                }
                case '2':
                {
                    actionStackMenu = _getch();
                    system("cls");
                    mainMenuStack();
                    break;
                }
                case '3':
                {
                    actionStackMenu = _getch();
                    system("cls");
                    mainMenuStack();
                    break;
                }
                case '4':
                {
                    actionStackMenu = _getch();
                    system("cls");
                    mainMenuStack();
                    break;
                }
                case '5':
                {
                    actionStackMenu = _getch();
                    system("cls");
                    mainMenuStack();
                    break;
                }
                case '6':
                {
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