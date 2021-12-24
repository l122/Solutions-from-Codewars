// https://www.codewars.com/kata/5715eaedb436cf5606000381
#include <igloo/igloo_alt.h>
using namespace igloo;

#include <vector>
#include <numeric>

// My first solution
// int positive_sum (const std::vector<int> arr){
  
//   return std::accumulate(arr.begin(), arr.end(), 0, [](int base, int a){return a > 0 ? a+base : base;});
// }

// Good idea from codewars

int positive_sum (const std::vector<int> arr){
  return std::accumulate(arr.begin(), arr.end(), 0, [](int base, int a){return base + std::max(a, 0);});
}

// TODO: Replace examples and use TDD development by writing your own tests

Describe(Tests)
{
    It(works_for_some_examples)
    {
        Assert::That(positive_sum(std::vector <int> {1,2,3,4,5}), Equals(15));
        Assert::That(positive_sum(std::vector <int> {1,-2,3,4,5}), Equals(13));
        Assert::That(positive_sum(std::vector <int> {-1,2,3,4,-5}), Equals(9));
    }
    It(returns_0_when_array_is_empty)
    {
        Assert::That(positive_sum(std::vector <int> {}), Equals(0));
    }
    It(returns_0_when_all_elements_are_negative)
    {
        Assert::That(positive_sum(std::vector <int> {-1,-2,-3,-4,-5}), Equals(0));
    }
};


int main(int argc, const char *argv[])
{
    return TestRunner::RunAllTests();
}