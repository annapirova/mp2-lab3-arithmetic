// объявление и реализация шаблонного стека
// стек поддерживает операции: 
// - вставка элемента, +
// - извлечение элемента, +
// - просмотр верхнего элемента (без удаления)+
// - проверка на пустоту,+ 
// - получение количества элементов в стеке+
// - очистка стека+
// при вставке в полный стек должна перевыделяться память
#include <iostream>

#define MAX_Size 1000

using namespace std;

template <class T>
class Stack
{
protected:
	T *pStack; 
	int Size;  
	int index;   
public:
	Stack(int s = 10);
	Stack(const Stack<T> &St);

	~Stack();

	void push(const T &elem);
	T pop(); 
	T view() const { return pStack[index - 1]; }; 
	int getSize() const { return Size; }; 
	int getIndex() { return index; }
	bool IsEmpty() { return index == 0; }; 
	void clear() { index = 0; };
};


template <class T>
Stack<T>::Stack(int S)
{
	if ((S >= 0) && (S < MAX_Size))
	{
		Size = S;
		pStack = new T[Size];
		index = 0;
	}
	else
		throw "error";
}


template <class T>
Stack<T>::Stack(const Stack<T> &St)
{
	Size = St.Size;
	index = St.index;
	pStack = new T[Size]; 

	for (int i = 0; i < index; i++)
		pStack[i] = St.pStack[i];
}


template <class T>
Stack<T>::~Stack()
{
	delete[] pStack;
}


template <class T>
void Stack<T>::push(const T &value)
{
	if (index<Size)
		pStack[index++] = value;
	else
	{
		if (Size + (Size + 2) / 2 <= MAX_Size) 
		{
			Size += (Size + 2) / 2;
			T* TempStack = new T[Size];
			for (int i = 0; i < index; i++)
				TempStack[i] = pStack[i];
			TempStack[index++] = value;
			delete[] pStack;
			pStack = new T[Size];
			for (int i = 0; i < index; i++)
				pStack[i] = TempStack[i];
			delete[] TempStack;
		}
		else
			throw "error";
	}
}


template <class T>
T Stack<T>::pop()
{
	if (!IsEmpty())
	{
		index--;
		return pStack[index];
	}
	else
		throw "error";
}