/**
* @author ismaildemircan --> e-mail: ismaildemircann98@gmail.com
* @date 9 December 2019 Sunday
* @brief This program is a tes system prepared using splay tree.
*/
#pragma once
#include "SplayTree.h"
class Menu
{
public:
	Menu();
	~Menu();
	/**
	* @brief : This function opens the menu and leads to the desired function.
	* @see main() : Review what function is called.
	*/
	void MENU();
	/**
	* @brief : This function calls the insert function in SplayTree header.
	* @param root : Tree's root.
	* @see main() : Review what function is called.
	*/
	Node* Insert(Node *root);
	/**
	* @brief : This function calls the Delete function in SplayTree header.
	* @param root : Tree's root.
	* @see main() : Review what function is called.
	*/
	Node* Delete(Node *root);
	/**
	* @brief : This function calls the Search function in SplayTree header.
	* @param root : Tree's root.
	* @see main() : Review what function is called.
	*/
	Node* Search(Node *root);
	/**
	* @brief : This function calls the inorder function in SplayTree header.
	* @param root : Tree's root.
	* @see main() : Review what function is called.
	*/
	Node* PreOrder(Node *root);
	SplayTree N;
};

