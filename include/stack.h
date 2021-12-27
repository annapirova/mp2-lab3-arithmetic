// ���������� � ���������� ���������� �����
// ���� ������������ ��������: 
// - ������� ��������, 
// - ���������� ��������, 
// - �������� �������� �������� (��� ��������)
// - �������� �� �������, 
// - ��������� ���������� ��������� � �����
// - ������� �����
// ��� ������� � ������ ���� ������ �������������� ������
#pragma once

template <class ValType>
class Stack
{
	ValType* p;
	int topindex;
	int size;
public:
	Stack(int s = 1000);
	~Stack();
	void push(ValType a);
	ValType pop();
	ValType top();
	bool isempty();
	void clean();
	int getquantity() 
	{ 
		return topindex; 
	}
	int getsize() 
	{ 
		return size;
	}
};

template <class ValType>
Stack<ValType>::Stack(int s)
{
	topindex = 0;
	size = s;
	p = new ValType[s];
}

template <class ValType>
Stack<ValType>::~Stack()
{
	delete[]p;
}

template <class ValType>
void Stack<ValType>::push(ValType a)
{
	if (topindex == size)
	{
		ValType* tmp = new ValType[size * 2];
		for (int i = 0; i < topindex; i++)
			tmp[i] = p[i];
		delete[] p;
		size = size * 2;
		p = new ValType[size];
		for (int i = 0; i < topindex; i++)
			p[i] = tmp[i];
	}
	p[topindex] = a;
	topindex += 1;
}

template <class ValType>
void Stack<ValType>::clean()
{
	topindex = 0;
}

template <class ValType>
bool Stack<ValType>::isempty()
{
	if (topindex == 0)
		return true;
	else
		return false;
}

template <class ValType>
ValType Stack<ValType>::pop()
{
	if (topindex == 0)
		throw ("������ ����");
	topindex -= 1;
	return p[topindex];
}

template <class ValType>
ValType Stack<ValType>::top()
{
	if (topindex == 0)
		throw ("������ ����");
	return p[topindex - 1];
}