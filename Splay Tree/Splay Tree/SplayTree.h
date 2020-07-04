/**
* @author ismaildemircan --> e-mail: ismaildemircann98@gmail.com
* @date 9 December 2019 Sunday
* @brief This program contains the functions of the SplayTree structure.
*/
#pragma once
#include <iostream>
using namespace std;
struct Node
{
	int data;
	Node* left;
	Node* right;
};
class SplayTree
{
public:
	SplayTree();
	~SplayTree();
	/**
	* @brief : This function do right rotation.
	* @param root : Tree's root.
	* @see main() : Review what function is called.
	*/
	Node* RR_Rotate(Node* root);
	/**
	* @brief : This function do left rotation.
	* @param root : Tree's root.
	* @see main() : Review what function is called.
	*/
	Node* LL_Rotate(Node* root);
	/**
	* @brief : This function turns the tree into a splay tree..
	* @param root : Tree's root.
	* @param data : Receive value.
	* @see main() : Review what function is called.
	*/
	Node* Splay(int data, Node* root);
	/**
	* @brief : This function creates a static node.
	* @param data : Receive value.
	* @see main() : Review what function is called.
	*/
	Node* New_Node(int data);
	/**
	* @brief : This function adds the value received from the user to the tree.
	* @param root : Tree's root.
	* @param data : Receive value.
	* @see main() : Review what function is called.
	*/
	Node* Insert(int data, Node* root);
	/**
	* @brief : This function deletes the value of the tree.
	* @param root : Tree's root.
	* @param data : Receive value.
	* @see main() : Review what function is called.
	*/
	Node* Delete(int data, Node* root);
	/**
	* @brief : This function find the eleman in the tree.
	* @param root : Tree's root.
	* @param data : Searching eleman.
	* @see main() : Review what function is called.
	*/
	Node* Search(int data, Node* root);
	/**
	* @brief : This function print preorder the values ​​in the tree.
	* @param root : Tree's root.
	* @see main() : Review what function is called.
	*/
	void PreOrder(Node *root);
};