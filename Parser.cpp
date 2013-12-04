// Parser.cpp: implementation of the Parser class.
//
//////////////////////////////////////////////////////////////////////

#include "Parser.h"
#include <ctype.h>
#include "define.h"
#include "CompilerPL0.h"

void Parser::reserve(Token w){
	reserveWord.push_back(w);
}
Parser::Parser(){}
Parser::Parser(FILE *i,SymbolTableMgr* s,QuadrupleMgr* q){
	in=i;
	tempLineNo=0;
	tempSerialNo=0;
	lineNo=0;
	serialNo=0;
	SMgr=s;
	QMgr=q;
	end=false;
	errorcount=0;
	hasmain=false;
	funcend=false;
	lex=Lexer(i);
	reserve(Word("const",Tag.CONSTTK));
	reserve(Word("integer",Tag.INTTK));
	reserve(Word("char",Tag.CHARTK));
	reserve(Word("var",Tag.VARTK));
	reserve(Word("array",Tag.ARRAYTK));
	reserve(Word("of",Tag.OFTK));
	reserve(Word("if",Tag.IFTK));
	reserve(Word("then",Tag.THENTK));
	reserve(Word("else",Tag.ELSETK));
	reserve(Word("do",Tag.DOTK));
	reserve(Word("while",Tag.WHILETK));
	reserve(Word("for",Tag.FORTK));
	reserve(Word("to",Tag.TOTK));
	reserve(Word("by",Tag.BYTK));
	reserve(Word("downto",Tag.DOWNTOTK));
	reserve(Word("procedure",Tag.PROCETK));
	reserve(Word("function",Tag.FUNCTK));
	reserve(Word("read",Tag.READTK));
	reserve(Word("write",Tag.READTK));
	reserve(Word("call",Tag.CALLTK));
	reserve(Word("begin",Tag.BEGINTK));
	reserve(Word("end",Tag.ENDTK));
	reserve(Type.Char);
	reserve(Type.Int);
	reserve(Type.Void);
}
Parser::~Parser(){}
int Parser::getFPos(FILE* fp,__int64* pose){
// to get the lastToken's position and set (tempToken,tempLineNo,tempSerialNo)
	tempToken= lastToken;
	tempLineNo= lineNo;
	tempSerialNo= serialNo;
	return fgetpos(in,pose);
}
int Parser::setFPos(FILE* fp,__int64* pose){
	lastToken=tempToken;
	lineNo= tempLineNo;
	serialNo = tempSerialNo;
	dpos = *pose;
	return fsetpos(in, pose);
}
bool Parser::checkKeyToken(string key){
// check whether the pre-Token is (string)key
//from the current position, get the latest token from the lexer lex
	Token preToken=lex.scan(lineNo,serialNo);
	if(preToken.lexeme==key){
		return true;
	}
	else{
		return false;
	}
}
bool Parser::checkKeyTokenR(string key){
	__int64 tpos;
	fgetpos(in,&tpos);
	int tl=lineNo;
	int ts=serialNo;
	Token preToken=lex.scan(lineNo,serialNo);
	if(preToken.lexeme==key){
		lineNo=tl;
		serialNo=ts;
		fsetpos(in,&tpos);
		return true;
	}
	else{
		lineNo=tl;
		serialNo=ts;
		fsetpos(in,&tpos);
		return false;
	}
}