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



