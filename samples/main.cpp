// реализаци€ пользовательского приложени€
#include "arithmetic.h"

int main()
{
	bool f = 1;
	cout << "________________________________________Calculation of arithmetical expression._________________________________________" << endl << endl;
	cout << "The expression can consist only integer operands. Also it can be positive or negative. Operations you can use: +, -, *, / and ^" << endl;

	while (f != 0)
	{
		switch (f)
		{
		case 1:
		{
			string s;
			cout << endl;
			cout << "Enter your expression: ";
			cin >> s;
			Arithmetic A(s);
			double res;
			res = A.Calcul();
			cout << res << endl << endl;
			cout << "Do you want to continue?" << endl;
			cout << "1. Yes." << endl;
			cout << "0. No." << endl;
			cin >> f;
			break;
		}
		}
	}
}