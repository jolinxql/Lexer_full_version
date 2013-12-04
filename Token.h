#ifndef TOKEN_H
#define TOKEN_H 0
#include <string>
class Token{
public:
	Token(int t);		// Constructor
	Token();			// Constructor
	std::string toString();
public:
	int tag;	// the tag of Token
	bool word;	// the Token is a word
	bool type;	// the Token is a type
	bool num;	// the Token is a number
	std::string lexeme;	//for word,type,num
	int value;	// for number
	int width;	// for type
};
#endif