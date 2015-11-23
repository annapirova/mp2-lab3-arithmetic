#include "stack.h"
#include "arithmetic.h"
#include "parser.h"

#include <locale>
#include <iostream>
using namespace std;



void main()
{
	setlocale(LC_CTYPE, "Russian");
	TStack<int> s1(5);
	s1.push(1);
	s1.push(2);
	s1.push(3);
	s1.push(4);
	s1.push(5);
	cout <<s1;
	char a[7]={'(','(','a','*','b',')',')'};
	if(Check(a))
		cout<<"Верно" <<endl;
	else 
		cout<<"Не верно"<<endl;

}
