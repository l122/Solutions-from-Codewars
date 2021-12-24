// https://www.codewars.com/kata/574b3b1599d8f897470018f6

#include <igloo/igloo_alt.h>
using namespace igloo;

int getRealFloor(int f) {
  return f <=0 ? f : f-- < 13 ? f : --f;
}

Describe(Tests)
{
    It(test)
    {
        Assert::That(getRealFloor(1), Equals(0));
        Assert::That(getRealFloor(5), Equals(4));
        Assert::That(getRealFloor(15), Equals(13));
    }
}; 

int main(int argc, const char *argv[])
{
    return TestRunner::RunAllTests();
}