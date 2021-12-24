// https://www.codewars.com/kata/555086d53eac039a2a000083

#include <igloo/igloo_alt.h>
using namespace igloo;

bool lovefunc(int f1, int f2) {
  return (f1 + f2) % 2;
}

Describe(Fixed_tests) {
  It(Valid_cases) {
    Assert::That(lovefunc(1, 2), Equals(true));
    Assert::That(lovefunc(0, 3), Equals(true));
    Assert::That(lovefunc(99, 198), Equals(true));
  }
  It(Invalid_cases) {
    Assert::That(lovefunc(0, 0), Equals(false));
    Assert::That(lovefunc(2, 2), Equals(false));
    Assert::That(lovefunc(101, 101), Equals(false));
  }
};

int main(int argc, const char *argv[])
{
    return TestRunner::RunAllTests();
}