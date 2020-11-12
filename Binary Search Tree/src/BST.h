/**
* @author ismaildemircan --> e-mail: ismaildemircann98@gmail.com
* @date 1 December 2019 Sunday
* @brief This program contains the functions of the BST structure.
*/
#pragma once
#include <iostream>
struct Node {
	Node(int value) : data(value), left(NULL), right(NULL)
	{
	}
	int data;
	Node *left;
	Node *right;
};
class BST {
public:
	int SameNumber = 0;
	BST();
	~BST();
	Node *_root;
	void insert(int data)
	{
		insert(_root, data);
	}
	/**
	* @brief : This function deletes the value of the tree.
	* @param data : Receive value.
	* @see main() : Review what function is called.
	*/
	void Delete(int item);
	/**
	* @brief : This function in tree arrange to links the node of the leaf to delete.
	* @param *par : Parent of node.
	* @param *loc : Locaition of node.
	* @see main() : Review what function is called.
	*/
	void Delcase_a(Node *par, Node *loc);
	/**
	* @brief : This function in tree arrange to links the node of the parent to delete.
	* @param *par : Parent of node.
	* @param *loc : Locaition of node.
	* @see main() : Review what function is called.
	*/
	void Delcase_b(Node *par, Node *loc);
	/**
	* @brief : This function in tree arrange to links the node of the root to delete.
	* @param *par : Parent of node.
	* @param *loc : Locaition of node.
	* @see main() : Review what function is called.
	*/
	void Delcase_c(Node *par, Node *loc);
	void preOrder()
	{
		preOrder(_root);
	}
	void inOrder()
	{
		inOrder(_root);
	}
	void postOrder()
	{
		postOrder(_root);
	}
	int Count()
	{
		return Count(_root);
	}
	int leaf()
	{
		return leaf(_root);
	}
	void same_num(int num, int & Same_num)
	{
		same_num(_root, num, Same_num);
	}
	void display(int level)
	{
		display(_root, level);
	}
	int getHeight()
	{
		return getHeight(_root);
	}
	bool isBalanced()
	{
		return isBalanced(_root);
	}
	/**
	* @brief : This function find the eleman in the tree.
	* @param treeNode **par : Parent of node.
	* @param treeNode **loc: Location of node.
	* @param treeNode item: Searching eleman.
	* @see main() : Review what function is called.
	*/
	void find(int item, Node **par, Node **loc);
	/**
	* @brief : This function get the max eleman in the tree.
	* @see main() : Review what function is called.
	*/
	Node * getMaxNode();
	/**
	* @brief : This function get the min eleman in the tree.
	* @see main() : Review what function is called.
	*/
	Node * getMinNode();
	Node * DoBalance()
	{
		return DoBalance(_root);
	}
	/**
	* @brief : This function do rotate left once in the tree.
	* @see main() : Review what function is called.
	*/
	void rotateLeftOnce(Node *& node);
	/**
	* @brief : This function do rotate left twice in the tree.
	* @see main() : Review what function is called.
	*/
	void rotateLeftTwice(Node *& node);
	/**
	* @brief : This function do rotate right once in the tree.
	* @see main() : Review what function is called.
	*/
	void rotateRightOnce(Node *& node);
	/**
	* @brief : This function do rotate right twice in the tree.
	* @see main() : Review what function is called.
	*/
	void rotateRightTwice(Node *& node);
private:
	/**
	* @brief : This function adds the value received from the user to the tree.
	* @param treeNode : BST root.
	* @param data : Receive value.
	* @see main() : Review what function is called.
	*/
	void insert(Node *treeNode, int data);
	/**
	* @brief : This function print preorder the values ​​in the tree.
	* @param treeNode : BST root.
	* @see main() : Review what function is called.
	*/
	void preOrder(Node * treeNode);
	/**
	* @brief : This function print inorder the values ​​in the tree.
	* @param treeNode : BST root.
	* @see main() : Review what function is called.
	*/
	void inOrder(Node * treeNode);
	/**
	* @brief : This function print postorder the values ​​in the tree.
	* @param treeNode : BST root.
	* @see main() : Review what function is called.
	*/
	void postOrder(Node * treeNode);
	/**
	* @brief : Number of elements in tree.
	* @param treeNode : BST root.
	* @see main() : Review what function is called.
	*/
	int Count(Node *treeNode);
	/**
	* @brief : Number of leaf elements in tree.
	* @param treeNode : BST root.
	* @see main() : Review what function is called.
	*/
	int leaf(Node * treeNode);
	/**
	* @brief : Number of same elements in tree.
	* @param treeNode : BST root.
	* @see main() : Review what function is called.
	*/
	void same_num(Node * treeNode, int num, int & Same_num);
	/**
	* @brief : This function show element ​in the tree.
	* @param treeNode : BST root.
	* @param level : It's a height of tree.
	* @see main() : Review what function is called.
	*/
	void display(Node *treeNode, int level);
	/**
	* @brief : This function calculate height tree.
	* @param treeNode : BST root.
	* @see main() : Review what function is called.
	*/
	int getHeight(Node *treeNode);
	/**
	* @brief : This function get control balance tree.
	* @param treeNode : BST root.
	* @see main() : Review what function is called.
	*/
	bool isBalanced(Node *treeNode);
	/**
	* @brief : This function do balance in the tree.
	* @see main() : Review what function is called.
	*/
	Node * DoBalance(Node *&);
};
