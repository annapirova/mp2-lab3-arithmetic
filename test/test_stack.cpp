#include "stack.h"
#include <gtest.h>


TEST(TStack, can_create_stack) 
{
	ASSERT_NO_THROW(TStack<int> s);
}

TEST(TStack, check_stack_is_empty)
{
	TStack<int> s(10);
	EXPECT_TRUE(s.isEmpty());
}

TEST(TStack, check_stack_is_full)
{
	TStack<int> s(10);
	for (int i = 0; i < s.getSize(); i++)
		s.push(i);
	EXPECT_TRUE(s.IsFull());
}

TEST(TStack, can_create_stack_whith_size) 
{
	ASSERT_NO_THROW(TStack<int> s(10));
}

TEST(TStack, can_not_create_stack_whith_negativ_length) 
{
	ASSERT_ANY_THROW(TStack<int> s(-10));
}

TEST(TStack, can_get_size_stack)
{
	TStack<int> s(10);
	EXPECT_EQ(10, s.getSize());
}

TEST(TStack, can_copy_stack)
{
	TStack<int> s1(10);
	for (int i = 0; i < 10; i++)
		s1.push(i);
	ASSERT_NO_THROW (TStack<int> s2(s1));
}

TEST(TStack, copied_stack_has_its_own_memory)
{
	TStack <int> s1(2);
	TStack <int> s2(s1);
	EXPECT_NE(&s2,&s1);
}

TEST(TStack, can_add_element) 
{
	TStack<int> s(10);
	int a=1;	
	ASSERT_NO_THROW(s.push(a););
}

TEST(TStack, can_pick_element)
{
	TStack<int> s(10);
	int a=1;
	s.push(a);
	int b;
	b=s.peek();
	EXPECT_EQ(a, s.put());
}








