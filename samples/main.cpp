// реализаци€ пользовательского приложени€
#include "arithmetic.h"

int main()
{
	bool f = 1;
	cout << "________________________________________Calculation of arithmetical expression.________________________________________________" << endl;
	cout << "The expression can consist only integer operands. Also it can be positive or negative. Operations you can use: +, -, *, / and ^" << endl;

	while (f == 1)
	{
		string s;
		cout << "Enter your expression: ";
		cin >> s;
		Arithmetic A(s);
		double res;
		res = A.Calcul();
		cout << res << endl;
		cout << "If you want to continue press 1" << endl;
		cin >> f;
	}
}