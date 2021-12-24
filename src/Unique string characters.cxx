// https://www.codewars.com/kata/5a262cfb8f27f217f700000b

#include <igloo/igloo_alt.h>
using namespace igloo;

#include <iostream>
#include <string>

std::string solve(std::string a, std::string b)
{
    std::string result;
    for (const auto &c : a)
    {
        if (b.find(c) == std::string::npos)
        {
            result.push_back(c);
        }
    }

    for (const auto &c : b)
    {
        if (a.find(c) == std::string::npos)
        {
            result.push_back(c);
        }
    }
    return result;
}

Describe(Unique_String_Characters)
{
    It(Example_tests)
    {
        Assert::That(solve("xyab","xzca"), Equals("ybzc"));
        Assert::That(solve("xyabb","xzca"),Equals("ybbzc"));
        Assert::That(solve("abcd","xyz"),Equals("abcdxyz"));
        Assert::That(solve("xxx","xzca"),Equals("zca"));
   
    }
}; 

int main(int argc, const char *argv[])
{
    return TestRunner::RunAllTests();
}