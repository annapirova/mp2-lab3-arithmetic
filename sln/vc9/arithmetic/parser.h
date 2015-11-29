#include "stack.h"
#include "arithmetic.h"


const int MaxSize=256;


class TParser
{
private:
	char inf[MaxSize];
	char postf[MaxSize];
	TStack<char> st_c; //стек операций
	TStack<double> st_d;
	int prior1 (char a);
	
public:
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
void TParser:: inf_to_postf(){		 //исправить 
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


