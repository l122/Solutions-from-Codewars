// https://www.codewars.com/kata/59ca8246d751df55cc00014c
#include <igloo/igloo_alt.h>
using namespace igloo;

bool hero(int bullets, int dragons) {
  return bullets >= (2 * dragons);
}

Describe(Sample_tests)
{
    It(Tests)
    {
        Assert::That(hero(10, 5), Equals(true));
        Assert::That(hero(7, 4), Equals(false));
        Assert::That(hero(4, 5), Equals(false));
        Assert::That(hero(100, 40), Equals(true));
        Assert::That(hero(1500, 751), Equals(false));
        Assert::That(hero(0, 1), Equals(false));
    }
};

int main(int argc, const char *argv[])
{
  return TestRunner::RunAllTests();
}