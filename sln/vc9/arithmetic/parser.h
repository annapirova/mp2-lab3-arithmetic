
#include "stack.h"
#include "arithmetic.h"


const int MaxSize=256;


class TParser
{
private:
	char inf[MaxSize];
	char postf[MaxSize];
	TStack<char> St_c; //стек операций
	TStack<double> St_d;
	
public:
	int prior1 (char a);
	double calc1 ();
	bool IsNumber(char a);
	bool TParser:: IsOper(char a);
	void GetNumber(char *s,double &d,int &l);
	TParser (char * c);
    void inf_to_postf();
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
/*void TParser:: inf_to_postf(){		 //исправить 
	int i=0,j=0;
	st_c.push('=');
	while (inf[i]!='\0')
	{
		//if (inf[i]=='('	)
			//st_c.push('(');
		if ((DType(inf[i])==1) || (DType(inf[i])==2))
			postf[j++]=inf[i];
		else
		if (DType(inf[i])==3)
		{
			if(prior(inf[i])>=prior1(st_c.peek()))
			{
				st_c.push(inf[i]);		}
		}
		else
				while(!st_c.isEmpty())
					postf[j++]=st_c.put();
		++i;
}
	

	cout<< postf[0];
		postf[j]='\0';
	
		
		
	
} */
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
	for(int i=0;i<6;i++)
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
void TParser:: GetNumber(char *s,double &d,int &l) {
	d=atof(s);
	l=0;
	while (IsNumber(s[l]))
		l++;
}

double TParser:: calc1 () { //строка уже в inf[]
	int i=0;
	//St_d.Clear(); //очищаем стек
	//St_c.Clear();

	St_c.push('=');

	while (inf[i]!='\0') 
	{
		if (IsNumber(inf[i])) 
		{
			double d;
			int l;
			GetNumber(&inf[i],d,l);
			St_d.push(d);
			i=i+l-1;
		}
		else
			if (inf[i]=='(')
				St_c.push('(');
			else if(inf[i]==')')
			{
				char temp=St_c.put();
				while (temp!= '(')
				{
					double R;
					double op2=St_d.put();
					double op1=St_d.put();
					switch (temp)
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
					temp=St_c.put();
				}
			}
			
			else //если операция
				if (IsOper (inf[i])) {
					char temp=St_c.put();
				while (prior1(inf[i])<=temp)
				{			

					double op2=St_d.put();
					double op1=St_d.put();
					
					double R; //результат
					switch(temp)
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
					temp=St_c.put();
				}
				St_c.push(temp);
				St_c.push(inf[i]);
				}
				i++;
	}
	char temp=St_c.put();
	while (temp!='=')
	{
		double op1, op2,R;
		op2=St_d.put();
		op1=St_d.put();
		switch(temp) 
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

		temp=St_d.put();
	}
	return (St_d.put());
}