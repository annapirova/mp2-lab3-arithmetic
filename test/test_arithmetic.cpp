#include "arithmetic.h"
#include "gtest/gtest.h"


TEST(Arithmetic, can_create) {
    ASSERT_NO_THROW(Arithmetic a("3-1"));
}

TEST(Arithmetic, can_launch) {
    Arithmetic a("3 + 4 * (sqrt(4) - sin(1) )");
    ASSERT_NO_THROW(a.launch());
}

TEST(Arithmetic, can_get_input_str) {
    string s = "3 + 4 * (sqrt(4) - sin(1) )";
    Arithmetic a(s);
    ASSERT_NO_THROW(a.get_input_str());
}

TEST(Arithmetic, can_get_corrected_str) {
    string s = "3 + 4 * (sqrt(4) - sin(1) )";
    Arithmetic a(s);
    a.launch();
    ASSERT_NO_THROW(a.get_corrected_str());
}

TEST(Arithmetic, can_get_RPN_str) {
    string s = "3 + 4 * (sqrt(4) - sin(1) )";
    Arithmetic a(s);
    a.launch();
    ASSERT_NO_THROW(a.get_RPN_str());
}

TEST(Arithmetic, can_get_cor_lexem) {

    string s = "3 + 4 * (sqrt(4) - sin(1) )";
    Arithmetic a(s);
    a.launch();
    ASSERT_NO_THROW(a.get_lexem_list_of_corrected_str());
}

TEST(Arithmetic, can_get_RPN_lexem) {
    string s = "3 + 4 * (sqrt(4) - sin(1) )";
    Arithmetic a(s);
    a.launch();
    ASSERT_NO_THROW(a.get_lexem_list_of_RPN_str());
}

TEST(Arithmetic, can_get_res) {
    string s = "3 + 4 * (sqrt(4) - sin(1) )";
    Arithmetic a(s);
    a.launch();
    ASSERT_NO_THROW(a.get_res());
}

TEST(Arithmetic, corrected_str_without_launch_is_empty) {
    string s = "3 + 4 * (sqrt(4) - sin(1) )";
    Arithmetic a(s);
    EXPECT_EQ("", a.get_corrected_str());
}

TEST(Arithmetic, RPN_str_without_launch_is_empty) {
    string s = "3 + 4 * (sqrt(4) - sin(1) )";
    Arithmetic a(s);
    EXPECT_EQ("", a.get_RPN_str());
}

TEST(Arithmetic, cor_lexem_without_launch_is_empty) {

    string s = "3 + 4 * (sqrt(4) - sin(1) )";
    Arithmetic a(s);
    EXPECT_EQ(1, a.get_lexem_list_of_corrected_str().empty());
}

TEST(Arithmetic, RPN_lexem_without_launch_is_empty) {
    string s = "3 + 4 * (sqrt(4) - sin(1) )";
    Arithmetic a(s);
    EXPECT_EQ(1, a.get_lexem_list_of_RPN_str().empty());
}

TEST(Arithmetic, res_without_launch_eq_0) {
    string s = "3 + 4 * (sqrt(4) - sin(1) )";
    Arithmetic a(s);
    EXPECT_EQ(0.0, a.get_res());
}

TEST(Arithmetic, get_input_str_is_correct) {
    string s = "3 + 4 * (sqrt(4) - sin(1) )";
    Arithmetic a(s);
    EXPECT_EQ(s, a.get_input_str());
}

TEST(Arithmetic, get_corrected_str_is_correct) {
    string s = "3 + 4 * (sqrt(4) - sin(1) )";
    string expected_str = "3+4*(sqrt(4)-sin(1))";
    Arithmetic a(s);
    a.launch();
    EXPECT_EQ(expected_str, a.get_corrected_str());
}

TEST(Arithmetic, get_RPN_str_is_correct) {
    string s = "3 + 4 * (sqrt(4) - sin(1) )";
    string RPN_str = " 3 4 4 sqrt 1 sin - * +";
    Arithmetic a(s);
    a.launch();
    EXPECT_EQ(RPN_str, a.get_RPN_str());
}

TEST(Arithmetic, get_cor_lexem_is_correct) {

    string s = "3 + 4 * (sqrt(4) - sin(1) )";
    Arithmetic a(s);
    a.launch();
    list<lexem> cor_lex;
    cor_lex.emplace_back("3");
    cor_lex.emplace_back("+");
    cor_lex.emplace_back("4");
    cor_lex.emplace_back("*");
    cor_lex.emplace_back("(");
    cor_lex.emplace_back("sqrt");
    cor_lex.emplace_back("(");
    cor_lex.emplace_back("4");
    cor_lex.emplace_back(")");
    cor_lex.emplace_back("-");
    cor_lex.emplace_back("sin");
    cor_lex.emplace_back("(");
    cor_lex.emplace_back("1");
    cor_lex.emplace_back(")");
    cor_lex.emplace_back(")");

    for (const auto &i: a.get_lexem_list_of_corrected_str()) {
        EXPECT_EQ(cor_lex.front().value, i.value);
        EXPECT_EQ(cor_lex.front().type, i.type);
        cor_lex.pop_front();
    }
}

TEST(Arithmetic, get_RPN_lexem_is_correct) {
    string s = "3 + 4 * (sqrt(4) - sin(1) )";
    Arithmetic a(s);
    a.launch();
    list<lexem> cor_lex;
    cor_lex.emplace_back("3");
    cor_lex.emplace_back("4");
    cor_lex.emplace_back("4");
    cor_lex.emplace_back("sqrt");
    cor_lex.emplace_back("1");
    cor_lex.emplace_back("sin");
    cor_lex.emplace_back("-");
    cor_lex.emplace_back("*");
    cor_lex.emplace_back("+");

    for (const auto &i: a.get_lexem_list_of_RPN_str()) {
        EXPECT_EQ(cor_lex.front().value, i.value);
        EXPECT_EQ(cor_lex.front().type, i.type);
        cor_lex.pop_front();
    }
}

TEST(Arithmetic, get_res_is_correct) {
    string s = "3 + 4 * (sqrt(4) - sin(1) )";
    Arithmetic a(s);
    a.launch();
    double eps = 1e-10;
    double delta = a.get_res() - 7.63412;
    EXPECT_GE(eps, delta);
}

// Added tests
TEST(Arithmetic, can_create_with_empty_string) {
    ASSERT_NO_THROW(Arithmetic a(""));
}

TEST(Arithmetic, can_launch_with_empty_string) {
    Arithmetic a("");
    ASSERT_NO_THROW(a.launch());
}

TEST(Arithmetic, cant_launch_with_one_skob) {
    Arithmetic a("(");
    ASSERT_ANY_THROW(a.launch());
}

TEST(Arithmetic, cant_launch_with_two_skob) {
    Arithmetic a(") (");
    ASSERT_ANY_THROW(a.launch());
}

TEST(Arithmetic, cant_launch_with_pair_skob) {
    Arithmetic a("(  )");
    ASSERT_ANY_THROW(a.launch());
}

TEST(Arithmetic, cant_launch_with_some_skob) {
    Arithmetic a("()((()))");
    ASSERT_ANY_THROW(a.launch());
}

TEST(Arithmetic, cant_launch_with_skob_and_operand) {
    Arithmetic a(")7 (");
    ASSERT_ANY_THROW(a.launch());
}

TEST(Arithmetic, cant_launch_with_one_plus) {
    Arithmetic a("+");
    ASSERT_ANY_THROW(a.launch());
}

TEST(Arithmetic, cant_launch_with_two_plus) {
    Arithmetic a("++");
    ASSERT_ANY_THROW(a.launch());
}

TEST(Arithmetic, cant_launch_with_plus_and_operand) {
    Arithmetic a("+q");
    ASSERT_ANY_THROW(a.launch());
}

TEST(Arithmetic, cant_launch_with_one_mul) {
    Arithmetic a("*");
    ASSERT_ANY_THROW(a.launch());
}

TEST(Arithmetic, cant_launch_with_two_mul) {
    Arithmetic a("* *");
    ASSERT_ANY_THROW(a.launch());
}

TEST(Arithmetic, cant_launch_with_mul_operand) {
    Arithmetic a("*9");
    ASSERT_ANY_THROW(a.launch());
}

TEST(Arithmetic, cant_launch_with_one_pow) {
    Arithmetic a("^");
    ASSERT_ANY_THROW(a.launch());
}

TEST(Arithmetic, cant_launch_with_two_pow) {
    Arithmetic a("^ ^");
    ASSERT_ANY_THROW(a.launch());
}

TEST(Arithmetic, cant_launch_with_pow_and_operand) {
    Arithmetic a("^n");
    ASSERT_ANY_THROW(a.launch());
}

TEST(Arithmetic, can_launch_with_minus_and_operand) {
    Arithmetic a("-2");
    ASSERT_NO_THROW(a.launch());
}

TEST(Arithmetic, cant_launch_with_operand_and_minus) {
    Arithmetic a("1-");
    ASSERT_ANY_THROW(a.launch());
}

TEST(Arithmetic, cant_launch_with_operand_and_divide) {
    Arithmetic a("1/");
    ASSERT_ANY_THROW(a.launch());
}

TEST(Arithmetic, cant_launch_with_operand_and_pow) {
    Arithmetic a("1^");
    ASSERT_ANY_THROW(a.launch());
}

TEST(Arithmetic, correct_res_with_equal_priority_znak) {
    string s = "1 + 2 + 3 - 4 - 5 + 6";
    Arithmetic a(s);
    a.launch();
    double eps = 1e-10;
    double delta = a.get_res() - 3.0;
    EXPECT_GE(eps, delta);
}

TEST(Arithmetic, correct_res_with_not_equal_priority_znak) {
    string s = "1 + 2 * 3 + 4 / 5 -  6";
    Arithmetic a(s);
    a.launch();
    double eps = 1e-10;
    double delta = a.get_res() - 1.8;
    EXPECT_GE(eps, delta);
}

TEST(Arithmetic, can_make_func_in_func) {
    string s = "cos(cos(98))";
    Arithmetic a(s);
    EXPECT_NO_THROW(a.launch());
}

TEST(Arithmetic, can_get_correct_func_in_func) {
    string s = "cos(cos(arccos(arccos(1.0))))";
    Arithmetic a(s);
    double eps = 1e-10;
    double delta = a.get_res() - 1.0;
    EXPECT_GE(eps, delta);
}