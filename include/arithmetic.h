#ifndef __ARITHMETIC_H__
#define __ARITMETIC_H__
#include <string> 
#include <ctype.h>
#include <cmath>
#include "stack.h"

using namespace std;

class arithmetic
{
	string formula, post;
	double x;

	Stack <char> s;
	Stack <double> StNum;

public:
	
void SetFormula(string str)
		{
			formula = '(' + str + ')';
		}
int CheckFormula()
		{
			for (int i = 0; i < formula.size(); i++)
			{
				if (formula[i] == '(')
					s.push('(');
				if (formula[i] == ')')
				{
					if (true==s.IsEmpty())
						return 0;
					else
						s.pop();
				}
			}
			if (true!=s.IsEmpty())
				return 0;
			else
				return 1;
		}
	int IsOperator(char ch)
		{
			if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^')
				return 1;
			
			return 0;
		}

	int Prioritet(char ch)
		{
			if (ch == '+' || ch == '-')
				return 1;
			else 
				if (ch == '*' || ch == '/')
					return 2;
			if (ch == '^')
				return 3;
			else
				if (ch == '(')
					return 0;
		}
	int IsDouble(char ch)
		{
			if (ch == '.' || ch == ',')
				return 1;

			return 0;
		}

};
#endif