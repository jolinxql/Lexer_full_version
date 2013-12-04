#ifndef LEXER_H
#define LEXER_H
#include "Word.h"
#include <vector>
class Lexer{
public:
	bool finish;
	std::vector<Word> words;	//a vector whose element type is word
	FILE *in;
private:
	char peek;	// the forefront char
	int preSerial;
public:
	Lexer();	// constructor
	Lexer(FILE *in); // constructor, input file -> in
	~Lexer();
	void reserve(Word w);	// reserve the inher attribute
	void readch(int& serialNo);		//to read and save the serial number
	bool readch(char c,int& lineNo,int& serialNo);	//
	void back(int& lineNo, int& serialNo);			// retract a char
	Token scan(int& lineNo,int& serialNo);			// scan from the given position
};
#endif