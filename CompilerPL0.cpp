#include "CompilerPL0.h"
#include "Lexer.h"
#include "Tag.h"
#include <iostream>
#include <windows.h>
#include <fstream>

// for testing Lexer, please delete it after tesing passed

#include "DTS.h"

using namespace std;

void preProcess(FILE*& in,char* filename, string& path, string& file, string& asmpath){
	//by using *&, the function can get the addr of "in" and 
	//also save the modification of the content of (string)*in.
	
	/*
	cout<<"Please input the file directory:"<<endl;
	int j;
	for(j=0;j<1000;j++){
		char c=getchar();
		if(c=='\n'){
			filename[j]=0;
			break;
		}
		filename[j]=c;
	}*/

	//Jolin: for test ! after deleting this segment, please incomment the segment above.
	char test[]="c:\\Mydoc\\PL0test\\test'1'.txt\n";
	int j;
	for(j=0;j<1000;j++){
		char c=test[j];
		if(c=='\n'){
			filename[j]=0;
			break;
		}
		filename[j]=c;
	}
	//jolin: test_end !

	while((in=fopen(filename,"r"))==NULL){
		cout<<"Can't open the input file."
			"Please check the directory,"
			"and try again:"<<endl;
		for(j=0;j<1000;j++){
			char c=getchar();
			if(c='\n'){
				filename[j]=0;
				break;
			}
			filename[j]=c;
		}
	}
	cout<<"File opening... is successful!"<<endl;
	//get path
	string tpath(filename);
	while(tpath[tpath.length()-1]!='\\'){
		tpath.resize(tpath.size()-1);
	}
	path=tpath;
	//get filename without extensive name
	int start=-1,end=-1;
	for(int i=j;i>=0;i--){
		if(end==-1&&filename[i]=='.')
			end=1;
		if(start==-1&&filename[i]=='\\')
			start=i;
		if(start!=-1&&end!=-1)
			break;
	}
	if(start>end)
		end=j;
	for(i=start+1;i<end;i++){
		file+=filename[i];
	}
	//get path for .asm
	asmpath=path+file+".asm";
}
void main(){
	char filename[1000]="";
	string path="",file="",asmpath="";
	FILE *in=NULL;
	preProcess(in,filename,path,file,asmpath);
	cout<<"The filename is: "<<filename<<endl;
	cout<<"The path of input is: "<<path<<endl;
	cout<<"and the file is: "<<file<<endl;
//	QuadrupleMgr* QMgr=new QuadrupleMgr();
//	SymbolTableMgr* SMgr=new SymbolTableMgr();
//	Parser* parser=new Parser(in,SMgr,QMgr);

	//Jolin:to test lexer:
	Lexer lex;
	lex=Lexer(in);
	Token preToken;
	int lineNo=0;
	int serialNo=0;
	string temp;
	fpos_t pose;
	bool end=false;
	
	do{

	fgetpos(in,&pose);
	preToken=lex.scan(lineNo,serialNo);
	if(preToken.num!=1)
	cout<<"tag="<<preToken.tag<<"\t"<<preToken.lexeme<<endl;
	else
	cout<<"tag="<<preToken.tag<<"\t"<<preToken.value<<endl;
	temp=preToken.toString();
	if(temp[0]==-1){
				end=true;
			}
	}while(!end);

	fclose(in);
	return;
}