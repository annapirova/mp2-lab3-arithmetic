#include "stack.h"
#include "arithmetic.h"
#include "parser.h"

#include <locale>
#include <iostream>
using namespace std;



void main()
{
	setlocale(LC_CTYPE, "Russian");

	char a[5]={'(','7','+','5',')'};
	TParser x(a);
	double res;
	res=x.calc1();
}
