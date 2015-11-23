#include <gtest.h>
#include "arithmetic.h"


TEST(Arithmetic, can_pick_out)
{
	char type0[256];
	char type1[256];
	char type2[256];
	Check br("a-7");

	br.PickOut(br.s, type0, type1, type2);

 	ASSERT_NO_THROW(br.PickOut(br.s, type0, type1, type2));
	ASSERT_NO_THROW(br.CheckOperands(br.s));

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

 	ASSERT_NO_THROW(br1.CheckBrackets(br1.s));

 	EXPECT_TRUE(br1.CheckBrackets(br1.s));
 	EXPECT_FALSE(br2.CheckBrackets(br2.s));
 	EXPECT_FALSE(br3.CheckBrackets(br3.s));
 	EXPECT_FALSE(br4.CheckBrackets(br4.s));
}