#include <gtest.h>

#include "arithmetic.h"

TEST(Arithmetic,can_check_brackets)
{
	char s[7]={'(','(','a','*','b',')',')'};
	EXPECT_TRUE(Check(s));
}

TEST(Arithmetic,can_detect_type)
{
	char s[]="5*a+7";
	int type [5];
	for (int i=0;i<5;i++)
		type[i]=DType(s[i]);
	EXPECT_EQ(1,type[0]);
	EXPECT_EQ(3,type[1]);
	EXPECT_EQ(2,type[2]);
	EXPECT_EQ(3,type[3]);
	EXPECT_EQ(1,type[4]);
}

TEST(Arithmetic,check_lack_of_operands)
{
	char s[]="a-";
	EXPECT_FALSE(CheckOperands(s));
}

TEST(Arithmetic,can_detect_prioritet)
{
	char s[]="51*a";
	int pr;
	pr=prior(s[2]);
	EXPECT_EQ(3,pr);
}

TEST(Arithmetic,can_chek_oper)
{
	char s[]="5++a";
	EXPECT_FALSE(CheckOper(s));
}