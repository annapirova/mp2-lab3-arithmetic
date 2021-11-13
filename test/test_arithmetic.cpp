// тесты для вычисления арифметических выражений

#include <gtest.h>
#include "arithmetic.h"

TEST(arithmetic, can_create_arithmetic)
{
	ASSERT_NO_THROW(Arithmetic A("5 + 5"));
}

TEST(arithmetic, split_correct)
{
	Arithmetic A("(sin(2*exp(log - 10)) + cos(2^2)) / -ln(a)");
	A.split();
	vector<lexema> inp = A.get_input_lex();
	vector<lexema> v;
	v.push_back(lexema("(", 0));
	v.push_back(lexema("sin", 5));
	v.push_back(lexema("(", 0));
	v.push_back(lexema("2", -3));
	v.push_back(lexema("*", 2));
	v.push_back(lexema("exp", 5));
	v.push_back(lexema("(", 0));
	v.push_back(lexema("log", -2));
	v.push_back(lexema("-", 1));
	v.push_back(lexema("10", -3));
	v.push_back(lexema(")", -1));
	v.push_back(lexema(")", -1));
	v.push_back(lexema("+", 1));
	v.push_back(lexema("cos", 5));
	v.push_back(lexema("(", 0));
	v.push_back(lexema("2", -3));
	v.push_back(lexema("^", 3));
	v.push_back(lexema("2", -3));
	v.push_back(lexema(")", -1));
	v.push_back(lexema(")", -1));
	v.push_back(lexema("/", 2));
	v.push_back(lexema("--", 4));
	v.push_back(lexema("ln", 5));
	v.push_back(lexema("(", 0));
	v.push_back(lexema("a", -2));
	v.push_back(lexema(")", -1));

	bool F = true;
	for (size_t i = 0; i < v.size(); i++)
	{
		if (!(inp[i] == v[i]))
			F = false;
	}

	EXPECT_TRUE(F);
}

TEST(arithmetic, check_bkt)
{
	Arithmetic A("4 + ( 4 - 1 ) )");
	A.split();
	EXPECT_FALSE(A.check_bkt());
}

TEST(arithmetic, check_symbols)
{
	Arithmetic A("(5 + 5) & 4");
	A.split();
	EXPECT_EQ(6, A.check_symbols().front());
}

TEST(arithmetic, check_points)
{
	Arithmetic A("5.0001.1 + 1");
	A.split();
	EXPECT_FALSE(A.check_points());
}

TEST(arithmetic, check_operation)
{
	Arithmetic A("5 + + 1");
	A.split();
	EXPECT_FALSE(A.check_operations());
}

TEST(arithmetic, converter_correct)
{
	Arithmetic A("(sin(2*exp(log - 10)) + cos(2^2)) / -ln(a)");
	A.split();
	A.converter();
	vector<lexema> inp = A.get_polish_lex();
	vector<lexema> v;
	v.push_back(lexema("2", -3));
	v.push_back(lexema("log", -2));
	v.push_back(lexema("10", -3));
	v.push_back(lexema("-", 1));
	v.push_back(lexema("exp", 5));
	v.push_back(lexema("*", 2));
	v.push_back(lexema("sin", 5));
	v.push_back(lexema("2", -3));
	v.push_back(lexema("2", -3));
	v.push_back(lexema("^", 3));
	v.push_back(lexema("cos", 5));
	v.push_back(lexema("+", 1));
	v.push_back(lexema("a", -2));
	v.push_back(lexema("ln", 5));
	v.push_back(lexema("--", 4));
	v.push_back(lexema("/", 2));

	bool F = true;
	for (size_t i = 0; i < v.size(); i++)
	{
		if (!(inp[i] == v[i]))
			F = false;
	}

	EXPECT_TRUE(F);
}

TEST(arithmetic, calculate_correct)
{
	Arithmetic A("(sin(2*exp(11 - 10)) + cos(2^2)) / -ln(2.71)");
	A.split();
	A.converter();
	A.set_values();
	A.calculate();
	EXPECT_FLOAT_EQ(1.406983, A.get_result());
}