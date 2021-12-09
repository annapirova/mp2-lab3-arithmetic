#include "arithmetic.h"
#include <cstring>
#include <string>

// реализаци€ пользовательского приложени€

int main()
{
	int i = 1;
	while (i == 1)
	{
		char* s2;
		s2 = (char*)malloc(sizeof(char) * 100);
		cout << "Welcome to the program!" << endl;
		cout << "Enter the arithmetic expression: ";
		std::cin.getline(s2, 100);
		cout << endl;
		arithmetic A(s2);
		while ((A.CheckBracket() == 0) || (A.CheckOperator() == 0) || (A.CheckLetters() == 0) || (A.CheckPoint() == 0))
		{
			cout << endl;
			cout << "Enter an expression again: ";
			std::cin.getline(s2, 100);
			cout << endl;
			arithmetic B(s2);
			A = B;
		}
		A = A.PolishEntry();
		double res = 0.0;
		res = A.CalculatePolishEntry();
		cout << "Calculation result: " << res << endl;
		cout << endl;
		cout << "Do you want to enter an expression again? " << endl;
		cout << "1. Yes" << endl;
		cout << "2. No" << endl;
		//cout << "Your choice: ";
		cin >> i;
		cout << endl;
		delete[] s2;
	}

	cin.get();
}