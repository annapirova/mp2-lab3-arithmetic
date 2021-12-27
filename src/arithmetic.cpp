// реализация функций и классов для вычисления арифметических выражений

#include "../include/arithmetic.h"


string operations = "+*-/";
string openbrackets = "([";
string closebrackets = "])";
string squarebrackets = "[]";
string roundbrackets = "()";

Variable& Variable::operator = (const Variable& v)
{
	name = v.name;
	value = v.value;
	return *this;
}

Lexem& Lexem::operator = (const Lexem& l)
{
	s = l.s;
	type = l.type;
	return *this;
}

bool Lexem::operator == (const Lexem& l)
{
	if (l.type != type)
		return false;
	else
	{
		if (s != l.s)
			return false;
		return true;
	}
}

int Lexem::priority()
{
	int p;
	if (s == "(")
		p = 0;
	if ((s == "+") || (s == "-"))
		p = 1;
	if ((s == "*") || (s == "/"))
		p = 2;
	return p;
}

Arithmetic::Arithmetic(string str)
{
	s = str;
	size_t p, p1, p2, p3;
	lexem = new Lexem[s.size()];
	vars = new Variable[10];
	nLexem = 0;
	nVars = 0;
	int nbr = 0;
	int i = 0;
	//разбиение на лексемы
	while (i < s.size())
	{
		//открывающие скобки
		p1 = openbrackets.find(s[i]);
		if (p1 != std::string::npos)
		{
			string opbrs;
			opbrs = s[i];
			lexem[nLexem].setlex(opbrs);
			lexem[nLexem].settype(open_br);
			nLexem += 1;
			nbr += 1;
			i++;
			continue;
		}
		//закрывающие скобки
		p2 = closebrackets.find(s[i]);
		if (p2 != std::string::npos)
		{
			string clbrs;
			clbrs = s[i];
			lexem[nLexem].setlex(clbrs);
			lexem[nLexem].settype(close_br);
			nLexem += 1;
			nbr += 1;
			i++;
			continue;
		}
		//операции +*-/
		p3 = operations.find(s[i]);
		if (p3 != std::string::npos)
		{
			string ops;
			ops = s[i];
			lexem[nLexem].setlex(ops);
			lexem[nLexem].settype(oper);
			nLexem += 1;
			i++;
			continue;
		}
		//переменные
		if (isalpha(s[i]) != 0)
		{
			nVars += 1;
			char a[10];
			string as;
			int j = 0;
			while ((i < s.size()) && (isalpha(s[i]) != 0))
			{
				a[j] = s[i];
				j++;
				i++;
				if ((i < s.size()) && (s[i] == '['))
				{
					do
					{
						a[j] = s[i];
						i++;
						j++;
					} while (s[i] != ']');

					a[j] = s[i];
					j++;
					i++;
				}

			}
			i--;
			as = a;
			as.erase(j);
			vars[nVars - 1].setname(as);
			lexem[nLexem].setlex(as);
			lexem[nLexem].settype(var);
			nLexem += 1;
			i++;
			continue;
		}
		//цифры
		if (isdigit(s[i]) != 0)
		{
			char c[16];
			string cs;
			int j = 0;
			while ((isdigit(s[i]) != 0) || (s[i] == '.'))
			{
				c[j] = s[i];
				j++;
				i++;
				if (i >= s.size())
					break;
			}
			i--;
			cs = c;
			cs.erase(j);
			lexem[nLexem].setlex(cs);
			lexem[nLexem].settype(val);
			nLexem += 1;
			i++;
			continue;
		}
	}

	//создали поле для перевода в польскую
	polish = new Lexem[nLexem - nbr];
	nPolish = 0;
}
int Arithmetic::check()
{
	//проверка числа скобочек
	size_t p1, p2, p3, p4, p5, p6;
	Stack <char> S(100);
	for (int i = 0; i < s.length(); i++)
	{
		p1 = openbrackets.find(s[i]);
		p2 = closebrackets.find(s[i]);
		p3 = roundbrackets.find(s[i]);
		p6 = squarebrackets.find(s[i]);

		if (p1 != std::string::npos)
			S.push(s[i]);
		else
		{
			if (p2 != std::string::npos)
			{
				if (S.isempty() == true)
				{
					throw "Нельзя перед открытием поставить закрывающуюся скобку";
//					cout << "Нельзя перед открытием поставить закрывающуюся скобку";
//					return 0;
				}

				p4 = roundbrackets.find(S.top());
				p5 = squarebrackets.find(S.top());

				if (!(((p3 != std::string::npos) && (p4 != std::string::npos)) || ((p5 != std::string::npos) && (p6 != std::string::npos))))
				{
					throw "Нельзя поставить закрывающуюся скобку";
//					cout << "Нельзя поставить закрывающуюся скобку";
//					return 0;
				}
				else
					S.pop();
			}
		}
	}

	for (int i = 0; i < s.length(); i++)
	{
		if (i != (s.length() - 1))
		{
			p1 = operations.find(s[i]);
			p2 = operations.find(s[i + 1]);

			//Проверка выражений "(+","(*","(/" 
			if ((s[i] == '(') && (p2 != std::string::npos) && (s[i + 1] != '-'))
			{
				throw "Ошибка выражений (+,(*,(/";
//				cout << "Ошибка выражений (+,(*,(/";
//				return 0;
			}

			//Проверка выражений "-)","+)","/)","*)"
			if ((p1 != std::string::npos) && (s[i + 1] == ')'))
			{
				throw "Ошибка выражений -),+),/),*)";
//				cout << "Ошибка выражений -),+),/),*)";
//				return 0;
			}
		}

	}
	return 1;
}

void Arithmetic::Polish()
{
	Lexem c;
	Lexem x;
	Stack <Lexem> st;
	int i = 0;
	while (i < nLexem)
	{
		c = lexem[i];
		if ((c.gettypy() == val) || (c.gettypy() == var))
		{
			polish[nPolish] = c;
			nPolish += 1;
		}
		if (c.gettypy() == open_br)
			st.push(c);
		if (c.gettypy() == oper)
		{
			if (st.isempty())
				st.push(c);
			else
			{
				x = st.top();
				while (c.priority() <= x.priority())
				{
					x = st.pop();
					polish[nPolish] = x;
					nPolish += 1;
					if (!(st.isempty()))
						x = st.top();
					else break;
				}
				st.push(c);
			}
		}
		if (c.getstr() == ")")
		{
			x = st.pop();
			while (x.getstr() != "(")
			{
				polish[nPolish] = x;
				nPolish += 1;
				x = st.pop();
			}
		}
		i++;
	}
	while (!st.isempty())
	{
		x = st.pop();
		polish[nPolish] = x;
		nPolish += 1;
	}
}

double Arithmetic::calculate()
{	
	Stack <double> st;
	double res;
	double x;
	int nvar = 0;
	for (int i = 0; i < nPolish; i++)
	{
		if (polish[i].gettypy() == val)
		{
			x = atof(polish[i].getstr().c_str());
			st.push(x);
		}
		if (polish[i].gettypy() == var)
		{
			x = vars[nvar].getvalue();
			st.push(x);
			nvar += 1;
		}
		if (polish[i].gettypy() == oper)
		{
			double c, b = st.pop();
			double a = st.pop();
			if (polish[i].getstr() == "+")
				c = a + b;
			if (polish[i].getstr() == "-")
				c = a - b;
			if (polish[i].getstr() == "*")
				c = a * b;
			if (polish[i].getstr() == "/")
				c = a / b;
			st.push(c);
		}
	}
	res = st.pop();
	if (!st.isempty())
		throw "Ошибка";
	return res;
}

string unary_minus(string s)
{
	size_t p;
	if (s[0] == '-')
	{
		s.insert(0, "0");
	}
	for (int i = 1; i < s.length(); i++)
	{
		p = openbrackets.find(s[i - 1]);
		if ((s[i] == '-') && (p != std::string::npos))
		{
			s.insert(i, "0");
		}
	}
	return s;
}

void Arithmetic::set_vars()
{
	bool f = true;
	double tmp;
	for (int i = 0; i < nVars; i++) {
		f = true;
		for (int j = 0; (j < i) && (f); j++)
		{
			if (vars[i].getname() == vars[j].getname())
			{
				vars[i].setvalue(vars[j].getvalue());
				f = false;
			}
		}
		if (f)
		{
			string str = vars[i].getname();
			cout << "Введите значение переменной - " << str << endl;
			cin >> tmp;
			vars[i].setvalue(tmp);
		}
	}
}

void Arithmetic::print_polish()
{
	for (int i = 0; i < nPolish; i++)
		cout << polish[i].getstr() << "\n";
}

string Arithmetic::print_polish_1()
{
	string s;
	for (int i = 0; i < nPolish; i++)
		s += polish[i].getstr();
	return s;
}