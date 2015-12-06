#pragma once
#include <string>
#include "stack.h"
#include <locale>
#include <iostream>
using namespace std;

const int MaxSize=256;


int DType(char s);
bool CheckSkob(char *s);
bool CheckOperands(char* s);
bool CheckOper(char *s);
int prior (char a);
bool CheckAll(char* s);
void InPoint(char *s);
bool operand_true(char a);
bool operand_true_1(char *c);
void InputVar(char *s);
bool CheckUnarMinus(char *s);
void UnarMinus(char *s);