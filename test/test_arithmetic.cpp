#include <gtest.h>
#include "arithmetic.h"

TEST(Arithmetic, Can_Check_Create)
{
	ASSERT_NO_THROW(Check br("ff")); //нужно править
}
TEST(Arithmetic, can_pick_out)
{
	char type0[256];
	char type1[256];
	char type2[256];
	Check br("a-7");

	br.PickOut(type0, type1, type2);

 	ASSERT_NO_THROW(br.PickOut(type0, type1, type2));

 	EXPECT_EQ(type1[0], 'a');
	EXPECT_EQ(type2[0], '-');
	EXPECT_EQ(type0[0], '7');
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
//тест падает
TEST(Arithmetic, prioritet)
{
	Check br("a-7");

	int k;
	char res[256];
	br.ChangeExpression(res);

	for (int i = 0; i < 3; i++){
		k = br.Prioritet(res[i]);
		cout << k << endl; 
	}

	EXPECT_EQ(k, 1);
}
// тест компилируетс€
TEST(Arithmetic, Can_ChangeExpression)
{
	Check br("a-7");
	char k[] = "a7-";
	
	char res[256];
	br.ChangeExpression(res);
	for(int i = 0; i < 2; i++)
		EXPECT_EQ(k[i], br.s[i]);
}