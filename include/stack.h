#ifndef _TSTACK_H_
#define _TSTACK_H_

#include <iostream>

#define MSize 20

class TStack
{
protected:
	int *pMem;
	int Size;
	int Index;
public:
	TStack();
	TStack(int n);
	~TStack();

	bool StEmpty (void) const;
	bool StFull (void) const;
	
	void PutElem(const int el); //добавить элемент в вершину стека 
	int GetElem();              //удалить элемент из стека


};



#endif