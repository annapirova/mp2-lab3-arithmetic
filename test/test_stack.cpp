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

TEST(Stack, can_create_copied_stack)
{
    Stack<int> st(3);
    ASSERT_NO_THROW(Stack<int> st1(st));
}

TEST(Stack, stack_is_empty)
{
    Stack<int> st(3);
    EXPECT_EQ(true, st.IsEmpty());
}

TEST(Stack, stack_is_not_empty)
{
    Stack<int> st(3);
    st.Push(1);
    EXPECT_EQ(false, st.IsEmpty());
}

TEST(Stack, can_push_element_in_stack)
{
    Stack<int> T(3);
    ASSERT_NO_THROW(Stack<int>, T.Push());
}

TEST(Stack, can_see_top_element)
{
    Stack<int> st(3);
    st.Push(1);
    EXPECT_EQ(1, st.Peek());
    //ASSERT_NO_THROW(Stack<int>, T.Peek());
}

TEST(Stack, can_clear)
{
    Stack<int> st(3);
    st.Push(1);
    st.Clear();
    EXPECT_TRUE(st.IsEmpty());
}

TEST(Stack, can_get_the_size_of_stack)
{
    Stack<int> T(3);
    EXPECT_EQ(3, T.GetSize());
    //ASSERT_NO_THROW(Stack<int>, T.GetSize());
}
TEST(Stack, can_delete_element_from_stack)
{
    Stack<int> st(3);
    st.Push(1);
    st.Push(2);
    st.Push(3);
    ASSERT_NO_THROW(3, st.Pop());
}

