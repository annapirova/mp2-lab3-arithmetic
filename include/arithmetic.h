// объ€вление функций и классов дл€ вычислени€ арифметических выражений
#include "stack.h"
#include <string>
#include <vector>
#include <iostream>

using namespace std;

struct lexema
{
	string val;
	int type;
	double x;
	lexema()
	{
		x = 0.0;
		val = "\0";
		type = -100;
	}
	lexema(string s, int t = -100)
	{
		val = s;
		type = t;
	}
	lexema(char s, int t = -100)
	{
		val = s;
		type = t;
	}
};

class Arithmetic
{
	string input;
	double result;
	vector<lexema> inp_lex;
	vector<lexema> pol_lex;
	int status;

	void enter();
	void split();
	int check_bkt();
	vector<int> check_symbols();
	bool isCorrect();
	void converter();
	void set_values();
	void calculate();

public:
	void launch();
	Arithmetic(string str = "");
	

};