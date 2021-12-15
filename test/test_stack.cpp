#include "pch.h"
#include "../arithmetic/stack.h"

TEST(TStack, can_create_stack_with_positive_lenght)
{
	ASSERT_NO_THROW(TStack<int> st(5));
}

TEST(TStack, can_create_too_large_stack)
{
	ASSERT_ANY_THROW(TStack<int> st(MAX_STACK_SIZE + 1));
}

TEST(TStack, throws_when_create_stack_with_negative_length)
{
	ASSERT_ANY_THROW(TStack<int> st(-5));
}

TEST(TStack, can_create_copied_stack)
{
	TStack<int> st(10);

	ASSERT_NO_THROW(TStack<int> st1(st));
}

TEST(TStack, can_not_delete_if_stack_is_empty)
{
	TStack<int> st(1);
	st.Push(1);
	st.Pop();
	st.IsEmpty();

	ASSERT_ANY_THROW(st.Pop());
}

TEST(TStack, can_not_see_the_top_element_if_stack_is_empty)
{
	TStack<int> st(1);
	st.Push(1);
	st.Pop();

	ASSERT_ANY_THROW(st.Top());
}

TEST(TStack, copied_stack_is_equal_to_source_one)
{
	TStack<int> st1(4);
	for (int i = 0; i < 4; i++)
		st1.Push(i);
	TStack<int> st2(st1);
	EXPECT_EQ(st1, st2);
}

TEST(TStack, can_get_size)
{
	TStack<int> st(4);
	for (int i = 0; i < 4; i++)
		st.Push(i);

	EXPECT_EQ(4, st.GetSize());
}

TEST(TStack, can_push_elem1)
{
	TStack<int> st(3);
	st.Push(1);
	st.Push(2);
	st.Push(3);
	st.Push(4);

	EXPECT_EQ(4, st.Top());
}

TEST(TStack, can_push_elem2)
{
	TStack<int> st(4);
	st.Push(1);
	st.Push(2);
	st.Push(3);
	st.Push(4);

	EXPECT_EQ(4, st.Top());
}

TEST(TStack, can_pop_elem)
{
	TStack<int> st(2);
	st.Push(1);
	st.Push(2);
	st.Pop();

	EXPECT_EQ(1, st.Top());
}

TEST(TStack, can_check_for_emptiness)
{
	TStack<int> st(2);
	st.Push(1);
	st.Push(2);

	EXPECT_NE(true, st.IsEmpty());
}

TEST(TStack, can_compare_stacks_of_different_sizes1)
{
	TStack<int> st1(2), st2(2);
	st1.Push(1);
	st1.Push(2);
	st2.Push(1);
	st2.Push(2);

	EXPECT_EQ(true, st1 == st2);
}

TEST(TStack, can_return_the_number_of_elements)
{
	TStack<int> st(4);
	st.Push(1);
	st.Push(3);
	st.Push(1);
	st.Push(2);
	st.Clean();

	EXPECT_EQ(true, st.IsEmpty());
}

TEST(TStack, can_equate_equal_stacks)
{
	TStack<int> st1(2);
	st1.Push(1);
	st1.Push(2);

	st1 = st1;
	EXPECT_EQ(st1, st1);
}
