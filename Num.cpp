// Num.cpp: implementation of the Num class.
//
//////////////////////////////////////////////////////////////////////
#include "Num.h"
#include "Tag.h"

Num::Num(std::string nn)  // synthesized attribute
{
	std::stringstream temp("");
	temp<<nn;	// set nn to (stringstream)temp
	temp>>value;// set temp to (string)value
	tag=Tag.INTCON;
	width=0;	// set the width to 0
	num=true;	// is a number
	word=false;	// not a word
	type=false;	// not a type
	lexeme=nn;	// return a synthesized attribute
}
Num::Num(int v)	// inherited attribute v
{
	tag=Tag.INTCON;
	value=v;	// inherited attribute
	std::stringstream temp("");
	temp<<value;// set (string)value to (stringstream)temp
	temp>>lexeme;	// save the inherited attribute temp
	num=true;	// is a number
	word=false;	// not a word
	type=false;	// not a type
}
Num::Num(){
}
Num::~Num(){
}
std::string Num::toString(){
	return lexeme;
}
