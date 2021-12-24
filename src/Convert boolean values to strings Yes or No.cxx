// https://www.codewars.com/kata/53369039d7ab3ac506000467

#include <igloo/igloo_alt.h>
using namespace igloo;

#include <string>

std::string bool_to_word(bool value)
{
  return value ? "Yes" : "No";
}

Describe(bool_to_word_method)
{
    It(basic_tests)
    {
        Assert::That(bool_to_word(true), Equals("Yes"));
        Assert::That(bool_to_word(false), Equals("No"));
    }
};

int main(int argc, const char *argv[])
{
    return TestRunner::RunAllTests();
}