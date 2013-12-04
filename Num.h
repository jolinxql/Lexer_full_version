// Num.h: interface for the Num class.
//
//////////////////////////////////////////////////////////////////////
#include "Token.h"
#include <sstream>
#if !defined(AFX_NUM_H__3E485731_B0CE_4FC5_9F4D_12CFA539E7DD__INCLUDED_)
#define AFX_NUM_H__3E485731_B0CE_4FC5_9F4D_12CFA539E7DD__INCLUDED_

// to check out the explaination of this segment, go to word.h
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class Num : public Token
{
public:
	Num(std::string nn);
	Num(int v);
	Num();
	virtual ~Num();	// I still thing "virtual" is unnecessary!
	std::string toString();	// to get the (string)lexeme
};
#endif // !defined(AFX_NUM_H__3E485731_B0CE_4FC5_9F4D_12CFA539E7DD__INCLUDED_)