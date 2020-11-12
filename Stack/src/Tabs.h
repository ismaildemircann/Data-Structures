/**
* @author ismaildemircan --> e-mail: ismaildemircann98@gmail.com
* @date 23 Kasým 2019 Pazar
* @brief This header is a tab structure built on a stack structure.
* It includes the functions of adding or removing
* new tabs to the program, retrieving the tab through the created recycle bin
* and finding the order in which the tab is located.
*/
#pragma once
class Tabs
{
public:
	Tabs();
	~Tabs();
	void Menu();
	void Add();
	void Delete();
	void Print()const;
	void Dimension();
	void Look();
	void Back();
	void History()const;
	void DHistory();
	void DSize();
};