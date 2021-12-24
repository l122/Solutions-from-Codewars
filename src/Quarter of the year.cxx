// https://www.codewars.com/kata/5ce9c1000bab0b001134f5af
#include <igloo/igloo_alt.h>
using namespace igloo;

#include <cmath>

int quarter_of(int month){
  return std::ceil(month / 3.0);
}

Describe(Sample_tests) {
  It(Base_cases) {
    Assert::That(quarter_of(1), Equals(1));
    Assert::That(quarter_of(3), Equals(1));
    Assert::That(quarter_of(5), Equals(2));
    Assert::That(quarter_of(7), Equals(3));
    Assert::That(quarter_of(9), Equals(3));
    Assert::That(quarter_of(11), Equals(4));
  }  
};


int main(int argc, const char *argv[])
{

    return TestRunner::RunAllTests();
}