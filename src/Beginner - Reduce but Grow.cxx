// https://www.codewars.com/kata/57f780909f7e8e3183000078
#include <igloo/igloo_alt.h>
using namespace igloo;

#include <vector>
#include <numeric>

int grow(std::vector<int> nums) {
    return std::accumulate(nums.begin(), nums.end(), 1, std::multiplies<int>());
}

using vec = std::vector<int>;

Describe(ReduceGrow) {
  It(BasicTests) {
    Assert::That(grow(vec{1, 2, 3}), Equals(6));
    Assert::That(grow(vec{4, 1, 1, 1, 4}), Equals(16));
    Assert::That(grow(vec{2, 2, 2, 2, 2, 2}), Equals(64));
  }
};

int main(int argc, const char *argv[])
{
    return TestRunner::RunAllTests();
}