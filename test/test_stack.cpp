#include <gtest.h>

#include "stack.h"

TEST(TStack, can_create_stack_with_positive_length)
{
  ASSERT_NO_THROW(TStack<int> c(5));
}

TEST(TStack, cant_create_too_large_stack)
{
  ASSERT_ANY_THROW(TStack<int> c(MAX_STACK_SIZE + 1));
}

TEST(TStack, throws_when_create_stack_with_negative_length)
{
  ASSERT_ANY_THROW(TStack<int> c(-5));
}

TEST(TStack, can_create_copied_stack)
{
  TStack<int> c(10);

  ASSERT_NO_THROW(TStack<int> c1(c));
}

TEST(TStack, copied_stack_are_equal) {
 	TStack<int> c1(10);
 	
	int k = 1;
	c1.Push(k);
	TStack<int> c2(c1);

	EXPECT_TRUE(c1.Get() == c2.Get()); 
}

TEST(TStack, can_add_element) {
 	TStack<int> c1(10);
 	int c2 = 1;	
 	ASSERT_NO_THROW(c1.Push(c2););
}

TEST(TStack, assign_stacks_are_equal) {
 	TStack<int> c1(10);
 	TStack<int> c2(10);
 
	int k = 1; 
	c1.Push(k);	
 	c2 = c1;

	EXPECT_TRUE(c1.Get() == c2.Get());
}

TEST(TStack, stack_equal_itself) {
 	TStack<int> c1(10);

	for (int i = 0; i < 10; i++) {
 		c1.Push(i);
 	}

 	EXPECT_TRUE(c1.Get() == c1.Get());
}
 
 TEST(TStack, different_stacks_not_equal) {
 	TStack<int> c1(10);
 	TStack<int> c2(10);

	int k = 1;
	c1.Push(k);
	k = k+3;
	c2.Push(k);

 	EXPECT_FALSE(c1.Get() == c2.Get());
}

  TEST(TStack, stacks_whith_different_top_not_equal) {
 	TStack<int> c1(10);
 	TStack<int> c2(10);
 	
	int k = 1;
	c1.Push(k);
	k = k+3;
	c2.Push(k);

 	EXPECT_FALSE(c1.Get() == c2.Get());
}

TEST(TStack, can_pop_element)
{
	TStack <int> c(2);

	int k = 5;
	c.Push(k);

	EXPECT_EQ(k, c.Pop());
	EXPECT_TRUE(c.IsEmpty());
}

TEST(TStack, can_get_element)
{
	TStack <int> c(2);

	int k = 5;
	c.Push(k);

	EXPECT_EQ(5,c.Get());
	EXPECT_EQ(0,c.top);
}

TEST(TStack, cant_get_element_when_stack_is_empty)
{
	TStack <int> c(5);

	ASSERT_ANY_THROW(c.Get());
}

TEST(TStack, cant_pop_element_when_stack_is_empty)
{
	TStack <int> c(5);

	ASSERT_ANY_THROW(c.Pop());
}

TEST(TStack, new_stack_is_empty)
{
	TStack<int> c(5);

	EXPECT_TRUE(c.IsEmpty());
}

TEST(TStack, can_not_add_element_in_full_stack) {
 	const int size = 2;
	TStack<int> c1(size);
 	int k = 47;
 	c1.Push(k);
 	c1.Push(5);
	EXPECT_TRUE(c1.IsFull());
	ASSERT_ANY_THROW(c1.Push(k)); 
}