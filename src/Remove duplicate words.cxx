// https://www.codewars.com/kata/5b39e3772ae7545f650000fc

#include <igloo/igloo_alt.h>
using namespace igloo;

#include <iostream>
#include <string>
#include <sstream>
#include <set>

std::string removeDuplicateWords(const std::string &str)
{
    std::stringstream ss(str);
    std::string result,
        temp;
    std::set<std::string> set;
    while (ss >> temp)
    {
        if (set.insert(temp).second)
        {
            result += temp;
            result.push_back(' ');
        }
    }
    if (!result.empty())
        result.pop_back();

    return result;
}

Describe(RemoveDuplicateWords)
{
    It(BasicTests)
    {
        Assert::That(removeDuplicateWords("alpha beta beta gamma gamma gamma delta alpha beta beta gamma gamma gamma delta"), Equals("alpha beta gamma delta"));
        Assert::That(removeDuplicateWords("my cat is cat fat"), Equals("my cat is fat"));
    }
};

int main(int argc, const char *argv[])
{
    return TestRunner::RunAllTests();
}