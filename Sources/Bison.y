%{

#include <kParser.hpp>
#include <kLexer.h>
#include <iostream>

using namespace std;

int yyerror( yyscan_t scanner, const char* errMsg )
{
    cerr << errMsg << endl;

    return 0;
}

%}


%code requires
{

typedef void* yyscan_t;

}

%param { yyscan_t scanner }

%union {
    int Number;
    void* Exp;
}

%token MUL
%token PLUS
%token <Number> NUMBER
%type <Exp> Expression

%left PLUS
%left MUL


%%

Start: Expression[E] {}
;

Expression: NUMBER[L] PLUS NUMBER[R] { cout << "Expression completed" << endl; }
;