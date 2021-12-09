#ifndef _ARITHMETIC_H_
#define _ARITHMETIC_H_

#include "stack.h"
#include <iostream>
#include <string>

using namespace std;


class Arithmetic
{
private:
    string s;
    string lex;
    string r;
    int size;
public:

    

    bool CheckBrackets(char* s);  //+
    bool CheckOperations_StandTogether(char* s); //+
    bool CheckOperations_StartsWithOP(char* s); //+
    bool CheckOperations_UnknownSymbols(char* s); //+

    void string1()
    {
        string s;
        cout << "Enter an expression:\n";
        getline(cin, s);
    }
    void Lexems(); //+
    int Prioritet(char s); //+
    void PolishZap(); //+
    double Calculating();  //+
};
#endif // !_ARITHMETIC_H_