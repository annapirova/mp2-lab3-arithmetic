#ifndef __STACK_H___
#define __STACK_H___

#include <iostream>
#include <memory>
using namespace std;


class Stack 
{
	public:
		int *st;
		int N;  //  размер стекового поля
		int Top;  //  индекс первого элемента

		
		Stack(int Max);
		Stack(const Stack &s);
		void Push(int x);  // добавить элемент
		int Get();  //  получиить элемент с удалением
		bool IsEmpty();  //  проверка пустоты
		bool IsFull();  //  проверка полноты
		~Stack();  //  деструктор
		friend ostream& operator<<(ostream &os, const Stack &s);
};		
#endif
