#ifndef __STACK_H___
#define __STACK_H___

#include <iostream>
#include <memory>
using namespace std;

template <class T>
class Stack 
{
    private:
		T *st;
	public:
		int N;  //  размер стекового поля
		int Top;  //  индекс первого элемента

		
		Stack(int Max);
		Stack(const Stack &s);
		void Push(T x);  // добавить элемент
		T Get();  //  получиить элемент с удалением
		bool IsEmpty();  //  проверка пустоты
		bool IsFull();  //  проверка полноты
		~Stack();  //  деструктор

		friend ostream& operator<<(ostream &os, const Stack &s)
		{
		for( int i = 0; i < s.Top + 1; i++) 
			os << s.st[i] << ' ';
		return os;
		}
};		





template <class T>
Stack<T> :: Stack(int n)
{
	if(n < 0)
		throw "Error";
	else
	{
		N = n;
		st = new T [N];
		Top = -1;
	}
}

template <class T>
Stack<T> :: Stack(const Stack &s)
{
	N = s.N;
	Top = s.Top;
	st = new T [N];
	if (Top > -1)
		memcpy(st, s.st, sizeof(T)*Top);
}

template <class T>
void Stack<T> :: Push( T x)
{
	Top++;
	st[Top] = x; 
}

template <class T>
T Stack<T> :: Get()
{
	T temp = st[Top]; 
	Top--;
	return temp;
}

template <class T>
bool Stack<T> :: IsEmpty()
{
	if(Top == (-1))
		return true;
	else 
		return false;
}

template <class T>
bool Stack<T> :: IsFull()
{
	if(Top == (N - 1))
		return true;
	else 
		return false;
}

template <class T>
Stack<T> :: ~Stack()
{
	delete []st;
}


//std::ostream& operator<<(std::ostream &os, const Stack &s)
//  {
//	  for( int i = 0; i < s.Top + 1; i++) 
//		os << s.st[i] << ' ';
//    return os;
//  }
#endif