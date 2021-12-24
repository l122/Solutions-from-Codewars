// https://www.codewars.com/kata/584466950d3bedb9b300001f

#include <igloo/igloo_alt.h>
using namespace igloo;

#include <iostream>
#include <string>
#include <algorithm>

static int stringCounter(std::string inputS, char charS)
{
    return std::count(inputS.begin(), inputS.end(), charS);
}

Describe(Hello_World_Tests)
{
        It(Hello_World_Tests)
    {
        Assert::That(stringCounter("Hello World",'o'), Equals(2));
    }
    It(Cinical_test_case)
    {
        Assert::That(stringCounter("Wait isn't it supposed to be cynical?",'i'), Equals(4));
    }
     It(Lets_see_how_you_handle_this)
    {
        Assert::That(stringCounter("I'm gona be the best code warrior ever dad",'r'), Equals(4));
    }
     It(What_do_you_think)
    {
        Assert::That(stringCounter("Do you like Harry Potter?",'?'), Equals(1));
    }
};

int main(int argc, const char *argv[])
{
    return TestRunner::RunAllTests();
}