#include <gtest.h>
#include "arithmetic.h"

TEST(Arithmetic, Can_Check_Create)
{
	ASSERT_ANY_THROW(Check br("\0"));
}
TEST(Arithmetic, can_pick_out)
{
	char type0[256];
	char type1[256];
	char type2[256];
	Check br("a-7+8.5");

	br.PickOut(type0, type1, type2);

 	ASSERT_NO_THROW(br.PickOut(type0, type1, type2));

 	EXPECT_EQ(type1[0], 'a');
	EXPECT_EQ(type2[0], '-');
	EXPECT_EQ(type0[0], '7');
	EXPECT_EQ(type2[1], '+');
	EXPECT_EQ(type0[1], '8.5');
}
TEST(Arithmetic,can_identify_unary_minus)
{
	Check str = "(-3.2*a)+5\0";
	EXPECT_TRUE(str.IsUnarMinus());
}
TEST(Arithmetic,can_process_unary_minus_at_the_beginning)
{
	Check str ="-2*a";
	char newstr[256];
	str.UnarMinus(newstr);
	EXPECT_EQ('0',newstr[0]);
	EXPECT_EQ('-',newstr[1]);
	EXPECT_EQ('2',newstr[2]);
	EXPECT_EQ('*',newstr[3]);
	EXPECT_EQ('a',newstr[4]);
}
TEST(Arithmetic,can_process_unary_minus_after_open_bracket)
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
TEST(Arithmetic, can_check_the_brackets)
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

TEST(Arithmetic, can_check_operands)
{
	Check br("a-7");
	ASSERT_NO_THROW(br.CheckOperands());
}

TEST(Arithmetic, prioritet)
{
	Check br("a-7");
	int k;

	for (int i = 0; i < 3; i++){
		k = br.Prioritet(br.s[i]);
	//	cout << k << endl;
	//	cout << br.s[i] << endl;
		if ( k != -1)
			EXPECT_EQ(k, 1);
	}
}
TEST(Arithmetic, Can_ChangeExpression)
{
	Check br("a-7");
	char k[] = "a7-";
	
	char res[256];
	br.ChangeExpression(res);
	for(int i = 0; i < 2; i++)
		EXPECT_EQ(k[i], br.s[i]);
}
