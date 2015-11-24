#include "stack.h"
#include "arithmetic.h"


const int MaxSize=256;


class TParser
{
private:
	char inf[MaxSize];
	char postf[MaxSize];
	TStack<char> st_c;
	int prior1 (char a);
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


/*
void TParser:: inf_to_postf(){
	int size_i=MaxSize,size_p=MaxSize;
 size_i = strlen(inf) + 1;
    for(int i = 0; i < size_i; i++)
    {
        if(inf[i] <= '9' && inf[i] >= '1')
            postf[size_p++] = inf[i];
        else if(inf[i] == '(')
            st_c.push(inf[i]);
        else if(inf[i] == ')')
        {
            while(st_c.put() != '(')
            {
                postf[size_p++] =st_c.put();
                st_c.peek();
            }
 
            st_c.peek();
        }
        else if(inf[i] == '+' || inf[i] == '-' || inf[i] == '*' || inf[i] == '/' || inf[i] == '^')
        {
            postf[size_p++] = ' ';
 
            if(st_c.isEmpty())
                st_c.push(inf[i]);
            else
            {
                 if(prior(inf[i]) > prior(st_c.put()))
                    st_c.push(inf[i]);

                else
                {
                    postf[size_p--] = ' ';
                    while(!st_c.isEmpty() && prior(st_c.put()) >= prior(inf[i]))
                    {
                        postf[size_p++] = st_c.put();
                        st_c.peek();
                    }
 
                    st_c.push(inf[i]);
                    postf[size_p++] = ' ';
                }

            }
        }
    }
 
    while(!st_c.isEmpty())
    {
        postf[size_p++] = st_c.put();
        st_c.peek();
    }
	 
}*/