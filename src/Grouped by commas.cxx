// https://www.codewars.com/kata/5274e122fc75c0943d000148

#include <igloo/igloo_alt.h>
using namespace igloo;

#include <iostream>
#include <string>

std::string group_by_commas(int n)
{
    std::string result = std::to_string(n);
    int numberLength = result.size();
    int counter = 0;
    for (int i = numberLength - 1; i >= 0; --i)
    {
        ++counter;
        if (counter % 3 == 0 && i != 0)
        {
            result.insert(i, ",");
        }
    }
    return result;
}

//A better solution
std::string group_by_commas2(int n)
{
    std::string result = std::to_string(n);
    for (int i = result.size() - 3; i > 0;)
    {
        result.insert(i, ",");
        i -= 3;
    }
    return result;
}
Describe(basic)
{
    It(example_tests)
    {
        Assert::That(         group_by_commas(1),             Equals("1"));
        Assert::That(        group_by_commas(12),            Equals("12"));
        Assert::That(       group_by_commas(123),           Equals("123"));
        Assert::That(      group_by_commas(1234),         Equals("1,234"));
        Assert::That(     group_by_commas(12345),        Equals("12,345"));
        Assert::That(    group_by_commas(123456),       Equals("123,456"));
        Assert::That(   group_by_commas(1234567),     Equals("1,234,567"));
        Assert::That(  group_by_commas(12345678),    Equals("12,345,678"));
        Assert::That( group_by_commas(123456789),   Equals("123,456,789"));
        Assert::That(group_by_commas(1234567890), Equals("1,234,567,890"));
    }
};


int main(int argc, const char *argv[])
{
    return TestRunner::RunAllTests();
}