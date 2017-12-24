// тесты для стека

#include "stack.h"
#include <gtest.h>


template <class T2>
class Test_stack : public ::testing::Test {
 protected:
	 Stack<T2> s1;
	 public:
  Test_stack() : s1(100)
  {
	  for (int i = 0; i < s1.getSize(); i++)
		  s1.push((T2)i);
  }
  virtual ~Test_stack() {}
};

typedef ::testing::Types<int, char, double> MyTypes;// связываем класс и типы
TYPED_TEST_CASE(Test_stack, MyTypes);


TYPED_TEST(Test_stack, can_copy_stack)
{
	Stack<MyTypes> s2(12);
	ASSERT_NO_THROW(Stack<MyTypes> s3(s2));
}


TYPED_TEST(Test_stack, can_deleted)
{
	s1.clear();
	EXPECT_EQ(true, s1.IsEmpty());
}

TYPED_TEST(Test_stack, can_pop)
{
	int s = s1.pop();
	EXPECT_EQ(99, s);
}

TYPED_TEST(Test_stack, sheck_isemty)
{
	EXPECT_EQ(false, s1.IsEmpty());
}

TYPED_TEST(Test_stack, get_size)

{
	EXPECT_EQ(100, s1.getSize());
}

TEST(Stack, can_create_stack_with_positive_lenght)
{
	ASSERT_NO_THROW(Stack<int> st(1));
}

TEST(TStack, throws_when_create_stack_with_negative_length)
{
	ASSERT_ANY_THROW(Stack<int> st(-1));
}

TEST(Stack, can_create_stack_with_lenght_more_max)
{
	ASSERT_ANY_THROW(Stack<double> st(1000000));
}

TEST(Stack, can_create_empty_stack)
{
	ASSERT_NO_THROW(Stack<int> st);
}

TEST(Stack, cant_pop_empty_Stack)
{
	Stack<int> st;
	ASSERT_ANY_THROW(st.pop());
}


