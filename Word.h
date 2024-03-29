// Word.h: interface for the Word class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_WORD_H__6F7E6F51_C4E0_48D1_8EE2_55E3BA762C81__INCLUDED_)
#define AFX_WORD_H__6F7E6F51_C4E0_48D1_8EE2_55E3BA762C81__INCLUDED_
#include "Token.h"
#if _MSC_VER > 1000 //for vc5.0 and higher
#pragma once	//physically be compiled for one time
#endif // _MSC_VER > 1000

class Word : public Token //Token is the base class of Word
{
public:
	static const Word lss,leq,gre,geq,eql,neq,assign;
public:
	Word(std::string s, int tag);
	Word();
	virtual ~Word();
	std::string toString();
};

#endif // !defined(AFX_WORD_H__6F7E6F51_C4E0_48D1_8EE2_55E3BA762C81__INCLUDED_)
