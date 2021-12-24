// https://www.codewars.com/kata/56f69d9f9400f508fb000ba7

#include <igloo/igloo_alt.h>
using namespace igloo;

#include <iostream>

#include <vector>
#include <numeric>

// Solution 1
// std::vector<int> MonkeyCount(int n) {
//   std::vector<int> out;
//   for (size_t i = 1; i <= n; ++i){
//       out.push_back(i);
//   }
//   return out;
// }

// A better solution
std::vector<int> MonkeyCount(int n) {
  std::vector<int> out(n);
  std::iota(out.begin(), out.end(), 1);
  return out;
}

#include <cmath>

using vec = std::vector<int>;

Describe(CountingMonkeys)
{
  It(ShouldWorkForFixedTests) {
    Assert::That(MonkeyCount(5), Equals(vec{1, 2, 3, 4, 5}));
    Assert::That(MonkeyCount(3), Equals(vec{1, 2, 3}));
    Assert::That(MonkeyCount(9), Equals(vec{1, 2, 3, 4, 5, 6, 7, 8, 9}));
    Assert::That(MonkeyCount(10), Equals(vec{1, 2, 3, 4, 5, 6, 7, 8, 9, 10}));
    Assert::That(MonkeyCount(20), Equals(vec{1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20}));
  }
};

int main(int argc, const char *argv[])
{
    return TestRunner::RunAllTests();
}