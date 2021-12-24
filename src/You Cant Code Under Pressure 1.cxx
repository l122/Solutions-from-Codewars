// https://www.codewars.com/kata/53ee5429ba190077850011d4

#include <igloo/igloo_alt.h>
using namespace igloo;


#include <cstdint>

int32_t double_integer(int32_t n)
{
  return n + n;
}

int32_t double_integer(int32_t);

Describe(should_pass_all_tests_provided)
{
   It(Sample_tests)
   {
      Assert::That(double_integer(1), Equals(2));
      Assert::That(double_integer(5), Equals(10));
      Assert::That(double_integer(10), Equals(20));
      Assert::That(double_integer(20), Equals(40));
      Assert::That(double_integer(40), Equals(80));
   }
};

int main(int argc, const char *argv[])
{
    return TestRunner::RunAllTests();
}