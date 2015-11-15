//#include "stack.h"
//#include <string.h>
//#include <memory.h>
//#include <iostream>
//
//
//
//Stack :: Stack(const Stack &s)
//{
//	N = s.N;
//	Top = s.Top;
//	st = new T [N];
//	if (Top > -1)
//		memcpy(st, s.st, sizeof(T)*Top);
//}
//			   
//void Stack :: Push( T x)
//{
//	Top++;
//	st[Top] = x; 
//}
//
//T Stack :: Get()
//{
//	T temp = st[Top]; 
//	Top--;
//	return temp;
//}
//
//bool Stack :: IsEmpty()
//{
//	if(Top == (-1))
//		return true;
//	else 
//		return false;
//}
//
//bool Stack :: IsFull()
//{
//	if(Top == (N - 1))
//		return true;
//	else 
//		return false;
//}
//
//Stack :: ~Stack()
//{
//	delete []st;
//}
//
//
//std::ostream& operator<<(std::ostream &os, const Stack &s)
//  {
//	  for( int i = 0; i < s.Top + 1; i++) 
//		os << s.st[i] << ' ';
//    return os;
//  }
