#ifndef __ARITHMETIC_H__
#define __ARITHMETIC_H__

#include "stack.h"
#include <iostream>
#include <cstring>

using namespace std;

class Check
{
public:
	char *s;

	Check(char* s); 
	bool CheckBrackets();
	bool CheckOperands();
	void PickOut(char *type0, char *type1, char *type2);
	int Prioritet(char s);
	char* ChangeExpression();
	bool IsOperation(char s);
};
#endif