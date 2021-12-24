// https://www.codewars.com/kata/55ecd718f46fba02e5000029

#include <igloo/igloo_alt.h>
using namespace igloo;

#include <vector>
#include <numeric>

std::vector<int> between(int start, int end) {
  std::vector<int> out(end - start + 1);
  std::iota(out.begin(), out.end(), start);
  return out;
}

Describe(Fixed_tests) {
  It(Basic_cases) {
    Assert::That(between(1, 4), Equals(std::vector<int>{1, 2, 3, 4}));
    Assert::That(between(-2, 2), Equals(std::vector<int>{-2, -1, 0, 1, 2}));
    Assert::That(between(-1, 10), Equals(std::vector<int>{-1, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10}));
    Assert::That(between(0, 1), Equals(std::vector<int>{0, 1}));
    Assert::That(between(-1, 0), Equals(std::vector<int>{-1, 0}));
    Assert::That(between(0, 0), Equals(std::vector<int>{0}));
    Assert::That(between(5, 5), Equals(std::vector<int>{5}));
  }
};

int main(int argc, const char *argv[])
{
    return TestRunner::RunAllTests();
}