%{

#include <kParser.hpp>
#include <iostream>

using namespace std;

%}

%option reentrant noyywrap never-interactive

DIGIT [0-9]
NUMBER {DIGIT}+

%%

{NUMBER}        { cout << "NUMBER"; return NUMBER; }
"+"             { cout << "PLUS"; return PLUS; }
"*"             { cout << "MUL"; return MUL; }
" "             {}
.               { cerr << "ERROR"; }
