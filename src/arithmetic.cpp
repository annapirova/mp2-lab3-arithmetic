// реализация функций и классов для вычисления арифметических выражений


#include "arithmetic.h"
#include <iostream>

using namespace std;

Lexem::Lexem()
{
	type = UNK;
	val = 0;
}

Lexem::Lexem(const char c)
{
	if (isalpha(c))
	{
		type = VAR;
		val = c;
	}
	else
	{
		val = operators.find(c);
		switch (operators.find(c))
		{
		case 0:
			type = OP_BR;
			break;
		case 5:
			type = CL_BR;
			break;
		}
		if ((val >= 0) && (val <= 5))
		{
			if ((val > 0) && (val < 5))
				type = OPER;
		}
		else
			type = UNK;
	}
}

Lexem::Lexem(const string& str)
{
	val = stod(str);
	type = VAL;
}

Lexem::Lexem(const Lexem &t)
{
	val = t.val;
	type = t.type;
}

int Lexem::priority()
{
	int pr;
	if (val == 0)
		pr = 0;
	else
	{
		if ((val > 0) && (val <= 2))
			pr = 2;
		else
			pr = 1;
	}
	return pr;
}

Lexem& Lexem::operator=(const Lexem &L)
{
	val = L.val;
	type = L.type;
	return *this;
}

void Lexem::nVar()
{
	char n = (char)val;
	cout << "input variable " << n << " : ";
	cin >> val;
}

string Arithmetic::Strdelspace(const string& s)
{
	string tmp = s;
	for (int i = 0; i < tmp.length(); i++)
		if (tmp[i] == ' ')
			tmp.erase(i, 1);//удаление с i
	return tmp;
}

Arithmetic::Arithmetic(const string& s)
{
	string tmp;
	tmp = Strdelspace(s);
	tmp = Minus(s);
	Lexems = new Lexem[tmp.length()];
	plLexems = new Lexem[tmp.length()];
	str = tmp;
	nLexems = 0;
	nplLexems = 0;
}

void Arithmetic::DivideToLexems()
{
	int L = str.length();
	for (int i = 0; i < L; i++)
	{
		char c = str[i];
		if ((operators.find(c) != string::npos) || (isalpha(c))) // operators
		{
			Lexem T(c);
			Lexems[nLexems] = T;
			nLexems++;
		}
		else
			if (isdigit(c))
			{
				string v;
				int j = i;
				while ((j < L) && (isdigit(str[j]) || (str[j] == '.')))
					j++;
				v = str.substr(i, j - i);
				if (CheckPoints(v))
				{
					Lexem t(v);
					Lexems[nLexems] = t;
					nLexems++;
				}
				else
				{
					Lexems[nLexems].type = UNK;
					nLexems++;
				}
				i = j - 1;
			}
			else
			{
				Lexems[nLexems].type = UNK;
				nLexems++;
			}
	}
}

void Arithmetic::ifVariable()
{
	for (int i = 0; i < nLexems; i++)
	{
		if (Lexems[i].type == VAR)
		{
			char c = (char)Lexems[i].val;
			Lexems[i].nVar();
			Lexems[i].type = VAL;
			for (int j = i + 1; j < nLexems; j++)
			{
				if ((Lexems[j].type == VAR) && (c == (char)Lexems[j].val))
					Lexems[j] = Lexems[i];
			}
		}
	}
}

void Arithmetic::PolishNotation() //
{
	Stack<Lexem> st;
	Stack<int> k;
	k.push(0);
	for (int i = 0; i < nLexems; i++)
	{
		int l = st.getIndex();
		switch (Lexems[i].type)
		{
		case VAL:
		{
			plLexems[nplLexems] = Lexems[i];
			nplLexems++;
			break;
		}
		case OP_BR:
		{
			st.push(Lexems[i]);
			k.push(st.getIndex());
			break;
		}
		case OPER:
		{
			if (st.IsEmpty() || (st.view().priority() < Lexems[i].priority()))
				st.push(Lexems[i]);
			else
			{
				plLexems[nplLexems] = st.pop();
				nplLexems++;
				st.push(Lexems[i]);
			}
			break;
		}
		case CL_BR:
		{
			for (int j = k.view(); j < l; j++)
			{
				plLexems[nplLexems] = st.pop();
				nplLexems++;
			}
			st.pop();
			k.pop();
			break;
		}
		}
	}
	if (!st.IsEmpty())
	{
		while (!st.IsEmpty())
		{
			plLexems[nplLexems] = st.pop();
			nplLexems++;
		}
	}
}

double Arithmetic::Calculate()
{
	Stack<double> st;
	for (int i = 0; i < nplLexems; i++)
	{
		if (plLexems[i].type == VAL)
			st.push(plLexems[i].val);
		else
		{
			double a = st.pop(), b = st.pop();
			switch ((int)plLexems[i].val)
			{
			case 1:
				st.push(b / a);
				break;
			case 2:
				st.push(b * a);
				break;
			case 3:
				st.push(b - a);
				break;
			case 4:
				st.push(b + a);
				break;
			}
		}
	}
	return st.pop();
}

int Arithmetic::CheckPoints(const string& s)
{
	int l = s.length(), k = 0;
	bool flag = true;

	for (int i = 0; i < l; i++)
		if (s[i] == '.')
			k++;

	if ((str[0] == '.') || (s[l] == '.') || (k > 1))
		flag = false;
	return flag;
}

int Arithmetic::CheckBrackets()
{
	bool f = true;
	if (str == "")
		f = false;
	else
	{
		int br = 0, k = 0;


		for (int i = 0; i < nLexems && br >= 0; i++)
		{
			if (Lexems[i].type == OP_BR)
			{
				br++;
				k = i;
			}
			if (Lexems[i].type == CL_BR)
			{
				br--;
				k = i;
			}
		}
		if (br != 0)
			f = false;
	}
	return f;
}


int Arithmetic::CheckOperators()
{
	bool flag = true;
	if (!((Lexems[0].type == OP_BR) || (Lexems[0].type == VAL) || (Lexems[0].type == VAR) || (Lexems[0].val == 2)))
	{
		cout << "error" << endl;
		flag = false;
	}

	for (int i = 0; i < nLexems - 1; i++)
	{
		switch (Lexems[i].type)
		{
		case OP_BR:
			if (!((Lexems[i + 1].type == OP_BR) || (Lexems[i + 1].type == VAL) || (Lexems[i + 1].type == VAR) || (Lexems[i + 1].val == 2)))
			{
				cout << "error" << endl;
				flag = false;
			}
			break;
		case VAL:
			if (!((Lexems[i + 1].type == OPER) || (Lexems[i + 1].type == CL_BR)))
			{
				cout << "error" << endl;
				flag = false;
			}
			break;
		case VAR:
			if (!((Lexems[i + 1].type == OPER) || (Lexems[i + 1].type == CL_BR)))
			{
				cout << "error" << endl;
				flag = false;
			}
			break;
		case OPER:
			if (!((Lexems[i + 1].type == VAL) || (Lexems[i + 1].type == VAR) || (Lexems[i + 1].type == OP_BR)))
			{
				cout << "error" << endl;
				flag = false;
			}
			break;
		case CL_BR:
			if (!((Lexems[i + 1].type == OPER) || (Lexems[i + 1].type == VAR) || (Lexems[i + 1].type == CL_BR)))
			{
				cout << "error" << endl;
				flag = false;
			}
			break;
		}
	}

	if (!((Lexems[nLexems - 1].type == CL_BR) || (Lexems[nLexems - 1].type == VAL) || (Lexems[nLexems - 1].type == VAR)))
	{
		cout << "error" << nLexems << endl;
		flag = false;
	}
	return flag;

}

string Arithmetic::Minus(const string& s)
{
	string tmp;
	tmp = Strdelspace(s);
	if (tmp != "")
	{
		if (tmp[0] == '-')
			tmp = "0" + tmp;
		for (int i = 0; i < tmp.length() - 1; i++)
		{
			if ((tmp[i] == '(') && (tmp[i + 1] == '-'))
				tmp.insert(i + 1, "0");
		}
	}
	return tmp;
}