// https://www.codewars.com/kata/5738f5ea9545204cec000155

#include <igloo/igloo_alt.h>
using namespace igloo;

#include <iostream>
#include <string>
#include <cctype>
#include <algorithm>

int countLettersAndDigits(std::string input)
{
    int result = 0;
    // for (const auto &i : input)
    // {
    //     if (std::isdigit(i) || std::isalpha(i))
    //         ++result;
    // }
    result = std::count_if(input.begin(), input.end(), isalnum);
    return result;
}

Describe(Tests)
{
    It(ExampleTests)
    {
        Assert::That(countLettersAndDigits("n!!ic_e!!123"), Equals(7));
    }
};

int main(int argc, const char *argv[])
{
    return TestRunner::RunAllTests();
}