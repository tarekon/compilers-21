#include <stdio.h>
#include <unordered_map>
#include <string>
#include <iostream>
#include <fstream>

#include <kParser.hpp>
#include <kLexer.h>

using namespace std;

enum TCommand {
    C_PrintTokens,
    C_Parse,
};

static unordered_map<string,TCommand> commandsMap = {
    { "print", C_PrintTokens },
    { "parse", C_Parse },
};

int main( int argc, char* argv[] )
{
    if( argc <= 1 || argc > 3 ) {
        cerr << "Invalid argument count" << endl;
        return -1;
    }

    string commandStr = argv[1];
    string inputFileName = argv[2];
    auto cmd = commandsMap.find( commandStr );
    if( cmd == commandsMap.end() ) {
        cerr << "Unknown command " << commandStr << endl;
        return -2;
    }
    TCommand command = cmd->second;

    ifstream inputFileStream( inputFileName, ios::ios_base::in );
    if( !inputFileStream ) {
        cerr << "Unable to open file " << inputFileName << endl;
        return -3;
    }

    string content{ istreambuf_iterator<char>( inputFileStream ), istreambuf_iterator<char>() };
    yyscan_t lexer;
    if( yylex_init( &lexer ) ) {
        cerr << "Lexer initialization failed" << endl;
        return -4;
    }

    YY_BUFFER_STATE state = yy_scan_string( content.c_str(), lexer );

    if( command == C_PrintTokens ) {
        int lexerStatus = 0;
        do {
            lexerStatus = yylex( lexer );
        } while( lexerStatus != 0 );
    } else {
        yyparse( lexer );
    }
}
