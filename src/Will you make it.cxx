// https://www.codewars.com/kata/5861d28f124b35723e00005e

#include <igloo/igloo_alt.h>
using namespace igloo;

bool zero_fuel(uint32_t distance_to_pump, uint32_t mpg, uint32_t fuel_left)
{
  return distance_to_pump <= mpg * fuel_left;
}

Describe(zero_fuel_function)
{
    It(should_pass_sample_tests)
    {
        Assert::That(zero_fuel(50, 25, 2), Equals(true));
        Assert::That(zero_fuel(100, 50, 1), Equals(false));
    }
};

int main(int argc, const char *argv[])
{
    return TestRunner::RunAllTests();
}