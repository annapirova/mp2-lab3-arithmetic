// #include "C:\Users\Администратор\mp2-lab3-arithmetic\include/arithmetic.h"
#include "Z:\mp2-lab3-arithmetic\include\arithmetic.h"
 
Check ::Check(char* s){
	this->s = new char[256];
	this->s = s;
}
bool Check :: CheckBrackets(){
	TStack<int> expr(256);
 	int len;
	len = strlen(this->s);
 	for (int i = 0; i < len; i++)
 	{
		if (this->s[i] == '(')
			expr.Push(i);
 		else 
			if(this->s[i] == ')')
 		{
 			if (expr.IsEmpty())
			{
				cout << "Expression is empty ";
 				return false;
			}
			else
 				expr.Pop();
 		}
 	}
 	if (expr.IsEmpty())
 		return true;
 	else 
 	{
		cout << "Expression is uncorrectly";
 		return false;
 	}
}

bool Check :: CheckOperands()
 {
	int len = strlen(this->s);
	char operators[] = "+*-/";
	for (int i = 0; i < len - 1; i++)
	{
		for (int j = 0; j < 4; j++)
			if ( this->s[i] == operators[j] )
				for ( int k = 0; k < 4; k++)
					if (this->s[i+1] == operators[k] )
					{
						throw "No operand between operators";
						return false;
					}
	}
 
 	return true;
 
}
void Check :: PickOut(char *type0, char *type1, char *type2)
 {
 	char letters[] = "abcdefghijqklmnoprstuvwxyz";
	char signs[] = "()+*-/";

	int len0 = strlen(this->s);
	int len1 = strlen(letters);
	int len2 = strlen(signs);

	//char type1[256];  массив переменные
	//char type2[256];  массив операции
	//char type0[256];  массив чисел - констант

	int k = 0;

 	for( int i = 0; i < len0; i++)
 		for( int j = 0; j < len1; j++)
 			if( this->s[i] == letters[j] )
 			{
				type1[k] = this->s[i];
				k++;
 			}

	k = 0;

	for( int i = 0; i < len0; i++)
		for( int j = 0; j < len2; j++)
			if( this->s[i] == signs[j] )
			{
				type2[k] = this->s[i];
				k++;
			}
	k = 0;

	for( int i = 0; i < len0; i++)
		if (isdigit(this->s[i])) 
		{
			type0[k] = this->s[i];
			k++;
		}
 } 

int Check :: Prioritet(char s)
{
	switch(s)
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
bool Check :: IsOperation(char s)
 {
 	if ( (s == '+') || (s == '-') || (s == '*') || (s == '/'))
 		return true;
 	else 
 		return false;
 }

char* Check :: ChangeExpression(){
	char res[256];
	int i,p=0;
	TStack<char> sg(256);
	int len = strlen(this->s); 

	for(i = 0; i < len;i++)
	{
		if (s[i]=='(') 
			sg.Push(s[i]);
		else 
			if (IsOperation(s[i])){
				char op = sg.Get();
				while((!sg.IsEmpty())&&(Prioritet(s[i]) > Prioritet(op))){
					p++;
					res[p]=sg.Pop();
				}
			sg.Push(s[i]);
		}
		else if(s[i]==')'){
			while((sg.IsEmpty() != true ) && (sg.top != '(')){
				p++;
				res[p] = sg.Pop();
			}
			sg.Pop();
		}
		else{
			p++;
			res[p] = s[i];
		}
	}
	while(!sg.IsEmpty())
	{
		p++;
		res[p]=sg.Pop();
	}

	res[p]='\0'; 
	return res; 
}