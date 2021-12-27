// тесты для стека

#include "stack.h"
#include <gtest.h>

TEST(Stack, can_create_stack)
{
	ASSERT_NO_THROW(Stack <int> a);
}

TEST(Stack, can_not_create_stack_whith_negativ_length)
{
	ASSERT_ANY_THROW(Stack <int> a(-10));
}

TEST(Stack, can_add_element)
{
	Stack <int> a(10);
	int b = 1;
	ASSERT_NO_THROW(a.push(b));
}

TEST(Stack, stacks_empty)
{
	Stack<int> a(10);
	EXPECT_TRUE(a.isempty());
}

/*TEST(Stack, can_not_be_added_if_there_are_no_seats)
{
	Stack<int> a(10);
	int b = 2;
	for (int i = 0; i < 10; i++)
	{
		a.push(i);
	}
	ASSERT_ANY_THROW(a.push(b));
}*/

TEST(Stack, can_pop_element)
{
	Stack<int> a(10);
	int b = 3;
	a.push(b);
	EXPECT_EQ(b, a.pop());
}

TEST(Stack, can_pop_and_not_delete_element)
{

	Stack<int> a(10);
	int b = 1;
	int c;
	a.push(b);
	c = a.top();
	EXPECT_EQ(b, a.pop());
}

TEST(Stack, can_not_pop_from_empty_stack)
{
	Stack<int> a(10);
	int b;
	ASSERT_ANY_THROW(b = a.pop());
}

TEST(Stack, can_know_number_of_elements)
{
	Stack<int> a(3);
	int b;
	for (int i = 0; i < 3; i++)
	{
		b = 3 * i + 1;
		a.push(b);
	}
	EXPECT_EQ(3, a.getquantity());
}

TEST(Stack, can_clean_stack)
{
	Stack<int> a(3);
	int b;
	for (int i = 0; i < 3; i++)
	{
		b = 3 * i + 1;
		a.push(b);
	}
	a.clean();
	EXPECT_EQ(0, a.getquantity());
}

TEST(Stack, memory_allocation_when_the_stack_is_full)
{
	Stack<int> a(100);
	for (int i = 0; i < 102; i++)
		a.push(i);
	EXPECT_EQ(200, a.getsize());
}