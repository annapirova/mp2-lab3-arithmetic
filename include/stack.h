#ifndef __TSTACK_H__
#define __TSTACK_H__

#include <iostream>

using namespace std;

const int MAX_STACK_SIZE = 1000;

template <class T>
class TStack
{
protected:
	T* pStack;
	int Size;
	int top;
public:
	TStack(int s = 10);
	TStack(const TStack& st);
	~TStack();
	bool operator==(const TStack& st) const;
	TStack& operator=(const TStack& st);
	void Push(T elem);
	T Pop();
	T Top();
	bool IsEmpty();
	int GetSize();
	void Clean();
};

template <class T>
TStack<T>::TStack(int s)
{
	Size = s;
	if (Size<0 || Size>MAX_STACK_SIZE)
		throw "error";
	pStack = new T[s];
	top = 0;
}

template <class T>
TStack<T>::TStack(const TStack<T>& st)
{
	Size = st.Size;
	top = st.top;
	pStack = new T[Size];
	for (int i = 0; i < top; i++)
		pStack[i] = st.pStack[i];
}

template <class T>
TStack<T>::~TStack()
{
	delete[] pStack;
}

template <class T>
TStack<T>& TStack<T>::operator=(const TStack& st)
{
	if (this != &st)
	{
		if (Size != st.Size)
		{
			delete[] pStack;
			pStack = new T[st.Size];
		}
		Size = st.Size;
		top = st.top;
		for (int i = 0; i < top; i++)
			pStack[i] = st.pStack[i];
	}
	return *this;
}

template <class T>
bool TStack<T>::operator==(const TStack& st) const
{
	if (this != &st)
	{
		if ((Size == st.Size) && (top == st.top))
		{
			for (int i = 0; i < top; i++)
				if (pStack[i] != st.pStack[i])
					return false;
			return true;
		}
		else
			return false;
	}
	return true;
}

template <class T>
bool TStack<T>::IsEmpty()
{
	if (top == 0)
		return true;
	else
		return false;
}

template<class T>
void TStack<T>::Push(T elem)
{
	if ((Size - top) == 0)
	{
		T* st1;
		st1 = new T[2 * Size];
		for (int i = 0; i < top; i++)
			st1[i] = pStack[i];
		delete[] pStack;
		pStack = st1;

		pStack[top] = elem;
		top++;

		Size = 2 * Size;
	}
	else
	{
		pStack[top] = elem;
		top += 1;
	}
}

template<class T>
T TStack<T>::Pop()
{
	if (!IsEmpty())
	{
		top = top - 1;
		return pStack[top];
	}
	else
		throw "empty";
}

template<class T>
T TStack<T>::Top()
{
	if (!IsEmpty())
	{
		return pStack[top - 1];
	}
	else throw "empty";
}

template<class T>
int TStack<T>::GetSize()
{
	return top;
}

template<class T>
void TStack<T>::Clean()
{
	top = 0;
}

#endif
