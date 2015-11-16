#include "stack.h"
#include <iostream>
using namespace std;

bool Check(char *s);
void main()
{

	TStack<int> s1(5);

	s1.push(1);
	s1.push(2);
	s1.push(3);
	s1.push(4);
	s1.push(5);
	s1.printStack();

	char a[7]={'(','(','a','*','b',')',')'};

	if(Check(a))
		cout<<"Verno" <<endl;
}
bool Check(char *s) {
	TStack<char> St;
	int i=0;
	while (s[i] != '0'){
		if (s[i] =='(')
			St.push('(');
		if (s[i] == ')')
			if (St.isEmpty())
				return false;
			else St.put();
			i++;
	}
	return St.isEmpty();
}