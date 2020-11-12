/**
* @author ismaildemircan --> e-mail: ismaildemircann98@gmail.com
* @date 1 December 2019 Sunday
* @brief This program is a file system prepared using binary search tree.
*/
#pragma once
class Files
{
public:
	Files();
	~Files();
	/**
	* @brief : This function opens the menu and leads to the desired function.
	* @see main() : Review what function is called.
	*/
	void Menu();
	/**
	* @brief : This function calls the insert function in BST header.
	* @see main() : Review what function is called.
	*/
	void Add();
	/**
	* @brief : This function calls the preorder function in BST header.
	* @see main() : Review what function is called.
	*/
	void PreOrder();
	/**
	* @brief : This function calls the inorder function in BST header.
	* @see main() : Review what function is called.
	*/
	void InOrder();
	/**
	* @brief : This function calls the postorder function in BST header.
	* @see main() : Review what function is called.
	*/
	void PostOrder();
	/**
	* @brief : This function calls the display function in BST header.
	* @see main() : Review what function is called.
	*/
	void Show();
	/**
	* @brief : This function calls the Delete function in BST header.
	* @see main() : Review what function is called.
	*/
	void DeleteF();
	/**
	* @brief : This function calls the Delete function in BST header.
	* @see main() : Review what function is called.
	*/
	void DeleteL();
	/**
	* @brief : This function calls the Delete function in BST header.
	* @see main() : Review what function is called.
	*/
	void DeleteA();
	/**
	* @brief : This function calls the getHeight function in BST header.
	* @see main() : Review what function is called.
	*/
	void Height();
	/**
	* @brief : This function calls the isBalanced function in BST header.
	* @see main() : Review what function is called.
	*/
	void IsBalance();
	/**
	* @brief : This function calls the getMax and getMin function in BST header.
	* @see main() : Review what function is called.
	*/
	void Max_Min();
	/**
	* @brief : This function calls the Count function in BST header.
	* @see main() : Review what function is called.
	*/
	void Count();
	/**
	* @brief : This function calls the Find function in BST header.
	* @see main() : Review what function is called.
	*/
	void Search();
	/**
	* @brief : This function calls the DoBalance function in BST header.
	* @see main() : Review what function is called.
	*/
	void DoBalance();
};