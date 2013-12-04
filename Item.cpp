// Item.cpp: implementation of the Item class.
//
//////////////////////////////////////////////////////////////////////
#include "Item.h"
#include "define.h"
#include "SymbolTable.h"

Item::Item()
{}
Item::Item(string alexeme,int akind,int atype,string avalue,int adimension,SymbolTable *aParentTable){
	isAssigned=false;
	lexeme=alexeme;
	kind=akind;
	type=atype;
	value=avalue;
	addr=0;
	arr=false;
	dimension=adimension;
	pParentTable=aParentTable;
	if(kind==PROC||kind==FUNC)	// see "define.h"
		pChildTable=new SymbolTable(this);	//if the item is a function,then need to create new child SymbolTable
	else
		pChildTable=NULL;	//not a function, so no need to create new table
}
Item::~Item()				// delete childTable of the item
{
	if(pChildTable!=NULL){	// the item is a function or procedure
		delete pChildTable;
		pChildTable = NULL;
	}
}