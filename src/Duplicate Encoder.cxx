// https://www.codewars.com/kata/54b42f9314d9229fd6000d9c

#include <igloo/igloo_alt.h>
using namespace igloo;

#include <iostream>
#include <string>
#include <algorithm>

std::string duplicate_encoder(std::string word)
{
    std::string output = "";
    std::transform(word.begin(), word.end(), word.begin(), tolower);
    for (auto symbol : word)
    {
        output += std::count(word.begin(), word.end(), symbol) > 1 ? ")" : "(";
    }
    return output;
}

// TODO: Replace examples and use TDD development by writing your own tests

Describe(Tests)
{  
    It(Basic_Tests)
    {
        Assert::That(duplicate_encoder("din"), Equals("((("));
        Assert::That(duplicate_encoder("recede"), Equals("()()()"));
        Assert::That(duplicate_encoder("Success"), Equals(")())())"));
        Assert::That(duplicate_encoder("CodeWarrior"), Equals("()(((())())"));
        Assert::That(duplicate_encoder("Supralapsarian"), Equals(")()))()))))()("));
        Assert::That(duplicate_encoder("(( @"), Equals("))(("));
        Assert::That(duplicate_encoder(" ( ( )"), Equals(")))))("));
    }
};

int main(int argc, const char *argv[])
{
    return TestRunner::RunAllTests();
}