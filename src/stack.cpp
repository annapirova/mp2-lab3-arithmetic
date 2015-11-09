#include "stack.h"

TStack::TStack()
{
	Size = MSize;
	pMem = new int[Size];
	Index = -1;

	for (int i = 0; i < Size; i++)
	{
		pMem[i] = 0;
	}
}

TStack::TStack(int n)
{
	if (n<0)
		throw("Negative size");
	Size=n;
	pMem= new int[Size];
	Index = -1;
	for (int i = 0; i < Size; i++) {
		pMem[i] = 0;
	}
}
TStack::~TStack()
{
	delete[]pMem;
}

bool TStack::StEmpty (void) const
{
	if(Index==-1)
		return true;
	return false;
}
bool TStack::StFull (void) const
{
	if( Index == Size-1)
		return true;
	return false;
}
void TStack::PutElem(const int el)
{
	if ((*this).StFull())
		throw ("Full stack");
	
	pMem[Index++] = el;
}

int TStack::GetElem()
{
	if ((*this).StEmpty())
		throw ("Empty stack");
	int a=pMem[Index];

	pMem[--Index];

	return a;
}