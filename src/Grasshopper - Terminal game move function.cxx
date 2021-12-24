// https://www.codewars.com/kata/563a631f7cbbc236cf0000c2

#include <igloo/igloo_alt.h>
using namespace igloo;

int move(int position, int roll) {
  return position + 2 * roll;
}


Describe(TerminalGameMove) {
  It(FixedTests) {
    Assert::That(move(0, 4), Equals(8));
    Assert::That(move(3, 6), Equals(15));
    Assert::That(move(2, 5), Equals(12));
  }
};

int main(int argc, const char *argv[])
{
    return TestRunner::RunAllTests();
}