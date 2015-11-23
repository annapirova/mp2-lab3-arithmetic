#include "stack.h"
#include "arithmetic.h"


const int MaxSize=256;


class TParser
{
private:
	char inf[MaxSize];
	char postf[MaxSize];
	TStack<char> st_c;
	TStack<double> st_d;
public:
	 TParser (char * c) {
		 int i=0;
		 while (c[i]!='\0')
		 {
			 inf[i]=c[i];
			 i++;
		 }
		 inf[i]='\0';
	 }
	 void inf_to_postf();
};

void TParser:: inf_to_postf(){
	int i=0,j=0;
	st_c.push('=');
	while (inf[i]!='\0')
	{
		if (inf[i]=='('	)
			st_c.push('(');
		if (DType(inf[i])==1)
			postf[j]=inf[i];
		j++;
		++i;
	}
	while (!st_c.isEmpty())
	{
		postf[j]=st_c.peek();
		j++;
	}
		postf[j]='\0';
	
}