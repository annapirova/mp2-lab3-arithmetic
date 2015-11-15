#include "C:\Users\Администратор\mp2-lab3-arithmetic\include/arithmetic.h"

bool CheckBrackets(char* s) 
{
	TStack<int> expr(256);
	int len;
	len = strlen(s);
	for (int i = 0; i < len; i++)
	{
		if (s[i] == '(')
			expr.Pop();
		else 
			if(s[i] == ')')
		{
			if (expr.IsEmpty())
			{
				cout <<  "Выражение в скобках"  << i << endl;
				break;
			}
			else
				expr.Pop();
		}
	}
	if (expr.IsEmpty())
		return true;
	else 
	{
		while (expr.IsEmpty() != true)
		{
			int res;
			res = expr.Pop();
			cout << res << ";";
		}
		return false;
	}		
}
bool CheckOperands(char* s)
{

	return true;
}