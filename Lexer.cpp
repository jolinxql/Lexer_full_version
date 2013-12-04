#include "Lexer.h"
#include "Tag.h"
#include "Type.h"
#include "Num.h"
#include "CompilerPL0.h"
#include <sstream>
#include <ctype.h>	// function: Check type

void Lexer::reserve(Word w){
	words.push_back(w);//std::vector<Word> words;--a vector whose element type is word
}
Lexer::Lexer(){
}
Lexer::Lexer(FILE *i){
	finish=false;
	peek=' ';
	in=i;
	preSerial=0;
	words=std::vector<Word>();
//begin to add reserve words to the vector words.
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
Lexer::~Lexer(){}
void Lexer::readch(int& serialNo){	//only read the peek
	peek=fgetc(in);
	serialNo++;
}

//read and check if peek equals char c, yes then peek=' ',else back
bool Lexer::readch(char c,int& lineNo,int& serialNo){
	readch(serialNo);
	if(peek!=c){
		back(lineNo,serialNo);
		peek=' ';
		return false;
	}
	peek=' ';
	return true;
}
void Lexer::back(int& lineNo,int& serialNo){
	__int64 tpos;
	fgetpos(in,&tpos);
	tpos--;
	serialNo--;
	if(serialNo<0){	// retract to the last line and last position
		lineNo--;
		serialNo=preSerial;
	}
	fsetpos(in,&tpos);
}
Token Lexer::scan(int& lineNo, int& serialNo){
	for(;;readch(serialNo)){
		if(peek==EOF){		//finish read the file
			finish=true;
			return Token(-1);
		}
		if(peek==' '||peek=='\t')	//skip spaces
			continue;
		else if(peek=='\n'){
			lineNo=lineNo+1;		//jump to the next line
			preSerial=serialNo;		//save the last char's positon
			serialNo=0;				//jump to the begining of the new line
		}
		else 
			break;
	}
	//---------------:=,<>,<=,>=-------------------
	switch(peek){
	case':': if(readch('=',lineNo,serialNo)) return Word.assign; else return Token(':');
	case'<': if(readch('>',lineNo,serialNo))
				 return Word.neq;
		else if(readch('=',lineNo,serialNo))
			return Word.leq;
		return Word.lss;
	case'>': if(readch('=',lineNo,serialNo)) return Word.geq; else return Word.gre;
	}
	//--------------- n u m b e r ------------------
	
	/*if(isdigit(peek)){	
	//this do not accept 001 or 00 and will recognize them as error,which means tag=300,
	//but this is totally valid. if u uncomment it and comment the segment below, it can run very well
		std::string temp="";
		do{
			std::stringstream t("");
			t<<peek;	// get peek and send to t
			std::string a;
			t>>a;		// send t to string a
			temp+=a;	// join chars together
			a.~basic_string();
			readch(serialNo);
		}while(isdigit(peek));
		back(lineNo,serialNo);
		peek=' ';
		if(temp.length()!=1&&temp[0]=='0')
			return Word(temp,Tag.ILLEGALNUM);
		return Num(temp);
	}
	*/

	//this  accept 00, 003,01... and will return them as 0, 3, 1
	if(isdigit(peek)){
		std::string temp="";
		while(peek=='0'){	//delete redundant 0
			readch(serialNo);
		}
		if(!isdigit(peek)){	//0
			back(lineNo,serialNo);
			peek=' ';
			return Num("0");
		}
		else
		do{
			std::stringstream t("");
			t<<peek;	// get peek and send to t
			std::string a;
			t>>a;		// send t to string a
			temp+=a;	// join chars together
			a.~basic_string();// release a for the next loop
			readch(serialNo);
		}while(isdigit(peek));
		back(lineNo,serialNo);
		peek=' ';
		return Num(temp);
	}
	//--------------- i d e n t i f i e r -------------------
	if(isalpha(peek)){
		std::string temp("");
		do{
			temp+=peek;
			readch(serialNo);
		}while(isdigit(peek)||isalpha(peek));
		for(int i=0;i<words.size();i++)//check reserve words table
			if(temp==words[i].toString())
				break;
		back(lineNo,serialNo);
		peek=' ';
		if(i<words.size())	// is a reserve word
			return words[i];
		Word w=Word(temp,Tag.IDEN);	// push the new identifier into the words table
		words.push_back(w);
		return w;
	}
	//---------------string const-------------------
	if(isalpha(peek)){
		std::string temp("");
		do{
			temp+=peek;
			readch(serialNo);
		}while(isdigit(peek)||isalpha(peek));
		for(int i=0;i<words.size();i++)//check reserve words table
			if(temp==words[i].toString())
				break;
		back(lineNo,serialNo);
		peek=' ';
		if(i<words.size())	// is a reserve word
			return words[i];
		Word w=Word(temp,Tag.IDEN);	// push the new identifier into the words table
		words.push_back(w);
		return w;
	}
	if(peek=='\''){
		std::string temp=("");
		readch(serialNo);
		if(peek!='\''&&peek!='\n'&&peek!=EOF&&(isdigit(peek)||isalpha(peek)))//skip spaces
		{
			temp+=peek;
			readch(serialNo);
			if(peek=='\''){
				peek=' ';
				Word w=Word(temp,Tag.CHARCON);
				return w;
			}
			else if(peek=='\n'){
				readch(serialNo);
				back(lineNo,serialNo);
				peek=' ';
				Word w=Word(temp,Tag.ILLEGALCHA);
				return w;
			}
		}
		else{
			back(lineNo,serialNo);
			peek=' ';
			Word w=Word(temp,Tag.ILLEGALCHA);
			return w;
		}	
	}
	if(peek=='"'){
		std::string temp=("");
		readch(serialNo);
		while (peek!='"'&&peek!='\n'&&peek!=EOF)
		{
			temp+=peek;
			readch(serialNo);
		} 
		if(peek=='"'){
			Word w=Word(temp,Tag.STRCON);
			peek=' ';
			return w;
		}
		else if(peek=='\n'){
			readch(serialNo);
			back(lineNo,serialNo);
			Word w=Word(temp,Tag.ILLEGALSTR);
			peek=' ';
			return w;
		}
		else{
			back(lineNo,serialNo);
			Word w=Word(temp,Tag.ILLEGALSTR);
			peek=' ';
			return w;
		}
	}
	Token tok=Token(peek);
	peek=' ';
	return tok;
}