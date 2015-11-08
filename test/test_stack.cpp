#include "stack.h"
#include <gtest.h>

TEST(TStack, can_create_stack_with_positive_length)
{
  ASSERT_NO_THROW(TStack<int> v(5));
}

TEST(TStack, cant_create_too_large_stack)
{
  ASSERT_ANY_THROW(TStack<int> v(MAX_STACK_SIZE + 1));
}

TEST(TStack, throws_when_create_stack_with_negative_length)
{
  ASSERT_ANY_THROW(TStack<int> v(-5));
}

TEST(TStack, throws_when_create_stack_with_negative_startindex)
{
  ASSERT_ANY_THROW(TStack<int> v(5, -2));
}

TEST(TStack, can_create_copied_stack)
{
  TStack<int> v(10);

  ASSERT_NO_THROW(TStack<int> v1(v));
}

TEST(TStack, can_set_and_get_elem)
{
  TStack<int> v(10);

  v.SetElem(1);

  EXPECT_EQ(1, v.GetElem());
}
