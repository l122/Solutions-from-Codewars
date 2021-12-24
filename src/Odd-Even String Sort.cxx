// https://www.codewars.com/kata/580755730b5a77650500010c

#include <igloo/igloo_alt.h>
using namespace igloo;


#include <iostream>
#include <string>

std::string sortMyString(const std::string &s)
{
    std::string odd, even;
    for (int i = 0; i < s.size(); ++i)
    {
        if (i % 2 == 0)
        {
            odd += s[i];
        }
        else
        {
            even += s[i];
        }
    }
    return odd + " " + even;
}
Describe(Other_Tests)
{
    It(Static_Ones)
    {
        Assert::That(sortMyString("CodeWars"), Equals("CdWr oeas"));
        Assert::That(sortMyString("YCOLUE'VREER"), Equals("YOU'RE CLEVER"));
    }
};
int main(int argc, const char *argv[])
{
    return TestRunner::RunAllTests();
}