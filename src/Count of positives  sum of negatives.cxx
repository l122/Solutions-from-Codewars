// https://www.codewars.com/kata/576bb71bbbcf0951d5000044/train/cpp
#include <igloo/igloo_alt.h>
using namespace igloo;

#include <vector>

// Solution 1
// std::vector<int> countPositivesSumNegatives(std::vector<int> input)
// {
//     int countPos = 0, sumNeg = 0;
//     for (const auto & n : input){
//         if (n > 0) countPos++;
//         else sumNeg += n;
//     }
//     std::vector<int> ret;
//     ret.push_back(countPos);
//     ret.push_back(sumNeg);
//     return ret;
// }

// Solution 2
#include <algorithm>
#include <numeric>

std::vector<int> countPositivesSumNegatives(std::vector<int> input)
{
    if (input.size() == 0) return input;
    std::vector<int> ret;
    int countPos = std::count_if(input.begin(), input.end(), [](int a){return a > 0;});
    ret.push_back(countPos);

    int sumNeg = std::accumulate(input.begin(), input.end(), 0, [](int a, int b){return b < 0 ? a + b : a;});
    ret.push_back(sumNeg);
    return ret;
}

Describe(Test)
{
    It(Test1)
    {
        std::vector<int> expected {10, -65};
        std::vector<int> result = countPositivesSumNegatives({1, 2, 3, 4, 5, 6, 7, 8, 9, 10, -11, -12, -13, -14, -15});
        Assert::That(result, Equals(expected));
    }
    
    It(Test2)
    {
        std::vector<int> expected = {8, -50};
        std::vector<int> result = countPositivesSumNegatives({0, 2, 3, 0, 5, 6, 7, 8, 9, 10, -11, -12, -13, -14});
        Assert::That(result, Equals(expected));
	  }
};


int main(int argc, const char *argv[])
{

    return TestRunner::RunAllTests();
}