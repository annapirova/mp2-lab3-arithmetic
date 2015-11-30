#pragma once
#include <string>
#include "stack.h"


int DType(char s);
bool CheckSkob(char *s);
bool CheckOperands(char* s);
bool CheckOper(char *s);
int prior (char a);
bool CheckAll(char* s);
void InPoint(char *s);
