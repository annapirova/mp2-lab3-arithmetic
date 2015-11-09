#include <gtest.h>
#include "stack.h"
#include <iostream>
using namespace std;
int main(int argc, char **argv) {
	int a;
	cout << "BBedute pa3mepHoctb Bedpa" << endl;
	cin >> a;
	cout << endl;
	Stack<int> STAK(a,0);
	int ct = 0;
	int ch;

	while (ct++ < a)
	{
		cin >> ch;
		STAK.push(ch); // помещаем элементы в стек
	}
	cout << endl;

	STAK.printStack(); // печать стека

	cout << "Ydalum elemeHt u3 Bedpa" << endl;
	int aza;
	aza=STAK.pop();
	cout <<"YdaJluJlu: "<< aza << endl;

	STAK.printStack(); // печать стека

	Stack<int> newStack(STAK);

	cout << "Cpa6otaJl koHctpyktop konupoBaHu9"<<endl;
	newStack.printStack();
	cout << "do6aBum elemeHt 9" << endl;
	STAK.push(9);
	STAK.printStack();


    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
	


	return 0;
}
