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
void Check :: PickOut(char *type0, char *type1, char *type2, char* type3)
 {
 	char letters[] = "abcdefghijqklmnoprstuvwxyz";

	int len0 = strlen(this->s);
	int len1 = strlen(letters);

	//char type1[256];  vars
	//char type2[256];  signs
	//char type0[256];  int;
	//char type3[256];  double;

	int k = 0;

 	for( int i = 0; i < len0; i++)
 		for( int j = 0; j < len1; j++)
 			if( this->s[i] == letters[j] ){
				type1[k] = this->s[i];
				k++;
			}
	k = 0;
	for( int i = 0; i < len0; i++)
			if( IsOperation(this->s[i])){
				type2[k] = this->s[i];
				k++;
			}
	this->FindInt(type0);
	this->FindDouble(type3);
 } 
char* Check :: FindInt(char *type0)
{
	int i = 0, k = 1, l = 0;
	while (this->s[i] != '\0') {
		if (isdigit(this->s[i])){
			
			if (isdigit(this->s[i+1]))
				k++; 
				else {
				for (int j = i - k; j < i+k ; j++, i++ ){
						if (isdigit(this->s[j]))
						type0[l] = type0[l]*10 + s[j];
					}
					l++;
				}
		}
	}
	return type0;
}
char* Check :: FindDouble(char *type3)
{
	int k = 0, i = 0;
	int l = 0, f = 0;
	for( int i = 1; i < len-1; i++)
		while ((s[i] == '.') || (s[i] == ','))
			if (isdigit(this->s[i-1])){
				f++; 
				if((isdigit(this->s[i+1])))
					k++;
			}
			else if((isdigit(this->s[i+1])))
					k++;
				else {
					k = min(k, f);
					for (int j = i - k; j < i+k ; j++, i++ )
						if (isdigit(s[j]))
						type3[l] = type3[l]*10 + s[j];

					for (int j = 1; j < k ; j++)
						type3[l] = type3[l]/10;
					l++;
				}

/*		if ((isdigit(this->s[i])) || (s[i] == '.') || (s[i] == ',') ){ //primenit` atod ili create new function, create calculator
			type0[k] = this->s[i];
			k++;
		}
*/

	return type3;
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