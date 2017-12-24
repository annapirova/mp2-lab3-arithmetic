// объявление функций и классов для вычисления арифметических выражений

#include <iostream>
#include <string>
#include "stack.h"
#include <cctype>

using namespace std;

enum  LexType { OP_BR, CL_BR, VAL, OPER, VAR, UNK };

const string operators = "(/*-+)";

struct Lexem
{
	LexType type;
	double val;

	Lexem();
	Lexem(const char c);
	Lexem(const string& str);
	Lexem(const Lexem &t);// конструктор копирования
	Lexem& operator=(const Lexem &t);
	~Lexem() { };
	int priority(); 
	void nVar(); // ввод значения переменной
	double GetVal() { return val; }
};


class Arithmetic
{
	string str;
	Lexem* Lexems;
	int nLexems; 

	Lexem* plLexems; // массив в виде польской записм
	int nplLexems; // к-во лексем в польской записи

public:
	Arithmetic(const string& str);
	~Arithmetic() { delete[] Lexems; delete[] plLexems; }

	double GetValLexems(const int i) { return Lexems[i].val; }
	double GetValplLexems(const int i) { return plLexems[i].val; }

	string Strdelspace(const string& s);

	void DivideToLexems();
	void ifVariable();

	void PolishNotation();
	double Calculate();

	int CheckBrackets();
	int CheckOperators();
	int CheckPoints(const string& str);
	string Minus(const string& s);
};
