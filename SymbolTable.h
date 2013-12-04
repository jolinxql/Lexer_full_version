// SymbolTable.h: interface for the SymbolTable class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_SYMBOLTABLE_H__8E92B2AC_BAB1_408F_9BF9_B6831316F704__INCLUDED_)
#define AFX_SYMBOLTABLE_H__8E92B2AC_BAB1_408F_9BF9_B6831316F704__INCLUDED_
#include <vector>
#include "Item.h"
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
using namespace std;
class Item;
class SymbolTable
{
public:
	Item* itemList[100];	// the class of element of the table is Item 
	Item* newItem;	//
	Item* pParentItem;// point to its parent SymbolTable
	int itemNumber;	// the total number of items in the table
public:
	SymbolTable();
	SymbolTable(Item* aParentItem);
	virtual ~SymbolTable();
	void error();
	int Find(string alexeme);
	int Check(string alexeme);
	int AllCapsFind(string alexeme);
	int AllCapsCheck(string alexeme);
	void Increase();
	int Insert(string alexeme, int akind, int atype, string avalue, int adimension);
	void Display(int aItemNo);
	void DisplayAll();

};

#endif // !defined(AFX_SYMBOLTABLE_H__8E92B2AC_BAB1_408F_9BF9_B6831316F704__INCLUDED_)
