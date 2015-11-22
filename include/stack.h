#ifndef STACK_H
#define STACK_H


#include <iostream>


template <typename T>
class Stack
{
private:
	T *stackPtr;                      // указатель на стек
	int size;                   // максимальное количество элементов в стеке
	int top;                          // номер текущего элемента стека
public:
	Stack(int _size = 10, int _top = 0);                  // по умолчанию размер стека равен 10 элементам
	Stack(const Stack<T> &);          // конструктор копирования
	~Stack();                         // деструктор

	void push(const T &);     // поместить элемент в вершину стека
	T pop();                   // удалить элемент из вершины стека и вернуть его
	int Peek() ;
	void printStack();         // вывод стека на экран
	int getStackSize() const;  // получить размер стека
	bool IsEmpty(void);         //ПУСТ?
	bool IsFull(void);          //ПОЛОН?
	int getTop() const;        // получить номер текущего элемента в стеке
	Stack<T>& operator=(const Stack& s);//оператор равно
	bool operator!=(const Stack<T> &s) const ;//сравнение 1
	bool operator==(const Stack<T> &s) const ;//сравнение 1
	void SetSize(int n);//изменение размера

};

// реализация методов шаблона класса STack

// конструктор Стека
template <typename T>
Stack<T>::Stack(int _size,int _top) 
{	size = _size; 

	stackPtr = new T[size]; 
	top = _top; // инициализируем текущий элемент нулем;
	for (int i = 0; i < size; i++)
		stackPtr[i] = T();
}

// конструктор копирования
template <typename T>
Stack<T>::Stack(const Stack<T> & otherStack) 
{
	size = otherStack.size;
	stackPtr = new T[size]; 
	top = otherStack.top;
	for (int i = 0; i < size; i++)
		stackPtr[i] = T();
	for (int i= 0; i < top; i++)
		stackPtr[i] = otherStack.stackPtr[i];
}

// функция деструктора Стека
template <typename T>
Stack<T>::~Stack()
{
	delete[] stackPtr; // удаляем стек
}

// функция добавления элемента в стек
template <typename T>
void Stack<T>::push(const T &value)
{
	// проверяем размер стека
	if (top >= size) // номер текущего элемента должен быть меньше размера стека
		throw ("stek zapolnen");

	stackPtr[top++] = value; // помещаем элемент в стек
}

// функция удаления элемента из стека
template <typename T>
 T Stack<T>::pop()
{
	// проверяем размер стека
	if (top <= 0)
	throw ("stek pust");// номер текущего элемента должен быть больше 0
		top--;
	T temp = stackPtr[top];
	stackPtr[top] = T();
	return temp;// удаляем элемент из стека
}
template <typename T>
 int Stack<T>::Peek()
{
	if (top == 0)
	{
		throw ("stek pust!");
	}
	return stackPtr[top-1];
}


// вывод стека на экран
template <typename T>
 void Stack<T>::printStack()
{
	for (int i = top-1; i >=0; i--)
		cout << "| "	<<stackPtr[i]<<endl;
}

// вернуть размер стека
template <typename T>
 int Stack<T>::getStackSize() const
{
	return size;
}

// вернуть номер вершины
template <typename T>
 int Stack<T>::getTop() const
{
	return top;
}

 template <class T>
 bool Stack<T>::IsFull(void)
 {
	 if (top == size)
		 return true;
	 else
		 return false;
 }

 template <class T>
 bool Stack<T>::IsEmpty(void)
 {
	 if (top == 0)
		 return true;
	 else
		 return false;
 }
  template <class T>
 Stack<T>& Stack<T>::operator=(const Stack& s)
{
	if (stackPtr == s.stackPtr)
	{
		return *this;
	}
	size = s.size;
	top = s.top;
	delete[]stackPtr;
	stackPtr = new int[size];
	for (int i = 0; i < size; i++)
	{
		stackPtr[i] = s.stackPtr[i];
	}
	return *this;
}
  template <class T>

bool Stack<T>::operator==(const Stack<T>& s) const
{
	if ((size == s.size)&&(top == s.top))
	{
		for (int i = 0; i < size; i++)
		{
			if (stackPtr[i] != s.stackPtr[i])
			{
				return false;
			}
		}
		return true;
	}
	return false;
}
 template <class T>
bool Stack<T>::operator!=(const Stack<T> &s) const 
{
	if ((*this)==s)
	{
		return false;
	}
	return true;
}
 template <class T>
void Stack<T>::SetSize(int n)
{
	if (n<0) 
	{
		throw ("new size < 0");
	}
	if (n<top)
	{
		throw ("new size < Top");
	}

	int *p = new int[top];
	for (int i = 0; i < top; i++)
	{
		p[i] = stackPtr[i];
	}

	size = n;
	delete []stackPtr;
	stackPtr = new int[size];
	for (int i = 0; i < top; i++)
	{
		stackPtr[i] = p[i];
	}
	for (int i = top; i < size;i++)
	{
		stackPtr[i] = 0;
	}
}
#endif // STACK_H
