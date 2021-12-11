// îáúÿâëåíèå ôóíêöèé è êëàññîâ äëÿ âû÷èñëåíèÿ àðèôìåòè÷åñêèõ âûðàæåíèé
#pragma once

#include <iostream>
#include <string>
#include "stack.h"

using namespace std;

enum LexType { LEFT_BRACKET, RIGHT_BRACKET, OPERATION, VALUE, UNKNOWN };

//const string znaky = "+-*/()";

struct Lexem
{
	string c;
	LexType t;
	Lexem()
	{
		c = "";
	}
	Lexem(string& c1)
	{
		c = c1;
	}
	Lexem(string& c1, LexType t1);
	Lexem(const Lexem& c1);
	Lexem& operator=(const Lexem& c1);
	bool operator==(const Lexem& c1) const;
	bool operator!=(const Lexem& c1) const;
};

class Arithmetic
{
	string inputstr;
	Lexem* lexems;
	int nLex;
public:
	Arithmetic(const string& inputstr1);
	~Arithmetic();
	Arithmetic& operator=(const Arithmetic& inputstr2);
	bool operator==(const Arithmetic& inputstr2) const;

	bool checkBrackets();
	bool checkSymbols();
	bool checkFormula();
	void divide();
	bool prioritet(Lexem a, Lexem b);
	int PolZap(Lexem* lex);
	double Calcul();
};