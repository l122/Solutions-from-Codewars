// https://www.codewars.com/kata/5572f7c346eb58ae9c000047

#include <igloo/igloo_alt.h>
using namespace igloo;

#include <iostream>

#include <string>
std::string pattern(int n)
{
    std::string result;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 0; j < i; ++j)
        {
            result.append(std::to_string(i));
        }
        result.push_back('\n');
    }
    if (!result.empty())
        result.pop_back();
    return result;
}

#include <string>

Describe(Tests)
{
    It(ExampleTests)
    {
        std::string expected = "1\n22";
        std::string actual = pattern(2);
        Assert::That("\n" + actual, Equals("\n" + expected));
        
        expected = "1\n22\n333";
        actual = pattern(3);
        Assert::That("\n" + actual, Equals("\n" + expected));
    }
};

int main(int argc, const char *argv[])
{
    return TestRunner::RunAllTests();
}