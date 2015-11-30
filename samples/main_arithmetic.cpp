#include "stack.h"
#include "arithmetic.h"
#include "parser.h"

#include <locale>
#include <iostream>
using namespace std;



void main()
{
	setlocale(LC_CTYPE, "Russian");

	char a[]="(9+3)/4";
	TParser x(a);
	x.Convert();
	double res=x.calc();
	cout<<endl<<res;
	
}
