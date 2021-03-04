%{

#include <iostream>

using namespace std;

%}

%option reentrant noyywrap never-interactive

DIGIT [0-9]
NUMBER {DIGIT}+

%%

{NUMBER}        { cout << "NUMBER"; }
"+"             { cout << "PLUS"; }
"-"             { cout << "MINUS"; }
" "             {}
