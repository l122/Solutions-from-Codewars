// https://www.codewars.com/kata/53da3dbb4a5168369a0000fe

#include <igloo/igloo_alt.h>
using namespace igloo;

#include <string>

std::string even_or_odd(int number) 
{
  return number & 1 ? "Odd" : "Even";
}

Describe(even_or_odd_method)
{
    It(basic_tests)
    {
        Assert::That(even_or_odd(2), Equals("Even"));
        Assert::That(even_or_odd(1), Equals("Odd"));
        Assert::That(even_or_odd(0), Equals("Even"));
        Assert::That(even_or_odd(7), Equals("Odd"));
        Assert::That(even_or_odd(-1), Equals("Odd"));
    }
};

int main(int argc, const char *argv[])
{
    return TestRunner::RunAllTests();
}