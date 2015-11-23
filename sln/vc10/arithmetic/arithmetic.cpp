#include "C:\Users\Администратор\mp2-lab3-arithmetic\include/arithmetic.h"

bool CheckBrackets(char* s) 
{
	TStack<int> expr(256);
	int len;
	len = strlen(s);
	for (int i = 0; i < len; i++)
	{
		if (s[i] == '(')
			expr.Push(i);
		else 
			if(s[i] == ')')
		{
			if (expr.IsEmpty())
				throw "Expression is empty ";
			else
				expr.Pop();
		}
	}
	if (expr.IsEmpty())
		return true;
	else 
	{
		throw "Expression is uncorrectly";
		return false;
	}		
}
bool CheckOperands(char* s)
{
	int len = strlen(s);
	char operators[] = "+*-/";
	for (int i = 0; i < len - 1; i++)
	{
		for (int j = 0; j < 4; j++)
			if ( s[i] == operators[j] )
				for ( int k = 0; k < 4; k++)
					if (s[i+1] == operators[k] )
					{
						throw "No operand between operators";
						return false;

					}
	}

	return true;
}
void PickOut(char *s, char *type0, char *type1, char *type2)
 {
 	char letters[] = "abcdefghijqklmnoprstuvwxyz";
	char signs[] = "()+*-/";

	int len0 = strlen(s);
	int len1 = strlen(letters);
	int len2 = strlen(signs);

	//char type1[256]; массив букв
	//char type2[256];  массив знаков
	//char type0[256]; массив цифр

	int k = 0;

 	for( int i = 0; i < len0; i++)
 		for( int j = 0; j < len1; j++)
 			if( s[i] == letters[j] )
 			{
				type1[k] = s[i];
				k++;
 			}

	k = 0;

	for( int i = 0; i < len0; i++)
		for( int j = 0; j < len2; j++)
			if( s[i] == signs[j] )
			{
				type2[k] = s[i];
				k++;
			}
	k = 0;

	for( int i = 0; i < len0; i++)
		if (isdigit(s[i])) 
		{
			type0[k] = s[i];
			k++;
		}
 }