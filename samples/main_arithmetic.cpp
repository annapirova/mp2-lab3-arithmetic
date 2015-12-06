#include "stack.h"
#include "arithmetic.h"
#include "parser.h"

#include <locale>
#include <iostream>
using namespace std;



void main()
{
	setlocale(LC_CTYPE, "Russian");
	int flag=1;
	char a[MaxSize];
	cout << "¬ведите арифмитическое выражение:";
	while (flag==1){
		gets(a);
		if(!CheckAll(a))
			cout << "¬ведите выражение заново:"; 
		else
		{
			InputVar(a);
			InPoint(a);
			TParser x(a);
			x.Convert();
			double res=x.calc();
			cout<<"Result="<<res<<endl;
			flag=0;
		}
	}
}