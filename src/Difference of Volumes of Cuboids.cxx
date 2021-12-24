// https://www.codewars.com/kata/58cb43f4256836ed95000f97

#include <igloo/igloo_alt.h>
using namespace igloo;

#include <array>
#include <numeric>
#include <cmath>

int findDifference(std::array<int, 3> a, std::array<int, 3> b) {
  int v1 = std::accumulate(a.begin(), a.end(), 1, std::multiplies());
  int v2 = std::accumulate(b.begin(), b.end(), 1, std::multiplies());
  return std::abs(v1 - v2);
}

using ar = std::array<int, 3>;

Describe(DifferenceVolumesCuboids) {
  It(BasicTests) {
    Assert::That(findDifference(ar{3, 2, 5}, ar{1, 4, 4}), Equals(14));
    Assert::That(findDifference(ar{9, 7, 2}, ar{5, 2, 2}), Equals(106));
    Assert::That(findDifference(ar{11, 2, 5}, ar{1, 10, 8}), Equals(30));
    Assert::That(findDifference(ar{4, 4, 7}, ar{3, 9, 3}), Equals(31));
    Assert::That(findDifference(ar{15, 20, 25}, ar{10, 30, 25}), Equals(0));
  }
};

int main(int argc, const char *argv[])
{
    return TestRunner::RunAllTests();
}