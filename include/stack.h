#include <iostream>

using namespace std;

template <class T>
class Stack
{
protected:
	T* pStack; 
	int Size;		
	int Index;	
public:
	Stack(int s = 10);
	Stack(const Stack& v);			
	~Stack();
	void Push(T elem);		
	T Pop();	
	T& Top();		
	bool IsEmpty();		
	int GetSize() { return (Index + 1); }	
	void Clean();		

};

template <class T>
Stack<T>::Stack(int s)
{
	if (s < 0)
		throw ("Error");
	Size = s;
	Index = -1;
	pStack = new T[Size];
} 

template <class T>
Stack<T>::Stack(const Stack<T>& v)
{
	Size = v.Size;
	Index = v.Index;
	pStack = new T[Size];
	for (int i = 0; i < Index; i++)
		pStack[i] = v.pStack[i];
} 

template <class T>
Stack<T>::~Stack()
{
	delete[] pStack;
} 

template <class T>
void Stack<T>::Push(T elem)
{
	if ((Size - Index) >= 1)
	{
		Index += 1;
		pStack[Index] = elem;
	}
	else
		if ((Size - Index) == 0)
		{
			T* pStackNew = new T[Size + 10];
			for (int i = 0; i < Index + 1; i++)
			{
				pStackNew[i] = pStack[i];
			}
			Index = Index + 1;
			pStackNew[Index] = elem;
			delete[] pStack;
			pStack = pStackNew;
			Size = Size + 10;

		}
} 

template <class T>
T Stack<T>::Pop()
{
	return pStack[Index--];
} 

template <class T>
T& Stack<T>::Top()
{
	return pStack[Index];
} 

template <class T>
bool Stack<T>::IsEmpty()
{
	if (Index < 0)
		return 1;
	else
		return 0;
} 

template <class T>
void  Stack<T>::Clean()
{
	Index = -1;
} 