 #include "C:\Users\Администратор\mp2-lab3-arithmetic\include/arithmetic.h"
 
Check ::Check(char* s){
}
bool Check :: CheckBrackets(Check br){
	TStack<int> expr(256);
 	int len;
	len = strlen(br.s);
 	for (int i = 0; i < len; i++)
 	{
		if (br.s[i] == '(')
			expr.Push(i);
 		else 
			if(br.s[i] == ')')
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

bool Check :: CheckOperands(Check br)
 {
	int len = strlen(br.s);
	char operators[] = "+*-/";
	for (int i = 0; i < len - 1; i++)
	{
		for (int j = 0; j < 4; j++)
			if ( br.s[i] == operators[j] )
				for ( int k = 0; k < 4; k++)
					if (br.s[i+1] == operators[k] )
					{
						throw "No operand between operators";
						return false;

					}
	}
 
 	return true;
 
}
void Check :: PickOut(Check br, char *type0, char *type1, char *type2)
 {
 	char letters[] = "abcdefghijqklmnoprstuvwxyz";
	char signs[] = "()+*-/";

	int len0 = strlen(s);
	int len1 = strlen(letters);
	int len2 = strlen(signs);

	//char type1[256];  массив символов
	//char type2[256];  массив букв
	//char type0[256];  массив знаков

	int k = 0;

 	for( int i = 0; i < len0; i++)
 		for( int j = 0; j < len1; j++)
 			if( br.s[i] == letters[j] )
 			{
				type1[k] = br.s[i];
				k++;
 			}

	k = 0;

	for( int i = 0; i < len0; i++)
		for( int j = 0; j < len2; j++)
			if( br.s[i] == signs[j] )
			{
				type2[k] = br.s[i];
				k++;
			}
	k = 0;

	for( int i = 0; i < len0; i++)
		if (isdigit(br.s[i])) 
		{
			type0[k] = br.s[i];
			k++;
		}
 } 

int Check :: Prioritet()
{
	switch(this->s)
	{
	case '(' :
			return 0;
	case '+':
			return 1;
	case '-':
			return 1;
	case '*':
			return 2;
	case '/':
			return 2;
	case '^':
			return 3;
	}
}