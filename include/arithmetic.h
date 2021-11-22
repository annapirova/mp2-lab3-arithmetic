// объ€вление функций и классов дл€ вычислени€ арифметических выражений
#include "stack.h"
#include <string>
#include <cstring>
#include <cstdlib>
#include <cctype>
#include <iostream>

using namespace std;

enum Lextype { open_br, close_br, var, val, oper };

class Lexem // лексем
{
	string s;
	Lextype type;
public:
	Lexem() {};

	string getstr() 
	{ 
		return s;
	}

	Lextype gettypy() 
	{ 
		return type;
	}

	Lexem& operator=(const Lexem& l);
	bool operator==(const Lexem& l);

	void setlex(string s1) 
	{ 
		s = s1; 
	}

	void settype(Lextype t) 
	{ 
		type = t; 
	}
	int priority();
};

class Variable // переменна€ и значение
{
	string name;
	double value;
public:
	Variable() {};
	string getname()
	{
		return name;
	}

	Variable& operator=(const Variable& v);

	void setvalue(double v) { 
		value = v; 
	};

	double getvalue() 
	{ 
		return value; 
	};
	
	void setname(string a) 
	{ 
		name = a; 
	}
};

class Arithmetic
{
	string s;

	Lexem* lexem;
	int nLexem;

	Lexem* polish;
	int nPolish;

	Variable* vars;
	int nVars;
public:
	Arithmetic(string str);
	int check();
	double calculate();
	void Polish();
};