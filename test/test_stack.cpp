// Тесты для стека
#include "stack.h"
#include <gtest.h>


TEST(TStack, can_create_TStack)
{
	ASSERT_NO_THROW(TStack<int> s);                    
}   
TEST(TStack, checking_for_TStack_emptiness)
{
	TStack<int>s;
	EXPECT_EQ(1, s.Empty());
}
TEST(TStack, can_insert_element_into_TStack)
{  
	TStack<int>s;
	s.Push(7);
	EXPECT_EQ(0, s.Empty());
}
TEST(TStack, cant_view_element_from_empty_TStack)
{
	TStack<int>s;
	ASSERT_ANY_THROW(s.Top());
}
TEST(TStack, view_element_into_TStack)
{
	TStack<int>s;
	s.Push(7);
	EXPECT_EQ(7, s.Top());
	EXPECT_EQ(0, s.Empty());  //элемент не был извлечен при просмотре
}
TEST(TStack, can_put_element_larger_size_TStack)
{
	TStack<int>s;
	for(int i=0;i< STACK_SIZE+2;i++)
	{s.Push(i);}
	ASSERT_NO_THROW(s.Top());
	EXPECT_EQ(STACK_SIZE+1, s.Top());
}
TEST(TStack, cant_take_element_from_empty_TStack)
{
	TStack<int>s;
	ASSERT_ANY_THROW(s.Pop());
}
TEST(TStack, take_element_from_empty_TStack)
{
	TStack<int>s;
	s.Push(7);
	EXPECT_EQ(7, s.Pop());
	EXPECT_EQ(1, s.Empty());  //элемент был извлечен при просмотре
}
TEST(TStack, get_the_number_of_elements_in_TStack)
{
	TStack<int>s;
	EXPECT_EQ(0, s.Count());
	for (int i = 0; i < 10; i++)
	{
		s.Push(i);
	}
	EXPECT_EQ(10, s.Count());
}
TEST(TStack, clean_TStack)
{
	TStack<int>s;
	for (int i = 0; i < 10; i++)
	{
		s.Push(i);
	}
	s.Clear();
	EXPECT_EQ(1, s.Empty());
}
/*
TEST(TStack, cant_take_element_from_empty_stack)
{
	TStack<int>s;
	ASSERT_ANY_THROW(s.Pop());
}
TEST(TStack, vzyatie_verhnego_elementa_is_TStack)
{
	TStack<int>ts(2);
	ts.Push(1);
	ts.Push(2);
	ASSERT_EQ(ts.Top(), 2);
}

TEST(TStack, ubrat_verhniy_element_is_TStack)
{
	TStack<int>ts(2);
	ts.Push(1);
	ts.Push(2);
	ts.Pop();
	ASSERT_EQ(ts.Top(), 1);
}

TEST(TStack, vzyatie_verhnego_elementa_is_pystogo_TStack)
{
	TStack<int>ts(0);
	ASSERT_ANY_THROW(ts.Top());
}

TEST(TStack, ybrat_element_is_pystogo_TStack)
{
	TStack<int>ts(0);
	ASSERT_ANY_THROW(ts.Pop());
}

TEST(TStack, can_create_copied_TStack)
{
	TStack<int> m(5);
	ASSERT_NO_THROW(TStack<int> m1(m));
}

TEST(TStack, copied_TStack_is_equal_to_source_one)
{
	TStack <int> m(4);
	m.Push(1);
	TStack <int> m1(m);
	int a = m.Pop();
	int b = m1.Pop();
	EXPECT_EQ(a, b);
}

TEST(TStack, copied_TStack_has_its_own_memory)
{
	TStack<int> m1(4);
	TStack<int> m2(4);

	m1.Push(1);
	m1.Push(2);

	m2.Push(1);
	m2.Push(2);
	EXPECT_FALSE(&m1 == &m2);
}*/