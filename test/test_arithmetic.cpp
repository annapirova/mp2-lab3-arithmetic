// тесты для вычисления арифметических выражений

#include <gtest.h>
#include "arithmetic.h"


string s1[22] = { "+++", "1+--2", "*/1", "1*", "3/", "(1+5", "1-5)", "(1+2)3", "3*(**2)","((2+3" };

string s2[5] = { "1+2+3-(3-2-1)", "-5", "(-5)", "-(-(-1*2.3/(4+5.5)))", "1.5*2.5" };

double s3[5] = { 1 + 2 + 3 - (3 - 2 - 1), -5, (-5), -(-(-1 * 2.3 / (4 + 5.5))), 1.5 *2.5 };


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

TEST(Lexem, can_calc_2)
{
	Arithmetic A("(1-2*3)*(1-3)");
	A.DivideToLexems();
	A.PolishNotation();
	double res = A.Calculate();
	EXPECT_EQ(10, res);
}


TEST(Arithmetic, convert_to_polish_notation)
{
	Arithmetic A("2*12");
	A.DivideToLexems();
	A.PolishNotation();
	EXPECT_EQ(2, A.GetValplLexems(0));
	EXPECT_EQ(12, A.GetValplLexems(1));
	EXPECT_EQ(2, A.GetValplLexems(2));
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
	Arithmetic A("(1+2-2-1");
	bool r1;
	A.DivideToLexems();
	r1 = A.CheckBrackets();
	EXPECT_EQ(false, r1);
}

TEST(Arithmetic, check_brack_3)
{
	Arithmetic A("()(1+21))");
	bool r2;
	A.DivideToLexems();
	r2 = A.CheckBrackets();
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


TEST(Arithmetic, check_operator_3)
{
	Arithmetic A("(2+3)+(-1)");
	bool r;
	A.DivideToLexems();
	r = A.CheckOperators();
	EXPECT_EQ(true, r);
}


TEST(Arithmetic, can_divide_to_lexems)
{
	Arithmetic A("2*12");
	A.DivideToLexems();
	EXPECT_EQ(2, A.GetValLexems(0));
	EXPECT_EQ(2, A.GetValLexems(1));
	EXPECT_EQ(12, A.GetValLexems(2));
}

TEST(Arithmetic, uncorrect_string)
{
	for (int i = 0; i < 11; i++)
	{
		Arithmetic A(s1[i]);
		A.DivideToLexems();
		EXPECT_EQ(false, A.CheckBrackets() && A.CheckOperators());
	}
}


TEST(Arithmetic, check_points)
{
	Arithmetic A("2.5");
	A.DivideToLexems();
	EXPECT_EQ(1, A.CheckPoints("2.5"));
}


TEST(Arithmetic, correct_string)
{
	for (int i = 0; i < 5; i++)
	{
		Arithmetic A(s2[i]);
		A.DivideToLexems();
		EXPECT_EQ(true, A.CheckBrackets() && A.CheckOperators());
	}
}

 
TEST(Arithmetic, can_calculate_2)
{
	for (int i = 0; i < 5; i++)
	{
		Arithmetic A(s2[i]);
		A.DivideToLexems();
		A.PolishNotation();
		EXPECT_EQ(s3[i], A.Calculate());
	}
}

