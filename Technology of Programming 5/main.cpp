#include <iostream>
#include <conio.h>
#include "keeper.h"

using namespace std;

static void mainMenu()
{
	cout << "Select section:\n\n" << endl;
	cout << "1 - Print all elements of the container\n\n" << endl;
	cout << "2 - Select the element from the container\n\n" << endl;
	cout << "3 - Create new element\n\n" << endl;
	cout << "4 - Save the container to the file\n\n" << endl;
	cout << "5 - Delete the element from the container\n\n" << endl;
	cout << "6 - Exit\n" << endl;
}

static void structureMenu()
{
	cout << "Actions with the deck:\n\n" << endl;
	cout << "1 - Push the element\n\n" << endl;
	cout << "2 - Pop the element\n\n" << endl;
	cout << "3 - Print the structure\n\n" << endl;
	cout << "4 - Back to the main menu\n" << endl;
}

int main()
{
	mainMenu();

	fstream databaseFile("database.txt");

	keeper cont(databaseFile); container* ptr = nullptr;

	databaseFile.close();

	char actionMainMenu = _getch();

	while (actionMainMenu != '6')
	{
		switch (actionMainMenu)
		{
		case '1':
		{
			system("cls");
			if (cont.getHead() == nullptr) cout << "Container is empty, try to create new element\n\n";
			else cont.printContainer();
			char actionMainMenu = _getch();
			system("cls");
			mainMenu();
			break;
		}
		case '2':
		{
			system("cls");
			if (cont.getHead() == nullptr) cout << "Container is empty, try to create new element\n\n";
			else
			{
				cont.printContainer();
				cout << "Write an index of element that you want to select: ";
				int index;
				cin >> index;
				container* temp = cont.getHead(); int cnt = 0;

				while (temp != nullptr)
				{
					cnt++;
					temp = temp->next;
				}
				temp = cont.getHead();

				if (temp == nullptr) cout << "Container is empty, nothing to select\n\n";

				else if (index < 0 || index > cnt) cout << "Incorrect index\n\n";
				else ptr = cont.selectElem(index);

				if (ptr != nullptr)
				{
					system("cls");
					structureMenu();

					char actionStructureMenu = _getch();

					while (actionStructureMenu != '4')
					{
						switch (actionStructureMenu)
						{
						case '1':
						{
							system("cls");
							ptr->data->printData();
							cout << "Write an amount of the element: ";
							int temp;
							cin >> temp;
							ptr->data->push(temp);
							ptr->data->printData();
							cout << endl;
							char actionStackMenu = _getch();
							system("cls");
							structureMenu();
							break;
						}
						case '2':
						{
							system("cls");
							ptr->data->printData();
							ptr->data->pop();
							ptr->data->printData();
							cout << endl;
							char actionStackMenu = _getch();
							system("cls");
							structureMenu();
							break;
						}
						case '3':
						{
							system("cls");
							ptr->data->printData();
							char actionStackMenu = _getch();
							system("cls");
							structureMenu();
							break;
						}
						default:
						{
							system("cls");
							cout << "Unknown command\n\n" << endl;
							actionStructureMenu = _getch();
							system("cls");
							structureMenu();
							break;
						}
						}
						actionStructureMenu = _getch();
					}
				}
				ptr = nullptr;
			}
			char actionMainMenu = _getch();
			system("cls");
			mainMenu();
			break;
		}
		case '3':
		{
			system("cls");
			cout << "1 - Deck\n\n2 - Stack\n\n3 - List\n\nSelect the type of a structure: ";
			int choice;
			cin >> choice;
			if (choice == 1)
			{
				deck* newDeck = new deck;
				cont.operator+(newDeck);
				cout << endl << "Deck has created succesfully";
			}
			else if (choice == 2)
			{
				stack* newStack = new stack;
				cont.operator+(newStack);
				cout << endl << "Stack has created succesfully";
			}
			else if (choice == 3)
			{
				list* newList = new list;
				cont.operator+(newList);
				cout << endl << "List has created succesfully";
			}
			else cout << endl << "Incorrect index";
			char actionMainMenu = _getch();
			system("cls");
			mainMenu();
			break;
		}
		case '4':
		{
			system("cls");
			cont.writeContainer();
			char actionMainMenu = _getch();
			system("cls");
			mainMenu();
			break;
		}
		case '5':
		{
			system("cls");
			if (cont.getHead() == nullptr) cout << "Container is empty, try to create new element\n\n";
			else
			{
				cont.printContainer();
				cout << "Select the index of the element that you want to delete: ";

				int index;
				cin >> index;
				container* temp = cont.getHead(); int cnt = 0;

				while (cnt != index)
				{
					temp = temp->next;
					cnt++;
				}

				ptr = temp;
				cout << "\nYou are now deleting this element: ";
				ptr->data->printData();
				cout << "Y/N? ";
				char choice;
				cin >> choice;
				cout << endl;
				if (choice == 'Y' || choice == 'y') cont.operator-(ptr);
				else cout << endl << "Deleting was not succesfull" << endl << endl;
			}
			char actionMainMenu = _getch();
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
			mainMenu();
			break;
		}
		}
		actionMainMenu = _getch();
	}
	return 0;
}