/**
* @author ismaildemircan --> e-mail: ismaildemircann98@gmail.com
* @date 9 December 2019 Sunday
* @brief This program contains the functions of the SplayTree structure.
*/
#include <iostream>
#include "SplayTree.h"
SplayTree::SplayTree()
{
}
SplayTree::~SplayTree()
{

}
/**
* @brief : This function do right rotation.
* @param root : Tree's root.
* @see main() : Review what function is called.
*/
Node* SplayTree::RR_Rotate(Node* root)
{
	cout << "zag ";
	PreOrder(root);
	Node* R = root->left;
	root->left = R->right;
	R->right = root;
	return R;
}
/**
* @brief : This function do left rotation.
* @param root : Tree's root.
* @see main() : Review what function is called.
*/
Node* SplayTree::LL_Rotate(Node* root)
{
	cout << "zig ";
	PreOrder(root);
	Node* L = root->right;
	root->right = L->left;
	L->left = root;
	return L;
}
/**
* @brief : This function turns the tree into a splay tree..
* @param root : Tree's root.
* @param data : Receive value.
* @see main() : Review what function is called.
*/
Node* SplayTree::Splay(int data, Node* root)
{
	if (!root)
		return NULL;
	Node head;
	head.left = NULL;
	head.right = NULL;
	Node* LMax = &head;
	Node* RMin = &head;
	while (1)
	{
		if (data < root->data)
		{
			if (!root->left)
				break;
			if (data < root->left->data)
			{
				root = RR_Rotate(root);
				if (!root->left)
					break;
			}
			RMin->left = root;
			RMin = RMin->left;
			root = root->left;
			RMin->left = NULL;
		}
		else if (data > root->data)
		{
			if (!root->right)
				break;
			if (data > root->right->data)
			{
				root = LL_Rotate(root);
				if (!root->right)
					break;
			}
			LMax->right = root;
			LMax = LMax->right;
			root = root->right;
			LMax->right = NULL;
		}
		else
			break;
	}
	LMax->right = root->left;
	RMin->left = root->right;
	root->left = head.right;
	root->right = head.left;
	return root;
}
/**
* @brief : This function creates a static node.
* @param data : Receive value.
* @see main() : Review what function is called.
*/
Node* SplayTree::New_Node(int data)
{
	Node* new_node = new Node;
	if (!new_node)
	{
		fprintf(stderr, "Out of memory!\n");
		exit(0);
	}
	new_node->data = data;
	new_node->left = new_node->right = NULL;
	return new_node;
}
/**
* @brief : This function adds the value received from the user to the tree.
* @param root : Tree's root.
* @param data : Receive value.
* @see main() : Review what function is called.
*/
Node* SplayTree::Insert(int data, Node* root)
{
	static Node* p_node = NULL;
	if (!p_node)
		p_node = New_Node(data);
	else
		p_node->data = data;
	if (!root)
	{
		root = p_node;
		p_node = NULL;
		return root;
	}
	root = Splay(data, root);
	if (data < root->data)
	{
		p_node->left = root->left;
		p_node->right = root;
		root->left = NULL;
		root = p_node;
	}
	else if (data > root->data)
	{
		p_node->right = root->right;
		p_node->left = root;
		root->right = NULL;
		root = p_node;
	}
	else
		return root;
	p_node = NULL;
	return root;
}
/**
* @brief : This function deletes the value of the tree.
* @param root : Tree's root.
* @param data : Receive value.
* @see main() : Review what function is called.
*/
Node* SplayTree::Delete(int data, Node* root)
{
	Node* temp;
	if (!root)
		return NULL;
	root = Splay(data, root);
	if (data != root->data)
		return root;
	else
	{
		if (!root->left)
		{
			temp = root;
			root = root->right;
		}
		else
		{
			temp = root;
			root = Splay(data, root->left);
			root->right = temp->right;
		}
		free(temp);
		return root;
	}
}
/**
* @brief : This function find the eleman in the tree.
* @param root : Tree's root.
* @param data : Searching eleman.
* @see main() : Review what function is called.
*/
Node* SplayTree::Search(int data, Node* root)
{
	return Splay(data, root);
}
/**
* @brief : This function print preorder the values ​​in the tree.
* @param root : Tree's root.
* @see main() : Review what function is called.
*/
void SplayTree::PreOrder(Node *root)
{
	if (root != NULL)
	{
		cout << root->data << " ";
		PreOrder(root->left);
		PreOrder(root->right);
	}
}