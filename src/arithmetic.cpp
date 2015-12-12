//#include "Z:\mp2-lab3-arithmetic\include\arithmetic.h"
//#include "C:\Users\Julia\mp2-lab3-arithmetic\include\arithmetic.h"

#include "arithmetic.h"
 
Check ::Check(char* s){
	if (s == NULL){
		len = 0;
		s = new char[256];
		throw "str is empty";
	}
	else{
		this->len = strlen(s); 
		if (len == 0){
			this->s = new char[256];
			len = 256;//подозрительные штуки, может быть равна нул.
		}
		else
		{
			this->s = new char[len];
			for (int i = 0; i < len; i++)
				this->s[i] = s[i];
		}
	}
}
bool Check :: CheckBrackets(){
	TStack<int> expr(256);
	bool flag = true;
 	for (int i = 0; i < len; i++){
		if (this->s[i] == '(')
			expr.Push(i);
 		else 
			if(this->s[i] == ')'){
 			if (expr.IsEmpty()){
 				flag = false;
				break;
			}
			else
 				expr.Pop();
 		}
 	}
	if (flag == true)
		if (!expr.IsEmpty())
 		flag = false;
	return flag;
}
bool Check :: CheckOperands()
 {
	char operators[] = "+*-/";
	for (int i = 0; i < len-1; i++){
		for (int j = 0; j < 4; j++)
			if ( this->s[i] == operators[j] )
				for ( int k = 0; k < 4; k++)
					if (this->s[i+1] == operators[k] ){
						cout << "No operand between operators" << endl;
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
		res[j++] = '0';
 		res[j] = '-';
 		j++;
 	}
 	else{
 		res[j] = s[0];
 		j++;
 	}
 	for (int i = 1; i < len-1; i++){
 		if (s[i] == '-'){
 			if((s[i-1]=='(') &&( (isdigit(s[i+1])) || (isalpha(s[i+1])))){
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
	res[j++] = s[len - 1];
 	res[j] = '\0';
}
bool Check :: IsUnarMinus()
 {
 	int i = 1;
 	bool flag = false;
 
 	if (this->s[0]=='-')
 		flag = true;
 	while(this->s[i] != '\0'){
 		if (this->s[i] == '-'){
 			if((this->s[i-1]=='(') && ( (isdigit(this->s[i+1])) || (isalpha(this->s[i+1])))){
 				flag = true;
 				break;
 			}
 		}
 		i++;
 	}
 	if (flag == true)
 		return flag;
 	else 
 		return false;
 }
void Check :: ChangeExpression(char *res){
	int i = 0;
	TStack<char> sg(256);
	int j = 0;
	for(i = 0; i < len; i++)
	{
		if (s[i]=='(') 
			sg.Push(s[i]);
		if (s[i] == ')')
 		{
 			char a = sg.Pop();
 			while (a !='(')
 			{
 				res[j++] = a;
 				a = sg.Pop();
 			}
 		}
		if (IsOperation(s[i])){
			if (sg.IsEmpty())
 				sg.Push(s[i]);
			else {
			char op = sg.Get();
			while (Prioritet(s[i]) <= Prioritet(op)){
				res[j++] = sg.Pop();
 					if (sg.IsEmpty() == false)
 						op = sg.Get();
 					else 
 						op = '(';
				}
			sg.Push(s[i]);
			}
		}
		 if( isdigit(s[i])){
			 if (i != len -1){
			 
 				if ((isdigit(s[i+1])) || (s[i+1] == '.') || (s[i+1] == ',')){
 					res[j] = s[i];
 					j++;
 			 }
				else
				{ 		
					res[j] = s[i];
 					j++;
 					res[j]=' ';
  					j++;
  				}
			 }
 			else {
 				res[j] = s[i];
 				j++;
 				res[j]=' ';
  				j++;
  			}
 		}

		if (isalpha(s[i])){
			res[j++] = s[i];
 			res[j++]=' ';
 		}

		if( (s[i] == '.') || (s[i] == ',')){
 					res[j] = s[i];
 					j++;
 		}
	}
	while((sg.IsEmpty() == false )){
				res[j++] = sg.Pop();
	}
	res[j] = '\0'; 
}
double Check :: Calculation ()
{
 	TStack <double> num(256);
 	int i = 0, m = 0;
 	double res;
 	while(this->s[i] != '\0')
 	{
 		if(isdigit(this->s[i]))
 		{ 
 			Check str("");
			str.len = 256;
 			int k = 0;
 			double number;	
 			m = i;
 			while( this->s[m] != ' ')
 			{
 				str.s[k] = this->s[m];
 				m++;
 				k++;
 			}
			str.s[k] = '\0';
			str.len = str.GetLen();
 			number = str.GetNumber();
 			num.Push(number);
			i = m;//индекс не менять
 		}
 		if (IsOperation(this->s[i]))
 		{
 			double opright, opleft;
 			opright = num.Pop();
 			opleft = num.Pop();
 			switch(this->s[i])
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
	if (this->s != NULL) delete[]this->s;
}
void Check :: Input(char *res)
 {
 	len = strlen(s);
	for (int i = 0; i < len; i++ )
		cout << s[i] << endl;

	int Size = 256;
 	int i = 0; int m = 0;
 	int *num = new int[Size];
 	for (int j = 0; j < Size;j++)
 		num[j] = -1;
	len = this->GetLen();
 	this->FindVars(num);
 	if (num[0] != -1)
 		cout << "Expression has vars" << endl;
	len = this->GetLen();
 	for (int p = 0; p < this->GetLen(); p++){
 		if (num[i] != p){
 			res[m] = s[p];
 			m++;
 		}
 		else{
			bool flag = true;
 			int j = 0;
 			char val[100];
			//while (flag == true){
			std::cout << s[num[i]] << " = ";
 			//gets(val);
			std::cin>>val;
 			if(val[0] == '-'){
 				res[m] = '0';
 				m++;
 				res[m] = ' ';
 				m++;
 				j=1;
				res[m++] = '-';
 				while (val[j] != '\0'){
 					res[m] = val[j];
 					m++;
 					j++;
 				}
 				res[m] = ' ';
 				m++;
 			}
 			else{
 				while (val[j] != '\0'){
 					res[m] = val[j];
 					m++;
 					j++;
 					}
 				}
			//	flag = false;
			//}
 			i++;
 		}		
 	}
	cout << "Point1" << endl;
	for (int i = 0; i < m ; i++)
		cout << res[i] << endl; 
 	res[m] = '\0';
 	delete []num;

}
void Check :: FindVars (int * res)
 {
 	int j = 0;
 	for (int i = 0; i < len; i++)
 		if(isalpha(s[i]) /*&& (!isdigit(s[i]))*/){
 			res[j]=i;
 			j++;
 		}
 }
bool Check :: AreVars()
{
	bool flag = false;
	for (int i = 0; i < len; i++)
	{
		if(isalpha(s[i])/* && (!isdigit(s[i]))*/){
			flag = true;
			break;
		}
	}
	if (flag == true)
		return true;
	else 
		return false;
}
int Check :: GetLen(){
	int prlen = 0, i = 0;
	while (s[i] != '\0') {
		i++;
		prlen++;
	}
	return prlen;
}