#include "stack.h"
#include <gtest.h>
TEST(Stack, create_stack)
{
	ASSERT_NO_THROW(Stack<int> stack(6));
}

TEST(Stack, create_stack_2)
{
	Stack<int> stack(2);
	Stack<int> stack2(stack);
	ASSERT_NO_THROW(Stack<int> stack(stack));
}

TEST(Stack, value_stack)
{
	Stack<int> stack(1);
	stack.push(1);
	stack.push(2);
	ASSERT_EQ(stack.Getcapasity(), 2);
}

TEST(Stack, capasity)
{
	Stack<int> stack(2);
	int s = stack.Getcapasity();
	ASSERT_EQ(s, stack.Getcapasity());
}


TEST(Stack, capasity_2)
{
	Stack<int> stack(2);
	stack.pop();
	int s = stack.Getcapasity();
	ASSERT_EQ(2, s);
}

TEST(Stack, create_value)
{
	Stack<int> stack(5);
	stack.push(4);
	int s = stack.Getcapasity();
	ASSERT_EQ(4, stack.pop());
}


TEST(Stack, clear_stack)
{
	Stack<int> stack(5);
	stack.clear();
	ASSERT_EQ(stack.isNotFull(), true);
}


TEST(Stack, full_stack)
{
	Stack<int> stack(2);
	stack.push(1);
	stack.push(2);
	ASSERT_EQ(stack.isFull(), true);
}

TEST(Stack, is_not_full)
{
	Stack<int> stack(2);
	stack.push(1);
	stack.push(2);
	ASSERT_EQ(stack.isNotFull(), false);
}

TEST(Stack, get_value_stack)
{
	Stack<int> stack(2);
	stack.push(1);
	stack.push(2);
	ASSERT_EQ(stack.getsize(), 2);
}

TEST(Stack, const_stack)
{
	ASSERT_NO_THROW(Stack<int> stack());
}



