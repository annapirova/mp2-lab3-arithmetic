// ���������� � ���������� ���������� �����
// ���� ������������ ��������: 
// - ������� ��������, 
// - ���������� ��������, 
// - �������� �������� �������� (��� ��������)
// - �������� �� �������, 
// - ��������� ���������� ��������� � �����
// - ������� �����
// ��� ������� � ������ ���� ������ �������������� ������
#ifndef STACK_H
#define STACK_H
#include <iostream>
using namespace std;
template <typename T>
class Stack {
private:
	T* st;
	int capasity;
	int size;
public:
	Stack();
	Stack(int s);
	Stack(const Stack<T>&);
	~Stack();
	bool Stack<T> ::isFull();
	bool Stack<T> ::isNotFull();
	void Stack<T>::push(const T& v);
	T Stack<T>::pop();
	T Stack<T>::getStack();
	int Getcapasity() { return capasity; }
	void Stack<T>::clear(/*const T& v*/);
};  
	template <typename T>
	Stack<T>::Stack() {
		capasity = 10; 
		st = new T[capasity];
		size = 0;
	}

	template <typename T>
	Stack<T>::Stack(int s) {
		capasity = s;
		st = new T[capasity];
		size = 0;
	}

	template <typename T>
	Stack<T>::Stack(const Stack<T>& otherStack) {
		capasity = otherStack.capasity;
		st = new T[capasity];
		size = otherStack.size;
		for (int i = 0; i < capasity; i++)
			st[i] = otherStack.st[i];
	}

	template <typename T>
	Stack<T>::~Stack()
	{ 
		delete[] st; 
	}

	template <typename T>
	bool Stack<T> ::isFull() { // �������� �� �������
		if (size == capasity) { 
			return true;
		}
		else {
			return false;
		}
	}

	template <typename T>
	bool Stack<T>::isNotFull() { // �������� �� �������
		if (size !=0) {
			return false;
		}
		else {
			return true;
		}
	}

	template <typename T>
	void Stack<T>::push(const T& v) { // �������� �������
		/*if (capasity == size + 1) {
			int tmpCapasity = capasity;
			T* tmpSt = new T[tmpCapasity];
			for (int i = 0; i < tmpCapasity; i++)
			{
				tmpSt[i] = st[i];
			}
			delete[]st;
			capasity = capasity + capasity;
			for (int i = 0; i < capasity; i++)
			{
				st[i] = tmpSt[i];
			}
			delete[]tmpSt;
		}
		st[size] = v;
		size++;*/
		if (size == capasity) {
			auto tmpCapasity = capasity;
			T* tmpContent = new T[tmpCapasity];
			for (int i = 0; i < size; ++i) {
				tmpContent[i] = st[i];
			}
			delete[]st;
			capasity = capasity + capasity;
			st = new T[capasity];
			for (int i = 0; i < tmpCapasity; ++i) {
				st[i] = tmpContent[i];
			}
		}
		size++;
		st[size - 1] = v;
	}

	template <typename T>
	T Stack<T>::getStack() { // ������� �������
		return st[size - 1];
		st[size - 1] == NULL;
		size--;
	}

	template<typename T>
    void Stack<T>::clear(/*const T& v*/)
	{
		size = 0;
	}

	template <typename T>
	T Stack<T>::pop() { // �������� �������
			return st[size -1];
	}

#endif