// https://www.codewars.com/kata/5933a1f8552bc2750a0000ed

#include <igloo/igloo_alt.h>
using namespace igloo;

int nthEven(int n) {
  return n > 1 ? 2 * (n-1) : 0;
}

//Clever solution from codewars
// int nthEven(int n) {
//   return n * 2 - 2;
// }

Describe(NthEven) {
  It(FixedTests) {
    Assert::That(nthEven(1), Equals(0));
    Assert::That(nthEven(2), Equals(2));
    Assert::That(nthEven(3), Equals(4));
    Assert::That(nthEven(6), Equals(10));
    Assert::That(nthEven(101), Equals(200));
    Assert::That(nthEven(201), Equals(400));
    Assert::That(nthEven(1001), Equals(2000));
  }
};

int main(int argc, const char *argv[])
{
    return TestRunner::RunAllTests();
}