// https://www.codewars.com/kata/5388f0e00b24c5635e000fc6
#include <igloo/igloo_alt.h>
using namespace igloo;

#include <utility>
#include <algorithm>

std::pair<int, int> swap_values(std::pair<int, int> values) {

  std::swap(values.first, values.second);
  return values;
}

// std::pair<int, int> swap_values(std::pair<int, int> values)
// {
//   values.first ^= values.second ^= values.first ^= values.second;
//   return values;
// }

Describe(Sample_cases) {
  It(Small_numbers) {
    Assert::That(swap_values(std::pair<int, int>{1, 2}), Equals(std::pair<int, int>{2, 1}));
  }
  It(Bigger_numbers) {
    Assert::That(swap_values(std::pair<int, int>{14958573, 222032399}), Equals(std::pair<int, int>{222032399, 14958573}));
  }
};

int main(int argc, const char *argv[])
{
  return TestRunner::RunAllTests();
}