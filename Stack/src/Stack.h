/**
* @author ismaildemircan --> e-mail: ismaildemircann98@gmail.com
* @date 23 Kasým 2019 Pazar
* @brief This program contains the functions of the stack structure.
*/
#pragma once
class Stacks
{
	Stacks *Top;
	Stacks *next;
private:
	int data;
public:
	Stacks();
	~Stacks();
	bool IsEmpty();
	void List()const;
	void Push(int);
	int Pop();
	int Count();
	int Undo(int);
	int Search(int);
};