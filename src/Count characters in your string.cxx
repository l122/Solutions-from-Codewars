// https://www.codewars.com/kata/52efefcbcdf57161d4000091

#include <igloo/igloo_alt.h>
using namespace igloo;

#include <iostream>
#include <string>
#include <map>

std::map<char, unsigned> count(const std::string &string)
{
    std::map<char, unsigned> result;
    for (const auto &letter : string)
    {
        ++result[letter];
    }
    return result;
}

using m = std::map<char, unsigned>;

Describe(SampleTests)
{
    It(should_pass_sample_tests)
    {
        Assert::That(count("aba"), Equals(m{{ 'a', 2 }, { 'b', 1 }}));
        Assert::That(count(""), Equals(m{}));
    }
};


int main(int argc, const char *argv[])
{
    return TestRunner::RunAllTests();
}