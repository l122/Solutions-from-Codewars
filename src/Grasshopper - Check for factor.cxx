// https://www.codewars.com/kata/55cbc3586671f6aa070000fb
#include <igloo/igloo_alt.h>
using namespace igloo;

bool checkForFactor(int base, int factor) {
  return !(base % factor);
}

Describe(CheckFactor) {
  It(ShouldReturnTrue) {
    Assert::That(checkForFactor(10, 2), Equals(true));
    Assert::That(checkForFactor(63, 7), Equals(true));
    Assert::That(checkForFactor(2450, 5), Equals(true));
    Assert::That(checkForFactor(24612, 3), Equals(true));
  }
  It(ShouldReturnFalse) {
    Assert::That(checkForFactor(9, 2), Equals(false));
    Assert::That(checkForFactor(653, 7), Equals(false));
    Assert::That(checkForFactor(2453, 5), Equals(false));
    Assert::That(checkForFactor(24617, 3), Equals(false));
  }
};

int main(int argc, const char *argv[])
{
    return TestRunner::RunAllTests();
}