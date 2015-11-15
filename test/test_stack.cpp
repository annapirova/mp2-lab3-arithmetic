#include "stack.h"
#include <gtest.h>
TEST(Stack, can_create_stack)
{
	ASSERT_NO_THROW(Stack<int> a);
}
TEST(Stack, can_create_stack_whith_size) {
	ASSERT_NO_THROW(Stack<int> a(20));
}
TEST(Stack, can_not_create_stack_whith_negativ_length)
{
	ASSERT_ANY_THROW(Stack<int> a(-10));
}
TEST(Stack, can_add_element) 
{
	Stack<int> a(10);

	int b=1;

	ASSERT_NO_THROW(a.push(b));
}
TEST(Stack, can_not_add_element_in_full_stack) {
	Stack<int> a(10);
	int b = 1;
	for (int i = 0; i < 10; i++)
	{
		a.push(i);
	}
	ASSERT_ANY_THROW(a.push(b));
}
TEST(Stack, can_pick_element) 
{
	Stack<int> a(10);
	int b = 1;
	a.push(b);
	EXPECT_EQ(b, a.pop());
}
TEST(Stack, can_pick_and_not_delete_element)
{

	Stack<int> a(10);
	int b = 1;
	int c;
	a.push(b);
	c = a.Peek();
	EXPECT_EQ(b, a.pop());
}
TEST(Stack, can_not_pop_from_empty_stack) 
{
	Stack<int> a(10);
	int b;
	ASSERT_ANY_THROW(b = a.pop());
}
TEST(Stack, can_copy_Stack)
{
	Stack<int> a(10);
	ASSERT_NO_THROW(Stack<int> b(a));
}
TEST(Stack, copied_stack_are_equal) 
{
	Stack<int> a(10);
	Stack<int> b(a);
	EXPECT_EQ(b,a);
}
TEST(Stack, copied_stack_are_not_equal)
{
	Stack<int> a(10);
	Stack<int> b(a);
	a.push(1);
	b.push(2);
	EXPECT_NE(b.pop(), a.pop());
}
TEST(Stack, can_SetSize) 
{
	Stack<int> a(10);
	for (int i = 0; i < 10; i++) 
	{
		a.push(i);
	}
	a.SetSize(11);
	ASSERT_NO_THROW(a.push(1));
}
TEST(Stack, can_not_SetSize_negativ_length) 
{
	Stack<int> a(10);
	a.SetSize(15);
	ASSERT_ANY_THROW(a.SetSize(-10));
}
TEST(Stack, can_not_SetSize_then_Size_larger_n)
{
	Stack<int> a(10);
	for (int i = 0; i < 10; i++)
	{
		a.push(i);
	}
	ASSERT_ANY_THROW(a.SetSize(5));
}

TEST(Stack, assign_stacks_are_equal)
{
	Stack<int> a(10);
	Stack<int> b(10);

	for (int i = 0; i < 10; i++) {
		a.push(i);
	}
	
	b = a;
	EXPECT_EQ(a,b);
}
TEST(Stack, stack_equal_itself) 
{
	Stack<int> a(10);
	for (int i = 0; i < 10; i++) {
		a.push(i);
	}
	EXPECT_EQ(a, a);
}
TEST(Stack, stacks_whith_different_size_not_equal)
{
	Stack<int> a(10);
	Stack<int> b(5);
	EXPECT_NE(a, b);
}
TEST(Stack, different_stacks_not_equal) 
{
	Stack<int> a(10);
	Stack<int> b(10);

	a.push(1);

	EXPECT_NE(a, b);
}
TEST(Stack, stacks_whith_different_top_not_equal) 
{
	Stack<int> a(10);
	Stack<int> b(10);
	b.push(0);
	EXPECT_NE(a, b);
}
