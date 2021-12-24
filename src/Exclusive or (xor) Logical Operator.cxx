// https://www.codewars.com/kata/56fa3c5ce4d45d2a52001b3c
#include <igloo/igloo_alt.h>
using namespace igloo;

bool xorf(bool a, bool b)
{
    return a ^ b;
}

Describe(ExampleTests)
{
    It(BasicTests)
    {
        Assert::That(xorf(false, false), Is().EqualTo(false));
        Assert::That(xorf(true, false), Is().EqualTo(true));
        Assert::That(xorf(false, true), Is().EqualTo(true));
        Assert::That(xorf(true, true), Is().EqualTo(false));
    }
    
    It(NestedCallTests)
    {
        Assert::That(xorf(false, xorf(false, false)), Is().EqualTo(false));
        Assert::That(xorf(xorf(true, false), false), Is().EqualTo(true));
        Assert::That(xorf(xorf(true, true), false), Is().EqualTo(false));
        Assert::That(xorf(true, xorf(true, true)), Is().EqualTo(true));
        Assert::That(xorf(xorf(false, false), xorf(false, false)), Is().EqualTo(false));
        Assert::That(xorf(xorf(false, false), xorf(false, true)), Is().EqualTo(true));
        Assert::That(xorf(xorf(true, false), xorf(false, false)), Is().EqualTo(true));
        Assert::That(xorf(xorf(true, false), xorf(true, false)), Is().EqualTo(false));
        Assert::That(xorf(xorf(true, true), xorf(true, false)), Is().EqualTo(true));
        Assert::That(xorf(xorf(true, xorf(true, true)), xorf(xorf(true, true), false)), Is().EqualTo(true));
    }
};

int main(int argc, const char *argv[])
{
    return TestRunner::RunAllTests();
}