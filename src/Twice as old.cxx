// https://www.codewars.com/kata/5b853229cfde412a470000d0

#include <igloo/igloo_alt.h>
using namespace igloo;

int twice_as_old(int dad, int son) {
  return (2 * son - dad) > 0 ? (2 * son - dad) : dad - 2 * son;
}

Describe(Sample_Tests)
{
    It(Tests)
    {
        Assert::That(twice_as_old(36, 7), Equals(22));
        Assert::That(twice_as_old(55, 30), Equals(5));
        Assert::That(twice_as_old(42, 21), Equals(0));
        Assert::That(twice_as_old(22, 1), Equals(20));
        Assert::That(twice_as_old(29, 0), Equals(29));
    }
};

int main(int argc, const char *argv[])
{
    return TestRunner::RunAllTests();
}