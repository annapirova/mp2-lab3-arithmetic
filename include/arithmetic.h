#ifndef _ARITHMETIC__H_
#define _ARITHMETIC__H_

#include <iostream>
#include "stack.h"

using namespace std; 

//ѕроверка корректности открывающих и закрывающих скобок
bool CheckParenthesis(char* str)
{
	TStack<int> s(100);

	int s_str=strlen(str);

	for(int i=0; i < s_str; i++)
	{
		if(str[i]=='(')
			s.PutElem(i);
		else 
			if(str[i]==')')
				if (s.StEmpty())
					throw("excess close parenthesis");
				else
					s.ExcludeElem();		
	}

	if (s.StEmpty())
		return true;
	else 
	{
		cout<<"Uncorectly close and open parenthesis"<<endl;
		return false;
	}


}

//ѕроверка наличи€ операндов между операторами
bool CheckOperator(char *s) 
{
	int s_str=strlen(s);

	char operators[]="+-*/";

	for(int i = 0; i < s_str-1;i++)
	{
		for(int j = 0; j < 4; j++)
			if ( s[i]==operators[j] )
				for(int k = 0; k < 4; k++)
					if (s[i+1]==operators[k])
					{
						cout<<"No operand between operators"<<endl;
						return false;

					}
	}


	return true;
}



#endif