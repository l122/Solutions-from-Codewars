// https://www.codewars.com/kata/557b5e0bddf29d861400005d
#include <igloo/igloo_alt.h>
using namespace igloo;

#include <cmath>

double converter(int mpg)
{
    return std::round(mpg * 1.609344 / 4.54609188 * 100) / 100;
}

Describe(Tests)
{
    It(ExampleTests)
    {
        Assert::That(converter(12), Equals(4.25));
        Assert::That(converter(24), Equals(8.50));
        Assert::That(converter(36), Equals(12.74));
    }
};

int main(int argc, const char *argv[])
{
  return TestRunner::RunAllTests();
}