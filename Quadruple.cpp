// Quadruple.cpp: implementation of the Quadruple class.
// the element of a quadruple list
//////////////////////////////////////////////////////////////////////

#include "Quadruple.h"
Quadruple::Quadruple(int aOpr,Item* aSrc1,Item* aSrc2,Item* aObj){
	Opr = aOpr;
	Src1 = aSrc1;
	Src2=aSrc2;
	Obj=aObj;
}
Quadruple::~Quadruple()
{}
