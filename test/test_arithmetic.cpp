#include <gtest.h>
#include "arithmetic.h"

TEST(Arithmetic, Can_Check_Create)
{
	ASSERT_ANY_THROW(Check br("\0"));
}

TEST(Arithmetic, Can_pick_out)
{
	char type0[256];
	char type1[256];
	char type2[256];
	char type3[256];
	Check br("a-78+8.5\0");

	br.PickOut(type0, type1, type2, type3);

 	ASSERT_NO_THROW(br.PickOut(type0, type1, type2, type3));

	EXPECT_EQ(type1[0], 'a');
	EXPECT_EQ(type2[0], '-');
	EXPECT_EQ(type0[0], '78');
	EXPECT_EQ(type2[1], '+');
	EXPECT_EQ(type3[0], '8.5');
}


TEST(Arithmetic,Can_identify_unary_minus)
{
	Check str = "(-3.2*a)+5\0";
	EXPECT_TRUE(str.IsUnarMinus());
}
TEST(Arithmetic,Unar_minus_at_the_beginning)
{
	Check str ="-2*a\0";
	char newstr[256];
	str.UnarMinus(newstr);
	EXPECT_EQ('0',newstr[0]);
	EXPECT_EQ('-',newstr[1]);
	EXPECT_EQ('2',newstr[2]);
	EXPECT_EQ('*',newstr[3]);
	EXPECT_EQ('a',newstr[4]);
}
TEST(Arithmetic,Unar_minus_after_open_bracket)
{
	Check str = "5+(-6)";
	char newstr[256];
	str.UnarMinus(newstr);
	EXPECT_EQ('5',newstr[0]);
	EXPECT_EQ('+',newstr[1]);
	EXPECT_EQ('(',newstr[2]);
	EXPECT_EQ('0',newstr[3]);
	EXPECT_EQ('-',newstr[4]);
	EXPECT_EQ('6',newstr[5]);
	EXPECT_EQ(')',newstr[6]);
}
TEST(Arithmetic, Can_check_the_brackets)
{
	Check br1("(1+2)*3");
	Check br2("(1+2)*3)");
	Check br3("(1+2)*3(");
	Check br4("((((1+2)*3()");

 	ASSERT_NO_THROW(br1.CheckBrackets());

 	EXPECT_TRUE(br1.CheckBrackets());
 	EXPECT_FALSE(br2.CheckBrackets());
 	EXPECT_FALSE(br3.CheckBrackets());
 	EXPECT_FALSE(br4.CheckBrackets());
}

TEST(Arithmetic, Can_check_operands)
{
	Check br("a-7");
	ASSERT_NO_THROW(br.CheckOperands());
}

TEST(Arithmetic, Prioritet)
{
	Check br("a-7");
	int k;

	for (int i = 0; i < 3; i++){
		k = br.Prioritet(br.s[i]);
		if ( k != -1)
			EXPECT_EQ(k, 1);
	}
}
TEST(Arithmetic, Can_ChangeExpression)
{
	Check br("a-7\0");
	char res[4];
	
	br.ChangeExpression(res);
	EXPECT_EQ('a', res[0]);
	EXPECT_EQ('7', res[2]);
	EXPECT_EQ('-', res[4]);

}
TEST(Arithmetic,Can_add_int)
{
	Check br("3+5\0");
 	double res;
 	Check result("");
	br.ChangeExpression(result.s);
	res = result.Calculation();
 	EXPECT_EQ(8,res);	
}
TEST(Arithmetic,Can_add_double)
{
	Check br("0.5+5\0");
 	double res;
 	Check result("");
	br.ChangeExpression(result.s);
	res = result.Calculation();
 	EXPECT_EQ(5.5,res);	
}
TEST(Arithmetic,Can_subtract_double)
{
 	Check br("5.5-5\0");
 	double res;
 	Check result("");
	br.ChangeExpression(result.s);
	res = result.Calculation();
 	EXPECT_EQ(0.5,res);	
}
 TEST(Arithmetic,Can_multiply_double)
{
 	Check br("0.5*2\0");
 	double res;
 	Check result("");
	br.ChangeExpression(result.s);
	res = result.Calculation();
 	EXPECT_EQ(1,res);	
}
 TEST(Arithmetic,Can_divide_int)
{
 	Check br("13/2\0");
 	double res;
 	Check result("");
	br.ChangeExpression(result.s);
	res = result.Calculation();
 	EXPECT_EQ(6.5,res);	
}
 TEST(Arithmetic,Can_involute_int)
{
 	Check br("2^3\0");
 	double res;
 	Check result("");
	br.ChangeExpression(result.s);
	res = result.Calculation();
 	EXPECT_EQ(8,res);	
}
 TEST(Arithmetic,can_calculate_expression_with_brackets)
 {
 	Check br("(5+2*7)*3-21\0");
 	double res;
 	Check result("");
	br.ChangeExpression(result.s);
	res = result.Calculation();
 	EXPECT_EQ(36,res);	
 }
 TEST(Arithmetic,can_calculate_expression_without_brackets)
 {
 	Check br("5+2*7*3-21\0");
 	double res;
 	Check result("");
	br.ChangeExpression(result.s);
	res = result.Calculation();
 	EXPECT_EQ(26,res);	
 }