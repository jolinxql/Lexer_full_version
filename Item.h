// Item.h: interface for the Item class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_ITEM_H__28768797_4351_402F_86F9_12FAE95E79D5__INCLUDED_)
#define AFX_ITEM_H__28768797_4351_402F_86F9_12FAE95E79D5__INCLUDED_
#include <string>
#include "Token.h"
#include <vector>
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
using namespace std;

class SymbolTable;
class Item // the element of SymbolTable
{
public:
	int kind;	//_CONST,VAR,TEMP,PROC,FUNC,CONSTTEMP,INCAR,REG
	int type;	//of a const or a var or a temp or a proc......:_VOID,ERR,_INT,CHAR,STRING
	int dimension;
	std::string lexeme;
	std::string value;
	int addr;
	bool arr;
	SymbolTable* pChildTable;
	SymbolTable* pParentTable;
	bool isAssigned;
public:
	Item();
	Item(string alexem,int akind,int atype,string avalue, int adimension,SymbolTable* aParentTable);
	virtual ~Item();
};

#endif