// https://www.codewars.com/kata/57bfea4cb19505912900012c/train/cpp

#include <igloo/igloo_alt.h>
using namespace igloo;

#include <utility>
#include <cmath>

std::pair<int, int> symmetricPoint(const std::pair<int, int>& p,
                                   const std::pair<int, int>& q) {
    int x, y;

    x = 2 * q.first - p.first; 
    y = 2 * q.second - p.second;
    
    return {x, y};
}

Describe(SampleTests) {
    It(should_pass_sample_tests) {
        Assert::That(symmetricPoint({0, 0}, {1, 1}),
                     Equals(std::pair<int, int>{2, 2}));

        Assert::That(symmetricPoint({2, 6}, {-2, -6}),
                     Equals(std::pair<int, int>{-6, -18}));

        Assert::That(
            symmetricPoint({10, -10}, {-10, 10}),
            Equals(std::pair<int, int>{-30, 30}));

        Assert::That(symmetricPoint({1, -35}, {-12, 1}),
                     Equals(std::pair<int, int>{-25, 37}));

        Assert::That(
            symmetricPoint({1000, 15}, {-7, -214}),
            Equals(std::pair<int, int>{-1014, -443}));

        Assert::That(symmetricPoint({0, 0}, {0, 0}),
                     Equals(std::pair<int, int>{0, 0}));
    }
};



int main(int argc, const char *argv[])
{
    return TestRunner::RunAllTests();
}