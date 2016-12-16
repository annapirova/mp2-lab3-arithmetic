#include <iostream>

using namespace std;

const int MAX_STACK_SIZE = 100000000;

// Шаблон вектора
template <class ValType>
class TStack {
protected:
	ValType *pVector;
	int Size;       // размер вектора
	int ActualIndex; // индекс первого элемента вектора
public:
	TStack(int s = 10);
	TStack(const TStack &v);                // конструктор копирования
	virtual ~TStack();
	int GetSize() const { return Size; } // размер вектора
	int GetActualIndex() const { return ActualIndex; } // индекс первого элемента
	void IncActualIndex() { ActualIndex += 1; }
	void DecActualIndex() { if (ActualIndex != 0) ActualIndex -= 1; else throw invalid_argument("Stack is empty"); }
	bool IsEmpty(void);
	bool IsFull(void);
	void SetElem(ValType n);
	ValType GetElem(void);
};

template <class ValType>
TStack<ValType>::TStack(int s) 
{
	if (s > MAX_STACK_SIZE) 
		throw invalid_argument("CONSTRUCTOR: MAX_STACK_SIZE < SIZE");
	
	if (s < 0) 
		throw invalid_argument("CONSTRUCTOR: SIZE < 0");
	
	pVector = new ValType[s];
	Size = s;
	ActualIndex = 0;

	for (int i = 0; i < Size; i++) 
		pVector[i] = ValType();
	
} /*-------------------------------------------------------------------------*/

template <class ValType> //конструктор копирования
TStack<ValType>::TStack(const TStack<ValType> &v) 
{
	Size = v.Size;
	ActualIndex = v.ActualIndex;
	pVector = new ValType[Size];

	for (int i = 0; i < ActualIndex; i++) 
		pVector[i] = v.pVector[i];
} /*-------------------------------------------------------------------------*/

template <class ValType>
TStack<ValType>::~TStack() 
{
	delete[] pVector;
} /*-------------------------------------------------------------------------*/


template <class ValType>
bool TStack<ValType>::IsEmpty(void)
{
	if (GetActualIndex()==0)
		return true;
	else
		return false;
} /*-------------------------------------------------------------------------*/

template <class ValType>
bool TStack<ValType>::IsFull(void)
{
	if (GetActualIndex() == GetSize())
		return true;
	else
		return false;
} /*-------------------------------------------------------------------------*/

template <class ValType>
void TStack<ValType>::SetElem(ValType n)
{
	if (IsFull())
		throw invalid_argument("Stackowerflow");

	(*this).pVector[GetActualIndex()] = n;
	IncActualIndex();
} /*-------------------------------------------------------------------------*/

template <class ValType>
ValType TStack<ValType>::GetElem(void)
{
	if (IsEmpty())
		throw invalid_argument("Stack is empty");

	ValType temp;
	DecActualIndex();
	temp = (*this).pVector[GetActualIndex()];
	(*this).pVector[GetActualIndex()] = ValType();

	return temp;
} /*-------------------------------------------------------------------------*/

