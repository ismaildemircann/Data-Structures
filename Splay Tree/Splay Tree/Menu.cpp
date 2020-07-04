/**
* @author ismaildemircan --> e-mail: ismaildemircann98@gmail.com
* @date 9 December 2019 Sunday
* @brief This program is a tes system prepared using splay tree.
*/
#include "Menu.h"
#include "SplayTree.h"
#include <iostream>
#include <conio.h>
using namespace std;
Menu::Menu()
{
}
Menu::~Menu()
{
}
/**
* @brief : This function opens the menu and leads to the desired function.
* @see main() : Review what function is called.
*/
void Menu::MENU()
{
	Node *root;
	root = NULL;
	char choose;
	do
	{
		system("cls");
		cout << "\n\t\t [A] - Add";
		cout << "\n\t\t [D] - Delete";
		cout << "\n\t\t [P] - Print Preorder";
		cout << "\n\t\t [S] - Search";
		cout << "\n\t\t [E] - Exit";
		cout << "\t\t\n\n\nChoose Operation: ";
		choose = _getch();
		system("cls");
		if (choose == 'A' || choose == 'a')
		{
			root = Insert(root);
			cout << endl << endl;
			system("pause");
		}
		if (choose == 'D' || choose == 'd')
		{
			root = Delete(root);
			cout << endl << endl;
			system("pause");
		}
		if (choose == 'P' || choose == 'p')
		{
			root = PreOrder(root);
			cout << endl << endl;
			system("pause");
		}
		if (choose == 'S' || choose == 's')
		{
			root = Search(root);
			cout << endl << endl;
			system("pause");
		}
		if (choose == 'E' || choose == 'e')
		{
			exit(0);
		}
	} while (choose != 'E' || choose != 'e');
}
/**
* @brief : This function calls the insert function in SplayTree header.
* @param root : Tree's root.
* @see main() : Review what function is called.
*/
Node* Menu::Insert(Node * root)
{
	int k;
	cout << "Enter value to be inserted: ";
	cin >> k;
	if (k < -99999 || k > 99999 || cin.fail())
	{
		system("cls");
		cin.clear();
		cin.ignore();
		MENU();
	}
	root = N.Insert(k, root);
	cout << endl << "Insert: " << k << endl;
	cout << "Then: " << endl;
	N.PreOrder(root);
	return root;
}
/**
* @brief : This function calls the Delete function in SplayTree header.
* @param root : Tree's root.
* @see main() : Review what function is called.
*/
Node* Menu::Delete(Node *root)
{
	int k;
	cout << "Enter value to be deleted: ";
	cin >> k;
	if (k < -99999 || k > 99999 || cin.fail())
	{
		system("cls");
		cin.clear();
		cin.ignore();
		MENU();
	}
	root = N.Delete(k, root);
	cout << endl << "Delete: " << k << endl;
	cout << "Then: " << endl;
	N.PreOrder(root);
	return root;
}
/**
* @brief : This function calls the Search function in SplayTree header.
* @param root : Tree's root.
* @see main() : Review what function is called.
*/
Node* Menu::Search(Node*root)
{
	int k;
	cout << "Enter value to be searched: ";
	cin >> k;
	if (k < -99999 || k > 99999 || cin.fail())
	{
		system("cls");
		cin.clear();
		cin.ignore();
		MENU();
	}
	root = N.Search(k, root);
	cout << endl << "Search: " << k << endl;
	cout << "Then: " << endl;
	N.PreOrder(root);
	return root;
}
/**
* @brief : This function calls the preorder function in SplayTree header.
* @param root : Tree's root.
* @see main() : Review what function is called.
*/
Node* Menu::PreOrder(Node*root)
{
	cout << endl << "PreOrder: ";
	N.PreOrder(root);
	return root;
}
