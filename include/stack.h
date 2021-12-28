
#ifndef __TSTACK_H__
#define __TSTACK_H__
#define STACK_SIZE (1000)
#include <vector>

template <class StackType>
class TStack
{
protected:
    int Head;
    int Size;
    StackType* mStack;
    void Overcrowded();     // Проверка на переполнение 
public:
    //Конструкторы и деструкторы
    TStack();
    ~TStack();
    //Операции со стеком
    void Push(StackType i); // Вставка элемента
    StackType Pop();        // Извлечение элемента
    StackType Top();        // Просмотр верхнего элемента (без удаления)
    bool Empty();           // Проверка на пустоту 
    int Count();            // Получение количества элементов в стеке
    void Clear();           // Очистка стека
};

//Реализация функций класса вектора 
//Конструкторы и деструкторы    
template <class StackType>
TStack<StackType>::TStack()
{
    Head = 0;
    Size = STACK_SIZE;
    mStack = new StackType[Size];
}
template <class StackType>
TStack<StackType>::~TStack()
{
    delete[] mStack;
}
//Операции со стеком
template <class StackType> // Вставка элемента
void TStack<StackType>::Push(StackType i)
{
    Overcrowded();
    mStack[Head] = i;
    Head++;
}
template <class StackType> // Извлечение элемента
StackType TStack<StackType>::Pop()
{
    if (!Empty())
    {
        Head--; return mStack[Head];
    }
    else { throw 1; }
}
template <class StackType> // Просмотр верхнего элемента (без удаления)
StackType TStack<StackType>::Top()
{
    if (!Empty()) { return mStack[Head - 1]; }
    else { throw 1; }
}
template <class StackType> // Проверка на пустоту
bool TStack<StackType>::Empty()
{
    if (Head == 0) { return 1; }
    else { return 0; }
}
template <class StackType> // Получение количества элементов в стеке
int TStack<StackType>::Count()
{
    return Head;
}
template <class StackType> // Очистка стека
void TStack<StackType>::Clear()
{
    Head = 0;
}
template <class StackType> // Проверка на переполнение 
void TStack<StackType>::Overcrowded()
{
    if (Head == Size)
    {
        StackType* mStack1;
        mStack1 = mStack;
        Size = Size * 2;
        mStack = new StackType[Size];
        for (int i = 0; i < Size / 2; i++)
        {
            mStack[i] = mStack1[i];
        }
    }
}
#endif