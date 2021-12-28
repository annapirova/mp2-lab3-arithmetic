// объявление функций и классов для вычисления арифметических выражений
#include "stack.h"
#include <string>
#include <vector>


class Tlexeme 
{protected:
  int Size;
  string* mLexeme; 
  int* priority;   
  int Flag = -1;  
 public:
  Tlexeme(string a="0");
  ~Tlexeme();
  
  void Fill(string a); 
  int Check_correct(); 
  string Pol(); 
  double Calculation(int x=0); 
  
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
	return out;
   }
 private:
  void Divide(); 
  void Pol_1(); 
  int Check_brack();
  int Check_sign(); 
  int Check_point(); 
  int Check_variable();
  int Check_function();
};




























//struct Lexema
//{
//	string Val;   //значение лексемы;
//	int Priority; //приоритет лексемы;
//	double Num;   //значение числа;
//	int type;     //Тип лексемы: 0 - скобки;  1 - число;  2 - оператор;
//	Lexema() {}
//	Lexema(string V);
//	Lexema(const Lexema& Lex);
//	char ReVal() { return Val[0]; }
//	
//	int operator==(const char& v) const;
//	int operator!=(const char& v) const;
//	friend ostream& operator<<(ostream& out, const Lexema& Lex)
//	{
//		out << Lex.Val;
//		return out;
//	}
//	~Lexema() {}
//
//
//};
//
//
//class arithmetic
//{
//private:
//	string Input;
//	string Polish;
//	double Res;
//	Lexema* LexInput;  //массив лексем;
//	Lexema* LexPolish; //Массив лексем в польской записи;
//	int Size;
//
//public:
//	arithmetic() {}
//	arithmetic(string);
//	void BreakLexemes();
//	void PolishLexemes();
//	double PolishLexemesSolution();
//	void Check() const;
//	~arithmetic() {
//		delete[] LexInput;
//		delete[] LexPolish;
//	}
//};