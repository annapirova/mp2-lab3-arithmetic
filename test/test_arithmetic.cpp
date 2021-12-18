// тесты для вычисления арифметических выражений

#include <gtest.h>
#include <string>
#include "arithmetic.h"

TEST(Arithmetic, correct_polish) {
    string S;
    S = "1+2";
    Arithmetic Arr(S);
    Arr.Polish();
    string a = "12+";
    EXPECT_EQ(a, Arr.print_polish_1());
}

TEST(Arithmetic, correct_polish_1) {
    string S;
    S = "((12+2)*2)";
    Arithmetic Arr(S);
    Arr.Polish();
    string a = "122+2*";
    EXPECT_EQ(a, Arr.print_polish_1());
}


class TestStr : public ::testing::TestWithParam<string>
{
protected:
	string S;

public:
	TestStr() : S(GetParam()) {}
	~TestStr() {}
};

TEST_P(TestStr, error_checking)
{
	Arithmetic Arr(S);
	EXPECT_EQ(1, Arr.check());
}

string arr[] = { "1+2","5.5+5.1","x+1","-1/(4-2)","a[i]*(6-10)","(-1)*10" };

INSTANTIATE_TEST_CASE_P(Instantiation, TestStr, ::testing::ValuesIn(arr));


class TestStr1 : public ::testing::TestWithParam<string>
{
protected:
    string S;

public:
    TestStr1() : S(GetParam()) {}
    ~TestStr1() {}
};

TEST_P(TestStr1, error_cheking_2)
{
    Arithmetic Arr(S);
    ASSERT_ANY_THROW(Arr.check());
}

string arr1[] = { ")(", "(*","(-+)","(+1)", ")7("};

INSTANTIATE_TEST_CASE_P(Instantiation1, TestStr1, ::testing::ValuesIn(arr1));

struct T
{
    string s;
    bool isCorrect;
    double res;

    T(string mys = "", bool f = true, double v = 0.0)
    {
        s = mys;
        isCorrect = f;
        res = v;
    }
};

class TestStr2 : public ::testing::TestWithParam<T>
{
protected:
    T testcase;
public:
    TestStr2() : testcase(GetParam()) {}
    ~TestStr2() {}
};

TEST_P(TestStr2, expression_validation)
{
    Arithmetic Res(GetParam().s);
    EXPECT_EQ(GetParam().isCorrect, Res.check());
}

T arr2[] = { /*T(")-2+6*6/9",false),*/T("3+2*(3.4-0.4)",true,9)}; // первый тест выводит фразу - "Нельзя перед открытием поставить закрывающуюся скобку"

INSTANTIATE_TEST_CASE_P(Instantiation2, TestStr2, ::testing::ValuesIn(arr2));