#include "arithmetic.h"



bool CheckSkob(char *s) { //Проверка скобок
	TStack<char> St;
	int i=0;
	while (s[i] != '\0'){
		if (s[i] =='(')
			St.push('(');
		if (s[i] == ')')
		{
			if (St.isEmpty())
				return false;
			else 
				St.put();
		}
		i++;
	}
	if (St.isEmpty())
		return true;
	else 
		cout<<"Ошибка в расставлении скобок!"<<endl;

}
int DType(char s) //1-цифра; 2-буква 3-знаки операций;
{
	char operand[]="+-*/";
	int flag=0;

	if (isdigit(s))
		return 1;
	else if (isalpha(s))
		return 2;
	else if((s=='.')||(s==','))
		return 4;
	else 
	{
		for(int i=0;i<4;i++)
			if (s==operand[i])
			{
				flag=1;
				break;
			}
			if(flag==1)
				return 3;
			else 
			{
				cout << "";
				return 0;
			}
	}

}
bool CheckOperands(char* s)// проверка на недостаток операндов
{
	char operat[]="-+*/";
	int flag=0;
	for (int i=1;i<4;i++)
	{
		if (s[0]==operat[i])
		{
			cout<< "Мало операндов" << endl;
			flag=1;
			break;
		}
	}

	for (int i=0;i<4;i++)
	{
		if (s[strlen(s)-1]==operat[i])
		{
			cout<< "Мало операндов" << endl;
			flag=1;
			break;
		}
	}
	if (flag==1)
		return false;
	else
		return true;
}
bool CheckOper(char *s)//проверка на количество операций подряд
{
	char operat[]="-+*/";
	int flag=0;
	for (int i=0;i<strlen(s);i++)
	{
		for(int j=0;j<4;j++)
			if (s[i]==operat[j])
			{
				for(int j=0;j<4;j++)
					if (s[i+1]==operat[j])
					{
						cout<< "Два знака операции подряд"<< endl;
						flag=1;
						break;
					}
					if (flag==1)
						break;
			}
			if (flag==1)
				break;
	}
	if (flag==1)
		return false;
	else
		return true;
}
bool CheckAll(char* s)//проверка условий
{
	if((CheckSkob(s))&&(CheckOperands(s))&&(CheckOper(s)))
		return true;
	else
		return false;
}
void InPoint(char *s)
{
	int len = strlen(s);
	for (int i=0;i<len;i++)
	{
		if (DType(s[i])==4)
		{
			if (s[i]==',')
				s[i]='.';
		}
	}
}