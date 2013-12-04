// Word.cpp: implementation of the Word class.
//
//////////////////////////////////////////////////////////////////////

#include "Word.h"
#include "Tag.h"
//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////
Word::Word(std::string s, int t){	//Operators
	tag=t;
	width=0;
	num=false;
	word=false;
	type=false;
	lexeme=s;	// set lexeme = (string) s
}
Word::Word(){
}
Word::~Word(){
	lexeme.~basic_string();
}
const Word Word::lss=Word("<",Tag.LSS);
const Word Word::leq=Word("<=",Tag.LEQ);
const Word Word::gre=Word(">",Tag.GRE);
const Word Word::geq=Word(">=",Tag.GEQ);
const Word Word::eql=Word("=",Tag.EQL);
const Word Word::neq=Word("<>",Tag.NEQ);
const Word Word::assign=Word(":=",Tag.ASSIGN);

std::string Word::toString(){
	return lexeme;		// get the lexeme string;
}