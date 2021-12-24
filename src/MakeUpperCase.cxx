// https://www.codewars.com/kata/57a0556c7cb1f31ab3000ad7

#include <igloo/igloo_alt.h>
using namespace igloo;

#include <string>
#include <algorithm>

std::string makeUpperCase (const std::string& input_str)
{
  std::string out(input_str);
  std::transform(out.begin(), out.end(), out.begin(), toupper);
  return out;
}

Describe(The_makeUpperCase_function)
{
    It(should_pass_all_the_tests_provided)
    {
        Assert::That(makeUpperCase("hello"), Equals("HELLO"));
    }
};

int main(int argc, const char *argv[])
{
    return TestRunner::RunAllTests();
}