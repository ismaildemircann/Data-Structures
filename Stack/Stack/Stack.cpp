/**
* @author ismaildemircan --> e-mail: ismaildemircann98@gmail.com
* @date 23 Kasım 2019 Pazar
* @brief This program contains the functions of the stack structure.
*/
#include <iostream>
#include "Stack.h"
using namespace std;
Stacks::Stacks()
{
	data = 0;
	Top = 0;
	next = 0;
}
Stacks::~Stacks()
{
}
/**
* @brief : This function adds the value received from the user to the top of the stack.
* @param number : Receive value
* @see main() : Review what function is called.
*/
void Stacks::Push(int number)
{
	Stacks *newStacks = new Stacks;
	newStacks->data = number;
	newStacks->next = 0;
	Stacks *p = Top;
	if (p == 0)
		Top = newStacks;
	else
	{
		while (p->next != 0)
		{
			p = p->next;
		}
		p->next = newStacks;
	}
}
/**
* @brief : This function deletes the value at the top of the stack.
* And assigns the deleted value to a temporary variable and then returns.
* @see main() : Review what function is called.
*/
int Stacks::Pop()
{
	Stacks *p = Top;
	int temp = 0;
	if (p->next == NULL)
	{
		temp = Top->data;
		delete Top;
		Top = NULL;
		return temp;
	}
	else
	{
		while (p->next->next != NULL)
		{
			p = p->next;
		}
		temp = p->next->data;
		delete p->next;
		p->next = NULL;
		return temp;
	}
}
/**
* @brief : This function prints the values ​​in the stack.
* @see main() : Review what function is called.
*/
void Stacks::List()const
{
	Stacks *p = Top;
	while (p)
	{
		cout << p->data << endl;
		p = p->next;
	}
}
/**
* @brief : This function takes the deleted value from the recycle bin and returns it to the stack.
* @param k : Number of elements in recycle bin
* @see main() : Review what function is called.
*/
int Stacks::Undo(int k)
{
	Stacks *p = Top;
	for (int i = 1; i < k; i++)
	{
		p = p->next;
	}
	return p->data;
}
/**
* @brief : This function returns the order in which the entered value is placed.
* @param k : Searched value
* @see main() : Review what function is called.
*/
int Stacks::Search(int x)
{
	Stacks *p = Top;
	int k = 0;
	while (p != 0)
	{
		k++;
		if (p->data == x)
		{
			return k;
		}
		p = p->next;
	}
	return -1;
}
/**
* @brief : Number of elements in stack.
* @see main() : Review what function is called.
*/
int  Stacks::Count()
{
	int i = 0;
	Stacks *p = Top;
	while (p)
	{
		p = p->next;
		i++;
	}
	return i;
}
/**
* @brief : This function checks if the stack is empty.
* @see main() : Review what function is called.
*/
bool Stacks::IsEmpty()
{
	Stacks *p = Top;
	if (p == 0)
	{
		return true;
	}
	return false;
}