// тесты для вычисления арифметических выражений
#include <gtest.h>
#include <arithmetic.h>

TEST(Tlexeme, Tlexeme_can_create_Test)
{
	ASSERT_NO_THROW(Tlexeme L);
}

TEST(Tlexeme, Tlexeme_can_create_string_Test)
{
	string a = "((2 + (2 - 3 + 1)))";
	ASSERT_NO_THROW(Tlexeme L(a));
}

TEST(Tlexeme, Tlexeme_can_create_string2_Test)
{
	string a = "1+1";
	ASSERT_NO_THROW(Tlexeme L(a));
}

TEST(Tlexeme, Tlexeme_can_fill_Test)
{
	Tlexeme L1;
	string a = "2+(3+1)";
	ASSERT_NO_THROW(L1.Fill(a));
}

TEST(Tlexeme, Tlexeme_can_fill2_Test)
{
	Tlexeme L1;
	string a = " ((2 + (2 - 3 + 1)))";
	ASSERT_NO_THROW(L1.Fill(a));

}

TEST(Tlexeme, Tlexeme_correctness_check_brackets_Test)
{
	Tlexeme L("(3+2");
	EXPECT_EQ(0, L.Check_correct());
}

TEST(Tlexeme, Tlexeme_correctness_check2_brackets_Test)
{
	Tlexeme L("3-((+2)");
	EXPECT_EQ(0, L.Check_correct());
}

TEST(Tlexeme, Tlexeme_correctness_check3_brackets_Test)
{
	Tlexeme L("3+2)");
	EXPECT_EQ(0, L.Check_correct());
}

TEST(Tlexeme, Tlexeme_correctness_check_signs_ofoperations1_Test)
{
	Tlexeme L("+3+2");
	EXPECT_EQ(0, L.Check_correct());
}

TEST(Tlexeme, Tlexeme_correctness_check_signs_ofoperations2_Test)
{
	Tlexeme L("+3+2");
	EXPECT_EQ(0, L.Check_correct());
}

TEST(Tlexeme, Tlexeme_correctness_check_signs_ofoperations3_Test)
{
	Tlexeme L("3*+2");
	EXPECT_EQ(0, L.Check_correct());
}

TEST(Tlexeme, Tlexeme_correctness_check_Test)
{
	Tlexeme L("22.00.2+1");
	EXPECT_EQ(0, L.Check_correct());
}

TEST(Tlexeme, Tlexeme_can_convert_empty_string_in_Polish_entry_Test)
{
	Tlexeme L;
	ASSERT_NO_THROW(L.Pol());
}

TEST(Tlexeme, cant_convert_incorrect_in_Polish_entry)
{
	Tlexeme L("(2+3)*6)");
	ASSERT_ANY_THROW(L.Pol());
}

TEST(Tlexeme, cant_convert_incorrect_in_Polish_entry2)
{
	Tlexeme L("(2+3)*6))");
	ASSERT_ANY_THROW(L.Pol());
}

TEST(Tlexeme, cant_convert_incorrect_in_Polish_entry3)
{
	Tlexeme L(")(2+3)*6)");
	ASSERT_ANY_THROW(L.Pol());
}

TEST(Tlexeme, cant_convert_incorrect_in_Polish_entry4)
{
	Tlexeme L("(2+3)*6)(");
	ASSERT_ANY_THROW(L.Pol());
}

TEST(Tlexeme, cant_convert_incorrect_in_Polish_entry5)
{
	Tlexeme L("(2+3)*6)()");
	ASSERT_ANY_THROW(L.Pol());
}