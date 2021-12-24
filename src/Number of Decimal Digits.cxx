// https://www.codewars.com/kata/58fa273ca6d84c158e000052/train/cpp

#include <igloo/igloo_alt.h>
using namespace igloo;

#include <iostream>
#include <stdint.h>

int digits(uint64_t n)
{
    // std::cout << SIZE_MAX << std::endl;
    if (n <= SIZE_MAX)
    {
        return std::to_string(n).size();
    }
    return -1;
}

Describe(sample_tests)
{
    It(test_digits)
    {
        Assert::That(digits(5ull), Equals(1));
        Assert::That(digits(12345ull), Equals(5));
        Assert::That(digits(9876543210ull), Equals(10));
    }
};

int main(int argc, const char *argv[])
{
    return TestRunner::RunAllTests();
}