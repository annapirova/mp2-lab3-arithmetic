#include "stack.h"
#include <string.h>
#include <memory.h>
#include <iostream>


Stack :: Stack(int n)
{
	if(n < 0)
		throw "Error";
	else
	{
		N = n;
		st = new int [N];
		Top = -1;
	}
}

Stack :: Stack(const Stack &s)
{
	N = s.N;
	Top = s.Top;
	st = new int [N];
	memcpy(st, s.st, sizeof(int)*N);
}
			   
void Stack :: Push( int x)
{
	Top++;
	st[Top] = x; 
}

int Stack :: Get()
{
	//Stack res(st.N);
	int temp = st[Top]; 
	Top--;
	return temp;
}

bool Stack :: IsEmpty()
{
	if(Top == (-1))
		return true;
	else 
		return false;
}

bool Stack :: IsFull()
{
	if(Top == (N - 1))
		return true;
	else 
		return false;
}

Stack :: ~Stack()
{
	delete []st;
}


std::ostream& operator<<(std::ostream &os, const Stack &s)
  {
	  for( int i = 0; i < s.Top + 1; i++) 
		os << s.st[i] << ' ';
    return os;
  }
