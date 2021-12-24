// https://www.codewars.com/kata/5a2b703dc5e2845c0900005a

#include <igloo/igloo_alt.h>
using namespace igloo;

bool isDivideBy(int number, int a, int b)
{
  return number % a == 0 && number % b == 0;
}

Describe(isDivideByTests)
{
    It(BasicTests)
    {
        Assert::That(isDivideBy(8, 2, 4), Equals(true));
        Assert::That(isDivideBy(12, -3, 4), Equals(true));
        Assert::That(isDivideBy(8, 3, 4), Equals(false));
        Assert::That(isDivideBy(48, 2, -5), Equals(false));
        Assert::That(isDivideBy(-100, -25, 10), Equals(true));
        Assert::That(isDivideBy(10000, 5, -3), Equals(false));
        Assert::That(isDivideBy(4, 4, 2), Equals(true));
        Assert::That(isDivideBy(5, 2, 3), Equals(false));
        Assert::That(isDivideBy(-96, 25, 17), Equals(false));
        Assert::That(isDivideBy(33, 1, 33), Equals(true));
    }
};

int main(int argc, const char *argv[])
{
    return TestRunner::RunAllTests();
}