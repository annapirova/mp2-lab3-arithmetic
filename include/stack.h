#ifndef STACK_H
#define STACK_H

#include <cassert> // для assert
#include <iostream>

#include <iomanip> // для setw

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
	void printStack();         // вывод стека на экран
	int getStackSize() const;  // получить размер стека
	bool IsEmpty(void);         //ПУСТ?
	bool IsFull(void);          //ПОЛОН?
	int getTop() const;        // получить номер текущего элемента в стеке
};

// реализация методов шаблона класса STack

// конструктор Стека
template <typename T>
Stack<T>::Stack(int _size,int _top) 
{	size = _size; // инициализация константы

	stackPtr = new T[size]; // выделить память под стек
	top = _top; // инициализируем текущий элемент нулем;
	for (int i = 0; i < size; i++)
		stackPtr[i] = T();
}

// конструктор копирования
template <typename T>
Stack<T>::Stack(const Stack<T> & otherStack) 
{
	size = otherStack.size;// инициализация константы
	stackPtr = new T[size]; // выделить память под новый стек
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
	assert(top < size); // номер текущего элемента должен быть меньше размера стека

	stackPtr[top++] = value; // помещаем элемент в стек
}

// функция удаления элемента из стека
template <typename T>
 T Stack<T>::pop()
{
	// проверяем размер стека
	assert(top > 0); // номер текущего элемента должен быть больше 0
		top--;
	T temp = stackPtr[top];
	stackPtr[top] = T();
	return temp;// удаляем элемент из стека
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
	 if (top + 1 == size)
		 return true;
	 else
		 return false;
 }

 template <class T>
 bool Stack<T>::IsEmpty(void)
 {
	 if (top == NULL)
		 return true;
	 else
		 return false;
 }
#endif // STACK_H
