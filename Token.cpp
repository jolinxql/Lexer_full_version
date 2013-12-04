#include "Token.h"
#include <sstream>	// std::stringstream

// Constructor
Token::Token(int t){
	tag=t;
	width=0;
	value=0;
	num=false;
	word=false;
	type=false;
	std::stringstream temp("");
	temp<<(char)tag;	// set (char)tag into (stringstream)temp;
	temp>>lexeme;		// set (stringstream)temp into (string)lexeme
}
Token::Token(){
	tag=0;		//
}
std::string Token::toString(){
	return lexeme;		// get the Token string
}