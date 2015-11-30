
#include "stack.h"
#include "arithmetic.h"


const int MaxSize=256;


class TParser
{
private:
	char inf[MaxSize];
	char postf[MaxSize];
	TStack<char> St_c;
	TStack<double> St_d;
	
public:
	TParser (char * c);
	int prior1 (char a);
	bool IsNumber(char a);
	bool IsOper(char a);
	void GetNumber(char *s,double &d,int &l);
    double calc ();
	void Convert();

};

TParser::TParser (char * c) {
		 int i=0;
		 while (c[i]!='\0')
		 {
			 inf[i]=c[i];
			 i++;
		 }
		 inf[i]='\0';
	 }
int TParser::prior1 (char a){ //приоритет операций
	switch(a){
	case '=' : return(0);
	case '(' : return(1);
	case '-' :
	case '+' : return(2);
	case '*' :
	case '/' : return(3);
	}
}
bool TParser:: IsNumber(char a){
	if (isdigit(a))
		return true;
	else
		return false;
}
bool TParser:: IsOper(char s){
	char operand[]="+-*/";
	int flag=0;
	for(int i=0;i<4;i++)
			if (s==operand[i])
			{
				flag=1;
				break;
			}
			if(flag==1)
				return true;
			else 
				return false;		
}
void TParser:: GetNumber(char *s,double &d,int &l) { //число из char
	d=atof(s);
	l=0;
	while (IsNumber(s[l]))
		l++;
}
void TParser::Convert()
{   // i - счетчик inf[], j - счетчик postf[]
	int j = 0;
	int i=0;
	St_c.push('=');
	for(int i = 0; inf[i] != '\0'; ++i) // Пока не конец строки обрабатываем очередной символ
	
	{
		if( inf[i] == '(' ) // Если открывающая скобка, добавляем в Стек
			St_c.push('(');

		if( IsNumber(inf[i]) ) // Если число, добавляем в постфиксную запись
			postf[j++] = inf[i];

		if( IsOper(inf[i]) ) // Если операция
		{
			/*if(St_c.isEmpty()) 
				St_c.push(inf[i]);
			else 
			{*/
				char temp = St_c.put();
				while( prior1(inf[i]) <= prior1(temp) ) // Пока приоритет inf[i] < операции на вершине Стека
				{
					postf[j++] = temp;//St_c.put(); // Добавляем операции из Стека в Постфиксную запись
					temp = St_c.put();					
					/*if (St_c.isEmpty()!=true)
						temp=St_c.peek();
					else 
						temp='(';*/
				}
				St_c.push(temp);
				St_c.push(inf[i]); // Добавляем операцию в Стек
				
		//}
		}

		if( inf[i] == ')' )
		{
			/*if(St_c.isEmpty()) 
				St_c.push(inf[i]);
			else {*/
				char temp = St_c.put();
				while(temp != '(')
				{
					postf[j++] = temp;
					temp = St_c.put();
				}
			//}
		}
		
	}
	while( !(St_c.isEmpty()))
		postf[j++] = St_c.put();
	postf[j] = '\0';
	for(j=0;j<15;j++)
		cout<<postf[j];
	
}
double TParser:: calc () { //строка уже в inf[]
	int i=0;
	//St_d.Clear(); //очищаем стек
	//St_c.Clear();


	while (postf[i]!='\0') 
	{
		if (IsNumber(postf[i])) 
		{
			double d;
			int l;
			GetNumber(&inf[i],d,l);
			St_d.push(d);			
		}
		if (IsOper(postf[i]))
		{
					double R;
					double op2=St_d.put();
					double op1=St_d.put();
					switch (postf[i])
						{
					case '+':
						R=op1+op2;
						break;
					case '-':
						R=op1-op2;
						break;
					case '*':
						R=op1*op2;
						break;
					case '/':
						R=op1/op2;
						break;
					}			
					St_d.push(R);	
		}
		i++;
	}
	return (St_d.put());
}
