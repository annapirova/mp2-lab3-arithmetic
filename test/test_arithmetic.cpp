#include <gtest.h>
#include "arithmetic.h"

TEST(Arithmetic,can_check_brackets)
{
	char s[]="((a*b(5+a)))";
	EXPECT_TRUE(CheckSkob(s));
}

TEST(Arithmetic,can_check_fail_brackets)
{
	char s[]="(a+b";
	EXPECT_FALSE(CheckSkob(s));
}

TEST(Arithmetic,can_detect_type)
{
	char s[]="5*a+7,5";
	int type [7];
	for (int i=0;i<7;i++)
		type[i]=DType(s[i]);
	EXPECT_EQ(1,type[0]);
	EXPECT_EQ(3,type[1]);
	EXPECT_EQ(2,type[2]);
	EXPECT_EQ(3,type[3]);
	EXPECT_EQ(1,type[4]);
	EXPECT_EQ(4,type[5]);
}

TEST(Arithmetic,check_lack_of_operands)
{
	char s[]="a-";
	EXPECT_FALSE(CheckOperands(s));
}

TEST(Arithmetic,can_detect_prioritet)
{
	char s[]="51*a+b";
	int pr1,pr2;
	pr1=prior(s[2]);
	pr2=prior(s[4]);
	EXPECT_EQ(3,pr1);
	EXPECT_EQ(2,pr2);
}

TEST(Arithmetic,can_chek_oper)
{
	char s[]="5++a";
	EXPECT_FALSE(CheckOper(s));
}

TEST(Arithmetic,check_all_is_true)
{
	char s[]="(a+b)";
	EXPECT_TRUE(CheckAll(s));
}

TEST(Arithmetic,check_all_is_false)
{
	char s[]="a+b-";
	EXPECT_FALSE(CheckAll(s));
}

TEST(Arithmetic,check_comma_in_point){
	char s[]="7,5+4";
	InPoint(s);
	EXPECT_EQ(s[1],'.');
}

TEST(Arithmetic,check_operand_is_false){
	char s[]="à+á";
	EXPECT_FALSE(operand_true_1(s));
}

TEST(Arithmetic,check_operand_is_true){
	char s[]="a+b";
	EXPECT_TRUE(operand_true_1(s));
}

TEST(Arithmetic,check_unarn_minus_1_is_true){
	char s[]="-a+b";
	EXPECT_TRUE(CheckUnarMinus(s));
}

TEST(Arithmetic,check_unarn_minus_2_is_true){
	char s[]="a*(-b)";
	EXPECT_TRUE(CheckUnarMinus(s));
}

TEST(Arithmetic,check_unarn_minus_3_is_true){
	char s[]="-a-b";
	EXPECT_TRUE(CheckUnarMinus(s));
}









