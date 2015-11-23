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
	bool CheckBrackets(Check br);
	bool CheckOperands(Check br);
	void PickOut(Check br, char *type0, char *type1, char *type2);
	int Prioritet();

};
#endif