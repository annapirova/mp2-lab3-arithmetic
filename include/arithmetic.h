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
	int len;

	Check(char* s); 
	bool CheckBrackets();
	bool CheckOperands();
	void PickOut(char *type0, char *type1, char *type2, char* type3);
	int Prioritet(char s);
	char* ChangeExpression(char *res);
	bool IsOperation(char s);
	void UnarMinus(char *res);
	bool IsUnarMinus();
	char* FindDouble(char *type0);
	char* FindInt(char *type0);
	double Calculation ();
	double GetNumber();
};
#endif