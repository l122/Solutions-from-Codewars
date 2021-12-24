// https://www.codewars.com/kata/5a1c28f9c9fc0ef2e900013b

#include <iostream>
#include <string>

#include <igloo/igloo_alt.h>
using namespace igloo;

std::string pyramid(int n)
{
    std::string result = "";
    char c = ' ';
    for (int i = 1; i <= n; ++i)
    {
        if (i == n)
            c = '_';
        result += std::string(n - i, c);
        result.push_back('/');
        result += std::string((i - 1) * 2, c);
        result.push_back('\\');
        result.push_back('\n');
    }

    return result;
}


Describe(Pyramid)
{
    It(BasicTests)
    {
        Assert::That(pyramid(1), Equals("/\\\n"));
        Assert::That(pyramid(2), Equals(" /\\\n/__\\\n"));
        Assert::That(pyramid(4), Equals("   /\\\n  /  \\\n /    \\\n/______\\\n"));
        Assert::That(pyramid(6), Equals("     /\\\n    /  \\\n   /    \\\n  /      \\\n /        \\\n/__________\\\n"));
        Assert::That(pyramid(10), Equals("         /\\\n        /  \\\n       /    \\\n      /      \\\n     /        \\\n    /          \\\n   /            \\\n  /              \\\n /                \\\n/__________________\\\n"));
    }
};


int main(int argc, const char *argv[])
{
    return TestRunner::RunAllTests();
}