// https://www.codewars.com/kata/515e271a311df0350d00000f/train/cpp
#include <igloo/igloo_alt.h>
using namespace igloo;

#include <vector>
#include <numeric>

int square_sum(std::vector<int> numbers)
{
    return std::accumulate(numbers.begin(), numbers.end(), 0, [](int a, int b){return a + b*b;});
}

Describe(test_square_sum)
{
    It(should_pass_some_basic_tests)
    {
        Assert::That(square_sum({1, 2}), Equals(5));
        Assert::That(square_sum({0, 3, 4, 5}), Equals(50));
    }
};


int main(int argc, const char *argv[])
{
    return TestRunner::RunAllTests();
}