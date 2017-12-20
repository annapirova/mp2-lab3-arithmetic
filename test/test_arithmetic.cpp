// тесты для вычисления арифметических выражений

#include <gtest.h>
#include "arithmetic.h"

TEST(Lexem, can_create_lexem_val)
{
	Lexem L("2");
	EXPECT_EQ(2, L.val);
}

TEST(Lexem, can_define_type_of_lexem)
{
	string s = "5";
	Lexem L(s);
	EXPECT_EQ(L.type, VAL);
}


TEST(Lexem, can_calc)
{
	Arithmetic A("1+2+3");
	A.DivideToLexems();
	A.PolishNotation();
	double res = A.Calculate();
	EXPECT_EQ(6, res);
}

TEST(Arithmetic, check_brack)
{
	Arithmetic A("(1+2)-(2-1)");
	bool r1;
	A.DivideToLexems();
	r1 = A.CheckBrackets();
	EXPECT_EQ(true, r1);
}

TEST(Arithmetic, check_brack_2)
{
	Arithmetic B("(1+2-2-1");
	bool r2;
	B.DivideToLexems();
	r2 = B.CheckBrackets();
	EXPECT_EQ(false, r2);
}

TEST(Arithmetic, check_operator)
{
	Arithmetic A("2+3-+)+(1)");
	bool r;
	A.DivideToLexems();
	r = A.CheckOperators();
	EXPECT_EQ(false, r);
}


TEST(Arithmetic, check_operator_2)
{
	Arithmetic A("(2*/31");
	bool r;
	A.DivideToLexems();
	r = A.CheckOperators();
	EXPECT_EQ(false, r);
}


TEST(Arithmetic, polish_notation)
{
	Arithmetic A("2*12");
	A.DivideToLexems();
	A.PolishNotation();
	EXPECT_EQ(2, A.GetValplLexems(0));
	EXPECT_EQ(12, A.GetValplLexems(1));
	EXPECT_EQ(2, A.GetValplLexems(2));
}

