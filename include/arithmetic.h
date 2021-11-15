#ifndef _ARITHMETIC_H_
#define _ARITHMETIC_H_
#include "stack.h"
#include <string>

class Arithmetic
{
private:
    
public:
    string s;
    string* Lex_in;
    string polish;
    int type;
    Stack<char> res;
    Stack<char> operation;
    int size;

    void divided_lex();
    bool check_brackets();
    //int check_formula();
    int prioritet(string s);
    void polsk_zap();
    bool calculating();
};

#endif