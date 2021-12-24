//https://www.codewars.com/kata/5a0d38c9697598b67a000041

#include <igloo/igloo_alt.h>
using namespace igloo;

#include <iostream>
#include <string>
#include <algorithm>
#include <bitset>

long eliminate_unset_bits(std::string number)
{
    int ones = std::count(number.begin(), number.end(), '1');
    std::string newNumber(ones, '1');
    return newNumber.empty() ? 0 : std::stol(newNumber, NULL, 2);
}

long eliminate_unset_bits2(const std::string &number)
{
    int ones = std::count(number.begin(), number.end(), '1');
    std::cout << std::bitset<8>{1l} << std::endl;
    std::cout << std::bitset<8>{(1l << ones) - 1};
    return (1l << ones) - 1;
}
Describe(Tests)
{
    It(Basic_Test_Cases)
    {
        Assert::That(eliminate_unset_bits("11010101010101"), Equals(255));
        Assert::That(eliminate_unset_bits("111"), Equals(7));
        Assert::That(eliminate_unset_bits("1000000"), Equals(1));
        Assert::That(eliminate_unset_bits("000000"), Equals(0));
    }
};

int main(int argc, const char *argv[])
{
    return TestRunner::RunAllTests();
}