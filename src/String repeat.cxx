// https://www.codewars.com/kata/57a0e5c372292dd76d000d7e

#include <igloo/igloo_alt.h>
using namespace igloo;

#include <string>

std::string repeat_str(size_t repeat, const std::string& str) {
  return repeat > 0 ? str + repeat_str(repeat - 1, str) : "";
}

Describe(Fixed_tests) {
  It(Sample_cases) {
    Assert::That(repeat_str(3, "*"), Equals("***"));
    Assert::That(repeat_str(5, "#"), Equals("#####"));
    Assert::That(repeat_str(2, "ha "), Equals("ha ha "));
    Assert::That(repeat_str(5, ">"), Equals(">>>>>"));
    Assert::That(repeat_str(10, "!"), Equals("!!!!!!!!!!"));
    Assert::That(repeat_str(3, "hello "), Equals("hello hello hello "));
    Assert::That(repeat_str(3, "$"), Equals("$$$"));
    Assert::That(repeat_str(5, "a"), Equals("aaaaa"));
    Assert::That(repeat_str(6, "A"), Equals("AAAAAA"));
    Assert::That(repeat_str(7, "aA"), Equals("aAaAaAaAaAaAaA"));
    Assert::That(repeat_str(3, ""), Equals(""));
    Assert::That(repeat_str(0, "null"), Equals(""));
    Assert::That(repeat_str(0, ""), Equals(""));
  }
};


int main(int argc, const char *argv[])
{
    return TestRunner::RunAllTests();
}