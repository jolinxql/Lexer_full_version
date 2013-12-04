// Type.h: interface for the Type class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_TYPE_H__F846D6E6_9DA3_40F9_AAEB_3E22A26EE0B6__INCLUDED_)
#define AFX_TYPE_H__F846D6E6_9DA3_40F9_AAEB_3E22A26EE0B6__INCLUDED_
#include "Word.h"
// to check out the explaination of this segment, go to word.h
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class Type :public Word	// Word is the base class of Type
{
public:
	static const Type Int, Char, Void;
public:
	Type(std::string s, int t, int w);
	Type();
	virtual ~Type(); // i don't think "virtual should be put here, but should be put in the base class Word to call Destructor."
};

#endif // !defined(AFX_TYPE_H__F846D6E6_9DA3_40F9_AAEB_3E22A26EE0B6__INCLUDED_)