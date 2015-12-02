//#include "Z:\mp2-lab3-arithmetic\include\arithmetic.h"
#include "C:\Users\Julia\mp2-lab3-arithmetic\include\arithmetic.h"
 
Check ::Check(char* s){
	if ((s == NULL) || (s == "\0"))
		throw "str is empty";
	this->len = strlen(s); 
	this->s = new char[len];
	for (int i = 0; i < len; i++)
		this->s[i] = s[i];
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
int Check :: Prioritet(char s)
{
	if (IsOperation(s)){
		if (s == '(') return 0;
		if ((s == '+') || (s == '-')) return 1;
		if ((s == '*') || (s == '/')) return 2;
		if (s == '^') return 3;
	}
	else return -1;
}
bool Check :: IsOperation(char s)
 {
 	if ( (s == '+') || (s == '-') || (s == '*') || (s == '/') || (s == '^'))
 		return true;
 	else 
 		return false;
 }
void Check :: UnarMinus(char *res)
{
 	int j = 0;

 	if (s[0] == '-'){
 		res[j] = '0';
 		j++;
 		res[j] = '-';
 		j++;
 	}
 	else{
 		res[j] = s[0];
 		j++;
 	}
 	for (int i = 1; i < len; i++){
 		if (s[i] == '-'){
 			if((s[i-1]=='(') && (isdigit(s[i+1]))|| (isalpha(s[i+1]))){
 				res[j] = '0';
 				j++;
 				res[j] = '-';
 				j++;
 			}
 		}
 		else{
 			res[j] = s[i];
 			j++;
 		}
 	}
 	res[j] = '\0';
}
bool Check :: IsUnarMinus()
 {
 	int i = 1;
 	int flag = 0;
 
 	if (this->s[0]=='-')
 		flag = 1;
 	while(this->s[i] != '\0'){
 		if (this->s[i] == '-'){
 			if((this->s[i-1]=='(') && (isdigit(this->s[i+1]))|| (isalpha(this->s[i+1]))){
 				flag = 1;
 				break;
 			}
 		}
 		i++;
 	}
 	if (flag == 1)
 		return true;
 	else 
 		return false;
 }
char* Check :: ChangeExpression(char *res){
	int i = 0;
	TStack<char> sg(256);
	int j = 0;
	for(i = 0; i < len;i++)
	{
		if (s[i]=='(') 
			sg.Push(s[i]);
		if (s[i] == ')')
 		{
 			char a = sg.Pop();
 			while (a !='(')
 			{
 				res[j] = a;
 				j++;
 				a = sg.Pop();
 			}
 		}
		if (IsOperation(s[i])){
			if (sg.IsEmpty())
 				sg.Push(s[i]);
			else {
			char op = sg.Get();
			while (Prioritet(s[i]) <= Prioritet(op)){
				res[j]=sg.Pop();
 					j++;
 					if (sg.IsEmpty() == false)
 						op = sg.Get();
 					else 
 						op = '(';
				}
			sg.Push(s[i]);
			}
		}
		if( isdigit(s[i])){
			if ((isdigit(s[i+1])) || (s[i+1] == '.') || (s[i+1] == ',')){
				res[j] = s[i];
				j++;
			}
			else {
				res[j] = s[i];
				j++;
				res[j]=' ';
 				j++;
 			}
		}
		if (isalpha(s[i])){
			res[j]=s[i];
 			j++;
 			res[j]=' ';
 			j++;
 		}
		if ((s[i+1] == '.') || (s[i+1] == ',')){
			res[j] = s[i+1];
 			j++;
 		}
	}
	while((sg.IsEmpty() == false )){
				res[j] = sg.Pop();
				j++;
			}
	res[j]='\0'; 
	return res; 
}
double Check :: Calculation ()
{
 	TStack <char> op(256);
 	TStack <double> num(256);
 	int l = 0, i = 0, m = 0;
 	double res;
 	while(s[i] != '\0')
 	{
 		if(isdigit(s[i]))
 		{ 
 			Check str("");
 			int k = 0;
 			double number;	
 			m = i;
 			while( s[m] !=' ')
 			{
 				str.s[k] = s[m];
 				m++;
 				k++;
 			}
 			str.s[k] = '\0';
 			l = m - i + 1;
 			number = str.GetNumber();
 			num.Push(number);
 			i = i + l - 1;
 		}
 		if (IsOperation(s[i]))
 		{
 			double opright, opleft;
 			opright = num.Pop();
 			opleft = num.Pop();
 			switch(s[i])
 			{
 				case '+': {
 					res = opleft + opright;
 					break;
 				}
 				case '-': {
 					res = opleft - opright;
 					break;
 				}
 				case '*': {
 					res = opleft * opright;
 					break;
 				}
 				case '/': {
 					res = opleft / opright;
 					break;
 				}
 				case '^': {
 					int op;
 					op = (int)opright; 
 					int count = 1; 
 					res = opleft;
 					do
 					{
 						if (op == 0)
 							res = 1;
 						else if ((op != 1) && (op > 0))
 							res = res * opleft; 
 						count++; 
 					} 
 					while ( op > count); 
 					break;
 				}
 			}
 			num.Push(res);
 		}
 		i++;
 	}
 	return num.Pop();
}
double Check :: GetNumber(){
 	double res = atof(s);
 	return res;
 }
Check :: ~Check ()
{
	delete []s;
}
void Check :: Input(char *res)
 {
 	int *num;
 	int Size = 256;
 	int i=0; int m=0;
 	num = new int[Size];
 	for (int j = 0; j < Size;j++)
 		num[j] = -1;
 	this->FindVars(num);
 	if (num[0] != -1)
 		cout << "Expression has vars" <<endl;
 	for (int p = 0; p < len; p++){
 		if (num[i] != p){
 			res[m] = s[p];
 			m++;
 		}
 		else{
 			char str[256];
 			int j = 0;
 			cout << s[num[i]]<< "=";
 			gets(str);
 			if(str[0] == '-'){
 				res[m] = '0';
 				m++;
 				res[m] = ' ';
 				m++;
 				j=1;
 				while (str[j] != '\0'){
 					res[m] = str[j];
 					m++;
 					j++;
 				}
 				res[m] = ' ';
 				m++;
 				res[m] = '-';
 				m++;
 				p++;
 			}
 			else{
 				while (str[j] != '\0')
 				{
 					res[m] = str[j];
 					m++;
 					j++;
 				}
 			}
 			i++;
 		}		
 	}
 	res[m] = '\0';
 	delete []num;
}
void Check :: FindVars (int * res)
 {
 	int j = 0;
 	for (int i = 0; i < len; i++)
 		if(isalpha(s[i]) && (!isdigit(s[i]))){
 			res[j]=i;
 			j++;
 		}
 }
bool Check :: AreVars()
{
	bool flag = false;
	for (int i = 0; i < len; i++)
	{
		if(isalpha(s[i]) && (!isdigit(s[i]))){
			flag = true;
			break;
		}
	}
	if (flag == true)
		return true;
	else 
		return false;
}