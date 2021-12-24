// https://www.codewars.com/kata/56dec885c54a926dcd001095

#include <igloo/igloo_alt.h>
using namespace igloo;

int opposite(int number) 
{
  return -number;
}

Describe(opposite_method)
{
    It(basic_tests)
    {
        Assert::That(opposite(1), Equals(-1));
    }
};

int main(int argc, const char *argv[])
{
    return TestRunner::RunAllTests();
}