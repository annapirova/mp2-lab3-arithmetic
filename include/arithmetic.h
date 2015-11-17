#ifndef __ARITHMETIC_H__
#define __ARITHMETIC_H__

#include "stack.h"
#include <iostream>
#include <cstring>

using namespace std;

bool CheckBrackets(char* s);
bool CheckOperands(char* s);
void PickOut(char *s, char *type0, char *type1, char *type2);

#endif