// https://www.codewars.com/kata/57a083a57cb1f31db7000028
#include <igloo/igloo_alt.h>
using namespace igloo;

#include <vector>
#include <cstdint>
#include <algorithm>
#include <cmath>

std::vector<uint64_t> powers_of_two(int n)
{
    std::vector<uint64_t> ret(n + 1);
    std::generate(ret.begin(), ret.end(), [x = 0]() mutable
                  { return std::pow(2, x++); });

    return ret;
}

Describe(Fixed_tests){
    It(Sample_cases){
        Assert::That(powers_of_two(0), Equals(std::vector<uint64_t>{1}));
Assert::That(powers_of_two(2), Equals(std::vector<uint64_t>{1, 2, 4}));
Assert::That(powers_of_two(4), Equals(std::vector<uint64_t>{1, 2, 4, 8, 16}));
Assert::That(powers_of_two(10), Equals(std::vector<uint64_t>{1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024}));
}
}
;

int main(int argc, const char *argv[])
{
    return TestRunner::RunAllTests();
}