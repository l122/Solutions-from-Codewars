// https://www.codewars.com/kata/55f9bca8ecaa9eac7100004a

#include <igloo/igloo_alt.h>
using namespace igloo;

int past(int h, int m, int s) {
  return h * 3600000 + m * 60000 + s * 1000;
}

Describe(Clock) {
  It(BasicTests) {
    Assert::That(past(0, 1, 1), Equals(61000));
    Assert::That(past(1, 1, 1), Equals(3661000));
    Assert::That(past(0, 0, 0), Equals(0));
    Assert::That(past(1, 0, 1), Equals(3601000));
    Assert::That(past(1, 0, 0), Equals(3600000));
  }
};
int main(int argc, const char *argv[])
{
    return TestRunner::RunAllTests();
}