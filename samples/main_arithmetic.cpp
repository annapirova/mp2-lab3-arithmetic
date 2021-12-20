// реализация пользовательского приложения

#include "arithmetic.h"
#include <sstream>


Lexema::Lexema(string V)
{
	Val = V;
	const int i = Val.size();
	if (i != 1)
	{
		Num = std::stod(Val); //Если число;
		type = 1;
	}
	else
	{
		
			if (isdigit(Val[0]))//Если число;
			{
				type = 1;
				Num = std::stod(Val);
			}
			else
			{
				switch (Val[0])//Если оператор;
				{
				case '(':
					Priority = 0;
					type = -1;
					Num = 0;
					break;
				case ')':
					Priority = 0;
					type = 0;
					Num = 0;
					break;
				case '+':
					Priority = 1;
					type = 2;
					Num = 0;
					break;
				case '-':
					Priority = 1;
					type = 2;
					Num = 0;
					break;
				case '*':
					Priority = 2;
					type = 2;
					Num = 0;
					break;
				case '/':
					Priority = 2;
					type = 2;
					Num = 0;
					break;
				}
			}
		}
	}

Lexema::Lexema(const Lexema& Lex)
{
	Val = Lex.Val;
	Priority = Lex.Priority;
	Num = Lex.Num;
	type = Lex.type;
}

int Lexema::operator==(const char& v) const
{
	if (Val[0] == v)
		return 1;
	else
		return 0;
}

int Lexema::operator!=(const char& v) const
{
	if (Val[0] == v)
		return 0;
	else
		return 1;
}

arithmetic::arithmetic(string str)
{
	Input = str;
	Size = 0;
	Polish = str;
	Res = 0.0;
	for (int i = 0; i < Input.size(); i++) //колечество лексем ;
	{
		if (Input[i] != ' ')
			Size++;
		if (Input[i] == '.')
			Input[i] = ',';
	}
	LexInput = new Lexema[Size];
	LexPolish = new Lexema[Size];
}


void arithmetic::BreakLexemes()//Разбить на Лексемы;
{
	int reg = 0;
	string Copystr;
	//LexInput = new Lexema[Size];


	for (int i = 0; i < Input.size(); i++)//заполнение массива Лексем;
	{
		{
		 Copystr = Input[i];
		 LexInput[reg] = Lexema(Copystr);
		 Copystr.clear();
		 reg++;
		}
	}
	Size = reg;

	int ind = 0;
	Lexema* CopyLexInput = new Lexema[Size];
	for (int k = 0; k < Size; k++)
		CopyLexInput[k] = LexInput[k];
	for (int i = 0; i < Size; i++)
	{
		if ((LexInput[ind] == '-') && ((LexInput[ind - 1]).type != 1) && LexInput[ind - 1] != ')')//выделяет отрицательные числа, как одну лексему;
		{
			CopyLexInput[i].Num = (-1) * CopyLexInput[i + 1].Num;
			CopyLexInput[i].Val = '-' + CopyLexInput[i + 1].Val;
			CopyLexInput[i].type = 1;
			for (int j = i; j < Size; j++)
			{
				if (j + 2 < Size)
					CopyLexInput[j + 1] = CopyLexInput[j + 2];
			}
			Size--;
			ind++;
		}
		if ((LexInput[ind] == '+') && (LexInput[ind - 1]).type != 1 && LexInput[ind - 1] != ')')
		{
			CopyLexInput[i].Val = CopyLexInput[i + 1].Val;
			CopyLexInput[i].type = 1;
			CopyLexInput[i].Num = CopyLexInput[i + 1].Num;
			for (int j = i; j < Size; j++)
			{
				if (j + 2 < Size)
					CopyLexInput[j + 1] = CopyLexInput[j + 2];
			}
			Size--;
			ind++;
		}
		ind++;
	}

	for (int k = 0; k < Size; k++)
		LexInput[k] = CopyLexInput[k];

	cout << endl << " Массив лексем: " << endl;
	for (int i = 0; i < Size; i++)
	{
		std::cout << "|" << LexInput[i] << "|" << "   ";
	}
}

void arithmetic::PolishLexemes()
{
	Stack<Lexema> stack(Size);
	int PolishIndex = 0;

	delete[] LexPolish;
	LexPolish = new Lexema[Size];

	for (int i = 0; i < Size; i++)
	{
		if (LexInput[i].type == 1)
		{
			LexPolish[PolishIndex] = LexInput[i];
			PolishIndex++;
		}
		if (LexInput[i].type == 2)
		{
			if (stack.isNotFull() == true)
			{
				stack.push(LexInput[i]);
			}
			else
			{
				if (stack.pop().Priority != 0)
				{

					while (LexInput[i].Priority <= stack.pop().Priority && stack.pop().Priority != 0)
					{
						if (stack.isNotFull() == false)
						{
							LexPolish[PolishIndex] = stack.getsize();
							PolishIndex++;
						}
						if (stack.Getcapasity() == 0)
							break;
					}

					stack.push(LexInput[i]);
				}

				if (LexInput[i].Priority > stack.pop().Priority && stack.pop().Priority != 0)
				{
					stack.push(LexInput[i]);

				}

				if (stack.pop().Priority == 0)
				{
					stack.push(LexInput[i]);
				}
			}
		}
		if (LexInput[i].type == -1)
		{
			stack.push(LexInput[i]);
		}
		if (LexInput[i].type == 0)
		{
			int index = stack.Getcapasity();
			for (int i = 0; i < index; i++)
			{
				if (stack.pop() != '(')
				{
					LexPolish[PolishIndex] = stack.getsize();
					PolishIndex++;
				}
				else
				{
					stack.getsize();
					index = i;
				}
			}
		}

	}

	if (stack.isNotFull() == false)
	{
		const int index2 = stack.Getcapasity();
		for (int i = Size - index2; i < Size; i++)
		{
			if (stack.pop() != '(' && stack.pop() != ')')
			{
				LexPolish[PolishIndex] = stack.getsize();
				PolishIndex++;
			}
		}
	}
	cout << endl << " Массив лексем в польской записи: " << endl;
	for (int i = 0; i < PolishIndex; i++)
	{
		std::cout << "|" << LexPolish[i] << "|" << "   ";

	}
	Size = PolishIndex;
}

double arithmetic::PolishLexemesSolution()
{
	Stack<double> stack(Size);
	int index = 0;
	double res = 0;
	while (index < Size)
	{
		if (LexPolish[index].type == 1)
		{
			stack.push(LexPolish[index].Num);
			//cout << endl << "вывожу число: " << LexPolish[index].Num << endl;
		}
		else
		{
			if (LexPolish[index] == '+')
			{
				double a = stack.getsize();
				double b = stack.getsize();
				stack.push(b + a);
				res = a + b;
			}
			if (LexPolish[index] == '-')
			{
				double a = stack.getsize();
				double b = stack.getsize();
				stack.push(b - a);
				res = b - a;
			}
			if (LexPolish[index] == '*')
			{
				double a = stack.getsize();
				double b = stack.getsize();
				stack.push(b * a);
				res = b * a;
			}
			if (LexPolish[index] == '/')
			{
				double a = stack.getsize();
				double b = stack.getsize();
				stack.push(b / a);
				res = b / a;
			}
		}
		index++;
		//cout << res << endl;
	}
	Res = stack.pop();
	cout << endl << " Ответ = " << Res << endl;
	return Res;
}


void arithmetic::Check() const
{
	int index = 0, SecIndex = 0;
	while (index < Input.size())
	{

		if (Input[index] == '(')
			SecIndex++;
		if (Input[index] == ')')
			SecIndex--;
		index++;
	}

	if (SecIndex != 0)
	{
		cout << "ошибка скобок" << endl;
		throw "Error";
	}

}