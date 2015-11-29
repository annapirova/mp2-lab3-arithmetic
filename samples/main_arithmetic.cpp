#include "stack.h"
#include "arithmetic.h"
#include "parser.h"

#include <locale>
#include <iostream>
using namespace std;



void main()
{
	setlocale(LC_CTYPE, "Russian");

	char a[5]={'(','a','+','b',')'};
	TParser x(a);
	//x.inf_to_postf();
}
