// https://www.codewars.com/kata/5a2be17aee1aaefe2a000151
#include <igloo/igloo_alt.h>
using namespace igloo;

#include <vector>
#include <numeric>

int arrayPlusArray(std::vector<int> a, std::vector<int> b) {
  return std::accumulate(a.begin(), a.end(), 0) + std::accumulate(b.begin(), b.end(), 0);
}

using V = std::vector<int>;

Describe(ArrayPlusArray) {
    It(BasicTests) {
        Assert::That(arrayPlusArray(V{1, 2, 3}, V{4, 5, 6}), Equals(21));
        Assert::That(arrayPlusArray(V{1, -2, -3}, V{4, -5, 6}), Equals(1));
        Assert::That(arrayPlusArray(V{-1, -2, -3}, V{-4, -5, -6}), Equals(-21));
        Assert::That(arrayPlusArray(V{0, 0, 0}, V{4, 5, 6}), Equals(15));
        Assert::That(arrayPlusArray(V{-1}, V{-1}), Equals(-2));
    }
};

int main(int argc, const char *argv[])
{
    return TestRunner::RunAllTests();
}