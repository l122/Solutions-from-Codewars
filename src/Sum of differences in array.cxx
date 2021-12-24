// https://www.codewars.com/kata/571d42206414b103dc0006a1
#include <igloo/igloo_alt.h>
using namespace igloo;

#include <vector>
#include <algorithm>

int sumOfDifferences(std::vector<int> arr)
{
    if (arr.size() < 2)
        return 0;

    std::sort(arr.begin(), arr.end(), std::greater<int>());

    int sum = 0;

    for (size_t i = 0; i < (arr.size() - 1); ++i)
    {
        sum += arr[i] - arr[i + 1];
    }
    return sum;
}

Describe(Sample_Tests){
    It(Fixed_Tests){
        Assert::That(sumOfDifferences({1, 2, 10}), Equals(9));
Assert::That(sumOfDifferences({-3, -2, -1}), Equals(2));
Assert::That(sumOfDifferences({1, 1, 1, 1}), Equals(0));
Assert::That(sumOfDifferences({-17, 17}), Equals(34));
Assert::That(sumOfDifferences({}), Equals(0));
Assert::That(sumOfDifferences({-1}), Equals(0));
Assert::That(sumOfDifferences({1}), Equals(0));
}
}
;

int main(int argc, const char *argv[])
{
    return TestRunner::RunAllTests();
}