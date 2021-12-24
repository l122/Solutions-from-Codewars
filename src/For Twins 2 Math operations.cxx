// https://www.codewars.com/kata/59c287b16bddd291c700009a

#include <igloo/igloo_alt.h>
using namespace igloo;

int ice_brick_volume(int radius, int bottle_length, int rim_length) {
  return 2 * radius * radius * (bottle_length - rim_length);
}

Describe(Fixed_Tests)
{
    It(Basic_tests)
    {
        Assert::That(ice_brick_volume(1, 10, 2), Equals(16));
        Assert::That(ice_brick_volume(5, 30, 7), Equals(1150));
    }
};


int main(int argc, const char *argv[])
{
    return TestRunner::RunAllTests();
}