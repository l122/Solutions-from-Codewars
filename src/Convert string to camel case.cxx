// https://www.codewars.com/kata/517abf86da9663f1d2000003

#include <igloo/igloo_alt.h>
using namespace igloo;

#include <iostream>
#include <string>

std::string to_camel_case(std::string text)
{
    std::string result = "";
    std::string excludingSymbols = "_-";
    bool flag = false;
    for (const auto &letter : text)
    {
        if (excludingSymbols.find(letter) == std::string::npos)
        {
            result += flag ? std::toupper(letter) : letter;
            flag = false;
        }
        else
        {
            flag = true;
        }
    }

    return result;
}

//Version 2

std::string to_camel_case2(std::string text)
{

    for (size_t i = 0; i < text.size(); ++i)
    {
        if (text[i] == '_' || text[i] == '-')
        {
            text.erase(i, 1);
            text[i] = std::toupper(text[i]);
        }
    }
    return text;
}

Describe(Testing_function_to_camel_case)
{
    It(Basic_tests)
    {
        Assert::That(to_camel_case(""), Equals(""));
        Assert::That(to_camel_case("the_stealth_warrior"), Equals("theStealthWarrior"));
        Assert::That(to_camel_case("The-Stealth-Warrior"), Equals("TheStealthWarrior"));
        Assert::That(to_camel_case("A-B-C"), Equals("ABC"));
    }
};

int main(int argc, const char *argv[])
{
    return TestRunner::RunAllTests();
}