//реализация стека
//

#ifndef __STACK_H
#define __STACK_H

const int MAX_STACK_SIZE = 1000;

template <class ValType>
class TStack
{
public:
  ValType *pVector;
  int Size;       // размер стека
  int top;		//номер текущего элемента стека

  TStack(int s = 10);
  TStack(const TStack<ValType> &c);        // конструктор копирования
  virtual ~TStack();

  void Push(const ValType &Val);		//добавление в стек нового элемента
  ValType Pop();				//удаление элемента из стека

  int GetSize(void)      { return Size; } // размер стека
  ValType Get();						//Взять стек
 
  bool IsEmpty(void);
  bool IsFull(void);
 
  TStack& operator=(const TStack<ValType> &c);     // присваивание

};

template <class ValType>
TStack<ValType>::TStack(int s)
{
	if (s > MAX_STACK_SIZE)
 	{
 		throw "Конструктор MAX_STACK_SIZE < s stack";
 	}
 	if (s < 0)
 	{
 		throw "Конструктор s < 0 stack";
 	}
 	pVector = new ValType[s];
 	Size = s;
/* 	for (int i = 0; i < Size; i++)
 	{
 		pVector[i] = ValType();
 	}
*/	top = 0;
} /*-------------------------------------------------------------------------*/
template <class ValType>
TStack<ValType>::TStack(const TStack<ValType> &c)
{
	pVector = new ValType[c.Size];
	Size = c.Size;
	top = c.top;
	for (int i = 0; i < Size; i++)
		pVector[i] = c.pVector[i];
} /*-------------------------------------------------------------------------*/

template <class ValType>
TStack<ValType>::~TStack()
{
	delete []pVector;
} /*-------------------------------------------------------------------------*/

template <class ValType>
void TStack<ValType>::Push(const ValType &Val)
{
	if ( IsFull() )
		throw "Full";
	top++;
	pVector[top] = Val;
	
} /*-------------------------------------------------------------------------*/

template <class ValType>
ValType TStack<ValType>::Pop()
{
	if ( IsEmpty() )
		throw "Empty";
	ValType res;
	res = pVector[top];
	top--;
	return res;
} /*-------------------------------------------------------------------------*/

template <class ValType>
ValType TStack<ValType>::Get()
{
	if ( IsEmpty() )
		throw "Empty";
	return pVector[top];
}/*-------------------------------------------------------------------------*/


template <class ValType>
bool TStack<ValType> :: IsEmpty( void )
{
	if ( top == 0 )
		return true;
	else
		return false;
} /*-------------------------------------------------------------------------*/

template <class ValType>
bool TStack<ValType> :: IsFull(void)
{
	return (top == Size);
} /*-------------------------------------------------------------------------*/

template <class ValType>
TStack<ValType>& TStack<ValType>::operator=(const TStack<ValType> &c)
{
	if (this != &c){
		if (Size != c.Size){
			delete []pVector;
			pVector = new ValType[c.Size];
		}
		Size = c.Size; top = c.top;
		for (int i = 0; i < Size; i++ )
			pVector[i] = c.pVector[i];
	}
	return *this;

} /*-------------------------------------------------------------------------*/

#endif