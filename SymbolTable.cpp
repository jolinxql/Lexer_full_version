// SymbolTable.cpp: implementation of the SymbolTable class.
//
//////////////////////////////////////////////////////////////////////

#include "SymbolTable.h"
#include "define.h"
#include <iostream>
#include "DTS.h"

SymbolTable::SymbolTable()	// initial
{
	itemNumber=0;		// the total number of this table
	pParentItem=NULL;	// a pointer to the parent item
}
SymbolTable::SymbolTable(Item* aParentItem){	// get the head of the table
		itemNumber=0;
		pParentItem=aParentItem;
}
SymbolTable::~SymbolTable(){
	for(int i=0;i<itemNumber;i++){
		if(itemList[i]->kind!=INVAR)	//delete all the variables and reserve all the invariables
			delete itemList[i];
	}
}
void SymbolTable::error(){		// Insert error
	printf("Insert error! Already exist.\n");
}
int SymbolTable::Find(string alexeme){	// find the item in the itemList according to its lexeme
	for(int i=0;i<itemNumber;i++){
		if(alexeme==itemList[i]->lexeme)
			return i;
	}
	return -1;
}
int SymbolTable::AllCapsFind(string alexeme){	// find the item in the itemList according to its lexeme
	for(int i=0;i<itemNumber;i++){
		if(alexeme==itemList[i]->lexeme)
			return i;
	}
	return -1;
}

int SymbolTable::Check(string alexeme){
	if(itemNumber==0)
		return -1;
	else{
		for(int i=0;i<itemNumber;i++)
			if(alexeme==itemList[i]->lexeme)
				return i;
			return -1;
	}
}
int SymbolTable::AllCapsCheck(string alexeme){
	if(itemNumber==0)
		return -1;
	else{
		for(int i=0;i<itemNumber;i++)
			if(alexeme==itemList[i]->lexeme)
				return i;
		return -1;
	}
}
void SymbolTable::Increase(){
	itemList[itemNumber]= newItem;	// add the newItem to the last element of the array
	itemNumber++;			// the total number of the item in the list increase
}
int SymbolTable::Insert(string alexeme,int akind,int atype,string avalue,int adimension){
	newItem=new Item(alexeme,akind,atype,avalue,adimension,this);
	Increase();				//	insert the new item to the last position of the itemlist
	return 0;
}

void SymbolTable::Display(int aItemNo){	// by giving the aItemNo, the specific item can be cout to the commend window
	if(aItemNo>=0&&aItemNo<itemNumber){
		cout<<"Item"<<aItemNo<<" name:"<<itemList[aItemNo]->lexeme;
		cout<<" kind:"<<DTS::Convert(itemList[aItemNo]->kind);
		cout<<" type:"<<DTS::Convert(itemList[aItemNo]->type);
		cout<<" value:"<<itemList[aItemNo]->value;
		cout<<" dimension:"<<itemList[aItemNo]->dimension;
		cout<<" pParenttable:"<< itemList[aItemNo]->pParentTable<< endl;
	}
}


void SymbolTable::DisplayAll(){
	for (int i = 0; i < itemNumber; i ++){
		if (pParentItem != NULL)
			cout << " ";
		Display(i);
		if (itemList[i] -> pChildTable != NULL)
			itemList[i] -> pChildTable -> DisplayAll();
	}
}

