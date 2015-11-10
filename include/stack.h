#pragma once
#include <cassert> 


template <typename T>

class TStack {
private:
	T *st;									//стек
	int Size;								//размер стека
	int LastIndex;							// последний элемент
public:
	TStack(int s);							//Конструктор
	TStack(const TStack<T> &St);			//Конструктор копирования
	~TStack();								//Деструктор
	int getSize() const {return Size;}		//Взять размер стека
	int getLastIndex() const {return LastIndex;}  //Взять последний элемент стека
	void push(const T &value);				//Положить элемент в стек
	void printStack();						//Печать
	//T* getPtr() const {return st;}			// вернуть указатель на стек
	bool pr1(T* &St);
};


template <typename T>
TStack<T>::TStack(int maxSize) : Size(maxSize) 
{
    st = new T[Size];						// выделить память под стек
	for (int i=0;i<Size;i++)
		st[i]=0;
    LastIndex = 0;							
}

template <typename T>
TStack<T>::~TStack()						 //деструктор
{
    delete [] st; 
}

template <typename T>                        //Конструктор копирования
TStack<T>::TStack(const TStack<T> & St) : Size(St.getSize()) 
{
    st = new T[Size];
    LastIndex = St.getLastIndex();
 
    for(int i=0;i<LastIndex;i++)
        st[i] = St.st[i];
}

template <typename T>						//Положить элемент в стек
void TStack<T>::push(const T &value)
{
    //assert(LastIndex < Size); // номер текущего элемента должен быть меньше размера стека
    pr1(st);
	st[LastIndex++] = value; // помещаем элемент в стек
}
 
template <typename T>						//Печать стека
void TStack<T>::printStack()
{
    for (int i = LastIndex - 1; i >= 0; i--)
        cout << st[i] << endl;
}

template <typename T>
bool TStack<T>::pr1(T* &St) {
	 if (LastIndex < Size)
		 return true;
	 else return false;
}


