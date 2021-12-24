// https://www.codewars.com/kata/55685cd7ad70877c23000102

#include <igloo/igloo_alt.h>
using namespace igloo;

int makeNegative(int num)
{
  return num > 0 ? -num : num;
}

Describe(make_negative_algorithm)
{
    It(should_handle_positive_test)
    {
        Assert::That(makeNegative(42), Equals(-42));
        Assert::That(makeNegative(-9), Equals(-9));
    }
};

int main(int argc, const char *argv[])
{
    return TestRunner::RunAllTests();
}