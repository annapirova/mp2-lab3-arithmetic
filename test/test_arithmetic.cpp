#include <gtest.h>
#include "arithmetic.h"


TEST(arithmetic, check_an_correctly_bracket1)
{
	string a;
	arithmetic b,d;
	a="a+b)";
	b.SetFormula(a);
	EXPECT_EQ(0,b.CheckFormula());
}
TEST(arithmetic,check_an_correctly_bracket2)
{
	string a;
	arithmetic b,d;
	a=")a+b()((";
	b.SetFormula(a);
	EXPECT_EQ(0,b.CheckFormula());
}
TEST(arithmetic,check_correctly_bracket)
{
	string a;
	arithmetic b,d;
	a="a+b*(c+b)";
	b.SetFormula(a);
	EXPECT_EQ(1,b.CheckFormula());
}
//TEST(arithmetic,check_unarny_minus)
//{
//	string a;
//	arithmetic b;
//	a="-b+5";
//	b.SetFormula(a);
//	EXPECT_EQ(1,b.Unarminus());
//}
//TEST(arithmetic,check_not_unarny_minus)
//{
//	string a;
//	arithmetic b;
//	a="b-5";
//	b.SetFormula(a);
//	EXPECT_EQ(0,b.Unarminus());
//}
TEST(arithmetic,check_correctly_operators1)
{
	string a;
	arithmetic b;
	a="a+-b";
	b.SetFormula(a);
	EXPECT_EQ(0,b.CheckOperators());
}
TEST(arithmetic,check_correctly_operators2_1)
{
	string a;
	arithmetic b;
	a="+a+b";
	b.SetFormula(a);
	EXPECT_EQ(0,b.CheckOperators2());
}
TEST(arithmetic,check_correctly_operators2_2)
{
	string a;
	arithmetic b;
	a="a+(b-)+4";
	b.SetFormula(a);
	EXPECT_EQ(0,b.CheckOperators2());
}
TEST(arithmetic,check_correctly_formula)
{
	string a;
	arithmetic b;
	a="(a+b)5";
	b.SetFormula(a);
	EXPECT_EQ(0,b.Check3());
}
TEST(arithmetic, check_correctly_convert_to_post)
{
	string a = "a+b*(c+b)";
	arithmetic formula;
	formula.SetFormula(a);
	formula.InfixToPost();
	a=formula.GetPost();
	string b = "a b c b + * + ";
	EXPECT_EQ(a, b);
}





