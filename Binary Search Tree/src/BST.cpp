/**
* @author ismaildemircan --> e-mail: ismaildemircann98@gmail.com
* @date 1 December 2019 Sunday
* @brief This program contains the functions of the BST structure.
*/
#include "BST.h"
#include <iostream>
#include <algorithm> 
using namespace std;
BST::BST()
{
	_root = NULL;
}
BST::~BST()
{
}
/**
* @brief : This function adds the value received from the user to the tree.
* @param treeNode : BST root.
* @param data : Receive value.
* @see main() : Review what function is called.
*/
void BST::insert(Node *treeNode, int data)
{
	if (!treeNode)
	{
		treeNode = new Node(data);
		_root = treeNode;
	}
	else
	{
		if (data < treeNode->data)
		{
			if (!treeNode->left)
			{
				Node *treeTemp = new Node(data);
				treeNode->left = treeTemp;
			}
			else
				insert(treeNode->left, data);
		}
		else
		{
			if (!treeNode->right)
			{
				Node *treeTemp = new Node(data);
				treeNode->right = treeTemp;
			}
			else
				insert(treeNode->right, data);
		}
	}
}
/**
* @brief : This function deletes the value of the tree.
* @param data : Receive value.
* @see main() : Review what function is called.
*/
void BST::Delete(int data)
{
	Node *parent, *location;
	if (_root == NULL)
	{
		cout << "Tree empty" << endl;
		return;
	}
	find(data, &parent, &location);
	if (location == NULL)
	{
		cout << "Item not present in tree" << endl;
		return;
	}
	if (location->left == NULL && location->right == NULL)
		Delcase_a(parent, location);
	if (location->left != NULL && location->right == NULL)
		Delcase_b(parent, location);
	if (location->left == NULL && location->right != NULL)
		Delcase_b(parent, location);
	if (location->left != NULL && location->right != NULL)
		Delcase_c(parent, location);
	free(location);
}
/**
* @brief : This function in tree arrange to links the node of the leaf to delete.
* @param *par : Parent of node.
* @param *loc : Locaition of node.
* @see main() : Review what function is called.
*/
void BST::Delcase_a(Node *par, Node *loc)
{
	if (par == NULL)
	{
		_root = NULL;
	}
	else
	{
		if (loc == par->left)
			par->left = NULL;
		else
			par->right = NULL;
	}
}
/**
* @brief : This function in tree arrange to links the node of the parent to delete.
* @param *par : Parent of node.
* @param *loc : Locaition of node.
* @see main() : Review what function is called.
*/
void BST::Delcase_b(Node *par, Node *loc)
{
	Node *child;
	if (loc->left != NULL)
		child = loc->left;
	else
		child = loc->right;
	if (par == NULL)
	{
		_root = child;
	}
	else
	{
		if (loc == par->left)
			par->left = child;
		else
			par->right = child;
	}
}
/**
* @brief : This function in tree arrange to links the node of the root to delete.
* @param *par : Parent of node.
* @param *loc : Locaition of node.
* @see main() : Review what function is called.
*/
void BST::Delcase_c(Node *par, Node *loc)
{
	Node *ptr, *ptrsave, *suc, *parsuc;
	ptrsave = loc;
	ptr = loc->right;
	while (ptr->left != NULL)
	{
		ptrsave = ptr;
		ptr = ptr->left;
	}
	suc = ptr;
	parsuc = ptrsave;
	if (suc->left == NULL && suc->right == NULL)
		Delcase_a(parsuc, suc);
	else
		Delcase_b(parsuc, suc);
	if (par == NULL)
	{
		_root = suc;
	}
	else
	{
		if (loc == par->left)
			par->left = suc;
		else
			par->right = suc;
	}
	suc->left = loc->left;
	suc->right = loc->right;
}
/**
* @brief : This function print preorder the values ​​in the tree.
* @param treeNode : BST root.
* @see main() : Review what function is called.
*/
void BST::preOrder(Node * treeNode)
{
	if (!treeNode)
		return;
	cout << treeNode->data << " ";
	preOrder(treeNode->left);
	preOrder(treeNode->right);
}
/**
* @brief : This function print inorder the values ​​in the tree.
* @param treeNode : BST root.
* @see main() : Review what function is called.
*/
void BST::inOrder(Node * treeNode)
{
	if (!treeNode)
		return;
	inOrder(treeNode->left);
	cout << treeNode->data << " ";
	inOrder(treeNode->right);
}
/**
* @brief : This function print postorder the values ​​in the tree.
* @param treeNode : BST root.
* @see main() : Review what function is called.
*/
void BST::postOrder(Node * treeNode)
{
	if (!treeNode)
		return;
	postOrder(treeNode->left);
	postOrder(treeNode->right);
	cout << treeNode->data << " ";
}
/**
* @brief : Number of elements in tree.
* @param treeNode : BST root.
* @see main() : Review what function is called.
*/
int BST::Count(Node *treeNode)
{
	if (treeNode == NULL)
		return 0;
	else
		return Count(treeNode->left) + 1 + Count(treeNode->right);
}
/**
* @brief : Number of leaf elements in tree.
* @param treeNode : BST root.
* @see main() : Review what function is called.
*/
int BST::leaf(Node* node)
{
	if (node == NULL)
		return 0;
	if (node->left == NULL && node->right == NULL)
		return 1;
	else
		return leaf(node->left) + leaf(node->right);
}
/**
* @brief : Number of same elements in tree.
* @param treeNode : BST root.
* @see main() : Review what function is called.
*/
void BST::same_num(Node *root, int num, int& Same_num)
{
	if (root != NULL) {
		same_num(root->left, num, Same_num);
		if (num == root->data)
			Same_num++;
		same_num(root->right, num, Same_num);
	}
}
/**
* @brief : This function show element ​in the tree.
* @param treeNode : BST root.
* @param level : It's a height of tree.
* @see main() : Review what function is called.
*/
void BST::display(Node *treenode, int level)
{
	int i;
	if (treenode != NULL)
	{
		display(treenode->right, level + 1);
		cout << endl;
		if (treenode == _root)
			cout << "Root->:  ";
		else
		{
			for (i = 0; i < level; i++)
				cout << "       ";
		}
		cout << treenode->data;
		display(treenode->left, level + 1);
	}
}
/**
* @brief : This function calculate height tree.
* @param treeNode : BST root.
* @see main() : Review what function is called.
*/
int BST::getHeight(Node *treenode)
{
	if (!treenode)
		return 0;
	return 1 + max(getHeight(treenode->left), getHeight(treenode->right));
}
/**
* @brief : This function get control balance tree.
* @param treeNode : BST root.
* @see main() : Review what function is called.
*/
bool BST::isBalanced(Node *treenode)
{
	if (!treenode)
		return false;
	int leftheight = getHeight(treenode->left);
	int rightheight = getHeight(treenode->right);
	if (abs(leftheight - rightheight) > 1)
		return false;
	return true;
}
/**
* @brief : This function find the eleman in the tree.
* @param treeNode **par : Parent of node.
* @param treeNode **loc: Location of node.
* @param treeNode item: Searching eleman.
* @see main() : Review what function is called.
*/
void BST::find(int item, Node **par, Node **loc)
{
	Node *ptr, *ptrsave;
	if (_root == NULL)
	{
		*loc = NULL;
		*par = NULL;
		return;
	}
	if (item == _root->data)
	{
		*loc = _root;
		*par = NULL;
		return;
	}
	if (item < _root->data)
		ptr = _root->left;
	else
		ptr = _root->right;
	ptrsave = _root;
	while (ptr != NULL)
	{
		if (item == ptr->data)
		{
			*loc = ptr;
			*par = ptrsave;
			return;
		}
		ptrsave = ptr;
		if (item < ptr->data)
			ptr = ptr->left;
		else
			ptr = ptr->right;
	}
	*loc = NULL;
	*par = ptrsave;
}
/**
* @brief : This function get the max eleman in the tree.
* @see main() : Review what function is called.
*/
Node * BST::getMaxNode()
{
	if (!_root)
	{
		cout << " The BST is empty!" << endl;
		return NULL;
	}
	Node * treeNode = _root;
	while (treeNode->right)
		treeNode = treeNode->right;
	return treeNode;
}
/**
* @brief : This function get the min eleman in the tree.
* @see main() : Review what function is called.
*/
Node * BST::getMinNode()
{
	if (!_root)
	{
		cout << " the BST is empty!" << endl;
		return NULL;
	}
	Node * treeNode = _root;
	while (treeNode->left)
		treeNode = treeNode->left;
	return treeNode;
}
/**
* @brief : This function do balance in the tree.
* @see main() : Review what function is called.
*/
Node * BST::DoBalance(Node*& node)
{
	if (node == NULL)
		return 0;
	if (getHeight(node->left) - getHeight(node->right) == 2)
	{
		if (node->data < node->left->data)
			rotateLeftOnce(node);
		else
			rotateLeftTwice(node);
	}
	if (getHeight(node->right) - getHeight(node->left) == 2)
	{
		if (node->data < node->right->data)
			rotateLeftOnce(node);
		else
			rotateLeftTwice(node);
	}
	return node;
}
/**
* @brief : This function do rotate left once in the tree.
* @see main() : Review what function is called.
*/
void BST::rotateLeftOnce(Node*& n)
{
	Node* temp = _root->right;
	n->right = _root->left;
	temp->left = n;
	n = temp;
	_root = n;
}
/**
* @brief : This function do rotate left twice in the tree.
* @see main() : Review what function is called.
*/
void BST::rotateLeftTwice(Node*& node)
{
	rotateRightOnce(node->left);
	rotateLeftOnce(node);
}
/**
* @brief : This function do rotate right once in the tree.
* @see main() : Review what function is called.
*/
void BST::rotateRightOnce(Node*& n)
{
	Node *temp = _root->left;
	n->left = temp->right;
	temp->right = n;
	n = temp;
	_root = n;
}
/**
	* @brief : This function do rotate right twice in the tree.
	* @see main() : Review what function is called.
	*/
void BST::rotateRightTwice(Node*& node)
{
	rotateLeftOnce(node->right);
	rotateRightOnce(node);
}