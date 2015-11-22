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
	double a,b,c,d ;

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
	int isNumber(char ch)
	{
		if (isdigit(ch) || ch == '.' || ch == ',')
			return 1;

		return 0;
	}

	int IsLetter(char ch)
		{
			if (isalpha(ch) )
				return 1;
			return 0;
		}

	void InfixToPost()
	{
		char tmp;

		for (int i = 0; i < formula.size(); i++)
		{ 
			if (isNumber(formula[i])) 
			{
				post += formula[i];
				while (isNumber(formula[i+1]))
				{
					post += formula[i + 1];
					i++;
				}
				post += ' ';
			}
			if (IsLetter(formula[i]))
			{
				post += formula[i];
				post += ' ';
			}
			else
				if (formula[i] == '(')
					s.push('(');
				else
					if (formula[i] == ')')
					{

						tmp = s.pop();

						while (tmp != '(')
						{
							post += tmp;
							tmp = s.pop();
							post += ' ';
						}
					}
					else
						if (IsOperator(formula[i]))
						{
				
							tmp = s.Peek();

							while (Prioritet(tmp) >= Prioritet(formula[i]))//&& !s.IsEmpty())
							{
								post += s.pop();
								post += ' ';
								tmp = s.Peek();
							}
							s.push(formula[i]);
							
						}
		}
	}

	double Calc()
	{
		InfixToPost();

		if (CheckFormula())
		{
			for (int i = 0; i < post.size(); i++)
			{
				if (IsOperator(post[i]))
				{
					double tmp1, tmp2, res;

					tmp2 = StNum.pop();
					tmp1 = StNum.pop();

					if (post[i] == '+')
						res = tmp1 + tmp2;
					if (post[i] == '-')
						res = tmp1 - tmp2;
					if (post[i] == '*')
						res = tmp1 * tmp2;
					if (post[i] == '/')
						res = tmp1 / tmp2;
					if (post[i] == '^')
						res = pow(tmp1, tmp2);

					StNum.push(res);
				}
				if (isNumber(post[i]))
				{

					string NUM = "";
					double tmp;
					while (post[i] != ' ' && i < post.size())
					{
						NUM += post[i];
						i++;
					}
					tmp = stod(NUM);
					StNum.push(tmp);

				}
				if (IsLetter(post[i]))
				{
					if (post[i] == 'a') StNum.push(a);
					if (post[i] == 'b') StNum.push(b);
					if (post[i] == 'c') StNum.push(c);
					if (post[i] == 'd') StNum.push(d);
				}
			}
			return StNum.pop();
		}
		return 0;
	}

	string GetPost() { return post; }

	char GetSymbvolOfFormula(int i) { return post[i]; }

	void SetParamater(double _a, double _b, double _c, double _d) 
	{ a = _a; 
	  b = _b;
	  c = _c;
	  d = _d;
	}

};
#endif