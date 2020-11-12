/**
* @author ismaildemircan --> e-mail: ismaildemircann98@gmail.com
* @date 23 Kasým 2019 Pazar
* @brief This program is a tab structure built on a stack structure.
* It includes the functions of adding or removing
* new tabs to the program, retrieving the tab through the created recycle bin
* and finding the order in which the tab is located.
*/
#include <iostream>
#include <conio.h>
#include <Windows.h>
#include "Stack.h"
#include "Tabs.h"
using namespace std;
Tabs::Tabs()
{
}
Tabs::~Tabs()
{
}
Stacks N;
Stacks S;
/**
* @brief : This function opens the menu and leads to the desired function.
* @see main() : Review what function is called.
*/
void Tabs::Menu()
{
	cout << "Website aplication is opening please wait a moment";
	Sleep(2000);
	char choose;
	do
	{
		system("cls");
		cout << "\n\n\n\t\t---------------------Website Tab---------------------";
		cout << "\n\t\t [A] - Add New Tab";
		cout << "\n\t\t [D] - Delete Last Tab";
		cout << "\n\t\t [T] - Total Number of Tabs Open";
		cout << "\n\t\t [L] - Print Tabs List\n";
		cout << "\n\t\t [S] - Search Website Number's Position in The Tabs\n";
		cout << "\n\t\t [H] - Deletion History Tabs List";
		cout << "\n\t\t [M] - Size of Deletion History";
		cout << "\n\t\t [U] - Undo Website Number";
		cout << "\n\t\t [P] - Permanently Delete in Last Tab in History\n";
		cout << "\n\t\t [E] - Exit";
		cout << "\t\t\n\n\nChoose operation: ";
		choose = _getch();
		system("cls");
		if (choose == 'A' || choose == 'a')
		{
			Add();
			system("pause");
		}
		if (choose == 'D' || choose == 'd')
		{
			Delete();
			system("pause");
		}
		if (choose == 'T' || choose == 't')
		{
			Dimension();
			system("pause");
		}
		if (choose == 'L' || choose == 'l')
		{
			Print();
			system("pause");
		}
		if (choose == 'H' || choose == 'h')
		{
			History();
			system("pause");
		}
		if (choose == 'P' || choose == 'p')
		{
			DHistory();
			system("pause");
		}
		if (choose == 'S' || choose == 's')
		{
			Look();
			system("pause");
		}
		if (choose == 'M' || choose == 'm')
		{
			DSize();
			system("pause");
		}
		if (choose == 'U' || choose == 'u')
		{
			Back();
			system("pause");
		}
		if (choose == 'E' || choose == 'e')
		{
			exit(0);
		}
	} while (choose != 'E' || choose != 'e');
}
/**
* @brief : This function calls the push function in stack header.
* @see main() : Review what function is called.
*/
void Tabs::Add()
{
	int i;
	cout << "Enter website number to add new tab: ";
	cin >> i;
	N.Push(i);
}
/**
* @brief : This function calls the pop function in stack header.
* @see main() : Review what function is called.
*/
void Tabs::Delete()
{
	if (N.IsEmpty())
		cout << "There are no tabs open." << endl;
	else
	{
		int a = N.Pop();
		cout << "Deleted tab number is: " << a << endl;
		S.Push(a);
	}
}
/**
* @brief : This function calls the count function in stack header.
* @see main() : Review what function is called.
*/
void Tabs::Dimension()
{
	cout << "Total number of tabs open: " << N.Count() << endl;
}
/**
* @brief : This function calls the list function in stack header.
* @see main() : Review what function is called.
*/
void Tabs::Print()const
{
	if (N.IsEmpty())
		cout << "There are no tabs open." << endl;
	else
	{
		cout << "Tab numbers that are open" << endl;
		N.List();
	}
	cout << endl << endl;
}
/**
* @brief : This function calls the search function in stack header.
* @see main() : Review what function is called.
*/
void Tabs::Look()
{
	if (N.IsEmpty())
		cout << "There are no tabs open." << endl << endl;
	else
	{
		int i, a = 0;
		cout << "Enter search website number: ";
		cin >> i;
		a = N.Search(i);
		if (a != -1)
		{
			cout << "Your search tab position is: " << a << endl << endl;
		}
		else
		{
			system("cls");
			Look();
		}
	}
}
/**
* @brief : This function calls the undo function in stack header.
* @see main() : Review what function is called.
*/
void Tabs::Back()
{
	History();
	int k = S.Count();
	if (k != 0)
	{
		k = S.Undo(k);
		N.Push(k);
		S.Pop();
	}
	else
	{
		Menu();
	}
}
/**
* @brief : This function calls the push function in stack header.
* @see main() : Review what function is called.
*/
void Tabs::History()const
{
	if (S.IsEmpty())
		cout << "Deletion History is empty." << endl << endl;
	else
	{
		cout << "The website numbers deleted." << endl;
		S.List();

	}
	cout << endl << endl;
}
/**
* @brief : This function calls the pop function in stack header.
* @see main() : Review what function is called.
*/
void Tabs::DHistory()
{
	if (S.IsEmpty())
		cout << "Deletion history is empty." << endl << endl;
	else
	{
		cout << "Permanently deleted tab number is: " << S.Pop() << endl << endl;
	}
}
/**
* @brief : This function calls the count function in stack header.
* @see main() : Review what function is called.
*/
void Tabs::DSize()
{
	cout << "Total Numbers of Deletion History: " << S.Count() << endl;
}