#include "arithmetic.h"

/*-----------------------------struct Lexem---------------------------- - */
Lexem::Lexem(string& c1, LexType t1)
{
	c = c1;
	t = t1;
}

Lexem::Lexem(const Lexem& c1)
{
	c = c1.c;
	t = c1.t;
}

Lexem& Lexem::operator=(const Lexem& c1)
{
	c = c1.c;
	t = c1.t;
	return *this;
}

bool Lexem::operator==(const Lexem& c1) const
{
	if ((c1.c == c) && (c1.t == t))
		return true;
	else
		return false;
}

bool Lexem::operator!=(const Lexem& c1) const
{
	return !(*this == c1);
}
/*------------------------------------------------------------------------*/
/*---------------------------class Arithmetic-----------------------------*/
Arithmetic::Arithmetic(const string& inputstr1)
{
	inputstr = inputstr1;
	lexems = new Lexem[inputstr.length()];
	nLex = 0;
	divide();
}

Arithmetic::~Arithmetic()
{
	delete[] lexems;
}

Arithmetic& Arithmetic::operator=(const Arithmetic& inputstr2)
{
	inputstr = inputstr2.inputstr;
	nLex = inputstr2.nLex;
	delete[] lexems;
	lexems = new Lexem[nLex];
	for (int i = 0; i < nLex; i++)
		lexems[i] = inputstr2.lexems[i];
	return *this;
}

bool Arithmetic::operator==(const Arithmetic& inputstr2) const
{
	if ((inputstr == inputstr2.inputstr) && (nLex == inputstr2.nLex))
		return true;
	else
		return false;
}

bool Arithmetic::checkBrackets()
{

	int len = inputstr.length();
	bool res = true;
	TStack<int> st(len);
	for (int i = 0; i < len; i++)
	{
		if (inputstr[i] == '(')
		{
			st.Push(i + 1);
		}
		else
		{
			if (inputstr[i] == ')')
			{
				if (!(st.IsEmpty()))
					st.Pop();
				else
					res = false;
			}
		}
	}
	return res;
}

bool Arithmetic::checkSymbols()
{
	for (int i = 0; i < nLex; i++)
	{
		if (lexems[i].t == UNKNOWN)
		{
			cout << "Nedopustimue symvolu" << endl;
			cout << ' ' << lexems[i].c << endl;
			return false;
		}
		else
			if (lexems[i].t == VALUE)
			{
				int k = 0;
				for (int j = 0; j < lexems[i].c.length(); j++)
					if (lexems[i].c[i] == '.')
						k++;
				if (k > 1 || lexems[i].c[0] == '.' || lexems[i].c[lexems[i].c.length() - 1] == '.')
				{
					cout << "Nedopustimue symvolu" << endl;
					cout << ' ' << lexems[i].c << endl;
					return false;
				}
			}
	}
	return true;
}
bool Arithmetic::checkFormula()
{
	int pos = -1;

	if (!(lexems[0].t == VALUE || lexems[0].t == LEFT_BRACKET || lexems[0].c[0] == '-' || lexems[0].t == RIGHT_BRACKET))
	{
		return false;
	}

	if (lexems[inputstr.length() - 1].t == OPERATION)
	{
		cout << "error" << endl;
		return false;
	}

	for (int i = 0; i < nLex - 1; i++)
	{
		pos += lexems[i].c.length();

		if ((lexems[i].t == RIGHT_BRACKET || lexems[i].t == VALUE) && (lexems[i + 1].t == LEFT_BRACKET || lexems[i + 1].t == VALUE))
		{
			cout << "error" << endl;
			return false;
		}

		if (lexems[i].t == LEFT_BRACKET && ((lexems[i + 1].t == OPERATION || lexems[i + 1].c[0] == '-') || lexems[i + 1].t == RIGHT_BRACKET))
		{
			cout << "error" << endl;
			return false;
		}
		if (lexems[i].t == OPERATION && (lexems[i + 1].t == OPERATION || lexems[i + 1].t == RIGHT_BRACKET))
		{
			cout << "error" << endl;
			return false;
		}
	}
	return true;
}
void Arithmetic::divide()
{
	for (int i = 0; i < inputstr.length(); i++)
	{
		char c1 = inputstr[i];
		const string oper = "+-*/^()";
		int pos = oper.find(c1);
		if (pos != string::npos)
		{
			if (pos < 5)
				lexems[nLex].t = OPERATION;
			else
				if (pos == 5)
					lexems[nLex].t = LEFT_BRACKET;
				else
					if (pos == 6)
						lexems[nLex].t = RIGHT_BRACKET;
			lexems[nLex].c = c1;
			nLex++;
		}
		else
			if (isdigit(c1))
			{
				int j = i;
				while (j < inputstr.length() && (isdigit(inputstr[j]) || inputstr[j] == '.'))
					j++;
				lexems[nLex].c = inputstr.substr(i, j - i);
				i = j - 1;
				lexems[nLex].t = VALUE;
				nLex++;
			}
			else
			{
				lexems[nLex].t = UNKNOWN;
				lexems[nLex].c = c1;
				nLex++;
			}
	}
}
bool Arithmetic::prioritet(Lexem a, Lexem b)
{
	switch (a.c[0])
	{
	case '(':
		return 0;
		break;
	case '+':
		return 1;
		break;
	case '-':
		return 1;
		break;
	case '*':
		return 2;
		break;
	case '/':
		return 2;
		break;
	case '^':
		return 3;
		break;
	}
}

int Arithmetic::PolZap(Lexem* lex)
{
	LexType t1;
	int j = 0;
	Lexem z;
	z.t = VALUE;
	z.c = "0";
	TStack<Lexem> s(nLex);
	for (int i = 0; i < nLex; i++)
	{
		t1 = lexems[i].t;
		if (t1 == OPERATION)
		{
			if (lexems[i].c[0] == '-' && (i == 0 || lexems[i - 1].c[0] == '('))
			{
				lex[j] = z;
				j++;
			}
			if (!s.IsEmpty() && !prioritet(lexems[i], s.Top()))
			{
				lex[j] = s.Pop();
				j++;
			}
			s.Push(lexems[i]);
		}
		if (t1 == LEFT_BRACKET)
		{
			s.Push(lexems[i]);
		}
		if (t1 == RIGHT_BRACKET)
		{
			while ((s.Top()).t != LEFT_BRACKET)
			{
				lex[j] = s.Pop();
				j++;
			}
			s.Pop();
		}
		if (t1 == VALUE)
		{
			lex[j] = lexems[i];
			j++;
		}
	}
	while (!s.IsEmpty())
	{
		lex[j] = s.Pop();
		j++;
	}
	return j;
}

double Arithmetic::Calcul()
{
	Lexem* lex = new Lexem[2 * nLex];
	int p = PolZap(lex);
	TStack<double> res(2 * p);
	for (int i = 0; i < p; i++)
		if (lex[i].t == VALUE)
			res.Push(stod(lex[i].c));
		else
		{
			double a = res.Pop(), b = res.Pop();
			switch (lex[i].c[0])
			{
			case '+':
				res.Push(a + b);
				break;
			case '-':
				res.Push(b - a);
				break;
			case '*':
				res.Push(b * a);
				break;
			case '/':
				res.Push(b / a);
				break;
			case '^':
				int op;
				op = (int)a;
				int count = 1;
				while (op > count)
				{
					if (op == 0)
						res.Push(1);
					else if ((op != 1) && (op > 0))
						res.Push(b * b);
					count++;
				}
				break;
			}
		}
	return res.Top();
}