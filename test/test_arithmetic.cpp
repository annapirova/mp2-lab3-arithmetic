#include <gtest.h>
#include "arithmetic.h"

TEST(Arithmetic, can_pick_out)
{
	char type0[256];
	char type1[256];
	char type2[256];
	char temp[] = "a-7";
//	PickOut(temp, type0, type1, type2);

 	ASSERT_NO_THROW(PickOut(temp, type0, type1, type2));
//	ASSERT_NO_THROW(CheckOperands(temp));

 	EXPECT_EQ(type1[0], 'a');
	EXPECT_EQ(type2[0], '-');
	EXPECT_EQ(type0[0], '7');
}

 TEST(Arithmetic, can_check_the_brackets)
{
 	char temp1[] = "(1+2)*3";
 	char temp2[] = "(1+2)*3)";
 	char temp3[] = "(1+2)*3(";
 	char temp4[] = "((((1+2)*3()";

//	CheckBrackets(temp1);
// 	ASSERT_NO_THROW(CheckBrackets(temp1));

 	//EXPECT_TRUE(CheckBrackets(temp1));
 	//EXPECT_FALSE(CheckBrackets(temp2));
 	//EXPECT_FALSE(CheckBrackets(temp3));
 	//EXPECT_FALSE(CheckBrackets(temp4));
}