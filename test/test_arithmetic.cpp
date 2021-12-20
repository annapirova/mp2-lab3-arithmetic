// тесты для вычисления арифметических выражений
#include <gtest.h>
#include <arithmetic.h>


TEST(Stack, create_copy)
{
	Stack<double> stack(6);
	ASSERT_NO_THROW(Stack<double> stack2(stack));
}

TEST(Lexema, can_create)
{
	ASSERT_NO_THROW(Lexema L);
}

TEST(Stack, throws)
{
	ASSERT_ANY_THROW(Stack<double> stack(-1));
}

TEST(Stack, create_copy_2)
{
	Stack<double> stack(2);
	stack.push(8.3);
	Stack<double> stack2(stack);
	ASSERT_EQ(8.3, stack.pop()); 
}



