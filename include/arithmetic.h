// Объявление функций и классов для вычисления арифметических выражений
#ifndef __ARITHMETIC_H__
#define __ARITHMETIC_H__
#include <iostream>
#include <string>
using namespace std;

class Tlexeme 
{protected:
  int Size;
  string* mLexeme; // массив строк разитых на лексемы
  int* priority;   // приоритет лексем
  int Flag = -1;   // флаг обработки
 public:
  //Конструкторы и деструкторы
  Tlexeme(string a="0");
  ~Tlexeme();
  //Операции
  int Check_correct(); //Проверка на корректность введения записи
  void Pol(); //Конвертировать в польскую запись
  double Calculation(); // Вычисление
  //Перегрузка операций ввода/вывода
  friend istream& operator>>(istream& in, Tlexeme& l)
  { in >> l.mLexeme[0];
	string a = l.mLexeme[0];
	l.Size = (l.mLexeme[0]).length();
	l.mLexeme = new string[l.Size];
	l.priority = new int[l.Size];
	l. mLexeme[0] = a;
	return in;
   }
  friend ostream& operator<<(ostream& out, const Tlexeme& l)
  { for (int i = 0; i < l.Size; i++)
	{ out << l.mLexeme[i] << ' ';}
	cout << endl;
	/*for (int i = 0; i < l.Size; i++)
	{ out << l.priority[i] << ' ';}
	cout << endl;*/
	return out;
   }
 private:
  // Закрытые функции
  void Divide(); //Разбить на лексемы
  int Check_brack();//Проверка скобок
  int Check_sign(); //Проверка знаков операций
  int Check_point(); //Проверка точек в дробных числах
  int Check_variable();//Проверка переменных
  int Check_function();//Проверка функции
};

#endif