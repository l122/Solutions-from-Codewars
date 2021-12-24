// https://www.codewars.com/kata/5899dc03bc95b1bf1b0000ad
#include <igloo/igloo_alt.h>
using namespace igloo;

#include <vector>
#include <algorithm>

std::vector<int> invert(std::vector<int> values)
{
    // std::for_each(values.begin(), values.end(),[](int &a){a*=-1;});
    // return values;
    // std::ranges::for_each(values, [](int &a){a*=-1;});
    // return values;
    // std::transform(values.begin(), values.end(), values.begin(), std::negate<int>());
    // return values;
    // std::ranges::transform(values.begin(), values.end(), values.begin(), std::negate<int>());
    // return values;
    std::vector<int> out;
    std::ranges::transform(values, std::back_inserter(out), std::negate<int>());
    return out;
}

Describe(test_invert)
{
    It(should_pass_some_basic_tests)
    {
        Assert::That(invert({1, 2, 3, 4, 5}), Equals(std::vector<int>{-1, -2, -3, -4, -5}));
        Assert::That(invert({1, -2, 3, -4, 5}), Equals(std::vector<int>{-1, 2, -3, 4, -5}));
        Assert::That(invert({}), Equals(std::vector<int>{}));
    }
};


int main(int argc, const char *argv[])
{
    return TestRunner::RunAllTests();
}