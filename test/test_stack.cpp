#include "pch.h"
#include "../arithmetic1/stack.h"

TEST(Stack, can_create_stack_with_positive_length)
{
    ASSERT_NO_THROW(Stack<int> T(3));
}

TEST(Stack, throws_when_create_stack_with_negative_length)
{
    ASSERT_ANY_THROW(Stack<int> T(-3));
}

TEST(Stack, can_create_stack_with_too_large_length)
{
    ASSERT_NO_THROW(Stack<int>, T(MAX_STACK_SIZE));
}

TEST(Stack, stack_is_empty)
{
    Stack<int> T(3);
    EXPECT_TRUE(T.IsEmpty());
}

TEST(Stack, can_push_element_in_stack)
{
    Stack<int> T(3);
    ASSERT_NO_THROW(Stack<int>, T.Push());
}

TEST(Stack, can_see_top_element)
{
    Stack<int> T(3);
    ASSERT_NO_THROW(Stack<int>, T.Peek());
}

TEST(Stack, can_clear)
{
    Stack<int> T(3);
    ASSERT_NO_THROW(Stack<int>, T.Clear());
}

TEST(Stack, can_get_the_size_of_stack)
{
    Stack<int> T(3);
    ASSERT_NO_THROW(Stack<int>, T.GetSize());
}
TEST(Stack, can_delete_element_from_stack)
{
    Stack<int> T(3);
    ASSERT_NO_THROW(Stack<int>, T.Pop());
}

