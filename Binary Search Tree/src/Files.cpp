/**
* @author ismaildemircan --> e-mail: ismaildemircann98@gmail.com
* @date 1 December 2019 Sunday
* @brief This program is a file system prepared using binary search tree.
*/
#include <iostream>
#include <conio.h>
#include "BST.h"
#include "Files.h"
using namespace std;
Files::Files()
{
}
Files::~Files()
{
}
BST N;
Node *_root = NULL;
/**
* @brief : This function opens the menu and leads to the desired function.
* @see main() : Review what function is called.
*/
void Files::Menu()
{
	char choose;
	do
	{
		system("cls");
		cout << "\n\t\t [A] - Add File";
		cout << "\n\t\t [X] - Delete First File of The Same Name.";
		cout << "\n\t\t [W] - Delete Last File of The Same Name.";
		cout << "\n\t\t [Q] - Delete All Files of The Same Name.";
		cout << "\n\t\t [P] - Print Files Preorder, Inorder, Postorder";
		cout << "\n\t\t [C] - Count Files";
		cout << "\n\t\t [S] - Show Files in Binary Tree Structure";
		cout << "\n\t\t [H] - Height of Files";
		cout << "\n\t\t [B] - Is it Balance in file's order";
		cout << "\n\t\t [K] - Max-Min Files Number";
		cout << "\n\t\t [V] - Search File Number";
		cout << "\n\t\t [Y] - Do Balance to Tree";
		cout << "\n\t\t [E] - Exit";
		cout << "\t\t\n\n\nChoose Operation: ";
		choose = _getch();
		system("cls");
		if (choose == 'A' || choose == 'a')
		{
			Add();
			system("pause");
		}
		if (choose == 'X' || choose == 'x')
		{
			DeleteF();
			system("pause");
		}
		if (choose == 'W' || choose == 'w')
		{
			DeleteL();
			system("pause");
		}
		if (choose == 'Q' || choose == 'q')
		{
			DeleteA();
			system("pause");
		}
		if (choose == 'S' || choose == 's')
		{
			Show();
			system("pause");
		}
		if (choose == 'P' || choose == 'p')
		{
			PreOrder();
			InOrder();
			PostOrder();
			system("pause");
		}
		if (choose == 'H' || choose == 'h')
		{
			Height();
			system("pause");
		}
		if (choose == 'B' || choose == 'b')
		{
			IsBalance();
			system("pause");
		}
		if (choose == 'K' || choose == 'k')
		{
			Max_Min();
			system("pause");
		}
		if (choose == 'C' || choose == 'c')
		{
			Count();
			system("pause");
		}
		if (choose == 'V' || choose == 'v')
		{
			Search();
			system("pause");
		}
		if (choose == 'Y' || choose == 'y')
		{
			DoBalance();
			system("pause");
		}
		if (choose == 'E' || choose == 'e')
		{
			exit(0);
		}
	} while (choose != 'E' || choose != 'e');
}
/**
* @brief : This function calls the insert function in BST header.
* @see main() : Review what function is called.
*/
void Files::Add()
{
	int i;
	cout << "Enter file number: ";
	cin >> i;
	N.insert(i);
}
/**
* @brief : This function calls the preorder function in BST header.
* @see main() : Review what function is called.
*/
void Files::PreOrder()
{
	cout << "Pre-order traverse: " << endl;
	N.preOrder();
	cout << endl;
}
/**
* @brief : This function calls the inorder function in BST header.
* @see main() : Review what function is called.
*/
void Files::InOrder()
{
	cout << endl << "In-order traverse: " << endl;
	N.inOrder();
	cout << endl;
}
/**
* @brief : This function calls the postorder function in BST header.
* @see main() : Review what function is called.
*/
void Files::PostOrder()
{
	cout << endl << "Post-order traverse is : " << endl;
	N.postOrder();
	cout << endl << endl;
}
/**
* @brief : This function calls the display function in BST header.
* @see main() : Review what function is called.
*/
void Files::Show()
{
	N.display(1);
	cout << endl << endl << endl << endl;
}
/**
* @brief : This function calls the Delete function in BST header.
* @see main() : Review what function is called.
*/
void Files::DeleteF()
{
	int num;
	int Same_num = 0;
	cout << "Enter the number to be deleted : ";
	cin >> num;
	N.same_num(num, Same_num);
	for (int i = 0; i < Same_num; i++)
		N.Delete(num);
}
/**
* @brief : This function calls the Delete function in BST header.
* @see main() : Review what function is called.
*/
void Files::DeleteL()
{
	int num;
	cout << "Enter the number to be deleted : ";
	cin >> num;
	N.Delete(num);
}
/**
* @brief : This function calls the Delete function in BST header.
* @see main() : Review what function is called.
*/
void Files::DeleteA()
{
	int num;
	int Same_num = 0;
	cout << "Enter the number to be deleted : ";
	cin >> num;
	N.same_num(num, Same_num);
	for (int i = 0; i < Same_num; i++)
		N.Delete(num);
}
/**
* @brief : This function calls the getHeight function in BST header.
* @see main() : Review what function is called.
*/
void Files::Height()
{
	int h = N.getHeight();
	cout << "The height of this BST is : " << h << endl;
}
/**
* @brief : This function calls the isBalanced function in BST header.
* @see main() : Review what function is called.
*/
void Files::IsBalance()
{
	bool isbal = N.isBalanced();
	if (isbal)
		cout << "BST is balanced! " << endl;
	else
		cout << "BST is not balanced! " << endl;
}
/**
* @brief : This function calls the getMax and getMin function in BST header.
* @see main() : Review what function is called.
*/
void Files::Max_Min()
{
	Node * mx = N.getMaxNode();
	cout << "Max number of files: " << mx->data << endl;
	Node * mi = N.getMinNode();
	cout << "Min number of files:" << mi->data << endl;
}
/**
* @brief : This function calls the Count function in BST header.
* @see main() : Review what function is called.
*/
void Files::Count()
{
	int count = 0;
	cout << "Leaf Files: " << N.leaf() << " Unique Files: " << N.Count() << " - Total Files: " << N.Count() << endl;
}
/**
* @brief : This function calls the Find function in BST header.
* @see main() : Review what function is called.
*/
void Files::Search()
{
	Node *parent, *location;
	int i;
	cout << "Enter searching file number: ";
	cin >> i;
	N.find(i, &parent, &location);
	if (location == NULL)
	{
		cout << "Item not present in tree" << endl;
		return;
	}
	else
	{
		cout << "Item is present in tree" << endl;
		return;
	}
}
/**
* @brief : This function calls the DoBalance function in BST header.
* @see main() : Review what function is called.
*/
void Files::DoBalance()
{
	N.DoBalance();
}