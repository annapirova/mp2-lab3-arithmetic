#ifndef _TSTACK_H_
#define _TSTACK_H_

#include <iostream>

#define MSize 20

template <class ValType>
class TStack
{
protected:
	ValType *pMem;
	int Size;
	int Index;
public:
	TStack();
	TStack(int n);
	~TStack();

	bool StEmpty (void) const;
	bool StFull (void) const;
	
	void PutElem(const ValType &el); //добавить элемент в вершину стека 
	ValType GetElem();              //удалить элемент из стека


};

template <class ValType>
TStack<ValType>::TStack()
{
	Size = MSize;
	pMem = new ValType[Size];
	Index = -1;

	for (int i = 0; i < Size; i++)
	{
		pMem[i] = 0;
	}
}

template <class ValType>
TStack<ValType>::TStack(int n)
{
	if (n<0)
		throw("Negative size");
	Size=n;
	pMem= new ValType[Size];
	Index = -1;
	for (int i = 0; i < Size; i++) {
		pMem[i] = 0;
	}
}

template <class ValType>
TStack<ValType>::~TStack()
{
	delete[]pMem;
}

template <class ValType>
bool TStack<ValType>::StEmpty (void) const
{
	if(Index==-1)
		return true;
	return false;
}

template <class ValType>
bool TStack<ValType>::StFull (void) const
{
	if( Index == Size-1)
		return true;
	return false;
}

template <class ValType>
void TStack<ValType>::PutElem(const ValType &el)
{
	if ((*this).StFull())
		throw ("Full stack");
	Index+=1;
	pMem[Index] = el;
	
}

template <class ValType>
ValType TStack<ValType>::GetElem()
{
	if ((*this).StEmpty())
		throw ("Empty stack");
	ValType a=pMem[Index];

	pMem[--Index];

	return a;
}

#endif