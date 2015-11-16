#include "stack.h"
#include <iostream>
using namespace std;


void main()
{
	
	TStack<int> s1(5);
	
	s1.push(1);
	s1.push(2);
	s1.push(3);
	s1.push(4);
	s1.push(5);
	s1.push(6);

	s1.printStack();
	
	
	
  
}