#include "arithmetic.h"
#include <iostream>

void main()
{
	string s = "y";
	while (s == "y")
	{
		string vv;
		cout << "enter expression" << endl;
		getline(cin, vv);
		if (vv == "")
		{
			getline(cin, vv);
		}
		Arithmetic A(vv);
		A.DivideToLexems();
		if (A.CheckBrackets() && A.CheckOperators())
		{
			double res;
			A.ifVariable();
			A.PolishNotation();
			res = A.Calculate();
			cout << vv + " = " << res << endl;
			cout << endl;
		}
		cout << "y - again" << endl;
		cout << "any - exit" << endl;
		cin >> s;
		cout << endl;
	}
}