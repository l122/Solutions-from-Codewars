// https://www.codewars.com/kata/55dc4520094bbaf50e0000cb
#include <igloo/igloo_alt.h>
using namespace igloo;

#include <iostream>

bool amIWilson(unsigned n) {
    if (n <= 1) return false;

    unsigned temp = n;
    auto fact = 1; 
    while (--temp){
        fact *= temp;
    }
    auto remainder = (fact + 1) % (n * n);
    return remainder == 0 ? true : false;
}

Describe(am_i_wilson) {
//   It(should_return_false_for_composite_numbers) {
//     Assert::That(amIWilson(9), IsFalse());
//     Assert::That(amIWilson(6), IsFalse());
//   }
//   It(should_return_false_for_nonwilson_primes) {
//     Assert::That(amIWilson(2), IsFalse());
//     Assert::That(amIWilson(17), IsFalse());
//   }
  It(should_return_true_for_wilson_primes) {
    // Assert::That(amIWilson(5), IsTrue());
    // Assert::That(amIWilson(13), IsTrue());
    Assert::That(amIWilson(563), IsTrue());
  }
//     It(should_return_false_for_zero_and_one) {
//     Assert::That(amIWilson(0), IsFalse());
//     Assert::That(amIWilson(1), IsFalse());
//   }
};

int main(int argc, const char *argv[])
{
    return TestRunner::RunAllTests();
}