// https://www.codewars.com/kata/59dd2c38f703c4ae5e000014

#include <igloo/igloo_alt.h>
using namespace igloo;

#include <iostream>
#include <string>
#include <cctype>

int solve(std::string s)
{
    int temp = 0,
        result = 0;
    std::string::size_type sz;

    for (std::size_t i = 0; i < s.length(); ++i)
    {
        if (isdigit(s[i]))
        {
            temp = std::stoi(s.substr(i), &sz);
            i += sz - 1;
            if (temp > result)
                result = temp;
        }
    }
    return result;
}

Describe(Numbers_in_strings)
{
    It(Example_tests)
    {
        Assert::That(solve("gh12cdy695m1"),Equals(695));
        Assert::That(solve("2ti9iei7qhr5"),Equals(9));
        Assert::That(solve("lu1j8qbbb85"),Equals(85));
        Assert::That(solve("185lu1j8qbbb85"),Equals(185));  
   
    }
};          

int main(int argc, const char *argv[])
{
    return TestRunner::RunAllTests();
}