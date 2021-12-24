// https://www.codewars.com/kata/576bb3c4b1abc497ec000065
#include <igloo/igloo_alt.h>
using namespace igloo;

#include <iostream>
#include <string>
#include <algorithm>

bool compare(std::string s1, std::string s2)
{
    //Convert all to uppercase
    std::transform(s1.begin(), s1.end(), s1.begin(), toupper);
    std::transform(s2.begin(), s2.end(), s2.begin(), toupper);

    //Convert string to sum of numbers
    unsigned long long int sum1 = 0, sum2 = 0;

    for (auto const &s : s1)
    {
        if (std::isalpha(s))
        {
            sum1 += static_cast<int>(s);
        }
        else
        {
            return true;
        }
    }

    for (auto const &s : s2)
    {
        if (std::isalpha(s))
        {
            sum2 += static_cast<int>(s);
        }
        else
        {
            return true;
        }
    }

    return sum1 == sum2;
}

Describe(Tests)
{
    It(ExampleTests)
    {
        Assert::That(compare("AD", "BC"), Equals(true));
    }
};

int main(int argc, const char *argv[])
{
    return TestRunner::RunAllTests();
}