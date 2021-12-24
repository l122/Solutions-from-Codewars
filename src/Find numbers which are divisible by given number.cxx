// https://www.codewars.com/kata/55edaba99da3a9c84000003b
#include <igloo/igloo_alt.h>
using namespace igloo;

#include <vector>
#include <algorithm>

std::vector<int> divisible_by(std::vector<int> numbers, int divisor)
{
    std::vector<int> to_vector;
    std::copy_if(numbers.begin(), numbers.end(), std::back_inserter(to_vector), [divisor](int a){
      return a % divisor == 0; });
    return to_vector;
}

#define V vector<int>

using namespace std;

Describe(TESTS)
{
    It(EXAMPLE_TESTS)
    {
        Assert::That(divisible_by({1, 2, 3, 4, 5, 6}, 2), Equals(V{2, 4, 6}));
        Assert::That(divisible_by({1, 2, 3, 4, 5, 6}, 3), Equals(V{3, 6}));
        Assert::That(divisible_by({0, 1, 2, 3, 4, 5, 6}, 4), Equals(V{0, 4}));
        Assert::That(divisible_by({0}, 4), Equals(V{0}));
        Assert::That(divisible_by({1, 3, 5}, 2), Equals(V{}));
        Assert::That(divisible_by({0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, 1), Equals(V{0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10}));
    }
};

int main(int argc, const char *argv[])
{
  return TestRunner::RunAllTests();
}