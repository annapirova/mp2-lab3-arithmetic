#include "pch.h"
#include "../arithmetic/arithmetic.h"

//-----------------------struct: Lexem---------------------------
TEST(Lexem, can_create_lexem)
{
	string s = "121";
	Lexem c1(s, VALUE);
	EXPECT_EQ("121", c1.c);
	EXPECT_EQ(VALUE, c1.t);
}

TEST(Lexem, can_copy_lexem) 
{
	Lexem c1;
	Lexem c2(c1);
	EXPECT_EQ(c1, c2);
}

TEST(Lexem, can_prirav_lex)
{
	string s1 = "121";
	string s2 = "+";
	Lexem c1(s1, VALUE);
	Lexem c2(s2, OPERATION);
	c2 = c1;
	EXPECT_EQ("121", c2.c);
	EXPECT_EQ(VALUE, c2.t);
}

TEST(Lexem, sravnenie1) 
{
	string s1 = "121";
	string s2 = "+";
	Lexem c1(s1, VALUE);
	Lexem c2(s2, OPERATION);
	EXPECT_EQ(c2 != c1, true);
}

TEST(Lexem, sravnenie2)
{
	string s1 = "121";
	string s2 = "121";
	Lexem c1(s1, VALUE);
	Lexem c2(s2, VALUE);
	EXPECT_EQ(c2 == c1, true);
}


//-------------------------class Arithmetic----------------------
TEST(Arithmetic, calcul1_1)
{
	Arithmetic A("5+4");
	EXPECT_EQ(9, A.Calcul());
}

TEST(Arithmetic, calcul_2)
{
	Arithmetic A("5.7+4");
	EXPECT_EQ(9.7, A.Calcul());
}

TEST(Arithmetic, calcul_3)
{
	Arithmetic A("50*2-(100+70)*2");
	EXPECT_EQ(-240, A.Calcul());
}

TEST(Arithmetic, calcul_4)
{
	Arithmetic A("5+2*3");
	EXPECT_EQ(11, A.Calcul());
}

TEST(Arithmetic, calcul_5)
{
	Arithmetic A("1^1");
	EXPECT_EQ(1, A.Calcul());
}

TEST(Arithmetic, calcul_6)
{
	Arithmetic A("4^2");
	EXPECT_EQ(16, A.Calcul());
}

TEST(Arithmetic, calcul_7)
{
	Arithmetic A("12/4");
	EXPECT_EQ(3, A.Calcul());
}

TEST(Arithmetic, calcul_8)
{
	Arithmetic A("(50*2-(100+70)*2)/4");
	EXPECT_EQ(-60, A.Calcul());
}

TEST(Arithmetic, calcul_9)
{
	Arithmetic A("-4+2");
	EXPECT_EQ(-2, A.Calcul());
}

TEST(Arithmetic, calcul_10)
{
	Arithmetic A("-4^2");
	EXPECT_EQ(-16, A.Calcul());
}

TEST(Arithmetic, calcul_11)
{
	Arithmetic A("12/0");
	EXPECT_EQ(false, A.Calcul());
}

TEST(Arithmetic, check_symbols_1)
{
	Arithmetic A("5&61");
	EXPECT_EQ(false, A.checkSymbols());
}

TEST(Arithmetic, check_symbols_2)
{
	Arithmetic A("5%61");
	EXPECT_EQ(false, A.checkSymbols());
}

TEST(Arithmetic, check_symbols_3)
{
	Arithmetic A("5??61");
	EXPECT_EQ(false, A.checkSymbols());
}

TEST(Arithmetic, check_symbols_4)
{
	Arithmetic A("5!=61");
	EXPECT_EQ(false, A.checkSymbols());
}

TEST(Arithmetic, check_formula_1)
{
	Arithmetic A("5+)6*89");
	EXPECT_EQ(false, A.checkFormula());
}
TEST(Arithmetic, check_formula_2)
{
	Arithmetic A("+5*9");
	EXPECT_EQ(false, A.checkFormula());
}

TEST(Arithmetic, check_formula_3)
{
	Arithmetic A("*5-9");
	EXPECT_EQ(false, A.checkFormula());
}

TEST(Arithmetic, check_formula_4)
{
	Arithmetic A("/5*9");
	EXPECT_EQ(false, A.checkFormula());
}
TEST(Arithmetic, check_formula_5)
{
	Arithmetic A("5+7/");
	EXPECT_EQ(false, A.checkFormula());
}
TEST(Arithmetic, check_formula_6)
{
	Arithmetic A("5()+7");
	EXPECT_EQ(false, A.checkFormula());
}
TEST(Arithmetic, check_formula_7)
{
	Arithmetic A(")(5+7");
	EXPECT_EQ(false, A.checkFormula());
}

TEST(Arithmetic, check_formula_8)
{
	Arithmetic A("5+-7");
	EXPECT_EQ(false, A.checkFormula());
}

TEST(Arithmetic, divide)
{
	Arithmetic A("5+4*7");
	int res;
	Lexem c[100];
	res = A.PolZap(c);
	EXPECT_EQ(5, res);
}

TEST(Arithmetic, check_brackets_1)
{
	Arithmetic A("(5+7)-4");
	EXPECT_EQ(true, A.checkBrackets());
}

TEST(Arithmetic, check_brackets_2)
{
	Arithmetic A(")5+4)");
	EXPECT_EQ(false, A.checkBrackets());
}

TEST(Arithmetic, check_brackets_3)
{
	Arithmetic A("5+4)");
	EXPECT_EQ(false, A.checkBrackets());
}

TEST(Arithmetic, check_brackets_4)
{
	Arithmetic A("(5+4");
	EXPECT_EQ(false, A.checkBrackets());
}

TEST(Arithmetic, check_brackets_5)
{
	Arithmetic A("(5+4)7)");
	EXPECT_EQ(false, A.checkBrackets());

}
TEST(Arithmetic, check_brackets_6)
{
	Arithmetic A("(*(3+2)");
	EXPECT_EQ(false, A.checkBrackets());
}

TEST(Arithmetic, can_pr_arith)
{
	string s1 = "5+6*(8-5)";
	string s2 = "5+6*(7-5)";
	Arithmetic A1(s1), A2(s2);
	A2 = A1;
	EXPECT_EQ(true, A2 == A1);
}

TEST(Arithmetic, can_sr1_arith)
{
	string s1 = "5+6*(8-5)";
	string s2 = "5+6*(7-5)";
	Arithmetic A1(s1), A2(s2);
	EXPECT_EQ(false, A2 == A1);
}

TEST(Arithmetic, can_sr2_arith)
{
	string s1 = "5+6*(8-5)";
	string s2 = "5+6*(8-5)";
	Arithmetic A1(s1), A2(s2);
	EXPECT_EQ(true, A1 == A2);
}