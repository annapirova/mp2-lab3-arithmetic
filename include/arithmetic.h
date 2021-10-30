// объявление функций и классов для вычисления арифметических выражений
#ifndef __ARITHMETIC_H__
#define __ARITHMETIC_H__
#include <iostream>
#include <string>
using namespace std;

class Tlexeme
{ protected:
	int Size;
	string* mLexeme; //массив строк разитых на лексемы
	int* priority; //приоритет лексем
	int Flag = 0; // наличие ошибок
    public:
	//Конструкторы и деструкторы
	Tlexeme(string a);
	~Tlexeme();
	//Операции
	bool Split(); //Проверка разбита ли строка на лексемы
	void Divide(); //Разбить на лексемы
	void Check_correct(); //Проверка на корректность введения записи
	void Pol(); //Вычисление польской записи
	private:
	int Check_brack();//Проверка скобок
	int  Check_sign(); //Проверка знаков операций
	int  Check_point(); //Проверка точек в дробных числах
	int  Check_variable();//Проверка переменных
	int  Check_function();//Проверка функции
	
	
};




/*
// Перевод в польскую запись
string POL(string s)
{
	int i;
	string a;
	for (int i = 0; i < a.length(); i++)
	{ switch (a[i])
	  { case '+-':
			   break;
		case '(':
			   break;
		case ')':
			break;
		case '0123456789':
			break;
		}
	}
	return a;
}

//Проверка на корректность
bool RIG(string s)
{ string a=s;
  bool flag = 1;
  TStack <char> S1; //скобки
  TStack <char> S2; //знаки выражения
  TStack <char> S3; //точки
  TStack <char> S4; //цифры
  for (int i = 0; i < a.length(); i++) //while
  {
	  switch (a[i])
	  {
	  case '(': S1.Push('('); break;
	  case ')': if (S1.Empty()) { flag = 0; cout << "Bracket error in place № " << i << endl; }
			  else { S1.Pop(); S2.Clear(); S3.Clear(); S4.Clear(); } break;
	  case '+' || '*' || '/': if (S4.Empty()) { flag = 0; cout << "Sign error in place № " << i << endl; }
							else { S2.Push(a[i]); } break;
	  case '-':  S2.Push(a[i]); break;
	  case '.':  S2.Push(a[i]); break;

	  }
  }

}
*/

/*
//Разбить на лексемы
string Lec(string s)
{ int n = s.length();
  string* s;


	for (int i = 0; i < a.length(); i++)
	{
		switch (a[i])
		{
		case '+-':
			break;
		case '(':
			break;
		case ')':
			break;
		case '0123456789':
			break;
		}
	}
	return a;
} */
#endif