// https://www.codewars.com/kata/5a6663e9fd56cb5ab800008b
#include <igloo/igloo_alt.h>
using namespace igloo;

#include <vector>

std::vector<int> humanYearsCatYearsDogYears(int humanYears) {
  std::vector<int> ret(3);
  int a = humanYears > 0 ? 1 : 0;
  int b = humanYears > 1 ? 1 : 0;
  int c = humanYears > 2 ? humanYears - 2 : 0;
  ret[0] = humanYears;
  ret[1] = 15 * a + 9 * b + 4 * c;
  ret[2] = 15 * a + 9 * b + 5 * c;
  return ret;
}

using V = std::vector<int>;

Describe(HumanYearsCatYearsDogYears) {
  It(BasicTests) {
    Assert::That(humanYearsCatYearsDogYears( 1), Equals(V{1, 15, 15}));
    Assert::That(humanYearsCatYearsDogYears( 2), Equals(V{2, 24, 24}));
    Assert::That(humanYearsCatYearsDogYears(10), Equals(V{10, 56, 64}));
  }
};

int main(int argc, const char *argv[])
{
    return TestRunner::RunAllTests();
}