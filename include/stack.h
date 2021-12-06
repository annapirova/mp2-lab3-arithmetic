#ifndef STACK_H
#define STACK_H


#include <iostream>
using namespace std;

const int MAX_STACK_SIZE = 100000;

template <class T>
class Stack
{
private:

    T* pStack;
    int Size;                  //размер
    int TopIndex;              //индекс вершины стека

public:

    Stack(int s);               //конструктор +
    Stack(const Stack<T>& st);  //конструктор копирования +
    ~Stack();                   //деструктор +

    void Push(const T elem);      //вставка элемента +
    T Pop();                    //извлечение элементы +
    T Peek();                   //просмотр верхнего элемента (без удаления) + 
    bool IsEmpty();             //проверка на пустоту, +
    int GetSize();              //получение количества элементов в стеке +
    bool Clear();               //очистка элементов +
};

template<class T>
Stack<T>::Stack(int s)
{
    if (s<0 || s>MAX_STACK_SIZE)
        throw "error";
    
    pStack = new T[s];
    Size = s;
    TopIndex = -1;

    for (int i = 0; i < Size; i++)
        pStack[i] = 0;
        
}

template<class T>
Stack<T>::Stack(const Stack<T>& st)
{
    Size = st.Size;
    TopIndex = st.TopIndex;
    pStack = new T[Size];

    for (int i = 0; i < TopIndex+1; i++)
        pStack[i] = st.pStack[i];
}

template<class T>
Stack<T>::~Stack()
{
    delete[] pStack;
}

template<class T>
void Stack<T>::Push(const T st)
{
    if (TopIndex >= Size)
        throw "error";
    else 
    {
        TopIndex++;
        pStack[TopIndex] = st;
    }
}

template<class T>
T Stack<T>::Pop()
{
    if(IsEmpty())
        throw "stack is empty";
    else
        return pStack[TopIndex--];
}

template<class T>
T Stack<T>::Peek()
{
    if (IsEmpty())
        throw "stack is empty";
    else
        return pStack[TopIndex];
}

template<class T>
bool Stack<T>::IsEmpty()
{
    if (TopIndex == -1) 
        return true; 
    else 
        return false;
}

template<class T>
int Stack<T>::GetSize()
{
    return Size;
}

template<class T>
bool Stack<T>::Clear()
{
    return TopIndex = -1;
}

#endif