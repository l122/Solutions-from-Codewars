// https://www.codewars.com/kata/5f9f43328a6bff002fa29eb8
#include <igloo/igloo_alt.h>
using namespace igloo;

#include <iostream>
#include <cmath>
#include <iomanip>

bool approx_equals(double a, double b) {
  return ((a*1000 - b*1000) <= 1) && ((a*1000 - b*1000) >= -1) ;
}

Describe(fixed_tests) {
  It(testing_approx_equals) {
    Assert::That(approx_equals(175.9827, 82.25), Equals(false));
    Assert::That(approx_equals(-156.24037, -156.24038), Equals(true));
    Assert::That(approx_equals(123.2345, 123.234501), Equals(true));
    Assert::That(approx_equals(1456.3652, 1456.3641), Equals(false));
    Assert::That(approx_equals(-1.234, -1.233999), Equals(true));
    Assert::That(approx_equals(98.7655, 98.7654999), Equals(true));
    Assert::That(approx_equals(-7.28495, -7.28596), Equals(false));
  }
};

int main(int argc, const char *argv[])
{
    return TestRunner::RunAllTests();
}