// https://www.codewars.com/kata/5545f109004975ea66000086

#include <igloo/igloo_alt.h>
using namespace igloo;

bool isDivisible(int n, int x, int y) {
  return n % x == 0 && n % y == 0;
}

Describe(IsDivisible) {
  It(BasicTests) {
    Assert::That(isDivisible(3, 3, 4), Equals(false));
    Assert::That(isDivisible(12, 3, 4), Equals(true));
    Assert::That(isDivisible(8, 3, 4), Equals(false));
    Assert::That(isDivisible(48, 3, 4), Equals(true));
    Assert::That(isDivisible(100, 5, 10), Equals(true));
    Assert::That(isDivisible(100, 5, 3), Equals(false));
    Assert::That(isDivisible(4, 4, 2), Equals(true));
    Assert::That(isDivisible(5, 2, 3), Equals(false));
    Assert::That(isDivisible(17, 17, 17), Equals(true));
    Assert::That(isDivisible(17, 1, 17), Equals(true));
  }
};

int main(int argc, const char *argv[])
{
    return TestRunner::RunAllTests();
}