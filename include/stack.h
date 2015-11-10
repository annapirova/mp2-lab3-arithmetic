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
	ValType& operator[](int pos) const;
public:
	TStack(int s = 10, int si = 0);
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

	template <class ValType>
	friend ostream& operator<<(ostream &out, const TStack &v) 
	{
		for (int i = 0; i < v.Size + v.ActualIndex; i++)
			out << v[i] << ' ';
		return out;
	}
};

template <class ValType>
TStack<ValType>::TStack(int s) 
{
	if (s > MAX_STACK_SIZE) 
		throw invalid_argument("CONSTRUCTOR: MAX_STACK_SIZE < SIZE");
	
	if (s < 0) 
		throw invalid_argument("CONSTRUCTOR: SIZE < 0");
	
	if (si < 0) 
		throw invalid_argument("CONSTRUCTOR: START INDEX < 0");

	if (!(si < s)) 
		throw invalid_argument("CONSTRUCTOR: START INDEX >= SIZE");
	
	pVector = new ValType[s];
	Size = s;

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

template <class ValType> // доступ
ValType& TStack<ValType>::operator[](int pos) const 
{
	if (pos < 0) 
		throw invalid_argument("[] ARGUMENT < 0");
	
	if (!(pos < Size)) 
		throw invalid_argument("[] ARGUMENT > SIZE");
	
	return pVector[pos];
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
	if (GetActualIndex() + 1 == GetSize())
		return true;
	else
		return false;
} /*-------------------------------------------------------------------------*/

template <class ValType>
void TStack<ValType>::SetElem(ValType n)
{
	if (IsFull())
		throw invalid_argument("Stackowerflow");
	if (IsEmpty())
	{
		(*this)[GetActualIndex()] = n;
		IncActualIndex();
	}
	else
		throw invalid_argument("Crash actual index");
} /*-------------------------------------------------------------------------*/

template <class ValType>
ValType TStack<ValType>::GetElem(void)
{
	if (IsEmpty())
		throw invalid_argument("Stack is empty");

	ValType temp;
	DecActualIndex();
	temp = (*this)[GetActualIndex()];
	(*this)[GetActualIndex()] = ValType();

	return temp;
} /*-------------------------------------------------------------------------*/

