// Type.cpp: implementation of the Type class.
//
//////////////////////////////////////////////////////////////////////
#include "Type.h"
#include "Tag.h"

Type::Type(std::string s,int t,int w)	// Type has three attributions
{
	tag=t;	// the tag of the (Type)Token
	value=0;
	word=true;	// Type has "word" attribution
	type=true;	// Type has "type" attribution
	lexeme=s;	// set specific string of the Type to lexeme
	width=w;
}

Type::~Type()
{}
const Type Type::Int=Type("integer",Tag.INTTK,8);
const Type Type::Char=Type("char",Tag.CHARTK,8);
const Type Type::Void=Type("procedure",Tag.PROCETK,0);
