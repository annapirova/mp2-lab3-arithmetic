#include "stack.h"
#include <gtest.h>

#include "stack.h"
#include <gtest.h>

TEST(Stack, can_create_stack_with_positive_size)
{
  ASSERT_NO_THROW(Stack a(3));
}


TEST(Stack, throws_when_create_stack_with_negative_size)
{
  ASSERT_ANY_THROW(Stack a(-3));
}


TEST(Stack, new_stack_is_not_filled)
{
  Stack a(100);
  EXPECT_EQ(-1, a.Top);
}

TEST(Stack, can_get_index_of_first_element)
{
  Stack a(100);
  a.Top = 6;
  EXPECT_EQ(6, a.Top);
}

TEST(Stack, can_push_element)
{
	Stack a(9);
	for (int i = 0; i < a.N; i++)
		a.Push(i);
	EXPECT_EQ(a[4], 4);
}


TEST(Stack, can_copy)
{
	const int k = 4;
	Stack a(k);
	for (int i = 0; i < k; i++)
		a.Push(i);
	Stack b(a);
	EXPECT_EQ(a[1], b[1]);
}

TEST(Stack, can_get_element)
{
	int temp;
	Stack a(9);
	for (int i = 0; i < 9; i++)
		a.Push(i);
	EXPECT_EQ(a.Get() , 8);
}


TEST(Stack, throws_when_set_element_with_too_large_index)
{
  Stack a(10);
  ASSERT_ANY_THROW( a[16] );
}

TEST(Stack, throws_when_set_element_with_too_negative_index)
{
  Stack a(10);
  ASSERT_ANY_THROW( a[-1] );
}

TEST(Stack, new_stack_is_empty)
{
	Stack a(10);
	EXPECT_EQ(true, a.IsEmpty());
}


TEST(Stack, stack_is_full)
{
	Stack a(10);
	for (int i = 0; i < a.N; i++)
		a.Push(i);
	EXPECT_EQ(true, a.IsFull());
}





