// реализация пользовательского приложения

#include "arithmetic.h"
#include <string>

int main()
{
	setlocale(LC_CTYPE, "Russian");
	string s;
	int f;
	cout << "Input the value, for example - 3+x*(3.4-0.4): ";
	getline(cin, s);
	s = unary_minus(s);
	Arithmetic Exp(s);
	f = Exp.check();
	Arithmetic Arr(s);
	Arr.Polish();
	Arr.print_polish();
	Arr.set_vars();
	double res = Arr.calculate();
	cout << res;
	return 0;
}