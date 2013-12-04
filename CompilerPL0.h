#ifndef COMPILERPL0_H
#define COMPILERPL0_H
#include "Num.h"
#include "Tag.h"
#include "Token.h"
#include "Type.h"
#include "Word.h"
#include "SymbolTable.h"
#include "Quadruple.h"
#include "SymbolTableMgr.h"
#include "QuadrupleMgr.h"
#include "Lexer.h"
#include "Parser.h"
#include <stdio.h>
#include <iostream>
#include <string>
#include <fstream>

static Token lastId;
static Token lastToken;

void main();
#endif