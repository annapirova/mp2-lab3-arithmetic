#include "arithmetic.h"

Lexem::Lexem(char* s, int k)
{
	strncpy_s(str, s, k);
	str[k] = '\0';

	if (k == 1)
	{
		if (isalpha(str[0]))
			type = 4;

		else
			if (isdigit(str[0]))
			{
				type = 2;
				Lex = atof(str);
			}
			else
			{
				switch (str[0])
				{
				case '(': type = 0;
					Pr = 0;
					break;
				case ')': type = 1;
					break;
				case '+': type = 3;
					Pr = 1;
					break;
				case '-': type = 3;
					Pr = 1;
					break;
				case '*': type = 3;
					Pr = 2;
					break;
				case '/': type = 3;
					Pr = 2;
					break;
				default: type = -1;
					break;
				}
			}
	}
	else if (k != 1)
	{
		type = 2;
		Lex = atof(str);
	}
}

Lexem::Lexem(const Lexem& l)
{
	strcpy_s(str, l.str);

	type = l.type;
	Lex = l.Lex;
	Pr = l.Pr;
}

Lexem Lexem::operator=(const Lexem& l)
{
	strcpy_s(str, l.str);

	type = l.type;
	Lex = l.Lex;
	Pr = l.Pr;

	return *this;
}

void Lexem::SetLex()
{
	cout << "Enter the value of" << str[0] << " : ";
	cin >> Lex;
	cout << endl;
}

arithmetic::arithmetic(char* s)
{
	Size = strlen(s);
	int k = 0; 
	pLexem = new Lexem[Size];
	for (int i = 0; i < Size; i++)
	{
		if (isdigit(s[i]))
		{
			int j = i; 
			while (isdigit(s[j]) || (s[j] == ','))
			{
				if (s[j] != '/0')
					j++;
			}
			pLexem[k] = Lexem(s + i, j - i);
			k++;
			i = j - 1;
		}
		else
		{
			pLexem[k] = Lexem(s + i, 1);
			k++;
		}
	}
	nLexems = k;

	for (int i = 0; i < nLexems; i++)
	{
		if (pLexem[i].type == 4)
		{
			pLexem[i].SetLex();
			for (int j = i + 1; j < nLexems; j++)
			{
				if (pLexem[i].str[0] == pLexem[j].str[0])
				{
					pLexem[j].Lex = pLexem[i].Lex;
					pLexem[j].type = 2;
				}
			}
			pLexem[i].type = 2;
		}
	}

	for (int i = 0; i < nLexems - 3; i++)
	{
		if ((pLexem[i].type == 0) && (pLexem[i + 1].str[0] == '-') && (pLexem[i + 2].type == 2))
		{
			pLexem[i + 2].Lex = 0 - pLexem[i + 2].Lex;
			for (int j = i + 1; j < nLexems - 1; j++)
			{
				pLexem[j] = pLexem[j + 1];
			}
			nLexems--;
		}
	}

	for (int i = 0; i < 1; i++)
	{
		if ((pLexem[i].str[0] == '-') && (pLexem[i + 1].type == 2))
		{

			pLexem[i + 1].Lex = 0 - pLexem[i + 1].Lex;
			for (int j = i; j < nLexems - 1; j++)
			{
				pLexem[j] = pLexem[j + 1];
			}
			nLexems--;
		}
	}

	for (int i = 0; i < nLexems - 3; i++)
	{
		if ((pLexem[i].type == 0) && (pLexem[i + 1].str[0] == '-') && (pLexem[i + 2].type == 4))
		{
			pLexem[i + 2].SetLex();
			pLexem[i + 2].type = 2;
			pLexem[i + 2].Lex = 0 - pLexem[i + 2].Lex;
			for (int j = i + 1; j < nLexems - 1; j++)
			{
				pLexem[j] = pLexem[j + 1];
			}
			nLexems--;
		}
	}

	for (int i = 0; i < 1; i++)
	{
		if ((pLexem[i].str[0] == '-') && (pLexem[i + 1].type == 4))
		{
			pLexem[i + 1].SetLex();
			pLexem[i + 1].type = 2;
			pLexem[i + 1].Lex = 0 - pLexem[i + 1].Lex;
			for (int j = i; j < nLexems - 1; j++)
			{
				pLexem[j] = pLexem[j + 1];
			}
			nLexems--;
		}
	}
}

arithmetic::arithmetic(const arithmetic& a)
{
	Size = a.Size;
	nLexems = a.nLexems;

	pLexem = new Lexem[Size];
	for (int i = 0; i < nLexems; i++)
		pLexem[i] = a.pLexem[i];

}

arithmetic::~arithmetic()
{
	delete[] pLexem;
}

arithmetic& arithmetic::operator +=(const Lexem a)
{
	int size = this->GetNLexems();
	pLexem[size] = a;
	nLexems += 1;

	return *this;
}

arithmetic& arithmetic::operator =(const arithmetic& a)
{
	Size = a.Size;
	nLexems = a.nLexems;

	pLexem = new Lexem[Size];
	for (int i = 0; i < nLexems; i++)
		pLexem[i] = a.pLexem[i];

	return (*this);
}

arithmetic arithmetic::PolishEntry()
{
	arithmetic res(*this);
	res.nLexems = 0;
	Stack<Lexem> s1;
	int k = 0;

	for (int i = 0; i < nLexems; i++)
	{
		if ((pLexem[i].type == 2) || (pLexem[i].type == 4))
			res += pLexem[i];

		/*if (pLexem[i].type == 0)
		{
			s1.Push(pLexem[i]);
		}*/

		if (pLexem[i].type == 3)
		{
			if (s1.IsEmpty())
				s1.Push(pLexem[i]);
			else
			{
				Lexem x = s1.Top();
				if (x.Pr > pLexem[i].Pr)
				{
					res += x;
					x = s1.Top();
				}

				while (x.Pr <= pLexem[i].Pr)
				{
					x = s1.Pop();
					res += x;
					s1.Push(pLexem[i]);
				}
			}
		}

		if (pLexem[i].type == 0)
		{
			s1.Push(pLexem[i]);
		}
		if (pLexem[i].type == 1)
		{
			Lexem x = s1.Pop();
			while (x.type != 0)
			{
				res += x;
				x = s1.Pop();
			}
		}
	}

	while (!s1.IsEmpty())
	{
		Lexem x = s1.Pop();
		res += x;
	}

	return res;
}

double arithmetic::CalculatePolishEntry()
{
	Stack<double> s1;
	double a, b, res = 0.0;

	for (int i = 0; i < nLexems; i++)
	{
		if (pLexem[i].type == 2)
		{
			s1.Push(pLexem[i].Lex);
		}

		if (pLexem[i].type == 3)
		{
			a = s1.Pop();
			b = s1.Pop();

			if (pLexem[i].str[0] == '+') { s1.Push(a + b); }
			if (pLexem[i].str[0] == '-') { s1.Push(b - a); }
			if (pLexem[i].str[0] == '*') { s1.Push(a * b); }
			if (pLexem[i].str[0] == '/') { s1.Push(b / a); }
		}
	}
	return s1.Pop();
}

bool arithmetic::CheckBracket()
{
	int k = 0;

	for (int i = 0; i < nLexems; i++)
	{
		if (pLexem[i].type == 0)
			k++;

		if (pLexem[i].type == 1)
			k--;
	}

	if (k != 0)
	{
		cout << " Error." << endl;
		return 0;
	}
	else
	{
		return 1;
	}
}

bool arithmetic::CheckLetters()
{
	int check = 0;
	for (int i = 0; i < nLexems; i++)
	{
		if (pLexem[i].type == 0)
		{
			cout << " Error" << endl;
			check++;
		}
	}

	for (int i = 0; i < nLexems - 1; i++)
	{
		if ((pLexem[i].type == 4) && (pLexem[i + 1].type == 4))
		{
			int k = 1;
			for (int j = i + 2; j < nLexems - 1; j++)
			{
				if (pLexem[j].type != 4)
				{
					j = nLexems;
				}
				k++;
			}
			cout << "Error" << endl;
			i = i + k;
			check++;
		}
	}

	if (check != 0)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}

bool arithmetic::CheckOperator()
{
	int check = 0;
	for (int i = 1; i < nLexems; i++)
	{
		if ((pLexem[i].type == 3) && (pLexem[i - 1].type == 3))
		{
			cout << " Error " << endl;
			check++;
		}
	}

	{
		int n = 0;
		int m = 0;

		for (int i = 0; i < nLexems; i++)
		{
			if (pLexem[i].type == 3)
			{
				n++;
			}
			if ((pLexem[i].type == 4) || (pLexem[i].type == 2))
			{
				m++;
			}
		}
		if (n > m - 1)
		{
			cout << " Error " << endl;
			check++;
		}
	}

	for (int i = 1; i < nLexems; i++)
	{
		if ((pLexem[i].type == 1) && (pLexem[i - 1].type == 3))
		{
			cout << " Error " << endl;
			check++;
		}

	}

	if ((pLexem[nLexems - 1].type == 1) && (pLexem[nLexems].type == 3))
	{
		cout << " Error " << endl;
		check++;
	}


	for (int i = 1; i < nLexems; i++)
	{
		if ((pLexem[i - 1].type == 0) && (pLexem[i].type == 3))
		{
			cout << " Error " << endl;
			check++;
		}
	}

	if ((pLexem[1].type == 0) && (pLexem[0].type == 3))
	{
		cout << " Error. " << endl;
		check++;
	}

	if (check != 0)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}

bool arithmetic::CheckPoint()
{
	int check = 0;
	for (int i = 1; i < nLexems; i++)
	{
		if ((pLexem[i].type == 4) && (pLexem[i - 1].str[0] == ','))
		{
			cout << " Error " << endl;
			check++;
		}

		if ((pLexem[i - 1].type == 4) && (pLexem[i].str[0] == ','))
		{
			cout << " Error " << endl;
			check++;
		}
	}

	for (int i = 1; i < nLexems; i++)
	{
		if ((pLexem[i].type == 1) && (pLexem[i - 1].str[0] == ','))
		{
			cout << " Error " << endl;
			check++;
		}
	}

	for (int i = 0; i < nLexems - 1; i++)
	{
		if ((pLexem[i].type == 1) && (pLexem[i + 1].str[0] == ','))
		{
			cout << " Error" << endl;
			check++;
		}
	}

	for (int i = 1; i < nLexems; i++)
	{
		if ((pLexem[i].type == 0) && (pLexem[i - 1].str[0] == ','))
		{
			cout << " Error " << endl;
			check++;
		}
	}

	for (int i = 0; i < nLexems - 1; i++)
	{
		if ((pLexem[i].type == 0) && (pLexem[i + 1].str[0] == ','))
		{
			cout << " Error " << endl;
			check++;
		}
	}

	if (check != 0)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}

char arithmetic::GetCharLexem(int n)
{
	char res;
	res = pLexem[n].str[0];
	return res;
}