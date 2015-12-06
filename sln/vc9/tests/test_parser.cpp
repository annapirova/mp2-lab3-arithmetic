#include <gtest.h>
#include "parser.h"

TEST(TParser,can_create_new_TParser){
	char s[]="4+7";
	TParser p(s);
	p.Convert();
	EXPECT_EQ(s[0],p.GetPostf(0));
	EXPECT_EQ(s[1],p.GetPostf(4));
	EXPECT_EQ(s[2],p.GetPostf(2));
}

TEST(TParser,check_is_oper){
	char a[]="1+2";
	TParser p(a);
	EXPECT_TRUE(p.IsOper(a[1]));
}

TEST(TParser,check_is_number){
	char a[]="1+2";
	TParser p(a);
	EXPECT_TRUE(p.IsNumber(a[0]));
}

TEST(TParser,can_convert_and_calc){
	char s[]="12.5+7";
	TParser p(s);
	p.Convert();
	double res=p.calc();
	EXPECT_EQ(19.5,res);
}


TEST(TParser,can_add)
{
	char s[]="7.5+2";
	TParser p(s);
	p.Convert();
	double res=p.calc();
	EXPECT_EQ(9.5,res);	
}

TEST(TParser,can_subtract)
{
	char s[]="1-0.4";
    TParser p(s);
	p.Convert();
	double res=p.calc();
	EXPECT_EQ(0.6,res);	
}

TEST(TParser,can_divide_values)
{
	char s[]="4.2/2";
	TParser p(s);
	p.Convert();
	double res=p.calc();
	EXPECT_EQ(2.1,res);	
}

TEST(TParser,can_multiply)
{
	char s[]="3.5*3";
	TParser p(s);
	p.Convert();
	double res=p.calc();
	EXPECT_EQ(10.5,res);	
}

