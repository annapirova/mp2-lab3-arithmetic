// тесты для вычисления арифметических выражений

#include <gtest.h>
#include <string>
#include "arithmetic.h"

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

T arr2[] = { T("3+2*(3.4-0.4)",true,9),T(")-2+6*6/9",false) }; // второй тест выводит фразу - "Нельзя перед открытием поставить закрывающуюся скобку"

INSTANTIATE_TEST_CASE_P(Instantiation2, TestStr2, ::testing::ValuesIn(arr2));