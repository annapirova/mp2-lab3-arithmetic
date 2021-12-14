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
////////////////////////////////////////////////
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
////////////////////////////////////////////////
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

TEST(Arithmetic, cget_RPN_str_is_correct) {
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
    cor_lex.push_back(lexem("3"));
    cor_lex.push_back(lexem("+"));
    cor_lex.push_back(lexem("4"));
    cor_lex.push_back(lexem("*"));
    cor_lex.push_back(lexem("("));
    cor_lex.push_back(lexem("sqrt"));
    cor_lex.push_back(lexem("("));
    cor_lex.push_back(lexem("4"));
    cor_lex.push_back(lexem(")"));
    cor_lex.push_back(lexem("-"));
    cor_lex.push_back(lexem("sin"));
    cor_lex.push_back(lexem("("));
    cor_lex.push_back(lexem("1"));
    cor_lex.push_back(lexem(")"));
    cor_lex.push_back(lexem(")"));

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